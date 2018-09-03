#include "MdSpi.h"
#include "ZmqServer.h"
#include <fstream>
#include <vector>

inline bool CMdSpi::IsErrorRspInfo(CThostFtdcRspInfoField* pRspInfo)
{
        // 如果ErrorID != 0, 说明收到了错误的响应
        if (pRspInfo == NULL)
                return false;

        bool bResult = (pRspInfo->ErrorID != 0);
        if (bResult) {
                guosen::msg::ctp::CThostFtdcRspInfoField body_message;
                body_message.set_errorid(pRspInfo->ErrorID);
                body_message.set_errormsg(pRspInfo->ErrorMsg);
                guosen::msg::ProtoMsg proto_message;
                proto_message.set_head(guosen::msg::MsgType::CThostFtdcRspInfoField);
                body_message.SerializeToString(proto_message.mutable_body());
                do_publish(proto_message);
        }
        return bResult;
}

void CMdSpi::load_config(const Document& d)
{
        broker_id = d["broker_id"].GetString();
        user_id = d["user_id"].GetString();
        passwd = d["passwd"].GetString();
        front_id = d["md_address"].GetString();
}
void CMdSpi::connect()
{
        if (userapi == nullptr) {
                // userapi = CThostFtdcMdApi::CreateFtdcMdApi(); // 靠UserApi
                userapi = CThostFtdcMdApi::CreateFtdcMdApi("./mdlog/"); // 靠UserApi

                if (!userapi) {
                        throw "ctp_md failed to create api";
                }
                userapi->RegisterSpi(this);
        }

        userapi->RegisterFront(const_cast<char*>(front_id.c_str())); // connect
        userapi->Init();
        userapi->Join();
}
int CMdSpi::exit()
{
        //该函数在原生API里没有，用于安全退出API用，原生的join似乎不太稳定
        userapi->RegisterSpi(NULL);
        userapi->Release();
        userapi = NULL;
        return 1;
}

void CMdSpi::subscribeMarketData(const vector<string>& instruments)
{
        auto ncount = instruments.size();
        char* insts[ncount];
        for (int i = 0; i < ncount; i++) {
                insts[i] = const_cast<char*>(instruments[i].c_str());
        }
        int iResult = userapi->SubscribeMarketData(insts, ncount);
}

void CMdSpi::subscribeAllMarketData()
{
        vector<string> sub_code;

        // sub_code.push_back("IF1808");
        // subscribeMarketData(sub_code);

        ifstream in("./config/future_contract.txt");

        if (in) {
                string line;
                vector<string> sub_code;

                while (getline(in, line)) {
                        sub_code.push_back(line);
                }
                subscribeMarketData(sub_code);
        } else //TODO need write to log
                cerr << "can not open future_contract file!" << endl;
}

int CMdSpi::unSubscribeMarketData(string instrumentID)
{
        char* buffer = (char*)instrumentID.c_str();
        char* myreq[1] = { buffer };
        int i = userapi->UnSubscribeMarketData(myreq, 1);
        return i;
}

int CMdSpi::subscribeForQuoteRsp(string instrumentID)
{
        char* buffer = (char*)instrumentID.c_str();
        char* myreq[1] = { buffer };
        int i = userapi->SubscribeForQuoteRsp(myreq, 1);
        return i;
}

int CMdSpi::unSubscribeForQuoteRsp(string instrumentID)
{
        char* buffer = (char*)instrumentID.c_str();
        char* myreq[1] = { buffer };
        int i = userapi->UnSubscribeForQuoteRsp(myreq, 1);
        return i;
}

int CMdSpi::reqUserLogin(guosen::msg::ctp::CThostFtdcReqUserLoginField req)
{
        CThostFtdcReqUserLoginField myreq;
        memset(&myreq, 0, sizeof(myreq));
        strcpy(myreq.BrokerID, req.brokerid().c_str());
        strcpy(myreq.UserID, req.userid().c_str());
        strcpy(myreq.Password, req.password().c_str());
        strcpy(myreq.TradingDay, req.tradingday().c_str());
        strcpy(myreq.InterfaceProductInfo, req.interfaceproductinfo().c_str());
        strcpy(myreq.ProtocolInfo, req.protocolinfo().c_str());
        strcpy(myreq.MacAddress, req.macaddress().c_str());
        strcpy(myreq.OneTimePassword, req.onetimepassword().c_str());
        strcpy(myreq.ClientIPAddress, req.clientipaddress().c_str());
        int i = userapi->ReqUserLogin(&myreq, ++nRequestID);
        return i;
}

int CMdSpi::reqUserLogout(guosen::msg::ctp::CThostFtdcUserLogoutField req)
{
        CThostFtdcUserLogoutField myreq;
        memset(&myreq, 0, sizeof(myreq));
        strcpy(myreq.BrokerID, req.brokerid().c_str());
        strcpy(myreq.UserID, req.userid().c_str());
        int i = userapi->ReqUserLogout(&myreq, ++nRequestID);
        cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
        return i;
}

//-------------------------------------------------------------------------------------
//API回调函数
//-------------------------------------------------------------------------------------

///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
void CMdSpi::OnFrontConnected()
{
        connection_status = true;
        guosen::msg::CtpRtnConnect body_message;
        body_message.set_status(true);
        body_message.set_nreason(0);

        guosen::msg::ProtoMsg proto_message;
        proto_message.set_head(guosen::msg::MsgType::ctprtnconnect);
        body_message.SerializeToString(proto_message.mutable_body());
        do_publish(proto_message);
        // TODO
        // reqUserLogin();
}

///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
///@param nReason 错误原因
///        0x1001 网络读失败
///        0x1002 网络写失败
///        0x2001 接收心跳超时
///        0x2002 发送心跳失败
///        0x2003 收到错误报文
void CMdSpi::OnFrontDisconnected(int nReason)
{
        // cerr << "--->>> " << __FUNCTION__ << endl;
        // cerr << "--->>> Reason = " << nReason << endl;

        guosen::msg::CtpRtnConnect body_message;
        body_message.set_status(false);
        body_message.set_nreason(nReason);

        guosen::msg::ProtoMsg proto_message;
        proto_message.set_head(guosen::msg::MsgType::ctprtnconnect);
        body_message.SerializeToString(proto_message.mutable_body());

        do_publish(proto_message);
}

///心跳超时警告。当长时间未收到报文时，该方法被调用。
///@param nTimeLapse 距离上次接收报文的时间
void CMdSpi::OnHeartBeatWarning(int nTimeLapse)
{
        // cerr << "--->>> " << __FUNCTION__ << endl;
        // cerr << "--->>> nTimerLapse = " << nTimeLapse << endl;
        guosen::msg::CtpHeartWarning body_message;
        body_message.set_ntimelapse(nTimeLapse);

        guosen::msg::ProtoMsg proto_message;
        proto_message.set_head(guosen::msg::MsgType::ctpheartwarning);
        body_message.SerializeToString(proto_message.mutable_body());

        do_publish(proto_message);
}

///登录请求响应
void CMdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
        if (pRspUserLogin == NULL or IsErrorRspInfo(pRspInfo)) {
                return;
        }

        // front_id = pRspUserLogin->FrontID;
        // session_id = pRspUserLogin->SessionID;
        login_status = true;

        guosen::msg::ctp::CThostFtdcRspUserLoginField body_message;
        body_message.set_tradingday(pRspUserLogin->TradingDay);
        body_message.set_logintime(pRspUserLogin->LoginTime);
        body_message.set_brokerid(pRspUserLogin->BrokerID);
        body_message.set_userid(pRspUserLogin->UserID);
        body_message.set_systemname(pRspUserLogin->SystemName);
        body_message.set_frontid(pRspUserLogin->FrontID);
        body_message.set_sessionid(pRspUserLogin->SessionID);
        body_message.set_maxorderref(pRspUserLogin->MaxOrderRef);
        body_message.set_shfetime(pRspUserLogin->SHFETime);
        body_message.set_dcetime(pRspUserLogin->DCETime);
        body_message.set_czcetime(pRspUserLogin->CZCETime);
        body_message.set_ffextime(pRspUserLogin->FFEXTime);
        body_message.set_inetime(pRspUserLogin->INETime);
        guosen::msg::ProtoMsg proto_message;
        proto_message.set_head(guosen::msg::MsgType::CThostFtdcRspUserLoginField);
        body_message.SerializeToString(proto_message.mutable_body());
        do_publish(proto_message);

        // TODO
        // subscribeAllMarketData();
}

///登出请求响应
void CMdSpi::OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
        if (pUserLogout == NULL or IsErrorRspInfo(pRspInfo)) {
                return;
        }

        login_status = false;
        guosen::msg::ctp::CThostFtdcUserLogoutField body_message;
        body_message.set_brokerid(pUserLogout->BrokerID);
        body_message.set_userid(pUserLogout->UserID);
        guosen::msg::ProtoMsg proto_message;
        proto_message.set_head(guosen::msg::MsgType::CThostFtdcUserLogoutField);
        body_message.SerializeToString(proto_message.mutable_body());
        do_publish(proto_message);
}

///错误应答
void CMdSpi::OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
        if (pRspInfo == NULL)
                return;

        bool bResult = (pRspInfo->ErrorID != 0);
        if (bResult) {
                guosen::msg::ctp::CThostFtdcRspInfoField body_message;
                body_message.set_errorid(pRspInfo->ErrorID);
                body_message.set_errormsg(pRspInfo->ErrorMsg);
                guosen::msg::ProtoMsg proto_message;
                proto_message.set_head(guosen::msg::MsgType::CThostFtdcRspInfoField);
                body_message.SerializeToString(proto_message.mutable_body());
                do_publish(proto_message);
        }
}

///订阅行情应答
void CMdSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
        if (pSpecificInstrument != NULL && !IsErrorRspInfo(pRspInfo)) {
                guosen::msg::ctp::CThostFtdcSpecificInstrumentField body_message;
                body_message.set_instrumentid(pSpecificInstrument->InstrumentID);
                guosen::msg::ProtoMsg proto_message;
                proto_message.set_head(guosen::msg::MsgType::CThostFtdcSpecificInstrumentField);
                body_message.SerializeToString(proto_message.mutable_body());
                do_publish(proto_message);
        }
}

///取消订阅行情应答
void CMdSpi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
        if (pSpecificInstrument != NULL && !IsErrorRspInfo(pRspInfo)) {
                guosen::msg::ctp::CThostFtdcSpecificInstrumentField body_message;
                body_message.set_instrumentid(pSpecificInstrument->InstrumentID);
                guosen::msg::ProtoMsg proto_message;
                proto_message.set_head(guosen::msg::MsgType::CThostFtdcSpecificInstrumentField);
                body_message.SerializeToString(proto_message.mutable_body());
                do_publish(proto_message);
        }
}

///订阅询价应答
void CMdSpi::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
        if (pSpecificInstrument != NULL && !IsErrorRspInfo(pRspInfo)) {
                guosen::msg::ctp::CThostFtdcSpecificInstrumentField body_message;
                body_message.set_instrumentid(pSpecificInstrument->InstrumentID);
                guosen::msg::ProtoMsg proto_message;
                proto_message.set_head(guosen::msg::MsgType::CThostFtdcSpecificInstrumentField);
                body_message.SerializeToString(proto_message.mutable_body());
                do_publish(proto_message);
        }
}
///取消订阅询价应答
void CMdSpi::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
        if (pSpecificInstrument != NULL && !IsErrorRspInfo(pRspInfo)) {
                guosen::msg::ctp::CThostFtdcSpecificInstrumentField body_message;
                body_message.set_instrumentid(pSpecificInstrument->InstrumentID);
                guosen::msg::ProtoMsg proto_message;
                proto_message.set_head(guosen::msg::MsgType::CThostFtdcSpecificInstrumentField);
                body_message.SerializeToString(proto_message.mutable_body());
                do_publish(proto_message);
        }
}

///深度行情通知
void CMdSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData)
{
        if (pDepthMarketData == NULL)
                return;

        guosen::msg::ctp::CThostFtdcDepthMarketDataField body_message;
        body_message.set_tradingday(pDepthMarketData->TradingDay);
        body_message.set_instrumentid(pDepthMarketData->InstrumentID);
        body_message.set_exchangeid(pDepthMarketData->ExchangeID);
        body_message.set_exchangeinstid(pDepthMarketData->ExchangeInstID);
        body_message.set_lastprice(pDepthMarketData->LastPrice);
        body_message.set_presettlementprice(pDepthMarketData->PreSettlementPrice);
        body_message.set_precloseprice(pDepthMarketData->PreClosePrice);
        body_message.set_preopeninterest(pDepthMarketData->PreOpenInterest);
        body_message.set_openprice(pDepthMarketData->OpenPrice);
        body_message.set_highestprice(pDepthMarketData->HighestPrice);
        body_message.set_lowestprice(pDepthMarketData->LowestPrice);
        body_message.set_volume(pDepthMarketData->Volume);
        body_message.set_turnover(pDepthMarketData->Turnover);
        body_message.set_openinterest(pDepthMarketData->OpenInterest);
        body_message.set_closeprice(pDepthMarketData->ClosePrice);
        body_message.set_settlementprice(pDepthMarketData->SettlementPrice);
        body_message.set_upperlimitprice(pDepthMarketData->UpperLimitPrice);
        body_message.set_lowerlimitprice(pDepthMarketData->LowerLimitPrice);
        body_message.set_predelta(pDepthMarketData->PreDelta);
        body_message.set_currdelta(pDepthMarketData->CurrDelta);
        body_message.set_updatetime(pDepthMarketData->UpdateTime);
        body_message.set_updatemillisec(pDepthMarketData->UpdateMillisec);
        body_message.set_bidprice1(pDepthMarketData->BidPrice1);
        body_message.set_bidvolume1(pDepthMarketData->BidVolume1);
        body_message.set_askprice1(pDepthMarketData->AskPrice1);
        body_message.set_askvolume1(pDepthMarketData->AskVolume1);
        body_message.set_bidprice2(pDepthMarketData->BidPrice2);
        body_message.set_bidvolume2(pDepthMarketData->BidVolume2);
        body_message.set_askprice2(pDepthMarketData->AskPrice2);
        body_message.set_askvolume2(pDepthMarketData->AskVolume2);
        body_message.set_bidprice3(pDepthMarketData->BidPrice3);
        body_message.set_bidvolume3(pDepthMarketData->BidVolume3);
        body_message.set_askprice3(pDepthMarketData->AskPrice3);
        body_message.set_askvolume3(pDepthMarketData->AskVolume3);
        body_message.set_bidprice4(pDepthMarketData->BidPrice4);
        body_message.set_bidvolume4(pDepthMarketData->BidVolume4);
        body_message.set_askprice4(pDepthMarketData->AskPrice4);
        body_message.set_askvolume4(pDepthMarketData->AskVolume4);
        body_message.set_bidprice5(pDepthMarketData->BidPrice5);
        body_message.set_bidvolume5(pDepthMarketData->BidVolume5);
        body_message.set_askprice5(pDepthMarketData->AskPrice5);
        body_message.set_askvolume5(pDepthMarketData->AskVolume5);
        body_message.set_averageprice(pDepthMarketData->AveragePrice);
        body_message.set_actionday(pDepthMarketData->ActionDay);
        guosen::msg::ProtoMsg proto_message;
        proto_message.set_head(guosen::msg::MsgType::CThostFtdcDepthMarketDataField);
        body_message.SerializeToString(proto_message.mutable_body());
        do_publish(proto_message);
}

///询价通知
void CMdSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp)
{
        if (pForQuoteRsp == NULL)
                return;

        guosen::msg::ctp::CThostFtdcForQuoteRspField body_message;
        body_message.set_tradingday(pForQuoteRsp->TradingDay);
        body_message.set_instrumentid(pForQuoteRsp->InstrumentID);
        body_message.set_forquotesysid(pForQuoteRsp->ForQuoteSysID);
        body_message.set_forquotetime(pForQuoteRsp->ForQuoteTime);
        body_message.set_actionday(pForQuoteRsp->ActionDay);
        body_message.set_exchangeid(pForQuoteRsp->ExchangeID);
        guosen::msg::ProtoMsg proto_message;
        proto_message.set_head(guosen::msg::MsgType::CThostFtdcForQuoteRspField);
        body_message.SerializeToString(proto_message.mutable_body());
        do_publish(proto_message);
}
