#include "MdSpi.h"
#include "ZmqServer.h"
#include <fstream>
#include <vector>

inline bool CMdSpi::IsErrorRspInfo(CThostFtdcRspInfoField* pRspInfo)
{
        bool bResult = (pRspInfo && pRspInfo->ErrorID != 0);
        if (bResult) {
                // cerr << "--->>> ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg << endl;
                guosen::CtpRspError body_message;
                body_message.set_ErrorID(pRspInfo->ErrorID);
                body_message.set_ErrorMsg(pRspInfo->ErrorMsg);

                guosen::ProtoMsg proto_message;
                proto_message.set_head(guosen::MsgType::ctpheartwarning);
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
        // cout << "--->>> " << __FUNCTION__ << endl;
        // char* pp[] = { "IF1807" };
        // int iResult = pUserCMdSpi->SubscribeMarketData(pp, 1);

        auto ncount = instruments.size();
        char* insts[ncount];
        for (int i = 0; i < ncount; i++) {
                insts[i] = const_cast<char*>(instruments[i].c_str());
                // char *buff = const_cast<char*>(instruments[i].c_str());
                // userapi->SubscribeMarketData({buff}, 1);
        }
        int iResult = userapi->SubscribeMarketData(insts, ncount);
        // cerr << "--->>>SubscribeMarketData " << ncount << " request: " << (iResult == 0 ? "success" : "failed") << endl;
}

void CMdSpi::subscribeAllMarketData()
{

        vector<string> sub_code;
        sub_code.push_back("IF1808");
        subscribeMarketData(sub_code);
        // ifstream in("./config/future_contract.txt");
        //
        // if (in) {
        //
        //         string line;
        //         vector<string> sub_code;
        //
        //         while (getline(in, line)) {
        //                 sub_code.push_back(line);
        //         }
        //         subscribeMarketData(sub_code);
        //
        // } else
        //         cerr << "can not open future_contract file!" << endl;
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

int CMdSpi::reqUserLogin()
{
        CThostFtdcReqUserLoginField myreq = CThostFtdcReqUserLoginField();
        memset(&myreq, 0, sizeof(myreq));
        cout << "交易日 TThostFtdcDateType:" << endl;
        // cin >> myreq.TradingDay;
        cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
        strcpy(myreq.BrokerID, broker_id.c_str());
        cout << "用户代码 TThostFtdcUserIDType:" << endl;
        strcpy(myreq.UserID, user_id.c_str());
        cout << "密码 TThostFtdcPasswordType:" << endl;
        strcpy(myreq.Password, passwd.c_str());
        cout << "用户端产品信息 TThostFtdcProductInfoType:" << endl;
        // cin >> myreq.UserProductInfo;
        cout << "接口端产品信息 TThostFtdcProductInfoType:" << endl;
        // cin >> myreq.InterfaceProductInfo;
        cout << "协议信息 TThostFtdcProtocolInfoType:" << endl;
        // cin >> myreq.ProtocolInfo;
        cout << "Mac地址 TThostFtdcMacAddressType:" << endl;
        // cin >> myreq.MacAddress;
        cout << "动态密码 TThostFtdcPasswordType:" << endl;
        // cin >> myreq.OneTimePassword;
        cout << "终端IP地址 TThostFtdcIPAddressType:" << endl;
        // cin >> myreq.ClientIPAddress;
        int i = userapi->ReqUserLogin(&myreq, ++reqid);
        return i;
}

int CMdSpi::reqUserLogout()
{
        CThostFtdcUserLogoutField myreq = CThostFtdcUserLogoutField();
        memset(&myreq, 0, sizeof(myreq));
        cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
        strcpy(myreq.BrokerID, broker_id.c_str());
        cout << "用户代码 TThostFtdcUserIDType:" << endl;
        strcpy(myreq.UserID, user_id.c_str());
        int i = userapi->ReqUserLogout(&myreq, ++reqid);
        return i;
}

//-------------------------------------------------------------------------------------
//API回调函数
//-------------------------------------------------------------------------------------

///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
void CMdSpi::OnFrontConnected()
{
        // cerr << "--->>> " << __FUNCTION__ << endl;
        // user login request
        guosen::CtpRtnConnect body_message;
        body_message.set_status(true);
        body_message.set_nreason(0);

        guosen::ProtoMsg proto_message;
        proto_message.set_head(guosen::MsgType::CTP_RTN_CONNECT);
        body_message.SerializeToString(proto_message.mutable_body());
        do_publish(proto_message);

        reqUserLogin();
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

        guosen::CtpRtnConnect body_message;
        body_message.set_status(false);
        body_message.set_nreason(nReason);

        guosen::ProtoMsg proto_message;
        proto_message.set_head(guosen::MsgType::CTP_RTN_CONNECT);
        body_message.SerializeToString(proto_message.mutable_body());

        do_publish(proto_message);
}

///心跳超时警告。当长时间未收到报文时，该方法被调用。
///@param nTimeLapse 距离上次接收报文的时间
void CMdSpi::OnHeartBeatWarning(int nTimeLapse)
{
        // cerr << "--->>> " << __FUNCTION__ << endl;
        // cerr << "--->>> nTimerLapse = " << nTimeLapse << endl;
        guosen::CtpHeartWarning body_message;
        body_message.set_ntimelapse(nTimeLapse);

        guosen::ProtoMsg proto_message;
        proto_message.set_head(guosen::MsgType::ctpheartwarning);
        body_message.SerializeToString(proto_message.mutable_body());

        do_publish(proto_message);
}

///登录请求响应
void CMdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
        // cout << "--->>> " << __FUNCTION__ << endl;
        // if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
        //         cout << "交易日 TThostFtdcDateType:" << pRspUserLogin->TradingDay << endl;
        //         cout << "登录成功时间 TThostFtdcTimeType:" << pRspUserLogin->LoginTime << endl;
        //         cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pRspUserLogin->BrokerID << endl;
        //         cout << "用户代码 TThostFtdcUserIDType:" << pRspUserLogin->UserID << endl;
        //         cout << "交易系统名称 TThostFtdcSystemNameType:" << pRspUserLogin->SystemName << endl;
        //         cout << "前置编号 TThostFtdcFrontIDType:" << pRspUserLogin->FrontID << endl;
        //         cout << "会话编号 TThostFtdcSessionIDType:" << pRspUserLogin->SessionID << endl;
        //         cout << "最大报单引用 TThostFtdcOrderRefType:" << pRspUserLogin->MaxOrderRef << endl;
        //         cout << "上期所时间 TThostFtdcTimeType:" << pRspUserLogin->SHFETime << endl;
        //         cout << "大商所时间 TThostFtdcTimeType:" << pRspUserLogin->DCETime << endl;
        //         cout << "郑商所时间 TThostFtdcTimeType:" << pRspUserLogin->CZCETime << endl;
        //         cout << "中金所时间 TThostFtdcTimeType:" << pRspUserLogin->FFEXTime << endl;
        //         cout << "能源中心时间 TThostFtdcTimeType:" << pRspUserLogin->INETime << endl;
        //
        //         // front_id = pRspUserLogin->FrontID;
        //         // session_id = pRspUserLogin->SessionID;
        //         // login_status = true;
        //         // order_ref = pRspUserLogin->MaxOrderRef;
        // }
        if (IsErrorRspInfo(pRspInfo) or pRspUserLogin == NULL)
                return;

        guosen::CtpRspLogin body_message;
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

        guosen::ProtoMsg proto_message;
        proto_message.set_head(guosen::MsgType::CTP_RTN_CONNECT);
        body_message.SerializeToString(proto_message.mutable_body());

        do_publish(proto_message);

        subscribeAllMarketData();
}

///登出请求响应
void CMdSpi::OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
        // cout << "--->>> " << __FUNCTION__ << endl;
        // if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
        //         cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pUserLogout->BrokerID << endl;
        //         cout << "用户代码 TThostFtdcUserIDType:" << pUserLogout->UserID << endl;
        // }

        guosen::CtpRspLogout body_message;
        body_message.set_brokerid(pUserLogout->BrokerID);
        body_message.set_userid(pUserLogout->UserID);

        guosen::ProtoMsg proto_message;
        proto_message.set_head(guosen::MsgType::ctprsplogout);
        body_message.SerializeToString(proto_message.mutable_body());

        do_publish(proto_message);
}

///错误应答
void CMdSpi::OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
        cerr << "--->>> " << __FUNCTION__ << endl;
}

///订阅行情应答
void CMdSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
        cout << "--->>> " << __FUNCTION__ << endl;
        if (pSpecificInstrument != NULL && !IsErrorRspInfo(pRspInfo)) {
                cout << pSpecificInstrument->InstrumentID << endl;
                // cout << "SubscribeMarketData success!" << endl;
        }
}

///取消订阅行情应答
void CMdSpi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
        cout << "--->>> " << __FUNCTION__ << endl;
        if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
                cout << "unSubscribeMarketData success!" << endl;
        }
}

///订阅询价应答
void CMdSpi::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
}
///取消订阅询价应答
void CMdSpi::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
}

///深度行情通知
void CMdSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData)
{

        if (pDepthMarketData == NULL) {
                cout << "p is null ,no data" << endl;
                return;
        }

        guosen::CtpRtnTick body_message;

        body_message.set_exchangeid(pDepthMarketData->ExchangeID);
        body_message.set_exchangeinstid(pDepthMarketData->ExchangeInstID);
        body_message.set_updatetime(pDepthMarketData->UpdateTime);
        body_message.set_instrumentid(pDepthMarketData->InstrumentID);             //原始Code
        body_message.set_actionday(pDepthMarketData->ActionDay);                   //业务发生日(自然日)
        body_message.set_tradingday(pDepthMarketData->TradingDay);                 //交易日
        body_message.set_updatemillisec(pDepthMarketData->UpdateMillisec);         //时间(HHMMSSmmm)
        body_message.set_preopeninterest(pDepthMarketData->PreOpenInterest);       //昨持仓
        body_message.set_precloseprice(pDepthMarketData->PreClosePrice);           //昨收盘价
        body_message.set_presettlementprice(pDepthMarketData->PreSettlementPrice); //昨结算
        body_message.set_openprice(pDepthMarketData->OpenPrice);                   //开盘价
        body_message.set_highestprice(pDepthMarketData->HighestPrice);             //最高价
        body_message.set_lowestprice(pDepthMarketData->LowestPrice);               //最低价
        body_message.set_lastprice(pDepthMarketData->LastPrice);                   //最新价
        body_message.set_volume(pDepthMarketData->Volume);                         //成交总量
        body_message.set_turnover(pDepthMarketData->Turnover);                     //成交总金额
        body_message.set_openinterest(pDepthMarketData->OpenInterest);             //持仓总量
        body_message.set_closeprice(pDepthMarketData->ClosePrice);                 //今收盘
        body_message.set_settlementprice(pDepthMarketData->SettlementPrice);       //今结算
        body_message.set_upperlimitprice(pDepthMarketData->UpperLimitPrice);       //涨停价
        body_message.set_lowerlimitprice(pDepthMarketData->LowerLimitPrice);       //跌停价
        body_message.set_predelta(pDepthMarketData->PreDelta);                     //昨虚实度
        body_message.set_currdelta(pDepthMarketData->CurrDelta);                   //今虚实度

        body_message.set_askprice1(pDepthMarketData->AskPrice1); //申卖价
        body_message.set_askprice2(pDepthMarketData->AskPrice2); //申卖价
        body_message.set_askprice3(pDepthMarketData->AskPrice3); //申卖价
        body_message.set_askprice4(pDepthMarketData->AskPrice4); //申卖价
        body_message.set_askprice5(pDepthMarketData->AskPrice5); //申卖价

        body_message.set_askvolume1(pDepthMarketData->AskVolume1); //申卖量
        body_message.set_askvolume2(pDepthMarketData->AskVolume2); //申卖量
        body_message.set_askvolume3(pDepthMarketData->AskVolume3); //申卖量
        body_message.set_askvolume4(pDepthMarketData->AskVolume4); //申卖量
        body_message.set_askvolume5(pDepthMarketData->AskVolume5); //申卖量

        body_message.set_bidprice1(pDepthMarketData->BidPrice1); //申买价
        body_message.set_bidprice2(pDepthMarketData->BidPrice2); //申买价
        body_message.set_bidprice3(pDepthMarketData->BidPrice3); //申买价
        body_message.set_bidprice4(pDepthMarketData->BidPrice4); //申买价
        body_message.set_bidprice5(pDepthMarketData->BidPrice5); //申买价

        body_message.set_bidvolume1(pDepthMarketData->BidVolume1);     //申买量
        body_message.set_bidvolume2(pDepthMarketData->BidVolume2);     //申买量
        body_message.set_bidvolume3(pDepthMarketData->BidVolume3);     //申买量
        body_message.set_bidvolume4(pDepthMarketData->BidVolume4);     //申买量
        body_message.set_bidvolume5(pDepthMarketData->BidVolume5);     //申买量
        body_message.set_averageprice(pDepthMarketData->AveragePrice); //郑商所期货均价

        // cout << "szcode:" << td.szcode() << endl;
        // cout << "ntime:" << td.time() << endl;
        // cout << "open:" << td.open() << endl;
        // cout << "high:" << td.high() << endl;
        // cout << "close:" << td.last() << endl;
        //

        guosen::ProtoMsg proto_message;
        proto_message.set_head(guosen::MsgType::CTP_RTN_TICK);
        body_message.SerializeToString(proto_message.mutable_body());

        do_publish(proto_message);
}

///询价通知
void CMdSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp) {}
