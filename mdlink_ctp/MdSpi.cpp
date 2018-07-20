#include "MdSpi.h"
#include "ctp.pb.h"
#include "zhelpers.hpp"
#include <fstream>
#include <vector>
// #include <stdio.h>

extern Document d;
extern zmq::context_t context;
extern zmq::socket_t publisher;

inline bool CMdSpi::IsErrorRspInfo(CThostFtdcRspInfoField* pRspInfo)
{
        bool bResult = (pRspInfo && pRspInfo->ErrorID != 0);
        if (bResult)
                cerr << "--->>> ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg << endl;
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
        cout << "--->>> " << __FUNCTION__ << endl;
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
        cerr << "--->>>SubscribeMarketData " << ncount << " request: " << ( iResult == 0 ? "success" : "failed") << endl;
}

void CMdSpi::subscribeAllMarketData()
{

        ifstream in("./config/future_contract.txt");

        if (in) {

                string line;
                vector<string> sub_code;

                while (getline(in, line)) {
                        sub_code.push_back(line);
                }
                subscribeMarketData(sub_code);

        } else
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
        cerr << "--->>> " << __FUNCTION__ << endl;
        // user login request
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
        cerr << "--->>> " << __FUNCTION__ << endl;
        cerr << "--->>> Reason = " << nReason << endl;
        // publisher.send("OnFrontDisconnected");
}

///心跳超时警告。当长时间未收到报文时，该方法被调用。
///@param nTimeLapse 距离上次接收报文的时间
void CMdSpi::OnHeartBeatWarning(int nTimeLapse)
{
        cerr << "--->>> " << __FUNCTION__ << endl;
        cerr << "--->>> nTimerLapse = " << nTimeLapse << endl;
}

///登录请求响应
void CMdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
        cout << "--->>> " << __FUNCTION__ << endl;
        if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
                cout << "交易日 TThostFtdcDateType:" << pRspUserLogin->TradingDay << endl;
                cout << "登录成功时间 TThostFtdcTimeType:" << pRspUserLogin->LoginTime << endl;
                cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pRspUserLogin->BrokerID << endl;
                cout << "用户代码 TThostFtdcUserIDType:" << pRspUserLogin->UserID << endl;
                cout << "交易系统名称 TThostFtdcSystemNameType:" << pRspUserLogin->SystemName << endl;
                cout << "前置编号 TThostFtdcFrontIDType:" << pRspUserLogin->FrontID << endl;
                cout << "会话编号 TThostFtdcSessionIDType:" << pRspUserLogin->SessionID << endl;
                cout << "最大报单引用 TThostFtdcOrderRefType:" << pRspUserLogin->MaxOrderRef << endl;
                cout << "上期所时间 TThostFtdcTimeType:" << pRspUserLogin->SHFETime << endl;
                cout << "大商所时间 TThostFtdcTimeType:" << pRspUserLogin->DCETime << endl;
                cout << "郑商所时间 TThostFtdcTimeType:" << pRspUserLogin->CZCETime << endl;
                cout << "中金所时间 TThostFtdcTimeType:" << pRspUserLogin->FFEXTime << endl;
                cout << "能源中心时间 TThostFtdcTimeType:" << pRspUserLogin->INETime << endl;

                // front_id = pRspUserLogin->FrontID;
                // session_id = pRspUserLogin->SessionID;
                // login_status = true;
                // order_ref = pRspUserLogin->MaxOrderRef;
        }

        subscribeAllMarketData();
}

///登出请求响应
void CMdSpi::OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
        cout << "--->>> " << __FUNCTION__ << endl;
        if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
                cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pUserLogout->BrokerID << endl;
                cout << "用户代码 TThostFtdcUserIDType:" << pUserLogout->UserID << endl;
        }
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
        if ( pSpecificInstrument != NULL && !IsErrorRspInfo(pRspInfo)) {
                cout <<  pSpecificInstrument->InstrumentID << endl;
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
        ctp::TDF_FUTURE_DATA td;
        // TODO: 该字段tdf中未使用
        // cerr << "ExchangeID=" << pDepthMarketData->ExchangeID << endl;
        // cerr << "ExchangeInstID=" << pDepthMarketData->ExchangeInstID << endl;
        // cerr << "UpdateTime=" << pDepthMarketData->UpdateTime << endl;

        td.set_szcode(pDepthMarketData->InstrumentID);                //原始Code
        td.set_nactionday(pDepthMarketData->ActionDay);               //业务发生日(自然日)
        td.set_ntradingday(pDepthMarketData->TradingDay);             //交易日
        td.set_ntime(pDepthMarketData->UpdateMillisec);               //时间(HHMMSSmmm)
        td.set_ipreopeninterest(pDepthMarketData->PreOpenInterest);   //昨持仓
        td.set_npreclose(pDepthMarketData->PreClosePrice);            //昨收盘价
        td.set_npresettleprice(pDepthMarketData->PreSettlementPrice); //昨结算
        td.set_nopen(pDepthMarketData->OpenPrice);                    //开盘价
        td.set_nhigh(pDepthMarketData->HighestPrice);                 //最高价
        td.set_nlow(pDepthMarketData->LowestPrice);                   //最低价
        td.set_nmatch(pDepthMarketData->LastPrice);                   //最新价
        td.set_ivolume(pDepthMarketData->Volume);                     //成交总量
        td.set_iturnover(pDepthMarketData->Turnover);                 //成交总金额
        td.set_iopeninterest(pDepthMarketData->OpenInterest);         //持仓总量
        td.set_nclose(pDepthMarketData->ClosePrice);                  //今收盘
        td.set_nsettleprice(pDepthMarketData->SettlementPrice);       //今结算
        td.set_nhighlimited(pDepthMarketData->UpperLimitPrice);       //涨停价
        td.set_nlowlimited(pDepthMarketData->LowerLimitPrice);        //跌停价
        td.set_npredelta(pDepthMarketData->PreDelta);                 //昨虚实度
        td.set_ncurrdelta(pDepthMarketData->CurrDelta);               //今虚实度

        td.add_naskprice(pDepthMarketData->AskPrice1); //申卖价
        td.add_naskprice(pDepthMarketData->AskPrice2); //申卖价
        td.add_naskprice(pDepthMarketData->AskPrice3); //申卖价
        td.add_naskprice(pDepthMarketData->AskPrice4); //申卖价
        td.add_naskprice(pDepthMarketData->AskPrice5); //申卖价

        td.add_naskvol(pDepthMarketData->AskVolume1); //申卖量
        td.add_naskvol(pDepthMarketData->AskVolume2); //申卖量
        td.add_naskvol(pDepthMarketData->AskVolume3); //申卖量
        td.add_naskvol(pDepthMarketData->AskVolume4); //申卖量
        td.add_naskvol(pDepthMarketData->AskVolume5); //申卖量

        td.add_nbidprice(pDepthMarketData->BidPrice1); //申买价
        td.add_nbidprice(pDepthMarketData->BidPrice2); //申买价
        td.add_nbidprice(pDepthMarketData->BidPrice3); //申买价
        td.add_nbidprice(pDepthMarketData->BidPrice4); //申买价
        td.add_nbidprice(pDepthMarketData->BidPrice5); //申买价

        td.add_nbidvol(pDepthMarketData->BidVolume1);     //申买量
        td.add_nbidvol(pDepthMarketData->BidVolume2);     //申买量
        td.add_nbidvol(pDepthMarketData->BidVolume3);     //申买量
        td.add_nbidvol(pDepthMarketData->BidVolume4);     //申买量
        td.add_nbidvol(pDepthMarketData->BidVolume5);     //申买量
        td.set_navgprice(pDepthMarketData->AveragePrice); //郑商所期货均价

        //TODO: 字段ctp行情中没有
        td.set_szwindcode("");   //600001.SH
        td.set_nauctionprice(0); //波动性中断参考价
        td.set_nauctionqty(0);   //波动性中断集合竞价虚拟匹配量
        td.set_nstatus(0);       //状态

        auto msg_size = td.ByteSize();
        zmq::message_t message(msg_size);
        // td.SerializerToString(message.data(),msg_size);
        td.SerializeToArray(message.data(), msg_size);
        // publisher.send(message);
        publisher.send(std::move(message));
}

///询价通知
void CMdSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp) {}
