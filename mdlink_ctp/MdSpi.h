#pragma once
#include "ctpmessage.pb.h"
#include "FileUtils.h"
#include "ThostFtdcMdApi.h"
#include <string>

using namespace std;

class CMdSpi : public CThostFtdcMdSpi {
    private:
        CThostFtdcMdApi* userapi;
        string broker_id;
        string user_id;
        string passwd;
        string front_id;
        bool login_status;
        bool connection_status;
        int nRequestID;

    public:
        //-------------------------------------------------------------------------------------
        //req:主动函数的请求字典
        //-------------------------------------------------------------------------------------

        CMdSpi()
            : userapi(nullptr)
            , broker_id("")
            , user_id("")
            , passwd("")
            , front_id("")
            , nRequestID(0)
            , connection_status(false)
            , login_status(false)
        {
        }

        string getTradingDay() { return userapi->GetTradingDay(); }

        int exit();

        void subscribeAllMarketData();

        void subscribeMarketData(const vector<string>& instruments);

        int unSubscribeMarketData(string instrumentID);

        int subscribeForQuoteRsp(string instrumentID);

        int unSubscribeForQuoteRsp(string instrumentID);

        int reqUserLogin(guosen::msg::ctp::CThostFtdcReqUserLoginField req);

        int reqUserLogout(guosen::msg::ctp::CThostFtdcUserLogoutField req);

        bool IsErrorRspInfo(CThostFtdcRspInfoField* pRspInfo);

        void load_config(const Document& d);

        void connect();

        //-------------------------------------------------------------------------------------
        //api回调函数
        //-------------------------------------------------------------------------------------

        virtual void OnFrontConnected();

        ///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
        ///@param nReason 错误原因
        ///        0x1001 网络读失败
        ///        0x1002 网络写失败
        ///        0x2001 接收心跳超时
        ///        0x2002 发送心跳失败
        ///        0x2003 收到错误报文
        virtual void OnFrontDisconnected(int nReason);

        ///心跳超时警告。当长时间未收到报文时，该方法被调用。
        ///@param nTimeLapse 距离上次接收报文的时间
        virtual void OnHeartBeatWarning(int nTimeLapse);

        ///登录请求响应
        virtual void OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///登出请求响应
        virtual void OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///错误应答
        virtual void OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///订阅行情应答
        virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///取消订阅行情应答
        virtual void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///订阅询价应答
        virtual void OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///取消订阅询价应答
        virtual void OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///深度行情通知
        virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData);

        ///询价通知
        virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp);
};
