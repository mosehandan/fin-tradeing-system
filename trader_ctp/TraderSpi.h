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

        //TODO:������ʼ��
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
        //req:���������������ֵ�
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
                        //userapi = CThostFtdcTraderApi::CreateFtdcTraderApi("./log/trader/"); // ����UserApi
                        userapi = CThostFtdcTraderApi::CreateFtdcTraderApi(); // ����UserApi

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
        ///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
        virtual void OnFrontConnected();

        ///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
        ///@param nReason ����ԭ��
        ///        0x1001 �����ʧ��
        ///        0x1002 ����дʧ��
        ///        0x2001 ����������ʱ
        ///        0x2002 ��������ʧ��
        ///        0x2003 �յ�������
        virtual void OnFrontDisconnected(int nReason);

        ///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
        ///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
        virtual void OnHeartBeatWarning(int nTimeLapse);

        ///�ͻ�����֤��Ӧ
        virtual void OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///��¼������Ӧ
        virtual void OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�ǳ�������Ӧ
        virtual void OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�û��������������Ӧ
        virtual void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�ʽ��˻��������������Ӧ
        virtual void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///����¼��������Ӧ
        virtual void OnRspOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///Ԥ��¼��������Ӧ
        virtual void OnRspParkedOrderInsert(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///Ԥ�񳷵�¼��������Ӧ
        virtual void OnRspParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///��������������Ӧ
        virtual void OnRspOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///��ѯ��󱨵�������Ӧ
        virtual void OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField* pQueryMaxOrderVolume, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///Ͷ���߽�����ȷ����Ӧ
        virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///ɾ��Ԥ����Ӧ
        virtual void OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///ɾ��Ԥ�񳷵���Ӧ
        virtual void OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///ִ������¼��������Ӧ
        virtual void OnRspExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///ִ���������������Ӧ
        virtual void OnRspExecOrderAction(CThostFtdcInputExecOrderActionField* pInputExecOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///ѯ��¼��������Ӧ
        virtual void OnRspForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///����¼��������Ӧ
        virtual void OnRspQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///���۲���������Ӧ
        virtual void OnRspQuoteAction(CThostFtdcInputQuoteActionField* pInputQuoteAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///����Ӧ��
        virtual void OnRspLockInsert(CThostFtdcInputLockField* pInputLock, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�������¼��������Ӧ
        virtual void OnRspCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ������Ӧ
        virtual void OnRspQryOrder(CThostFtdcOrderField* pOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ�ɽ���Ӧ
        virtual void OnRspQryTrade(CThostFtdcTradeField* pTrade, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯͶ���ֲ߳���Ӧ
        virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField* pInvestorPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ�ʽ��˻���Ӧ
        virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯͶ������Ӧ
        virtual void OnRspQryInvestor(CThostFtdcInvestorField* pInvestor, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ���ױ�����Ӧ
        virtual void OnRspQryTradingCode(CThostFtdcTradingCodeField* pTradingCode, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ��Լ��֤������Ӧ
        virtual void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField* pInstrumentMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ��Լ����������Ӧ
        virtual void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField* pInstrumentCommissionRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ��������Ӧ
        virtual void OnRspQryExchange(CThostFtdcExchangeField* pExchange, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ��Ʒ��Ӧ
        virtual void OnRspQryProduct(CThostFtdcProductField* pProduct, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ��Լ��Ӧ
        virtual void OnRspQryInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ������Ӧ
        virtual void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯͶ���߽�������Ӧ
        virtual void OnRspQrySettlementInfo(CThostFtdcSettlementInfoField* pSettlementInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯת��������Ӧ
        virtual void OnRspQryTransferBank(CThostFtdcTransferBankField* pTransferBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯͶ���ֲ߳���ϸ��Ӧ
        virtual void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField* pInvestorPositionDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ�ͻ�֪ͨ��Ӧ
        virtual void OnRspQryNotice(CThostFtdcNoticeField* pNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ������Ϣȷ����Ӧ
        virtual void OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯͶ���ֲ߳���ϸ��Ӧ
        virtual void OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField* pInvestorPositionCombineDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///��ѯ��֤����ϵͳ���͹�˾�ʽ��˻���Կ��Ӧ
        virtual void OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField* pCFMMCTradingAccountKey, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ�ֵ��۵���Ϣ��Ӧ
        virtual void OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField* pEWarrantOffset, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯͶ����Ʒ��/��Ʒ�ֱ�֤����Ӧ
        virtual void OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField* pInvestorProductGroupMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ��������֤������Ӧ
        virtual void OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField* pExchangeMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ������������֤������Ӧ
        virtual void OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField* pExchangeMarginRateAdjust, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ������Ӧ
        virtual void OnRspQryExchangeRate(CThostFtdcExchangeRateField* pExchangeRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ�����������Ա����Ȩ����Ӧ
        virtual void OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField* pSecAgentACIDMap, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ��Ʒ���ۻ���
        virtual void OnRspQryProductExchRate(CThostFtdcProductExchRateField* pProductExchRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ��Ʒ��
        virtual void OnRspQryProductGroup(CThostFtdcProductGroupField* pProductGroup, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ��Ȩ���׳ɱ���Ӧ
        virtual void OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField* pOptionInstrTradeCost, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ��Ȩ��Լ��������Ӧ
        virtual void OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField* pOptionInstrCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯִ��������Ӧ
        virtual void OnRspQryExecOrder(CThostFtdcExecOrderField* pExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯѯ����Ӧ
        virtual void OnRspQryForQuote(CThostFtdcForQuoteField* pForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ������Ӧ
        virtual void OnRspQryQuote(CThostFtdcQuoteField* pQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ����Ӧ��
        virtual void OnRspQryLock(CThostFtdcLockField* pLock, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ����֤ȯ��λӦ��
        virtual void OnRspQryLockPosition(CThostFtdcLockPositionField* pLockPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯͶ���߷ּ�
        virtual void OnRspQryInvestorLevel(CThostFtdcInvestorLevelField* pInvestorLevel, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯE+1����Ȩ������Ӧ
        virtual void OnRspQryExecFreeze(CThostFtdcExecFreezeField* pExecFreeze, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ��Ϻ�Լ��ȫϵ����Ӧ
        virtual void OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField* pCombInstrumentGuard, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ���������Ӧ
        virtual void OnRspQryCombAction(CThostFtdcCombActionField* pCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯת����ˮ��Ӧ
        virtual void OnRspQryTransferSerial(CThostFtdcTransferSerialField* pTransferSerial, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ����ǩԼ��ϵ��Ӧ
        virtual void OnRspQryAccountregister(CThostFtdcAccountregisterField* pAccountregister, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///����Ӧ��
        virtual void OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///����֪ͨ
        virtual void OnRtnOrder(CThostFtdcOrderField* pOrder);

        ///�ɽ�֪ͨ
        virtual void OnRtnTrade(CThostFtdcTradeField* pTrade);

        ///����¼�����ر�
        virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo);

        ///������������ر�
        virtual void OnErrRtnOrderAction(CThostFtdcOrderActionField* pOrderAction, CThostFtdcRspInfoField* pRspInfo);

        ///��Լ����״̬֪ͨ
        virtual void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField* pInstrumentStatus);

        ///����֪ͨ
        virtual void OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField* pTradingNoticeInfo);

        ///��ʾ������У�����
        virtual void OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField* pErrorConditionalOrder);

        ///ִ������֪ͨ
        virtual void OnRtnExecOrder(CThostFtdcExecOrderField* pExecOrder);

        ///ִ������¼�����ر�
        virtual void OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo);

        ///ִ�������������ر�
        virtual void OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField* pExecOrderAction, CThostFtdcRspInfoField* pRspInfo);

        ///ѯ��¼�����ر�
        virtual void OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo);

        ///����֪ͨ
        virtual void OnRtnQuote(CThostFtdcQuoteField* pQuote);

        ///����¼�����ر�
        virtual void OnErrRtnQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo);

        ///���۲�������ر�
        virtual void OnErrRtnQuoteAction(CThostFtdcQuoteActionField* pQuoteAction, CThostFtdcRspInfoField* pRspInfo);

        ///ѯ��֪ͨ
        virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp);

        ///��֤���������û�����
        virtual void OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField* pCFMMCTradingAccountToken);

        ///����֪ͨ
        virtual void OnRtnLock(CThostFtdcLockField* pLock);

        ///��������֪ͨ
        virtual void OnErrRtnLockInsert(CThostFtdcInputLockField* pInputLock, CThostFtdcRspInfoField* pRspInfo);

        ///�������֪ͨ
        virtual void OnRtnCombAction(CThostFtdcCombActionField* pCombAction);

        ///�������¼�����ر�
        virtual void OnErrRtnCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo);

        ///�����ѯǩԼ������Ӧ
        virtual void OnRspQryContractBank(CThostFtdcContractBankField* pContractBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯԤ����Ӧ
        virtual void OnRspQryParkedOrder(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯԤ�񳷵���Ӧ
        virtual void OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ����֪ͨ��Ӧ
        virtual void OnRspQryTradingNotice(CThostFtdcTradingNoticeField* pTradingNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ���͹�˾���ײ�����Ӧ
        virtual void OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField* pBrokerTradingParams, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ���͹�˾�����㷨��Ӧ
        virtual void OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField* pBrokerTradingAlgos, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�����ѯ��������û�����
        virtual void OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///���з��������ʽ�ת�ڻ�֪ͨ
        virtual void OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField* pRspTransfer);

        ///���з����ڻ��ʽ�ת����֪ͨ
        virtual void OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField* pRspTransfer);

        ///���з����������ת�ڻ�֪ͨ
        virtual void OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField* pRspRepeal);

        ///���з�������ڻ�ת����֪ͨ
        virtual void OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField* pRspRepeal);

        ///�ڻ����������ʽ�ת�ڻ�֪ͨ
        virtual void OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField* pRspTransfer);

        ///�ڻ������ڻ��ʽ�ת����֪ͨ
        virtual void OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField* pRspTransfer);

        ///ϵͳ����ʱ�ڻ����ֹ������������ת�ڻ��������д�����Ϻ��̷��ص�֪ͨ
        virtual void OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField* pRspRepeal);

        ///ϵͳ����ʱ�ڻ����ֹ���������ڻ�ת�����������д�����Ϻ��̷��ص�֪ͨ
        virtual void OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField* pRspRepeal);

        ///�ڻ������ѯ�������֪ͨ
        virtual void OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField* pNotifyQueryAccount);

        ///�ڻ����������ʽ�ת�ڻ�����ر�
        virtual void OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo);

        ///�ڻ������ڻ��ʽ�ת���д���ر�
        virtual void OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo);

        ///ϵͳ����ʱ�ڻ����ֹ������������ת�ڻ�����ر�
        virtual void OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo);

        ///ϵͳ����ʱ�ڻ����ֹ���������ڻ�ת���д���ر�
        virtual void OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo);

        ///�ڻ������ѯ����������ر�
        virtual void OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo);

        ///�ڻ������������ת�ڻ��������д�����Ϻ��̷��ص�֪ͨ
        virtual void OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField* pRspRepeal);

        ///�ڻ���������ڻ�ת�����������д�����Ϻ��̷��ص�֪ͨ
        virtual void OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField* pRspRepeal);

        ///�ڻ����������ʽ�ת�ڻ�Ӧ��
        virtual void OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�ڻ������ڻ��ʽ�ת����Ӧ��
        virtual void OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///�ڻ������ѯ�������Ӧ��
        virtual void OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

        ///���з������ڿ���֪ͨ
        virtual void OnRtnOpenAccountByBank(CThostFtdcOpenAccountField* pOpenAccount);

        ///���з�����������֪ͨ
        virtual void OnRtnCancelAccountByBank(CThostFtdcCancelAccountField* pCancelAccount);

        ///���з����������˺�֪ͨ
        virtual void OnRtnChangeAccountByBank(CThostFtdcChangeAccountField* pChangeAccount);
};

