// #pragma once
#include "FileUtils.h"
#include "ThostFtdcTraderApi.h"

class CTraderSpi : public CThostFtdcTraderSpi {

    private:
        CThostFtdcTraderApi* userapi;
        // map<string,string> config_info;
        string broker_id;
        string passwd;
        string user_id;
        int nRequestID;

        //TODO:变量初始化
        string auth_code;
        string user_product_info;

        bool connection_status;
        bool login_status;
        bool auth_status;
        bool login_failed;

        int session_id;
        string front_id;
        
        string order_ref;

        bool require_auth;
    public:
        //-------------------------------------------------------------------------------------
        //req:主动函数的请求字典
        //-------------------------------------------------------------------------------------

        CTraderSpi()
            : nRequestID(0)
            , user_id("")
            , passwd("")
            , broker_id("")
            , front_id("")
            , userapi(NULL)
            , auth_code("")
            , user_product_info("")
        {
        }

        int exit();

        void subscribePrivateTopic(int nType);

        void subscribePublicTopic(int nType);

        void reqAuthenticate();

        void reqUserLogin();

        void reqUserLogout();

        void reqUserPasswordUpdate();

        void reqTradingAccountPasswordUpdate();

        void reqOrderInsert();

        void reqParkedOrderInsert();

        void reqParkedOrderAction();

        void reqOrderAction();

        void reqQueryMaxOrderVolume();

        void reqSettlementInfoConfirm();

        void reqRemoveParkedOrder();

        void reqRemoveParkedOrderAction();

        void reqExecOrderInsert();

        void reqExecOrderAction();

        void reqForQuoteInsert();

        void reqQuoteInsert();

        void reqQuoteAction();

        void reqLockInsert();

        void reqCombActionInsert();

        void reqQryOrder();

        void reqQryTrade();

        void reqQryInvestorPosition();

        void reqQryTradingAccount();

        void reqQryInvestor();

        void reqQryTradingCode();

        void reqQryInstrumentMarginRate();

        void reqQryInstrumentCommissionRate();

        void reqQryExchange();

        void reqQryProduct();

        void reqQryInstrument();

        void reqQryDepthMarketData();

        void reqQrySettlementInfo();

        void reqQryTransferBank();

        void reqQryInvestorPositionDetail();

        void reqQryNotice();

        void reqQrySettlementInfoConfirm();

        void reqQryInvestorPositionCombineDetail();

        void reqQryCFMMCTradingAccountKey();

        void reqQryEWarrantOffset();

        void reqQryInvestorProductGroupMargin();

        void reqQryExchangeMarginRate();

        void reqQryExchangeMarginRateAdjust();

        void reqQryExchangeRate();

        void reqQrySecAgentACIDMap();

        void reqQryProductExchRate();

        void reqQryProductGroup();

        void reqQryOptionInstrTradeCost();

        void reqQryOptionInstrCommRate();

        void reqQryExecOrder();

        void reqQryForQuote();

        void reqQryQuote();

        void reqQryLock();

        void reqQryLockPosition();

        void reqQryInvestorLevel();

        void reqQryExecFreeze();

        void reqQryCombInstrumentGuard();

        void reqQryCombAction();

        void reqQryTransferSerial();

        void reqQryAccountregister();

        void reqQryContractBank();

        void reqQryParkedOrder();

        void reqQryParkedOrderAction();

        void reqQryTradingNotice();

        void reqQryBrokerTradingParams();

        void reqQryBrokerTradingAlgos();

        void reqQueryCFMMCTradingAccountToken();

        void reqFromBankToFutureByFuture();

        void reqFromFutureToBankByFuture();

        void reqQueryBankAccountMoneyByFuture();

        void TestAllFunction();

        void PrintAllFunction();

        bool IsErrorRspInfo(CThostFtdcRspInfoField* pRspInfo);

        inline void load_config(const Document& d)
        {
                broker_id = d["broker_id"].GetString();
                user_id = d["user_id"].GetString();
                passwd = d["passwd"].GetString();
                front_id = d["td_address"].GetString();
        }

        inline void connect()
        {
                if (userapi == nullptr) {
                        //userapi = CThostFtdcTraderApi::CreateFtdcTraderApi("./log/trader/"); // 创建UserApi
                        userapi = CThostFtdcTraderApi::CreateFtdcTraderApi(); // 创建UserApi

                        if (!userapi) {
                                throw "CtpTrader failed to create api";
                        }
                        userapi->RegisterSpi(this);
                }

                userapi->RegisterFront(const_cast<char*>(front_id.c_str())); // connect
                // userapi->RegisterFront("tcp://180.169.101.178:41205"); // connect
                // userapi->SubscribePublicTopic(THOST_TERT_QUICK);       // need check
                // userapi->SubscribePublicTopic(THOST_TERT_QUICK);       // need check
                userapi->SubscribePrivateTopic(THOST_TERT_RESTART); // need check
                userapi->SubscribePrivateTopic(THOST_TERT_RESTART); // need check
                userapi->Init();
                userapi->Join();
        }

    public:
        ///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
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

        ///客户端认证响应
        virtual void OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///登录请求响应
        virtual void OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///登出请求响应
        virtual void OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///用户口令更新请求响应
        virtual void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///资金账户口令更新请求响应
        virtual void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///报单录入请求响应
        virtual void OnRspOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///预埋单录入请求响应
        virtual void OnRspParkedOrderInsert(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///预埋撤单录入请求响应
        virtual void OnRspParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///报单操作请求响应
        virtual void OnRspOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///查询最大报单数量响应
        virtual void OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField* pQueryMaxOrderVolume, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///投资者结算结果确认响应
        virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///删除预埋单响应
        virtual void OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///删除预埋撤单响应
        virtual void OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///执行宣告录入请求响应
        virtual void OnRspExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///执行宣告操作请求响应
        virtual void OnRspExecOrderAction(CThostFtdcInputExecOrderActionField* pInputExecOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///询价录入请求响应
        virtual void OnRspForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///报价录入请求响应
        virtual void OnRspQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///报价操作请求响应
        virtual void OnRspQuoteAction(CThostFtdcInputQuoteActionField* pInputQuoteAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///锁定应答
        virtual void OnRspLockInsert(CThostFtdcInputLockField* pInputLock, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///申请组合录入请求响应
        virtual void OnRspCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询报单响应
        virtual void OnRspQryOrder(CThostFtdcOrderField* pOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询成交响应
        virtual void OnRspQryTrade(CThostFtdcTradeField* pTrade, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询投资者持仓响应
        virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField* pInvestorPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询资金账户响应
        virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询投资者响应
        virtual void OnRspQryInvestor(CThostFtdcInvestorField* pInvestor, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询交易编码响应
        virtual void OnRspQryTradingCode(CThostFtdcTradingCodeField* pTradingCode, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询合约保证金率响应
        virtual void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField* pInstrumentMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询合约手续费率响应
        virtual void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField* pInstrumentCommissionRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询交易所响应
        virtual void OnRspQryExchange(CThostFtdcExchangeField* pExchange, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询产品响应
        virtual void OnRspQryProduct(CThostFtdcProductField* pProduct, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询合约响应
        virtual void OnRspQryInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询行情响应
        virtual void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询投资者结算结果响应
        virtual void OnRspQrySettlementInfo(CThostFtdcSettlementInfoField* pSettlementInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询转帐银行响应
        virtual void OnRspQryTransferBank(CThostFtdcTransferBankField* pTransferBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询投资者持仓明细响应
        virtual void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField* pInvestorPositionDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询客户通知响应
        virtual void OnRspQryNotice(CThostFtdcNoticeField* pNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询结算信息确认响应
        virtual void OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询投资者持仓明细响应
        virtual void OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField* pInvestorPositionCombineDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///查询保证金监管系统经纪公司资金账户密钥响应
        virtual void OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField* pCFMMCTradingAccountKey, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询仓单折抵信息响应
        virtual void OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField* pEWarrantOffset, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询投资者品种/跨品种保证金响应
        virtual void OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField* pInvestorProductGroupMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询交易所保证金率响应
        virtual void OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField* pExchangeMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询交易所调整保证金率响应
        virtual void OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField* pExchangeMarginRateAdjust, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询汇率响应
        virtual void OnRspQryExchangeRate(CThostFtdcExchangeRateField* pExchangeRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询二级代理操作员银期权限响应
        virtual void OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField* pSecAgentACIDMap, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询产品报价汇率
        virtual void OnRspQryProductExchRate(CThostFtdcProductExchRateField* pProductExchRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询产品组
        virtual void OnRspQryProductGroup(CThostFtdcProductGroupField* pProductGroup, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询期权交易成本响应
        virtual void OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField* pOptionInstrTradeCost, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询期权合约手续费响应
        virtual void OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField* pOptionInstrCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询执行宣告响应
        virtual void OnRspQryExecOrder(CThostFtdcExecOrderField* pExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询询价响应
        virtual void OnRspQryForQuote(CThostFtdcForQuoteField* pForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询报价响应
        virtual void OnRspQryQuote(CThostFtdcQuoteField* pQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询锁定应答
        virtual void OnRspQryLock(CThostFtdcLockField* pLock, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询锁定证券仓位应答
        virtual void OnRspQryLockPosition(CThostFtdcLockPositionField* pLockPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询投资者分级
        virtual void OnRspQryInvestorLevel(CThostFtdcInvestorLevelField* pInvestorLevel, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询E+1日行权冻结响应
        virtual void OnRspQryExecFreeze(CThostFtdcExecFreezeField* pExecFreeze, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询组合合约安全系数响应
        virtual void OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField* pCombInstrumentGuard, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询申请组合响应
        virtual void OnRspQryCombAction(CThostFtdcCombActionField* pCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询转帐流水响应
        virtual void OnRspQryTransferSerial(CThostFtdcTransferSerialField* pTransferSerial, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询银期签约关系响应
        virtual void OnRspQryAccountregister(CThostFtdcAccountregisterField* pAccountregister, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///错误应答
        virtual void OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///报单通知
        virtual void OnRtnOrder(CThostFtdcOrderField* pOrder);

        ///成交通知
        virtual void OnRtnTrade(CThostFtdcTradeField* pTrade);

        ///报单录入错误回报
        virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo);

        ///报单操作错误回报
        virtual void OnErrRtnOrderAction(CThostFtdcOrderActionField* pOrderAction, CThostFtdcRspInfoField* pRspInfo);

        ///合约交易状态通知
        virtual void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField* pInstrumentStatus);

        ///交易通知
        virtual void OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField* pTradingNoticeInfo);

        ///提示条件单校验错误
        virtual void OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField* pErrorConditionalOrder);

        ///执行宣告通知
        virtual void OnRtnExecOrder(CThostFtdcExecOrderField* pExecOrder);

        ///执行宣告录入错误回报
        virtual void OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo);

        ///执行宣告操作错误回报
        virtual void OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField* pExecOrderAction, CThostFtdcRspInfoField* pRspInfo);

        ///询价录入错误回报
        virtual void OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo);

        ///报价通知
        virtual void OnRtnQuote(CThostFtdcQuoteField* pQuote);

        ///报价录入错误回报
        virtual void OnErrRtnQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo);

        ///报价操作错误回报
        virtual void OnErrRtnQuoteAction(CThostFtdcQuoteActionField* pQuoteAction, CThostFtdcRspInfoField* pRspInfo);

        ///询价通知
        virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp);

        ///保证金监控中心用户令牌
        virtual void OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField* pCFMMCTradingAccountToken);

        ///锁定通知
        virtual void OnRtnLock(CThostFtdcLockField* pLock);

        ///锁定错误通知
        virtual void OnErrRtnLockInsert(CThostFtdcInputLockField* pInputLock, CThostFtdcRspInfoField* pRspInfo);

        ///申请组合通知
        virtual void OnRtnCombAction(CThostFtdcCombActionField* pCombAction);

        ///申请组合录入错误回报
        virtual void OnErrRtnCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo);

        ///请求查询签约银行响应
        virtual void OnRspQryContractBank(CThostFtdcContractBankField* pContractBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询预埋单响应
        virtual void OnRspQryParkedOrder(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询预埋撤单响应
        virtual void OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询交易通知响应
        virtual void OnRspQryTradingNotice(CThostFtdcTradingNoticeField* pTradingNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询经纪公司交易参数响应
        virtual void OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField* pBrokerTradingParams, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询经纪公司交易算法响应
        virtual void OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField* pBrokerTradingAlgos, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///请求查询监控中心用户令牌
        virtual void OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///银行发起银行资金转期货通知
        virtual void OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField* pRspTransfer);

        ///银行发起期货资金转银行通知
        virtual void OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField* pRspTransfer);

        ///银行发起冲正银行转期货通知
        virtual void OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField* pRspRepeal);

        ///银行发起冲正期货转银行通知
        virtual void OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField* pRspRepeal);

        ///期货发起银行资金转期货通知
        virtual void OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField* pRspTransfer);

        ///期货发起期货资金转银行通知
        virtual void OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField* pRspTransfer);

        ///系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
        virtual void OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField* pRspRepeal);

        ///系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
        virtual void OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField* pRspRepeal);

        ///期货发起查询银行余额通知
        virtual void OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField* pNotifyQueryAccount);

        ///期货发起银行资金转期货错误回报
        virtual void OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo);

        ///期货发起期货资金转银行错误回报
        virtual void OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo);

        ///系统运行时期货端手工发起冲正银行转期货错误回报
        virtual void OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo);

        ///系统运行时期货端手工发起冲正期货转银行错误回报
        virtual void OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo);

        ///期货发起查询银行余额错误回报
        virtual void OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo);

        ///期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
        virtual void OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField* pRspRepeal);

        ///期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
        virtual void OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField* pRspRepeal);

        ///期货发起银行资金转期货应答
        virtual void OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///期货发起期货资金转银行应答
        virtual void OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///期货发起查询银行余额应答
        virtual void OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///银行发起银期开户通知
        virtual void OnRtnOpenAccountByBank(CThostFtdcOpenAccountField* pOpenAccount);

        ///银行发起银期销户通知
        virtual void OnRtnCancelAccountByBank(CThostFtdcCancelAccountField* pCancelAccount);

        ///银行发起变更银行账号通知
        virtual void OnRtnChangeAccountByBank(CThostFtdcChangeAccountField* pChangeAccount);
};

