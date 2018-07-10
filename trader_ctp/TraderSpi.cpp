// #include "ThostFtdcTraderApi.h"
#include "TraderSpi.h"
// #include "zhelpers.hpp"
// #include <chrono>
// #include <thread>

// extern Document d;
// extern zmq::socket_t publisher;
// extern zmq::socket_t reply;

//inline void CTraderSpi::connect()
//{
//	if (userapi == nullptr) {
//		//userapi = CThostFtdcTraderApi::CreateFtdcTraderApi("./log/trader/"); // ����UserApi
//		userapi = CThostFtdcTraderApi::CreateFtdcTraderApi(); // ����UserApi
//
//		if (!userapi) {
//			throw "CtpTrader failed to create api";
//		}
//		userapi->RegisterSpi(this);
//	}
//}

bool CTraderSpi::IsErrorRspInfo(CThostFtdcRspInfoField* pRspInfo)
{
    // ���ErrorID != 0, ˵���յ��˴������Ӧ
    bool bResult = ((pRspInfo) && (pRspInfo->ErrorID != 0));
    if (bResult)
	cout << "--->>> ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg << endl;
    return bResult;
}

void CTraderSpi::TestAllFunction()
{
    int fun_number = 0;
    PrintAllFunction();
    while (1) {
	cout << "������Ҫ���Եĺ������,0Ϊ��ʾ���к���: ";
	cin >> fun_number;
	switch (fun_number) {

	case 1: {
	    reqUserLogin();
	    break;
	}
	case 2: {
	    reqUserLogout();
	    break;
	}
	case 3: {
	    reqUserPasswordUpdate();
	    break;
	}
	case 4: {
	    reqTradingAccountPasswordUpdate();
	    break;
	}
	case 5: {
	    reqOrderInsert();
	    break;
	}
	case 6: {
	    reqParkedOrderInsert();
	    break;
	}
	case 7: {
	    reqParkedOrderAction();
	    break;
	}
	case 8: {
	    reqOrderAction();
	    break;
	}
	case 9: {
	    reqQueryMaxOrderVolume();
	    break;
	}
	case 10: {
	    reqSettlementInfoConfirm();
	    break;
	}
	case 11: {
	    reqRemoveParkedOrder();
	    break;
	}
	case 12: {
	    reqRemoveParkedOrderAction();
	    break;
	}
	case 13: {
	    reqExecOrderInsert();
	    break;
	}
	case 14: {
	    reqExecOrderAction();
	    break;
	}
	case 15: {
	    reqForQuoteInsert();
	    break;
	}
	case 16: {
	    reqQuoteInsert();
	    break;
	}
	case 17: {
	    reqQuoteAction();
	    break;
	}
	case 18: {
	    reqLockInsert();
	    break;
	}
	case 19: {
	    reqCombActionInsert();
	    break;
	}
	case 20: {
	    reqQryOrder();
	    break;
	}
	case 21: {
	    reqQryTrade();
	    break;
	}
	case 22: {
	    reqQryInvestorPosition();
	    break;
	}
	case 23: {
	    reqQryTradingAccount();
	    break;
	}
	case 24: {
	    reqQryInvestor();
	    break;
	}
	case 25: {
	    reqQryTradingCode();
	    break;
	}
	case 26: {
	    reqQryInstrumentMarginRate();
	    break;
	}
	case 27: {
	    reqQryInstrumentCommissionRate();
	    break;
	}
	case 28: {
	    reqQryExchange();
	    break;
	}
	case 29: {
	    reqQryProduct();
	    break;
	}
	case 30: {
	    reqQryInstrument();
	    break;
	}
	case 31: {
	    reqQryDepthMarketData();
	    break;
	}
	case 32: {
	    reqQrySettlementInfo();
	    break;
	}
	case 33: {
	    reqQryTransferBank();
	    break;
	}
	case 34: {
	    reqQryInvestorPositionDetail();
	    break;
	}
	case 35: {
	    reqQryNotice();
	    break;
	}
	case 36: {
	    reqQrySettlementInfoConfirm();
	    break;
	}
	case 37: {
	    reqQryInvestorPositionCombineDetail();
	    break;
	}
	case 38: {
	    reqQryCFMMCTradingAccountKey();
	    break;
	}
	case 39: {
	    reqQryEWarrantOffset();
	    break;
	}
	case 40: {
	    reqQryInvestorProductGroupMargin();
	    break;
	}
	case 41: {
	    reqQryExchangeMarginRate();
	    break;
	}
	case 42: {
	    reqQryExchangeMarginRateAdjust();
	    break;
	}
	case 43: {
	    reqQryExchangeRate();
	    break;
	}
	case 44: {
	    reqQrySecAgentACIDMap();
	    break;
	}
	case 45: {
	    reqQryProductExchRate();
	    break;
	}
	case 46: {
	    reqQryProductGroup();
	    break;
	}
	case 47: {
	    reqQryOptionInstrTradeCost();
	    break;
	}
	case 48: {
	    reqQryOptionInstrCommRate();
	    break;
	}
	case 49: {
	    reqQryExecOrder();
	    break;
	}
	case 50: {
	    reqQryForQuote();
	    break;
	}
	case 51: {
	    reqQryQuote();
	    break;
	}
	case 52: {
	    reqQryLock();
	    break;
	}
	case 53: {
	    reqQryLockPosition();
	    break;
	}
	case 54: {
	    reqQryInvestorLevel();
	    break;
	}
	case 55: {
	    reqQryExecFreeze();
	    break;
	}
	case 56: {
	    reqQryCombInstrumentGuard();
	    break;
	}
	case 57: {
	    reqQryCombAction();
	    break;
	}
	case 58: {
	    reqQryTransferSerial();
	    break;
	}
	case 59: {
	    reqQryAccountregister();
	    break;
	}
	case 60: {
	    reqQryContractBank();
	    break;
	}
	case 61: {
	    reqQryParkedOrder();
	    break;
	}
	case 62: {
	    reqQryParkedOrderAction();
	    break;
	}
	case 63: {
	    reqQryTradingNotice();
	    break;
	}
	case 64: {
	    reqQryBrokerTradingParams();
	    break;
	}
	case 65: {
	    reqQryBrokerTradingAlgos();
	    break;
	}
	case 66: {
	    reqQueryCFMMCTradingAccountToken();
	    break;
	}
	case 67: {
	    reqFromBankToFutureByFuture();
	    break;
	}
	case 68: {
	    reqFromFutureToBankByFuture();
	    break;
	}
	case 69: {
	    reqQueryBankAccountMoneyByFuture();
	    break;
	}
	}
    }
}

void CTraderSpi::PrintAllFunction()
{

    cout << "�ɹ����Եĺ�������:" << endl;
    cout << "1 �û���¼���� ReqUserLogin" << endl;
    cout << "2 �ǳ����� ReqUserLogout" << endl;
    cout << "3 �û������������ ReqUserPasswordUpdate" << endl;
    cout << "4 �ʽ��˻������������ ReqTradingAccountPasswordUpdate" << endl;
    cout << "5 ����¼������ ReqOrderInsert" << endl;
    cout << "6 Ԥ��¼������ ReqParkedOrderInsert" << endl;
    cout << "7 Ԥ�񳷵�¼������ ReqParkedOrderAction" << endl;
    cout << "8 ������������ ReqOrderAction" << endl;
    cout << "9 ��ѯ��󱨵��������� ReqQueryMaxOrderVolume" << endl;
    cout << "10 Ͷ���߽�����ȷ�� ReqSettlementInfoConfirm" << endl;
    cout << "11 ����ɾ��Ԥ�� ReqRemoveParkedOrder" << endl;
    cout << "12 ����ɾ��Ԥ�񳷵� ReqRemoveParkedOrderAction" << endl;
    cout << "13 ִ������¼������ ReqExecOrderInsert" << endl;
    cout << "14 ִ������������� ReqExecOrderAction" << endl;
    cout << "15 ѯ��¼������ ReqForQuoteInsert" << endl;
    cout << "16 ����¼������ ReqQuoteInsert" << endl;
    cout << "17 ���۲������� ReqQuoteAction" << endl;
    cout << "18 �������� ReqLockInsert" << endl;
    cout << "19 �������¼������ ReqCombActionInsert" << endl;
    cout << "20 �����ѯ���� ReqQryOrder" << endl;
    cout << "21 �����ѯ�ɽ� ReqQryTrade" << endl;
    cout << "22 �����ѯͶ���ֲ߳� ReqQryInvestorPosition" << endl;
    cout << "23 �����ѯ�ʽ��˻� ReqQryTradingAccount" << endl;
    cout << "24 �����ѯͶ���� ReqQryInvestor" << endl;
    cout << "25 �����ѯ���ױ��� ReqQryTradingCode" << endl;
    cout << "26 �����ѯ��Լ��֤���� ReqQryInstrumentMarginRate" << endl;
    cout << "27 �����ѯ��Լ�������� ReqQryInstrumentCommissionRate" << endl;
    cout << "28 �����ѯ������ ReqQryExchange" << endl;
    cout << "29 �����ѯ��Ʒ ReqQryProduct" << endl;
    cout << "30 �����ѯ��Լ ReqQryInstrument" << endl;
    cout << "31 �����ѯ���� ReqQryDepthMarketData" << endl;
    cout << "32 �����ѯͶ���߽����� ReqQrySettlementInfo" << endl;
    cout << "33 �����ѯת������ ReqQryTransferBank" << endl;
    cout << "34 �����ѯͶ���ֲ߳���ϸ ReqQryInvestorPositionDetail" << endl;
    cout << "35 �����ѯ�ͻ�֪ͨ ReqQryNotice" << endl;
    cout << "36 �����ѯ������Ϣȷ�� ReqQrySettlementInfoConfirm" << endl;
    cout << "37 �����ѯͶ���ֲ߳���ϸ ReqQryInvestorPositionCombineDetail" << endl;
    cout << "38 �����ѯ��֤����ϵͳ���͹�˾�ʽ��˻���Կ ReqQryCFMMCTradingAccountKey" << endl;
    cout << "39 �����ѯ�ֵ��۵���Ϣ ReqQryEWarrantOffset" << endl;
    cout << "40 �����ѯͶ����Ʒ��/��Ʒ�ֱ�֤�� ReqQryInvestorProductGroupMargin" << endl;
    cout << "41 �����ѯ��������֤���� ReqQryExchangeMarginRate" << endl;
    cout << "42 �����ѯ������������֤���� ReqQryExchangeMarginRateAdjust" << endl;
    cout << "43 �����ѯ���� ReqQryExchangeRate" << endl;
    cout << "44 �����ѯ�����������Ա����Ȩ�� ReqQrySecAgentACIDMap" << endl;
    cout << "45 �����ѯ��Ʒ���ۻ��� ReqQryProductExchRate" << endl;
    cout << "46 �����ѯ��Ʒ�� ReqQryProductGroup" << endl;
    cout << "47 �����ѯ��Ȩ���׳ɱ� ReqQryOptionInstrTradeCost" << endl;
    cout << "48 �����ѯ��Ȩ��Լ������ ReqQryOptionInstrCommRate" << endl;
    cout << "49 �����ѯִ������ ReqQryExecOrder" << endl;
    cout << "50 �����ѯѯ�� ReqQryForQuote" << endl;
    cout << "51 �����ѯ���� ReqQryQuote" << endl;
    cout << "52 �����ѯ���� ReqQryLock" << endl;
    cout << "53 �����ѯ����֤ȯ��λ ReqQryLockPosition" << endl;
    cout << "54 �����ѯͶ���߷ּ� ReqQryInvestorLevel" << endl;
    cout << "55 �����ѯE+1����Ȩ���� ReqQryExecFreeze" << endl;
    cout << "56 �����ѯ��Ϻ�Լ��ȫϵ�� ReqQryCombInstrumentGuard" << endl;
    cout << "57 �����ѯ������� ReqQryCombAction" << endl;
    cout << "58 �����ѯת����ˮ ReqQryTransferSerial" << endl;
    cout << "59 �����ѯ����ǩԼ��ϵ ReqQryAccountregister" << endl;
    cout << "60 �����ѯǩԼ���� ReqQryContractBank" << endl;
    cout << "61 �����ѯԤ�� ReqQryParkedOrder" << endl;
    cout << "62 �����ѯԤ�񳷵� ReqQryParkedOrderAction" << endl;
    cout << "63 �����ѯ����֪ͨ ReqQryTradingNotice" << endl;
    cout << "64 �����ѯ���͹�˾���ײ��� ReqQryBrokerTradingParams" << endl;
    cout << "65 �����ѯ���͹�˾�����㷨 ReqQryBrokerTradingAlgos" << endl;
    cout << "66 �����ѯ��������û����� ReqQueryCFMMCTradingAccountToken" << endl;
    cout << "67 �ڻ����������ʽ�ת�ڻ����� ReqFromBankToFutureByFuture" << endl;
    cout << "68 �ڻ������ڻ��ʽ�ת�������� ReqFromFutureToBankByFuture" << endl;
    cout << "69 �ڻ������ѯ����������� ReqQueryBankAccountMoneyByFuture" << endl;
}

int CTraderSpi::exit()
{
    userapi->RegisterFront(NULL);
    userapi->Release();
    userapi = NULL;
    return 1;
}

void CTraderSpi::subscribePrivateTopic(int nType)
{
    //�ú���Ϊ�ֶ���д
    THOST_TE_RESUME_TYPE type;

    switch (nType) {
    case 0: {
	type = THOST_TERT_RESTART;
	break;
    };

    case 1: {
	type = THOST_TERT_RESUME;
	break;
    };

    case 2: {
	type = THOST_TERT_QUICK;
	break;
    };
    }

    userapi->SubscribePrivateTopic(type);
};

void CTraderSpi::subscribePublicTopic(int nType)
{
    //�ú���Ϊ�ֶ���д
    THOST_TE_RESUME_TYPE type;

    switch (nType) {
    case 0: {
	type = THOST_TERT_RESTART;
	break;
    };

    case 1: {
	type = THOST_TERT_RESUME;
	break;
    };

    case 2: {
	type = THOST_TERT_QUICK;
	break;
    };
    }

    userapi->SubscribePublicTopic(type);
};

void CTraderSpi::reqAuthenticate()
{
    CThostFtdcReqAuthenticateField myreq = CThostFtdcReqAuthenticateField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    strcpy(myreq.BrokerID, broker_id.c_str());
    cout << "�û����� TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "�û��˲�Ʒ��Ϣ TThostFtdcProductInfoType:" << endl;
    cin >> myreq.UserProductInfo;
    cout << "��֤�� TThostFtdcAuthCodeType:" << endl;
    cin >> myreq.AuthCode;
    int i = userapi->ReqAuthenticate(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqUserLogin()
{
    CThostFtdcReqUserLoginField myreq = CThostFtdcReqUserLoginField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "������ TThostFtdcDateType:" << endl;
    // cin >> myreq.TradingDay;
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    strcpy(myreq.BrokerID, broker_id.c_str());
    cout << "�û����� TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "���� TThostFtdcPasswordType:" << endl;
    strcpy(myreq.Password, passwd.c_str());
    cout << "�û��˲�Ʒ��Ϣ TThostFtdcProductInfoType:" << endl;
    // cin >> myreq.UserProductInfo;
    cout << "�ӿڶ˲�Ʒ��Ϣ TThostFtdcProductInfoType:" << endl;
    // cin >> myreq.InterfaceProductInfo;
    cout << "Э����Ϣ TThostFtdcProtocolInfoType:" << endl;
    // cin >> myreq.ProtocolInfo;
    cout << "Mac��ַ TThostFtdcMacAddressType:" << endl;
    // cin >> myreq.MacAddress;
    cout << "��̬���� TThostFtdcPasswordType:" << endl;
    // cin >> myreq.OneTimePassword;
    cout << "�ն�IP��ַ TThostFtdcIPAddressType:" << endl;
    // cin >> myreq.ClientIPAddress;
    int i = userapi->ReqUserLogin(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqUserLogout()
{
    CThostFtdcUserLogoutField myreq = CThostFtdcUserLogoutField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "�û����� TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    int i = userapi->ReqUserLogout(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqUserPasswordUpdate()
{
    CThostFtdcUserPasswordUpdateField myreq = CThostFtdcUserPasswordUpdateField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "�û����� TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "ԭ���Ŀ��� TThostFtdcPasswordType:" << endl;
    cin >> myreq.OldPassword;
    cout << "�µĿ��� TThostFtdcPasswordType:" << endl;
    cin >> myreq.NewPassword;
    int i = userapi->ReqUserPasswordUpdate(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqTradingAccountPasswordUpdate()
{
    CThostFtdcTradingAccountPasswordUpdateField myreq = CThostFtdcTradingAccountPasswordUpdateField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:";
    cin >> myreq.BrokerID;
    cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << endl;
    cin >> myreq.AccountID;
    cout << "ԭ���Ŀ��� TThostFtdcPasswordType:" << endl;
    cin >> myreq.OldPassword;
    cout << "�µĿ��� TThostFtdcPasswordType:" << endl;
    cin >> myreq.NewPassword;
    cout << "���ִ��� TThostFtdcCurrencyIDType:" << endl;
    cin >> myreq.CurrencyID;
    int i = userapi->ReqTradingAccountPasswordUpdate(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqOrderInsert()
{
    CThostFtdcInputOrderField myreq = CThostFtdcInputOrderField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "�������� TThostFtdcOrderRefType:" << endl;
    cin >> myreq.OrderRef;
    cout << "�û����� TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "�����۸����� TThostFtdcOrderPriceTypeType:" << endl;
    cin >> myreq.OrderPriceType;
    cout << "�������� TThostFtdcDirectionType:" << endl;
    cin >> myreq.Direction;
    cout << "��Ͽ�ƽ��־ TThostFtdcCombOffsetFlagType:" << endl;
    cin >> myreq.CombOffsetFlag;
    cout << "���Ͷ���ױ���־ TThostFtdcCombHedgeFlagType:" << endl;
    cin >> myreq.CombHedgeFlag;
    cout << "�۸� TThostFtdcPriceType:" << endl;
    cin >> myreq.LimitPrice;
    cout << "���� TThostFtdcVolumeType:" << endl;
    cin >> myreq.VolumeTotalOriginal;
    cout << "��Ч������ TThostFtdcTimeConditionType:" << endl;
    cin >> myreq.TimeCondition;
    cout << "GTD���� TThostFtdcDateType:" << endl;
    cin >> myreq.GTDDate;
    cout << "�ɽ������� TThostFtdcVolumeConditionType:" << endl;
    cin >> myreq.VolumeCondition;
    cout << "��С�ɽ��� TThostFtdcVolumeType:" << endl;
    cin >> myreq.MinVolume;
    cout << "�������� TThostFtdcContingentConditionType:" << endl;
    cin >> myreq.ContingentCondition;
    cout << "ֹ��� TThostFtdcPriceType:" << endl;
    cin >> myreq.StopPrice;
    cout << "ǿƽԭ�� TThostFtdcForceCloseReasonType:" << endl;
    cin >> myreq.ForceCloseReason;
    cout << "�Զ������־ TThostFtdcBoolType:" << endl;
    cin >> myreq.IsAutoSuspend;
    cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << endl;
    cin >> myreq.BusinessUnit;
    cout << "������ TThostFtdcRequestIDType:" << endl;
    cin >> myreq.RequestID;
    cout << "�û�ǿ����־ TThostFtdcBoolType:" << endl;
    cin >> myreq.UserForceClose;
    cout << "��������־ TThostFtdcBoolType:" << endl;
    cin >> myreq.IsSwapOrder;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqOrderInsert(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqParkedOrderInsert()
{
    CThostFtdcParkedOrderField myreq = CThostFtdcParkedOrderField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "�������� TThostFtdcOrderRefType:" << endl;
    cin >> myreq.OrderRef;
    cout << "�û����� TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "�����۸����� TThostFtdcOrderPriceTypeType:" << endl;
    cin >> myreq.OrderPriceType;
    cout << "�������� TThostFtdcDirectionType:" << endl;
    cin >> myreq.Direction;
    cout << "��Ͽ�ƽ��־ TThostFtdcCombOffsetFlagType:" << endl;
    cin >> myreq.CombOffsetFlag;
    cout << "���Ͷ���ױ���־ TThostFtdcCombHedgeFlagType:" << endl;
    cin >> myreq.CombHedgeFlag;
    cout << "�۸� TThostFtdcPriceType:" << endl;
    cin >> myreq.LimitPrice;
    cout << "���� TThostFtdcVolumeType:" << endl;
    cin >> myreq.VolumeTotalOriginal;
    cout << "��Ч������ TThostFtdcTimeConditionType:" << endl;
    cin >> myreq.TimeCondition;
    cout << "GTD���� TThostFtdcDateType:" << endl;
    cin >> myreq.GTDDate;
    cout << "�ɽ������� TThostFtdcVolumeConditionType:" << endl;
    cin >> myreq.VolumeCondition;
    cout << "��С�ɽ��� TThostFtdcVolumeType:" << endl;
    cin >> myreq.MinVolume;
    cout << "�������� TThostFtdcContingentConditionType:" << endl;
    cin >> myreq.ContingentCondition;
    cout << "ֹ��� TThostFtdcPriceType:" << endl;
    cin >> myreq.StopPrice;
    cout << "ǿƽԭ�� TThostFtdcForceCloseReasonType:" << endl;
    cin >> myreq.ForceCloseReason;
    cout << "�Զ������־ TThostFtdcBoolType:" << endl;
    cin >> myreq.IsAutoSuspend;
    cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << endl;
    cin >> myreq.BusinessUnit;
    cout << "������ TThostFtdcRequestIDType:" << endl;
    cin >> myreq.RequestID;
    cout << "�û�ǿ����־ TThostFtdcBoolType:" << endl;
    cin >> myreq.UserForceClose;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "Ԥ�񱨵���� TThostFtdcParkedOrderIDType:" << endl;
    cin >> myreq.ParkedOrderID;
    cout << "�û����� TThostFtdcUserTypeType:" << endl;
    cin >> myreq.UserType;
    cout << "Ԥ��״̬ TThostFtdcParkedOrderStatusType:" << endl;
    cin >> myreq.Status;
    cout << "������� TThostFtdcErrorIDType:" << endl;
    cin >> myreq.ErrorID;
    cout << "������Ϣ TThostFtdcErrorMsgType:" << endl;
    cin >> myreq.ErrorMsg;
    cout << "��������־ TThostFtdcBoolType:" << endl;
    cin >> myreq.IsSwapOrder;
    int i = userapi->ReqParkedOrderInsert(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqParkedOrderAction()
{
    CThostFtdcParkedOrderActionField myreq = CThostFtdcParkedOrderActionField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "������������ TThostFtdcOrderActionRefType:" << endl;
    cin >> myreq.OrderActionRef;
    cout << "�������� TThostFtdcOrderRefType:" << endl;
    cin >> myreq.OrderRef;
    cout << "������ TThostFtdcRequestIDType:" << endl;
    cin >> myreq.RequestID;
    cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << endl;
    cin >> myreq.FrontID;
    cout << "�Ự��� TThostFtdcSessionIDType:" << endl;
    cin >> myreq.SessionID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "������� TThostFtdcOrderSysIDType:" << endl;
    cin >> myreq.OrderSysID;
    cout << "������־ TThostFtdcActionFlagType:" << endl;
    cin >> myreq.ActionFlag;
    cout << "�۸� TThostFtdcPriceType:" << endl;
    cin >> myreq.LimitPrice;
    cout << "�����仯 TThostFtdcVolumeType:" << endl;
    cin >> myreq.VolumeChange;
    cout << "�û����� TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "Ԥ�񳷵������ TThostFtdcParkedOrderActionIDType:" << endl;
    cin >> myreq.ParkedOrderActionID;
    cout << "�û����� TThostFtdcUserTypeType:" << endl;
    cin >> myreq.UserType;
    cout << "Ԥ�񳷵�״̬ TThostFtdcParkedOrderStatusType:" << endl;
    cin >> myreq.Status;
    cout << "������� TThostFtdcErrorIDType:" << endl;
    cin >> myreq.ErrorID;
    cout << "������Ϣ TThostFtdcErrorMsgType:" << endl;
    cin >> myreq.ErrorMsg;
    int i = userapi->ReqParkedOrderAction(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqOrderAction()
{
    CThostFtdcInputOrderActionField myreq = CThostFtdcInputOrderActionField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "������������ TThostFtdcOrderActionRefType:" << endl;
    cin >> myreq.OrderActionRef;
    cout << "�������� TThostFtdcOrderRefType:" << endl;
    cin >> myreq.OrderRef;
    cout << "������ TThostFtdcRequestIDType:" << endl;
    cin >> myreq.RequestID;
    cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << endl;
    cin >> myreq.FrontID;
    cout << "�Ự��� TThostFtdcSessionIDType:" << endl;
    cin >> myreq.SessionID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "������� TThostFtdcOrderSysIDType:" << endl;
    cin >> myreq.OrderSysID;
    cout << "������־ TThostFtdcActionFlagType:" << endl;
    cin >> myreq.ActionFlag;
    cout << "�۸� TThostFtdcPriceType:" << endl;
    cin >> myreq.LimitPrice;
    cout << "�����仯 TThostFtdcVolumeType:" << endl;
    cin >> myreq.VolumeChange;
    cout << "�û����� TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    int i = userapi->ReqOrderAction(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQueryMaxOrderVolume()
{
    CThostFtdcQueryMaxOrderVolumeField myreq = CThostFtdcQueryMaxOrderVolumeField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "�������� TThostFtdcDirectionType:" << endl;
    cin >> myreq.Direction;
    cout << "��ƽ��־ TThostFtdcOffsetFlagType:" << endl;
    cin >> myreq.OffsetFlag;
    cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << endl;
    cin >> myreq.HedgeFlag;
    cout << "������������� TThostFtdcVolumeType:" << endl;
    cin >> myreq.MaxVolume;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQueryMaxOrderVolume(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqSettlementInfoConfirm()
{
    CThostFtdcSettlementInfoConfirmField myreq = CThostFtdcSettlementInfoConfirmField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "ȷ������ TThostFtdcDateType:" << endl;
    cin >> myreq.ConfirmDate;
    cout << "ȷ��ʱ�� TThostFtdcTimeType:" << endl;
    cin >> myreq.ConfirmTime;
    int i = userapi->ReqSettlementInfoConfirm(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqRemoveParkedOrder()
{
    CThostFtdcRemoveParkedOrderField myreq = CThostFtdcRemoveParkedOrderField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "Ԥ�񱨵���� TThostFtdcParkedOrderIDType:" << endl;
    cin >> myreq.ParkedOrderID;
    int i = userapi->ReqRemoveParkedOrder(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqRemoveParkedOrderAction()
{
    CThostFtdcRemoveParkedOrderActionField myreq = CThostFtdcRemoveParkedOrderActionField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "Ԥ�񳷵���� TThostFtdcParkedOrderActionIDType:" << endl;
    cin >> myreq.ParkedOrderActionID;
    int i = userapi->ReqRemoveParkedOrderAction(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqExecOrderInsert()
{
    CThostFtdcInputExecOrderField myreq = CThostFtdcInputExecOrderField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "ִ���������� TThostFtdcOrderRefType:" << endl;
    cin >> myreq.ExecOrderRef;
    cout << "�û����� TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "���� TThostFtdcVolumeType:" << endl;
    cin >> myreq.Volume;
    cout << "������ TThostFtdcRequestIDType:" << endl;
    cin >> myreq.RequestID;
    cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << endl;
    cin >> myreq.BusinessUnit;
    cout << "��ƽ��־ TThostFtdcOffsetFlagType:" << endl;
    cin >> myreq.OffsetFlag;
    cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << endl;
    cin >> myreq.HedgeFlag;
    cout << "ִ������ TThostFtdcActionTypeType:" << endl;
    cin >> myreq.ActionType;
    cout << "����ͷ������ĳֲַ��� TThostFtdcPosiDirectionType:" << endl;
    cin >> myreq.PosiDirection;
    cout << "��Ȩ��Ȩ���Ƿ����ڻ�ͷ��ı�� TThostFtdcExecOrderPositionFlagType:" << endl;
    cin >> myreq.ReservePositionFlag;
    cout << "��Ȩ��Ȩ�����ɵ�ͷ���Ƿ��Զ�ƽ�� TThostFtdcExecOrderCloseFlagType:" << endl;
    cin >> myreq.CloseFlag;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqExecOrderInsert(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqExecOrderAction()
{
    CThostFtdcInputExecOrderActionField myreq = CThostFtdcInputExecOrderActionField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "ִ������������� TThostFtdcOrderActionRefType:" << endl;
    cin >> myreq.ExecOrderActionRef;
    cout << "ִ���������� TThostFtdcOrderRefType:" << endl;
    cin >> myreq.ExecOrderRef;
    cout << "������ TThostFtdcRequestIDType:" << endl;
    cin >> myreq.RequestID;
    cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << endl;
    cin >> myreq.FrontID;
    cout << "�Ự��� TThostFtdcSessionIDType:" << endl;
    cin >> myreq.SessionID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "ִ������������ TThostFtdcExecOrderSysIDType:" << endl;
    cin >> myreq.ExecOrderSysID;
    cout << "������־ TThostFtdcActionFlagType:" << endl;
    cin >> myreq.ActionFlag;
    cout << "�û����� TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    int i = userapi->ReqExecOrderAction(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqForQuoteInsert()
{
    CThostFtdcInputForQuoteField myreq = CThostFtdcInputForQuoteField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "ѯ������ TThostFtdcOrderRefType:" << endl;
    cin >> myreq.ForQuoteRef;
    cout << "�û����� TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqForQuoteInsert(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQuoteInsert()
{
    CThostFtdcInputQuoteField myreq = CThostFtdcInputQuoteField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "�������� TThostFtdcOrderRefType:" << endl;
    cin >> myreq.QuoteRef;
    cout << "�û����� TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "���۸� TThostFtdcPriceType:" << endl;
    cin >> myreq.AskPrice;
    cout << "��۸� TThostFtdcPriceType:" << endl;
    cin >> myreq.BidPrice;
    cout << "������ TThostFtdcVolumeType:" << endl;
    cin >> myreq.AskVolume;
    cout << "������ TThostFtdcVolumeType:" << endl;
    cin >> myreq.BidVolume;
    cout << "������ TThostFtdcRequestIDType:" << endl;
    cin >> myreq.RequestID;
    cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << endl;
    cin >> myreq.BusinessUnit;
    cout << "����ƽ��־ TThostFtdcOffsetFlagType:" << endl;
    cin >> myreq.AskOffsetFlag;
    cout << "��ƽ��־ TThostFtdcOffsetFlagType:" << endl;
    cin >> myreq.BidOffsetFlag;
    cout << "��Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << endl;
    cin >> myreq.AskHedgeFlag;
    cout << "��Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << endl;
    cin >> myreq.BidHedgeFlag;
    cout << "�������������� TThostFtdcOrderRefType:" << endl;
    cin >> myreq.AskOrderRef;
    cout << "�����򱨵����� TThostFtdcOrderRefType:" << endl;
    cin >> myreq.BidOrderRef;
    cout << "Ӧ�۱�� TThostFtdcOrderSysIDType:" << endl;
    cin >> myreq.ForQuoteSysID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQuoteInsert(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQuoteAction()
{
    CThostFtdcInputQuoteActionField myreq = CThostFtdcInputQuoteActionField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "���۲������� TThostFtdcOrderActionRefType:" << endl;
    cin >> myreq.QuoteActionRef;
    cout << "�������� TThostFtdcOrderRefType:" << endl;
    cin >> myreq.QuoteRef;
    cout << "������ TThostFtdcRequestIDType:" << endl;
    cin >> myreq.RequestID;
    cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << endl;
    cin >> myreq.FrontID;
    cout << "�Ự��� TThostFtdcSessionIDType:" << endl;
    cin >> myreq.SessionID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "���۲������ TThostFtdcOrderSysIDType:" << endl;
    cin >> myreq.QuoteSysID;
    cout << "������־ TThostFtdcActionFlagType:" << endl;
    cin >> myreq.ActionFlag;
    cout << "�û����� TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    int i = userapi->ReqQuoteAction(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqLockInsert()
{
    CThostFtdcInputLockField myreq = CThostFtdcInputLockField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "�������� TThostFtdcOrderRefType:" << endl;
    cin >> myreq.LockRef;
    cout << "�û����� TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "���� TThostFtdcVolumeType:" << endl;
    cin >> myreq.Volume;
    cout << "������ TThostFtdcRequestIDType:" << endl;
    cin >> myreq.RequestID;
    cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << endl;
    cin >> myreq.BusinessUnit;
    cout << "�������� TThostFtdcLockTypeType:" << endl;
    cin >> myreq.LockType;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqLockInsert(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqCombActionInsert()
{
    CThostFtdcInputCombActionField myreq = CThostFtdcInputCombActionField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "������� TThostFtdcOrderRefType:" << endl;
    cin >> myreq.CombActionRef;
    cout << "�û����� TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "�������� TThostFtdcDirectionType:" << endl;
    cin >> myreq.Direction;
    cout << "���� TThostFtdcVolumeType:" << endl;
    cin >> myreq.Volume;
    cout << "���ָ��� TThostFtdcCombDirectionType:" << endl;
    cin >> myreq.CombDirection;
    cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << endl;
    cin >> myreq.HedgeFlag;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqCombActionInsert(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryOrder()
{
    CThostFtdcQryOrderField myreq = CThostFtdcQryOrderField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "������� TThostFtdcOrderSysIDType:" << endl;
    cin >> myreq.OrderSysID;
    cout << "��ʼʱ�� TThostFtdcTimeType:" << endl;
    cin >> myreq.InsertTimeStart;
    cout << "����ʱ�� TThostFtdcTimeType:" << endl;
    cin >> myreq.InsertTimeEnd;
    int i = userapi->ReqQryOrder(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryTrade()
{
    CThostFtdcQryTradeField myreq = CThostFtdcQryTradeField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "�ɽ���� TThostFtdcTradeIDType:" << endl;
    cin >> myreq.TradeID;
    cout << "��ʼʱ�� TThostFtdcTimeType:" << endl;
    cin >> myreq.TradeTimeStart;
    cout << "����ʱ�� TThostFtdcTimeType:" << endl;
    cin >> myreq.TradeTimeEnd;
    int i = userapi->ReqQryTrade(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryInvestorPosition()
{
    CThostFtdcQryInvestorPositionField myreq = CThostFtdcQryInvestorPositionField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryInvestorPosition(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryTradingAccount()
{
    CThostFtdcQryTradingAccountField myreq = CThostFtdcQryTradingAccountField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "���ִ��� TThostFtdcCurrencyIDType:" << endl;
    cin >> myreq.CurrencyID;
    cout << "ҵ������ TThostFtdcBizTypeType:" << endl;
    cin >> myreq.BizType;
    int i = userapi->ReqQryTradingAccount(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryInvestor()
{
    CThostFtdcQryInvestorField myreq = CThostFtdcQryInvestorField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    int i = userapi->ReqQryInvestor(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryTradingCode()
{
    CThostFtdcQryTradingCodeField myreq = CThostFtdcQryTradingCodeField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "�ͻ����� TThostFtdcClientIDType:" << endl;
    cin >> myreq.ClientID;
    cout << "���ױ������� TThostFtdcClientIDTypeType:" << endl;
    cin >> myreq.ClientIDType;
    int i = userapi->ReqQryTradingCode(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryInstrumentMarginRate()
{
    CThostFtdcQryInstrumentMarginRateField myreq = CThostFtdcQryInstrumentMarginRateField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << endl;
    cin >> myreq.HedgeFlag;
    int i = userapi->ReqQryInstrumentMarginRate(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryInstrumentCommissionRate()
{
    CThostFtdcQryInstrumentCommissionRateField myreq = CThostFtdcQryInstrumentCommissionRateField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryInstrumentCommissionRate(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryExchange()
{
    CThostFtdcQryExchangeField myreq = CThostFtdcQryExchangeField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryExchange(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryProduct()
{
    CThostFtdcQryProductField myreq = CThostFtdcQryProductField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "��Ʒ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.ProductID;
    cout << "��Ʒ���� TThostFtdcProductClassType:" << endl;
    cin >> myreq.ProductClass;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryProduct(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryInstrument()
{
    CThostFtdcQryInstrumentField myreq = CThostFtdcQryInstrumentField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "��Լ�ڽ������Ĵ��� TThostFtdcExchangeInstIDType:" << endl;
    cin >> myreq.ExchangeInstID;
    cout << "��Ʒ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.ProductID;
    int i = userapi->ReqQryInstrument(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryDepthMarketData()
{
    CThostFtdcQryDepthMarketDataField myreq = CThostFtdcQryDepthMarketDataField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryDepthMarketData(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQrySettlementInfo()
{
    CThostFtdcQrySettlementInfoField myreq = CThostFtdcQrySettlementInfoField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "������ TThostFtdcDateType:" << endl;
    cin >> myreq.TradingDay;
    int i = userapi->ReqQrySettlementInfo(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryTransferBank()
{
    CThostFtdcQryTransferBankField myreq = CThostFtdcQryTransferBankField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���д��� TThostFtdcBankIDType:" << endl;
    cin >> myreq.BankID;
    cout << "���з����Ĵ��� TThostFtdcBankBrchIDType:" << endl;
    cin >> myreq.BankBrchID;
    int i = userapi->ReqQryTransferBank(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryInvestorPositionDetail()
{
    CThostFtdcQryInvestorPositionDetailField myreq = CThostFtdcQryInvestorPositionDetailField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryInvestorPositionDetail(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryNotice()
{
    CThostFtdcQryNoticeField myreq = CThostFtdcQryNoticeField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    int i = userapi->ReqQryNotice(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQrySettlementInfoConfirm()
{
    CThostFtdcQrySettlementInfoConfirmField myreq = CThostFtdcQrySettlementInfoConfirmField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    int i = userapi->ReqQrySettlementInfoConfirm(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryInvestorPositionCombineDetail()
{
    CThostFtdcQryInvestorPositionCombineDetailField myreq = CThostFtdcQryInvestorPositionCombineDetailField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��ϳֲֺ�Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.CombInstrumentID;
    int i = userapi->ReqQryInvestorPositionCombineDetail(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryCFMMCTradingAccountKey()
{
    CThostFtdcQryCFMMCTradingAccountKeyField myreq = CThostFtdcQryCFMMCTradingAccountKeyField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    int i = userapi->ReqQryCFMMCTradingAccountKey(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryEWarrantOffset()
{
    CThostFtdcQryEWarrantOffsetField myreq = CThostFtdcQryEWarrantOffsetField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    int i = userapi->ReqQryEWarrantOffset(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryInvestorProductGroupMargin()
{
    CThostFtdcQryInvestorProductGroupMarginField myreq = CThostFtdcQryInvestorProductGroupMarginField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "Ʒ��/��Ʒ�ֱ�ʾ TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.ProductGroupID;
    cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << endl;
    cin >> myreq.HedgeFlag;
    int i = userapi->ReqQryInvestorProductGroupMargin(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryExchangeMarginRate()
{
    CThostFtdcQryExchangeMarginRateField myreq = CThostFtdcQryExchangeMarginRateField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << endl;
    cin >> myreq.HedgeFlag;
    int i = userapi->ReqQryExchangeMarginRate(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryExchangeMarginRateAdjust()
{
    CThostFtdcQryExchangeMarginRateAdjustField myreq = CThostFtdcQryExchangeMarginRateAdjustField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << endl;
    cin >> myreq.HedgeFlag;
    int i = userapi->ReqQryExchangeMarginRateAdjust(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryExchangeRate()
{
    CThostFtdcQryExchangeRateField myreq = CThostFtdcQryExchangeRateField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Դ���� TThostFtdcCurrencyIDType:" << endl;
    cin >> myreq.FromCurrencyID;
    cout << "Ŀ����� TThostFtdcCurrencyIDType:" << endl;
    cin >> myreq.ToCurrencyID;
    int i = userapi->ReqQryExchangeRate(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQrySecAgentACIDMap()
{
    CThostFtdcQrySecAgentACIDMapField myreq = CThostFtdcQrySecAgentACIDMapField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "�û����� TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "�ʽ��˻� TThostFtdcAccountIDType:" << endl;
    cin >> myreq.AccountID;
    cout << "���� TThostFtdcCurrencyIDType:" << endl;
    cin >> myreq.CurrencyID;
    int i = userapi->ReqQrySecAgentACIDMap(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryProductExchRate()
{
    CThostFtdcQryProductExchRateField myreq = CThostFtdcQryProductExchRateField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "��Ʒ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.ProductID;
    int i = userapi->ReqQryProductExchRate(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryProductGroup()
{
    CThostFtdcQryProductGroupField myreq = CThostFtdcQryProductGroupField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "��Ʒ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.ProductID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryProductGroup(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryOptionInstrTradeCost()
{
    CThostFtdcQryOptionInstrTradeCostField myreq = CThostFtdcQryOptionInstrTradeCostField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << endl;
    cin >> myreq.HedgeFlag;
    cout << "��Ȩ��Լ���� TThostFtdcPriceType:" << endl;
    cin >> myreq.InputPrice;
    cout << "��ļ۸�,��0���������� TThostFtdcPriceType:" << endl;
    cin >> myreq.UnderlyingPrice;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryOptionInstrTradeCost(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryOptionInstrCommRate()
{
    CThostFtdcQryOptionInstrCommRateField myreq = CThostFtdcQryOptionInstrCommRateField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryOptionInstrCommRate(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryExecOrder()
{
    CThostFtdcQryExecOrderField myreq = CThostFtdcQryExecOrderField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "ִ�������� TThostFtdcExecOrderSysIDType:" << endl;
    cin >> myreq.ExecOrderSysID;
    cout << "��ʼʱ�� TThostFtdcTimeType:" << endl;
    cin >> myreq.InsertTimeStart;
    cout << "����ʱ�� TThostFtdcTimeType:" << endl;
    cin >> myreq.InsertTimeEnd;
    int i = userapi->ReqQryExecOrder(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryForQuote()
{
    CThostFtdcQryForQuoteField myreq = CThostFtdcQryForQuoteField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "��ʼʱ�� TThostFtdcTimeType:" << endl;
    cin >> myreq.InsertTimeStart;
    cout << "����ʱ�� TThostFtdcTimeType:" << endl;
    cin >> myreq.InsertTimeEnd;
    int i = userapi->ReqQryForQuote(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryQuote()
{
    CThostFtdcQryQuoteField myreq = CThostFtdcQryQuoteField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "���۱�� TThostFtdcOrderSysIDType:" << endl;
    cin >> myreq.QuoteSysID;
    cout << "��ʼʱ�� TThostFtdcTimeType:" << endl;
    cin >> myreq.InsertTimeStart;
    cout << "����ʱ�� TThostFtdcTimeType:" << endl;
    cin >> myreq.InsertTimeEnd;
    int i = userapi->ReqQryQuote(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryLock()
{
    CThostFtdcQryLockField myreq = CThostFtdcQryLockField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "������� TThostFtdcOrderSysIDType:" << endl;
    cin >> myreq.LockSysID;
    cout << "��ʼʱ�� TThostFtdcTimeType:" << endl;
    cin >> myreq.InsertTimeStart;
    cout << "����ʱ�� TThostFtdcTimeType:" << endl;
    cin >> myreq.InsertTimeEnd;
    int i = userapi->ReqQryLock(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryLockPosition()
{
    CThostFtdcQryLockPositionField myreq = CThostFtdcQryLockPositionField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryLockPosition(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryInvestorLevel()
{
    CThostFtdcQryInvestorLevelField myreq = CThostFtdcQryInvestorLevelField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryInvestorLevel(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryExecFreeze()
{
    CThostFtdcQryExecFreezeField myreq = CThostFtdcQryExecFreezeField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryExecFreeze(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryCombInstrumentGuard()
{
    CThostFtdcQryCombInstrumentGuardField myreq = CThostFtdcQryCombInstrumentGuardField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    int i = userapi->ReqQryCombInstrumentGuard(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryCombAction()
{
    CThostFtdcQryCombActionField myreq = CThostFtdcQryCombActionField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryCombAction(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryTransferSerial()
{
    CThostFtdcQryTransferSerialField myreq = CThostFtdcQryTransferSerialField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << endl;
    cin >> myreq.AccountID;
    cout << "���б��� TThostFtdcBankIDType:" << endl;
    cin >> myreq.BankID;
    cout << "���ִ��� TThostFtdcCurrencyIDType:" << endl;
    cin >> myreq.CurrencyID;
    int i = userapi->ReqQryTransferSerial(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryAccountregister()
{
    CThostFtdcQryAccountregisterField myreq = CThostFtdcQryAccountregisterField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << endl;
    cin >> myreq.AccountID;
    cout << "���б��� TThostFtdcBankIDType:" << endl;
    cin >> myreq.BankID;
    cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << endl;
    cin >> myreq.BankBranchID;
    cout << "���ִ��� TThostFtdcCurrencyIDType:" << endl;
    cin >> myreq.CurrencyID;
    int i = userapi->ReqQryAccountregister(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryContractBank()
{
    CThostFtdcQryContractBankField myreq = CThostFtdcQryContractBankField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "���д��� TThostFtdcBankIDType:" << endl;
    cin >> myreq.BankID;
    cout << "���з����Ĵ��� TThostFtdcBankBrchIDType:" << endl;
    cin >> myreq.BankBrchID;
    int i = userapi->ReqQryContractBank(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryParkedOrder()
{
    CThostFtdcQryParkedOrderField myreq = CThostFtdcQryParkedOrderField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryParkedOrder(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryParkedOrderAction()
{
    CThostFtdcQryParkedOrderActionField myreq = CThostFtdcQryParkedOrderActionField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryParkedOrderAction(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryTradingNotice()
{
    CThostFtdcQryTradingNoticeField myreq = CThostFtdcQryTradingNoticeField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    int i = userapi->ReqQryTradingNotice(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryBrokerTradingParams()
{
    CThostFtdcQryBrokerTradingParamsField myreq = CThostFtdcQryBrokerTradingParamsField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "���ִ��� TThostFtdcCurrencyIDType:" << endl;
    cin >> myreq.CurrencyID;
    int i = userapi->ReqQryBrokerTradingParams(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryBrokerTradingAlgos()
{
    CThostFtdcQryBrokerTradingAlgosField myreq = CThostFtdcQryBrokerTradingAlgosField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "���������� TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    int i = userapi->ReqQryBrokerTradingAlgos(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQueryCFMMCTradingAccountToken()
{
    CThostFtdcQueryCFMMCTradingAccountTokenField myreq = CThostFtdcQueryCFMMCTradingAccountTokenField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    int i = userapi->ReqQueryCFMMCTradingAccountToken(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqFromBankToFutureByFuture()
{
    CThostFtdcReqTransferField myreq = CThostFtdcReqTransferField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "ҵ������ TThostFtdcTradeCodeType:" << endl;
    cin >> myreq.TradeCode;
    cout << "���д��� TThostFtdcBankIDType:" << endl;
    cin >> myreq.BankID;
    cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << endl;
    cin >> myreq.BankBranchID;
    cout << "���̴��� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << endl;
    cin >> myreq.BrokerBranchID;
    cout << "�������� TThostFtdcTradeDateType:" << endl;
    cin >> myreq.TradeDate;
    cout << "����ʱ�� TThostFtdcTradeTimeType:" << endl;
    cin >> myreq.TradeTime;
    cout << "������ˮ�� TThostFtdcBankSerialType:" << endl;
    cin >> myreq.BankSerial;
    // cout << "����ϵͳ���� TThostFtdcTradeDateType	TradingDa:" << endl;
    // cin >> myreq.;
    cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << endl;
    cin >> myreq.PlateSerial;
    cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << endl;
    cin >> myreq.LastFragment;
    cout << "�Ự�� TThostFtdcSessionIDType:" << endl;
    cin >> myreq.SessionID;
    cout << "�ͻ����� TThostFtdcIndividualNameType:" << endl;
    cin >> myreq.CustomerName;
    cout << "֤������ TThostFtdcIdCardTypeType:" << endl;
    cin >> myreq.IdCardType;
    cout << "֤������ TThostFtdcIdentifiedCardNoType:" << endl;
    cin >> myreq.IdentifiedCardNo;
    cout << "�ͻ����� TThostFtdcCustTypeType:" << endl;
    cin >> myreq.CustType;
    cout << "�����ʺ� TThostFtdcBankAccountType:" << endl;
    cin >> myreq.BankAccount;
    cout << "�������� TThostFtdcPasswordType:" << endl;
    cin >> myreq.BankPassWord;
    cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << endl;
    cin >> myreq.AccountID;
    cout << "�ڻ����� TThostFtdcPasswordType:" << endl;
    strcpy(myreq.Password, passwd.c_str());
    cout << "��װ��� TThostFtdcInstallIDType:" << endl;
    cin >> myreq.InstallID;
    cout << "�ڻ���˾��ˮ�� TThostFtdcFutureSerialType:" << endl;
    cin >> myreq.FutureSerial;
    cout << "�û���ʶ TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << endl;
    cin >> myreq.VerifyCertNoFlag;
    cout << "���ִ��� TThostFtdcCurrencyIDType:" << endl;
    cin >> myreq.CurrencyID;
    cout << "ת�ʽ�� TThostFtdcTradeAmountType:" << endl;
    cin >> myreq.TradeAmount;
    cout << "�ڻ���ȡ��� TThostFtdcTradeAmountType:" << endl;
    cin >> myreq.FutureFetchAmount;
    cout << "����֧����־ TThostFtdcFeePayFlagType:" << endl;
    cin >> myreq.FeePayFlag;
    cout << "Ӧ�տͻ����� TThostFtdcCustFeeType:" << endl;
    cin >> myreq.CustFee;
    cout << "Ӧ���ڻ���˾���� TThostFtdcFutureFeeType:" << endl;
    cin >> myreq.BrokerFee;
    cout << "���ͷ������շ�����Ϣ TThostFtdcAddInfoType:" << endl;
    cin >> myreq.Message;
    cout << "ժҪ TThostFtdcDigestType:" << endl;
    cin >> myreq.Digest;
    cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << endl;
    cin >> myreq.BankAccType;
    cout << "������־ TThostFtdcDeviceIDType:" << endl;
    cin >> myreq.DeviceID;
    cout << "�ڻ���λ�ʺ����� TThostFtdcBankAccTypeType:" << endl;
    cin >> myreq.BankSecuAccType;
    cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << endl;
    cin >> myreq.BrokerIDByBank;
    cout << "�ڻ���λ�ʺ� TThostFtdcBankAccountType:" << endl;
    cin >> myreq.BankSecuAcc;
    cout << "���������־ TThostFtdcPwdFlagType:" << endl;
    cin >> myreq.BankPwdFlag;
    cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << endl;
    cin >> myreq.SecuPwdFlag;
    cout << "���׹�Ա TThostFtdcOperNoType:" << endl;
    cin >> myreq.OperNo;
    cout << "������ TThostFtdcRequestIDType:" << endl;
    cin >> myreq.RequestID;
    cout << "����ID TThostFtdcTIDType:" << endl;
    cin >> myreq.TID;
    cout << "ת�˽���״̬ TThostFtdcTransferStatusType:" << endl;
    cin >> myreq.TransferStatus;
    int i = userapi->ReqFromBankToFutureByFuture(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqFromFutureToBankByFuture()
{
    CThostFtdcReqTransferField myreq = CThostFtdcReqTransferField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "ҵ������ TThostFtdcTradeCodeType:" << endl;
    cin >> myreq.TradeCode;
    cout << "���д��� TThostFtdcBankIDType:" << endl;
    cin >> myreq.BankID;
    cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << endl;
    cin >> myreq.BankBranchID;
    cout << "���̴��� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << endl;
    cin >> myreq.BrokerBranchID;
    cout << "�������� TThostFtdcTradeDateType:" << endl;
    cin >> myreq.TradeDate;
    cout << "����ʱ�� TThostFtdcTradeTimeType:" << endl;
    cin >> myreq.TradeTime;
    cout << "������ˮ�� TThostFtdcBankSerialType:" << endl;
    cin >> myreq.BankSerial;
    // cout << "����ϵͳ���� TThostFtdcTradeDateType	TradingDa:" << endl;
    // cin >> myreq.;
    cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << endl;
    cin >> myreq.PlateSerial;
    cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << endl;
    cin >> myreq.LastFragment;
    cout << "�Ự�� TThostFtdcSessionIDType:" << endl;
    cin >> myreq.SessionID;
    cout << "�ͻ����� TThostFtdcIndividualNameType:" << endl;
    cin >> myreq.CustomerName;
    cout << "֤������ TThostFtdcIdCardTypeType:" << endl;
    cin >> myreq.IdCardType;
    cout << "֤������ TThostFtdcIdentifiedCardNoType:" << endl;
    cin >> myreq.IdentifiedCardNo;
    cout << "�ͻ����� TThostFtdcCustTypeType:" << endl;
    cin >> myreq.CustType;
    cout << "�����ʺ� TThostFtdcBankAccountType:" << endl;
    cin >> myreq.BankAccount;
    cout << "�������� TThostFtdcPasswordType:" << endl;
    cin >> myreq.BankPassWord;
    cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << endl;
    cin >> myreq.AccountID;
    cout << "�ڻ����� TThostFtdcPasswordType:" << endl;
    strcpy(myreq.Password, passwd.c_str());
    cout << "��װ��� TThostFtdcInstallIDType:" << endl;
    cin >> myreq.InstallID;
    cout << "�ڻ���˾��ˮ�� TThostFtdcFutureSerialType:" << endl;
    cin >> myreq.FutureSerial;
    cout << "�û���ʶ TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << endl;
    cin >> myreq.VerifyCertNoFlag;
    cout << "���ִ��� TThostFtdcCurrencyIDType:" << endl;
    cin >> myreq.CurrencyID;
    cout << "ת�ʽ�� TThostFtdcTradeAmountType:" << endl;
    cin >> myreq.TradeAmount;
    cout << "�ڻ���ȡ��� TThostFtdcTradeAmountType:" << endl;
    cin >> myreq.FutureFetchAmount;
    cout << "����֧����־ TThostFtdcFeePayFlagType:" << endl;
    cin >> myreq.FeePayFlag;
    cout << "Ӧ�տͻ����� TThostFtdcCustFeeType:" << endl;
    cin >> myreq.CustFee;
    cout << "Ӧ���ڻ���˾���� TThostFtdcFutureFeeType:" << endl;
    cin >> myreq.BrokerFee;
    cout << "���ͷ������շ�����Ϣ TThostFtdcAddInfoType:" << endl;
    cin >> myreq.Message;
    cout << "ժҪ TThostFtdcDigestType:" << endl;
    cin >> myreq.Digest;
    cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << endl;
    cin >> myreq.BankAccType;
    cout << "������־ TThostFtdcDeviceIDType:" << endl;
    cin >> myreq.DeviceID;
    cout << "�ڻ���λ�ʺ����� TThostFtdcBankAccTypeType:" << endl;
    cin >> myreq.BankSecuAccType;
    cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << endl;
    cin >> myreq.BrokerIDByBank;
    cout << "�ڻ���λ�ʺ� TThostFtdcBankAccountType:" << endl;
    cin >> myreq.BankSecuAcc;
    cout << "���������־ TThostFtdcPwdFlagType:" << endl;
    cin >> myreq.BankPwdFlag;
    cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << endl;
    cin >> myreq.SecuPwdFlag;
    cout << "���׹�Ա TThostFtdcOperNoType:" << endl;
    cin >> myreq.OperNo;
    cout << "������ TThostFtdcRequestIDType:" << endl;
    cin >> myreq.RequestID;
    cout << "����ID TThostFtdcTIDType:" << endl;
    cin >> myreq.TID;
    cout << "ת�˽���״̬ TThostFtdcTransferStatusType:" << endl;
    cin >> myreq.TransferStatus;
    int i = userapi->ReqFromFutureToBankByFuture(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQueryBankAccountMoneyByFuture()
{
    CThostFtdcReqQueryAccountField myreq = CThostFtdcReqQueryAccountField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "ҵ������ TThostFtdcTradeCodeType:" << endl;
    cin >> myreq.TradeCode;
    cout << "���д��� TThostFtdcBankIDType:" << endl;
    cin >> myreq.BankID;
    cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << endl;
    cin >> myreq.BankBranchID;
    cout << "���̴��� TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << endl;
    cin >> myreq.BrokerBranchID;
    cout << "�������� TThostFtdcTradeDateType:" << endl;
    cin >> myreq.TradeDate;
    cout << "����ʱ�� TThostFtdcTradeTimeType:" << endl;
    cin >> myreq.TradeTime;
    cout << "������ˮ�� TThostFtdcBankSerialType:" << endl;
    cin >> myreq.BankSerial;
    cout << "����ϵͳ���� TThostFtdcTradeDateType:" << endl;
    cin >> myreq.TradingDay;
    cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << endl;
    cin >> myreq.PlateSerial;
    cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << endl;
    cin >> myreq.LastFragment;
    cout << "�Ự�� TThostFtdcSessionIDType:" << endl;
    cin >> myreq.SessionID;
    cout << "�ͻ����� TThostFtdcIndividualNameType:" << endl;
    cin >> myreq.CustomerName;
    cout << "֤������ TThostFtdcIdCardTypeType:" << endl;
    cin >> myreq.IdCardType;
    cout << "֤������ TThostFtdcIdentifiedCardNoType:" << endl;
    cin >> myreq.IdentifiedCardNo;
    cout << "�ͻ����� TThostFtdcCustTypeType:" << endl;
    cin >> myreq.CustType;
    cout << "�����ʺ� TThostFtdcBankAccountType:" << endl;
    cin >> myreq.BankAccount;
    cout << "�������� TThostFtdcPasswordType:" << endl;
    cin >> myreq.BankPassWord;
    cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << endl;
    cin >> myreq.AccountID;
    cout << "�ڻ����� TThostFtdcPasswordType:" << endl;
    strcpy(myreq.Password, passwd.c_str());
    cout << "�ڻ���˾��ˮ�� TThostFtdcFutureSerialType:" << endl;
    cin >> myreq.FutureSerial;
    cout << "��װ��� TThostFtdcInstallIDType:" << endl;
    cin >> myreq.InstallID;
    cout << "�û���ʶ TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << endl;
    cin >> myreq.VerifyCertNoFlag;
    cout << "���ִ��� TThostFtdcCurrencyIDType:" << endl;
    cin >> myreq.CurrencyID;
    cout << "ժҪ TThostFtdcDigestType:" << endl;
    cin >> myreq.Digest;
    cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << endl;
    cin >> myreq.BankAccType;
    cout << "������־ TThostFtdcDeviceIDType:" << endl;
    cin >> myreq.DeviceID;
    cout << "�ڻ���λ�ʺ����� TThostFtdcBankAccTypeType:" << endl;
    cin >> myreq.BankSecuAccType;
    cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << endl;
    cin >> myreq.BrokerIDByBank;
    cout << "�ڻ���λ�ʺ� TThostFtdcBankAccountType:" << endl;
    cin >> myreq.BankSecuAcc;
    cout << "���������־ TThostFtdcPwdFlagType:" << endl;
    cin >> myreq.BankPwdFlag;
    cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << endl;
    cin >> myreq.SecuPwdFlag;
    cout << "���׹�Ա TThostFtdcOperNoType:" << endl;
    cin >> myreq.OperNo;
    cout << "������ TThostFtdcRequestIDType:" << endl;
    cin >> myreq.RequestID;
    cout << "����ID TThostFtdcTIDType:" << endl;
    cin >> myreq.TID;
    int i = userapi->ReqQueryBankAccountMoneyByFuture(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};
///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
void CTraderSpi::OnFrontConnected()
{
    cout << "--->>> "
	 << "OnFrontConnected" << endl;
    // user login request
    reqUserLogin();
}

///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
///@param nReason ����ԭ��
///        0x1001 �����ʧ��
///        0x1002 ����дʧ��
///        0x2001 ����������ʱ
///        0x2002 ��������ʧ��
///        0x2003 �յ�������
void CTraderSpi::OnFrontDisconnected(int nReason)
{
    cout << "--->>> "
	 << "OnFrontDisconnected"
	 << "--->>> Reason = " << hex << nReason << endl;
}

///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
void CTraderSpi::OnHeartBeatWarning(int nTimeLapse)
{
    cout << "--->>> "
	 << "OnHeartBeatWarning"
	 << "--->>> nTimerLapse = " << nTimeLapse << endl;
}

///�ͻ�����֤��Ӧ
void CTraderSpi::OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pRspAuthenticateField->BrokerID << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pRspAuthenticateField->UserID << endl;
	cout << "�û��˲�Ʒ��Ϣ TThostFtdcProductInfoType:" << pRspAuthenticateField->UserProductInfo << endl;
    }
}

///��¼������Ӧ
void CTraderSpi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "������ TThostFtdcDateType:" << pRspUserLogin->TradingDay << endl;
	cout << "��¼�ɹ�ʱ�� TThostFtdcTimeType:" << pRspUserLogin->LoginTime << endl;
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pRspUserLogin->BrokerID << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pRspUserLogin->UserID << endl;
	cout << "����ϵͳ���� TThostFtdcSystemNameType:" << pRspUserLogin->SystemName << endl;
	cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << pRspUserLogin->FrontID << endl;
	cout << "�Ự��� TThostFtdcSessionIDType:" << pRspUserLogin->SessionID << endl;
	cout << "��󱨵����� TThostFtdcOrderRefType:" << pRspUserLogin->MaxOrderRef << endl;
	cout << "������ʱ�� TThostFtdcTimeType:" << pRspUserLogin->SHFETime << endl;
	cout << "������ʱ�� TThostFtdcTimeType:" << pRspUserLogin->DCETime << endl;
	cout << "֣����ʱ�� TThostFtdcTimeType:" << pRspUserLogin->CZCETime << endl;
	cout << "�н���ʱ�� TThostFtdcTimeType:" << pRspUserLogin->FFEXTime << endl;
	cout << "��Դ����ʱ�� TThostFtdcTimeType:" << pRspUserLogin->INETime << endl;

	// FRONT_ID = pRspUserLogin->FrontID;
	// SESSION_ID = pRspUserLogin->SessionID;
	// int iNextOrderRef = atoi(pRspUserLogin->MaxOrderRef);
	// iNextOrderRef++;
	// sprintf(ORDER_REF, "%d", iNextOrderRef);
	///��ȡ��ǰ������
	// cout << "--->>> call api function GetTradingDay = " << userapi->GetTradingDay() << endl;
	///Ͷ���߽�����ȷ��
	// ReqSettlementInfoConfirm();
    }

    TestAllFunction();
}

///�ǳ�������Ӧ
void CTraderSpi::OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pUserLogout->BrokerID << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pUserLogout->UserID << endl;
    }
}

///�û��������������Ӧ
void CTraderSpi::OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pUserPasswordUpdate->BrokerID << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pUserPasswordUpdate->UserID << endl;
	cout << "ԭ���Ŀ��� TThostFtdcPasswordType:" << pUserPasswordUpdate->OldPassword << endl;
	cout << "�µĿ��� TThostFtdcPasswordType:" << pUserPasswordUpdate->NewPassword << endl;
    }
}

///�ʽ��˻��������������Ӧ
void CTraderSpi::OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pTradingAccountPasswordUpdate->BrokerID << endl;
	cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pTradingAccountPasswordUpdate->AccountID << endl;
	cout << "ԭ���Ŀ��� TThostFtdcPasswordType:" << pTradingAccountPasswordUpdate->OldPassword << endl;
	cout << "�µĿ��� TThostFtdcPasswordType:" << pTradingAccountPasswordUpdate->NewPassword << endl;
	cout << "���ִ��� TThostFtdcCurrencyIDType:" << pTradingAccountPasswordUpdate->CurrencyID << endl;
    }
}

///����¼��������Ӧ
void CTraderSpi::OnRspOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pInputOrder->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pInputOrder->InvestorID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pInputOrder->InstrumentID << endl;
	cout << "�������� TThostFtdcOrderRefType:" << pInputOrder->OrderRef << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pInputOrder->UserID << endl;
	cout << "�����۸����� TThostFtdcOrderPriceTypeType:" << pInputOrder->OrderPriceType << endl;
	cout << "�������� TThostFtdcDirectionType:" << pInputOrder->Direction << endl;
	cout << "��Ͽ�ƽ��־ TThostFtdcCombOffsetFlagType:" << pInputOrder->CombOffsetFlag << endl;
	cout << "���Ͷ���ױ���־ TThostFtdcCombHedgeFlagType:" << pInputOrder->CombHedgeFlag << endl;
	cout << "�۸� TThostFtdcPriceType:" << pInputOrder->LimitPrice << endl;
	cout << "���� TThostFtdcVolumeType:" << pInputOrder->VolumeTotalOriginal << endl;
	cout << "��Ч������ TThostFtdcTimeConditionType:" << pInputOrder->TimeCondition << endl;
	cout << "GTD���� pInputOrder->TThostFtdcDateType:" << pInputOrder->GTDDate << endl;
	cout << "�ɽ������� TThostFtdcVolumeConditionType:" << pInputOrder->VolumeCondition << endl;
	cout << "��С�ɽ��� TThostFtdcVolumeType:" << pInputOrder->MinVolume << endl;
	cout << "�������� TThostFtdcContingentConditionType:" << pInputOrder->ContingentCondition << endl;
	cout << "ֹ��� TThostFtdcPriceType:" << pInputOrder->StopPrice << endl;
	cout << "ǿƽԭ�� TThostFtdcForceCloseReasonType:" << pInputOrder->ForceCloseReason << endl;
	cout << "�Զ������־ TThostFtdcBoolType:" << pInputOrder->IsAutoSuspend << endl;
	cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << pInputOrder->BusinessUnit << endl;
	cout << "������ TThostFtdcRequestIDType:" << pInputOrder->RequestID << endl;
	cout << "�û�ǿ����־ TThostFtdcBoolType:" << pInputOrder->UserForceClose << endl;
	cout << "��������־ TThostFtdcBoolType:" << pInputOrder->IsSwapOrder << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pInputOrder->ExchangeID << endl;
    }
}

///Ԥ��¼��������Ӧ
void CTraderSpi::OnRspParkedOrderInsert(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pParkedOrder->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pParkedOrder->InvestorID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pParkedOrder->InstrumentID << endl;
	cout << "�������� TThostFtdcOrderRefType:" << pParkedOrder->OrderRef << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pParkedOrder->UserID << endl;
	cout << "�����۸����� TThostFtdcOrderPriceTypeType:" << pParkedOrder->OrderPriceType << endl;
	cout << "�������� TThostFtdcDirectionType:" << pParkedOrder->Direction << endl;
	cout << "��Ͽ�ƽ��־ TThostFtdcCombOffsetFlagType:" << pParkedOrder->CombOffsetFlag << endl;
	cout << "���Ͷ���ױ���־ TThostFtdcCombHedgeFlagType:" << pParkedOrder->CombHedgeFlag << endl;
	cout << "�۸� TThostFtdcPriceType:" << pParkedOrder->LimitPrice << endl;
	cout << "���� TThostFtdcVolumeType:" << pParkedOrder->VolumeTotalOriginal << endl;
	cout << "��Ч������ TThostFtdcTimeConditionType:" << pParkedOrder->TimeCondition << endl;
	// cout << "GTD����:" << pParkedOrder->TThostFtdcDateType << endlGTDDate;
	cout << "�ɽ������� TThostFtdcVolumeConditionType:" << pParkedOrder->VolumeCondition << endl;
	cout << "��С�ɽ��� TThostFtdcVolumeType:" << pParkedOrder->MinVolume << endl;
	cout << "�������� TThostFtdcContingentConditionType:" << pParkedOrder->ContingentCondition << endl;
	cout << "ֹ��� TThostFtdcPriceType:" << pParkedOrder->StopPrice << endl;
	cout << "ǿƽԭ�� TThostFtdcForceCloseReasonType:" << pParkedOrder->ForceCloseReason << endl;
	cout << "�Զ������־ TThostFtdcBoolType:" << pParkedOrder->IsAutoSuspend << endl;
	cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << pParkedOrder->BusinessUnit << endl;
	cout << "������ TThostFtdcRequestIDType:" << pParkedOrder->RequestID << endl;
	cout << "�û�ǿ����־ TThostFtdcBoolType:" << pParkedOrder->UserForceClose << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pParkedOrder->ExchangeID << endl;
	cout << "Ԥ�񱨵���� TThostFtdcParkedOrderIDType:" << pParkedOrder->ParkedOrderID << endl;
	cout << "�û����� TThostFtdcUserTypeType:" << pParkedOrder->UserType << endl;
	cout << "Ԥ��״̬ TThostFtdcParkedOrderStatusType:" << pParkedOrder->Status << endl;
	cout << "������� TThostFtdcErrorIDType:" << pParkedOrder->ErrorID << endl;
	cout << "������Ϣ TThostFtdcErrorMsgType:" << pParkedOrder->ErrorMsg << endl;
	cout << "��������־ TThostFtdcBoolType:" << pParkedOrder->IsSwapOrder << endl;
    }
}

///Ԥ�񳷵�¼��������Ӧ
void CTraderSpi::OnRspParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pParkedOrderAction->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pParkedOrderAction->InvestorID << endl;
	cout << "������������ TThostFtdcOrderActionRefType:" << pParkedOrderAction->OrderActionRef << endl;
	cout << "�������� TThostFtdcOrderRefType:" << pParkedOrderAction->OrderRef << endl;
	cout << "������ TThostFtdcRequestIDType:" << pParkedOrderAction->RequestID << endl;
	cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << pParkedOrderAction->FrontID << endl;
	cout << "�Ự��� TThostFtdcSessionIDType:" << pParkedOrderAction->SessionID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pParkedOrderAction->ExchangeID << endl;
	cout << "������� TThostFtdcOrderSysIDType:" << pParkedOrderAction->OrderSysID << endl;
	cout << "������־ TThostFtdcActionFlagType:" << pParkedOrderAction->ActionFlag << endl;
	cout << "�۸� TThostFtdcPriceType:" << pParkedOrderAction->LimitPrice << endl;
	cout << "�����仯 TThostFtdcVolumeType:" << pParkedOrderAction->VolumeChange << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pParkedOrderAction->UserID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pParkedOrderAction->InstrumentID << endl;
	cout << "Ԥ�񳷵������ TThostFtdcParkedOrderActionIDType:" << pParkedOrderAction->ParkedOrderActionID << endl;
	cout << "�û����� TThostFtdcUserTypeType:" << pParkedOrderAction->UserType << endl;
	cout << "Ԥ�񳷵�״̬ TThostFtdcParkedOrderStatusType:" << pParkedOrderAction->Status << endl;
	cout << "������� TThostFtdcErrorIDType:" << pParkedOrderAction->ErrorID << endl;
	cout << "������Ϣ TThostFtdcErrorMsgType:" << pParkedOrderAction->ErrorMsg << endl;
    }
}

///��������������Ӧ
void CTraderSpi::OnRspOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pInputOrderAction->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pInputOrderAction->InvestorID << endl;
	cout << "������������ TThostFtdcOrderActionRefType:" << pInputOrderAction->OrderActionRef << endl;
	cout << "�������� TThostFtdcOrderRefType:" << pInputOrderAction->OrderRef << endl;
	cout << "������ TThostFtdcRequestIDType:" << pInputOrderAction->RequestID << endl;
	cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << pInputOrderAction->FrontID << endl;
	cout << "�Ự��� TThostFtdcSessionIDType:" << pInputOrderAction->SessionID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pInputOrderAction->ExchangeID << endl;
	cout << "������� TThostFtdcOrderSysIDType:" << pInputOrderAction->OrderSysID << endl;
	cout << "������־ TThostFtdcActionFlagType:" << pInputOrderAction->ActionFlag << endl;
	cout << "�۸� TThostFtdcPriceType:" << pInputOrderAction->LimitPrice << endl;
	cout << "�����仯 TThostFtdcVolumeType:" << pInputOrderAction->VolumeChange << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pInputOrderAction->UserID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pInputOrderAction->InstrumentID << endl;
    }
}

///��ѯ��󱨵�������Ӧ
void CTraderSpi::OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField* pQueryMaxOrderVolume, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pQueryMaxOrderVolume->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pQueryMaxOrderVolume->InvestorID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pQueryMaxOrderVolume->InstrumentID << endl;
	cout << "�������� TThostFtdcDirectionType:" << pQueryMaxOrderVolume->Direction << endl;
	cout << "��ƽ��־ TThostFtdcOffsetFlagType:" << pQueryMaxOrderVolume->OffsetFlag << endl;
	cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pQueryMaxOrderVolume->HedgeFlag << endl;
	cout << "������������� TThostFtdcVolumeType:" << pQueryMaxOrderVolume->MaxVolume << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pQueryMaxOrderVolume->ExchangeID << endl;
    }
}

///Ͷ���߽�����ȷ����Ӧ
void CTraderSpi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pSettlementInfoConfirm->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pSettlementInfoConfirm->InvestorID << endl;
	cout << "ȷ������ TThostFtdcDateType:" << pSettlementInfoConfirm->ConfirmDate << endl;
	cout << "ȷ��ʱ�� TThostFtdcTimeType:" << pSettlementInfoConfirm->ConfirmTime << endl;
    }
}

///ɾ��Ԥ����Ӧ
void CTraderSpi::OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pRemoveParkedOrder->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pRemoveParkedOrder->InvestorID << endl;
	cout << "Ԥ�񱨵���� TThostFtdcParkedOrderIDType:" << pRemoveParkedOrder->ParkedOrderID << endl;
    }
}

///ɾ��Ԥ�񳷵���Ӧ
void CTraderSpi::OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pRemoveParkedOrderAction->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pRemoveParkedOrderAction->InvestorID << endl;
	cout << "Ԥ�񳷵���� TThostFtdcParkedOrderActionIDType:" << pRemoveParkedOrderAction->ParkedOrderActionID << endl;
    }
}

///ִ������¼��������Ӧ
void CTraderSpi::OnRspExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pInputExecOrder->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pInputExecOrder->InvestorID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pInputExecOrder->InstrumentID << endl;
	cout << "ִ���������� TThostFtdcOrderRefType:" << pInputExecOrder->ExecOrderRef << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pInputExecOrder->UserID << endl;
	cout << "���� TThostFtdcVolumeType:" << pInputExecOrder->Volume << endl;
	cout << "������ TThostFtdcRequestIDType:" << pInputExecOrder->RequestID << endl;
	cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << pInputExecOrder->BusinessUnit << endl;
	cout << "��ƽ��־ TThostFtdcOffsetFlagType:" << pInputExecOrder->OffsetFlag << endl;
	cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pInputExecOrder->HedgeFlag << endl;
	cout << "ִ������ TThostFtdcActionTypeType:" << pInputExecOrder->ActionType << endl;
	cout << "����ͷ������ĳֲַ��� TThostFtdcPosiDirectionType:" << pInputExecOrder->PosiDirection << endl;
	cout << "��Ȩ��Ȩ���Ƿ����ڻ�ͷ��ı�� TThostFtdcExecOrderPositionFlagType:" << pInputExecOrder->ReservePositionFlag << endl;
	cout << "��Ȩ��Ȩ�����ɵ�ͷ���Ƿ��Զ�ƽ�� TThostFtdcExecOrderCloseFlagType:" << pInputExecOrder->CloseFlag << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pInputExecOrder->ExchangeID << endl;
    }
}

///ִ���������������Ӧ
void CTraderSpi::OnRspExecOrderAction(CThostFtdcInputExecOrderActionField* pInputExecOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pInputExecOrderAction->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pInputExecOrderAction->InvestorID << endl;
	cout << "ִ������������� TThostFtdcOrderActionRefType:" << pInputExecOrderAction->ExecOrderActionRef << endl;
	cout << "ִ���������� TThostFtdcOrderRefType:" << pInputExecOrderAction->ExecOrderRef << endl;
	cout << "������ TThostFtdcRequestIDType:" << pInputExecOrderAction->RequestID << endl;
	cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << pInputExecOrderAction->FrontID << endl;
	cout << "�Ự��� TThostFtdcSessionIDType:" << pInputExecOrderAction->SessionID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pInputExecOrderAction->ExchangeID << endl;
	cout << "ִ������������ TThostFtdcExecOrderSysIDType:" << pInputExecOrderAction->ExecOrderSysID << endl;
	cout << "������־ TThostFtdcActionFlagType:" << pInputExecOrderAction->ActionFlag << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pInputExecOrderAction->UserID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pInputExecOrderAction->InstrumentID << endl;
    }
}

///ѯ��¼��������Ӧ
void CTraderSpi::OnRspForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pInputForQuote->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pInputForQuote->InvestorID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pInputForQuote->InstrumentID << endl;
	cout << "ѯ������ TThostFtdcOrderRefType:" << pInputForQuote->ForQuoteRef << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pInputForQuote->UserID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pInputForQuote->ExchangeID << endl;
    }
}

///����¼��������Ӧ
void CTraderSpi::OnRspQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pInputQuote->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pInputQuote->InvestorID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pInputQuote->InstrumentID << endl;
	cout << "�������� TThostFtdcOrderRefType:" << pInputQuote->QuoteRef << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pInputQuote->UserID << endl;
	cout << "���۸� TThostFtdcPriceType:" << pInputQuote->AskPrice << endl;
	cout << "��۸� TThostFtdcPriceType:" << pInputQuote->BidPrice << endl;
	cout << "������ TThostFtdcVolumeType:" << pInputQuote->AskVolume << endl;
	cout << "������ TThostFtdcVolumeType:" << pInputQuote->BidVolume << endl;
	cout << "������ TThostFtdcRequestIDType:" << pInputQuote->RequestID << endl;
	cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << pInputQuote->BusinessUnit << endl;
	cout << "����ƽ��־ TThostFtdcOffsetFlagType:" << pInputQuote->AskOffsetFlag << endl;
	cout << "��ƽ��־ TThostFtdcOffsetFlagType:" << pInputQuote->BidOffsetFlag << endl;
	cout << "��Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pInputQuote->AskHedgeFlag << endl;
	cout << "��Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pInputQuote->BidHedgeFlag << endl;
	cout << "�������������� TThostFtdcOrderRefType:" << pInputQuote->AskOrderRef << endl;
	cout << "�����򱨵����� TThostFtdcOrderRefType:" << pInputQuote->BidOrderRef << endl;
	cout << "Ӧ�۱�� TThostFtdcOrderSysIDType:" << pInputQuote->ForQuoteSysID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pInputQuote->ExchangeID << endl;
    }
}

///���۲���������Ӧ
void CTraderSpi::OnRspQuoteAction(CThostFtdcInputQuoteActionField* pInputQuoteAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pInputQuoteAction->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pInputQuoteAction->InvestorID << endl;
	cout << "���۲������� TThostFtdcOrderActionRefType:" << pInputQuoteAction->QuoteActionRef << endl;
	cout << "�������� TThostFtdcOrderRefType:" << pInputQuoteAction->QuoteRef << endl;
	cout << "������ TThostFtdcRequestIDType:" << pInputQuoteAction->RequestID << endl;
	cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << pInputQuoteAction->FrontID << endl;
	cout << "�Ự��� TThostFtdcSessionIDType:" << pInputQuoteAction->SessionID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pInputQuoteAction->ExchangeID << endl;
	cout << "���۲������ TThostFtdcOrderSysIDType:" << pInputQuoteAction->QuoteSysID << endl;
	cout << "������־ TThostFtdcActionFlagType:" << pInputQuoteAction->ActionFlag << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pInputQuoteAction->UserID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pInputQuoteAction->InstrumentID << endl;
    }
}

///����Ӧ��
void CTraderSpi::OnRspLockInsert(CThostFtdcInputLockField* pInputLock, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pInputLock->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pInputLock->InvestorID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pInputLock->InstrumentID << endl;
	cout << "�������� TThostFtdcOrderRefType:" << pInputLock->LockRef << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pInputLock->UserID << endl;
	cout << "���� TThostFtdcVolumeType:" << pInputLock->Volume << endl;
	cout << "������ TThostFtdcRequestIDType:" << pInputLock->RequestID << endl;
	cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << pInputLock->BusinessUnit << endl;
	cout << "�������� TThostFtdcLockTypeType:" << pInputLock->LockType << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pInputLock->ExchangeID << endl;
    }
}

///�������¼��������Ӧ
void CTraderSpi::OnRspCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pInputCombAction->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pInputCombAction->InvestorID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pInputCombAction->InstrumentID << endl;
	cout << "������� TThostFtdcOrderRefType:" << pInputCombAction->CombActionRef << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pInputCombAction->UserID << endl;
	cout << "�������� TThostFtdcDirectionType:" << pInputCombAction->Direction << endl;
	cout << "���� TThostFtdcVolumeType:" << pInputCombAction->Volume << endl;
	cout << "���ָ��� TThostFtdcCombDirectionType:" << pInputCombAction->CombDirection << endl;
	cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pInputCombAction->HedgeFlag << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pInputCombAction->ExchangeID << endl;
    }
}

///�����ѯ������Ӧ
void CTraderSpi::OnRspQryOrder(CThostFtdcOrderField* pOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pOrder->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pOrder->InvestorID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pOrder->InstrumentID << endl;
	cout << "�������� TThostFtdcOrderRefType:" << pOrder->OrderRef << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pOrder->UserID << endl;
	cout << "�����۸����� TThostFtdcOrderPriceTypeType:" << pOrder->OrderPriceType << endl;
	cout << "�������� TThostFtdcDirectionType:" << pOrder->Direction << endl;
	cout << "��Ͽ�ƽ��־ TThostFtdcCombOffsetFlagType:" << pOrder->CombOffsetFlag << endl;
	cout << "���Ͷ���ױ���־ TThostFtdcCombHedgeFlagType:" << pOrder->CombHedgeFlag << endl;
	cout << "�۸� TThostFtdcPriceType:" << pOrder->LimitPrice << endl;
	cout << "���� TThostFtdcVolumeType:" << pOrder->VolumeTotalOriginal << endl;
	cout << "��Ч������ TThostFtdcTimeConditionType:" << pOrder->TimeCondition << endl;
	// cout << "GTD����:" << pOrder->TThostFtdcDateType << endlGTDDate;
	cout << "�ɽ������� TThostFtdcVolumeConditionType:" << pOrder->VolumeCondition << endl;
	cout << "��С�ɽ��� TThostFtdcVolumeType:" << pOrder->MinVolume << endl;
	cout << "�������� TThostFtdcContingentConditionType:" << pOrder->ContingentCondition << endl;
	cout << "ֹ��� TThostFtdcPriceType:" << pOrder->StopPrice << endl;
	cout << "ǿƽԭ�� TThostFtdcForceCloseReasonType:" << pOrder->ForceCloseReason << endl;
	cout << "�Զ������־ TThostFtdcBoolType:" << pOrder->IsAutoSuspend << endl;
	cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << pOrder->BusinessUnit << endl;
	cout << "������ TThostFtdcRequestIDType:" << pOrder->RequestID << endl;
	cout << "���ر������ TThostFtdcOrderLocalIDType:" << pOrder->OrderLocalID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pOrder->ExchangeID << endl;
	cout << "��Ա���� TThostFtdcParticipantIDType:" << pOrder->ParticipantID << endl;
	cout << "�ͻ����� TThostFtdcClientIDType:" << pOrder->ClientID << endl;
	cout << "��Լ�ڽ������Ĵ��� TThostFtdcExchangeInstIDType:" << pOrder->ExchangeInstID << endl;
	cout << "����������Ա���� TThostFtdcTraderIDType:" << pOrder->TraderID << endl;
	cout << "��װ��� TThostFtdcInstallIDType:" << pOrder->InstallID << endl;
	cout << "�����ύ״̬ TThostFtdcOrderSubmitStatusType:" << pOrder->OrderSubmitStatus << endl;
	cout << "������ʾ��� TThostFtdcSequenceNoType:" << pOrder->NotifySequence << endl;
	cout << "������ TThostFtdcDateType:" << pOrder->TradingDay << endl;
	cout << "������ TThostFtdcSettlementIDType:" << pOrder->SettlementID << endl;
	cout << "������� TThostFtdcOrderSysIDType:" << pOrder->OrderSysID << endl;
	cout << "������Դ TThostFtdcOrderSourceType:" << pOrder->OrderSource << endl;
	cout << "����״̬ TThostFtdcOrderStatusType:" << pOrder->OrderStatus << endl;
	cout << "�������� TThostFtdcOrderTypeType:" << pOrder->OrderType << endl;
	cout << "��ɽ����� TThostFtdcVolumeType:" << pOrder->VolumeTraded << endl;
	cout << "ʣ������ TThostFtdcVolumeType:" << pOrder->VolumeTotal << endl;
	cout << "�������� TThostFtdcDateType:" << pOrder->InsertDate << endl;
	cout << "ί��ʱ�� TThostFtdcTimeType:" << pOrder->InsertTime << endl;
	cout << "����ʱ�� TThostFtdcTimeType:" << pOrder->ActiveTime << endl;
	cout << "����ʱ�� TThostFtdcTimeType:" << pOrder->SuspendTime << endl;
	cout << "����޸�ʱ�� TThostFtdcTimeType:" << pOrder->UpdateTime << endl;
	cout << "����ʱ�� TThostFtdcTimeType:" << pOrder->CancelTime << endl;
	cout << "����޸Ľ���������Ա���� TThostFtdcTraderIDType:" << pOrder->ActiveTraderID << endl;
	cout << "�����Ա��� TThostFtdcParticipantIDType:" << pOrder->ClearingPartID << endl;
	cout << "��� TThostFtdcSequenceNoType:" << pOrder->SequenceNo << endl;
	cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << pOrder->FrontID << endl;
	cout << "�Ự��� TThostFtdcSessionIDType:" << pOrder->SessionID << endl;
	cout << "�û��˲�Ʒ��Ϣ TThostFtdcProductInfoType:" << pOrder->UserProductInfo << endl;
	cout << "״̬��Ϣ TThostFtdcErrorMsgType:" << pOrder->StatusMsg << endl;
	cout << "�û�ǿ����־ TThostFtdcBoolType:" << pOrder->UserForceClose << endl;
	cout << "�����û����� TThostFtdcUserIDType:" << pOrder->ActiveUserID << endl;
	cout << "���͹�˾������� TThostFtdcSequenceNoType:" << pOrder->BrokerOrderSeq << endl;
	cout << "��ر��� TThostFtdcOrderSysIDType:" << pOrder->RelativeOrderSysID << endl;
	cout << "֣�����ɽ����� TThostFtdcVolumeType:" << pOrder->ZCETotalTradedVolume << endl;
	cout << "��������־ TThostFtdcBoolType:" << pOrder->IsSwapOrder << endl;
	cout << "Ӫҵ����� TThostFtdcBranchIDType:" << pOrder->BranchID << endl;
    }
}

///�����ѯ�ɽ���Ӧ
void CTraderSpi::OnRspQryTrade(CThostFtdcTradeField* pTrade, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pTrade->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pTrade->InvestorID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pTrade->InstrumentID << endl;
	cout << "�������� TThostFtdcOrderRefType:" << pTrade->OrderRef << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pTrade->UserID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pTrade->ExchangeID << endl;
	cout << "�ɽ���� TThostFtdcTradeIDType:" << pTrade->TradeID << endl;
	cout << "�������� TThostFtdcDirectionType:" << pTrade->Direction << endl;
	cout << "������� TThostFtdcOrderSysIDType:" << pTrade->OrderSysID << endl;
	cout << "��Ա���� TThostFtdcParticipantIDType:" << pTrade->ParticipantID << endl;
	cout << "�ͻ����� TThostFtdcClientIDType:" << pTrade->ClientID << endl;
	cout << "���׽�ɫ TThostFtdcTradingRoleType:" << pTrade->TradingRole << endl;
	cout << "��Լ�ڽ������Ĵ��� TThostFtdcExchangeInstIDType:" << pTrade->ExchangeInstID << endl;
	cout << "��ƽ��־ TThostFtdcOffsetFlagType:" << pTrade->OffsetFlag << endl;
	cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pTrade->HedgeFlag << endl;
	cout << "�۸� TThostFtdcPriceType:" << pTrade->Price << endl;
	cout << "���� TThostFtdcVolumeType:" << pTrade->Volume << endl;
	cout << "�ɽ�ʱ�� TThostFtdcDateType:" << pTrade->TradeDate << endl;
	cout << "�ɽ�ʱ�� TThostFtdcTimeType:" << pTrade->TradeTime << endl;
	cout << "�ɽ����� TThostFtdcTradeTypeType:" << pTrade->TradeType << endl;
	cout << "�ɽ�����Դ TThostFtdcPriceSourceType:" << pTrade->PriceSource << endl;
	cout << "����������Ա���� TThostFtdcTraderIDType:" << pTrade->TraderID << endl;
	cout << "���ر������ TThostFtdcOrderLocalIDType:" << pTrade->OrderLocalID << endl;
	cout << "�����Ա��� TThostFtdcParticipantIDType:" << pTrade->ClearingPartID << endl;
	cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << pTrade->BusinessUnit << endl;
	cout << "��� TThostFtdcSequenceNoType:" << pTrade->SequenceNo << endl;
	cout << "������ TThostFtdcDateType:" << pTrade->TradingDay << endl;
	cout << "������ TThostFtdcSettlementIDType:" << pTrade->SettlementID << endl;
	cout << "���͹�˾������� TThostFtdcSequenceNoType:" << pTrade->BrokerOrderSeq << endl;
	cout << "�ɽ���Դ TThostFtdcTradeSourceType:" << pTrade->TradeSource << endl;
    }
}

///�����ѯͶ���ֲ߳���Ӧ
void CTraderSpi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField* pInvestorPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pInvestorPosition->InstrumentID << endl;
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pInvestorPosition->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pInvestorPosition->InvestorID << endl;
	cout << "�ֲֶ�շ��� TThostFtdcPosiDirectionType:" << pInvestorPosition->PosiDirection << endl;
	cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pInvestorPosition->HedgeFlag << endl;
	cout << "�ֲ����� TThostFtdcPositionDateType:" << pInvestorPosition->PositionDate << endl;
	cout << "���ճֲ� TThostFtdcVolumeType:" << pInvestorPosition->YdPosition << endl;
	cout << "���ճֲ� TThostFtdcVolumeType:" << pInvestorPosition->Position << endl;
	cout << "��ͷ���� TThostFtdcVolumeType:" << pInvestorPosition->LongFrozen << endl;
	cout << "��ͷ���� TThostFtdcVolumeType:" << pInvestorPosition->ShortFrozen << endl;
	cout << "���ֶ����� TThostFtdcMoneyType:" << pInvestorPosition->LongFrozenAmount << endl;
	cout << "���ֶ����� TThostFtdcMoneyType:" << pInvestorPosition->ShortFrozenAmount << endl;
	cout << "������ TThostFtdcVolumeType:" << pInvestorPosition->OpenVolume << endl;
	cout << "ƽ���� TThostFtdcVolumeType:" << pInvestorPosition->CloseVolume << endl;
	cout << "���ֽ�� TThostFtdcMoneyType:" << pInvestorPosition->OpenAmount << endl;
	cout << "ƽ�ֽ�� TThostFtdcMoneyType:" << pInvestorPosition->CloseAmount << endl;
	cout << "�ֲֳɱ� TThostFtdcMoneyType:" << pInvestorPosition->PositionCost << endl;
	cout << "�ϴ�ռ�õı�֤�� TThostFtdcMoneyType:" << pInvestorPosition->PreMargin << endl;
	cout << "ռ�õı�֤�� TThostFtdcMoneyType:" << pInvestorPosition->UseMargin << endl;
	cout << "����ı�֤�� TThostFtdcMoneyType:" << pInvestorPosition->FrozenMargin << endl;
	cout << "������ʽ� TThostFtdcMoneyType:" << pInvestorPosition->FrozenCash << endl;
	cout << "����������� TThostFtdcMoneyType:" << pInvestorPosition->FrozenCommission << endl;
	cout << "�ʽ��� TThostFtdcMoneyType:" << pInvestorPosition->CashIn << endl;
	cout << "������ TThostFtdcMoneyType:" << pInvestorPosition->Commission << endl;
	cout << "ƽ��ӯ�� TThostFtdcMoneyType:" << pInvestorPosition->CloseProfit << endl;
	cout << "�ֲ�ӯ�� TThostFtdcMoneyType:" << pInvestorPosition->PositionProfit << endl;
	cout << "�ϴν���� TThostFtdcPriceType:" << pInvestorPosition->PreSettlementPrice << endl;
	cout << "���ν���� TThostFtdcPriceType:" << pInvestorPosition->SettlementPrice << endl;
	cout << "������ TThostFtdcDateType:" << pInvestorPosition->TradingDay << endl;
	cout << "������ TThostFtdcSettlementIDType:" << pInvestorPosition->SettlementID << endl;
	cout << "���ֳɱ� TThostFtdcMoneyType:" << pInvestorPosition->OpenCost << endl;
	cout << "��������֤�� TThostFtdcMoneyType:" << pInvestorPosition->ExchangeMargin << endl;
	cout << "��ϳɽ��γɵĳֲ� TThostFtdcVolumeType:" << pInvestorPosition->CombPosition << endl;
	cout << "��϶�ͷ���� TThostFtdcVolumeType:" << pInvestorPosition->CombLongFrozen << endl;
	cout << "��Ͽ�ͷ���� TThostFtdcVolumeType:" << pInvestorPosition->CombShortFrozen << endl;
	cout << "���ն���ƽ��ӯ�� TThostFtdcMoneyType:" << pInvestorPosition->CloseProfitByDate << endl;
	cout << "��ʶԳ�ƽ��ӯ�� TThostFtdcMoneyType:" << pInvestorPosition->CloseProfitByTrade << endl;
	cout << "���ճֲ� TThostFtdcVolumeType:" << pInvestorPosition->TodayPosition << endl;
	cout << "��֤���� TThostFtdcRatioType:" << pInvestorPosition->MarginRateByMoney << endl;
	cout << "��֤���ʰ����� TThostFtdcRatioType:" << pInvestorPosition->MarginRateByVolume << endl;
	cout << "ִ�ж��� TThostFtdcVolumeType:" << pInvestorPosition->StrikeFrozen << endl;
	cout << "ִ�ж����� TThostFtdcMoneyType:" << pInvestorPosition->StrikeFrozenAmount << endl;
	cout << "����ִ�ж��� TThostFtdcVolumeType:" << pInvestorPosition->AbandonFrozen << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pInvestorPosition->ExchangeID << endl;
	cout << "ִ�ж������� TThostFtdcVolumeType:" << pInvestorPosition->YdStrikeFrozen << endl;
    }
}

///�����ѯ�ʽ��˻���Ӧ
void CTraderSpi::OnRspQryTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> "
	 << "OnRspQryTradingAccount" << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pTradingAccount->BrokerID << endl;
	cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pTradingAccount->AccountID << endl;
	cout << "�ϴ���Ѻ��� TThostFtdcMoneyType:" << pTradingAccount->PreMortgage << endl;
	cout << "�ϴ����ö�� TThostFtdcMoneyType:" << pTradingAccount->PreCredit << endl;
	cout << "�ϴδ��� TThostFtdcMoneyType:" << pTradingAccount->PreDeposit << endl;
	cout << "�ϴν���׼���� TThostFtdcMoneyType:" << pTradingAccount->PreBalance << endl;
	cout << "�ϴ�ռ�õı�֤�� TThostFtdcMoneyType:" << pTradingAccount->PreMargin << endl;
	cout << "��Ϣ���� TThostFtdcMoneyType:" << pTradingAccount->InterestBase << endl;
	cout << "��Ϣ���� TThostFtdcMoneyType:" << pTradingAccount->Interest << endl;
	cout << "����� TThostFtdcMoneyType:" << pTradingAccount->Deposit << endl;
	cout << "������ TThostFtdcMoneyType:" << pTradingAccount->Withdraw << endl;
	cout << "����ı�֤�� TThostFtdcMoneyType:" << pTradingAccount->FrozenMargin << endl;
	cout << "������ʽ� TThostFtdcMoneyType:" << pTradingAccount->FrozenCash << endl;
	cout << "����������� TThostFtdcMoneyType:" << pTradingAccount->FrozenCommission << endl;
	cout << "��ǰ��֤���ܶ� TThostFtdcMoneyType:" << pTradingAccount->CurrMargin << endl;
	cout << "�ʽ��� TThostFtdcMoneyType:" << pTradingAccount->CashIn << endl;
	cout << "������ TThostFtdcMoneyType:" << pTradingAccount->Commission << endl;
	cout << "ƽ��ӯ�� TThostFtdcMoneyType:" << pTradingAccount->CloseProfit << endl;
	cout << "�ֲ�ӯ�� TThostFtdcMoneyType:" << pTradingAccount->PositionProfit << endl;
	cout << "�ڻ�����׼���� TThostFtdcMoneyType:" << pTradingAccount->Balance << endl;
	cout << "�����ʽ� TThostFtdcMoneyType:" << pTradingAccount->Available << endl;
	cout << "��ȡ�ʽ� TThostFtdcMoneyType:" << pTradingAccount->WithdrawQuota << endl;
	cout << "����׼���� TThostFtdcMoneyType:" << pTradingAccount->Reserve << endl;
	cout << "������ TThostFtdcDateType:" << pTradingAccount->TradingDay << endl;
	cout << "������ TThostFtdcSettlementIDType:" << pTradingAccount->SettlementID << endl;
	cout << "���ö�� TThostFtdcMoneyType:" << pTradingAccount->Credit << endl;
	cout << "��Ѻ��� TThostFtdcMoneyType:" << pTradingAccount->Mortgage << endl;
	cout << "��������֤�� TThostFtdcMoneyType:" << pTradingAccount->ExchangeMargin << endl;
	cout << "Ͷ���߽��֤�� TThostFtdcMoneyType:" << pTradingAccount->DeliveryMargin << endl;
	cout << "���������֤�� TThostFtdcMoneyType:" << pTradingAccount->ExchangeDeliveryMargin << endl;
	cout << "�����ڻ�����׼���� TThostFtdcMoneyType:" << pTradingAccount->ReserveBalance << endl;
	cout << "���ִ��� TThostFtdcCurrencyIDType:" << pTradingAccount->CurrencyID << endl;
	cout << "�ϴλ��������� TThostFtdcMoneyType:" << pTradingAccount->PreFundMortgageIn << endl;
	cout << "�ϴλ����ʳ���� TThostFtdcMoneyType:" << pTradingAccount->PreFundMortgageOut << endl;
	cout << "���������� TThostFtdcMoneyType:" << pTradingAccount->FundMortgageIn << endl;
	cout << "�����ʳ���� TThostFtdcMoneyType:" << pTradingAccount->FundMortgageOut << endl;
	cout << "������Ѻ��� TThostFtdcMoneyType:" << pTradingAccount->FundMortgageAvailable << endl;
	cout << "����Ѻ���ҽ�� TThostFtdcMoneyType:" << pTradingAccount->MortgageableFund << endl;
	cout << "�����Ʒռ�ñ�֤�� TThostFtdcMoneyType:" << pTradingAccount->SpecProductMargin << endl;
	cout << "�����Ʒ���ᱣ֤�� TThostFtdcMoneyType:" << pTradingAccount->SpecProductFrozenMargin << endl;
	cout << "�����Ʒ������ TThostFtdcMoneyType:" << pTradingAccount->SpecProductCommission << endl;
	cout << "�����Ʒ���������� TThostFtdcMoneyType:" << pTradingAccount->SpecProductFrozenCommission << endl;
	cout << "�����Ʒ�ֲ�ӯ�� TThostFtdcMoneyType:" << pTradingAccount->SpecProductPositionProfit << endl;
	cout << "�����Ʒƽ��ӯ�� TThostFtdcMoneyType:" << pTradingAccount->SpecProductCloseProfit << endl;
	cout << "���ݳֲ�ӯ���㷨����������Ʒ�ֲ�ӯ�� TThostFtdcMoneyType:" << pTradingAccount->SpecProductPositionProfitByAlg << endl;
	cout << "�����Ʒ��������֤�� TThostFtdcMoneyType:" << pTradingAccount->SpecProductExchangeMargin << endl;
	cout << "ҵ������ TThostFtdcBizTypeType:" << pTradingAccount->BizType << endl;
    }
}

///�����ѯͶ������Ӧ
void CTraderSpi::OnRspQryInvestor(CThostFtdcInvestorField* pInvestor, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pInvestor->InvestorID << endl;
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pInvestor->BrokerID << endl;
	cout << "Ͷ���߷������ TThostFtdcInvestorIDType:" << pInvestor->InvestorGroupID << endl;
	cout << "Ͷ�������� TThostFtdcPartyNameType:" << pInvestor->InvestorName << endl;
	cout << "֤������ TThostFtdcIdCardTypeType:" << pInvestor->IdentifiedCardType << endl;
	cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pInvestor->IdentifiedCardNo << endl;
	cout << "�Ƿ��Ծ TThostFtdcBoolType:" << pInvestor->IsActive << endl;
	cout << "��ϵ�绰 TThostFtdcTelephoneType:" << pInvestor->Telephone << endl;
	cout << "ͨѶ��ַ TThostFtdcAddressType:" << pInvestor->Address << endl;
	cout << "�������� TThostFtdcDateType:" << pInvestor->OpenDate << endl;
	cout << "�ֻ� TThostFtdcMobileType:" << pInvestor->Mobile << endl;
	cout << "��������ģ����� TThostFtdcInvestorIDType:" << pInvestor->CommModelID << endl;
	cout << "��֤����ģ����� TThostFtdcInvestorIDType:" << pInvestor->MarginModelID << endl;
    }
}

///�����ѯ���ױ�����Ӧ
void CTraderSpi::OnRspQryTradingCode(CThostFtdcTradingCodeField* pTradingCode, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pTradingCode->InvestorID << endl;
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pTradingCode->BrokerID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pTradingCode->ExchangeID << endl;
	cout << "�ͻ����� TThostFtdcClientIDType:" << pTradingCode->ClientID << endl;
	cout << "�Ƿ��Ծ TThostFtdcBoolType:" << pTradingCode->IsActive << endl;
	cout << "���ױ������� TThostFtdcClientIDTypeType:" << pTradingCode->ClientIDType << endl;
	cout << "Ӫҵ����� TThostFtdcBranchIDType:" << pTradingCode->BranchID << endl;
	cout << "ҵ������ TThostFtdcBizTypeType:" << pTradingCode->BizType << endl;
    }
}

///�����ѯ��Լ��֤������Ӧ
void CTraderSpi::OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField* pInstrumentMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pInstrumentMarginRate->InstrumentID << endl;
	cout << "Ͷ���߷�Χ TThostFtdcInvestorRangeType:" << pInstrumentMarginRate->InvestorRange << endl;
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pInstrumentMarginRate->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pInstrumentMarginRate->InvestorID << endl;
	cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pInstrumentMarginRate->HedgeFlag << endl;
	cout << "��ͷ��֤���� TThostFtdcRatioType:" << pInstrumentMarginRate->LongMarginRatioByMoney << endl;
	cout << "��ͷ��֤��� TThostFtdcMoneyType:" << pInstrumentMarginRate->LongMarginRatioByVolume << endl;
	cout << "��ͷ��֤���� TThostFtdcRatioType:" << pInstrumentMarginRate->ShortMarginRatioByMoney << endl;
	cout << "��ͷ��֤��� TThostFtdcMoneyType:" << pInstrumentMarginRate->ShortMarginRatioByVolume << endl;
	cout << "�Ƿ���Խ�������ȡ TThostFtdcBoolType:" << pInstrumentMarginRate->IsRelative << endl;
    }
}

///�����ѯ��Լ����������Ӧ
void CTraderSpi::OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField* pInstrumentCommissionRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pInstrumentCommissionRate->InstrumentID << endl;
	cout << "Ͷ���߷�Χ TThostFtdcInvestorRangeType:" << pInstrumentCommissionRate->InvestorRange << endl;
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pInstrumentCommissionRate->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pInstrumentCommissionRate->InvestorID << endl;
	cout << "������������ TThostFtdcRatioType:" << pInstrumentCommissionRate->OpenRatioByMoney << endl;
	cout << "���������� TThostFtdcRatioType:" << pInstrumentCommissionRate->OpenRatioByVolume << endl;
	cout << "ƽ���������� TThostFtdcRatioType:" << pInstrumentCommissionRate->CloseRatioByMoney << endl;
	cout << "ƽ�������� TThostFtdcRatioType:" << pInstrumentCommissionRate->CloseRatioByVolume << endl;
	cout << "ƽ���������� TThostFtdcRatioType:" << pInstrumentCommissionRate->CloseTodayRatioByMoney << endl;
	cout << "ƽ�������� TThostFtdcRatioType:" << pInstrumentCommissionRate->CloseTodayRatioByVolume << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pInstrumentCommissionRate->ExchangeID << endl;
	cout << "ҵ������ TThostFtdcBizTypeType:" << pInstrumentCommissionRate->BizType << endl;
    }
}

///�����ѯ��������Ӧ
void CTraderSpi::OnRspQryExchange(CThostFtdcExchangeField* pExchange, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���������� TThostFtdcExchangeIDType:" << pExchange->ExchangeID << endl;
	cout << "���������� TThostFtdcExchangeNameType:" << pExchange->ExchangeName << endl;
	cout << "���������� TThostFtdcExchangePropertyType:" << pExchange->ExchangeProperty << endl;
    }
}

///�����ѯ��Ʒ��Ӧ
void CTraderSpi::OnRspQryProduct(CThostFtdcProductField* pProduct, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "��Ʒ���� TThostFtdcInstrumentIDType:" << pProduct->ProductID << endl;
	cout << "��Ʒ���� TThostFtdcProductNameType:" << pProduct->ProductName << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pProduct->ExchangeID << endl;
	cout << "��Ʒ���� TThostFtdcProductClassType:" << pProduct->ProductClass << endl;
	cout << "��Լ�������� TThostFtdcVolumeMultipleType:" << pProduct->VolumeMultiple << endl;
	cout << "��С�䶯��λ TThostFtdcPriceType:" << pProduct->PriceTick << endl;
	cout << "�м۵�����µ��� TThostFtdcVolumeType:" << pProduct->MaxMarketOrderVolume << endl;
	cout << "�м۵���С�µ��� TThostFtdcVolumeType:" << pProduct->MinMarketOrderVolume << endl;
	cout << "�޼۵�����µ��� TThostFtdcVolumeType:" << pProduct->MaxLimitOrderVolume << endl;
	cout << "�޼۵���С�µ��� TThostFtdcVolumeType:" << pProduct->MinLimitOrderVolume << endl;
	cout << "�ֲ����� TThostFtdcPositionTypeType:" << pProduct->PositionType << endl;
	cout << "�ֲ��������� TThostFtdcPositionDateTypeType:" << pProduct->PositionDateType << endl;
	cout << "ƽ�ִ������� TThostFtdcCloseDealTypeType:" << pProduct->CloseDealType << endl;
	cout << "���ױ������� TThostFtdcCurrencyIDType:" << pProduct->TradeCurrencyID << endl;
	cout << "��Ѻ�ʽ���÷�Χ TThostFtdcMortgageFundUseRangeType:" << pProduct->MortgageFundUseRange << endl;
	cout << "��������Ʒ���� TThostFtdcInstrumentIDType:" << pProduct->ExchangeProductID << endl;
	cout << "��Լ������Ʒ���� TThostFtdcUnderlyingMultipleType:" << pProduct->UnderlyingMultiple << endl;
    }
}

///�����ѯ��Լ��Ӧ
void CTraderSpi::OnRspQryInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> "
	 << "OnRspQryInstrument" << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pInstrument->InstrumentID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pInstrument->ExchangeID << endl;
	cout << "��Լ���� TThostFtdcInstrumentNameType:" << pInstrument->InstrumentName << endl;
	cout << "��Լ�ڽ������Ĵ��� TThostFtdcExchangeInstIDType:" << pInstrument->ExchangeInstID << endl;
	cout << "��Ʒ���� TThostFtdcInstrumentIDType:" << pInstrument->ProductID << endl;
	cout << "��Ʒ���� TThostFtdcProductClassType:" << pInstrument->ProductClass << endl;
	cout << "������� TThostFtdcYearType:" << pInstrument->DeliveryYear << endl;
	cout << "������ TThostFtdcMonthType:" << pInstrument->DeliveryMonth << endl;
	cout << "�м۵�����µ��� TThostFtdcVolumeType:" << pInstrument->MaxMarketOrderVolume << endl;
	cout << "�м۵���С�µ��� TThostFtdcVolumeType:" << pInstrument->MinMarketOrderVolume << endl;
	cout << "�޼۵�����µ��� TThostFtdcVolumeType:" << pInstrument->MaxLimitOrderVolume << endl;
	cout << "�޼۵���С�µ��� TThostFtdcVolumeType:" << pInstrument->MinLimitOrderVolume << endl;
	cout << "��Լ�������� TThostFtdcVolumeMultipleType:" << pInstrument->VolumeMultiple << endl;
	cout << "��С�䶯��λ TThostFtdcPriceType:" << pInstrument->PriceTick << endl;
	cout << "������ TThostFtdcDateType:" << pInstrument->CreateDate << endl;
	cout << "������ TThostFtdcDateType:" << pInstrument->OpenDate << endl;
	cout << "������ TThostFtdcDateType:" << pInstrument->ExpireDate << endl;
	cout << "��ʼ������ TThostFtdcDateType:" << pInstrument->StartDelivDate << endl;
	cout << "���������� TThostFtdcDateType:" << pInstrument->EndDelivDate << endl;
	cout << "��Լ��������״̬ TThostFtdcInstLifePhaseType:" << pInstrument->InstLifePhase << endl;
	cout << "��ǰ�Ƿ��� TThostFtdcBoolType:" << pInstrument->IsTrading << endl;
	cout << "�ֲ����� TThostFtdcPositionTypeType:" << pInstrument->PositionType << endl;
	cout << "�ֲ��������� TThostFtdcPositionDateTypeType:" << pInstrument->PositionDateType << endl;
	cout << "��ͷ��֤���� TThostFtdcRatioType:" << pInstrument->LongMarginRatio << endl;
	cout << "��ͷ��֤���� TThostFtdcRatioType:" << pInstrument->ShortMarginRatio << endl;
	cout << "�Ƿ�ʹ�ô��߱�֤���㷨 TThostFtdcMaxMarginSideAlgorithmType:" << pInstrument->MaxMarginSideAlgorithm << endl;
	cout << "������Ʒ���� TThostFtdcInstrumentIDType:" << pInstrument->UnderlyingInstrID << endl;
	cout << "ִ�м� TThostFtdcPriceType:" << pInstrument->StrikePrice << endl;
	cout << "��Ȩ���� TThostFtdcOptionsTypeType:" << pInstrument->OptionsType << endl;
	cout << "��Լ������Ʒ���� TThostFtdcUnderlyingMultipleType:" << pInstrument->UnderlyingMultiple << endl;
	cout << "������� TThostFtdcCombinationTypeType:" << pInstrument->CombinationType << endl;
	cout << "��С���µ���λ TThostFtdcVolumeType:" << pInstrument->MinBuyVolume << endl;
	cout << "��С���µ���λ TThostFtdcVolumeType:" << pInstrument->MinSellVolume << endl;
	cout << "��Լ��ʶ�� TThostFtdcInstrumentCodeType:" << pInstrument->InstrumentCode << endl;
    }
}

///�����ѯ������Ӧ
void CTraderSpi::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "������ TThostFtdcDateType:" << pDepthMarketData->TradingDay << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pDepthMarketData->InstrumentID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pDepthMarketData->ExchangeID << endl;
	cout << "��Լ�ڽ������Ĵ��� TThostFtdcExchangeInstIDType:" << pDepthMarketData->ExchangeInstID << endl;
	cout << "���¼� TThostFtdcPriceType:" << pDepthMarketData->LastPrice << endl;
	cout << "�ϴν���� TThostFtdcPriceType:" << pDepthMarketData->PreSettlementPrice << endl;
	cout << "������ TThostFtdcPriceType:" << pDepthMarketData->PreClosePrice << endl;
	cout << "��ֲ��� TThostFtdcLargeVolumeType:" << pDepthMarketData->PreOpenInterest << endl;
	cout << "���� TThostFtdcPriceType:" << pDepthMarketData->OpenPrice << endl;
	cout << "��߼� TThostFtdcPriceType:" << pDepthMarketData->HighestPrice << endl;
	cout << "��ͼ� TThostFtdcPriceType:" << pDepthMarketData->LowestPrice << endl;
	cout << "���� TThostFtdcVolumeType:" << pDepthMarketData->Volume << endl;
	cout << "�ɽ���� TThostFtdcMoneyType:" << pDepthMarketData->Turnover << endl;
	cout << "�ֲ��� TThostFtdcLargeVolumeType:" << pDepthMarketData->OpenInterest << endl;
	cout << "������ TThostFtdcPriceType:" << pDepthMarketData->ClosePrice << endl;
	cout << "���ν���� TThostFtdcPriceType:" << pDepthMarketData->SettlementPrice << endl;
	cout << "��ͣ��� TThostFtdcPriceType:" << pDepthMarketData->UpperLimitPrice << endl;
	cout << "��ͣ��� TThostFtdcPriceType:" << pDepthMarketData->LowerLimitPrice << endl;
	cout << "����ʵ�� TThostFtdcRatioType:" << pDepthMarketData->PreDelta << endl;
	cout << "����ʵ�� TThostFtdcRatioType:" << pDepthMarketData->CurrDelta << endl;
	cout << "����޸�ʱ�� TThostFtdcTimeType:" << pDepthMarketData->UpdateTime << endl;
	cout << "����޸ĺ��� TThostFtdcMillisecType:" << pDepthMarketData->UpdateMillisec << endl;
	cout << "�����һ TThostFtdcPriceType:" << pDepthMarketData->BidPrice1 << endl;
	cout << "������һ TThostFtdcVolumeType:" << pDepthMarketData->BidVolume1 << endl;
	cout << "������һ TThostFtdcPriceType:" << pDepthMarketData->AskPrice1 << endl;
	cout << "������һ TThostFtdcVolumeType:" << pDepthMarketData->AskVolume1 << endl;
	cout << "����۶� TThostFtdcPriceType:" << pDepthMarketData->BidPrice2 << endl;
	cout << "�������� TThostFtdcVolumeType:" << pDepthMarketData->BidVolume2 << endl;
	cout << "�����۶� TThostFtdcPriceType:" << pDepthMarketData->AskPrice2 << endl;
	cout << "�������� TThostFtdcVolumeType:" << pDepthMarketData->AskVolume2 << endl;
	cout << "������� TThostFtdcPriceType:" << pDepthMarketData->BidPrice3 << endl;
	cout << "�������� TThostFtdcVolumeType:" << pDepthMarketData->BidVolume3 << endl;
	cout << "�������� TThostFtdcPriceType:" << pDepthMarketData->AskPrice3 << endl;
	cout << "�������� TThostFtdcVolumeType:" << pDepthMarketData->AskVolume3 << endl;
	cout << "������� TThostFtdcPriceType:" << pDepthMarketData->BidPrice4 << endl;
	cout << "�������� TThostFtdcVolumeType:" << pDepthMarketData->BidVolume4 << endl;
	cout << "�������� TThostFtdcPriceType:" << pDepthMarketData->AskPrice4 << endl;
	cout << "�������� TThostFtdcVolumeType:" << pDepthMarketData->AskVolume4 << endl;
	cout << "������� TThostFtdcPriceType:" << pDepthMarketData->BidPrice5 << endl;
	cout << "�������� TThostFtdcVolumeType:" << pDepthMarketData->BidVolume5 << endl;
	cout << "�������� TThostFtdcPriceType:" << pDepthMarketData->AskPrice5 << endl;
	cout << "�������� TThostFtdcVolumeType:" << pDepthMarketData->AskVolume5 << endl;
	cout << "���վ��� TThostFtdcPriceType:" << pDepthMarketData->AveragePrice << endl;
	cout << "ҵ������ TThostFtdcDateType:" << pDepthMarketData->ActionDay << endl;
    }
}

///�����ѯͶ���߽�������Ӧ
void CTraderSpi::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField* pSettlementInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "������ TThostFtdcDateType:" << pSettlementInfo->TradingDay << endl;
	cout << "������ TThostFtdcSettlementIDType:" << pSettlementInfo->SettlementID << endl;
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pSettlementInfo->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pSettlementInfo->InvestorID << endl;
	cout << "��� TThostFtdcSequenceNoType:" << pSettlementInfo->SequenceNo << endl;
	cout << "��Ϣ���� TThostFtdcContentType:" << pSettlementInfo->Content << endl;
    }
}

///�����ѯת��������Ӧ
void CTraderSpi::OnRspQryTransferBank(CThostFtdcTransferBankField* pTransferBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���д��� TThostFtdcBankIDType:" << pTransferBank->BankID << endl;
	cout << "���з����Ĵ��� TThostFtdcBankBrchIDType:" << pTransferBank->BankBrchID << endl;
	cout << "�������� TThostFtdcBankNameType:" << pTransferBank->BankName << endl;
	cout << "�Ƿ��Ծ TThostFtdcBoolType:" << pTransferBank->IsActive << endl;
    }
}

///�����ѯͶ���ֲ߳���ϸ��Ӧ
void CTraderSpi::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField* pInvestorPositionDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pInvestorPositionDetail->InstrumentID << endl;
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pInvestorPositionDetail->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pInvestorPositionDetail->InvestorID << endl;
	cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pInvestorPositionDetail->HedgeFlag << endl;
	cout << "���� TThostFtdcDirectionType:" << pInvestorPositionDetail->Direction << endl;
	cout << "�������� TThostFtdcDateType:" << pInvestorPositionDetail->OpenDate << endl;
	cout << "�ɽ���� TThostFtdcTradeIDType:" << pInvestorPositionDetail->TradeID << endl;
	cout << "���� TThostFtdcVolumeType:" << pInvestorPositionDetail->Volume << endl;
	cout << "���ּ� TThostFtdcPriceType:" << pInvestorPositionDetail->OpenPrice << endl;
	cout << "������ TThostFtdcDateType:" << pInvestorPositionDetail->TradingDay << endl;
	cout << "������ TThostFtdcSettlementIDType:" << pInvestorPositionDetail->SettlementID << endl;
	cout << "�ɽ����� TThostFtdcTradeTypeType:" << pInvestorPositionDetail->TradeType << endl;
	cout << "��Ϻ�Լ���� TThostFtdcInstrumentIDType:" << pInvestorPositionDetail->CombInstrumentID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pInvestorPositionDetail->ExchangeID << endl;
	cout << "���ն���ƽ��ӯ�� TThostFtdcMoneyType:" << pInvestorPositionDetail->CloseProfitByDate << endl;
	cout << "��ʶԳ�ƽ��ӯ�� TThostFtdcMoneyType:" << pInvestorPositionDetail->CloseProfitByTrade << endl;
	cout << "���ն��гֲ�ӯ�� TThostFtdcMoneyType:" << pInvestorPositionDetail->PositionProfitByDate << endl;
	cout << "��ʶԳ�ֲ�ӯ�� TThostFtdcMoneyType:" << pInvestorPositionDetail->PositionProfitByTrade << endl;
	cout << "Ͷ���߱�֤�� TThostFtdcMoneyType:" << pInvestorPositionDetail->Margin << endl;
	cout << "��������֤�� TThostFtdcMoneyType:" << pInvestorPositionDetail->ExchMargin << endl;
	cout << "��֤���� TThostFtdcRatioType:" << pInvestorPositionDetail->MarginRateByMoney << endl;
	cout << "��֤���ʰ����� TThostFtdcRatioType:" << pInvestorPositionDetail->MarginRateByVolume << endl;
	cout << "������ TThostFtdcPriceType:" << pInvestorPositionDetail->LastSettlementPrice << endl;
	cout << "����� TThostFtdcPriceType:" << pInvestorPositionDetail->SettlementPrice << endl;
	cout << "ƽ���� TThostFtdcVolumeType:" << pInvestorPositionDetail->CloseVolume << endl;
	cout << "ƽ�ֽ�� TThostFtdcMoneyType:" << pInvestorPositionDetail->CloseAmount << endl;
    }
}

///�����ѯ�ͻ�֪ͨ��Ӧ
void CTraderSpi::OnRspQryNotice(CThostFtdcNoticeField* pNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pNotice->BrokerID << endl;
	cout << "��Ϣ���� TThostFtdcContentType:" << pNotice->Content << endl;
	cout << "���͹�˾֪ͨ�������к� TThostFtdcSequenceLabelType:" << pNotice->SequenceLabel << endl;
    }
}

///�����ѯ������Ϣȷ����Ӧ
void CTraderSpi::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pSettlementInfoConfirm->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pSettlementInfoConfirm->InvestorID << endl;
	cout << "ȷ������ TThostFtdcDateType:" << pSettlementInfoConfirm->ConfirmDate << endl;
	cout << "ȷ��ʱ�� TThostFtdcTimeType:" << pSettlementInfoConfirm->ConfirmTime << endl;
    }
}

///�����ѯͶ���ֲ߳���ϸ��Ӧ
void CTraderSpi::OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField* pInvestorPositionCombineDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "������ TThostFtdcDateType:" << pInvestorPositionCombineDetail->TradingDay << endl;
	cout << "�������� TThostFtdcDateType:" << pInvestorPositionCombineDetail->OpenDate << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pInvestorPositionCombineDetail->ExchangeID << endl;
	cout << "������ TThostFtdcSettlementIDType:" << pInvestorPositionCombineDetail->SettlementID << endl;
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pInvestorPositionCombineDetail->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pInvestorPositionCombineDetail->InvestorID << endl;
	cout << "��ϱ�� TThostFtdcTradeIDType:" << pInvestorPositionCombineDetail->ComTradeID << endl;
	cout << "��ϱ�� TThostFtdcTradeIDType:" << pInvestorPositionCombineDetail->TradeID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pInvestorPositionCombineDetail->InstrumentID << endl;
	cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pInvestorPositionCombineDetail->HedgeFlag << endl;
	cout << "���� TThostFtdcDirectionType:" << pInvestorPositionCombineDetail->Direction << endl;
	cout << "�ֲ��� TThostFtdcVolumeType:" << pInvestorPositionCombineDetail->TotalAmt << endl;
	cout << "Ͷ���߱�֤�� TThostFtdcMoneyType:" << pInvestorPositionCombineDetail->Margin << endl;
	cout << "��������֤�� TThostFtdcMoneyType:" << pInvestorPositionCombineDetail->ExchMargin << endl;
	cout << "��֤���� TThostFtdcRatioType:" << pInvestorPositionCombineDetail->MarginRateByMoney << endl;
	cout << "��֤���ʰ����� TThostFtdcRatioType:" << pInvestorPositionCombineDetail->MarginRateByVolume << endl;
	cout << "���ȱ�� TThostFtdcLegIDType:" << pInvestorPositionCombineDetail->LegID << endl;
	cout << "���ȳ��� TThostFtdcLegMultipleType:" << pInvestorPositionCombineDetail->LegMultiple << endl;
	cout << "��ϳֲֺ�Լ���� TThostFtdcInstrumentIDType:" << pInvestorPositionCombineDetail->CombInstrumentID << endl;
	cout << "�ɽ���� TThostFtdcTradeGroupIDType:" << pInvestorPositionCombineDetail->TradeGroupID << endl;
    }
}

///��ѯ��֤����ϵͳ���͹�˾�ʽ��˻���Կ��Ӧ
void CTraderSpi::OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField* pCFMMCTradingAccountKey, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pCFMMCTradingAccountKey->BrokerID << endl;
	cout << "���͹�˾ͳһ���� TThostFtdcParticipantIDType:" << pCFMMCTradingAccountKey->ParticipantID << endl;
	cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pCFMMCTradingAccountKey->AccountID << endl;
	cout << "��Կ��� TThostFtdcSequenceNoType:" << pCFMMCTradingAccountKey->KeyID << endl;
	cout << "��̬��Կ TThostFtdcCFMMCKeyType:" << pCFMMCTradingAccountKey->CurrentKey << endl;
    }
}

///�����ѯ�ֵ��۵���Ϣ��Ӧ
void CTraderSpi::OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField* pEWarrantOffset, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "�������� TThostFtdcTradeDateType:" << pEWarrantOffset->TradingDay << endl;
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pEWarrantOffset->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pEWarrantOffset->InvestorID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pEWarrantOffset->ExchangeID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pEWarrantOffset->InstrumentID << endl;
	cout << "�������� TThostFtdcDirectionType:" << pEWarrantOffset->Direction << endl;
	cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pEWarrantOffset->HedgeFlag << endl;
	cout << "���� TThostFtdcVolumeType:" << pEWarrantOffset->Volume << endl;
    }
}

///�����ѯͶ����Ʒ��/��Ʒ�ֱ�֤����Ӧ
void CTraderSpi::OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField* pInvestorProductGroupMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "Ʒ�ֿ�Ʒ�ֱ�ʾ TThostFtdcInstrumentIDType:" << pInvestorProductGroupMargin->ProductGroupID << endl;
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pInvestorProductGroupMargin->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pInvestorProductGroupMargin->InvestorID << endl;
	cout << "������ TThostFtdcDateType:" << pInvestorProductGroupMargin->TradingDay << endl;
	cout << "������ TThostFtdcSettlementIDType:" << pInvestorProductGroupMargin->SettlementID << endl;
	cout << "����ı�֤�� TThostFtdcMoneyType:" << pInvestorProductGroupMargin->FrozenMargin << endl;
	cout << "��ͷ����ı�֤�� TThostFtdcMoneyType:" << pInvestorProductGroupMargin->LongFrozenMargin << endl;
	cout << "��ͷ����ı�֤�� TThostFtdcMoneyType:" << pInvestorProductGroupMargin->ShortFrozenMargin << endl;
	cout << "ռ�õı�֤�� TThostFtdcMoneyType:" << pInvestorProductGroupMargin->UseMargin << endl;
	cout << "��ͷ��֤�� TThostFtdcMoneyType:" << pInvestorProductGroupMargin->LongUseMargin << endl;
	cout << "��ͷ��֤�� TThostFtdcMoneyType:" << pInvestorProductGroupMargin->ShortUseMargin << endl;
	cout << "��������֤�� TThostFtdcMoneyType:" << pInvestorProductGroupMargin->ExchMargin << endl;
	cout << "��������ͷ��֤�� TThostFtdcMoneyType:" << pInvestorProductGroupMargin->LongExchMargin << endl;
	cout << "��������ͷ��֤�� TThostFtdcMoneyType:" << pInvestorProductGroupMargin->ShortExchMargin << endl;
	cout << "ƽ��ӯ�� TThostFtdcMoneyType:" << pInvestorProductGroupMargin->CloseProfit << endl;
	cout << "����������� TThostFtdcMoneyType:" << pInvestorProductGroupMargin->FrozenCommission << endl;
	cout << "������ TThostFtdcMoneyType:" << pInvestorProductGroupMargin->Commission << endl;
	cout << "������ʽ� TThostFtdcMoneyType:" << pInvestorProductGroupMargin->FrozenCash << endl;
	cout << "�ʽ��� TThostFtdcMoneyType:" << pInvestorProductGroupMargin->CashIn << endl;
	cout << "�ֲ�ӯ�� TThostFtdcMoneyType:" << pInvestorProductGroupMargin->PositionProfit << endl;
	cout << "�۵��ܽ�� TThostFtdcMoneyType:" << pInvestorProductGroupMargin->OffsetAmount << endl;
	cout << "��ͷ�۵��ܽ�� TThostFtdcMoneyType:" << pInvestorProductGroupMargin->LongOffsetAmount << endl;
	cout << "��ͷ�۵��ܽ�� TThostFtdcMoneyType:" << pInvestorProductGroupMargin->ShortOffsetAmount << endl;
	cout << "�������۵��ܽ�� TThostFtdcMoneyType:" << pInvestorProductGroupMargin->ExchOffsetAmount << endl;
	cout << "��������ͷ�۵��ܽ�� TThostFtdcMoneyType:" << pInvestorProductGroupMargin->LongExchOffsetAmount << endl;
	cout << "��������ͷ�۵��ܽ�� TThostFtdcMoneyType:" << pInvestorProductGroupMargin->ShortExchOffsetAmount << endl;
	cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pInvestorProductGroupMargin->HedgeFlag << endl;
    }
}

///�����ѯ��������֤������Ӧ
void CTraderSpi::OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField* pExchangeMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pExchangeMarginRate->BrokerID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pExchangeMarginRate->InstrumentID << endl;
	cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pExchangeMarginRate->HedgeFlag << endl;
	cout << "��ͷ��֤���� TThostFtdcRatioType:" << pExchangeMarginRate->LongMarginRatioByMoney << endl;
	cout << "��ͷ��֤��� TThostFtdcMoneyType:" << pExchangeMarginRate->LongMarginRatioByVolume << endl;
	cout << "��ͷ��֤���� TThostFtdcRatioType:" << pExchangeMarginRate->ShortMarginRatioByMoney << endl;
	cout << "��ͷ��֤��� TThostFtdcMoneyType:" << pExchangeMarginRate->ShortMarginRatioByVolume << endl;
    }
}

///�����ѯ������������֤������Ӧ
void CTraderSpi::OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField* pExchangeMarginRateAdjust, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pExchangeMarginRateAdjust->BrokerID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pExchangeMarginRateAdjust->InstrumentID << endl;
	cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pExchangeMarginRateAdjust->HedgeFlag << endl;
	cout << "���潻����Ͷ���߶�ͷ��֤���� TThostFtdcRatioType:" << pExchangeMarginRateAdjust->LongMarginRatioByMoney << endl;
	cout << "���潻����Ͷ���߶�ͷ��֤��� TThostFtdcMoneyType:" << pExchangeMarginRateAdjust->LongMarginRatioByVolume << endl;
	cout << "���潻����Ͷ���߿�ͷ��֤���� TThostFtdcRatioType:" << pExchangeMarginRateAdjust->ShortMarginRatioByMoney << endl;
	cout << "���潻����Ͷ���߿�ͷ��֤��� TThostFtdcMoneyType:" << pExchangeMarginRateAdjust->ShortMarginRatioByVolume << endl;
	cout << "��������ͷ��֤���� TThostFtdcRatioType:" << pExchangeMarginRateAdjust->ExchLongMarginRatioByMoney << endl;
	cout << "��������ͷ��֤��� TThostFtdcMoneyType:" << pExchangeMarginRateAdjust->ExchLongMarginRatioByVolume << endl;
	cout << "��������ͷ��֤���� TThostFtdcRatioType:" << pExchangeMarginRateAdjust->ExchShortMarginRatioByMoney << endl;
	cout << "��������ͷ��֤��� TThostFtdcMoneyType:" << pExchangeMarginRateAdjust->ExchShortMarginRatioByVolume << endl;
	cout << "�����潻����Ͷ���߶�ͷ��֤���� TThostFtdcRatioType:" << pExchangeMarginRateAdjust->NoLongMarginRatioByMoney << endl;
	cout << "�����潻����Ͷ���߶�ͷ��֤��� TThostFtdcMoneyType:" << pExchangeMarginRateAdjust->NoLongMarginRatioByVolume << endl;
	cout << "�����潻����Ͷ���߿�ͷ��֤���� TThostFtdcRatioType:" << pExchangeMarginRateAdjust->NoShortMarginRatioByMoney << endl;
	cout << "�����潻����Ͷ���߿�ͷ��֤��� TThostFtdcMoneyType:" << pExchangeMarginRateAdjust->NoShortMarginRatioByVolume << endl;
    }
}

///�����ѯ������Ӧ
void CTraderSpi::OnRspQryExchangeRate(CThostFtdcExchangeRateField* pExchangeRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pExchangeRate->BrokerID << endl;
	cout << "Դ���� TThostFtdcCurrencyIDType:" << pExchangeRate->FromCurrencyID << endl;
	cout << "Դ���ֵ�λ���� TThostFtdcCurrencyUnitType:" << pExchangeRate->FromCurrencyUnit << endl;
	cout << "Ŀ����� TThostFtdcCurrencyIDType:" << pExchangeRate->ToCurrencyID << endl;
	cout << "���� TThostFtdcExchangeRateType:" << pExchangeRate->ExchangeRate << endl;
    }
}

///�����ѯ�����������Ա����Ȩ����Ӧ
void CTraderSpi::OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField* pSecAgentACIDMap, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pSecAgentACIDMap->BrokerID << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pSecAgentACIDMap->UserID << endl;
	cout << "�ʽ��˻� TThostFtdcAccountIDType:" << pSecAgentACIDMap->AccountID << endl;
	cout << "���� TThostFtdcCurrencyIDType:" << pSecAgentACIDMap->CurrencyID << endl;
	cout << "�����н�����ʽ��ʺ� TThostFtdcAccountIDType:" << pSecAgentACIDMap->BrokerSecAgentID << endl;
    }
}

///�����ѯ��Ʒ���ۻ���
void CTraderSpi::OnRspQryProductExchRate(CThostFtdcProductExchRateField* pProductExchRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "��Ʒ���� TThostFtdcInstrumentIDType:" << pProductExchRate->ProductID << endl;
	cout << "���۱������� TThostFtdcCurrencyIDType:" << pProductExchRate->QuoteCurrencyID << endl;
	cout << "���� TThostFtdcExchangeRateType:" << pProductExchRate->ExchangeRate << endl;
    }
}

///�����ѯ��Ʒ��
void CTraderSpi::OnRspQryProductGroup(CThostFtdcProductGroupField* pProductGroup, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "��Ʒ���� TThostFtdcInstrumentIDType:" << pProductGroup->ProductID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pProductGroup->ExchangeID << endl;
	cout << "��Ʒ����� TThostFtdcInstrumentIDType:" << pProductGroup->ProductGroupID << endl;
    }
}

///�����ѯ��Ȩ���׳ɱ���Ӧ
void CTraderSpi::OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField* pOptionInstrTradeCost, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pOptionInstrTradeCost->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pOptionInstrTradeCost->InvestorID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pOptionInstrTradeCost->InstrumentID << endl;
	cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pOptionInstrTradeCost->HedgeFlag << endl;
	cout << "��Ȩ��Լ��֤�𲻱䲿�� TThostFtdcMoneyType:" << pOptionInstrTradeCost->FixedMargin << endl;
	cout << "��Ȩ��Լ��С��֤�� TThostFtdcMoneyType:" << pOptionInstrTradeCost->MiniMargin << endl;
	cout << "��Ȩ��ԼȨ���� TThostFtdcMoneyType:" << pOptionInstrTradeCost->Royalty << endl;
	cout << "��������Ȩ��Լ��֤�𲻱䲿�� TThostFtdcMoneyType:" << pOptionInstrTradeCost->ExchFixedMargin << endl;
	cout << "��������Ȩ��Լ��С��֤�� TThostFtdcMoneyType:" << pOptionInstrTradeCost->ExchMiniMargin << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pOptionInstrTradeCost->ExchangeID << endl;
    }
}

///�����ѯ��Ȩ��Լ��������Ӧ
void CTraderSpi::OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField* pOptionInstrCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pOptionInstrCommRate->InstrumentID << endl;
	cout << "Ͷ���߷�Χ TThostFtdcInvestorRangeType:" << pOptionInstrCommRate->InvestorRange << endl;
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pOptionInstrCommRate->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pOptionInstrCommRate->InvestorID << endl;
	cout << "������������ TThostFtdcRatioType:" << pOptionInstrCommRate->OpenRatioByMoney << endl;
	cout << "���������� TThostFtdcRatioType:" << pOptionInstrCommRate->OpenRatioByVolume << endl;
	cout << "ƽ���������� TThostFtdcRatioType:" << pOptionInstrCommRate->CloseRatioByMoney << endl;
	cout << "ƽ�������� TThostFtdcRatioType:" << pOptionInstrCommRate->CloseRatioByVolume << endl;
	cout << "ƽ���������� TThostFtdcRatioType:" << pOptionInstrCommRate->CloseTodayRatioByMoney << endl;
	cout << "ƽ�������� TThostFtdcRatioType:" << pOptionInstrCommRate->CloseTodayRatioByVolume << endl;
	cout << "ִ���������� TThostFtdcRatioType:" << pOptionInstrCommRate->StrikeRatioByMoney << endl;
	cout << "ִ�������� TThostFtdcRatioType:" << pOptionInstrCommRate->StrikeRatioByVolume << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pOptionInstrCommRate->ExchangeID << endl;
    }
}

///�����ѯִ��������Ӧ
void CTraderSpi::OnRspQryExecOrder(CThostFtdcExecOrderField* pExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pExecOrder->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pExecOrder->InvestorID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pExecOrder->InstrumentID << endl;
	cout << "ִ���������� TThostFtdcOrderRefType:" << pExecOrder->ExecOrderRef << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pExecOrder->UserID << endl;
	cout << "���� TThostFtdcVolumeType:" << pExecOrder->Volume << endl;
	cout << "������ TThostFtdcRequestIDType:" << pExecOrder->RequestID << endl;
	cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << pExecOrder->BusinessUnit << endl;
	cout << "��ƽ��־ TThostFtdcOffsetFlagType:" << pExecOrder->OffsetFlag << endl;
	cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pExecOrder->HedgeFlag << endl;
	cout << "ִ������ TThostFtdcActionTypeType:" << pExecOrder->ActionType << endl;
	cout << "����ͷ������ĳֲַ��� TThostFtdcPosiDirectionType:" << pExecOrder->PosiDirection << endl;
	cout << "��Ȩ��Ȩ���Ƿ����ڻ�ͷ��ı�� TThostFtdcExecOrderPositionFlagType:" << pExecOrder->ReservePositionFlag << endl;
	cout << "��Ȩ��Ȩ�����ɵ�ͷ���Ƿ��Զ�ƽ�� TThostFtdcExecOrderCloseFlagType:" << pExecOrder->CloseFlag << endl;
	cout << "����ִ�������� TThostFtdcOrderLocalIDType:" << pExecOrder->ExecOrderLocalID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pExecOrder->ExchangeID << endl;
	cout << "��Ա���� TThostFtdcParticipantIDType:" << pExecOrder->ParticipantID << endl;
	cout << "�ͻ����� TThostFtdcClientIDType:" << pExecOrder->ClientID << endl;
	cout << "��Լ�ڽ������Ĵ��� TThostFtdcExchangeInstIDType:" << pExecOrder->ExchangeInstID << endl;
	cout << "����������Ա���� TThostFtdcTraderIDType:" << pExecOrder->TraderID << endl;
	cout << "��װ��� TThostFtdcInstallIDType:" << pExecOrder->InstallID << endl;
	cout << "ִ�������ύ״̬ TThostFtdcOrderSubmitStatusType:" << pExecOrder->OrderSubmitStatus << endl;
	cout << "������ʾ��� TThostFtdcSequenceNoType:" << pExecOrder->NotifySequence << endl;
	cout << "������ TThostFtdcDateType:" << pExecOrder->TradingDay << endl;
	cout << "������ TThostFtdcSettlementIDType:" << pExecOrder->SettlementID << endl;
	cout << "ִ�������� TThostFtdcExecOrderSysIDType:" << pExecOrder->ExecOrderSysID << endl;
	cout << "�������� TThostFtdcDateType:" << pExecOrder->InsertDate << endl;
	cout << "����ʱ�� TThostFtdcTimeType:" << pExecOrder->InsertTime << endl;
	cout << "����ʱ�� TThostFtdcTimeType:" << pExecOrder->CancelTime << endl;
	cout << "ִ�н�� TThostFtdcExecResultType:" << pExecOrder->ExecResult << endl;
	cout << "�����Ա��� TThostFtdcParticipantIDType:" << pExecOrder->ClearingPartID << endl;
	cout << "��� TThostFtdcSequenceNoType:" << pExecOrder->SequenceNo << endl;
	cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << pExecOrder->FrontID << endl;
	cout << "�Ự��� TThostFtdcSessionIDType:" << pExecOrder->SessionID << endl;
	cout << "�û��˲�Ʒ��Ϣ TThostFtdcProductInfoType:" << pExecOrder->UserProductInfo << endl;
	cout << "״̬��Ϣ TThostFtdcErrorMsgType:" << pExecOrder->StatusMsg << endl;
	cout << "�����û����� TThostFtdcUserIDType:" << pExecOrder->ActiveUserID << endl;
	cout << "���͹�˾������� TThostFtdcSequenceNoType:" << pExecOrder->BrokerExecOrderSeq << endl;
	cout << "Ӫҵ����� TThostFtdcBranchIDType:" << pExecOrder->BranchID << endl;
    }
}

///�����ѯѯ����Ӧ
void CTraderSpi::OnRspQryForQuote(CThostFtdcForQuoteField* pForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pForQuote->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pForQuote->InvestorID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pForQuote->InstrumentID << endl;
	cout << "ѯ������ TThostFtdcOrderRefType:" << pForQuote->ForQuoteRef << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pForQuote->UserID << endl;
	cout << "����ѯ�۱�� TThostFtdcOrderLocalIDType:" << pForQuote->ForQuoteLocalID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pForQuote->ExchangeID << endl;
	cout << "��Ա���� TThostFtdcParticipantIDType:" << pForQuote->ParticipantID << endl;
	cout << "�ͻ����� TThostFtdcClientIDType:" << pForQuote->ClientID << endl;
	cout << "��Լ�ڽ������Ĵ��� TThostFtdcExchangeInstIDType:" << pForQuote->ExchangeInstID << endl;
	cout << "����������Ա���� TThostFtdcTraderIDType:" << pForQuote->TraderID << endl;
	cout << "��װ��� TThostFtdcInstallIDType:" << pForQuote->InstallID << endl;
	cout << "�������� TThostFtdcDateType:" << pForQuote->InsertDate << endl;
	cout << "����ʱ�� TThostFtdcTimeType:" << pForQuote->InsertTime << endl;
	cout << "ѯ��״̬ TThostFtdcForQuoteStatusType:" << pForQuote->ForQuoteStatus << endl;
	cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << pForQuote->FrontID << endl;
	cout << "�Ự��� TThostFtdcSessionIDType:" << pForQuote->SessionID << endl;
	cout << "״̬��Ϣ TThostFtdcErrorMsgType:" << pForQuote->StatusMsg << endl;
	cout << "�����û����� TThostFtdcUserIDType:" << pForQuote->ActiveUserID << endl;
	cout << "���͹�˾ѯ�۱�� TThostFtdcSequenceNoType:" << pForQuote->BrokerForQutoSeq << endl;
    }
}

///�����ѯ������Ӧ
void CTraderSpi::OnRspQryQuote(CThostFtdcQuoteField* pQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pQuote->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pQuote->InvestorID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pQuote->InstrumentID << endl;
	cout << "�������� TThostFtdcOrderRefType:" << pQuote->QuoteRef << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pQuote->UserID << endl;
	cout << "���۸� TThostFtdcPriceType:" << pQuote->AskPrice << endl;
	cout << "��۸� TThostFtdcPriceType:" << pQuote->BidPrice << endl;
	cout << "������ TThostFtdcVolumeType:" << pQuote->AskVolume << endl;
	cout << "������ TThostFtdcVolumeType:" << pQuote->BidVolume << endl;
	cout << "������ TThostFtdcRequestIDType:" << pQuote->RequestID << endl;
	cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << pQuote->BusinessUnit << endl;
	cout << "����ƽ��־ TThostFtdcOffsetFlagType:" << pQuote->AskOffsetFlag << endl;
	cout << "��ƽ��־ TThostFtdcOffsetFlagType:" << pQuote->BidOffsetFlag << endl;
	cout << "��Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pQuote->AskHedgeFlag << endl;
	cout << "��Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pQuote->BidHedgeFlag << endl;
	cout << "���ر��۱�� TThostFtdcOrderLocalIDType:" << pQuote->QuoteLocalID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pQuote->ExchangeID << endl;
	cout << "��Ա���� TThostFtdcParticipantIDType:" << pQuote->ParticipantID << endl;
	cout << "�ͻ����� TThostFtdcClientIDType:" << pQuote->ClientID << endl;
	cout << "��Լ�ڽ������Ĵ��� TThostFtdcExchangeInstIDType:" << pQuote->ExchangeInstID << endl;
	cout << "����������Ա���� TThostFtdcTraderIDType:" << pQuote->TraderID << endl;
	cout << "��װ��� TThostFtdcInstallIDType:" << pQuote->InstallID << endl;
	cout << "������ʾ��� TThostFtdcSequenceNoType:" << pQuote->NotifySequence << endl;
	cout << "�����ύ״̬ TThostFtdcOrderSubmitStatusType:" << pQuote->OrderSubmitStatus << endl;
	cout << "������ TThostFtdcDateType:" << pQuote->TradingDay << endl;
	cout << "������ TThostFtdcSettlementIDType:" << pQuote->SettlementID << endl;
	cout << "���۱�� TThostFtdcOrderSysIDType:" << pQuote->QuoteSysID << endl;
	cout << "�������� TThostFtdcDateType:" << pQuote->InsertDate << endl;
	cout << "����ʱ�� TThostFtdcTimeType:" << pQuote->InsertTime << endl;
	cout << "����ʱ�� TThostFtdcTimeType:" << pQuote->CancelTime << endl;
	cout << "����״̬ TThostFtdcOrderStatusType:" << pQuote->QuoteStatus << endl;
	cout << "�����Ա��� TThostFtdcParticipantIDType:" << pQuote->ClearingPartID << endl;
	cout << "��� TThostFtdcSequenceNoType:" << pQuote->SequenceNo << endl;
	cout << "����������� TThostFtdcOrderSysIDType:" << pQuote->AskOrderSysID << endl;
	cout << "�򷽱������ TThostFtdcOrderSysIDType:" << pQuote->BidOrderSysID << endl;
	cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << pQuote->FrontID << endl;
	cout << "�Ự��� TThostFtdcSessionIDType:" << pQuote->SessionID << endl;
	cout << "�û��˲�Ʒ��Ϣ TThostFtdcProductInfoType:" << pQuote->UserProductInfo << endl;
	cout << "״̬��Ϣ TThostFtdcErrorMsgType:" << pQuote->StatusMsg << endl;
	cout << "�����û����� TThostFtdcUserIDType:" << pQuote->ActiveUserID << endl;
	cout << "���͹�˾���۱�� TThostFtdcSequenceNoType:" << pQuote->BrokerQuoteSeq << endl;
	cout << "�������������� TThostFtdcOrderRefType:" << pQuote->AskOrderRef << endl;
	cout << "�����򱨵����� TThostFtdcOrderRefType:" << pQuote->BidOrderRef << endl;
	cout << "Ӧ�۱�� TThostFtdcOrderSysIDType:" << pQuote->ForQuoteSysID << endl;
	cout << "Ӫҵ����� TThostFtdcBranchIDType:" << pQuote->BranchID << endl;
    }
}

///�����ѯ����Ӧ��
void CTraderSpi::OnRspQryLock(CThostFtdcLockField* pLock, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pLock->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pLock->InvestorID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pLock->InstrumentID << endl;
	cout << "�������� TThostFtdcOrderRefType:" << pLock->LockRef << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pLock->UserID << endl;
	cout << "���� TThostFtdcVolumeType:" << pLock->Volume << endl;
	cout << "������ TThostFtdcRequestIDType:" << pLock->RequestID << endl;
	cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << pLock->BusinessUnit << endl;
	cout << "�������� TThostFtdcLockTypeType:" << pLock->LockType << endl;
	cout << "����������� TThostFtdcOrderLocalIDType:" << pLock->LockLocalID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pLock->ExchangeID << endl;
	cout << "��Ա���� TThostFtdcParticipantIDType:" << pLock->ParticipantID << endl;
	cout << "�ͻ����� TThostFtdcClientIDType:" << pLock->ClientID << endl;
	cout << "��Լ�ڽ������Ĵ��� TThostFtdcExchangeInstIDType:" << pLock->ExchangeInstID << endl;
	cout << "����������Ա���� TThostFtdcTraderIDType:" << pLock->TraderID << endl;
	cout << "��װ��� TThostFtdcInstallIDType:" << pLock->InstallID << endl;
	cout << "ִ�������ύ״̬ TThostFtdcOrderSubmitStatusType:" << pLock->OrderSubmitStatus << endl;
	cout << "������ʾ��� TThostFtdcSequenceNoType:" << pLock->NotifySequence << endl;
	cout << "������ TThostFtdcDateType:" << pLock->TradingDay << endl;
	cout << "������ TThostFtdcSettlementIDType:" << pLock->SettlementID << endl;
	cout << "������� TThostFtdcOrderSysIDType:" << pLock->LockSysID << endl;
	cout << "�������� TThostFtdcDateType:" << pLock->InsertDate << endl;
	cout << "����ʱ�� TThostFtdcTimeType:" << pLock->InsertTime << endl;
	cout << "����ʱ�� TThostFtdcTimeType:" << pLock->CancelTime << endl;
	cout << "����״̬ TThostFtdcOrderActionStatusType:" << pLock->LockStatus << endl;
	cout << "�����Ա��� TThostFtdcParticipantIDType:" << pLock->ClearingPartID << endl;
	cout << "��� TThostFtdcSequenceNoType:" << pLock->SequenceNo << endl;
	cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << pLock->FrontID << endl;
	cout << "�Ự��� TThostFtdcSessionIDType:" << pLock->SessionID << endl;
	cout << "�û��˲�Ʒ��Ϣ TThostFtdcProductInfoType:" << pLock->UserProductInfo << endl;
	cout << "״̬��Ϣ TThostFtdcErrorMsgType:" << pLock->StatusMsg << endl;
	cout << "�����û����� TThostFtdcUserIDType:" << pLock->ActiveUserID << endl;
	cout << "���͹�˾������� TThostFtdcSequenceNoType:" << pLock->BrokerLockSeq << endl;
	cout << "Ӫҵ����� TThostFtdcBranchIDType:" << pLock->BranchID << endl;
    }
}

///�����ѯ����֤ȯ��λӦ��
void CTraderSpi::OnRspQryLockPosition(CThostFtdcLockPositionField* pLockPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pLockPosition->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pLockPosition->InvestorID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pLockPosition->InstrumentID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pLockPosition->ExchangeID << endl;
	cout << "���� TThostFtdcVolumeType:" << pLockPosition->Volume << endl;
	cout << "�������� TThostFtdcVolumeType:" << pLockPosition->FrozenVolume << endl;
    }
}

///�����ѯͶ���߷ּ�
void CTraderSpi::OnRspQryInvestorLevel(CThostFtdcInvestorLevelField* pInvestorLevel, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pInvestorLevel->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pInvestorLevel->InvestorID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pInvestorLevel->ExchangeID << endl;
	cout << "Ͷ���߷ּ����� TThostFtdcLevelTypeType:" << pInvestorLevel->LevelType << endl;
    }
}

///�����ѯE+1����Ȩ������Ӧ
void CTraderSpi::OnRspQryExecFreeze(CThostFtdcExecFreezeField* pExecFreeze, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "��ĺ�Լ���� TThostFtdcInstrumentIDType:" << pExecFreeze->InstrumentID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pExecFreeze->ExchangeID << endl;
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pExecFreeze->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pExecFreeze->InvestorID << endl;
	cout << "�ֲֶ�շ��� TThostFtdcPosiDirectionType:" << pExecFreeze->PosiDirection << endl;
	cout << "��Ȩ���� TThostFtdcOptionsTypeType:" << pExecFreeze->OptionsType << endl;
	cout << "�����������λ�� TThostFtdcVolumeType:" << pExecFreeze->Volume << endl;
	cout << "������ TThostFtdcMoneyType:" << pExecFreeze->FrozenAmount << endl;
    }
}

///�����ѯ��Ϻ�Լ��ȫϵ����Ӧ
void CTraderSpi::OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField* pCombInstrumentGuard, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pCombInstrumentGuard->BrokerID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pCombInstrumentGuard->InstrumentID << endl;
	cout << "δ֪ TThostFtdcRatioType:" << pCombInstrumentGuard->GuarantRatio << endl;
    }
}

///�����ѯ���������Ӧ
void CTraderSpi::OnRspQryCombAction(CThostFtdcCombActionField* pCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pCombAction->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pCombAction->InvestorID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pCombAction->InstrumentID << endl;
	cout << "������� TThostFtdcOrderRefType:" << pCombAction->CombActionRef << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pCombAction->UserID << endl;
	cout << "�������� TThostFtdcDirectionType:" << pCombAction->Direction << endl;
	cout << "���� TThostFtdcVolumeType:" << pCombAction->Volume << endl;
	cout << "���ָ��� TThostFtdcCombDirectionType:" << pCombAction->CombDirection << endl;
	cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pCombAction->HedgeFlag << endl;
	cout << "����������ϱ�� TThostFtdcOrderLocalIDType:" << pCombAction->ActionLocalID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pCombAction->ExchangeID << endl;
	cout << "��Ա���� TThostFtdcParticipantIDType:" << pCombAction->ParticipantID << endl;
	cout << "�ͻ����� TThostFtdcClientIDType:" << pCombAction->ClientID << endl;
	cout << "��Լ�ڽ������Ĵ��� TThostFtdcExchangeInstIDType:" << pCombAction->ExchangeInstID << endl;
	cout << "����������Ա���� TThostFtdcTraderIDType:" << pCombAction->TraderID << endl;
	cout << "��װ��� TThostFtdcInstallIDType:" << pCombAction->InstallID << endl;
	cout << "���״̬ TThostFtdcOrderActionStatusType:" << pCombAction->ActionStatus << endl;
	cout << "������ʾ��� TThostFtdcSequenceNoType:" << pCombAction->NotifySequence << endl;
	cout << "������ TThostFtdcDateType:" << pCombAction->TradingDay << endl;
	cout << "������ TThostFtdcSettlementIDType:" << pCombAction->SettlementID << endl;
	cout << "��� TThostFtdcSequenceNoType:" << pCombAction->SequenceNo << endl;
	cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << pCombAction->FrontID << endl;
	cout << "�Ự��� TThostFtdcSessionIDType:" << pCombAction->SessionID << endl;
	cout << "�û��˲�Ʒ��Ϣ TThostFtdcProductInfoType:" << pCombAction->UserProductInfo << endl;
	cout << "״̬��Ϣ TThostFtdcErrorMsgType:" << pCombAction->StatusMsg << endl;
    }
}

///�����ѯת����ˮ��Ӧ
void CTraderSpi::OnRspQryTransferSerial(CThostFtdcTransferSerialField* pTransferSerial, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "ƽ̨��ˮ�� TThostFtdcPlateSerialType:" << pTransferSerial->PlateSerial << endl;
	cout << "���׷������� TThostFtdcTradeDateType:" << pTransferSerial->TradeDate << endl;
	cout << "�������� TThostFtdcDateType:" << pTransferSerial->TradingDay << endl;
	cout << "����ʱ�� TThostFtdcTradeTimeType:" << pTransferSerial->TradeTime << endl;
	cout << "���״��� TThostFtdcTradeCodeType:" << pTransferSerial->TradeCode << endl;
	cout << "�Ự��� TThostFtdcSessionIDType:" << pTransferSerial->SessionID << endl;
	cout << "���б��� TThostFtdcBankIDType:" << pTransferSerial->BankID << endl;
	cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << pTransferSerial->BankBranchID << endl;
	cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << pTransferSerial->BankAccType << endl;
	cout << "�����ʺ� TThostFtdcBankAccountType:" << pTransferSerial->BankAccount << endl;
	cout << "������ˮ�� TThostFtdcBankSerialType:" << pTransferSerial->BankSerial << endl;
	cout << "�ڻ���˾���� TThostFtdcBrokerIDType:" << pTransferSerial->BrokerID << endl;
	cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << pTransferSerial->BrokerBranchID << endl;
	cout << "�ڻ���˾�ʺ����� TThostFtdcFutureAccTypeType:" << pTransferSerial->FutureAccType << endl;
	cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pTransferSerial->AccountID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pTransferSerial->InvestorID << endl;
	cout << "�ڻ���˾��ˮ�� TThostFtdcFutureSerialType:" << pTransferSerial->FutureSerial << endl;
	cout << "֤������ TThostFtdcIdCardTypeType:" << pTransferSerial->IdCardType << endl;
	cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pTransferSerial->IdentifiedCardNo << endl;
	cout << "���ִ��� TThostFtdcCurrencyIDType:" << pTransferSerial->CurrencyID << endl;
	cout << "���׽�� TThostFtdcTradeAmountType:" << pTransferSerial->TradeAmount << endl;
	cout << "Ӧ�տͻ����� TThostFtdcCustFeeType:" << pTransferSerial->CustFee << endl;
	cout << "Ӧ���ڻ���˾���� TThostFtdcFutureFeeType:" << pTransferSerial->BrokerFee << endl;
	cout << "��Ч��־ TThostFtdcAvailabilityFlagType:" << pTransferSerial->AvailabilityFlag << endl;
	cout << "����Ա TThostFtdcOperatorCodeType:" << pTransferSerial->OperatorCode << endl;
	cout << "�������ʺ� TThostFtdcBankAccountType:" << pTransferSerial->BankNewAccount << endl;
	cout << "������� TThostFtdcErrorIDType:" << pTransferSerial->ErrorID << endl;
	cout << "������Ϣ TThostFtdcErrorMsgType:" << pTransferSerial->ErrorMsg << endl;
    }
}

///�����ѯ����ǩԼ��ϵ��Ӧ
void CTraderSpi::OnRspQryAccountregister(CThostFtdcAccountregisterField* pAccountregister, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "�������� TThostFtdcTradeDateType:" << pAccountregister->TradeDay << endl;
	cout << "���б��� TThostFtdcBankIDType:" << pAccountregister->BankID << endl;
	cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << pAccountregister->BankBranchID << endl;
	cout << "�����ʺ� TThostFtdcBankAccountType:" << pAccountregister->BankAccount << endl;
	cout << "�ڻ���˾���� TThostFtdcBrokerIDType:" << pAccountregister->BrokerID << endl;
	cout << "�ڻ���˾��֧�������� TThostFtdcFutureBranchIDType:" << pAccountregister->BrokerBranchID << endl;
	cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pAccountregister->AccountID << endl;
	cout << "֤������ TThostFtdcIdCardTypeType:" << pAccountregister->IdCardType << endl;
	cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pAccountregister->IdentifiedCardNo << endl;
	cout << "�ͻ����� TThostFtdcIndividualNameType:" << pAccountregister->CustomerName << endl;
	cout << "���ִ��� TThostFtdcCurrencyIDType:" << pAccountregister->CurrencyID << endl;
	cout << "��������� TThostFtdcOpenOrDestroyType:" << pAccountregister->OpenOrDestroy << endl;
	cout << "ǩԼ���� TThostFtdcTradeDateType:" << pAccountregister->RegDate << endl;
	cout << "��Լ���� TThostFtdcTradeDateType:" << pAccountregister->OutDate << endl;
	// cout << "����ID:" << pAccountregister->TThostFtdcTIDType << endlTID;
	cout << "�ͻ����� TThostFtdcCustTypeType:" << pAccountregister->CustType << endl;
	cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << pAccountregister->BankAccType << endl;
    }
}

///����Ӧ��
void CTraderSpi::OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg << endl;
}

///����֪ͨ
void CTraderSpi::OnRtnOrder(CThostFtdcOrderField* pOrder)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pOrder->BrokerID << endl;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pOrder->InvestorID << endl;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << pOrder->InstrumentID << endl;
    cout << "�������� TThostFtdcOrderRefType:" << pOrder->OrderRef << endl;
    cout << "�û����� TThostFtdcUserIDType:" << pOrder->UserID << endl;
    cout << "�����۸����� TThostFtdcOrderPriceTypeType:" << pOrder->OrderPriceType << endl;
    cout << "�������� TThostFtdcDirectionType:" << pOrder->Direction << endl;
    cout << "��Ͽ�ƽ��־ TThostFtdcCombOffsetFlagType:" << pOrder->CombOffsetFlag << endl;
    cout << "���Ͷ���ױ���־ TThostFtdcCombHedgeFlagType:" << pOrder->CombHedgeFlag << endl;
    cout << "�۸� TThostFtdcPriceType:" << pOrder->LimitPrice << endl;
    cout << "���� TThostFtdcVolumeType:" << pOrder->VolumeTotalOriginal << endl;
    cout << "��Ч������ TThostFtdcTimeConditionType:" << pOrder->TimeCondition << endl;
    // cout << "GTD����:" << pOrder->TThostFtdcDateType << endlGTDDate;
    cout << "�ɽ������� TThostFtdcVolumeConditionType:" << pOrder->VolumeCondition << endl;
    cout << "��С�ɽ��� TThostFtdcVolumeType:" << pOrder->MinVolume << endl;
    cout << "�������� TThostFtdcContingentConditionType:" << pOrder->ContingentCondition << endl;
    cout << "ֹ��� TThostFtdcPriceType:" << pOrder->StopPrice << endl;
    cout << "ǿƽԭ�� TThostFtdcForceCloseReasonType:" << pOrder->ForceCloseReason << endl;
    cout << "�Զ������־ TThostFtdcBoolType:" << pOrder->IsAutoSuspend << endl;
    cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << pOrder->BusinessUnit << endl;
    cout << "������ TThostFtdcRequestIDType:" << pOrder->RequestID << endl;
    cout << "���ر������ TThostFtdcOrderLocalIDType:" << pOrder->OrderLocalID << endl;
    cout << "���������� TThostFtdcExchangeIDType:" << pOrder->ExchangeID << endl;
    cout << "��Ա���� TThostFtdcParticipantIDType:" << pOrder->ParticipantID << endl;
    cout << "�ͻ����� TThostFtdcClientIDType:" << pOrder->ClientID << endl;
    cout << "��Լ�ڽ������Ĵ��� TThostFtdcExchangeInstIDType:" << pOrder->ExchangeInstID << endl;
    cout << "����������Ա���� TThostFtdcTraderIDType:" << pOrder->TraderID << endl;
    cout << "��װ��� TThostFtdcInstallIDType:" << pOrder->InstallID << endl;
    cout << "�����ύ״̬ TThostFtdcOrderSubmitStatusType:" << pOrder->OrderSubmitStatus << endl;
    cout << "������ʾ��� TThostFtdcSequenceNoType:" << pOrder->NotifySequence << endl;
    cout << "������ TThostFtdcDateType:" << pOrder->TradingDay << endl;
    cout << "������ TThostFtdcSettlementIDType:" << pOrder->SettlementID << endl;
    cout << "������� TThostFtdcOrderSysIDType:" << pOrder->OrderSysID << endl;
    cout << "������Դ TThostFtdcOrderSourceType:" << pOrder->OrderSource << endl;
    cout << "����״̬ TThostFtdcOrderStatusType:" << pOrder->OrderStatus << endl;
    cout << "�������� TThostFtdcOrderTypeType:" << pOrder->OrderType << endl;
    cout << "��ɽ����� TThostFtdcVolumeType:" << pOrder->VolumeTraded << endl;
    cout << "ʣ������ TThostFtdcVolumeType:" << pOrder->VolumeTotal << endl;
    cout << "�������� TThostFtdcDateType:" << pOrder->InsertDate << endl;
    cout << "ί��ʱ�� TThostFtdcTimeType:" << pOrder->InsertTime << endl;
    cout << "����ʱ�� TThostFtdcTimeType:" << pOrder->ActiveTime << endl;
    cout << "����ʱ�� TThostFtdcTimeType:" << pOrder->SuspendTime << endl;
    cout << "����޸�ʱ�� TThostFtdcTimeType:" << pOrder->UpdateTime << endl;
    cout << "����ʱ�� TThostFtdcTimeType:" << pOrder->CancelTime << endl;
    cout << "����޸Ľ���������Ա���� TThostFtdcTraderIDType:" << pOrder->ActiveTraderID << endl;
    cout << "�����Ա��� TThostFtdcParticipantIDType:" << pOrder->ClearingPartID << endl;
    cout << "��� TThostFtdcSequenceNoType:" << pOrder->SequenceNo << endl;
    cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << pOrder->FrontID << endl;
    cout << "�Ự��� TThostFtdcSessionIDType:" << pOrder->SessionID << endl;
    cout << "�û��˲�Ʒ��Ϣ TThostFtdcProductInfoType:" << pOrder->UserProductInfo << endl;
    cout << "״̬��Ϣ TThostFtdcErrorMsgType:" << pOrder->StatusMsg << endl;
    cout << "�û�ǿ����־ TThostFtdcBoolType:" << pOrder->UserForceClose << endl;
    cout << "�����û����� TThostFtdcUserIDType:" << pOrder->ActiveUserID << endl;
    cout << "���͹�˾������� TThostFtdcSequenceNoType:" << pOrder->BrokerOrderSeq << endl;
    cout << "��ر��� TThostFtdcOrderSysIDType:" << pOrder->RelativeOrderSysID << endl;
    cout << "֣�����ɽ����� TThostFtdcVolumeType:" << pOrder->ZCETotalTradedVolume << endl;
    cout << "��������־ TThostFtdcBoolType:" << pOrder->IsSwapOrder << endl;
    cout << "Ӫҵ����� TThostFtdcBranchIDType:" << pOrder->BranchID << endl;
}

///�ɽ�֪ͨ
void CTraderSpi::OnRtnTrade(CThostFtdcTradeField* pTrade)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pTrade->BrokerID << endl;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pTrade->InvestorID << endl;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << pTrade->InstrumentID << endl;
    cout << "�������� TThostFtdcOrderRefType:" << pTrade->OrderRef << endl;
    cout << "�û����� TThostFtdcUserIDType:" << pTrade->UserID << endl;
    cout << "���������� TThostFtdcExchangeIDType:" << pTrade->ExchangeID << endl;
    cout << "�ɽ���� TThostFtdcTradeIDType:" << pTrade->TradeID << endl;
    cout << "�������� TThostFtdcDirectionType:" << pTrade->Direction << endl;
    cout << "������� TThostFtdcOrderSysIDType:" << pTrade->OrderSysID << endl;
    cout << "��Ա���� TThostFtdcParticipantIDType:" << pTrade->ParticipantID << endl;
    cout << "�ͻ����� TThostFtdcClientIDType:" << pTrade->ClientID << endl;
    cout << "���׽�ɫ TThostFtdcTradingRoleType:" << pTrade->TradingRole << endl;
    cout << "��Լ�ڽ������Ĵ��� TThostFtdcExchangeInstIDType:" << pTrade->ExchangeInstID << endl;
    cout << "��ƽ��־ TThostFtdcOffsetFlagType:" << pTrade->OffsetFlag << endl;
    cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pTrade->HedgeFlag << endl;
    cout << "�۸� TThostFtdcPriceType:" << pTrade->Price << endl;
    cout << "���� TThostFtdcVolumeType:" << pTrade->Volume << endl;
    cout << "�ɽ�ʱ�� TThostFtdcDateType:" << pTrade->TradeDate << endl;
    cout << "�ɽ�ʱ�� TThostFtdcTimeType:" << pTrade->TradeTime << endl;
    cout << "�ɽ����� TThostFtdcTradeTypeType:" << pTrade->TradeType << endl;
    cout << "�ɽ�����Դ TThostFtdcPriceSourceType:" << pTrade->PriceSource << endl;
    cout << "����������Ա���� TThostFtdcTraderIDType:" << pTrade->TraderID << endl;
    cout << "���ر������ TThostFtdcOrderLocalIDType:" << pTrade->OrderLocalID << endl;
    cout << "�����Ա��� TThostFtdcParticipantIDType:" << pTrade->ClearingPartID << endl;
    cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << pTrade->BusinessUnit << endl;
    cout << "��� TThostFtdcSequenceNoType:" << pTrade->SequenceNo << endl;
    cout << "������ TThostFtdcDateType:" << pTrade->TradingDay << endl;
    cout << "������ TThostFtdcSettlementIDType:" << pTrade->SettlementID << endl;
    cout << "���͹�˾������� TThostFtdcSequenceNoType:" << pTrade->BrokerOrderSeq << endl;
    cout << "�ɽ���Դ TThostFtdcTradeSourceType:" << pTrade->TradeSource << endl;
}

///����¼�����ر�
void CTraderSpi::OnErrRtnOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (!IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pInputOrder->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pInputOrder->InvestorID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pInputOrder->InstrumentID << endl;
	cout << "�������� TThostFtdcOrderRefType:" << pInputOrder->OrderRef << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pInputOrder->UserID << endl;
	cout << "�����۸����� TThostFtdcOrderPriceTypeType:" << pInputOrder->OrderPriceType << endl;
	cout << "�������� TThostFtdcDirectionType:" << pInputOrder->Direction << endl;
	cout << "��Ͽ�ƽ��־ TThostFtdcCombOffsetFlagType:" << pInputOrder->CombOffsetFlag << endl;
	cout << "���Ͷ���ױ���־ TThostFtdcCombHedgeFlagType:" << pInputOrder->CombHedgeFlag << endl;
	cout << "�۸� TThostFtdcPriceType:" << pInputOrder->LimitPrice << endl;
	cout << "���� TThostFtdcVolumeType:" << pInputOrder->VolumeTotalOriginal << endl;
	cout << "��Ч������ TThostFtdcTimeConditionType:" << pInputOrder->TimeCondition << endl;
	cout << "���� TThostFtdcDateType:" << pInputOrder->GTDDate << endl;
	cout << "�ɽ������� TThostFtdcVolumeConditionType:" << pInputOrder->VolumeCondition << endl;
	cout << "��С�ɽ��� TThostFtdcVolumeType:" << pInputOrder->MinVolume << endl;
	cout << "�������� TThostFtdcContingentConditionType:" << pInputOrder->ContingentCondition << endl;
	cout << "ֹ��� TThostFtdcPriceType:" << pInputOrder->StopPrice << endl;
	cout << "ǿƽԭ�� TThostFtdcForceCloseReasonType:" << pInputOrder->ForceCloseReason << endl;
	cout << "�Զ������־ TThostFtdcBoolType:" << pInputOrder->IsAutoSuspend << endl;
	cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << pInputOrder->BusinessUnit << endl;
	cout << "������ TThostFtdcRequestIDType:" << pInputOrder->RequestID << endl;
	cout << "�û�ǿ����־ TThostFtdcBoolType:" << pInputOrder->UserForceClose << endl;
	cout << "��������־ TThostFtdcBoolType:" << pInputOrder->IsSwapOrder << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pInputOrder->ExchangeID << endl;
    }
}

///������������ر�
void CTraderSpi::OnErrRtnOrderAction(CThostFtdcOrderActionField* pOrderAction, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (!IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pOrderAction->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pOrderAction->InvestorID << endl;
	cout << "������������ TThostFtdcOrderActionRefType:" << pOrderAction->OrderActionRef << endl;
	cout << "�������� TThostFtdcOrderRefType:" << pOrderAction->OrderRef << endl;
	cout << "������ TThostFtdcRequestIDType:" << pOrderAction->RequestID << endl;
	cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << pOrderAction->FrontID << endl;
	cout << "�Ự��� TThostFtdcSessionIDType:" << pOrderAction->SessionID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pOrderAction->ExchangeID << endl;
	cout << "������� TThostFtdcOrderSysIDType:" << pOrderAction->OrderSysID << endl;
	cout << "������־ TThostFtdcActionFlagType:" << pOrderAction->ActionFlag << endl;
	cout << "�۸� TThostFtdcPriceType:" << pOrderAction->LimitPrice << endl;
	cout << "�����仯 TThostFtdcVolumeType:" << pOrderAction->VolumeChange << endl;
	cout << "�������� TThostFtdcDateType:" << pOrderAction->ActionDate << endl;
	cout << "����ʱ�� TThostFtdcTimeType:" << pOrderAction->ActionTime << endl;
	cout << "����������Ա���� TThostFtdcTraderIDType:" << pOrderAction->TraderID << endl;
	cout << "��װ��� TThostFtdcInstallIDType:" << pOrderAction->InstallID << endl;
	cout << "���ر������ TThostFtdcOrderLocalIDType:" << pOrderAction->OrderLocalID << endl;
	cout << "�������ر�� TThostFtdcOrderLocalIDType:" << pOrderAction->ActionLocalID << endl;
	cout << "��Ա���� TThostFtdcParticipantIDType:" << pOrderAction->ParticipantID << endl;
	cout << "�ͻ����� TThostFtdcClientIDType:" << pOrderAction->ClientID << endl;
	cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << pOrderAction->BusinessUnit << endl;
	cout << "��������״̬ TThostFtdcOrderActionStatusType:" << pOrderAction->OrderActionStatus << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pOrderAction->UserID << endl;
	cout << "״̬��Ϣ TThostFtdcErrorMsgType:" << pOrderAction->StatusMsg << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pOrderAction->InstrumentID << endl;
	cout << "Ӫҵ����� TThostFtdcBranchIDType:" << pOrderAction->BranchID << endl;
    }
}

///��Լ����״̬֪ͨ
void CTraderSpi::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField* pInstrumentStatus)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "���������� TThostFtdcExchangeIDType:" << pInstrumentStatus->ExchangeID << endl;
    cout << "��Լ�ڽ������Ĵ��� TThostFtdcExchangeInstIDType:" << pInstrumentStatus->ExchangeInstID << endl;
    cout << "��������� TThostFtdcSettlementGroupIDType:" << pInstrumentStatus->SettlementGroupID << endl;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << pInstrumentStatus->InstrumentID << endl;
    cout << "��Լ����״̬ TThostFtdcInstrumentStatusType:" << pInstrumentStatus->InstrumentStatus << endl;
    cout << "���׽׶α�� TThostFtdcTradingSegmentSNType:" << pInstrumentStatus->TradingSegmentSN << endl;
    cout << "���뱾״̬ʱ�� TThostFtdcTimeType:" << pInstrumentStatus->EnterTime << endl;
    cout << "���뱾״̬ԭ�� TThostFtdcInstStatusEnterReasonType:" << pInstrumentStatus->EnterReason << endl;
}

///����֪ͨ
void CTraderSpi::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField* pTradingNoticeInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pTradingNoticeInfo->BrokerID << endl;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pTradingNoticeInfo->InvestorID << endl;
    cout << "����ʱ�� TThostFtdcTimeType:" << pTradingNoticeInfo->SendTime << endl;
    cout << "��Ϣ���� TThostFtdcContentType:" << pTradingNoticeInfo->FieldContent << endl;
    cout << "����ϵ�к� TThostFtdcSequenceSeriesType:" << pTradingNoticeInfo->SequenceSeries << endl;
    cout << "���к� TThostFtdcSequenceNoType:" << pTradingNoticeInfo->SequenceNo << endl;
}

///��ʾ������У�����
void CTraderSpi::OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField* pErrorConditionalOrder)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pErrorConditionalOrder->BrokerID << endl;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pErrorConditionalOrder->InvestorID << endl;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << pErrorConditionalOrder->InstrumentID << endl;
    cout << "�������� TThostFtdcOrderRefType:" << pErrorConditionalOrder->OrderRef << endl;
    cout << "�û����� TThostFtdcUserIDType:" << pErrorConditionalOrder->UserID << endl;
    cout << "�����۸����� TThostFtdcOrderPriceTypeType:" << pErrorConditionalOrder->OrderPriceType << endl;
    cout << "�������� TThostFtdcDirectionType:" << pErrorConditionalOrder->Direction << endl;
    cout << "��Ͽ�ƽ��־ TThostFtdcCombOffsetFlagType:" << pErrorConditionalOrder->CombOffsetFlag << endl;
    cout << "���Ͷ���ױ���־ TThostFtdcCombHedgeFlagType:" << pErrorConditionalOrder->CombHedgeFlag << endl;
    cout << "�۸� TThostFtdcPriceType:" << pErrorConditionalOrder->LimitPrice << endl;
    cout << "���� TThostFtdcVolumeType:" << pErrorConditionalOrder->VolumeTotalOriginal << endl;
    cout << "��Ч������ TThostFtdcTimeConditionType:" << pErrorConditionalOrder->TimeCondition << endl;
    cout << "���� TThostFtdcDateType:" << pErrorConditionalOrder->GTDDate << endl;
    cout << "�ɽ������� TThostFtdcVolumeConditionType:" << pErrorConditionalOrder->VolumeCondition << endl;
    cout << "��С�ɽ��� TThostFtdcVolumeType:" << pErrorConditionalOrder->MinVolume << endl;
    cout << "�������� TThostFtdcContingentConditionType:" << pErrorConditionalOrder->ContingentCondition << endl;
    cout << "ֹ��� TThostFtdcPriceType:" << pErrorConditionalOrder->StopPrice << endl;
    cout << "ǿƽԭ�� TThostFtdcForceCloseReasonType:" << pErrorConditionalOrder->ForceCloseReason << endl;
    cout << "�Զ������־ TThostFtdcBoolType:" << pErrorConditionalOrder->IsAutoSuspend << endl;
    cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << pErrorConditionalOrder->BusinessUnit << endl;
    cout << "������ TThostFtdcRequestIDType:" << pErrorConditionalOrder->RequestID << endl;
    cout << "���ر������ TThostFtdcOrderLocalIDType:" << pErrorConditionalOrder->OrderLocalID << endl;
    cout << "���������� TThostFtdcExchangeIDType:" << pErrorConditionalOrder->ExchangeID << endl;
    cout << "��Ա���� TThostFtdcParticipantIDType:" << pErrorConditionalOrder->ParticipantID << endl;
    cout << "�ͻ����� TThostFtdcClientIDType:" << pErrorConditionalOrder->ClientID << endl;
    cout << "��Լ�ڽ������Ĵ��� TThostFtdcExchangeInstIDType:" << pErrorConditionalOrder->ExchangeInstID << endl;
    cout << "����������Ա���� TThostFtdcTraderIDType:" << pErrorConditionalOrder->TraderID << endl;
    cout << "��װ��� TThostFtdcInstallIDType:" << pErrorConditionalOrder->InstallID << endl;
    cout << "�����ύ״̬ TThostFtdcOrderSubmitStatusType:" << pErrorConditionalOrder->OrderSubmitStatus << endl;
    cout << "������ʾ��� TThostFtdcSequenceNoType:" << pErrorConditionalOrder->NotifySequence << endl;
    cout << "������ TThostFtdcDateType:" << pErrorConditionalOrder->TradingDay << endl;
    cout << "������ TThostFtdcSettlementIDType:" << pErrorConditionalOrder->SettlementID << endl;
    cout << "������� TThostFtdcOrderSysIDType:" << pErrorConditionalOrder->OrderSysID << endl;
    cout << "������Դ TThostFtdcOrderSourceType:" << pErrorConditionalOrder->OrderSource << endl;
    cout << "����״̬ TThostFtdcOrderStatusType:" << pErrorConditionalOrder->OrderStatus << endl;
    cout << "�������� TThostFtdcOrderTypeType:" << pErrorConditionalOrder->OrderType << endl;
    cout << "��ɽ����� TThostFtdcVolumeType:" << pErrorConditionalOrder->VolumeTraded << endl;
    cout << "ʣ������ TThostFtdcVolumeType:" << pErrorConditionalOrder->VolumeTotal << endl;
    cout << "�������� TThostFtdcDateType:" << pErrorConditionalOrder->InsertDate << endl;
    cout << "ί��ʱ�� TThostFtdcTimeType:" << pErrorConditionalOrder->InsertTime << endl;
    cout << "����ʱ�� TThostFtdcTimeType:" << pErrorConditionalOrder->ActiveTime << endl;
    cout << "����ʱ�� TThostFtdcTimeType:" << pErrorConditionalOrder->SuspendTime << endl;
    cout << "����޸�ʱ�� TThostFtdcTimeType:" << pErrorConditionalOrder->UpdateTime << endl;
    cout << "����ʱ�� TThostFtdcTimeType:" << pErrorConditionalOrder->CancelTime << endl;
    cout << "����޸Ľ���������Ա���� TThostFtdcTraderIDType:" << pErrorConditionalOrder->ActiveTraderID << endl;
    cout << "�����Ա��� TThostFtdcParticipantIDType:" << pErrorConditionalOrder->ClearingPartID << endl;
    cout << "��� TThostFtdcSequenceNoType:" << pErrorConditionalOrder->SequenceNo << endl;
    cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << pErrorConditionalOrder->FrontID << endl;
    cout << "�Ự��� TThostFtdcSessionIDType:" << pErrorConditionalOrder->SessionID << endl;
    cout << "�û��˲�Ʒ��Ϣ TThostFtdcProductInfoType:" << pErrorConditionalOrder->UserProductInfo << endl;
    cout << "״̬��Ϣ TThostFtdcErrorMsgType:" << pErrorConditionalOrder->StatusMsg << endl;
    cout << "�û�ǿ����־ TThostFtdcBoolType:" << pErrorConditionalOrder->UserForceClose << endl;
    cout << "�����û����� TThostFtdcUserIDType:" << pErrorConditionalOrder->ActiveUserID << endl;
    cout << "���͹�˾������� TThostFtdcSequenceNoType:" << pErrorConditionalOrder->BrokerOrderSeq << endl;
    cout << "��ر��� TThostFtdcOrderSysIDType:" << pErrorConditionalOrder->RelativeOrderSysID << endl;
    cout << "֣�����ɽ����� TThostFtdcVolumeType:" << pErrorConditionalOrder->ZCETotalTradedVolume << endl;
    cout << "������� TThostFtdcErrorIDType:" << pErrorConditionalOrder->ErrorID << endl;
    cout << "������Ϣ TThostFtdcErrorMsgType:" << pErrorConditionalOrder->ErrorMsg << endl;
    cout << "��������־ TThostFtdcBoolType:" << pErrorConditionalOrder->IsSwapOrder << endl;
    cout << "Ӫҵ����� TThostFtdcBranchIDType:" << pErrorConditionalOrder->BranchID << endl;
}

///ִ������֪ͨ
void CTraderSpi::OnRtnExecOrder(CThostFtdcExecOrderField* pExecOrder)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pExecOrder->BrokerID << endl;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pExecOrder->InvestorID << endl;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << pExecOrder->InstrumentID << endl;
    cout << "ִ���������� TThostFtdcOrderRefType:" << pExecOrder->ExecOrderRef << endl;
    cout << "�û����� TThostFtdcUserIDType:" << pExecOrder->UserID << endl;
    cout << "���� TThostFtdcVolumeType:" << pExecOrder->Volume << endl;
    cout << "������ TThostFtdcRequestIDType:" << pExecOrder->RequestID << endl;
    cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << pExecOrder->BusinessUnit << endl;
    cout << "��ƽ��־ TThostFtdcOffsetFlagType:" << pExecOrder->OffsetFlag << endl;
    cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pExecOrder->HedgeFlag << endl;
    cout << "ִ������ TThostFtdcActionTypeType:" << pExecOrder->ActionType << endl;
    cout << "����ͷ������ĳֲַ��� TThostFtdcPosiDirectionType:" << pExecOrder->PosiDirection << endl;
    cout << "��Ȩ��Ȩ���Ƿ����ڻ�ͷ��ı�� TThostFtdcExecOrderPositionFlagType:" << pExecOrder->ReservePositionFlag << endl;
    cout << "��Ȩ��Ȩ�����ɵ�ͷ���Ƿ��Զ�ƽ�� TThostFtdcExecOrderCloseFlagType:" << pExecOrder->CloseFlag << endl;
    cout << "����ִ�������� TThostFtdcOrderLocalIDType:" << pExecOrder->ExecOrderLocalID << endl;
    cout << "���������� TThostFtdcExchangeIDType:" << pExecOrder->ExchangeID << endl;
    cout << "��Ա���� TThostFtdcParticipantIDType:" << pExecOrder->ParticipantID << endl;
    cout << "�ͻ����� TThostFtdcClientIDType:" << pExecOrder->ClientID << endl;
    cout << "��Լ�ڽ������Ĵ��� TThostFtdcExchangeInstIDType:" << pExecOrder->ExchangeInstID << endl;
    cout << "����������Ա���� TThostFtdcTraderIDType:" << pExecOrder->TraderID << endl;
    cout << "��װ��� TThostFtdcInstallIDType:" << pExecOrder->InstallID << endl;
    cout << "ִ�������ύ״̬ TThostFtdcOrderSubmitStatusType:" << pExecOrder->OrderSubmitStatus << endl;
    cout << "������ʾ��� TThostFtdcSequenceNoType:" << pExecOrder->NotifySequence << endl;
    cout << "������ TThostFtdcDateType:" << pExecOrder->TradingDay << endl;
    cout << "������ TThostFtdcSettlementIDType:" << pExecOrder->SettlementID << endl;
    cout << "ִ�������� TThostFtdcExecOrderSysIDType:" << pExecOrder->ExecOrderSysID << endl;
    cout << "�������� TThostFtdcDateType:" << pExecOrder->InsertDate << endl;
    cout << "����ʱ�� TThostFtdcTimeType:" << pExecOrder->InsertTime << endl;
    cout << "����ʱ�� TThostFtdcTimeType:" << pExecOrder->CancelTime << endl;
    cout << "ִ�н�� TThostFtdcExecResultType:" << pExecOrder->ExecResult << endl;
    cout << "�����Ա��� TThostFtdcParticipantIDType:" << pExecOrder->ClearingPartID << endl;
    cout << "��� TThostFtdcSequenceNoType:" << pExecOrder->SequenceNo << endl;
    cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << pExecOrder->FrontID << endl;
    cout << "�Ự��� TThostFtdcSessionIDType:" << pExecOrder->SessionID << endl;
    cout << "�û��˲�Ʒ��Ϣ TThostFtdcProductInfoType:" << pExecOrder->UserProductInfo << endl;
    cout << "״̬��Ϣ TThostFtdcErrorMsgType:" << pExecOrder->StatusMsg << endl;
    cout << "�����û����� TThostFtdcUserIDType:" << pExecOrder->ActiveUserID << endl;
    cout << "���͹�˾������� TThostFtdcSequenceNoType:" << pExecOrder->BrokerExecOrderSeq << endl;
    cout << "Ӫҵ����� TThostFtdcBranchIDType:" << pExecOrder->BranchID << endl;
}

///ִ������¼�����ر�
void CTraderSpi::OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (!IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pInputExecOrder->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pInputExecOrder->InvestorID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pInputExecOrder->InstrumentID << endl;
	cout << "ִ���������� TThostFtdcOrderRefType:" << pInputExecOrder->ExecOrderRef << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pInputExecOrder->UserID << endl;
	cout << "���� TThostFtdcVolumeType:" << pInputExecOrder->Volume << endl;
	cout << "������ TThostFtdcRequestIDType:" << pInputExecOrder->RequestID << endl;
	cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << pInputExecOrder->BusinessUnit << endl;
	cout << "��ƽ��־ TThostFtdcOffsetFlagType:" << pInputExecOrder->OffsetFlag << endl;
	cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pInputExecOrder->HedgeFlag << endl;
	cout << "ִ������ TThostFtdcActionTypeType:" << pInputExecOrder->ActionType << endl;
	cout << "����ͷ������ĳֲַ��� TThostFtdcPosiDirectionType:" << pInputExecOrder->PosiDirection << endl;
	cout << "��Ȩ��Ȩ���Ƿ����ڻ�ͷ��ı�� TThostFtdcExecOrderPositionFlagType:" << pInputExecOrder->ReservePositionFlag << endl;
	cout << "��Ȩ��Ȩ�����ɵ�ͷ���Ƿ��Զ�ƽ�� TThostFtdcExecOrderCloseFlagType:" << pInputExecOrder->CloseFlag << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pInputExecOrder->ExchangeID << endl;
    }
}

///ִ�������������ر�
void CTraderSpi::OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField* pExecOrderAction, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (!IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pExecOrderAction->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pExecOrderAction->InvestorID << endl;
	cout << "ִ������������� TThostFtdcOrderActionRefType:" << pExecOrderAction->ExecOrderActionRef << endl;
	cout << "ִ���������� TThostFtdcOrderRefType:" << pExecOrderAction->ExecOrderRef << endl;
	cout << "������ TThostFtdcRequestIDType:" << pExecOrderAction->RequestID << endl;
	cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << pExecOrderAction->FrontID << endl;
	cout << "�Ự��� TThostFtdcSessionIDType:" << pExecOrderAction->SessionID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pExecOrderAction->ExchangeID << endl;
	cout << "ִ������������ TThostFtdcExecOrderSysIDType:" << pExecOrderAction->ExecOrderSysID << endl;
	cout << "������־ TThostFtdcActionFlagType:" << pExecOrderAction->ActionFlag << endl;
	cout << "�������� TThostFtdcDateType:" << pExecOrderAction->ActionDate << endl;
	cout << "����ʱ�� TThostFtdcTimeType:" << pExecOrderAction->ActionTime << endl;
	cout << "����������Ա���� TThostFtdcTraderIDType:" << pExecOrderAction->TraderID << endl;
	cout << "��װ��� TThostFtdcInstallIDType:" << pExecOrderAction->InstallID << endl;
	cout << "����ִ�������� TThostFtdcOrderLocalIDType:" << pExecOrderAction->ExecOrderLocalID << endl;
	cout << "�������ر�� TThostFtdcOrderLocalIDType:" << pExecOrderAction->ActionLocalID << endl;
	cout << "��Ա���� TThostFtdcParticipantIDType:" << pExecOrderAction->ParticipantID << endl;
	cout << "�ͻ����� TThostFtdcClientIDType:" << pExecOrderAction->ClientID << endl;
	cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << pExecOrderAction->BusinessUnit << endl;
	cout << "��������״̬ TThostFtdcOrderActionStatusType:" << pExecOrderAction->OrderActionStatus << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pExecOrderAction->UserID << endl;
	cout << "ִ������ TThostFtdcActionTypeType:" << pExecOrderAction->ActionType << endl;
	cout << "״̬��Ϣ TThostFtdcErrorMsgType:" << pExecOrderAction->StatusMsg << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pExecOrderAction->InstrumentID << endl;
	cout << "Ӫҵ����� TThostFtdcBranchIDType:" << pExecOrderAction->BranchID << endl;
    }
}

///ѯ��¼�����ر�
void CTraderSpi::OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (!IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pInputForQuote->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pInputForQuote->InvestorID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pInputForQuote->InstrumentID << endl;
	cout << "ѯ������ TThostFtdcOrderRefType:" << pInputForQuote->ForQuoteRef << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pInputForQuote->UserID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pInputForQuote->ExchangeID << endl;
    }
}

///����֪ͨ
void CTraderSpi::OnRtnQuote(CThostFtdcQuoteField* pQuote)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pQuote->BrokerID << endl;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pQuote->InvestorID << endl;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << pQuote->InstrumentID << endl;
    cout << "�������� TThostFtdcOrderRefType:" << pQuote->QuoteRef << endl;
    cout << "�û����� TThostFtdcUserIDType:" << pQuote->UserID << endl;
    cout << "���۸� TThostFtdcPriceType:" << pQuote->AskPrice << endl;
    cout << "��۸� TThostFtdcPriceType:" << pQuote->BidPrice << endl;
    cout << "������ TThostFtdcVolumeType:" << pQuote->AskVolume << endl;
    cout << "������ TThostFtdcVolumeType:" << pQuote->BidVolume << endl;
    cout << "������ TThostFtdcRequestIDType:" << pQuote->RequestID << endl;
    cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << pQuote->BusinessUnit << endl;
    cout << "����ƽ��־ TThostFtdcOffsetFlagType:" << pQuote->AskOffsetFlag << endl;
    cout << "��ƽ��־ TThostFtdcOffsetFlagType:" << pQuote->BidOffsetFlag << endl;
    cout << "��Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pQuote->AskHedgeFlag << endl;
    cout << "��Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pQuote->BidHedgeFlag << endl;
    cout << "���ر��۱�� TThostFtdcOrderLocalIDType:" << pQuote->QuoteLocalID << endl;
    cout << "���������� TThostFtdcExchangeIDType:" << pQuote->ExchangeID << endl;
    cout << "��Ա���� TThostFtdcParticipantIDType:" << pQuote->ParticipantID << endl;
    cout << "�ͻ����� TThostFtdcClientIDType:" << pQuote->ClientID << endl;
    cout << "��Լ�ڽ������Ĵ��� TThostFtdcExchangeInstIDType:" << pQuote->ExchangeInstID << endl;
    cout << "����������Ա���� TThostFtdcTraderIDType:" << pQuote->TraderID << endl;
    cout << "��װ��� TThostFtdcInstallIDType:" << pQuote->InstallID << endl;
    cout << "������ʾ��� TThostFtdcSequenceNoType:" << pQuote->NotifySequence << endl;
    cout << "�����ύ״̬ TThostFtdcOrderSubmitStatusType:" << pQuote->OrderSubmitStatus << endl;
    cout << "������ TThostFtdcDateType:" << pQuote->TradingDay << endl;
    cout << "������ TThostFtdcSettlementIDType:" << pQuote->SettlementID << endl;
    cout << "���۱�� TThostFtdcOrderSysIDType:" << pQuote->QuoteSysID << endl;
    cout << "�������� TThostFtdcDateType:" << pQuote->InsertDate << endl;
    cout << "����ʱ�� TThostFtdcTimeType:" << pQuote->InsertTime << endl;
    cout << "����ʱ�� TThostFtdcTimeType:" << pQuote->CancelTime << endl;
    cout << "����״̬ TThostFtdcOrderStatusType:" << pQuote->QuoteStatus << endl;
    cout << "�����Ա��� TThostFtdcParticipantIDType:" << pQuote->ClearingPartID << endl;
    cout << "��� TThostFtdcSequenceNoType:" << pQuote->SequenceNo << endl;
    cout << "����������� TThostFtdcOrderSysIDType:" << pQuote->AskOrderSysID << endl;
    cout << "�򷽱������ TThostFtdcOrderSysIDType:" << pQuote->BidOrderSysID << endl;
    cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << pQuote->FrontID << endl;
    cout << "�Ự��� TThostFtdcSessionIDType:" << pQuote->SessionID << endl;
    cout << "�û��˲�Ʒ��Ϣ TThostFtdcProductInfoType:" << pQuote->UserProductInfo << endl;
    cout << "״̬��Ϣ TThostFtdcErrorMsgType:" << pQuote->StatusMsg << endl;
    cout << "�����û����� TThostFtdcUserIDType:" << pQuote->ActiveUserID << endl;
    cout << "���͹�˾���۱�� TThostFtdcSequenceNoType:" << pQuote->BrokerQuoteSeq << endl;
    cout << "�������������� TThostFtdcOrderRefType:" << pQuote->AskOrderRef << endl;
    cout << "�����򱨵����� TThostFtdcOrderRefType:" << pQuote->BidOrderRef << endl;
    cout << "Ӧ�۱�� TThostFtdcOrderSysIDType:" << pQuote->ForQuoteSysID << endl;
    cout << "Ӫҵ����� TThostFtdcBranchIDType:" << pQuote->BranchID << endl;
}

///����¼�����ر�
void CTraderSpi::OnErrRtnQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (!IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pInputQuote->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pInputQuote->InvestorID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pInputQuote->InstrumentID << endl;
	cout << "�������� TThostFtdcOrderRefType:" << pInputQuote->QuoteRef << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pInputQuote->UserID << endl;
	cout << "���۸� TThostFtdcPriceType:" << pInputQuote->AskPrice << endl;
	cout << "��۸� TThostFtdcPriceType:" << pInputQuote->BidPrice << endl;
	cout << "������ TThostFtdcVolumeType:" << pInputQuote->AskVolume << endl;
	cout << "������ TThostFtdcVolumeType:" << pInputQuote->BidVolume << endl;
	cout << "������ TThostFtdcRequestIDType:" << pInputQuote->RequestID << endl;
	cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << pInputQuote->BusinessUnit << endl;
	cout << "����ƽ��־ TThostFtdcOffsetFlagType:" << pInputQuote->AskOffsetFlag << endl;
	cout << "��ƽ��־ TThostFtdcOffsetFlagType:" << pInputQuote->BidOffsetFlag << endl;
	cout << "��Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pInputQuote->AskHedgeFlag << endl;
	cout << "��Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pInputQuote->BidHedgeFlag << endl;
	cout << "�������������� TThostFtdcOrderRefType:" << pInputQuote->AskOrderRef << endl;
	cout << "�����򱨵����� TThostFtdcOrderRefType:" << pInputQuote->BidOrderRef << endl;
	cout << "Ӧ�۱�� TThostFtdcOrderSysIDType:" << pInputQuote->ForQuoteSysID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pInputQuote->ExchangeID << endl;
    }
}

///���۲�������ر�
void CTraderSpi::OnErrRtnQuoteAction(CThostFtdcQuoteActionField* pQuoteAction, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (!IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pQuoteAction->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pQuoteAction->InvestorID << endl;
	cout << "���۲������� TThostFtdcOrderActionRefType:" << pQuoteAction->QuoteActionRef << endl;
	cout << "�������� TThostFtdcOrderRefType:" << pQuoteAction->QuoteRef << endl;
	cout << "������ TThostFtdcRequestIDType:" << pQuoteAction->RequestID << endl;
	cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << pQuoteAction->FrontID << endl;
	cout << "�Ự��� TThostFtdcSessionIDType:" << pQuoteAction->SessionID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pQuoteAction->ExchangeID << endl;
	cout << "���۲������ TThostFtdcOrderSysIDType:" << pQuoteAction->QuoteSysID << endl;
	cout << "������־ TThostFtdcActionFlagType:" << pQuoteAction->ActionFlag << endl;
	cout << "�������� TThostFtdcDateType:" << pQuoteAction->ActionDate << endl;
	cout << "����ʱ�� TThostFtdcTimeType:" << pQuoteAction->ActionTime << endl;
	cout << "����������Ա���� TThostFtdcTraderIDType:" << pQuoteAction->TraderID << endl;
	cout << "��װ��� TThostFtdcInstallIDType:" << pQuoteAction->InstallID << endl;
	cout << "���ر��۱�� TThostFtdcOrderLocalIDType:" << pQuoteAction->QuoteLocalID << endl;
	cout << "�������ر�� TThostFtdcOrderLocalIDType:" << pQuoteAction->ActionLocalID << endl;
	cout << "��Ա���� TThostFtdcParticipantIDType:" << pQuoteAction->ParticipantID << endl;
	cout << "�ͻ����� TThostFtdcClientIDType:" << pQuoteAction->ClientID << endl;
	cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << pQuoteAction->BusinessUnit << endl;
	cout << "��������״̬ TThostFtdcOrderActionStatusType:" << pQuoteAction->OrderActionStatus << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pQuoteAction->UserID << endl;
	cout << "״̬��Ϣ TThostFtdcErrorMsgType:" << pQuoteAction->StatusMsg << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pQuoteAction->InstrumentID << endl;
	cout << "Ӫҵ����� TThostFtdcBranchIDType:" << pQuoteAction->BranchID << endl;
    }
}

///ѯ��֪ͨ
void CTraderSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "������ TThostFtdcDateType:" << pForQuoteRsp->TradingDay << endl;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << pForQuoteRsp->InstrumentID << endl;
    cout << "ѯ�۱�� TThostFtdcOrderSysIDType:" << pForQuoteRsp->ForQuoteSysID << endl;
    cout << "ѯ��ʱ�� TThostFtdcTimeType:" << pForQuoteRsp->ForQuoteTime << endl;
    cout << "ҵ������ TThostFtdcDateType:" << pForQuoteRsp->ActionDay << endl;
    cout << "���������� TThostFtdcExchangeIDType:" << pForQuoteRsp->ExchangeID << endl;
}

///��֤���������û�����
void CTraderSpi::OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField* pCFMMCTradingAccountToken)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pCFMMCTradingAccountToken->BrokerID << endl;
    cout << "���͹�˾ͳһ���� TThostFtdcParticipantIDType:" << pCFMMCTradingAccountToken->ParticipantID << endl;
    cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pCFMMCTradingAccountToken->AccountID << endl;
    cout << "��Կ��� TThostFtdcSequenceNoType:" << pCFMMCTradingAccountToken->KeyID << endl;
    cout << "��̬���� TThostFtdcCFMMCTokenType:" << pCFMMCTradingAccountToken->Token << endl;
}

///����֪ͨ
void CTraderSpi::OnRtnLock(CThostFtdcLockField* pLock)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pLock->BrokerID << endl;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pLock->InvestorID << endl;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << pLock->InstrumentID << endl;
    cout << "�������� TThostFtdcOrderRefType:" << pLock->LockRef << endl;
    cout << "�û����� TThostFtdcUserIDType:" << pLock->UserID << endl;
    cout << "���� TThostFtdcVolumeType:" << pLock->Volume << endl;
    cout << "������ TThostFtdcRequestIDType:" << pLock->RequestID << endl;
    cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << pLock->BusinessUnit << endl;
    cout << "�������� TThostFtdcLockTypeType:" << pLock->LockType << endl;
    cout << "����������� TThostFtdcOrderLocalIDType:" << pLock->LockLocalID << endl;
    cout << "���������� TThostFtdcExchangeIDType:" << pLock->ExchangeID << endl;
    cout << "��Ա���� TThostFtdcParticipantIDType:" << pLock->ParticipantID << endl;
    cout << "�ͻ����� TThostFtdcClientIDType:" << pLock->ClientID << endl;
    cout << "��Լ�ڽ������Ĵ��� TThostFtdcExchangeInstIDType:" << pLock->ExchangeInstID << endl;
    cout << "����������Ա���� TThostFtdcTraderIDType:" << pLock->TraderID << endl;
    cout << "��װ��� TThostFtdcInstallIDType:" << pLock->InstallID << endl;
    cout << "ִ�������ύ״̬ TThostFtdcOrderSubmitStatusType:" << pLock->OrderSubmitStatus << endl;
    cout << "������ʾ��� TThostFtdcSequenceNoType:" << pLock->NotifySequence << endl;
    cout << "������ TThostFtdcDateType:" << pLock->TradingDay << endl;
    cout << "������ TThostFtdcSettlementIDType:" << pLock->SettlementID << endl;
    cout << "������� TThostFtdcOrderSysIDType:" << pLock->LockSysID << endl;
    cout << "�������� TThostFtdcDateType:" << pLock->InsertDate << endl;
    cout << "����ʱ�� TThostFtdcTimeType:" << pLock->InsertTime << endl;
    cout << "����ʱ�� TThostFtdcTimeType:" << pLock->CancelTime << endl;
    cout << "����״̬ TThostFtdcOrderActionStatusType:" << pLock->LockStatus << endl;
    cout << "�����Ա��� TThostFtdcParticipantIDType:" << pLock->ClearingPartID << endl;
    cout << "��� TThostFtdcSequenceNoType:" << pLock->SequenceNo << endl;
    cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << pLock->FrontID << endl;
    cout << "�Ự��� TThostFtdcSessionIDType:" << pLock->SessionID << endl;
    cout << "�û��˲�Ʒ��Ϣ TThostFtdcProductInfoType:" << pLock->UserProductInfo << endl;
    cout << "״̬��Ϣ TThostFtdcErrorMsgType:" << pLock->StatusMsg << endl;
    cout << "�����û����� TThostFtdcUserIDType:" << pLock->ActiveUserID << endl;
    cout << "���͹�˾������� TThostFtdcSequenceNoType:" << pLock->BrokerLockSeq << endl;
    cout << "Ӫҵ����� TThostFtdcBranchIDType:" << pLock->BranchID << endl;
}

///��������֪ͨ
void CTraderSpi::OnErrRtnLockInsert(CThostFtdcInputLockField* pInputLock, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pInputLock->BrokerID << endl;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pInputLock->InvestorID << endl;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << pInputLock->InstrumentID << endl;
    cout << "�������� TThostFtdcOrderRefType:" << pInputLock->LockRef << endl;
    cout << "�û����� TThostFtdcUserIDType:" << pInputLock->UserID << endl;
    cout << "���� TThostFtdcVolumeType:" << pInputLock->Volume << endl;
    cout << "������ TThostFtdcRequestIDType:" << pInputLock->RequestID << endl;
    cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << pInputLock->BusinessUnit << endl;
    cout << "�������� TThostFtdcLockTypeType:" << pInputLock->LockType << endl;
    cout << "���������� TThostFtdcExchangeIDType:" << pInputLock->ExchangeID << endl;
}

///�������֪ͨ
void CTraderSpi::OnRtnCombAction(CThostFtdcCombActionField* pCombAction)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pCombAction->BrokerID << endl;
    cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pCombAction->InvestorID << endl;
    cout << "��Լ���� TThostFtdcInstrumentIDType:" << pCombAction->InstrumentID << endl;
    cout << "������� TThostFtdcOrderRefType:" << pCombAction->CombActionRef << endl;
    cout << "�û����� TThostFtdcUserIDType:" << pCombAction->UserID << endl;
    cout << "�������� TThostFtdcDirectionType:" << pCombAction->Direction << endl;
    cout << "���� TThostFtdcVolumeType:" << pCombAction->Volume << endl;
    cout << "���ָ��� TThostFtdcCombDirectionType:" << pCombAction->CombDirection << endl;
    cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pCombAction->HedgeFlag << endl;
    cout << "����������ϱ�� TThostFtdcOrderLocalIDType:" << pCombAction->ActionLocalID << endl;
    cout << "���������� TThostFtdcExchangeIDType:" << pCombAction->ExchangeID << endl;
    cout << "��Ա���� TThostFtdcParticipantIDType:" << pCombAction->ParticipantID << endl;
    cout << "�ͻ����� TThostFtdcClientIDType:" << pCombAction->ClientID << endl;
    cout << "��Լ�ڽ������Ĵ��� TThostFtdcExchangeInstIDType:" << pCombAction->ExchangeInstID << endl;
    cout << "����������Ա���� TThostFtdcTraderIDType:" << pCombAction->TraderID << endl;
    cout << "��װ��� TThostFtdcInstallIDType:" << pCombAction->InstallID << endl;
    cout << "���״̬ TThostFtdcOrderActionStatusType:" << pCombAction->ActionStatus << endl;
    cout << "������ʾ��� TThostFtdcSequenceNoType:" << pCombAction->NotifySequence << endl;
    cout << "������ TThostFtdcDateType:" << pCombAction->TradingDay << endl;
    cout << "������ TThostFtdcSettlementIDType:" << pCombAction->SettlementID << endl;
    cout << "��� TThostFtdcSequenceNoType:" << pCombAction->SequenceNo << endl;
    cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << pCombAction->FrontID << endl;
    cout << "�Ự��� TThostFtdcSessionIDType:" << pCombAction->SessionID << endl;
    cout << "�û��˲�Ʒ��Ϣ TThostFtdcProductInfoType:" << pCombAction->UserProductInfo << endl;
    cout << "״̬��Ϣ TThostFtdcErrorMsgType:" << pCombAction->StatusMsg << endl;
}

///�������¼�����ر�
void CTraderSpi::OnErrRtnCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (!IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pInputCombAction->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pInputCombAction->InvestorID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pInputCombAction->InstrumentID << endl;
	cout << "������� TThostFtdcOrderRefType:" << pInputCombAction->CombActionRef << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pInputCombAction->UserID << endl;
	cout << "�������� TThostFtdcDirectionType:" << pInputCombAction->Direction << endl;
	cout << "���� TThostFtdcVolumeType:" << pInputCombAction->Volume << endl;
	cout << "���ָ��� TThostFtdcCombDirectionType:" << pInputCombAction->CombDirection << endl;
	cout << "Ͷ���ױ���־ TThostFtdcHedgeFlagType:" << pInputCombAction->HedgeFlag << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pInputCombAction->ExchangeID << endl;
    }
}

///�����ѯǩԼ������Ӧ
void CTraderSpi::OnRspQryContractBank(CThostFtdcContractBankField* pContractBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pContractBank->BrokerID << endl;
	cout << "���д��� TThostFtdcBankIDType:" << pContractBank->BankID << endl;
	cout << "���з����Ĵ��� TThostFtdcBankBrchIDType:" << pContractBank->BankBrchID << endl;
	cout << "�������� TThostFtdcBankNameType:" << pContractBank->BankName << endl;
    }
}

///�����ѯԤ����Ӧ
void CTraderSpi::OnRspQryParkedOrder(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pParkedOrder->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pParkedOrder->InvestorID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pParkedOrder->InstrumentID << endl;
	cout << "�������� TThostFtdcOrderRefType:" << pParkedOrder->OrderRef << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pParkedOrder->UserID << endl;
	cout << "�����۸����� TThostFtdcOrderPriceTypeType:" << pParkedOrder->OrderPriceType << endl;
	cout << "�������� TThostFtdcDirectionType:" << pParkedOrder->Direction << endl;
	cout << "��Ͽ�ƽ��־ TThostFtdcCombOffsetFlagType:" << pParkedOrder->CombOffsetFlag << endl;
	cout << "���Ͷ���ױ���־ TThostFtdcCombHedgeFlagType:" << pParkedOrder->CombHedgeFlag << endl;
	cout << "�۸� TThostFtdcPriceType:" << pParkedOrder->LimitPrice << endl;
	cout << "���� TThostFtdcVolumeType:" << pParkedOrder->VolumeTotalOriginal << endl;
	cout << "��Ч������ TThostFtdcTimeConditionType:" << pParkedOrder->TimeCondition << endl;
	cout << "���� TThostFtdcDateType:" << pParkedOrder->GTDDate << endl;
	cout << "�ɽ������� TThostFtdcVolumeConditionType:" << pParkedOrder->VolumeCondition << endl;
	cout << "��С�ɽ��� TThostFtdcVolumeType:" << pParkedOrder->MinVolume << endl;
	cout << "�������� TThostFtdcContingentConditionType:" << pParkedOrder->ContingentCondition << endl;
	cout << "ֹ��� TThostFtdcPriceType:" << pParkedOrder->StopPrice << endl;
	cout << "ǿƽԭ�� TThostFtdcForceCloseReasonType:" << pParkedOrder->ForceCloseReason << endl;
	cout << "�Զ������־ TThostFtdcBoolType:" << pParkedOrder->IsAutoSuspend << endl;
	cout << "ҵ��Ԫ TThostFtdcBusinessUnitType:" << pParkedOrder->BusinessUnit << endl;
	cout << "������ TThostFtdcRequestIDType:" << pParkedOrder->RequestID << endl;
	cout << "�û�ǿ����־ TThostFtdcBoolType:" << pParkedOrder->UserForceClose << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pParkedOrder->ExchangeID << endl;
	cout << "Ԥ�񱨵���� TThostFtdcParkedOrderIDType:" << pParkedOrder->ParkedOrderID << endl;
	cout << "�û����� TThostFtdcUserTypeType:" << pParkedOrder->UserType << endl;
	cout << "Ԥ��״̬ TThostFtdcParkedOrderStatusType:" << pParkedOrder->Status << endl;
	cout << "������� TThostFtdcErrorIDType:" << pParkedOrder->ErrorID << endl;
	cout << "������Ϣ TThostFtdcErrorMsgType:" << pParkedOrder->ErrorMsg << endl;
	cout << "��������־ TThostFtdcBoolType:" << pParkedOrder->IsSwapOrder << endl;
    }
}

///�����ѯԤ�񳷵���Ӧ
void CTraderSpi::OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pParkedOrderAction->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pParkedOrderAction->InvestorID << endl;
	cout << "������������ TThostFtdcOrderActionRefType:" << pParkedOrderAction->OrderActionRef << endl;
	cout << "�������� TThostFtdcOrderRefType:" << pParkedOrderAction->OrderRef << endl;
	cout << "������ TThostFtdcRequestIDType:" << pParkedOrderAction->RequestID << endl;
	cout << "ǰ�ñ�� TThostFtdcFrontIDType:" << pParkedOrderAction->FrontID << endl;
	cout << "�Ự��� TThostFtdcSessionIDType:" << pParkedOrderAction->SessionID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pParkedOrderAction->ExchangeID << endl;
	cout << "������� TThostFtdcOrderSysIDType:" << pParkedOrderAction->OrderSysID << endl;
	cout << "������־ TThostFtdcActionFlagType:" << pParkedOrderAction->ActionFlag << endl;
	cout << "�۸� TThostFtdcPriceType:" << pParkedOrderAction->LimitPrice << endl;
	cout << "�����仯 TThostFtdcVolumeType:" << pParkedOrderAction->VolumeChange << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pParkedOrderAction->UserID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pParkedOrderAction->InstrumentID << endl;
	cout << "Ԥ�񳷵������ TThostFtdcParkedOrderActionIDType:" << pParkedOrderAction->ParkedOrderActionID << endl;
	cout << "�û����� TThostFtdcUserTypeType:" << pParkedOrderAction->UserType << endl;
	cout << "Ԥ�񳷵�״̬ TThostFtdcParkedOrderStatusType:" << pParkedOrderAction->Status << endl;
	cout << "������� TThostFtdcErrorIDType:" << pParkedOrderAction->ErrorID << endl;
	cout << "������Ϣ TThostFtdcErrorMsgType:" << pParkedOrderAction->ErrorMsg << endl;
    }
}

///�����ѯ����֪ͨ��Ӧ
void CTraderSpi::OnRspQryTradingNotice(CThostFtdcTradingNoticeField* pTradingNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pTradingNotice->BrokerID << endl;
	cout << "Ͷ���߷�Χ TThostFtdcInvestorRangeType:" << pTradingNotice->InvestorRange << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pTradingNotice->InvestorID << endl;
	cout << "����ϵ�к� TThostFtdcSequenceSeriesType:" << pTradingNotice->SequenceSeries << endl;
	cout << "�û����� TThostFtdcUserIDType:" << pTradingNotice->UserID << endl;
	cout << "����ʱ�� TThostFtdcTimeType:" << pTradingNotice->SendTime << endl;
	cout << "���к� TThostFtdcSequenceNoType:" << pTradingNotice->SequenceNo << endl;
	cout << "��Ϣ���� TThostFtdcContentType:" << pTradingNotice->FieldContent << endl;
    }
}

///�����ѯ���͹�˾���ײ�����Ӧ
void CTraderSpi::OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField* pBrokerTradingParams, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pBrokerTradingParams->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pBrokerTradingParams->InvestorID << endl;
	cout << "��֤��۸����� TThostFtdcMarginPriceTypeType:" << pBrokerTradingParams->MarginPriceType << endl;
	cout << "ӯ���㷨 TThostFtdcAlgorithmType:" << pBrokerTradingParams->Algorithm << endl;
	cout << "�����Ƿ����ƽ��ӯ�� TThostFtdcIncludeCloseProfitType:" << pBrokerTradingParams->AvailIncludeCloseProfit << endl;
	cout << "���ִ��� TThostFtdcCurrencyIDType:" << pBrokerTradingParams->CurrencyID << endl;
	cout << "��ȨȨ����۸����� TThostFtdcOptionRoyaltyPriceTypeType:" << pBrokerTradingParams->OptionRoyaltyPriceType << endl;
    }
}

///�����ѯ���͹�˾�����㷨��Ӧ
void CTraderSpi::OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField* pBrokerTradingAlgos, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pBrokerTradingAlgos->BrokerID << endl;
	cout << "���������� TThostFtdcExchangeIDType:" << pBrokerTradingAlgos->ExchangeID << endl;
	cout << "��Լ���� TThostFtdcInstrumentIDType:" << pBrokerTradingAlgos->InstrumentID << endl;
	cout << "�ֲִ����㷨��� TThostFtdcHandlePositionAlgoIDType:" << pBrokerTradingAlgos->HandlePositionAlgoID << endl;
	cout << "Ѱ�ұ�֤�����㷨��� TThostFtdcFindMarginRateAlgoIDType:" << pBrokerTradingAlgos->FindMarginRateAlgoID << endl;
	cout << "�ʽ����㷨��� TThostFtdcHandleTradingAccountAlgoIDType:" << pBrokerTradingAlgos->HandleTradingAccountAlgoID << endl;
    }
}

///�����ѯ��������û�����
void CTraderSpi::OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pQueryCFMMCTradingAccountToken->BrokerID << endl;
	cout << "Ͷ���ߴ��� TThostFtdcInvestorIDType:" << pQueryCFMMCTradingAccountToken->InvestorID << endl;
    }
}

///���з��������ʽ�ת�ڻ�֪ͨ
void CTraderSpi::OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField* pRspTransfer)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "ҵ������ TThostFtdcTradeCodeType:" << pRspTransfer->TradeCode << endl;
    cout << "���д��� TThostFtdcBankIDType:" << pRspTransfer->BankID << endl;
    cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << pRspTransfer->BankBranchID << endl;
    cout << "���̴��� TThostFtdcBrokerIDType:" << pRspTransfer->BrokerID << endl;
    cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << pRspTransfer->BrokerBranchID << endl;
    cout << "�������� TThostFtdcTradeDateType:" << pRspTransfer->TradeDate << endl;
    cout << "����ʱ�� TThostFtdcTradeTimeType:" << pRspTransfer->TradeTime << endl;
    cout << "������ˮ�� TThostFtdcBankSerialType:" << pRspTransfer->BankSerial << endl;
    cout << "����ϵͳ���� TThostFtdcTradeDateType:" << pRspTransfer->TradingDay << endl;
    cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << pRspTransfer->PlateSerial << endl;
    cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << pRspTransfer->LastFragment << endl;
    cout << "�Ự�� TThostFtdcSessionIDType:" << pRspTransfer->SessionID << endl;
    cout << "�ͻ����� TThostFtdcIndividualNameType:" << pRspTransfer->CustomerName << endl;
    cout << "֤������ TThostFtdcIdCardTypeType:" << pRspTransfer->IdCardType << endl;
    cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pRspTransfer->IdentifiedCardNo << endl;
    cout << "�ͻ����� TThostFtdcCustTypeType:" << pRspTransfer->CustType << endl;
    cout << "�����ʺ� TThostFtdcBankAccountType:" << pRspTransfer->BankAccount << endl;
    cout << "�������� TThostFtdcPasswordType:" << pRspTransfer->BankPassWord << endl;
    cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pRspTransfer->AccountID << endl;
    cout << "�ڻ����� TThostFtdcPasswordType:" << pRspTransfer->Password << endl;
    cout << "��װ��� TThostFtdcInstallIDType:" << pRspTransfer->InstallID << endl;
    cout << "�ڻ���˾��ˮ�� TThostFtdcFutureSerialType:" << pRspTransfer->FutureSerial << endl;
    cout << "�û���ʶ TThostFtdcUserIDType:" << pRspTransfer->UserID << endl;
    cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << pRspTransfer->VerifyCertNoFlag << endl;
    cout << "���ִ��� TThostFtdcCurrencyIDType:" << pRspTransfer->CurrencyID << endl;
    cout << "ת�ʽ�� TThostFtdcTradeAmountType:" << pRspTransfer->TradeAmount << endl;
    cout << "�ڻ���ȡ��� TThostFtdcTradeAmountType:" << pRspTransfer->FutureFetchAmount << endl;
    cout << "����֧����־ TThostFtdcFeePayFlagType:" << pRspTransfer->FeePayFlag << endl;
    cout << "Ӧ�տͻ����� TThostFtdcCustFeeType:" << pRspTransfer->CustFee << endl;
    cout << "Ӧ���ڻ���˾���� TThostFtdcFutureFeeType:" << pRspTransfer->BrokerFee << endl;
    cout << "���ͷ������շ�����Ϣ TThostFtdcAddInfoType:" << pRspTransfer->Message << endl;
    cout << "ժҪ TThostFtdcDigestType:" << pRspTransfer->Digest << endl;
    cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << pRspTransfer->BankAccType << endl;
    cout << "������־ TThostFtdcDeviceIDType:" << pRspTransfer->DeviceID << endl;
    cout << "�ڻ���λ�ʺ����� TThostFtdcBankAccTypeType:" << pRspTransfer->BankSecuAccType << endl;
    cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << pRspTransfer->BrokerIDByBank << endl;
    cout << "�ڻ���λ�ʺ� TThostFtdcBankAccountType:" << pRspTransfer->BankSecuAcc << endl;
    cout << "���������־ TThostFtdcPwdFlagType:" << pRspTransfer->BankPwdFlag << endl;
    cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << pRspTransfer->SecuPwdFlag << endl;
    cout << "���׹�Ա TThostFtdcOperNoType:" << pRspTransfer->OperNo << endl;
    cout << "������ TThostFtdcRequestIDType:" << pRspTransfer->RequestID << endl;
    // cout << "����ID:" << pRspTransfer->TThostFtdcTIDType << endlTID;
    cout << "ת�˽���״̬ TThostFtdcTransferStatusType:" << pRspTransfer->TransferStatus << endl;
    cout << "������� TThostFtdcErrorIDType:" << pRspTransfer->ErrorID << endl;
    cout << "������Ϣ TThostFtdcErrorMsgType:" << pRspTransfer->ErrorMsg << endl;
}

///���з����ڻ��ʽ�ת����֪ͨ
void CTraderSpi::OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField* pRspTransfer)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "ҵ������ TThostFtdcTradeCodeType:" << pRspTransfer->TradeCode << endl;
    cout << "���д��� TThostFtdcBankIDType:" << pRspTransfer->BankID << endl;
    cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << pRspTransfer->BankBranchID << endl;
    cout << "���̴��� TThostFtdcBrokerIDType:" << pRspTransfer->BrokerID << endl;
    cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << pRspTransfer->BrokerBranchID << endl;
    cout << "�������� TThostFtdcTradeDateType:" << pRspTransfer->TradeDate << endl;
    cout << "����ʱ�� TThostFtdcTradeTimeType:" << pRspTransfer->TradeTime << endl;
    cout << "������ˮ�� TThostFtdcBankSerialType:" << pRspTransfer->BankSerial << endl;
    cout << "����ϵͳ���� TThostFtdcTradeDateType:" << pRspTransfer->TradingDay << endl;
    cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << pRspTransfer->PlateSerial << endl;
    cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << pRspTransfer->LastFragment << endl;
    cout << "�Ự�� TThostFtdcSessionIDType:" << pRspTransfer->SessionID << endl;
    cout << "�ͻ����� TThostFtdcIndividualNameType:" << pRspTransfer->CustomerName << endl;
    cout << "֤������ TThostFtdcIdCardTypeType:" << pRspTransfer->IdCardType << endl;
    cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pRspTransfer->IdentifiedCardNo << endl;
    cout << "�ͻ����� TThostFtdcCustTypeType:" << pRspTransfer->CustType << endl;
    cout << "�����ʺ� TThostFtdcBankAccountType:" << pRspTransfer->BankAccount << endl;
    cout << "�������� TThostFtdcPasswordType:" << pRspTransfer->BankPassWord << endl;
    cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pRspTransfer->AccountID << endl;
    cout << "�ڻ����� TThostFtdcPasswordType:" << pRspTransfer->Password << endl;
    cout << "��װ��� TThostFtdcInstallIDType:" << pRspTransfer->InstallID << endl;
    cout << "�ڻ���˾��ˮ�� TThostFtdcFutureSerialType:" << pRspTransfer->FutureSerial << endl;
    cout << "�û���ʶ TThostFtdcUserIDType:" << pRspTransfer->UserID << endl;
    cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << pRspTransfer->VerifyCertNoFlag << endl;
    cout << "���ִ��� TThostFtdcCurrencyIDType:" << pRspTransfer->CurrencyID << endl;
    cout << "ת�ʽ�� TThostFtdcTradeAmountType:" << pRspTransfer->TradeAmount << endl;
    cout << "�ڻ���ȡ��� TThostFtdcTradeAmountType:" << pRspTransfer->FutureFetchAmount << endl;
    cout << "����֧����־ TThostFtdcFeePayFlagType:" << pRspTransfer->FeePayFlag << endl;
    cout << "Ӧ�տͻ����� TThostFtdcCustFeeType:" << pRspTransfer->CustFee << endl;
    cout << "Ӧ���ڻ���˾���� TThostFtdcFutureFeeType:" << pRspTransfer->BrokerFee << endl;
    cout << "���ͷ������շ�����Ϣ TThostFtdcAddInfoType:" << pRspTransfer->Message << endl;
    cout << "ժҪ TThostFtdcDigestType:" << pRspTransfer->Digest << endl;
    cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << pRspTransfer->BankAccType << endl;
    cout << "������־ TThostFtdcDeviceIDType:" << pRspTransfer->DeviceID << endl;
    cout << "�ڻ���λ�ʺ����� TThostFtdcBankAccTypeType:" << pRspTransfer->BankSecuAccType << endl;
    cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << pRspTransfer->BrokerIDByBank << endl;
    cout << "�ڻ���λ�ʺ� TThostFtdcBankAccountType:" << pRspTransfer->BankSecuAcc << endl;
    cout << "���������־ TThostFtdcPwdFlagType:" << pRspTransfer->BankPwdFlag << endl;
    cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << pRspTransfer->SecuPwdFlag << endl;
    cout << "���׹�Ա TThostFtdcOperNoType:" << pRspTransfer->OperNo << endl;
    cout << "������ TThostFtdcRequestIDType:" << pRspTransfer->RequestID << endl;
    // cout << "����ID:" << pRspTransfer->TThostFtdcTIDType << endlTID;
    cout << "ת�˽���״̬ TThostFtdcTransferStatusType:" << pRspTransfer->TransferStatus << endl;
    cout << "������� TThostFtdcErrorIDType:" << pRspTransfer->ErrorID << endl;
    cout << "������Ϣ TThostFtdcErrorMsgType:" << pRspTransfer->ErrorMsg << endl;
}

///���з����������ת�ڻ�֪ͨ
void CTraderSpi::OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField* pRspRepeal)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "����ʱ���� TThostFtdcRepealTimeIntervalType:" << pRspRepeal->RepealTimeInterval << endl;
    cout << "�Ѿ��������� TThostFtdcRepealedTimesType:" << pRspRepeal->RepealedTimes << endl;
    cout << "���г�����־ TThostFtdcBankRepealFlagType:" << pRspRepeal->BankRepealFlag << endl;
    cout << "���̳�����־ TThostFtdcBrokerRepealFlagType:" << pRspRepeal->BrokerRepealFlag << endl;
    cout << "������ƽ̨��ˮ�� TThostFtdcPlateSerialType:" << pRspRepeal->PlateRepealSerial << endl;
    cout << "������������ˮ�� TThostFtdcBankSerialType:" << pRspRepeal->BankRepealSerial << endl;
    cout << "�������ڻ���ˮ�� TThostFtdcFutureSerialType:" << pRspRepeal->FutureRepealSerial << endl;
    cout << "ҵ������ TThostFtdcTradeCodeType:" << pRspRepeal->TradeCode << endl;
    cout << "���д��� TThostFtdcBankIDType:" << pRspRepeal->BankID << endl;
    cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << pRspRepeal->BankBranchID << endl;
    cout << "���̴��� TThostFtdcBrokerIDType:" << pRspRepeal->BrokerID << endl;
    cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << pRspRepeal->BrokerBranchID << endl;
    cout << "�������� TThostFtdcTradeDateType:" << pRspRepeal->TradeDate << endl;
    cout << "����ʱ�� TThostFtdcTradeTimeType:" << pRspRepeal->TradeTime << endl;
    cout << "������ˮ�� TThostFtdcBankSerialType:" << pRspRepeal->BankSerial << endl;
    cout << "����ϵͳ���� TThostFtdcTradeDateType:" << pRspRepeal->TradingDay << endl;
    cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << pRspRepeal->PlateSerial << endl;
    cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << pRspRepeal->LastFragment << endl;
    cout << "�Ự�� TThostFtdcSessionIDType:" << pRspRepeal->SessionID << endl;
    cout << "�ͻ����� TThostFtdcIndividualNameType:" << pRspRepeal->CustomerName << endl;
    cout << "֤������ TThostFtdcIdCardTypeType:" << pRspRepeal->IdCardType << endl;
    cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pRspRepeal->IdentifiedCardNo << endl;
    cout << "�ͻ����� TThostFtdcCustTypeType:" << pRspRepeal->CustType << endl;
    cout << "�����ʺ� TThostFtdcBankAccountType:" << pRspRepeal->BankAccount << endl;
    cout << "�������� TThostFtdcPasswordType:" << pRspRepeal->BankPassWord << endl;
    cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pRspRepeal->AccountID << endl;
    cout << "�ڻ����� TThostFtdcPasswordType:" << pRspRepeal->Password << endl;
    cout << "��װ��� TThostFtdcInstallIDType:" << pRspRepeal->InstallID << endl;
    cout << "�ڻ���˾��ˮ�� TThostFtdcFutureSerialType:" << pRspRepeal->FutureSerial << endl;
    cout << "�û���ʶ TThostFtdcUserIDType:" << pRspRepeal->UserID << endl;
    cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << pRspRepeal->VerifyCertNoFlag << endl;
    cout << "���ִ��� TThostFtdcCurrencyIDType:" << pRspRepeal->CurrencyID << endl;
    cout << "ת�ʽ�� TThostFtdcTradeAmountType:" << pRspRepeal->TradeAmount << endl;
    cout << "�ڻ���ȡ��� TThostFtdcTradeAmountType:" << pRspRepeal->FutureFetchAmount << endl;
    cout << "����֧����־ TThostFtdcFeePayFlagType:" << pRspRepeal->FeePayFlag << endl;
    cout << "Ӧ�տͻ����� TThostFtdcCustFeeType:" << pRspRepeal->CustFee << endl;
    cout << "Ӧ���ڻ���˾���� TThostFtdcFutureFeeType:" << pRspRepeal->BrokerFee << endl;
    cout << "���ͷ������շ�����Ϣ TThostFtdcAddInfoType:" << pRspRepeal->Message << endl;
    cout << "ժҪ TThostFtdcDigestType:" << pRspRepeal->Digest << endl;
    cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << pRspRepeal->BankAccType << endl;
    cout << "������־ TThostFtdcDeviceIDType:" << pRspRepeal->DeviceID << endl;
    cout << "�ڻ���λ�ʺ����� TThostFtdcBankAccTypeType:" << pRspRepeal->BankSecuAccType << endl;
    cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << pRspRepeal->BrokerIDByBank << endl;
    cout << "�ڻ���λ�ʺ� TThostFtdcBankAccountType:" << pRspRepeal->BankSecuAcc << endl;
    cout << "���������־ TThostFtdcPwdFlagType:" << pRspRepeal->BankPwdFlag << endl;
    cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << pRspRepeal->SecuPwdFlag << endl;
    cout << "���׹�Ա TThostFtdcOperNoType:" << pRspRepeal->OperNo << endl;
    cout << "������ TThostFtdcRequestIDType:" << pRspRepeal->RequestID << endl;
    // cout << "����ID:" << pRspRepeal->TThostFtdcTIDType << endlTID;
    cout << "ת�˽���״̬ TThostFtdcTransferStatusType:" << pRspRepeal->TransferStatus << endl;
    cout << "������� TThostFtdcErrorIDType:" << pRspRepeal->ErrorID << endl;
    cout << "������Ϣ TThostFtdcErrorMsgType:" << pRspRepeal->ErrorMsg << endl;
}

///���з�������ڻ�ת����֪ͨ
void CTraderSpi::OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField* pRspRepeal)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "����ʱ���� TThostFtdcRepealTimeIntervalType:" << pRspRepeal->RepealTimeInterval << endl;
    cout << "�Ѿ��������� TThostFtdcRepealedTimesType:" << pRspRepeal->RepealedTimes << endl;
    cout << "���г�����־ TThostFtdcBankRepealFlagType:" << pRspRepeal->BankRepealFlag << endl;
    cout << "���̳�����־ TThostFtdcBrokerRepealFlagType:" << pRspRepeal->BrokerRepealFlag << endl;
    cout << "������ƽ̨��ˮ�� TThostFtdcPlateSerialType:" << pRspRepeal->PlateRepealSerial << endl;
    cout << "������������ˮ�� TThostFtdcBankSerialType:" << pRspRepeal->BankRepealSerial << endl;
    cout << "�������ڻ���ˮ�� TThostFtdcFutureSerialType:" << pRspRepeal->FutureRepealSerial << endl;
    cout << "ҵ������ TThostFtdcTradeCodeType:" << pRspRepeal->TradeCode << endl;
    cout << "���д��� TThostFtdcBankIDType:" << pRspRepeal->BankID << endl;
    cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << pRspRepeal->BankBranchID << endl;
    cout << "���̴��� TThostFtdcBrokerIDType:" << pRspRepeal->BrokerID << endl;
    cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << pRspRepeal->BrokerBranchID << endl;
    cout << "�������� TThostFtdcTradeDateType:" << pRspRepeal->TradeDate << endl;
    cout << "����ʱ�� TThostFtdcTradeTimeType:" << pRspRepeal->TradeTime << endl;
    cout << "������ˮ�� TThostFtdcBankSerialType:" << pRspRepeal->BankSerial << endl;
    cout << "����ϵͳ���� TThostFtdcTradeDateType:" << pRspRepeal->TradingDay << endl;
    cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << pRspRepeal->PlateSerial << endl;
    cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << pRspRepeal->LastFragment << endl;
    cout << "�Ự�� TThostFtdcSessionIDType:" << pRspRepeal->SessionID << endl;
    cout << "�ͻ����� TThostFtdcIndividualNameType:" << pRspRepeal->CustomerName << endl;
    cout << "֤������ TThostFtdcIdCardTypeType:" << pRspRepeal->IdCardType << endl;
    cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pRspRepeal->IdentifiedCardNo << endl;
    cout << "�ͻ����� TThostFtdcCustTypeType:" << pRspRepeal->CustType << endl;
    cout << "�����ʺ� TThostFtdcBankAccountType:" << pRspRepeal->BankAccount << endl;
    cout << "�������� TThostFtdcPasswordType:" << pRspRepeal->BankPassWord << endl;
    cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pRspRepeal->AccountID << endl;
    cout << "�ڻ����� TThostFtdcPasswordType:" << pRspRepeal->Password << endl;
    cout << "��װ��� TThostFtdcInstallIDType:" << pRspRepeal->InstallID << endl;
    cout << "�ڻ���˾��ˮ�� TThostFtdcFutureSerialType:" << pRspRepeal->FutureSerial << endl;
    cout << "�û���ʶ TThostFtdcUserIDType:" << pRspRepeal->UserID << endl;
    cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << pRspRepeal->VerifyCertNoFlag << endl;
    cout << "���ִ��� TThostFtdcCurrencyIDType:" << pRspRepeal->CurrencyID << endl;
    cout << "ת�ʽ�� TThostFtdcTradeAmountType:" << pRspRepeal->TradeAmount << endl;
    cout << "�ڻ���ȡ��� TThostFtdcTradeAmountType:" << pRspRepeal->FutureFetchAmount << endl;
    cout << "����֧����־ TThostFtdcFeePayFlagType:" << pRspRepeal->FeePayFlag << endl;
    cout << "Ӧ�տͻ����� TThostFtdcCustFeeType:" << pRspRepeal->CustFee << endl;
    cout << "Ӧ���ڻ���˾���� TThostFtdcFutureFeeType:" << pRspRepeal->BrokerFee << endl;
    cout << "���ͷ������շ�����Ϣ TThostFtdcAddInfoType:" << pRspRepeal->Message << endl;
    cout << "ժҪ TThostFtdcDigestType:" << pRspRepeal->Digest << endl;
    cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << pRspRepeal->BankAccType << endl;
    cout << "������ TThostFtdcDeviceIDType:" << pRspRepeal->DeviceID << endl;
    cout << "�ڻ���λ�ʺ����� TThostFtdcBankAccTypeType:" << pRspRepeal->BankSecuAccType << endl;
    cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << pRspRepeal->BrokerIDByBank << endl;
    cout << "�ڻ���λ�ʺ� TThostFtdcBankAccountType:" << pRspRepeal->BankSecuAcc << endl;
    cout << "���������־ TThostFtdcPwdFlagType:" << pRspRepeal->BankPwdFlag << endl;
    cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << pRspRepeal->SecuPwdFlag << endl;
    cout << "���׹�Ա TThostFtdcOperNoType:" << pRspRepeal->OperNo << endl;
    cout << "������ TThostFtdcRequestIDType:" << pRspRepeal->RequestID << endl;
    cout << "���� TThostFtdcTIDType:" << pRspRepeal->TID << endl;
    cout << "ת�˽���״̬ TThostFtdcTransferStatusType:" << pRspRepeal->TransferStatus << endl;
    cout << "������� TThostFtdcErrorIDType:" << pRspRepeal->ErrorID << endl;
    cout << "������Ϣ TThostFtdcErrorMsgType:" << pRspRepeal->ErrorMsg << endl;
}

///�ڻ����������ʽ�ת�ڻ�֪ͨ
void CTraderSpi::OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField* pRspTransfer)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "ҵ������ TThostFtdcTradeCodeType:" << pRspTransfer->TradeCode << endl;
    cout << "���д��� TThostFtdcBankIDType:" << pRspTransfer->BankID << endl;
    cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << pRspTransfer->BankBranchID << endl;
    cout << "���̴��� TThostFtdcBrokerIDType:" << pRspTransfer->BrokerID << endl;
    cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << pRspTransfer->BrokerBranchID << endl;
    cout << "�������� TThostFtdcTradeDateType:" << pRspTransfer->TradeDate << endl;
    cout << "����ʱ�� TThostFtdcTradeTimeType:" << pRspTransfer->TradeTime << endl;
    cout << "������ˮ�� TThostFtdcBankSerialType:" << pRspTransfer->BankSerial << endl;
    cout << "����ϵͳ���� TThostFtdcTradeDateType:" << pRspTransfer->TradingDay << endl;
    cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << pRspTransfer->PlateSerial << endl;
    cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << pRspTransfer->LastFragment << endl;
    cout << "�Ự�� TThostFtdcSessionIDType:" << pRspTransfer->SessionID << endl;
    cout << "�ͻ����� TThostFtdcIndividualNameType:" << pRspTransfer->CustomerName << endl;
    cout << "֤������ TThostFtdcIdCardTypeType:" << pRspTransfer->IdCardType << endl;
    cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pRspTransfer->IdentifiedCardNo << endl;
    cout << "�ͻ����� TThostFtdcCustTypeType:" << pRspTransfer->CustType << endl;
    cout << "�����ʺ� TThostFtdcBankAccountType:" << pRspTransfer->BankAccount << endl;
    cout << "�������� TThostFtdcPasswordType:" << pRspTransfer->BankPassWord << endl;
    cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pRspTransfer->AccountID << endl;
    cout << "�ڻ����� TThostFtdcPasswordType:" << pRspTransfer->Password << endl;
    cout << "��װ��� TThostFtdcInstallIDType:" << pRspTransfer->InstallID << endl;
    cout << "�ڻ���˾��ˮ�� TThostFtdcFutureSerialType:" << pRspTransfer->FutureSerial << endl;
    cout << "�û���ʶ TThostFtdcUserIDType:" << pRspTransfer->UserID << endl;
    cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << pRspTransfer->VerifyCertNoFlag << endl;
    cout << "���ִ��� TThostFtdcCurrencyIDType:" << pRspTransfer->CurrencyID << endl;
    cout << "ת�ʽ�� TThostFtdcTradeAmountType:" << pRspTransfer->TradeAmount << endl;
    cout << "�ڻ���ȡ��� TThostFtdcTradeAmountType:" << pRspTransfer->FutureFetchAmount << endl;
    cout << "����֧����־ TThostFtdcFeePayFlagType:" << pRspTransfer->FeePayFlag << endl;
    cout << "Ӧ�տͻ����� TThostFtdcCustFeeType:" << pRspTransfer->CustFee << endl;
    cout << "Ӧ���ڻ���˾���� TThostFtdcFutureFeeType:" << pRspTransfer->BrokerFee << endl;
    cout << "���ͷ������շ�����Ϣ TThostFtdcAddInfoType:" << pRspTransfer->Message << endl;
    cout << "ժҪ TThostFtdcDigestType:" << pRspTransfer->Digest << endl;
    cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << pRspTransfer->BankAccType << endl;
    cout << "������־ TThostFtdcDeviceIDType:" << pRspTransfer->DeviceID << endl;
    cout << "�ڻ���λ�ʺ����� TThostFtdcBankAccTypeType:" << pRspTransfer->BankSecuAccType << endl;
    cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << pRspTransfer->BrokerIDByBank << endl;
    cout << "�ڻ���λ�ʺ� TThostFtdcBankAccountType:" << pRspTransfer->BankSecuAcc << endl;
    cout << "���������־ TThostFtdcPwdFlagType:" << pRspTransfer->BankPwdFlag << endl;
    cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << pRspTransfer->SecuPwdFlag << endl;
    cout << "���׹�Ա TThostFtdcOperNoType:" << pRspTransfer->OperNo << endl;
    cout << "������ TThostFtdcRequestIDType:" << pRspTransfer->RequestID << endl;
    // cout << "����ID:" << pRspTransfer->TThostFtdcTIDType << endlTID;
    cout << "ת�˽���״̬ TThostFtdcTransferStatusType:" << pRspTransfer->TransferStatus << endl;
    cout << "������� TThostFtdcErrorIDType:" << pRspTransfer->ErrorID << endl;
    cout << "������Ϣ TThostFtdcErrorMsgType:" << pRspTransfer->ErrorMsg << endl;
}

///�ڻ������ڻ��ʽ�ת����֪ͨ
void CTraderSpi::OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField* pRspTransfer)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "ҵ������ TThostFtdcTradeCodeType:" << pRspTransfer->TradeCode << endl;
    cout << "���д��� TThostFtdcBankIDType:" << pRspTransfer->BankID << endl;
    cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << pRspTransfer->BankBranchID << endl;
    cout << "���̴��� TThostFtdcBrokerIDType:" << pRspTransfer->BrokerID << endl;
    cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << pRspTransfer->BrokerBranchID << endl;
    cout << "�������� TThostFtdcTradeDateType:" << pRspTransfer->TradeDate << endl;
    cout << "����ʱ�� TThostFtdcTradeTimeType:" << pRspTransfer->TradeTime << endl;
    cout << "������ˮ�� TThostFtdcBankSerialType:" << pRspTransfer->BankSerial << endl;
    cout << "����ϵͳ���� TThostFtdcTradeDateType:" << pRspTransfer->TradingDay << endl;
    cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << pRspTransfer->PlateSerial << endl;
    cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << pRspTransfer->LastFragment << endl;
    cout << "�Ự�� TThostFtdcSessionIDType:" << pRspTransfer->SessionID << endl;
    cout << "�ͻ����� TThostFtdcIndividualNameType:" << pRspTransfer->CustomerName << endl;
    cout << "֤������ TThostFtdcIdCardTypeType:" << pRspTransfer->IdCardType << endl;
    cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pRspTransfer->IdentifiedCardNo << endl;
    cout << "�ͻ����� TThostFtdcCustTypeType:" << pRspTransfer->CustType << endl;
    cout << "�����ʺ� TThostFtdcBankAccountType:" << pRspTransfer->BankAccount << endl;
    cout << "�������� TThostFtdcPasswordType:" << pRspTransfer->BankPassWord << endl;
    cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pRspTransfer->AccountID << endl;
    cout << "�ڻ����� TThostFtdcPasswordType:" << pRspTransfer->Password << endl;
    cout << "��װ��� TThostFtdcInstallIDType:" << pRspTransfer->InstallID << endl;
    cout << "�ڻ���˾��ˮ�� TThostFtdcFutureSerialType:" << pRspTransfer->FutureSerial << endl;
    cout << "�û���ʶ TThostFtdcUserIDType:" << pRspTransfer->UserID << endl;
    cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << pRspTransfer->VerifyCertNoFlag << endl;
    cout << "���ִ��� TThostFtdcCurrencyIDType:" << pRspTransfer->CurrencyID << endl;
    cout << "ת�ʽ�� TThostFtdcTradeAmountType:" << pRspTransfer->TradeAmount << endl;
    cout << "�ڻ���ȡ��� TThostFtdcTradeAmountType:" << pRspTransfer->FutureFetchAmount << endl;
    cout << "����֧����־ TThostFtdcFeePayFlagType:" << pRspTransfer->FeePayFlag << endl;
    cout << "Ӧ�տͻ����� TThostFtdcCustFeeType:" << pRspTransfer->CustFee << endl;
    cout << "Ӧ���ڻ���˾���� TThostFtdcFutureFeeType:" << pRspTransfer->BrokerFee << endl;
    cout << "���ͷ������շ�����Ϣ TThostFtdcAddInfoType:" << pRspTransfer->Message << endl;
    cout << "ժҪ TThostFtdcDigestType:" << pRspTransfer->Digest << endl;
    cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << pRspTransfer->BankAccType << endl;
    cout << "������־ TThostFtdcDeviceIDType:" << pRspTransfer->DeviceID << endl;
    cout << "�ڻ���λ�ʺ����� TThostFtdcBankAccTypeType:" << pRspTransfer->BankSecuAccType << endl;
    cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << pRspTransfer->BrokerIDByBank << endl;
    cout << "�ڻ���λ�ʺ� TThostFtdcBankAccountType:" << pRspTransfer->BankSecuAcc << endl;
    cout << "���������־ TThostFtdcPwdFlagType:" << pRspTransfer->BankPwdFlag << endl;
    cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << pRspTransfer->SecuPwdFlag << endl;
    cout << "���׹�Ա TThostFtdcOperNoType:" << pRspTransfer->OperNo << endl;
    cout << "������ TThostFtdcRequestIDType:" << pRspTransfer->RequestID << endl;
    // cout << "����ID:" << pRspTransfer->TThostFtdcTIDType << endlTID;
    cout << "ת�˽���״̬ TThostFtdcTransferStatusType:" << pRspTransfer->TransferStatus << endl;
    cout << "������� TThostFtdcErrorIDType:" << pRspTransfer->ErrorID << endl;
    cout << "������Ϣ TThostFtdcErrorMsgType:" << pRspTransfer->ErrorMsg << endl;
}

///ϵͳ����ʱ�ڻ����ֹ������������ת�ڻ��������д�����Ϻ��̷��ص�֪ͨ
void CTraderSpi::OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField* pRspRepeal)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "����ʱ���� TThostFtdcRepealTimeIntervalType:" << pRspRepeal->RepealTimeInterval << endl;
    cout << "�Ѿ��������� TThostFtdcRepealedTimesType:" << pRspRepeal->RepealedTimes << endl;
    cout << "���г�����־ TThostFtdcBankRepealFlagType:" << pRspRepeal->BankRepealFlag << endl;
    cout << "���̳�����־ TThostFtdcBrokerRepealFlagType:" << pRspRepeal->BrokerRepealFlag << endl;
    cout << "������ƽ̨��ˮ�� TThostFtdcPlateSerialType:" << pRspRepeal->PlateRepealSerial << endl;
    cout << "������������ˮ�� TThostFtdcBankSerialType:" << pRspRepeal->BankRepealSerial << endl;
    cout << "�������ڻ���ˮ�� TThostFtdcFutureSerialType:" << pRspRepeal->FutureRepealSerial << endl;
    cout << "ҵ������ TThostFtdcTradeCodeType:" << pRspRepeal->TradeCode << endl;
    cout << "���д��� TThostFtdcBankIDType:" << pRspRepeal->BankID << endl;
    cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << pRspRepeal->BankBranchID << endl;
    cout << "���̴��� TThostFtdcBrokerIDType:" << pRspRepeal->BrokerID << endl;
    cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << pRspRepeal->BrokerBranchID << endl;
    cout << "�������� TThostFtdcTradeDateType:" << pRspRepeal->TradeDate << endl;
    cout << "����ʱ�� TThostFtdcTradeTimeType:" << pRspRepeal->TradeTime << endl;
    cout << "������ˮ�� TThostFtdcBankSerialType:" << pRspRepeal->BankSerial << endl;
    cout << "����ϵͳ���� TThostFtdcTradeDateType:" << pRspRepeal->TradingDay << endl;
    cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << pRspRepeal->PlateSerial << endl;
    cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << pRspRepeal->LastFragment << endl;
    cout << "�Ự�� TThostFtdcSessionIDType:" << pRspRepeal->SessionID << endl;
    cout << "�ͻ����� TThostFtdcIndividualNameType:" << pRspRepeal->CustomerName << endl;
    cout << "֤������ TThostFtdcIdCardTypeType:" << pRspRepeal->IdCardType << endl;
    cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pRspRepeal->IdentifiedCardNo << endl;
    cout << "�ͻ����� TThostFtdcCustTypeType:" << pRspRepeal->CustType << endl;
    cout << "�����ʺ� TThostFtdcBankAccountType:" << pRspRepeal->BankAccount << endl;
    cout << "�������� TThostFtdcPasswordType:" << pRspRepeal->BankPassWord << endl;
    cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pRspRepeal->AccountID << endl;
    cout << "�ڻ����� TThostFtdcPasswordType:" << pRspRepeal->Password << endl;
    cout << "��װ��� TThostFtdcInstallIDType:" << pRspRepeal->InstallID << endl;
    cout << "�ڻ���˾��ˮ�� TThostFtdcFutureSerialType:" << pRspRepeal->FutureSerial << endl;
    cout << "�û���ʶ TThostFtdcUserIDType:" << pRspRepeal->UserID << endl;
    cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << pRspRepeal->VerifyCertNoFlag << endl;
    cout << "���ִ��� TThostFtdcCurrencyIDType:" << pRspRepeal->CurrencyID << endl;
    cout << "ת�ʽ�� TThostFtdcTradeAmountType:" << pRspRepeal->TradeAmount << endl;
    cout << "�ڻ���ȡ��� TThostFtdcTradeAmountType:" << pRspRepeal->FutureFetchAmount << endl;
    cout << "����֧����־ TThostFtdcFeePayFlagType:" << pRspRepeal->FeePayFlag << endl;
    cout << "Ӧ�տͻ����� TThostFtdcCustFeeType:" << pRspRepeal->CustFee << endl;
    cout << "Ӧ���ڻ���˾���� TThostFtdcFutureFeeType:" << pRspRepeal->BrokerFee << endl;
    cout << "���ͷ������շ�����Ϣ TThostFtdcAddInfoType:" << pRspRepeal->Message << endl;
    cout << "ժҪ TThostFtdcDigestType:" << pRspRepeal->Digest << endl;
    cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << pRspRepeal->BankAccType << endl;
    cout << "������־ TThostFtdcDeviceIDType:" << pRspRepeal->DeviceID << endl;
    cout << "�ڻ���λ�ʺ����� TThostFtdcBankAccTypeType:" << pRspRepeal->BankSecuAccType << endl;
    cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << pRspRepeal->BrokerIDByBank << endl;
    cout << "�ڻ���λ�ʺ� TThostFtdcBankAccountType:" << pRspRepeal->BankSecuAcc << endl;
    cout << "���������־ TThostFtdcPwdFlagType:" << pRspRepeal->BankPwdFlag << endl;
    cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << pRspRepeal->SecuPwdFlag << endl;
    cout << "���׹�Ա TThostFtdcOperNoType:" << pRspRepeal->OperNo << endl;
    cout << "������ TThostFtdcRequestIDType:" << pRspRepeal->RequestID << endl;
    // cout << "����ID:" << pRspRepeal->TThostFtdcTIDType << endlTID;
    cout << "ת�˽���״̬ TThostFtdcTransferStatusType:" << pRspRepeal->TransferStatus << endl;
    cout << "������� TThostFtdcErrorIDType:" << pRspRepeal->ErrorID << endl;
    cout << "������Ϣ TThostFtdcErrorMsgType:" << pRspRepeal->ErrorMsg << endl;
}

///ϵͳ����ʱ�ڻ����ֹ���������ڻ�ת�����������д�����Ϻ��̷��ص�֪ͨ
void CTraderSpi::OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField* pRspRepeal)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "����ʱ���� TThostFtdcRepealTimeIntervalType:" << pRspRepeal->RepealTimeInterval << endl;
    cout << "�Ѿ��������� TThostFtdcRepealedTimesType:" << pRspRepeal->RepealedTimes << endl;
    cout << "���г�����־ TThostFtdcBankRepealFlagType:" << pRspRepeal->BankRepealFlag << endl;
    cout << "���̳�����־ TThostFtdcBrokerRepealFlagType:" << pRspRepeal->BrokerRepealFlag << endl;
    cout << "������ƽ̨��ˮ�� TThostFtdcPlateSerialType:" << pRspRepeal->PlateRepealSerial << endl;
    cout << "������������ˮ�� TThostFtdcBankSerialType:" << pRspRepeal->BankRepealSerial << endl;
    cout << "�������ڻ���ˮ�� TThostFtdcFutureSerialType:" << pRspRepeal->FutureRepealSerial << endl;
    cout << "ҵ������ TThostFtdcTradeCodeType:" << pRspRepeal->TradeCode << endl;
    cout << "���д��� TThostFtdcBankIDType:" << pRspRepeal->BankID << endl;
    cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << pRspRepeal->BankBranchID << endl;
    cout << "���̴��� TThostFtdcBrokerIDType:" << pRspRepeal->BrokerID << endl;
    cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << pRspRepeal->BrokerBranchID << endl;
    cout << "�������� TThostFtdcTradeDateType:" << pRspRepeal->TradeDate << endl;
    cout << "����ʱ�� TThostFtdcTradeTimeType:" << pRspRepeal->TradeTime << endl;
    cout << "������ˮ�� TThostFtdcBankSerialType:" << pRspRepeal->BankSerial << endl;
    cout << "����ϵͳ���� TThostFtdcTradeDateType:" << pRspRepeal->TradingDay << endl;
    cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << pRspRepeal->PlateSerial << endl;
    cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << pRspRepeal->LastFragment << endl;
    cout << "�Ự�� TThostFtdcSessionIDType:" << pRspRepeal->SessionID << endl;
    cout << "�ͻ����� TThostFtdcIndividualNameType:" << pRspRepeal->CustomerName << endl;
    cout << "֤������ TThostFtdcIdCardTypeType:" << pRspRepeal->IdCardType << endl;
    cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pRspRepeal->IdentifiedCardNo << endl;
    cout << "�ͻ����� TThostFtdcCustTypeType:" << pRspRepeal->CustType << endl;
    cout << "�����ʺ� TThostFtdcBankAccountType:" << pRspRepeal->BankAccount << endl;
    cout << "�������� TThostFtdcPasswordType:" << pRspRepeal->BankPassWord << endl;
    cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pRspRepeal->AccountID << endl;
    cout << "�ڻ����� TThostFtdcPasswordType:" << pRspRepeal->Password << endl;
    cout << "��װ��� TThostFtdcInstallIDType:" << pRspRepeal->InstallID << endl;
    cout << "�ڻ���˾��ˮ�� TThostFtdcFutureSerialType:" << pRspRepeal->FutureSerial << endl;
    cout << "�û���ʶ TThostFtdcUserIDType:" << pRspRepeal->UserID << endl;
    cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << pRspRepeal->VerifyCertNoFlag << endl;
    cout << "���ִ��� TThostFtdcCurrencyIDType:" << pRspRepeal->CurrencyID << endl;
    cout << "ת�ʽ�� TThostFtdcTradeAmountType:" << pRspRepeal->TradeAmount << endl;
    cout << "�ڻ���ȡ��� TThostFtdcTradeAmountType:" << pRspRepeal->FutureFetchAmount << endl;
    cout << "����֧����־ TThostFtdcFeePayFlagType:" << pRspRepeal->FeePayFlag << endl;
    cout << "Ӧ�տͻ����� TThostFtdcCustFeeType:" << pRspRepeal->CustFee << endl;
    cout << "Ӧ���ڻ���˾���� TThostFtdcFutureFeeType:" << pRspRepeal->BrokerFee << endl;
    cout << "���ͷ������շ�����Ϣ TThostFtdcAddInfoType:" << pRspRepeal->Message << endl;
    cout << "ժҪ TThostFtdcDigestType:" << pRspRepeal->Digest << endl;
    cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << pRspRepeal->BankAccType << endl;
    cout << "������־ TThostFtdcDeviceIDType:" << pRspRepeal->DeviceID << endl;
    cout << "�ڻ���λ�ʺ����� TThostFtdcBankAccTypeType:" << pRspRepeal->BankSecuAccType << endl;
    cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << pRspRepeal->BrokerIDByBank << endl;
    cout << "�ڻ���λ�ʺ� TThostFtdcBankAccountType:" << pRspRepeal->BankSecuAcc << endl;
    cout << "���������־ TThostFtdcPwdFlagType:" << pRspRepeal->BankPwdFlag << endl;
    cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << pRspRepeal->SecuPwdFlag << endl;
    cout << "���׹�Ա TThostFtdcOperNoType:" << pRspRepeal->OperNo << endl;
    cout << "������ TThostFtdcRequestIDType:" << pRspRepeal->RequestID << endl;
    // cout << "����ID:" << pRspRepeal->TThostFtdcTIDType << endlTID;
    cout << "ת�˽���״̬ TThostFtdcTransferStatusType:" << pRspRepeal->TransferStatus << endl;
    cout << "������� TThostFtdcErrorIDType:" << pRspRepeal->ErrorID << endl;
    cout << "������Ϣ TThostFtdcErrorMsgType:" << pRspRepeal->ErrorMsg << endl;
}

///�ڻ������ѯ�������֪ͨ
void CTraderSpi::OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField* pNotifyQueryAccount)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "ҵ������ TThostFtdcTradeCodeType:" << pNotifyQueryAccount->TradeCode << endl;
    cout << "���д��� TThostFtdcBankIDType:" << pNotifyQueryAccount->BankID << endl;
    cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << pNotifyQueryAccount->BankBranchID << endl;
    cout << "���̴��� TThostFtdcBrokerIDType:" << pNotifyQueryAccount->BrokerID << endl;
    cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << pNotifyQueryAccount->BrokerBranchID << endl;
    cout << "�������� TThostFtdcTradeDateType:" << pNotifyQueryAccount->TradeDate << endl;
    cout << "����ʱ�� TThostFtdcTradeTimeType:" << pNotifyQueryAccount->TradeTime << endl;
    cout << "������ˮ�� TThostFtdcBankSerialType:" << pNotifyQueryAccount->BankSerial << endl;
    cout << "����ϵͳ���� TThostFtdcTradeDateType:" << pNotifyQueryAccount->TradingDay << endl;
    cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << pNotifyQueryAccount->PlateSerial << endl;
    cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << pNotifyQueryAccount->LastFragment << endl;
    cout << "�Ự�� TThostFtdcSessionIDType:" << pNotifyQueryAccount->SessionID << endl;
    cout << "�ͻ����� TThostFtdcIndividualNameType:" << pNotifyQueryAccount->CustomerName << endl;
    cout << "֤������ TThostFtdcIdCardTypeType:" << pNotifyQueryAccount->IdCardType << endl;
    cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pNotifyQueryAccount->IdentifiedCardNo << endl;
    cout << "�ͻ����� TThostFtdcCustTypeType:" << pNotifyQueryAccount->CustType << endl;
    cout << "�����ʺ� TThostFtdcBankAccountType:" << pNotifyQueryAccount->BankAccount << endl;
    cout << "�������� TThostFtdcPasswordType:" << pNotifyQueryAccount->BankPassWord << endl;
    cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pNotifyQueryAccount->AccountID << endl;
    cout << "�ڻ����� TThostFtdcPasswordType:" << pNotifyQueryAccount->Password << endl;
    cout << "�ڻ���˾��ˮ�� TThostFtdcFutureSerialType:" << pNotifyQueryAccount->FutureSerial << endl;
    cout << "��װ��� TThostFtdcInstallIDType:" << pNotifyQueryAccount->InstallID << endl;
    cout << "�û���ʶ TThostFtdcUserIDType:" << pNotifyQueryAccount->UserID << endl;
    cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << pNotifyQueryAccount->VerifyCertNoFlag << endl;
    cout << "���ִ��� TThostFtdcCurrencyIDType:" << pNotifyQueryAccount->CurrencyID << endl;
    cout << "ժҪ TThostFtdcDigestType:" << pNotifyQueryAccount->Digest << endl;
    cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << pNotifyQueryAccount->BankAccType << endl;
    cout << "������־ TThostFtdcDeviceIDType:" << pNotifyQueryAccount->DeviceID << endl;
    cout << "�ڻ���λ�ʺ����� TThostFtdcBankAccTypeType:" << pNotifyQueryAccount->BankSecuAccType << endl;
    cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << pNotifyQueryAccount->BrokerIDByBank << endl;
    cout << "�ڻ���λ�ʺ� TThostFtdcBankAccountType:" << pNotifyQueryAccount->BankSecuAcc << endl;
    cout << "���������־ TThostFtdcPwdFlagType:" << pNotifyQueryAccount->BankPwdFlag << endl;
    cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << pNotifyQueryAccount->SecuPwdFlag << endl;
    cout << "���׹�Ա TThostFtdcOperNoType:" << pNotifyQueryAccount->OperNo << endl;
    cout << "������ TThostFtdcRequestIDType:" << pNotifyQueryAccount->RequestID << endl;
    cout << "���� TThostFtdcTIDType:" << pNotifyQueryAccount->TID << endl;
    cout << "���п��ý�� TThostFtdcTradeAmountType:" << pNotifyQueryAccount->BankUseAmount << endl;
    cout << "���п�ȡ��� TThostFtdcTradeAmountType:" << pNotifyQueryAccount->BankFetchAmount << endl;
    cout << "������� TThostFtdcErrorIDType:" << pNotifyQueryAccount->ErrorID << endl;
    cout << "������Ϣ TThostFtdcErrorMsgType:" << pNotifyQueryAccount->ErrorMsg << endl;
}

///�ڻ����������ʽ�ת�ڻ�����ر�
void CTraderSpi::OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "ҵ������ TThostFtdcTradeCodeType:" << pReqTransfer->TradeCode << endl;
    cout << "���д��� TThostFtdcBankIDType:" << pReqTransfer->BankID << endl;
    cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << pReqTransfer->BankBranchID << endl;
    cout << "���̴��� TThostFtdcBrokerIDType:" << pReqTransfer->BrokerID << endl;
    cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << pReqTransfer->BrokerBranchID << endl;
    cout << "�������� TThostFtdcTradeDateType:" << pReqTransfer->TradeDate << endl;
    cout << "����ʱ�� TThostFtdcTradeTimeType:" << pReqTransfer->TradeTime << endl;
    cout << "������ˮ�� TThostFtdcBankSerialType:" << pReqTransfer->BankSerial << endl;
    cout << "����ϵͳ���� TThostFtdcTradeDateType:" << pReqTransfer->TradingDay << endl;
    cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << pReqTransfer->PlateSerial << endl;
    cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << pReqTransfer->LastFragment << endl;
    cout << "�Ự�� TThostFtdcSessionIDType:" << pReqTransfer->SessionID << endl;
    cout << "�ͻ����� TThostFtdcIndividualNameType:" << pReqTransfer->CustomerName << endl;
    cout << "֤������ TThostFtdcIdCardTypeType:" << pReqTransfer->IdCardType << endl;
    cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pReqTransfer->IdentifiedCardNo << endl;
    cout << "�ͻ����� TThostFtdcCustTypeType:" << pReqTransfer->CustType << endl;
    cout << "�����ʺ� TThostFtdcBankAccountType:" << pReqTransfer->BankAccount << endl;
    cout << "�������� TThostFtdcPasswordType:" << pReqTransfer->BankPassWord << endl;
    cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pReqTransfer->AccountID << endl;
    cout << "�ڻ����� TThostFtdcPasswordType:" << pReqTransfer->Password << endl;
    cout << "��װ��� TThostFtdcInstallIDType:" << pReqTransfer->InstallID << endl;
    cout << "�ڻ���˾��ˮ�� TThostFtdcFutureSerialType:" << pReqTransfer->FutureSerial << endl;
    cout << "�û���ʶ TThostFtdcUserIDType:" << pReqTransfer->UserID << endl;
    cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << pReqTransfer->VerifyCertNoFlag << endl;
    cout << "���ִ��� TThostFtdcCurrencyIDType:" << pReqTransfer->CurrencyID << endl;
    cout << "ת�ʽ�� TThostFtdcTradeAmountType:" << pReqTransfer->TradeAmount << endl;
    cout << "�ڻ���ȡ��� TThostFtdcTradeAmountType:" << pReqTransfer->FutureFetchAmount << endl;
    cout << "����֧����־ TThostFtdcFeePayFlagType:" << pReqTransfer->FeePayFlag << endl;
    cout << "Ӧ�տͻ����� TThostFtdcCustFeeType:" << pReqTransfer->CustFee << endl;
    cout << "Ӧ���ڻ���˾���� TThostFtdcFutureFeeType:" << pReqTransfer->BrokerFee << endl;
    cout << "���ͷ������շ�����Ϣ TThostFtdcAddInfoType:" << pReqTransfer->Message << endl;
    cout << "ժҪ TThostFtdcDigestType:" << pReqTransfer->Digest << endl;
    cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << pReqTransfer->BankAccType << endl;
    cout << "������־ TThostFtdcDeviceIDType:" << pReqTransfer->DeviceID << endl;
    cout << "�ڻ���λ�ʺ����� TThostFtdcBankAccTypeType:" << pReqTransfer->BankSecuAccType << endl;
    cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << pReqTransfer->BrokerIDByBank << endl;
    cout << "�ڻ���λ�ʺ� TThostFtdcBankAccountType:" << pReqTransfer->BankSecuAcc << endl;
    cout << "���������־ TThostFtdcPwdFlagType:" << pReqTransfer->BankPwdFlag << endl;
    cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << pReqTransfer->SecuPwdFlag << endl;
    cout << "���׹�Ա TThostFtdcOperNoType:" << pReqTransfer->OperNo << endl;
    cout << "������ TThostFtdcRequestIDType:" << pReqTransfer->RequestID << endl;
    // cout << "����ID:" << pReqTransfer->TThostFtdcTIDType << endlTID;
    cout << "ת�˽���״̬ TThostFtdcTransferStatusType:" << pReqTransfer->TransferStatus << endl;
}

///�ڻ������ڻ��ʽ�ת���д���ر�
void CTraderSpi::OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (!IsErrorRspInfo(pRspInfo)) {
	cout << "ҵ������ TThostFtdcTradeCodeType:" << pReqTransfer->TradeCode << endl;
	cout << "���д��� TThostFtdcBankIDType:" << pReqTransfer->BankID << endl;
	cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << pReqTransfer->BankBranchID << endl;
	cout << "���̴��� TThostFtdcBrokerIDType:" << pReqTransfer->BrokerID << endl;
	cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << pReqTransfer->BrokerBranchID << endl;
	cout << "�������� TThostFtdcTradeDateType:" << pReqTransfer->TradeDate << endl;
	cout << "����ʱ�� TThostFtdcTradeTimeType:" << pReqTransfer->TradeTime << endl;
	cout << "������ˮ�� TThostFtdcBankSerialType:" << pReqTransfer->BankSerial << endl;
	cout << "����ϵͳ���� TThostFtdcTradeDateType:" << pReqTransfer->TradingDay << endl;
	cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << pReqTransfer->PlateSerial << endl;
	cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << pReqTransfer->LastFragment << endl;
	cout << "�Ự�� TThostFtdcSessionIDType:" << pReqTransfer->SessionID << endl;
	cout << "�ͻ����� TThostFtdcIndividualNameType:" << pReqTransfer->CustomerName << endl;
	cout << "֤������ TThostFtdcIdCardTypeType:" << pReqTransfer->IdCardType << endl;
	cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pReqTransfer->IdentifiedCardNo << endl;
	cout << "�ͻ����� TThostFtdcCustTypeType:" << pReqTransfer->CustType << endl;
	cout << "�����ʺ� TThostFtdcBankAccountType:" << pReqTransfer->BankAccount << endl;
	cout << "�������� TThostFtdcPasswordType:" << pReqTransfer->BankPassWord << endl;
	cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pReqTransfer->AccountID << endl;
	cout << "�ڻ����� TThostFtdcPasswordType:" << pReqTransfer->Password << endl;
	cout << "��װ��� TThostFtdcInstallIDType:" << pReqTransfer->InstallID << endl;
	cout << "�ڻ���˾��ˮ�� TThostFtdcFutureSerialType:" << pReqTransfer->FutureSerial << endl;
	cout << "�û���ʶ TThostFtdcUserIDType:" << pReqTransfer->UserID << endl;
	cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << pReqTransfer->VerifyCertNoFlag << endl;
	cout << "���ִ��� TThostFtdcCurrencyIDType:" << pReqTransfer->CurrencyID << endl;
	cout << "ת�ʽ�� TThostFtdcTradeAmountType:" << pReqTransfer->TradeAmount << endl;
	cout << "�ڻ���ȡ��� TThostFtdcTradeAmountType:" << pReqTransfer->FutureFetchAmount << endl;
	cout << "����֧����־ TThostFtdcFeePayFlagType:" << pReqTransfer->FeePayFlag << endl;
	cout << "Ӧ�տͻ����� TThostFtdcCustFeeType:" << pReqTransfer->CustFee << endl;
	cout << "Ӧ���ڻ���˾���� TThostFtdcFutureFeeType:" << pReqTransfer->BrokerFee << endl;
	cout << "���ͷ������շ�����Ϣ TThostFtdcAddInfoType:" << pReqTransfer->Message << endl;
	cout << "ժҪ TThostFtdcDigestType:" << pReqTransfer->Digest << endl;
	cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << pReqTransfer->BankAccType << endl;
	cout << "������־ TThostFtdcDeviceIDType:" << pReqTransfer->DeviceID << endl;
	cout << "�ڻ���λ�ʺ����� TThostFtdcBankAccTypeType:" << pReqTransfer->BankSecuAccType << endl;
	cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << pReqTransfer->BrokerIDByBank << endl;
	cout << "�ڻ���λ�ʺ� TThostFtdcBankAccountType:" << pReqTransfer->BankSecuAcc << endl;
	cout << "���������־ TThostFtdcPwdFlagType:" << pReqTransfer->BankPwdFlag << endl;
	cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << pReqTransfer->SecuPwdFlag << endl;
	cout << "���׹�Ա TThostFtdcOperNoType:" << pReqTransfer->OperNo << endl;
	cout << "������ TThostFtdcRequestIDType:" << pReqTransfer->RequestID << endl;
	// cout << "����ID:" << pReqTransfer->TThostFtdcTIDType << endlTID;
	cout << "ת�˽���״̬ TThostFtdcTransferStatusType:" << pReqTransfer->TransferStatus << endl;
    }
}

///ϵͳ����ʱ�ڻ����ֹ������������ת�ڻ�����ر�
void CTraderSpi::OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (!IsErrorRspInfo(pRspInfo)) {
	cout << "����ʱ���� TThostFtdcRepealTimeIntervalType:" << pReqRepeal->RepealTimeInterval << endl;
	cout << "�Ѿ��������� TThostFtdcRepealedTimesType:" << pReqRepeal->RepealedTimes << endl;
	cout << "���г�����־ TThostFtdcBankRepealFlagType:" << pReqRepeal->BankRepealFlag << endl;
	cout << "���̳�����־ TThostFtdcBrokerRepealFlagType:" << pReqRepeal->BrokerRepealFlag << endl;
	cout << "������ƽ̨��ˮ�� TThostFtdcPlateSerialType:" << pReqRepeal->PlateRepealSerial << endl;
	cout << "������������ˮ�� TThostFtdcBankSerialType:" << pReqRepeal->BankRepealSerial << endl;
	cout << "�������ڻ���ˮ�� TThostFtdcFutureSerialType:" << pReqRepeal->FutureRepealSerial << endl;
	cout << "ҵ������ TThostFtdcTradeCodeType:" << pReqRepeal->TradeCode << endl;
	cout << "���д��� TThostFtdcBankIDType:" << pReqRepeal->BankID << endl;
	cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << pReqRepeal->BankBranchID << endl;
	cout << "���̴��� TThostFtdcBrokerIDType:" << pReqRepeal->BrokerID << endl;
	cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << pReqRepeal->BrokerBranchID << endl;
	cout << "�������� TThostFtdcTradeDateType:" << pReqRepeal->TradeDate << endl;
	cout << "����ʱ�� TThostFtdcTradeTimeType:" << pReqRepeal->TradeTime << endl;
	cout << "������ˮ�� TThostFtdcBankSerialType:" << pReqRepeal->BankSerial << endl;
	cout << "����ϵͳ���� TThostFtdcTradeDateType:" << pReqRepeal->TradingDay << endl;
	cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << pReqRepeal->PlateSerial << endl;
	cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << pReqRepeal->LastFragment << endl;
	cout << "�Ự�� TThostFtdcSessionIDType:" << pReqRepeal->SessionID << endl;
	cout << "�ͻ����� TThostFtdcIndividualNameType:" << pReqRepeal->CustomerName << endl;
	cout << "֤������ TThostFtdcIdCardTypeType:" << pReqRepeal->IdCardType << endl;
	cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pReqRepeal->IdentifiedCardNo << endl;
	cout << "�ͻ����� TThostFtdcCustTypeType:" << pReqRepeal->CustType << endl;
	cout << "�����ʺ� TThostFtdcBankAccountType:" << pReqRepeal->BankAccount << endl;
	cout << "�������� TThostFtdcPasswordType:" << pReqRepeal->BankPassWord << endl;
	cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pReqRepeal->AccountID << endl;
	cout << "�ڻ����� TThostFtdcPasswordType:" << pReqRepeal->Password << endl;
	cout << "��װ��� TThostFtdcInstallIDType:" << pReqRepeal->InstallID << endl;
	cout << "�ڻ���˾��ˮ�� TThostFtdcFutureSerialType:" << pReqRepeal->FutureSerial << endl;
	cout << "�û���ʶ TThostFtdcUserIDType:" << pReqRepeal->UserID << endl;
	cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << pReqRepeal->VerifyCertNoFlag << endl;
	cout << "���ִ��� TThostFtdcCurrencyIDType:" << pReqRepeal->CurrencyID << endl;
	cout << "ת�ʽ�� TThostFtdcTradeAmountType:" << pReqRepeal->TradeAmount << endl;
	cout << "�ڻ���ȡ��� TThostFtdcTradeAmountType:" << pReqRepeal->FutureFetchAmount << endl;
	cout << "����֧����־ TThostFtdcFeePayFlagType:" << pReqRepeal->FeePayFlag << endl;
	cout << "Ӧ�տͻ����� TThostFtdcCustFeeType:" << pReqRepeal->CustFee << endl;
	cout << "Ӧ���ڻ���˾���� TThostFtdcFutureFeeType:" << pReqRepeal->BrokerFee << endl;
	cout << "���ͷ������շ�����Ϣ TThostFtdcAddInfoType:" << pReqRepeal->Message << endl;
	cout << "ժҪ TThostFtdcDigestType:" << pReqRepeal->Digest << endl;
	cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << pReqRepeal->BankAccType << endl;
	cout << "������־ TThostFtdcDeviceIDType:" << pReqRepeal->DeviceID << endl;
	cout << "�ڻ���λ�ʺ����� TThostFtdcBankAccTypeType:" << pReqRepeal->BankSecuAccType << endl;
	cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << pReqRepeal->BrokerIDByBank << endl;
	cout << "�ڻ���λ�ʺ� TThostFtdcBankAccountType:" << pReqRepeal->BankSecuAcc << endl;
	cout << "���������־ TThostFtdcPwdFlagType:" << pReqRepeal->BankPwdFlag << endl;
	cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << pReqRepeal->SecuPwdFlag << endl;
	cout << "���׹�Ա TThostFtdcOperNoType:" << pReqRepeal->OperNo << endl;
	cout << "������ TThostFtdcRequestIDType:" << pReqRepeal->RequestID << endl;
	// cout << "����ID:" << pReqRepeal->TThostFtdcTIDType << endlTID;
	cout << "ת�˽���״̬ TThostFtdcTransferStatusType:" << pReqRepeal->TransferStatus << endl;
    }
}

///ϵͳ����ʱ�ڻ����ֹ���������ڻ�ת���д���ر�
void CTraderSpi::OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (!IsErrorRspInfo(pRspInfo)) {
	cout << "����ʱ���� TThostFtdcRepealTimeIntervalType:" << pReqRepeal->RepealTimeInterval << endl;
	cout << "�Ѿ��������� TThostFtdcRepealedTimesType:" << pReqRepeal->RepealedTimes << endl;
	cout << "���г�����־ TThostFtdcBankRepealFlagType:" << pReqRepeal->BankRepealFlag << endl;
	cout << "���̳�����־ TThostFtdcBrokerRepealFlagType:" << pReqRepeal->BrokerRepealFlag << endl;
	cout << "������ƽ̨��ˮ�� TThostFtdcPlateSerialType:" << pReqRepeal->PlateRepealSerial << endl;
	cout << "������������ˮ�� TThostFtdcBankSerialType:" << pReqRepeal->BankRepealSerial << endl;
	cout << "�������ڻ���ˮ�� TThostFtdcFutureSerialType:" << pReqRepeal->FutureRepealSerial << endl;
	cout << "ҵ������ TThostFtdcTradeCodeType:" << pReqRepeal->TradeCode << endl;
	cout << "���д��� TThostFtdcBankIDType:" << pReqRepeal->BankID << endl;
	cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << pReqRepeal->BankBranchID << endl;
	cout << "���̴��� TThostFtdcBrokerIDType:" << pReqRepeal->BrokerID << endl;
	cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << pReqRepeal->BrokerBranchID << endl;
	cout << "�������� TThostFtdcTradeDateType:" << pReqRepeal->TradeDate << endl;
	cout << "����ʱ�� TThostFtdcTradeTimeType:" << pReqRepeal->TradeTime << endl;
	cout << "������ˮ�� TThostFtdcBankSerialType:" << pReqRepeal->BankSerial << endl;
	cout << "����ϵͳ���� TThostFtdcTradeDateType:" << pReqRepeal->TradingDay << endl;
	cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << pReqRepeal->PlateSerial << endl;
	cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << pReqRepeal->LastFragment << endl;
	cout << "�Ự�� TThostFtdcSessionIDType:" << pReqRepeal->SessionID << endl;
	cout << "�ͻ����� TThostFtdcIndividualNameType:" << pReqRepeal->CustomerName << endl;
	cout << "֤������ TThostFtdcIdCardTypeType:" << pReqRepeal->IdCardType << endl;
	cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pReqRepeal->IdentifiedCardNo << endl;
	cout << "�ͻ����� TThostFtdcCustTypeType:" << pReqRepeal->CustType << endl;
	cout << "�����ʺ� TThostFtdcBankAccountType:" << pReqRepeal->BankAccount << endl;
	cout << "�������� TThostFtdcPasswordType:" << pReqRepeal->BankPassWord << endl;
	cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pReqRepeal->AccountID << endl;
	cout << "�ڻ����� TThostFtdcPasswordType:" << pReqRepeal->Password << endl;
	cout << "��װ��� TThostFtdcInstallIDType:" << pReqRepeal->InstallID << endl;
	cout << "�ڻ���˾��ˮ�� TThostFtdcFutureSerialType:" << pReqRepeal->FutureSerial << endl;
	cout << "�û���ʶ TThostFtdcUserIDType:" << pReqRepeal->UserID << endl;
	cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << pReqRepeal->VerifyCertNoFlag << endl;
	cout << "���ִ��� TThostFtdcCurrencyIDType:" << pReqRepeal->CurrencyID << endl;
	cout << "ת�ʽ�� TThostFtdcTradeAmountType:" << pReqRepeal->TradeAmount << endl;
	cout << "�ڻ���ȡ��� TThostFtdcTradeAmountType:" << pReqRepeal->FutureFetchAmount << endl;
	cout << "����֧����־ TThostFtdcFeePayFlagType:" << pReqRepeal->FeePayFlag << endl;
	cout << "Ӧ�տͻ����� TThostFtdcCustFeeType:" << pReqRepeal->CustFee << endl;
	cout << "Ӧ���ڻ���˾���� TThostFtdcFutureFeeType:" << pReqRepeal->BrokerFee << endl;
	cout << "���ͷ������շ�����Ϣ TThostFtdcAddInfoType:" << pReqRepeal->Message << endl;
	cout << "ժҪ TThostFtdcDigestType:" << pReqRepeal->Digest << endl;
	cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << pReqRepeal->BankAccType << endl;
	cout << "������־ TThostFtdcDeviceIDType:" << pReqRepeal->DeviceID << endl;
	cout << "�ڻ���λ�ʺ����� TThostFtdcBankAccTypeType:" << pReqRepeal->BankSecuAccType << endl;
	cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << pReqRepeal->BrokerIDByBank << endl;
	cout << "�ڻ���λ�ʺ� TThostFtdcBankAccountType:" << pReqRepeal->BankSecuAcc << endl;
	cout << "���������־ TThostFtdcPwdFlagType:" << pReqRepeal->BankPwdFlag << endl;
	cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << pReqRepeal->SecuPwdFlag << endl;
	cout << "���׹�Ա TThostFtdcOperNoType:" << pReqRepeal->OperNo << endl;
	cout << "������ TThostFtdcRequestIDType:" << pReqRepeal->RequestID << endl;
	// cout << "����ID:" << pReqRepeal->TThostFtdcTIDType << endlTID;
	cout << "ת�˽���״̬ TThostFtdcTransferStatusType:" << pReqRepeal->TransferStatus << endl;
    }
}

///�ڻ������ѯ����������ر�
void CTraderSpi::OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (!IsErrorRspInfo(pRspInfo)) {
	cout << "ҵ������ TThostFtdcTradeCodeType:" << pReqQueryAccount->TradeCode << endl;
	cout << "���д��� TThostFtdcBankIDType:" << pReqQueryAccount->BankID << endl;
	cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << pReqQueryAccount->BankBranchID << endl;
	cout << "���̴��� TThostFtdcBrokerIDType:" << pReqQueryAccount->BrokerID << endl;
	cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << pReqQueryAccount->BrokerBranchID << endl;
	cout << "�������� TThostFtdcTradeDateType:" << pReqQueryAccount->TradeDate << endl;
	cout << "����ʱ�� TThostFtdcTradeTimeType:" << pReqQueryAccount->TradeTime << endl;
	cout << "������ˮ�� TThostFtdcBankSerialType:" << pReqQueryAccount->BankSerial << endl;
	cout << "����ϵͳ���� TThostFtdcTradeDateType:" << pReqQueryAccount->TradingDay << endl;
	cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << pReqQueryAccount->PlateSerial << endl;
	cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << pReqQueryAccount->LastFragment << endl;
	cout << "�Ự�� TThostFtdcSessionIDType:" << pReqQueryAccount->SessionID << endl;
	cout << "�ͻ����� TThostFtdcIndividualNameType:" << pReqQueryAccount->CustomerName << endl;
	cout << "֤������ TThostFtdcIdCardTypeType:" << pReqQueryAccount->IdCardType << endl;
	cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pReqQueryAccount->IdentifiedCardNo << endl;
	cout << "�ͻ����� TThostFtdcCustTypeType:" << pReqQueryAccount->CustType << endl;
	cout << "�����ʺ� TThostFtdcBankAccountType:" << pReqQueryAccount->BankAccount << endl;
	cout << "�������� TThostFtdcPasswordType:" << pReqQueryAccount->BankPassWord << endl;
	cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pReqQueryAccount->AccountID << endl;
	cout << "�ڻ����� TThostFtdcPasswordType:" << pReqQueryAccount->Password << endl;
	cout << "�ڻ���˾��ˮ�� TThostFtdcFutureSerialType:" << pReqQueryAccount->FutureSerial << endl;
	cout << "��װ��� TThostFtdcInstallIDType:" << pReqQueryAccount->InstallID << endl;
	cout << "�û���ʶ TThostFtdcUserIDType:" << pReqQueryAccount->UserID << endl;
	cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << pReqQueryAccount->VerifyCertNoFlag << endl;
	cout << "���ִ��� TThostFtdcCurrencyIDType:" << pReqQueryAccount->CurrencyID << endl;
	cout << "ժҪ TThostFtdcDigestType:" << pReqQueryAccount->Digest << endl;
	cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << pReqQueryAccount->BankAccType << endl;
	cout << "������־ TThostFtdcDeviceIDType:" << pReqQueryAccount->DeviceID << endl;
	cout << "�ڻ���λ�ʺ����� TThostFtdcBankAccTypeType:" << pReqQueryAccount->BankSecuAccType << endl;
	cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << pReqQueryAccount->BrokerIDByBank << endl;
	cout << "�ڻ���λ�ʺ� TThostFtdcBankAccountType:" << pReqQueryAccount->BankSecuAcc << endl;
	cout << "���������־ TThostFtdcPwdFlagType:" << pReqQueryAccount->BankPwdFlag << endl;
	cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << pReqQueryAccount->SecuPwdFlag << endl;
	cout << "���׹�Ա TThostFtdcOperNoType:" << pReqQueryAccount->OperNo << endl;
	cout << "������ TThostFtdcRequestIDType:" << pReqQueryAccount->RequestID << endl;
	// cout << "����ID:" << pReqQueryAccount->TThostFtdcTIDType << endlTID;
    }
}

///�ڻ������������ת�ڻ��������д�����Ϻ��̷��ص�֪ͨ
void CTraderSpi::OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField* pRspRepeal)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "����ʱ���� TThostFtdcRepealTimeIntervalType:" << pRspRepeal->RepealTimeInterval << endl;
    cout << "�Ѿ��������� TThostFtdcRepealedTimesType:" << pRspRepeal->RepealedTimes << endl;
    cout << "���г�����־ TThostFtdcBankRepealFlagType:" << pRspRepeal->BankRepealFlag << endl;
    cout << "���̳�����־ TThostFtdcBrokerRepealFlagType:" << pRspRepeal->BrokerRepealFlag << endl;
    cout << "������ƽ̨��ˮ�� TThostFtdcPlateSerialType:" << pRspRepeal->PlateRepealSerial << endl;
    cout << "������������ˮ�� TThostFtdcBankSerialType:" << pRspRepeal->BankRepealSerial << endl;
    cout << "�������ڻ���ˮ�� TThostFtdcFutureSerialType:" << pRspRepeal->FutureRepealSerial << endl;
    cout << "ҵ������ TThostFtdcTradeCodeType:" << pRspRepeal->TradeCode << endl;
    cout << "���д��� TThostFtdcBankIDType:" << pRspRepeal->BankID << endl;
    cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << pRspRepeal->BankBranchID << endl;
    cout << "���̴��� TThostFtdcBrokerIDType:" << pRspRepeal->BrokerID << endl;
    cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << pRspRepeal->BrokerBranchID << endl;
    cout << "�������� TThostFtdcTradeDateType:" << pRspRepeal->TradeDate << endl;
    cout << "����ʱ�� TThostFtdcTradeTimeType:" << pRspRepeal->TradeTime << endl;
    cout << "������ˮ�� TThostFtdcBankSerialType:" << pRspRepeal->BankSerial << endl;
    cout << "����ϵͳ���� TThostFtdcTradeDateType:" << pRspRepeal->TradingDay << endl;
    cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << pRspRepeal->PlateSerial << endl;
    cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << pRspRepeal->LastFragment << endl;
    cout << "�Ự�� TThostFtdcSessionIDType:" << pRspRepeal->SessionID << endl;
    cout << "�ͻ����� TThostFtdcIndividualNameType:" << pRspRepeal->CustomerName << endl;
    cout << "֤������ TThostFtdcIdCardTypeType:" << pRspRepeal->IdCardType << endl;
    cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pRspRepeal->IdentifiedCardNo << endl;
    cout << "�ͻ����� TThostFtdcCustTypeType:" << pRspRepeal->CustType << endl;
    cout << "�����ʺ� TThostFtdcBankAccountType:" << pRspRepeal->BankAccount << endl;
    cout << "�������� TThostFtdcPasswordType:" << pRspRepeal->BankPassWord << endl;
    cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pRspRepeal->AccountID << endl;
    cout << "�ڻ����� TThostFtdcPasswordType:" << pRspRepeal->Password << endl;
    cout << "��װ��� TThostFtdcInstallIDType:" << pRspRepeal->InstallID << endl;
    cout << "�ڻ���˾��ˮ�� TThostFtdcFutureSerialType:" << pRspRepeal->FutureSerial << endl;
    cout << "�û���ʶ TThostFtdcUserIDType:" << pRspRepeal->UserID << endl;
    cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << pRspRepeal->VerifyCertNoFlag << endl;
    cout << "���ִ��� TThostFtdcCurrencyIDType:" << pRspRepeal->CurrencyID << endl;
    cout << "ת�ʽ�� TThostFtdcTradeAmountType:" << pRspRepeal->TradeAmount << endl;
    cout << "�ڻ���ȡ��� TThostFtdcTradeAmountType:" << pRspRepeal->FutureFetchAmount << endl;
    cout << "����֧����־ TThostFtdcFeePayFlagType:" << pRspRepeal->FeePayFlag << endl;
    cout << "Ӧ�տͻ����� TThostFtdcCustFeeType:" << pRspRepeal->CustFee << endl;
    cout << "Ӧ���ڻ���˾���� TThostFtdcFutureFeeType:" << pRspRepeal->BrokerFee << endl;
    cout << "���ͷ������շ�����Ϣ TThostFtdcAddInfoType:" << pRspRepeal->Message << endl;
    cout << "ժҪ TThostFtdcDigestType:" << pRspRepeal->Digest << endl;
    cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << pRspRepeal->BankAccType << endl;
    cout << "������־ TThostFtdcDeviceIDType:" << pRspRepeal->DeviceID << endl;
    cout << "�ڻ���λ�ʺ����� TThostFtdcBankAccTypeType:" << pRspRepeal->BankSecuAccType << endl;
    cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << pRspRepeal->BrokerIDByBank << endl;
    cout << "�ڻ���λ�ʺ� TThostFtdcBankAccountType:" << pRspRepeal->BankSecuAcc << endl;
    cout << "���������־ TThostFtdcPwdFlagType:" << pRspRepeal->BankPwdFlag << endl;
    cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << pRspRepeal->SecuPwdFlag << endl;
    cout << "���׹�Ա TThostFtdcOperNoType:" << pRspRepeal->OperNo << endl;
    cout << "������ TThostFtdcRequestIDType:" << pRspRepeal->RequestID << endl;
    // cout << "����ID:" << pRspRepeal->TThostFtdcTIDType << endlTID;
    cout << "ת�˽���״̬ TThostFtdcTransferStatusType:" << pRspRepeal->TransferStatus << endl;
    cout << "������� TThostFtdcErrorIDType:" << pRspRepeal->ErrorID << endl;
    cout << "������Ϣ TThostFtdcErrorMsgType:" << pRspRepeal->ErrorMsg << endl;
}

///�ڻ���������ڻ�ת�����������д�����Ϻ��̷��ص�֪ͨ
void CTraderSpi::OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField* pRspRepeal)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "����ʱ���� TThostFtdcRepealTimeIntervalType:" << pRspRepeal->RepealTimeInterval << endl;
    cout << "�Ѿ��������� TThostFtdcRepealedTimesType:" << pRspRepeal->RepealedTimes << endl;
    cout << "���г�����־ TThostFtdcBankRepealFlagType:" << pRspRepeal->BankRepealFlag << endl;
    cout << "���̳�����־ TThostFtdcBrokerRepealFlagType:" << pRspRepeal->BrokerRepealFlag << endl;
    cout << "������ƽ̨��ˮ�� TThostFtdcPlateSerialType:" << pRspRepeal->PlateRepealSerial << endl;
    cout << "������������ˮ�� TThostFtdcBankSerialType:" << pRspRepeal->BankRepealSerial << endl;
    cout << "�������ڻ���ˮ�� TThostFtdcFutureSerialType:" << pRspRepeal->FutureRepealSerial << endl;
    cout << "ҵ������ TThostFtdcTradeCodeType:" << pRspRepeal->TradeCode << endl;
    cout << "���д��� TThostFtdcBankIDType:" << pRspRepeal->BankID << endl;
    cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << pRspRepeal->BankBranchID << endl;
    cout << "���̴��� TThostFtdcBrokerIDType:" << pRspRepeal->BrokerID << endl;
    cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << pRspRepeal->BrokerBranchID << endl;
    cout << "�������� TThostFtdcTradeDateType:" << pRspRepeal->TradeDate << endl;
    cout << "����ʱ�� TThostFtdcTradeTimeType:" << pRspRepeal->TradeTime << endl;
    cout << "������ˮ�� TThostFtdcBankSerialType:" << pRspRepeal->BankSerial << endl;
    cout << "����ϵͳ���� TThostFtdcTradeDateType:" << pRspRepeal->TradingDay << endl;
    cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << pRspRepeal->PlateSerial << endl;
    cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << pRspRepeal->LastFragment << endl;
    cout << "�Ự�� TThostFtdcSessionIDType:" << pRspRepeal->SessionID << endl;
    cout << "�ͻ����� TThostFtdcIndividualNameType:" << pRspRepeal->CustomerName << endl;
    cout << "֤������ TThostFtdcIdCardTypeType:" << pRspRepeal->IdCardType << endl;
    cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pRspRepeal->IdentifiedCardNo << endl;
    cout << "�ͻ����� TThostFtdcCustTypeType:" << pRspRepeal->CustType << endl;
    cout << "�����ʺ� TThostFtdcBankAccountType:" << pRspRepeal->BankAccount << endl;
    cout << "�������� TThostFtdcPasswordType:" << pRspRepeal->BankPassWord << endl;
    cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pRspRepeal->AccountID << endl;
    cout << "�ڻ����� TThostFtdcPasswordType:" << pRspRepeal->Password << endl;
    cout << "��װ��� TThostFtdcInstallIDType:" << pRspRepeal->InstallID << endl;
    cout << "�ڻ���˾��ˮ�� TThostFtdcFutureSerialType:" << pRspRepeal->FutureSerial << endl;
    cout << "�û���ʶ TThostFtdcUserIDType:" << pRspRepeal->UserID << endl;
    cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << pRspRepeal->VerifyCertNoFlag << endl;
    cout << "���ִ��� TThostFtdcCurrencyIDType:" << pRspRepeal->CurrencyID << endl;
    cout << "ת�ʽ�� TThostFtdcTradeAmountType:" << pRspRepeal->TradeAmount << endl;
    cout << "�ڻ���ȡ��� TThostFtdcTradeAmountType:" << pRspRepeal->FutureFetchAmount << endl;
    cout << "����֧����־ TThostFtdcFeePayFlagType:" << pRspRepeal->FeePayFlag << endl;
    cout << "Ӧ�տͻ����� TThostFtdcCustFeeType:" << pRspRepeal->CustFee << endl;
    cout << "Ӧ���ڻ���˾���� TThostFtdcFutureFeeType:" << pRspRepeal->BrokerFee << endl;
    cout << "���ͷ������շ�����Ϣ TThostFtdcAddInfoType:" << pRspRepeal->Message << endl;
    cout << "ժҪ TThostFtdcDigestType:" << pRspRepeal->Digest << endl;
    cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << pRspRepeal->BankAccType << endl;
    cout << "������־ TThostFtdcDeviceIDType:" << pRspRepeal->DeviceID << endl;
    cout << "�ڻ���λ�ʺ����� TThostFtdcBankAccTypeType:" << pRspRepeal->BankSecuAccType << endl;
    cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << pRspRepeal->BrokerIDByBank << endl;
    cout << "�ڻ���λ�ʺ� TThostFtdcBankAccountType:" << pRspRepeal->BankSecuAcc << endl;
    cout << "���������־ TThostFtdcPwdFlagType:" << pRspRepeal->BankPwdFlag << endl;
    cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << pRspRepeal->SecuPwdFlag << endl;
    cout << "���׹�Ա TThostFtdcOperNoType:" << pRspRepeal->OperNo << endl;
    cout << "������ TThostFtdcRequestIDType:" << pRspRepeal->RequestID << endl;
    // cout << "����ID:" << pRspRepeal->TThostFtdcTIDType << endlTID;
    cout << "ת�˽���״̬ TThostFtdcTransferStatusType:" << pRspRepeal->TransferStatus << endl;
    cout << "������� TThostFtdcErrorIDType:" << pRspRepeal->ErrorID << endl;
    cout << "������Ϣ TThostFtdcErrorMsgType:" << pRspRepeal->ErrorMsg << endl;
}

///�ڻ����������ʽ�ת�ڻ�Ӧ��
void CTraderSpi::OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "ҵ������ TThostFtdcTradeCodeType:" << pReqTransfer->TradeCode << endl;
	cout << "���д��� TThostFtdcBankIDType:" << pReqTransfer->BankID << endl;
	cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << pReqTransfer->BankBranchID << endl;
	cout << "���̴��� TThostFtdcBrokerIDType:" << pReqTransfer->BrokerID << endl;
	cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << pReqTransfer->BrokerBranchID << endl;
	cout << "�������� TThostFtdcTradeDateType:" << pReqTransfer->TradeDate << endl;
	cout << "����ʱ�� TThostFtdcTradeTimeType:" << pReqTransfer->TradeTime << endl;
	cout << "������ˮ�� TThostFtdcBankSerialType:" << pReqTransfer->BankSerial << endl;
	cout << "����ϵͳ���� TThostFtdcTradeDateType:" << pReqTransfer->TradingDay << endl;
	cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << pReqTransfer->PlateSerial << endl;
	cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << pReqTransfer->LastFragment << endl;
	cout << "�Ự�� TThostFtdcSessionIDType:" << pReqTransfer->SessionID << endl;
	cout << "�ͻ����� TThostFtdcIndividualNameType:" << pReqTransfer->CustomerName << endl;
	cout << "֤������ TThostFtdcIdCardTypeType:" << pReqTransfer->IdCardType << endl;
	cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pReqTransfer->IdentifiedCardNo << endl;
	cout << "�ͻ����� TThostFtdcCustTypeType:" << pReqTransfer->CustType << endl;
	cout << "�����ʺ� TThostFtdcBankAccountType:" << pReqTransfer->BankAccount << endl;
	cout << "�������� TThostFtdcPasswordType:" << pReqTransfer->BankPassWord << endl;
	cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pReqTransfer->AccountID << endl;
	cout << "�ڻ����� TThostFtdcPasswordType:" << pReqTransfer->Password << endl;
	cout << "��װ��� TThostFtdcInstallIDType:" << pReqTransfer->InstallID << endl;
	cout << "�ڻ���˾��ˮ�� TThostFtdcFutureSerialType:" << pReqTransfer->FutureSerial << endl;
	cout << "�û���ʶ TThostFtdcUserIDType:" << pReqTransfer->UserID << endl;
	cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << pReqTransfer->VerifyCertNoFlag << endl;
	cout << "���ִ��� TThostFtdcCurrencyIDType:" << pReqTransfer->CurrencyID << endl;
	cout << "ת�ʽ�� TThostFtdcTradeAmountType:" << pReqTransfer->TradeAmount << endl;
	cout << "�ڻ���ȡ��� TThostFtdcTradeAmountType:" << pReqTransfer->FutureFetchAmount << endl;
	cout << "����֧����־ TThostFtdcFeePayFlagType:" << pReqTransfer->FeePayFlag << endl;
	cout << "Ӧ�տͻ����� TThostFtdcCustFeeType:" << pReqTransfer->CustFee << endl;
	cout << "Ӧ���ڻ���˾���� TThostFtdcFutureFeeType:" << pReqTransfer->BrokerFee << endl;
	cout << "���ͷ������շ�����Ϣ TThostFtdcAddInfoType:" << pReqTransfer->Message << endl;
	cout << "ժҪ TThostFtdcDigestType:" << pReqTransfer->Digest << endl;
	cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << pReqTransfer->BankAccType << endl;
	cout << "������־ TThostFtdcDeviceIDType:" << pReqTransfer->DeviceID << endl;
	cout << "�ڻ���λ�ʺ����� TThostFtdcBankAccTypeType:" << pReqTransfer->BankSecuAccType << endl;
	cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << pReqTransfer->BrokerIDByBank << endl;
	cout << "�ڻ���λ�ʺ� TThostFtdcBankAccountType:" << pReqTransfer->BankSecuAcc << endl;
	cout << "���������־ TThostFtdcPwdFlagType:" << pReqTransfer->BankPwdFlag << endl;
	cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << pReqTransfer->SecuPwdFlag << endl;
	cout << "���׹�Ա TThostFtdcOperNoType:" << pReqTransfer->OperNo << endl;
	cout << "������ TThostFtdcRequestIDType:" << pReqTransfer->RequestID << endl;
	// cout << "����ID:" << pReqTransfer->TThostFtdcTIDType << endlTID;
	cout << "ת�˽���״̬ TThostFtdcTransferStatusType:" << pReqTransfer->TransferStatus << endl;
    }
}

///�ڻ������ڻ��ʽ�ת����Ӧ��
void CTraderSpi::OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "ҵ������ TThostFtdcTradeCodeType:" << pReqTransfer->TradeCode << endl;
	cout << "���д��� TThostFtdcBankIDType:" << pReqTransfer->BankID << endl;
	cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << pReqTransfer->BankBranchID << endl;
	cout << "���̴��� TThostFtdcBrokerIDType:" << pReqTransfer->BrokerID << endl;
	cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << pReqTransfer->BrokerBranchID << endl;
	cout << "�������� TThostFtdcTradeDateType:" << pReqTransfer->TradeDate << endl;
	cout << "����ʱ�� TThostFtdcTradeTimeType:" << pReqTransfer->TradeTime << endl;
	cout << "������ˮ�� TThostFtdcBankSerialType:" << pReqTransfer->BankSerial << endl;
	cout << "����ϵͳ���� TThostFtdcTradeDateType:" << pReqTransfer->TradingDay << endl;
	cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << pReqTransfer->PlateSerial << endl;
	cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << pReqTransfer->LastFragment << endl;
	cout << "�Ự�� TThostFtdcSessionIDType:" << pReqTransfer->SessionID << endl;
	cout << "�ͻ����� TThostFtdcIndividualNameType:" << pReqTransfer->CustomerName << endl;
	cout << "֤������ TThostFtdcIdCardTypeType:" << pReqTransfer->IdCardType << endl;
	cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pReqTransfer->IdentifiedCardNo << endl;
	cout << "�ͻ����� TThostFtdcCustTypeType:" << pReqTransfer->CustType << endl;
	cout << "�����ʺ� TThostFtdcBankAccountType:" << pReqTransfer->BankAccount << endl;
	cout << "�������� TThostFtdcPasswordType:" << pReqTransfer->BankPassWord << endl;
	cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pReqTransfer->AccountID << endl;
	cout << "�ڻ����� TThostFtdcPasswordType:" << pReqTransfer->Password << endl;
	cout << "��װ��� TThostFtdcInstallIDType:" << pReqTransfer->InstallID << endl;
	cout << "�ڻ���˾��ˮ�� TThostFtdcFutureSerialType:" << pReqTransfer->FutureSerial << endl;
	cout << "�û���ʶ TThostFtdcUserIDType:" << pReqTransfer->UserID << endl;
	cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << pReqTransfer->VerifyCertNoFlag << endl;
	cout << "���ִ��� TThostFtdcCurrencyIDType:" << pReqTransfer->CurrencyID << endl;
	cout << "ת�ʽ�� TThostFtdcTradeAmountType:" << pReqTransfer->TradeAmount << endl;
	cout << "�ڻ���ȡ��� TThostFtdcTradeAmountType:" << pReqTransfer->FutureFetchAmount << endl;
	cout << "����֧����־ TThostFtdcFeePayFlagType:" << pReqTransfer->FeePayFlag << endl;
	cout << "Ӧ�տͻ����� TThostFtdcCustFeeType:" << pReqTransfer->CustFee << endl;
	cout << "Ӧ���ڻ���˾���� TThostFtdcFutureFeeType:" << pReqTransfer->BrokerFee << endl;
	cout << "���ͷ������շ�����Ϣ TThostFtdcAddInfoType:" << pReqTransfer->Message << endl;
	cout << "ժҪ TThostFtdcDigestType:" << pReqTransfer->Digest << endl;
	cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << pReqTransfer->BankAccType << endl;
	cout << "������־ TThostFtdcDeviceIDType:" << pReqTransfer->DeviceID << endl;
	cout << "�ڻ���λ�ʺ����� TThostFtdcBankAccTypeType:" << pReqTransfer->BankSecuAccType << endl;
	cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << pReqTransfer->BrokerIDByBank << endl;
	cout << "�ڻ���λ�ʺ� TThostFtdcBankAccountType:" << pReqTransfer->BankSecuAcc << endl;
	cout << "���������־ TThostFtdcPwdFlagType:" << pReqTransfer->BankPwdFlag << endl;
	cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << pReqTransfer->SecuPwdFlag << endl;
	cout << "���׹�Ա TThostFtdcOperNoType:" << pReqTransfer->OperNo << endl;
	cout << "������ TThostFtdcRequestIDType:" << pReqTransfer->RequestID << endl;
	// cout << "����ID:" << pReqTransfer->TThostFtdcTIDType << endlTID;
	cout << "ת�˽���״̬ TThostFtdcTransferStatusType:" << pReqTransfer->TransferStatus << endl;
    }
}

///�ڻ������ѯ�������Ӧ��
void CTraderSpi::OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "ҵ������ TThostFtdcTradeCodeType:" << pReqQueryAccount->TradeCode << endl;
	cout << "���д��� TThostFtdcBankIDType:" << pReqQueryAccount->BankID << endl;
	cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << pReqQueryAccount->BankBranchID << endl;
	cout << "���̴��� TThostFtdcBrokerIDType:" << pReqQueryAccount->BrokerID << endl;
	cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << pReqQueryAccount->BrokerBranchID << endl;
	cout << "�������� TThostFtdcTradeDateType:" << pReqQueryAccount->TradeDate << endl;
	cout << "����ʱ�� TThostFtdcTradeTimeType:" << pReqQueryAccount->TradeTime << endl;
	cout << "������ˮ�� TThostFtdcBankSerialType:" << pReqQueryAccount->BankSerial << endl;
	cout << "����ϵͳ���� TThostFtdcTradeDateType:" << pReqQueryAccount->TradingDay << endl;
	cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << pReqQueryAccount->PlateSerial << endl;
	cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << pReqQueryAccount->LastFragment << endl;
	cout << "�Ự�� TThostFtdcSessionIDType:" << pReqQueryAccount->SessionID << endl;
	cout << "�ͻ����� TThostFtdcIndividualNameType:" << pReqQueryAccount->CustomerName << endl;
	cout << "֤������ TThostFtdcIdCardTypeType:" << pReqQueryAccount->IdCardType << endl;
	cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pReqQueryAccount->IdentifiedCardNo << endl;
	cout << "�ͻ����� TThostFtdcCustTypeType:" << pReqQueryAccount->CustType << endl;
	cout << "�����ʺ� TThostFtdcBankAccountType:" << pReqQueryAccount->BankAccount << endl;
	cout << "�������� TThostFtdcPasswordType:" << pReqQueryAccount->BankPassWord << endl;
	cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pReqQueryAccount->AccountID << endl;
	cout << "�ڻ����� TThostFtdcPasswordType:" << pReqQueryAccount->Password << endl;
	cout << "�ڻ���˾��ˮ�� TThostFtdcFutureSerialType:" << pReqQueryAccount->FutureSerial << endl;
	cout << "��װ��� TThostFtdcInstallIDType:" << pReqQueryAccount->InstallID << endl;
	cout << "�û���ʶ TThostFtdcUserIDType:" << pReqQueryAccount->UserID << endl;
	cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << pReqQueryAccount->VerifyCertNoFlag << endl;
	cout << "���ִ��� TThostFtdcCurrencyIDType:" << pReqQueryAccount->CurrencyID << endl;
	cout << "ժҪ TThostFtdcDigestType:" << pReqQueryAccount->Digest << endl;
	cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << pReqQueryAccount->BankAccType << endl;
	cout << "������־ TThostFtdcDeviceIDType:" << pReqQueryAccount->DeviceID << endl;
	cout << "�ڻ���λ�ʺ����� TThostFtdcBankAccTypeType:" << pReqQueryAccount->BankSecuAccType << endl;
	cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << pReqQueryAccount->BrokerIDByBank << endl;
	cout << "�ڻ���λ�ʺ� TThostFtdcBankAccountType:" << pReqQueryAccount->BankSecuAcc << endl;
	cout << "���������־ TThostFtdcPwdFlagType:" << pReqQueryAccount->BankPwdFlag << endl;
	cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << pReqQueryAccount->SecuPwdFlag << endl;
	cout << "���׹�Ա TThostFtdcOperNoType:" << pReqQueryAccount->OperNo << endl;
	cout << "������ TThostFtdcRequestIDType:" << pReqQueryAccount->RequestID << endl;
	// cout << "����ID:" << pReqQueryAccount->TThostFtdcTIDType << endlTID;
    }
}

///���з������ڿ���֪ͨ
void CTraderSpi::OnRtnOpenAccountByBank(CThostFtdcOpenAccountField* pOpenAccount)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "ҵ������ TThostFtdcTradeCodeType:" << pOpenAccount->TradeCode << endl;
    cout << "���д��� TThostFtdcBankIDType:" << pOpenAccount->BankID << endl;
    cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << pOpenAccount->BankBranchID << endl;
    cout << "���̴��� TThostFtdcBrokerIDType:" << pOpenAccount->BrokerID << endl;
    cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << pOpenAccount->BrokerBranchID << endl;
    cout << "�������� TThostFtdcTradeDateType:" << pOpenAccount->TradeDate << endl;
    cout << "����ʱ�� TThostFtdcTradeTimeType:" << pOpenAccount->TradeTime << endl;
    cout << "������ˮ�� TThostFtdcBankSerialType:" << pOpenAccount->BankSerial << endl;
    cout << "����ϵͳ���� TThostFtdcTradeDateType:" << pOpenAccount->TradingDay << endl;
    cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << pOpenAccount->PlateSerial << endl;
    cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << pOpenAccount->LastFragment << endl;
    cout << "�Ự�� TThostFtdcSessionIDType:" << pOpenAccount->SessionID << endl;
    cout << "�ͻ����� TThostFtdcIndividualNameType:" << pOpenAccount->CustomerName << endl;
    cout << "֤������ TThostFtdcIdCardTypeType:" << pOpenAccount->IdCardType << endl;
    cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pOpenAccount->IdentifiedCardNo << endl;
    cout << "�Ա� TThostFtdcGenderType:" << pOpenAccount->Gender << endl;
    cout << "���Ҵ��� TThostFtdcCountryCodeType:" << pOpenAccount->CountryCode << endl;
    cout << "�ͻ����� TThostFtdcCustTypeType:" << pOpenAccount->CustType << endl;
    cout << "��ַ TThostFtdcAddressType:" << pOpenAccount->Address << endl;
    cout << "�ʱ� TThostFtdcZipCodeType:" << pOpenAccount->ZipCode << endl;
    cout << "�绰���� TThostFtdcTelephoneType:" << pOpenAccount->Telephone << endl;
    cout << "�ֻ� TThostFtdcMobilePhoneType:" << pOpenAccount->MobilePhone << endl;
    cout << "���� TThostFtdcFaxType:" << pOpenAccount->Fax << endl;
    cout << "�����ʼ� TThostFtdcEMailType:" << pOpenAccount->EMail << endl;
    cout << "�ʽ��˻�״̬ TThostFtdcMoneyAccountStatusType:" << pOpenAccount->MoneyAccountStatus << endl;
    cout << "�����ʺ� TThostFtdcBankAccountType:" << pOpenAccount->BankAccount << endl;
    cout << "�������� TThostFtdcPasswordType:" << pOpenAccount->BankPassWord << endl;
    cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pOpenAccount->AccountID << endl;
    cout << "�ڻ����� TThostFtdcPasswordType:" << pOpenAccount->Password << endl;
    cout << "��װ��� TThostFtdcInstallIDType:" << pOpenAccount->InstallID << endl;
    cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << pOpenAccount->VerifyCertNoFlag << endl;
    cout << "���ִ��� TThostFtdcCurrencyIDType:" << pOpenAccount->CurrencyID << endl;
    cout << "�㳮��־ TThostFtdcCashExchangeCodeType:" << pOpenAccount->CashExchangeCode << endl;
    cout << "ժҪ TThostFtdcDigestType:" << pOpenAccount->Digest << endl;
    cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << pOpenAccount->BankAccType << endl;
    cout << "������־ TThostFtdcDeviceIDType:" << pOpenAccount->DeviceID << endl;
    cout << "�ڻ���λ�ʺ����� TThostFtdcBankAccTypeType:" << pOpenAccount->BankSecuAccType << endl;
    cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << pOpenAccount->BrokerIDByBank << endl;
    cout << "�ڻ���λ�ʺ� TThostFtdcBankAccountType:" << pOpenAccount->BankSecuAcc << endl;
    cout << "���������־ TThostFtdcPwdFlagType:" << pOpenAccount->BankPwdFlag << endl;
    cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << pOpenAccount->SecuPwdFlag << endl;
    cout << "���׹�Ա TThostFtdcOperNoType:" << pOpenAccount->OperNo << endl;
    // cout << "����ID:" << pOpenAccount->TThostFtdcTIDType << endlTID;
    cout << "�û���ʶ TThostFtdcUserIDType:" << pOpenAccount->UserID << endl;
    cout << "������� TThostFtdcErrorIDType:" << pOpenAccount->ErrorID << endl;
    cout << "������Ϣ TThostFtdcErrorMsgType:" << pOpenAccount->ErrorMsg << endl;
}

///���з�����������֪ͨ
void CTraderSpi::OnRtnCancelAccountByBank(CThostFtdcCancelAccountField* pCancelAccount)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "ҵ������ TThostFtdcTradeCodeType:" << pCancelAccount->TradeCode << endl;
    cout << "���д��� TThostFtdcBankIDType:" << pCancelAccount->BankID << endl;
    cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << pCancelAccount->BankBranchID << endl;
    cout << "���̴��� TThostFtdcBrokerIDType:" << pCancelAccount->BrokerID << endl;
    cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << pCancelAccount->BrokerBranchID << endl;
    cout << "�������� TThostFtdcTradeDateType:" << pCancelAccount->TradeDate << endl;
    cout << "����ʱ�� TThostFtdcTradeTimeType:" << pCancelAccount->TradeTime << endl;
    cout << "������ˮ�� TThostFtdcBankSerialType:" << pCancelAccount->BankSerial << endl;
    cout << "����ϵͳ���� TThostFtdcTradeDateType:" << pCancelAccount->TradingDay << endl;
    cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << pCancelAccount->PlateSerial << endl;
    cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << pCancelAccount->LastFragment << endl;
    cout << "�Ự�� TThostFtdcSessionIDType:" << pCancelAccount->SessionID << endl;
    cout << "�ͻ����� TThostFtdcIndividualNameType:" << pCancelAccount->CustomerName << endl;
    cout << "֤������ TThostFtdcIdCardTypeType:" << pCancelAccount->IdCardType << endl;
    cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pCancelAccount->IdentifiedCardNo << endl;
    cout << "�Ա� TThostFtdcGenderType:" << pCancelAccount->Gender << endl;
    cout << "���Ҵ��� TThostFtdcCountryCodeType:" << pCancelAccount->CountryCode << endl;
    cout << "�ͻ����� TThostFtdcCustTypeType:" << pCancelAccount->CustType << endl;
    cout << "��ַ TThostFtdcAddressType:" << pCancelAccount->Address << endl;
    cout << "�ʱ� TThostFtdcZipCodeType:" << pCancelAccount->ZipCode << endl;
    cout << "�绰���� TThostFtdcTelephoneType:" << pCancelAccount->Telephone << endl;
    cout << "�ֻ� TThostFtdcMobilePhoneType:" << pCancelAccount->MobilePhone << endl;
    cout << "���� TThostFtdcFaxType:" << pCancelAccount->Fax << endl;
    cout << "�����ʼ� TThostFtdcEMailType:" << pCancelAccount->EMail << endl;
    cout << "�ʽ��˻�״̬ TThostFtdcMoneyAccountStatusType:" << pCancelAccount->MoneyAccountStatus << endl;
    cout << "�����ʺ� TThostFtdcBankAccountType:" << pCancelAccount->BankAccount << endl;
    cout << "�������� TThostFtdcPasswordType:" << pCancelAccount->BankPassWord << endl;
    cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pCancelAccount->AccountID << endl;
    cout << "�ڻ����� TThostFtdcPasswordType:" << pCancelAccount->Password << endl;
    cout << "��װ��� TThostFtdcInstallIDType:" << pCancelAccount->InstallID << endl;
    cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << pCancelAccount->VerifyCertNoFlag << endl;
    cout << "���ִ��� TThostFtdcCurrencyIDType:" << pCancelAccount->CurrencyID << endl;
    cout << "�㳮��־ TThostFtdcCashExchangeCodeType:" << pCancelAccount->CashExchangeCode << endl;
    cout << "ժҪ TThostFtdcDigestType:" << pCancelAccount->Digest << endl;
    cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << pCancelAccount->BankAccType << endl;
    cout << "������־ TThostFtdcDeviceIDType:" << pCancelAccount->DeviceID << endl;
    cout << "�ڻ���λ�ʺ����� TThostFtdcBankAccTypeType:" << pCancelAccount->BankSecuAccType << endl;
    cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << pCancelAccount->BrokerIDByBank << endl;
    cout << "�ڻ���λ�ʺ� TThostFtdcBankAccountType:" << pCancelAccount->BankSecuAcc << endl;
    cout << "���������־ TThostFtdcPwdFlagType:" << pCancelAccount->BankPwdFlag << endl;
    cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << pCancelAccount->SecuPwdFlag << endl;
    cout << "���׹�Ա TThostFtdcOperNoType:" << pCancelAccount->OperNo << endl;
    // cout << "����ID:" << pCancelAccount->TThostFtdcTIDType << endlTID;
    cout << "�û���ʶ TThostFtdcUserIDType:" << pCancelAccount->UserID << endl;
    cout << "������� TThostFtdcErrorIDType:" << pCancelAccount->ErrorID << endl;
    cout << "������Ϣ TThostFtdcErrorMsgType:" << pCancelAccount->ErrorMsg << endl;
}

///���з����������˺�֪ͨ
void CTraderSpi::OnRtnChangeAccountByBank(CThostFtdcChangeAccountField* pChangeAccount)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "ҵ������ TThostFtdcTradeCodeType:" << pChangeAccount->TradeCode << endl;
    cout << "���д��� TThostFtdcBankIDType:" << pChangeAccount->BankID << endl;
    cout << "���з�֧�������� TThostFtdcBankBrchIDType:" << pChangeAccount->BankBranchID << endl;
    cout << "���̴��� TThostFtdcBrokerIDType:" << pChangeAccount->BrokerID << endl;
    cout << "���̷�֧�������� TThostFtdcFutureBranchIDType:" << pChangeAccount->BrokerBranchID << endl;
    cout << "�������� TThostFtdcTradeDateType:" << pChangeAccount->TradeDate << endl;
    cout << "����ʱ�� TThostFtdcTradeTimeType:" << pChangeAccount->TradeTime << endl;
    cout << "������ˮ�� TThostFtdcBankSerialType:" << pChangeAccount->BankSerial << endl;
    cout << "����ϵͳ���� TThostFtdcTradeDateType:" << pChangeAccount->TradingDay << endl;
    cout << "����ƽ̨��Ϣ��ˮ�� TThostFtdcSerialType:" << pChangeAccount->PlateSerial << endl;
    cout << "����Ƭ��־ TThostFtdcLastFragmentType:" << pChangeAccount->LastFragment << endl;
    cout << "�Ự�� TThostFtdcSessionIDType:" << pChangeAccount->SessionID << endl;
    cout << "�ͻ����� TThostFtdcIndividualNameType:" << pChangeAccount->CustomerName << endl;
    cout << "֤������ TThostFtdcIdCardTypeType:" << pChangeAccount->IdCardType << endl;
    cout << "֤������ TThostFtdcIdentifiedCardNoType:" << pChangeAccount->IdentifiedCardNo << endl;
    cout << "�Ա� TThostFtdcGenderType:" << pChangeAccount->Gender << endl;
    cout << "���Ҵ��� TThostFtdcCountryCodeType:" << pChangeAccount->CountryCode << endl;
    cout << "�ͻ����� TThostFtdcCustTypeType:" << pChangeAccount->CustType << endl;
    cout << "��ַ TThostFtdcAddressType:" << pChangeAccount->Address << endl;
    cout << "�ʱ� TThostFtdcZipCodeType:" << pChangeAccount->ZipCode << endl;
    cout << "�绰���� TThostFtdcTelephoneType:" << pChangeAccount->Telephone << endl;
    cout << "�ֻ� TThostFtdcMobilePhoneType:" << pChangeAccount->MobilePhone << endl;
    cout << "���� TThostFtdcFaxType:" << pChangeAccount->Fax << endl;
    cout << "�����ʼ� TThostFtdcEMailType:" << pChangeAccount->EMail << endl;
    cout << "�ʽ��˻�״̬ TThostFtdcMoneyAccountStatusType:" << pChangeAccount->MoneyAccountStatus << endl;
    cout << "�����ʺ� TThostFtdcBankAccountType:" << pChangeAccount->BankAccount << endl;
    cout << "�������� TThostFtdcPasswordType:" << pChangeAccount->BankPassWord << endl;
    cout << "�������ʺ� TThostFtdcBankAccountType:" << pChangeAccount->NewBankAccount << endl;
    cout << "���������� TThostFtdcPasswordType:" << pChangeAccount->NewBankPassWord << endl;
    cout << "Ͷ�����ʺ� TThostFtdcAccountIDType:" << pChangeAccount->AccountID << endl;
    cout << "�ڻ����� TThostFtdcPasswordType:" << pChangeAccount->Password << endl;
    cout << "�����ʺ����� TThostFtdcBankAccTypeType:" << pChangeAccount->BankAccType << endl;
    cout << "��װ��� TThostFtdcInstallIDType:" << pChangeAccount->InstallID << endl;
    cout << "��֤�ͻ�֤�������־ TThostFtdcYesNoIndicatorType:" << pChangeAccount->VerifyCertNoFlag << endl;
    cout << "���ִ��� TThostFtdcCurrencyIDType:" << pChangeAccount->CurrencyID << endl;
    cout << "�ڻ���˾���б��� TThostFtdcBankCodingForFutureType:" << pChangeAccount->BrokerIDByBank << endl;
    cout << "���������־ TThostFtdcPwdFlagType:" << pChangeAccount->BankPwdFlag << endl;
    cout << "�ڻ��ʽ�����˶Ա�־ TThostFtdcPwdFlagType:" << pChangeAccount->SecuPwdFlag << endl;
    // cout << "����ID:" << pChangeAccount->TThostFtdcTIDType << endlTID;
    cout << "ժҪ TThostFtdcDigestType:" << pChangeAccount->Digest << endl;
    cout << "������� TThostFtdcErrorIDType:" << pChangeAccount->ErrorID << endl;
    cout << "������Ϣ TThostFtdcErrorMsgType:" << pChangeAccount->ErrorMsg << endl;
}

