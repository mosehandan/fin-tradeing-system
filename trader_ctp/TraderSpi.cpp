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
//		//userapi = CThostFtdcTraderApi::CreateFtdcTraderApi("./log/trader/"); // 创建UserApi
//		userapi = CThostFtdcTraderApi::CreateFtdcTraderApi(); // 创建UserApi
//
//		if (!userapi) {
//			throw "CtpTrader failed to create api";
//		}
//		userapi->RegisterSpi(this);
//	}
//}

bool CTraderSpi::IsErrorRspInfo(CThostFtdcRspInfoField* pRspInfo)
{
    // 如果ErrorID != 0, 说明收到了错误的响应
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
	cout << "请输入要测试的函数编号,0为显示所有函数: ";
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

    cout << "可供测试的函数如下:" << endl;
    cout << "1 用户登录请求 ReqUserLogin" << endl;
    cout << "2 登出请求 ReqUserLogout" << endl;
    cout << "3 用户口令更新请求 ReqUserPasswordUpdate" << endl;
    cout << "4 资金账户口令更新请求 ReqTradingAccountPasswordUpdate" << endl;
    cout << "5 报单录入请求 ReqOrderInsert" << endl;
    cout << "6 预埋单录入请求 ReqParkedOrderInsert" << endl;
    cout << "7 预埋撤单录入请求 ReqParkedOrderAction" << endl;
    cout << "8 报单操作请求 ReqOrderAction" << endl;
    cout << "9 查询最大报单数量请求 ReqQueryMaxOrderVolume" << endl;
    cout << "10 投资者结算结果确认 ReqSettlementInfoConfirm" << endl;
    cout << "11 请求删除预埋单 ReqRemoveParkedOrder" << endl;
    cout << "12 请求删除预埋撤单 ReqRemoveParkedOrderAction" << endl;
    cout << "13 执行宣告录入请求 ReqExecOrderInsert" << endl;
    cout << "14 执行宣告操作请求 ReqExecOrderAction" << endl;
    cout << "15 询价录入请求 ReqForQuoteInsert" << endl;
    cout << "16 报价录入请求 ReqQuoteInsert" << endl;
    cout << "17 报价操作请求 ReqQuoteAction" << endl;
    cout << "18 锁定请求 ReqLockInsert" << endl;
    cout << "19 申请组合录入请求 ReqCombActionInsert" << endl;
    cout << "20 请求查询报单 ReqQryOrder" << endl;
    cout << "21 请求查询成交 ReqQryTrade" << endl;
    cout << "22 请求查询投资者持仓 ReqQryInvestorPosition" << endl;
    cout << "23 请求查询资金账户 ReqQryTradingAccount" << endl;
    cout << "24 请求查询投资者 ReqQryInvestor" << endl;
    cout << "25 请求查询交易编码 ReqQryTradingCode" << endl;
    cout << "26 请求查询合约保证金率 ReqQryInstrumentMarginRate" << endl;
    cout << "27 请求查询合约手续费率 ReqQryInstrumentCommissionRate" << endl;
    cout << "28 请求查询交易所 ReqQryExchange" << endl;
    cout << "29 请求查询产品 ReqQryProduct" << endl;
    cout << "30 请求查询合约 ReqQryInstrument" << endl;
    cout << "31 请求查询行情 ReqQryDepthMarketData" << endl;
    cout << "32 请求查询投资者结算结果 ReqQrySettlementInfo" << endl;
    cout << "33 请求查询转帐银行 ReqQryTransferBank" << endl;
    cout << "34 请求查询投资者持仓明细 ReqQryInvestorPositionDetail" << endl;
    cout << "35 请求查询客户通知 ReqQryNotice" << endl;
    cout << "36 请求查询结算信息确认 ReqQrySettlementInfoConfirm" << endl;
    cout << "37 请求查询投资者持仓明细 ReqQryInvestorPositionCombineDetail" << endl;
    cout << "38 请求查询保证金监管系统经纪公司资金账户密钥 ReqQryCFMMCTradingAccountKey" << endl;
    cout << "39 请求查询仓单折抵信息 ReqQryEWarrantOffset" << endl;
    cout << "40 请求查询投资者品种/跨品种保证金 ReqQryInvestorProductGroupMargin" << endl;
    cout << "41 请求查询交易所保证金率 ReqQryExchangeMarginRate" << endl;
    cout << "42 请求查询交易所调整保证金率 ReqQryExchangeMarginRateAdjust" << endl;
    cout << "43 请求查询汇率 ReqQryExchangeRate" << endl;
    cout << "44 请求查询二级代理操作员银期权限 ReqQrySecAgentACIDMap" << endl;
    cout << "45 请求查询产品报价汇率 ReqQryProductExchRate" << endl;
    cout << "46 请求查询产品组 ReqQryProductGroup" << endl;
    cout << "47 请求查询期权交易成本 ReqQryOptionInstrTradeCost" << endl;
    cout << "48 请求查询期权合约手续费 ReqQryOptionInstrCommRate" << endl;
    cout << "49 请求查询执行宣告 ReqQryExecOrder" << endl;
    cout << "50 请求查询询价 ReqQryForQuote" << endl;
    cout << "51 请求查询报价 ReqQryQuote" << endl;
    cout << "52 请求查询锁定 ReqQryLock" << endl;
    cout << "53 请求查询锁定证券仓位 ReqQryLockPosition" << endl;
    cout << "54 请求查询投资者分级 ReqQryInvestorLevel" << endl;
    cout << "55 请求查询E+1日行权冻结 ReqQryExecFreeze" << endl;
    cout << "56 请求查询组合合约安全系数 ReqQryCombInstrumentGuard" << endl;
    cout << "57 请求查询申请组合 ReqQryCombAction" << endl;
    cout << "58 请求查询转帐流水 ReqQryTransferSerial" << endl;
    cout << "59 请求查询银期签约关系 ReqQryAccountregister" << endl;
    cout << "60 请求查询签约银行 ReqQryContractBank" << endl;
    cout << "61 请求查询预埋单 ReqQryParkedOrder" << endl;
    cout << "62 请求查询预埋撤单 ReqQryParkedOrderAction" << endl;
    cout << "63 请求查询交易通知 ReqQryTradingNotice" << endl;
    cout << "64 请求查询经纪公司交易参数 ReqQryBrokerTradingParams" << endl;
    cout << "65 请求查询经纪公司交易算法 ReqQryBrokerTradingAlgos" << endl;
    cout << "66 请求查询监控中心用户令牌 ReqQueryCFMMCTradingAccountToken" << endl;
    cout << "67 期货发起银行资金转期货请求 ReqFromBankToFutureByFuture" << endl;
    cout << "68 期货发起期货资金转银行请求 ReqFromFutureToBankByFuture" << endl;
    cout << "69 期货发起查询银行余额请求 ReqQueryBankAccountMoneyByFuture" << endl;
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
    //该函数为手动编写
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
    //该函数为手动编写
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
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    strcpy(myreq.BrokerID, broker_id.c_str());
    cout << "用户代码 TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "用户端产品信息 TThostFtdcProductInfoType:" << endl;
    cin >> myreq.UserProductInfo;
    cout << "认证码 TThostFtdcAuthCodeType:" << endl;
    cin >> myreq.AuthCode;
    int i = userapi->ReqAuthenticate(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqUserLogin()
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
    int i = userapi->ReqUserLogin(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqUserLogout()
{
    CThostFtdcUserLogoutField myreq = CThostFtdcUserLogoutField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "用户代码 TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    int i = userapi->ReqUserLogout(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqUserPasswordUpdate()
{
    CThostFtdcUserPasswordUpdateField myreq = CThostFtdcUserPasswordUpdateField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "用户代码 TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "原来的口令 TThostFtdcPasswordType:" << endl;
    cin >> myreq.OldPassword;
    cout << "新的口令 TThostFtdcPasswordType:" << endl;
    cin >> myreq.NewPassword;
    int i = userapi->ReqUserPasswordUpdate(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqTradingAccountPasswordUpdate()
{
    CThostFtdcTradingAccountPasswordUpdateField myreq = CThostFtdcTradingAccountPasswordUpdateField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:";
    cin >> myreq.BrokerID;
    cout << "投资者帐号 TThostFtdcAccountIDType:" << endl;
    cin >> myreq.AccountID;
    cout << "原来的口令 TThostFtdcPasswordType:" << endl;
    cin >> myreq.OldPassword;
    cout << "新的口令 TThostFtdcPasswordType:" << endl;
    cin >> myreq.NewPassword;
    cout << "币种代码 TThostFtdcCurrencyIDType:" << endl;
    cin >> myreq.CurrencyID;
    int i = userapi->ReqTradingAccountPasswordUpdate(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqOrderInsert()
{
    CThostFtdcInputOrderField myreq = CThostFtdcInputOrderField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "报单引用 TThostFtdcOrderRefType:" << endl;
    cin >> myreq.OrderRef;
    cout << "用户代码 TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "报单价格条件 TThostFtdcOrderPriceTypeType:" << endl;
    cin >> myreq.OrderPriceType;
    cout << "买卖方向 TThostFtdcDirectionType:" << endl;
    cin >> myreq.Direction;
    cout << "组合开平标志 TThostFtdcCombOffsetFlagType:" << endl;
    cin >> myreq.CombOffsetFlag;
    cout << "组合投机套保标志 TThostFtdcCombHedgeFlagType:" << endl;
    cin >> myreq.CombHedgeFlag;
    cout << "价格 TThostFtdcPriceType:" << endl;
    cin >> myreq.LimitPrice;
    cout << "数量 TThostFtdcVolumeType:" << endl;
    cin >> myreq.VolumeTotalOriginal;
    cout << "有效期类型 TThostFtdcTimeConditionType:" << endl;
    cin >> myreq.TimeCondition;
    cout << "GTD日期 TThostFtdcDateType:" << endl;
    cin >> myreq.GTDDate;
    cout << "成交量类型 TThostFtdcVolumeConditionType:" << endl;
    cin >> myreq.VolumeCondition;
    cout << "最小成交量 TThostFtdcVolumeType:" << endl;
    cin >> myreq.MinVolume;
    cout << "触发条件 TThostFtdcContingentConditionType:" << endl;
    cin >> myreq.ContingentCondition;
    cout << "止损价 TThostFtdcPriceType:" << endl;
    cin >> myreq.StopPrice;
    cout << "强平原因 TThostFtdcForceCloseReasonType:" << endl;
    cin >> myreq.ForceCloseReason;
    cout << "自动挂起标志 TThostFtdcBoolType:" << endl;
    cin >> myreq.IsAutoSuspend;
    cout << "业务单元 TThostFtdcBusinessUnitType:" << endl;
    cin >> myreq.BusinessUnit;
    cout << "请求编号 TThostFtdcRequestIDType:" << endl;
    cin >> myreq.RequestID;
    cout << "用户强评标志 TThostFtdcBoolType:" << endl;
    cin >> myreq.UserForceClose;
    cout << "互换单标志 TThostFtdcBoolType:" << endl;
    cin >> myreq.IsSwapOrder;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqOrderInsert(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqParkedOrderInsert()
{
    CThostFtdcParkedOrderField myreq = CThostFtdcParkedOrderField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "报单引用 TThostFtdcOrderRefType:" << endl;
    cin >> myreq.OrderRef;
    cout << "用户代码 TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "报单价格条件 TThostFtdcOrderPriceTypeType:" << endl;
    cin >> myreq.OrderPriceType;
    cout << "买卖方向 TThostFtdcDirectionType:" << endl;
    cin >> myreq.Direction;
    cout << "组合开平标志 TThostFtdcCombOffsetFlagType:" << endl;
    cin >> myreq.CombOffsetFlag;
    cout << "组合投机套保标志 TThostFtdcCombHedgeFlagType:" << endl;
    cin >> myreq.CombHedgeFlag;
    cout << "价格 TThostFtdcPriceType:" << endl;
    cin >> myreq.LimitPrice;
    cout << "数量 TThostFtdcVolumeType:" << endl;
    cin >> myreq.VolumeTotalOriginal;
    cout << "有效期类型 TThostFtdcTimeConditionType:" << endl;
    cin >> myreq.TimeCondition;
    cout << "GTD日期 TThostFtdcDateType:" << endl;
    cin >> myreq.GTDDate;
    cout << "成交量类型 TThostFtdcVolumeConditionType:" << endl;
    cin >> myreq.VolumeCondition;
    cout << "最小成交量 TThostFtdcVolumeType:" << endl;
    cin >> myreq.MinVolume;
    cout << "触发条件 TThostFtdcContingentConditionType:" << endl;
    cin >> myreq.ContingentCondition;
    cout << "止损价 TThostFtdcPriceType:" << endl;
    cin >> myreq.StopPrice;
    cout << "强平原因 TThostFtdcForceCloseReasonType:" << endl;
    cin >> myreq.ForceCloseReason;
    cout << "自动挂起标志 TThostFtdcBoolType:" << endl;
    cin >> myreq.IsAutoSuspend;
    cout << "业务单元 TThostFtdcBusinessUnitType:" << endl;
    cin >> myreq.BusinessUnit;
    cout << "请求编号 TThostFtdcRequestIDType:" << endl;
    cin >> myreq.RequestID;
    cout << "用户强评标志 TThostFtdcBoolType:" << endl;
    cin >> myreq.UserForceClose;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "预埋报单编号 TThostFtdcParkedOrderIDType:" << endl;
    cin >> myreq.ParkedOrderID;
    cout << "用户类型 TThostFtdcUserTypeType:" << endl;
    cin >> myreq.UserType;
    cout << "预埋单状态 TThostFtdcParkedOrderStatusType:" << endl;
    cin >> myreq.Status;
    cout << "错误代码 TThostFtdcErrorIDType:" << endl;
    cin >> myreq.ErrorID;
    cout << "错误信息 TThostFtdcErrorMsgType:" << endl;
    cin >> myreq.ErrorMsg;
    cout << "互换单标志 TThostFtdcBoolType:" << endl;
    cin >> myreq.IsSwapOrder;
    int i = userapi->ReqParkedOrderInsert(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqParkedOrderAction()
{
    CThostFtdcParkedOrderActionField myreq = CThostFtdcParkedOrderActionField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "报单操作引用 TThostFtdcOrderActionRefType:" << endl;
    cin >> myreq.OrderActionRef;
    cout << "报单引用 TThostFtdcOrderRefType:" << endl;
    cin >> myreq.OrderRef;
    cout << "请求编号 TThostFtdcRequestIDType:" << endl;
    cin >> myreq.RequestID;
    cout << "前置编号 TThostFtdcFrontIDType:" << endl;
    cin >> myreq.FrontID;
    cout << "会话编号 TThostFtdcSessionIDType:" << endl;
    cin >> myreq.SessionID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "报单编号 TThostFtdcOrderSysIDType:" << endl;
    cin >> myreq.OrderSysID;
    cout << "操作标志 TThostFtdcActionFlagType:" << endl;
    cin >> myreq.ActionFlag;
    cout << "价格 TThostFtdcPriceType:" << endl;
    cin >> myreq.LimitPrice;
    cout << "数量变化 TThostFtdcVolumeType:" << endl;
    cin >> myreq.VolumeChange;
    cout << "用户代码 TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "预埋撤单单编号 TThostFtdcParkedOrderActionIDType:" << endl;
    cin >> myreq.ParkedOrderActionID;
    cout << "用户类型 TThostFtdcUserTypeType:" << endl;
    cin >> myreq.UserType;
    cout << "预埋撤单状态 TThostFtdcParkedOrderStatusType:" << endl;
    cin >> myreq.Status;
    cout << "错误代码 TThostFtdcErrorIDType:" << endl;
    cin >> myreq.ErrorID;
    cout << "错误信息 TThostFtdcErrorMsgType:" << endl;
    cin >> myreq.ErrorMsg;
    int i = userapi->ReqParkedOrderAction(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqOrderAction()
{
    CThostFtdcInputOrderActionField myreq = CThostFtdcInputOrderActionField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "报单操作引用 TThostFtdcOrderActionRefType:" << endl;
    cin >> myreq.OrderActionRef;
    cout << "报单引用 TThostFtdcOrderRefType:" << endl;
    cin >> myreq.OrderRef;
    cout << "请求编号 TThostFtdcRequestIDType:" << endl;
    cin >> myreq.RequestID;
    cout << "前置编号 TThostFtdcFrontIDType:" << endl;
    cin >> myreq.FrontID;
    cout << "会话编号 TThostFtdcSessionIDType:" << endl;
    cin >> myreq.SessionID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "报单编号 TThostFtdcOrderSysIDType:" << endl;
    cin >> myreq.OrderSysID;
    cout << "操作标志 TThostFtdcActionFlagType:" << endl;
    cin >> myreq.ActionFlag;
    cout << "价格 TThostFtdcPriceType:" << endl;
    cin >> myreq.LimitPrice;
    cout << "数量变化 TThostFtdcVolumeType:" << endl;
    cin >> myreq.VolumeChange;
    cout << "用户代码 TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    int i = userapi->ReqOrderAction(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQueryMaxOrderVolume()
{
    CThostFtdcQueryMaxOrderVolumeField myreq = CThostFtdcQueryMaxOrderVolumeField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "买卖方向 TThostFtdcDirectionType:" << endl;
    cin >> myreq.Direction;
    cout << "开平标志 TThostFtdcOffsetFlagType:" << endl;
    cin >> myreq.OffsetFlag;
    cout << "投机套保标志 TThostFtdcHedgeFlagType:" << endl;
    cin >> myreq.HedgeFlag;
    cout << "最大允许报单数量 TThostFtdcVolumeType:" << endl;
    cin >> myreq.MaxVolume;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQueryMaxOrderVolume(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqSettlementInfoConfirm()
{
    CThostFtdcSettlementInfoConfirmField myreq = CThostFtdcSettlementInfoConfirmField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "确认日期 TThostFtdcDateType:" << endl;
    cin >> myreq.ConfirmDate;
    cout << "确认时间 TThostFtdcTimeType:" << endl;
    cin >> myreq.ConfirmTime;
    int i = userapi->ReqSettlementInfoConfirm(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqRemoveParkedOrder()
{
    CThostFtdcRemoveParkedOrderField myreq = CThostFtdcRemoveParkedOrderField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "预埋报单编号 TThostFtdcParkedOrderIDType:" << endl;
    cin >> myreq.ParkedOrderID;
    int i = userapi->ReqRemoveParkedOrder(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqRemoveParkedOrderAction()
{
    CThostFtdcRemoveParkedOrderActionField myreq = CThostFtdcRemoveParkedOrderActionField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "预埋撤单编号 TThostFtdcParkedOrderActionIDType:" << endl;
    cin >> myreq.ParkedOrderActionID;
    int i = userapi->ReqRemoveParkedOrderAction(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqExecOrderInsert()
{
    CThostFtdcInputExecOrderField myreq = CThostFtdcInputExecOrderField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "执行宣告引用 TThostFtdcOrderRefType:" << endl;
    cin >> myreq.ExecOrderRef;
    cout << "用户代码 TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "数量 TThostFtdcVolumeType:" << endl;
    cin >> myreq.Volume;
    cout << "请求编号 TThostFtdcRequestIDType:" << endl;
    cin >> myreq.RequestID;
    cout << "业务单元 TThostFtdcBusinessUnitType:" << endl;
    cin >> myreq.BusinessUnit;
    cout << "开平标志 TThostFtdcOffsetFlagType:" << endl;
    cin >> myreq.OffsetFlag;
    cout << "投机套保标志 TThostFtdcHedgeFlagType:" << endl;
    cin >> myreq.HedgeFlag;
    cout << "执行类型 TThostFtdcActionTypeType:" << endl;
    cin >> myreq.ActionType;
    cout << "保留头寸申请的持仓方向 TThostFtdcPosiDirectionType:" << endl;
    cin >> myreq.PosiDirection;
    cout << "期权行权后是否保留期货头寸的标记 TThostFtdcExecOrderPositionFlagType:" << endl;
    cin >> myreq.ReservePositionFlag;
    cout << "期权行权后生成的头寸是否自动平仓 TThostFtdcExecOrderCloseFlagType:" << endl;
    cin >> myreq.CloseFlag;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqExecOrderInsert(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqExecOrderAction()
{
    CThostFtdcInputExecOrderActionField myreq = CThostFtdcInputExecOrderActionField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "执行宣告操作引用 TThostFtdcOrderActionRefType:" << endl;
    cin >> myreq.ExecOrderActionRef;
    cout << "执行宣告引用 TThostFtdcOrderRefType:" << endl;
    cin >> myreq.ExecOrderRef;
    cout << "请求编号 TThostFtdcRequestIDType:" << endl;
    cin >> myreq.RequestID;
    cout << "前置编号 TThostFtdcFrontIDType:" << endl;
    cin >> myreq.FrontID;
    cout << "会话编号 TThostFtdcSessionIDType:" << endl;
    cin >> myreq.SessionID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "执行宣告操作编号 TThostFtdcExecOrderSysIDType:" << endl;
    cin >> myreq.ExecOrderSysID;
    cout << "操作标志 TThostFtdcActionFlagType:" << endl;
    cin >> myreq.ActionFlag;
    cout << "用户代码 TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    int i = userapi->ReqExecOrderAction(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqForQuoteInsert()
{
    CThostFtdcInputForQuoteField myreq = CThostFtdcInputForQuoteField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "询价引用 TThostFtdcOrderRefType:" << endl;
    cin >> myreq.ForQuoteRef;
    cout << "用户代码 TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqForQuoteInsert(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQuoteInsert()
{
    CThostFtdcInputQuoteField myreq = CThostFtdcInputQuoteField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "报价引用 TThostFtdcOrderRefType:" << endl;
    cin >> myreq.QuoteRef;
    cout << "用户代码 TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "卖价格 TThostFtdcPriceType:" << endl;
    cin >> myreq.AskPrice;
    cout << "买价格 TThostFtdcPriceType:" << endl;
    cin >> myreq.BidPrice;
    cout << "卖数量 TThostFtdcVolumeType:" << endl;
    cin >> myreq.AskVolume;
    cout << "买数量 TThostFtdcVolumeType:" << endl;
    cin >> myreq.BidVolume;
    cout << "请求编号 TThostFtdcRequestIDType:" << endl;
    cin >> myreq.RequestID;
    cout << "业务单元 TThostFtdcBusinessUnitType:" << endl;
    cin >> myreq.BusinessUnit;
    cout << "卖开平标志 TThostFtdcOffsetFlagType:" << endl;
    cin >> myreq.AskOffsetFlag;
    cout << "买开平标志 TThostFtdcOffsetFlagType:" << endl;
    cin >> myreq.BidOffsetFlag;
    cout << "卖投机套保标志 TThostFtdcHedgeFlagType:" << endl;
    cin >> myreq.AskHedgeFlag;
    cout << "买投机套保标志 TThostFtdcHedgeFlagType:" << endl;
    cin >> myreq.BidHedgeFlag;
    cout << "衍生卖报单引用 TThostFtdcOrderRefType:" << endl;
    cin >> myreq.AskOrderRef;
    cout << "衍生买报单引用 TThostFtdcOrderRefType:" << endl;
    cin >> myreq.BidOrderRef;
    cout << "应价编号 TThostFtdcOrderSysIDType:" << endl;
    cin >> myreq.ForQuoteSysID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQuoteInsert(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQuoteAction()
{
    CThostFtdcInputQuoteActionField myreq = CThostFtdcInputQuoteActionField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "报价操作引用 TThostFtdcOrderActionRefType:" << endl;
    cin >> myreq.QuoteActionRef;
    cout << "报价引用 TThostFtdcOrderRefType:" << endl;
    cin >> myreq.QuoteRef;
    cout << "请求编号 TThostFtdcRequestIDType:" << endl;
    cin >> myreq.RequestID;
    cout << "前置编号 TThostFtdcFrontIDType:" << endl;
    cin >> myreq.FrontID;
    cout << "会话编号 TThostFtdcSessionIDType:" << endl;
    cin >> myreq.SessionID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "报价操作编号 TThostFtdcOrderSysIDType:" << endl;
    cin >> myreq.QuoteSysID;
    cout << "操作标志 TThostFtdcActionFlagType:" << endl;
    cin >> myreq.ActionFlag;
    cout << "用户代码 TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    int i = userapi->ReqQuoteAction(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqLockInsert()
{
    CThostFtdcInputLockField myreq = CThostFtdcInputLockField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "锁定引用 TThostFtdcOrderRefType:" << endl;
    cin >> myreq.LockRef;
    cout << "用户代码 TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "数量 TThostFtdcVolumeType:" << endl;
    cin >> myreq.Volume;
    cout << "请求编号 TThostFtdcRequestIDType:" << endl;
    cin >> myreq.RequestID;
    cout << "业务单元 TThostFtdcBusinessUnitType:" << endl;
    cin >> myreq.BusinessUnit;
    cout << "锁定类型 TThostFtdcLockTypeType:" << endl;
    cin >> myreq.LockType;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqLockInsert(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqCombActionInsert()
{
    CThostFtdcInputCombActionField myreq = CThostFtdcInputCombActionField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "组合引用 TThostFtdcOrderRefType:" << endl;
    cin >> myreq.CombActionRef;
    cout << "用户代码 TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "买卖方向 TThostFtdcDirectionType:" << endl;
    cin >> myreq.Direction;
    cout << "数量 TThostFtdcVolumeType:" << endl;
    cin >> myreq.Volume;
    cout << "组合指令方向 TThostFtdcCombDirectionType:" << endl;
    cin >> myreq.CombDirection;
    cout << "投机套保标志 TThostFtdcHedgeFlagType:" << endl;
    cin >> myreq.HedgeFlag;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqCombActionInsert(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryOrder()
{
    CThostFtdcQryOrderField myreq = CThostFtdcQryOrderField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "报单编号 TThostFtdcOrderSysIDType:" << endl;
    cin >> myreq.OrderSysID;
    cout << "开始时间 TThostFtdcTimeType:" << endl;
    cin >> myreq.InsertTimeStart;
    cout << "结束时间 TThostFtdcTimeType:" << endl;
    cin >> myreq.InsertTimeEnd;
    int i = userapi->ReqQryOrder(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryTrade()
{
    CThostFtdcQryTradeField myreq = CThostFtdcQryTradeField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "成交编号 TThostFtdcTradeIDType:" << endl;
    cin >> myreq.TradeID;
    cout << "开始时间 TThostFtdcTimeType:" << endl;
    cin >> myreq.TradeTimeStart;
    cout << "结束时间 TThostFtdcTimeType:" << endl;
    cin >> myreq.TradeTimeEnd;
    int i = userapi->ReqQryTrade(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryInvestorPosition()
{
    CThostFtdcQryInvestorPositionField myreq = CThostFtdcQryInvestorPositionField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryInvestorPosition(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryTradingAccount()
{
    CThostFtdcQryTradingAccountField myreq = CThostFtdcQryTradingAccountField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "币种代码 TThostFtdcCurrencyIDType:" << endl;
    cin >> myreq.CurrencyID;
    cout << "业务类型 TThostFtdcBizTypeType:" << endl;
    cin >> myreq.BizType;
    int i = userapi->ReqQryTradingAccount(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryInvestor()
{
    CThostFtdcQryInvestorField myreq = CThostFtdcQryInvestorField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    int i = userapi->ReqQryInvestor(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryTradingCode()
{
    CThostFtdcQryTradingCodeField myreq = CThostFtdcQryTradingCodeField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "客户代码 TThostFtdcClientIDType:" << endl;
    cin >> myreq.ClientID;
    cout << "交易编码类型 TThostFtdcClientIDTypeType:" << endl;
    cin >> myreq.ClientIDType;
    int i = userapi->ReqQryTradingCode(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryInstrumentMarginRate()
{
    CThostFtdcQryInstrumentMarginRateField myreq = CThostFtdcQryInstrumentMarginRateField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "投机套保标志 TThostFtdcHedgeFlagType:" << endl;
    cin >> myreq.HedgeFlag;
    int i = userapi->ReqQryInstrumentMarginRate(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryInstrumentCommissionRate()
{
    CThostFtdcQryInstrumentCommissionRateField myreq = CThostFtdcQryInstrumentCommissionRateField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryInstrumentCommissionRate(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryExchange()
{
    CThostFtdcQryExchangeField myreq = CThostFtdcQryExchangeField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryExchange(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryProduct()
{
    CThostFtdcQryProductField myreq = CThostFtdcQryProductField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "产品代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.ProductID;
    cout << "产品类型 TThostFtdcProductClassType:" << endl;
    cin >> myreq.ProductClass;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryProduct(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryInstrument()
{
    CThostFtdcQryInstrumentField myreq = CThostFtdcQryInstrumentField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "合约在交易所的代码 TThostFtdcExchangeInstIDType:" << endl;
    cin >> myreq.ExchangeInstID;
    cout << "产品代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.ProductID;
    int i = userapi->ReqQryInstrument(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryDepthMarketData()
{
    CThostFtdcQryDepthMarketDataField myreq = CThostFtdcQryDepthMarketDataField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryDepthMarketData(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQrySettlementInfo()
{
    CThostFtdcQrySettlementInfoField myreq = CThostFtdcQrySettlementInfoField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "交易日 TThostFtdcDateType:" << endl;
    cin >> myreq.TradingDay;
    int i = userapi->ReqQrySettlementInfo(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryTransferBank()
{
    CThostFtdcQryTransferBankField myreq = CThostFtdcQryTransferBankField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "银行代码 TThostFtdcBankIDType:" << endl;
    cin >> myreq.BankID;
    cout << "银行分中心代码 TThostFtdcBankBrchIDType:" << endl;
    cin >> myreq.BankBrchID;
    int i = userapi->ReqQryTransferBank(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryInvestorPositionDetail()
{
    CThostFtdcQryInvestorPositionDetailField myreq = CThostFtdcQryInvestorPositionDetailField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryInvestorPositionDetail(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryNotice()
{
    CThostFtdcQryNoticeField myreq = CThostFtdcQryNoticeField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    int i = userapi->ReqQryNotice(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQrySettlementInfoConfirm()
{
    CThostFtdcQrySettlementInfoConfirmField myreq = CThostFtdcQrySettlementInfoConfirmField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    int i = userapi->ReqQrySettlementInfoConfirm(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryInvestorPositionCombineDetail()
{
    CThostFtdcQryInvestorPositionCombineDetailField myreq = CThostFtdcQryInvestorPositionCombineDetailField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "组合持仓合约编码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.CombInstrumentID;
    int i = userapi->ReqQryInvestorPositionCombineDetail(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryCFMMCTradingAccountKey()
{
    CThostFtdcQryCFMMCTradingAccountKeyField myreq = CThostFtdcQryCFMMCTradingAccountKeyField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    int i = userapi->ReqQryCFMMCTradingAccountKey(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryEWarrantOffset()
{
    CThostFtdcQryEWarrantOffsetField myreq = CThostFtdcQryEWarrantOffsetField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    int i = userapi->ReqQryEWarrantOffset(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryInvestorProductGroupMargin()
{
    CThostFtdcQryInvestorProductGroupMarginField myreq = CThostFtdcQryInvestorProductGroupMarginField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "品种/跨品种标示 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.ProductGroupID;
    cout << "投机套保标志 TThostFtdcHedgeFlagType:" << endl;
    cin >> myreq.HedgeFlag;
    int i = userapi->ReqQryInvestorProductGroupMargin(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryExchangeMarginRate()
{
    CThostFtdcQryExchangeMarginRateField myreq = CThostFtdcQryExchangeMarginRateField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "投机套保标志 TThostFtdcHedgeFlagType:" << endl;
    cin >> myreq.HedgeFlag;
    int i = userapi->ReqQryExchangeMarginRate(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryExchangeMarginRateAdjust()
{
    CThostFtdcQryExchangeMarginRateAdjustField myreq = CThostFtdcQryExchangeMarginRateAdjustField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "投机套保标志 TThostFtdcHedgeFlagType:" << endl;
    cin >> myreq.HedgeFlag;
    int i = userapi->ReqQryExchangeMarginRateAdjust(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryExchangeRate()
{
    CThostFtdcQryExchangeRateField myreq = CThostFtdcQryExchangeRateField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "源币种 TThostFtdcCurrencyIDType:" << endl;
    cin >> myreq.FromCurrencyID;
    cout << "目标币种 TThostFtdcCurrencyIDType:" << endl;
    cin >> myreq.ToCurrencyID;
    int i = userapi->ReqQryExchangeRate(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQrySecAgentACIDMap()
{
    CThostFtdcQrySecAgentACIDMapField myreq = CThostFtdcQrySecAgentACIDMapField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "用户代码 TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "资金账户 TThostFtdcAccountIDType:" << endl;
    cin >> myreq.AccountID;
    cout << "币种 TThostFtdcCurrencyIDType:" << endl;
    cin >> myreq.CurrencyID;
    int i = userapi->ReqQrySecAgentACIDMap(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryProductExchRate()
{
    CThostFtdcQryProductExchRateField myreq = CThostFtdcQryProductExchRateField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "产品代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.ProductID;
    int i = userapi->ReqQryProductExchRate(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryProductGroup()
{
    CThostFtdcQryProductGroupField myreq = CThostFtdcQryProductGroupField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "产品代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.ProductID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryProductGroup(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryOptionInstrTradeCost()
{
    CThostFtdcQryOptionInstrTradeCostField myreq = CThostFtdcQryOptionInstrTradeCostField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "投机套保标志 TThostFtdcHedgeFlagType:" << endl;
    cin >> myreq.HedgeFlag;
    cout << "期权合约报价 TThostFtdcPriceType:" << endl;
    cin >> myreq.InputPrice;
    cout << "标的价格,填0则用昨结算价 TThostFtdcPriceType:" << endl;
    cin >> myreq.UnderlyingPrice;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryOptionInstrTradeCost(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryOptionInstrCommRate()
{
    CThostFtdcQryOptionInstrCommRateField myreq = CThostFtdcQryOptionInstrCommRateField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryOptionInstrCommRate(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryExecOrder()
{
    CThostFtdcQryExecOrderField myreq = CThostFtdcQryExecOrderField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "执行宣告编号 TThostFtdcExecOrderSysIDType:" << endl;
    cin >> myreq.ExecOrderSysID;
    cout << "开始时间 TThostFtdcTimeType:" << endl;
    cin >> myreq.InsertTimeStart;
    cout << "结束时间 TThostFtdcTimeType:" << endl;
    cin >> myreq.InsertTimeEnd;
    int i = userapi->ReqQryExecOrder(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryForQuote()
{
    CThostFtdcQryForQuoteField myreq = CThostFtdcQryForQuoteField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "开始时间 TThostFtdcTimeType:" << endl;
    cin >> myreq.InsertTimeStart;
    cout << "结束时间 TThostFtdcTimeType:" << endl;
    cin >> myreq.InsertTimeEnd;
    int i = userapi->ReqQryForQuote(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryQuote()
{
    CThostFtdcQryQuoteField myreq = CThostFtdcQryQuoteField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "报价编号 TThostFtdcOrderSysIDType:" << endl;
    cin >> myreq.QuoteSysID;
    cout << "开始时间 TThostFtdcTimeType:" << endl;
    cin >> myreq.InsertTimeStart;
    cout << "结束时间 TThostFtdcTimeType:" << endl;
    cin >> myreq.InsertTimeEnd;
    int i = userapi->ReqQryQuote(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryLock()
{
    CThostFtdcQryLockField myreq = CThostFtdcQryLockField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "锁定编号 TThostFtdcOrderSysIDType:" << endl;
    cin >> myreq.LockSysID;
    cout << "开始时间 TThostFtdcTimeType:" << endl;
    cin >> myreq.InsertTimeStart;
    cout << "结束时间 TThostFtdcTimeType:" << endl;
    cin >> myreq.InsertTimeEnd;
    int i = userapi->ReqQryLock(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryLockPosition()
{
    CThostFtdcQryLockPositionField myreq = CThostFtdcQryLockPositionField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryLockPosition(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryInvestorLevel()
{
    CThostFtdcQryInvestorLevelField myreq = CThostFtdcQryInvestorLevelField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryInvestorLevel(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryExecFreeze()
{
    CThostFtdcQryExecFreezeField myreq = CThostFtdcQryExecFreezeField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryExecFreeze(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryCombInstrumentGuard()
{
    CThostFtdcQryCombInstrumentGuardField myreq = CThostFtdcQryCombInstrumentGuardField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    int i = userapi->ReqQryCombInstrumentGuard(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryCombAction()
{
    CThostFtdcQryCombActionField myreq = CThostFtdcQryCombActionField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryCombAction(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryTransferSerial()
{
    CThostFtdcQryTransferSerialField myreq = CThostFtdcQryTransferSerialField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者帐号 TThostFtdcAccountIDType:" << endl;
    cin >> myreq.AccountID;
    cout << "银行编码 TThostFtdcBankIDType:" << endl;
    cin >> myreq.BankID;
    cout << "币种代码 TThostFtdcCurrencyIDType:" << endl;
    cin >> myreq.CurrencyID;
    int i = userapi->ReqQryTransferSerial(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryAccountregister()
{
    CThostFtdcQryAccountregisterField myreq = CThostFtdcQryAccountregisterField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者帐号 TThostFtdcAccountIDType:" << endl;
    cin >> myreq.AccountID;
    cout << "银行编码 TThostFtdcBankIDType:" << endl;
    cin >> myreq.BankID;
    cout << "银行分支机构编码 TThostFtdcBankBrchIDType:" << endl;
    cin >> myreq.BankBranchID;
    cout << "币种代码 TThostFtdcCurrencyIDType:" << endl;
    cin >> myreq.CurrencyID;
    int i = userapi->ReqQryAccountregister(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryContractBank()
{
    CThostFtdcQryContractBankField myreq = CThostFtdcQryContractBankField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "银行代码 TThostFtdcBankIDType:" << endl;
    cin >> myreq.BankID;
    cout << "银行分中心代码 TThostFtdcBankBrchIDType:" << endl;
    cin >> myreq.BankBrchID;
    int i = userapi->ReqQryContractBank(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryParkedOrder()
{
    CThostFtdcQryParkedOrderField myreq = CThostFtdcQryParkedOrderField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryParkedOrder(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryParkedOrderAction()
{
    CThostFtdcQryParkedOrderActionField myreq = CThostFtdcQryParkedOrderActionField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    int i = userapi->ReqQryParkedOrderAction(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryTradingNotice()
{
    CThostFtdcQryTradingNoticeField myreq = CThostFtdcQryTradingNoticeField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    int i = userapi->ReqQryTradingNotice(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryBrokerTradingParams()
{
    CThostFtdcQryBrokerTradingParamsField myreq = CThostFtdcQryBrokerTradingParamsField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    cout << "币种代码 TThostFtdcCurrencyIDType:" << endl;
    cin >> myreq.CurrencyID;
    int i = userapi->ReqQryBrokerTradingParams(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQryBrokerTradingAlgos()
{
    CThostFtdcQryBrokerTradingAlgosField myreq = CThostFtdcQryBrokerTradingAlgosField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << endl;
    cin >> myreq.ExchangeID;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << endl;
    cin >> myreq.InstrumentID;
    int i = userapi->ReqQryBrokerTradingAlgos(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQueryCFMMCTradingAccountToken()
{
    CThostFtdcQueryCFMMCTradingAccountTokenField myreq = CThostFtdcQueryCFMMCTradingAccountTokenField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << endl;
    cin >> myreq.InvestorID;
    int i = userapi->ReqQueryCFMMCTradingAccountToken(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqFromBankToFutureByFuture()
{
    CThostFtdcReqTransferField myreq = CThostFtdcReqTransferField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "业务功能码 TThostFtdcTradeCodeType:" << endl;
    cin >> myreq.TradeCode;
    cout << "银行代码 TThostFtdcBankIDType:" << endl;
    cin >> myreq.BankID;
    cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << endl;
    cin >> myreq.BankBranchID;
    cout << "期商代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << endl;
    cin >> myreq.BrokerBranchID;
    cout << "交易日期 TThostFtdcTradeDateType:" << endl;
    cin >> myreq.TradeDate;
    cout << "交易时间 TThostFtdcTradeTimeType:" << endl;
    cin >> myreq.TradeTime;
    cout << "银行流水号 TThostFtdcBankSerialType:" << endl;
    cin >> myreq.BankSerial;
    // cout << "交易系统日期 TThostFtdcTradeDateType	TradingDa:" << endl;
    // cin >> myreq.;
    cout << "银期平台消息流水号 TThostFtdcSerialType:" << endl;
    cin >> myreq.PlateSerial;
    cout << "最后分片标志 TThostFtdcLastFragmentType:" << endl;
    cin >> myreq.LastFragment;
    cout << "会话号 TThostFtdcSessionIDType:" << endl;
    cin >> myreq.SessionID;
    cout << "客户姓名 TThostFtdcIndividualNameType:" << endl;
    cin >> myreq.CustomerName;
    cout << "证件类型 TThostFtdcIdCardTypeType:" << endl;
    cin >> myreq.IdCardType;
    cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << endl;
    cin >> myreq.IdentifiedCardNo;
    cout << "客户类型 TThostFtdcCustTypeType:" << endl;
    cin >> myreq.CustType;
    cout << "银行帐号 TThostFtdcBankAccountType:" << endl;
    cin >> myreq.BankAccount;
    cout << "银行密码 TThostFtdcPasswordType:" << endl;
    cin >> myreq.BankPassWord;
    cout << "投资者帐号 TThostFtdcAccountIDType:" << endl;
    cin >> myreq.AccountID;
    cout << "期货密码 TThostFtdcPasswordType:" << endl;
    strcpy(myreq.Password, passwd.c_str());
    cout << "安装编号 TThostFtdcInstallIDType:" << endl;
    cin >> myreq.InstallID;
    cout << "期货公司流水号 TThostFtdcFutureSerialType:" << endl;
    cin >> myreq.FutureSerial;
    cout << "用户标识 TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << endl;
    cin >> myreq.VerifyCertNoFlag;
    cout << "币种代码 TThostFtdcCurrencyIDType:" << endl;
    cin >> myreq.CurrencyID;
    cout << "转帐金额 TThostFtdcTradeAmountType:" << endl;
    cin >> myreq.TradeAmount;
    cout << "期货可取金额 TThostFtdcTradeAmountType:" << endl;
    cin >> myreq.FutureFetchAmount;
    cout << "费用支付标志 TThostFtdcFeePayFlagType:" << endl;
    cin >> myreq.FeePayFlag;
    cout << "应收客户费用 TThostFtdcCustFeeType:" << endl;
    cin >> myreq.CustFee;
    cout << "应收期货公司费用 TThostFtdcFutureFeeType:" << endl;
    cin >> myreq.BrokerFee;
    cout << "发送方给接收方的消息 TThostFtdcAddInfoType:" << endl;
    cin >> myreq.Message;
    cout << "摘要 TThostFtdcDigestType:" << endl;
    cin >> myreq.Digest;
    cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << endl;
    cin >> myreq.BankAccType;
    cout << "渠道标志 TThostFtdcDeviceIDType:" << endl;
    cin >> myreq.DeviceID;
    cout << "期货单位帐号类型 TThostFtdcBankAccTypeType:" << endl;
    cin >> myreq.BankSecuAccType;
    cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << endl;
    cin >> myreq.BrokerIDByBank;
    cout << "期货单位帐号 TThostFtdcBankAccountType:" << endl;
    cin >> myreq.BankSecuAcc;
    cout << "银行密码标志 TThostFtdcPwdFlagType:" << endl;
    cin >> myreq.BankPwdFlag;
    cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << endl;
    cin >> myreq.SecuPwdFlag;
    cout << "交易柜员 TThostFtdcOperNoType:" << endl;
    cin >> myreq.OperNo;
    cout << "请求编号 TThostFtdcRequestIDType:" << endl;
    cin >> myreq.RequestID;
    cout << "交易ID TThostFtdcTIDType:" << endl;
    cin >> myreq.TID;
    cout << "转账交易状态 TThostFtdcTransferStatusType:" << endl;
    cin >> myreq.TransferStatus;
    int i = userapi->ReqFromBankToFutureByFuture(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqFromFutureToBankByFuture()
{
    CThostFtdcReqTransferField myreq = CThostFtdcReqTransferField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "业务功能码 TThostFtdcTradeCodeType:" << endl;
    cin >> myreq.TradeCode;
    cout << "银行代码 TThostFtdcBankIDType:" << endl;
    cin >> myreq.BankID;
    cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << endl;
    cin >> myreq.BankBranchID;
    cout << "期商代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << endl;
    cin >> myreq.BrokerBranchID;
    cout << "交易日期 TThostFtdcTradeDateType:" << endl;
    cin >> myreq.TradeDate;
    cout << "交易时间 TThostFtdcTradeTimeType:" << endl;
    cin >> myreq.TradeTime;
    cout << "银行流水号 TThostFtdcBankSerialType:" << endl;
    cin >> myreq.BankSerial;
    // cout << "交易系统日期 TThostFtdcTradeDateType	TradingDa:" << endl;
    // cin >> myreq.;
    cout << "银期平台消息流水号 TThostFtdcSerialType:" << endl;
    cin >> myreq.PlateSerial;
    cout << "最后分片标志 TThostFtdcLastFragmentType:" << endl;
    cin >> myreq.LastFragment;
    cout << "会话号 TThostFtdcSessionIDType:" << endl;
    cin >> myreq.SessionID;
    cout << "客户姓名 TThostFtdcIndividualNameType:" << endl;
    cin >> myreq.CustomerName;
    cout << "证件类型 TThostFtdcIdCardTypeType:" << endl;
    cin >> myreq.IdCardType;
    cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << endl;
    cin >> myreq.IdentifiedCardNo;
    cout << "客户类型 TThostFtdcCustTypeType:" << endl;
    cin >> myreq.CustType;
    cout << "银行帐号 TThostFtdcBankAccountType:" << endl;
    cin >> myreq.BankAccount;
    cout << "银行密码 TThostFtdcPasswordType:" << endl;
    cin >> myreq.BankPassWord;
    cout << "投资者帐号 TThostFtdcAccountIDType:" << endl;
    cin >> myreq.AccountID;
    cout << "期货密码 TThostFtdcPasswordType:" << endl;
    strcpy(myreq.Password, passwd.c_str());
    cout << "安装编号 TThostFtdcInstallIDType:" << endl;
    cin >> myreq.InstallID;
    cout << "期货公司流水号 TThostFtdcFutureSerialType:" << endl;
    cin >> myreq.FutureSerial;
    cout << "用户标识 TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << endl;
    cin >> myreq.VerifyCertNoFlag;
    cout << "币种代码 TThostFtdcCurrencyIDType:" << endl;
    cin >> myreq.CurrencyID;
    cout << "转帐金额 TThostFtdcTradeAmountType:" << endl;
    cin >> myreq.TradeAmount;
    cout << "期货可取金额 TThostFtdcTradeAmountType:" << endl;
    cin >> myreq.FutureFetchAmount;
    cout << "费用支付标志 TThostFtdcFeePayFlagType:" << endl;
    cin >> myreq.FeePayFlag;
    cout << "应收客户费用 TThostFtdcCustFeeType:" << endl;
    cin >> myreq.CustFee;
    cout << "应收期货公司费用 TThostFtdcFutureFeeType:" << endl;
    cin >> myreq.BrokerFee;
    cout << "发送方给接收方的消息 TThostFtdcAddInfoType:" << endl;
    cin >> myreq.Message;
    cout << "摘要 TThostFtdcDigestType:" << endl;
    cin >> myreq.Digest;
    cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << endl;
    cin >> myreq.BankAccType;
    cout << "渠道标志 TThostFtdcDeviceIDType:" << endl;
    cin >> myreq.DeviceID;
    cout << "期货单位帐号类型 TThostFtdcBankAccTypeType:" << endl;
    cin >> myreq.BankSecuAccType;
    cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << endl;
    cin >> myreq.BrokerIDByBank;
    cout << "期货单位帐号 TThostFtdcBankAccountType:" << endl;
    cin >> myreq.BankSecuAcc;
    cout << "银行密码标志 TThostFtdcPwdFlagType:" << endl;
    cin >> myreq.BankPwdFlag;
    cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << endl;
    cin >> myreq.SecuPwdFlag;
    cout << "交易柜员 TThostFtdcOperNoType:" << endl;
    cin >> myreq.OperNo;
    cout << "请求编号 TThostFtdcRequestIDType:" << endl;
    cin >> myreq.RequestID;
    cout << "交易ID TThostFtdcTIDType:" << endl;
    cin >> myreq.TID;
    cout << "转账交易状态 TThostFtdcTransferStatusType:" << endl;
    cin >> myreq.TransferStatus;
    int i = userapi->ReqFromFutureToBankByFuture(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};

void CTraderSpi::reqQueryBankAccountMoneyByFuture()
{
    CThostFtdcReqQueryAccountField myreq = CThostFtdcReqQueryAccountField();
    memset(&myreq, 0, sizeof(myreq));
    cout << "业务功能码 TThostFtdcTradeCodeType:" << endl;
    cin >> myreq.TradeCode;
    cout << "银行代码 TThostFtdcBankIDType:" << endl;
    cin >> myreq.BankID;
    cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << endl;
    cin >> myreq.BankBranchID;
    cout << "期商代码 TThostFtdcBrokerIDType:" << endl;
    cin >> myreq.BrokerID;
    cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << endl;
    cin >> myreq.BrokerBranchID;
    cout << "交易日期 TThostFtdcTradeDateType:" << endl;
    cin >> myreq.TradeDate;
    cout << "交易时间 TThostFtdcTradeTimeType:" << endl;
    cin >> myreq.TradeTime;
    cout << "银行流水号 TThostFtdcBankSerialType:" << endl;
    cin >> myreq.BankSerial;
    cout << "交易系统日期 TThostFtdcTradeDateType:" << endl;
    cin >> myreq.TradingDay;
    cout << "银期平台消息流水号 TThostFtdcSerialType:" << endl;
    cin >> myreq.PlateSerial;
    cout << "最后分片标志 TThostFtdcLastFragmentType:" << endl;
    cin >> myreq.LastFragment;
    cout << "会话号 TThostFtdcSessionIDType:" << endl;
    cin >> myreq.SessionID;
    cout << "客户姓名 TThostFtdcIndividualNameType:" << endl;
    cin >> myreq.CustomerName;
    cout << "证件类型 TThostFtdcIdCardTypeType:" << endl;
    cin >> myreq.IdCardType;
    cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << endl;
    cin >> myreq.IdentifiedCardNo;
    cout << "客户类型 TThostFtdcCustTypeType:" << endl;
    cin >> myreq.CustType;
    cout << "银行帐号 TThostFtdcBankAccountType:" << endl;
    cin >> myreq.BankAccount;
    cout << "银行密码 TThostFtdcPasswordType:" << endl;
    cin >> myreq.BankPassWord;
    cout << "投资者帐号 TThostFtdcAccountIDType:" << endl;
    cin >> myreq.AccountID;
    cout << "期货密码 TThostFtdcPasswordType:" << endl;
    strcpy(myreq.Password, passwd.c_str());
    cout << "期货公司流水号 TThostFtdcFutureSerialType:" << endl;
    cin >> myreq.FutureSerial;
    cout << "安装编号 TThostFtdcInstallIDType:" << endl;
    cin >> myreq.InstallID;
    cout << "用户标识 TThostFtdcUserIDType:" << endl;
    strcpy(myreq.UserID, user_id.c_str());
    cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << endl;
    cin >> myreq.VerifyCertNoFlag;
    cout << "币种代码 TThostFtdcCurrencyIDType:" << endl;
    cin >> myreq.CurrencyID;
    cout << "摘要 TThostFtdcDigestType:" << endl;
    cin >> myreq.Digest;
    cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << endl;
    cin >> myreq.BankAccType;
    cout << "渠道标志 TThostFtdcDeviceIDType:" << endl;
    cin >> myreq.DeviceID;
    cout << "期货单位帐号类型 TThostFtdcBankAccTypeType:" << endl;
    cin >> myreq.BankSecuAccType;
    cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << endl;
    cin >> myreq.BrokerIDByBank;
    cout << "期货单位帐号 TThostFtdcBankAccountType:" << endl;
    cin >> myreq.BankSecuAcc;
    cout << "银行密码标志 TThostFtdcPwdFlagType:" << endl;
    cin >> myreq.BankPwdFlag;
    cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << endl;
    cin >> myreq.SecuPwdFlag;
    cout << "交易柜员 TThostFtdcOperNoType:" << endl;
    cin >> myreq.OperNo;
    cout << "请求编号 TThostFtdcRequestIDType:" << endl;
    cin >> myreq.RequestID;
    cout << "交易ID TThostFtdcTIDType:" << endl;
    cin >> myreq.TID;
    int i = userapi->ReqQueryBankAccountMoneyByFuture(&myreq, ++nRequestID);
    cout << "--->>> send request: " << (i == 0 ? "success" : "failed") << endl;
};
///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
void CTraderSpi::OnFrontConnected()
{
    cout << "--->>> "
	 << "OnFrontConnected" << endl;
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
void CTraderSpi::OnFrontDisconnected(int nReason)
{
    cout << "--->>> "
	 << "OnFrontDisconnected"
	 << "--->>> Reason = " << hex << nReason << endl;
}

///心跳超时警告。当长时间未收到报文时，该方法被调用。
///@param nTimeLapse 距离上次接收报文的时间
void CTraderSpi::OnHeartBeatWarning(int nTimeLapse)
{
    cout << "--->>> "
	 << "OnHeartBeatWarning"
	 << "--->>> nTimerLapse = " << nTimeLapse << endl;
}

///客户端认证响应
void CTraderSpi::OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pRspAuthenticateField->BrokerID << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pRspAuthenticateField->UserID << endl;
	cout << "用户端产品信息 TThostFtdcProductInfoType:" << pRspAuthenticateField->UserProductInfo << endl;
    }
}

///登录请求响应
void CTraderSpi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
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

	// FRONT_ID = pRspUserLogin->FrontID;
	// SESSION_ID = pRspUserLogin->SessionID;
	// int iNextOrderRef = atoi(pRspUserLogin->MaxOrderRef);
	// iNextOrderRef++;
	// sprintf(ORDER_REF, "%d", iNextOrderRef);
	///获取当前交易日
	// cout << "--->>> call api function GetTradingDay = " << userapi->GetTradingDay() << endl;
	///投资者结算结果确认
	// ReqSettlementInfoConfirm();
    }

    TestAllFunction();
}

///登出请求响应
void CTraderSpi::OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pUserLogout->BrokerID << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pUserLogout->UserID << endl;
    }
}

///用户口令更新请求响应
void CTraderSpi::OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pUserPasswordUpdate->BrokerID << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pUserPasswordUpdate->UserID << endl;
	cout << "原来的口令 TThostFtdcPasswordType:" << pUserPasswordUpdate->OldPassword << endl;
	cout << "新的口令 TThostFtdcPasswordType:" << pUserPasswordUpdate->NewPassword << endl;
    }
}

///资金账户口令更新请求响应
void CTraderSpi::OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pTradingAccountPasswordUpdate->BrokerID << endl;
	cout << "投资者帐号 TThostFtdcAccountIDType:" << pTradingAccountPasswordUpdate->AccountID << endl;
	cout << "原来的口令 TThostFtdcPasswordType:" << pTradingAccountPasswordUpdate->OldPassword << endl;
	cout << "新的口令 TThostFtdcPasswordType:" << pTradingAccountPasswordUpdate->NewPassword << endl;
	cout << "币种代码 TThostFtdcCurrencyIDType:" << pTradingAccountPasswordUpdate->CurrencyID << endl;
    }
}

///报单录入请求响应
void CTraderSpi::OnRspOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pInputOrder->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pInputOrder->InvestorID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pInputOrder->InstrumentID << endl;
	cout << "报单引用 TThostFtdcOrderRefType:" << pInputOrder->OrderRef << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pInputOrder->UserID << endl;
	cout << "报单价格条件 TThostFtdcOrderPriceTypeType:" << pInputOrder->OrderPriceType << endl;
	cout << "买卖方向 TThostFtdcDirectionType:" << pInputOrder->Direction << endl;
	cout << "组合开平标志 TThostFtdcCombOffsetFlagType:" << pInputOrder->CombOffsetFlag << endl;
	cout << "组合投机套保标志 TThostFtdcCombHedgeFlagType:" << pInputOrder->CombHedgeFlag << endl;
	cout << "价格 TThostFtdcPriceType:" << pInputOrder->LimitPrice << endl;
	cout << "数量 TThostFtdcVolumeType:" << pInputOrder->VolumeTotalOriginal << endl;
	cout << "有效期类型 TThostFtdcTimeConditionType:" << pInputOrder->TimeCondition << endl;
	cout << "GTD日期 pInputOrder->TThostFtdcDateType:" << pInputOrder->GTDDate << endl;
	cout << "成交量类型 TThostFtdcVolumeConditionType:" << pInputOrder->VolumeCondition << endl;
	cout << "最小成交量 TThostFtdcVolumeType:" << pInputOrder->MinVolume << endl;
	cout << "触发条件 TThostFtdcContingentConditionType:" << pInputOrder->ContingentCondition << endl;
	cout << "止损价 TThostFtdcPriceType:" << pInputOrder->StopPrice << endl;
	cout << "强平原因 TThostFtdcForceCloseReasonType:" << pInputOrder->ForceCloseReason << endl;
	cout << "自动挂起标志 TThostFtdcBoolType:" << pInputOrder->IsAutoSuspend << endl;
	cout << "业务单元 TThostFtdcBusinessUnitType:" << pInputOrder->BusinessUnit << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pInputOrder->RequestID << endl;
	cout << "用户强评标志 TThostFtdcBoolType:" << pInputOrder->UserForceClose << endl;
	cout << "互换单标志 TThostFtdcBoolType:" << pInputOrder->IsSwapOrder << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pInputOrder->ExchangeID << endl;
    }
}

///预埋单录入请求响应
void CTraderSpi::OnRspParkedOrderInsert(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pParkedOrder->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pParkedOrder->InvestorID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pParkedOrder->InstrumentID << endl;
	cout << "报单引用 TThostFtdcOrderRefType:" << pParkedOrder->OrderRef << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pParkedOrder->UserID << endl;
	cout << "报单价格条件 TThostFtdcOrderPriceTypeType:" << pParkedOrder->OrderPriceType << endl;
	cout << "买卖方向 TThostFtdcDirectionType:" << pParkedOrder->Direction << endl;
	cout << "组合开平标志 TThostFtdcCombOffsetFlagType:" << pParkedOrder->CombOffsetFlag << endl;
	cout << "组合投机套保标志 TThostFtdcCombHedgeFlagType:" << pParkedOrder->CombHedgeFlag << endl;
	cout << "价格 TThostFtdcPriceType:" << pParkedOrder->LimitPrice << endl;
	cout << "数量 TThostFtdcVolumeType:" << pParkedOrder->VolumeTotalOriginal << endl;
	cout << "有效期类型 TThostFtdcTimeConditionType:" << pParkedOrder->TimeCondition << endl;
	// cout << "GTD日期:" << pParkedOrder->TThostFtdcDateType << endlGTDDate;
	cout << "成交量类型 TThostFtdcVolumeConditionType:" << pParkedOrder->VolumeCondition << endl;
	cout << "最小成交量 TThostFtdcVolumeType:" << pParkedOrder->MinVolume << endl;
	cout << "触发条件 TThostFtdcContingentConditionType:" << pParkedOrder->ContingentCondition << endl;
	cout << "止损价 TThostFtdcPriceType:" << pParkedOrder->StopPrice << endl;
	cout << "强平原因 TThostFtdcForceCloseReasonType:" << pParkedOrder->ForceCloseReason << endl;
	cout << "自动挂起标志 TThostFtdcBoolType:" << pParkedOrder->IsAutoSuspend << endl;
	cout << "业务单元 TThostFtdcBusinessUnitType:" << pParkedOrder->BusinessUnit << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pParkedOrder->RequestID << endl;
	cout << "用户强评标志 TThostFtdcBoolType:" << pParkedOrder->UserForceClose << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pParkedOrder->ExchangeID << endl;
	cout << "预埋报单编号 TThostFtdcParkedOrderIDType:" << pParkedOrder->ParkedOrderID << endl;
	cout << "用户类型 TThostFtdcUserTypeType:" << pParkedOrder->UserType << endl;
	cout << "预埋单状态 TThostFtdcParkedOrderStatusType:" << pParkedOrder->Status << endl;
	cout << "错误代码 TThostFtdcErrorIDType:" << pParkedOrder->ErrorID << endl;
	cout << "错误信息 TThostFtdcErrorMsgType:" << pParkedOrder->ErrorMsg << endl;
	cout << "互换单标志 TThostFtdcBoolType:" << pParkedOrder->IsSwapOrder << endl;
    }
}

///预埋撤单录入请求响应
void CTraderSpi::OnRspParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pParkedOrderAction->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pParkedOrderAction->InvestorID << endl;
	cout << "报单操作引用 TThostFtdcOrderActionRefType:" << pParkedOrderAction->OrderActionRef << endl;
	cout << "报单引用 TThostFtdcOrderRefType:" << pParkedOrderAction->OrderRef << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pParkedOrderAction->RequestID << endl;
	cout << "前置编号 TThostFtdcFrontIDType:" << pParkedOrderAction->FrontID << endl;
	cout << "会话编号 TThostFtdcSessionIDType:" << pParkedOrderAction->SessionID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pParkedOrderAction->ExchangeID << endl;
	cout << "报单编号 TThostFtdcOrderSysIDType:" << pParkedOrderAction->OrderSysID << endl;
	cout << "操作标志 TThostFtdcActionFlagType:" << pParkedOrderAction->ActionFlag << endl;
	cout << "价格 TThostFtdcPriceType:" << pParkedOrderAction->LimitPrice << endl;
	cout << "数量变化 TThostFtdcVolumeType:" << pParkedOrderAction->VolumeChange << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pParkedOrderAction->UserID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pParkedOrderAction->InstrumentID << endl;
	cout << "预埋撤单单编号 TThostFtdcParkedOrderActionIDType:" << pParkedOrderAction->ParkedOrderActionID << endl;
	cout << "用户类型 TThostFtdcUserTypeType:" << pParkedOrderAction->UserType << endl;
	cout << "预埋撤单状态 TThostFtdcParkedOrderStatusType:" << pParkedOrderAction->Status << endl;
	cout << "错误代码 TThostFtdcErrorIDType:" << pParkedOrderAction->ErrorID << endl;
	cout << "错误信息 TThostFtdcErrorMsgType:" << pParkedOrderAction->ErrorMsg << endl;
    }
}

///报单操作请求响应
void CTraderSpi::OnRspOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pInputOrderAction->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pInputOrderAction->InvestorID << endl;
	cout << "报单操作引用 TThostFtdcOrderActionRefType:" << pInputOrderAction->OrderActionRef << endl;
	cout << "报单引用 TThostFtdcOrderRefType:" << pInputOrderAction->OrderRef << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pInputOrderAction->RequestID << endl;
	cout << "前置编号 TThostFtdcFrontIDType:" << pInputOrderAction->FrontID << endl;
	cout << "会话编号 TThostFtdcSessionIDType:" << pInputOrderAction->SessionID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pInputOrderAction->ExchangeID << endl;
	cout << "报单编号 TThostFtdcOrderSysIDType:" << pInputOrderAction->OrderSysID << endl;
	cout << "操作标志 TThostFtdcActionFlagType:" << pInputOrderAction->ActionFlag << endl;
	cout << "价格 TThostFtdcPriceType:" << pInputOrderAction->LimitPrice << endl;
	cout << "数量变化 TThostFtdcVolumeType:" << pInputOrderAction->VolumeChange << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pInputOrderAction->UserID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pInputOrderAction->InstrumentID << endl;
    }
}

///查询最大报单数量响应
void CTraderSpi::OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField* pQueryMaxOrderVolume, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pQueryMaxOrderVolume->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pQueryMaxOrderVolume->InvestorID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pQueryMaxOrderVolume->InstrumentID << endl;
	cout << "买卖方向 TThostFtdcDirectionType:" << pQueryMaxOrderVolume->Direction << endl;
	cout << "开平标志 TThostFtdcOffsetFlagType:" << pQueryMaxOrderVolume->OffsetFlag << endl;
	cout << "投机套保标志 TThostFtdcHedgeFlagType:" << pQueryMaxOrderVolume->HedgeFlag << endl;
	cout << "最大允许报单数量 TThostFtdcVolumeType:" << pQueryMaxOrderVolume->MaxVolume << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pQueryMaxOrderVolume->ExchangeID << endl;
    }
}

///投资者结算结果确认响应
void CTraderSpi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pSettlementInfoConfirm->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pSettlementInfoConfirm->InvestorID << endl;
	cout << "确认日期 TThostFtdcDateType:" << pSettlementInfoConfirm->ConfirmDate << endl;
	cout << "确认时间 TThostFtdcTimeType:" << pSettlementInfoConfirm->ConfirmTime << endl;
    }
}

///删除预埋单响应
void CTraderSpi::OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pRemoveParkedOrder->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pRemoveParkedOrder->InvestorID << endl;
	cout << "预埋报单编号 TThostFtdcParkedOrderIDType:" << pRemoveParkedOrder->ParkedOrderID << endl;
    }
}

///删除预埋撤单响应
void CTraderSpi::OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pRemoveParkedOrderAction->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pRemoveParkedOrderAction->InvestorID << endl;
	cout << "预埋撤单编号 TThostFtdcParkedOrderActionIDType:" << pRemoveParkedOrderAction->ParkedOrderActionID << endl;
    }
}

///执行宣告录入请求响应
void CTraderSpi::OnRspExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pInputExecOrder->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pInputExecOrder->InvestorID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pInputExecOrder->InstrumentID << endl;
	cout << "执行宣告引用 TThostFtdcOrderRefType:" << pInputExecOrder->ExecOrderRef << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pInputExecOrder->UserID << endl;
	cout << "数量 TThostFtdcVolumeType:" << pInputExecOrder->Volume << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pInputExecOrder->RequestID << endl;
	cout << "业务单元 TThostFtdcBusinessUnitType:" << pInputExecOrder->BusinessUnit << endl;
	cout << "开平标志 TThostFtdcOffsetFlagType:" << pInputExecOrder->OffsetFlag << endl;
	cout << "投机套保标志 TThostFtdcHedgeFlagType:" << pInputExecOrder->HedgeFlag << endl;
	cout << "执行类型 TThostFtdcActionTypeType:" << pInputExecOrder->ActionType << endl;
	cout << "保留头寸申请的持仓方向 TThostFtdcPosiDirectionType:" << pInputExecOrder->PosiDirection << endl;
	cout << "期权行权后是否保留期货头寸的标记 TThostFtdcExecOrderPositionFlagType:" << pInputExecOrder->ReservePositionFlag << endl;
	cout << "期权行权后生成的头寸是否自动平仓 TThostFtdcExecOrderCloseFlagType:" << pInputExecOrder->CloseFlag << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pInputExecOrder->ExchangeID << endl;
    }
}

///执行宣告操作请求响应
void CTraderSpi::OnRspExecOrderAction(CThostFtdcInputExecOrderActionField* pInputExecOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pInputExecOrderAction->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pInputExecOrderAction->InvestorID << endl;
	cout << "执行宣告操作引用 TThostFtdcOrderActionRefType:" << pInputExecOrderAction->ExecOrderActionRef << endl;
	cout << "执行宣告引用 TThostFtdcOrderRefType:" << pInputExecOrderAction->ExecOrderRef << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pInputExecOrderAction->RequestID << endl;
	cout << "前置编号 TThostFtdcFrontIDType:" << pInputExecOrderAction->FrontID << endl;
	cout << "会话编号 TThostFtdcSessionIDType:" << pInputExecOrderAction->SessionID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pInputExecOrderAction->ExchangeID << endl;
	cout << "执行宣告操作编号 TThostFtdcExecOrderSysIDType:" << pInputExecOrderAction->ExecOrderSysID << endl;
	cout << "操作标志 TThostFtdcActionFlagType:" << pInputExecOrderAction->ActionFlag << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pInputExecOrderAction->UserID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pInputExecOrderAction->InstrumentID << endl;
    }
}

///询价录入请求响应
void CTraderSpi::OnRspForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pInputForQuote->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pInputForQuote->InvestorID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pInputForQuote->InstrumentID << endl;
	cout << "询价引用 TThostFtdcOrderRefType:" << pInputForQuote->ForQuoteRef << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pInputForQuote->UserID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pInputForQuote->ExchangeID << endl;
    }
}

///报价录入请求响应
void CTraderSpi::OnRspQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pInputQuote->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pInputQuote->InvestorID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pInputQuote->InstrumentID << endl;
	cout << "报价引用 TThostFtdcOrderRefType:" << pInputQuote->QuoteRef << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pInputQuote->UserID << endl;
	cout << "卖价格 TThostFtdcPriceType:" << pInputQuote->AskPrice << endl;
	cout << "买价格 TThostFtdcPriceType:" << pInputQuote->BidPrice << endl;
	cout << "卖数量 TThostFtdcVolumeType:" << pInputQuote->AskVolume << endl;
	cout << "买数量 TThostFtdcVolumeType:" << pInputQuote->BidVolume << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pInputQuote->RequestID << endl;
	cout << "业务单元 TThostFtdcBusinessUnitType:" << pInputQuote->BusinessUnit << endl;
	cout << "卖开平标志 TThostFtdcOffsetFlagType:" << pInputQuote->AskOffsetFlag << endl;
	cout << "买开平标志 TThostFtdcOffsetFlagType:" << pInputQuote->BidOffsetFlag << endl;
	cout << "卖投机套保标志 TThostFtdcHedgeFlagType:" << pInputQuote->AskHedgeFlag << endl;
	cout << "买投机套保标志 TThostFtdcHedgeFlagType:" << pInputQuote->BidHedgeFlag << endl;
	cout << "衍生卖报单引用 TThostFtdcOrderRefType:" << pInputQuote->AskOrderRef << endl;
	cout << "衍生买报单引用 TThostFtdcOrderRefType:" << pInputQuote->BidOrderRef << endl;
	cout << "应价编号 TThostFtdcOrderSysIDType:" << pInputQuote->ForQuoteSysID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pInputQuote->ExchangeID << endl;
    }
}

///报价操作请求响应
void CTraderSpi::OnRspQuoteAction(CThostFtdcInputQuoteActionField* pInputQuoteAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pInputQuoteAction->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pInputQuoteAction->InvestorID << endl;
	cout << "报价操作引用 TThostFtdcOrderActionRefType:" << pInputQuoteAction->QuoteActionRef << endl;
	cout << "报价引用 TThostFtdcOrderRefType:" << pInputQuoteAction->QuoteRef << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pInputQuoteAction->RequestID << endl;
	cout << "前置编号 TThostFtdcFrontIDType:" << pInputQuoteAction->FrontID << endl;
	cout << "会话编号 TThostFtdcSessionIDType:" << pInputQuoteAction->SessionID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pInputQuoteAction->ExchangeID << endl;
	cout << "报价操作编号 TThostFtdcOrderSysIDType:" << pInputQuoteAction->QuoteSysID << endl;
	cout << "操作标志 TThostFtdcActionFlagType:" << pInputQuoteAction->ActionFlag << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pInputQuoteAction->UserID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pInputQuoteAction->InstrumentID << endl;
    }
}

///锁定应答
void CTraderSpi::OnRspLockInsert(CThostFtdcInputLockField* pInputLock, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pInputLock->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pInputLock->InvestorID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pInputLock->InstrumentID << endl;
	cout << "锁定引用 TThostFtdcOrderRefType:" << pInputLock->LockRef << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pInputLock->UserID << endl;
	cout << "数量 TThostFtdcVolumeType:" << pInputLock->Volume << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pInputLock->RequestID << endl;
	cout << "业务单元 TThostFtdcBusinessUnitType:" << pInputLock->BusinessUnit << endl;
	cout << "锁定类型 TThostFtdcLockTypeType:" << pInputLock->LockType << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pInputLock->ExchangeID << endl;
    }
}

///申请组合录入请求响应
void CTraderSpi::OnRspCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pInputCombAction->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pInputCombAction->InvestorID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pInputCombAction->InstrumentID << endl;
	cout << "组合引用 TThostFtdcOrderRefType:" << pInputCombAction->CombActionRef << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pInputCombAction->UserID << endl;
	cout << "买卖方向 TThostFtdcDirectionType:" << pInputCombAction->Direction << endl;
	cout << "数量 TThostFtdcVolumeType:" << pInputCombAction->Volume << endl;
	cout << "组合指令方向 TThostFtdcCombDirectionType:" << pInputCombAction->CombDirection << endl;
	cout << "投机套保标志 TThostFtdcHedgeFlagType:" << pInputCombAction->HedgeFlag << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pInputCombAction->ExchangeID << endl;
    }
}

///请求查询报单响应
void CTraderSpi::OnRspQryOrder(CThostFtdcOrderField* pOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pOrder->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pOrder->InvestorID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pOrder->InstrumentID << endl;
	cout << "报单引用 TThostFtdcOrderRefType:" << pOrder->OrderRef << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pOrder->UserID << endl;
	cout << "报单价格条件 TThostFtdcOrderPriceTypeType:" << pOrder->OrderPriceType << endl;
	cout << "买卖方向 TThostFtdcDirectionType:" << pOrder->Direction << endl;
	cout << "组合开平标志 TThostFtdcCombOffsetFlagType:" << pOrder->CombOffsetFlag << endl;
	cout << "组合投机套保标志 TThostFtdcCombHedgeFlagType:" << pOrder->CombHedgeFlag << endl;
	cout << "价格 TThostFtdcPriceType:" << pOrder->LimitPrice << endl;
	cout << "数量 TThostFtdcVolumeType:" << pOrder->VolumeTotalOriginal << endl;
	cout << "有效期类型 TThostFtdcTimeConditionType:" << pOrder->TimeCondition << endl;
	// cout << "GTD日期:" << pOrder->TThostFtdcDateType << endlGTDDate;
	cout << "成交量类型 TThostFtdcVolumeConditionType:" << pOrder->VolumeCondition << endl;
	cout << "最小成交量 TThostFtdcVolumeType:" << pOrder->MinVolume << endl;
	cout << "触发条件 TThostFtdcContingentConditionType:" << pOrder->ContingentCondition << endl;
	cout << "止损价 TThostFtdcPriceType:" << pOrder->StopPrice << endl;
	cout << "强平原因 TThostFtdcForceCloseReasonType:" << pOrder->ForceCloseReason << endl;
	cout << "自动挂起标志 TThostFtdcBoolType:" << pOrder->IsAutoSuspend << endl;
	cout << "业务单元 TThostFtdcBusinessUnitType:" << pOrder->BusinessUnit << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pOrder->RequestID << endl;
	cout << "本地报单编号 TThostFtdcOrderLocalIDType:" << pOrder->OrderLocalID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pOrder->ExchangeID << endl;
	cout << "会员代码 TThostFtdcParticipantIDType:" << pOrder->ParticipantID << endl;
	cout << "客户代码 TThostFtdcClientIDType:" << pOrder->ClientID << endl;
	cout << "合约在交易所的代码 TThostFtdcExchangeInstIDType:" << pOrder->ExchangeInstID << endl;
	cout << "交易所交易员代码 TThostFtdcTraderIDType:" << pOrder->TraderID << endl;
	cout << "安装编号 TThostFtdcInstallIDType:" << pOrder->InstallID << endl;
	cout << "报单提交状态 TThostFtdcOrderSubmitStatusType:" << pOrder->OrderSubmitStatus << endl;
	cout << "报单提示序号 TThostFtdcSequenceNoType:" << pOrder->NotifySequence << endl;
	cout << "交易日 TThostFtdcDateType:" << pOrder->TradingDay << endl;
	cout << "结算编号 TThostFtdcSettlementIDType:" << pOrder->SettlementID << endl;
	cout << "报单编号 TThostFtdcOrderSysIDType:" << pOrder->OrderSysID << endl;
	cout << "报单来源 TThostFtdcOrderSourceType:" << pOrder->OrderSource << endl;
	cout << "报单状态 TThostFtdcOrderStatusType:" << pOrder->OrderStatus << endl;
	cout << "报单类型 TThostFtdcOrderTypeType:" << pOrder->OrderType << endl;
	cout << "今成交数量 TThostFtdcVolumeType:" << pOrder->VolumeTraded << endl;
	cout << "剩余数量 TThostFtdcVolumeType:" << pOrder->VolumeTotal << endl;
	cout << "报单日期 TThostFtdcDateType:" << pOrder->InsertDate << endl;
	cout << "委托时间 TThostFtdcTimeType:" << pOrder->InsertTime << endl;
	cout << "激活时间 TThostFtdcTimeType:" << pOrder->ActiveTime << endl;
	cout << "挂起时间 TThostFtdcTimeType:" << pOrder->SuspendTime << endl;
	cout << "最后修改时间 TThostFtdcTimeType:" << pOrder->UpdateTime << endl;
	cout << "撤销时间 TThostFtdcTimeType:" << pOrder->CancelTime << endl;
	cout << "最后修改交易所交易员代码 TThostFtdcTraderIDType:" << pOrder->ActiveTraderID << endl;
	cout << "结算会员编号 TThostFtdcParticipantIDType:" << pOrder->ClearingPartID << endl;
	cout << "序号 TThostFtdcSequenceNoType:" << pOrder->SequenceNo << endl;
	cout << "前置编号 TThostFtdcFrontIDType:" << pOrder->FrontID << endl;
	cout << "会话编号 TThostFtdcSessionIDType:" << pOrder->SessionID << endl;
	cout << "用户端产品信息 TThostFtdcProductInfoType:" << pOrder->UserProductInfo << endl;
	cout << "状态信息 TThostFtdcErrorMsgType:" << pOrder->StatusMsg << endl;
	cout << "用户强评标志 TThostFtdcBoolType:" << pOrder->UserForceClose << endl;
	cout << "操作用户代码 TThostFtdcUserIDType:" << pOrder->ActiveUserID << endl;
	cout << "经纪公司报单编号 TThostFtdcSequenceNoType:" << pOrder->BrokerOrderSeq << endl;
	cout << "相关报单 TThostFtdcOrderSysIDType:" << pOrder->RelativeOrderSysID << endl;
	cout << "郑商所成交数量 TThostFtdcVolumeType:" << pOrder->ZCETotalTradedVolume << endl;
	cout << "互换单标志 TThostFtdcBoolType:" << pOrder->IsSwapOrder << endl;
	cout << "营业部编号 TThostFtdcBranchIDType:" << pOrder->BranchID << endl;
    }
}

///请求查询成交响应
void CTraderSpi::OnRspQryTrade(CThostFtdcTradeField* pTrade, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pTrade->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pTrade->InvestorID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pTrade->InstrumentID << endl;
	cout << "报单引用 TThostFtdcOrderRefType:" << pTrade->OrderRef << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pTrade->UserID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pTrade->ExchangeID << endl;
	cout << "成交编号 TThostFtdcTradeIDType:" << pTrade->TradeID << endl;
	cout << "买卖方向 TThostFtdcDirectionType:" << pTrade->Direction << endl;
	cout << "报单编号 TThostFtdcOrderSysIDType:" << pTrade->OrderSysID << endl;
	cout << "会员代码 TThostFtdcParticipantIDType:" << pTrade->ParticipantID << endl;
	cout << "客户代码 TThostFtdcClientIDType:" << pTrade->ClientID << endl;
	cout << "交易角色 TThostFtdcTradingRoleType:" << pTrade->TradingRole << endl;
	cout << "合约在交易所的代码 TThostFtdcExchangeInstIDType:" << pTrade->ExchangeInstID << endl;
	cout << "开平标志 TThostFtdcOffsetFlagType:" << pTrade->OffsetFlag << endl;
	cout << "投机套保标志 TThostFtdcHedgeFlagType:" << pTrade->HedgeFlag << endl;
	cout << "价格 TThostFtdcPriceType:" << pTrade->Price << endl;
	cout << "数量 TThostFtdcVolumeType:" << pTrade->Volume << endl;
	cout << "成交时期 TThostFtdcDateType:" << pTrade->TradeDate << endl;
	cout << "成交时间 TThostFtdcTimeType:" << pTrade->TradeTime << endl;
	cout << "成交类型 TThostFtdcTradeTypeType:" << pTrade->TradeType << endl;
	cout << "成交价来源 TThostFtdcPriceSourceType:" << pTrade->PriceSource << endl;
	cout << "交易所交易员代码 TThostFtdcTraderIDType:" << pTrade->TraderID << endl;
	cout << "本地报单编号 TThostFtdcOrderLocalIDType:" << pTrade->OrderLocalID << endl;
	cout << "结算会员编号 TThostFtdcParticipantIDType:" << pTrade->ClearingPartID << endl;
	cout << "业务单元 TThostFtdcBusinessUnitType:" << pTrade->BusinessUnit << endl;
	cout << "序号 TThostFtdcSequenceNoType:" << pTrade->SequenceNo << endl;
	cout << "交易日 TThostFtdcDateType:" << pTrade->TradingDay << endl;
	cout << "结算编号 TThostFtdcSettlementIDType:" << pTrade->SettlementID << endl;
	cout << "经纪公司报单编号 TThostFtdcSequenceNoType:" << pTrade->BrokerOrderSeq << endl;
	cout << "成交来源 TThostFtdcTradeSourceType:" << pTrade->TradeSource << endl;
    }
}

///请求查询投资者持仓响应
void CTraderSpi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField* pInvestorPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pInvestorPosition->InstrumentID << endl;
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pInvestorPosition->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pInvestorPosition->InvestorID << endl;
	cout << "持仓多空方向 TThostFtdcPosiDirectionType:" << pInvestorPosition->PosiDirection << endl;
	cout << "投机套保标志 TThostFtdcHedgeFlagType:" << pInvestorPosition->HedgeFlag << endl;
	cout << "持仓日期 TThostFtdcPositionDateType:" << pInvestorPosition->PositionDate << endl;
	cout << "上日持仓 TThostFtdcVolumeType:" << pInvestorPosition->YdPosition << endl;
	cout << "今日持仓 TThostFtdcVolumeType:" << pInvestorPosition->Position << endl;
	cout << "多头冻结 TThostFtdcVolumeType:" << pInvestorPosition->LongFrozen << endl;
	cout << "空头冻结 TThostFtdcVolumeType:" << pInvestorPosition->ShortFrozen << endl;
	cout << "开仓冻结金额 TThostFtdcMoneyType:" << pInvestorPosition->LongFrozenAmount << endl;
	cout << "开仓冻结金额 TThostFtdcMoneyType:" << pInvestorPosition->ShortFrozenAmount << endl;
	cout << "开仓量 TThostFtdcVolumeType:" << pInvestorPosition->OpenVolume << endl;
	cout << "平仓量 TThostFtdcVolumeType:" << pInvestorPosition->CloseVolume << endl;
	cout << "开仓金额 TThostFtdcMoneyType:" << pInvestorPosition->OpenAmount << endl;
	cout << "平仓金额 TThostFtdcMoneyType:" << pInvestorPosition->CloseAmount << endl;
	cout << "持仓成本 TThostFtdcMoneyType:" << pInvestorPosition->PositionCost << endl;
	cout << "上次占用的保证金 TThostFtdcMoneyType:" << pInvestorPosition->PreMargin << endl;
	cout << "占用的保证金 TThostFtdcMoneyType:" << pInvestorPosition->UseMargin << endl;
	cout << "冻结的保证金 TThostFtdcMoneyType:" << pInvestorPosition->FrozenMargin << endl;
	cout << "冻结的资金 TThostFtdcMoneyType:" << pInvestorPosition->FrozenCash << endl;
	cout << "冻结的手续费 TThostFtdcMoneyType:" << pInvestorPosition->FrozenCommission << endl;
	cout << "资金差额 TThostFtdcMoneyType:" << pInvestorPosition->CashIn << endl;
	cout << "手续费 TThostFtdcMoneyType:" << pInvestorPosition->Commission << endl;
	cout << "平仓盈亏 TThostFtdcMoneyType:" << pInvestorPosition->CloseProfit << endl;
	cout << "持仓盈亏 TThostFtdcMoneyType:" << pInvestorPosition->PositionProfit << endl;
	cout << "上次结算价 TThostFtdcPriceType:" << pInvestorPosition->PreSettlementPrice << endl;
	cout << "本次结算价 TThostFtdcPriceType:" << pInvestorPosition->SettlementPrice << endl;
	cout << "交易日 TThostFtdcDateType:" << pInvestorPosition->TradingDay << endl;
	cout << "结算编号 TThostFtdcSettlementIDType:" << pInvestorPosition->SettlementID << endl;
	cout << "开仓成本 TThostFtdcMoneyType:" << pInvestorPosition->OpenCost << endl;
	cout << "交易所保证金 TThostFtdcMoneyType:" << pInvestorPosition->ExchangeMargin << endl;
	cout << "组合成交形成的持仓 TThostFtdcVolumeType:" << pInvestorPosition->CombPosition << endl;
	cout << "组合多头冻结 TThostFtdcVolumeType:" << pInvestorPosition->CombLongFrozen << endl;
	cout << "组合空头冻结 TThostFtdcVolumeType:" << pInvestorPosition->CombShortFrozen << endl;
	cout << "逐日盯市平仓盈亏 TThostFtdcMoneyType:" << pInvestorPosition->CloseProfitByDate << endl;
	cout << "逐笔对冲平仓盈亏 TThostFtdcMoneyType:" << pInvestorPosition->CloseProfitByTrade << endl;
	cout << "今日持仓 TThostFtdcVolumeType:" << pInvestorPosition->TodayPosition << endl;
	cout << "保证金率 TThostFtdcRatioType:" << pInvestorPosition->MarginRateByMoney << endl;
	cout << "保证金率按手数 TThostFtdcRatioType:" << pInvestorPosition->MarginRateByVolume << endl;
	cout << "执行冻结 TThostFtdcVolumeType:" << pInvestorPosition->StrikeFrozen << endl;
	cout << "执行冻结金额 TThostFtdcMoneyType:" << pInvestorPosition->StrikeFrozenAmount << endl;
	cout << "放弃执行冻结 TThostFtdcVolumeType:" << pInvestorPosition->AbandonFrozen << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pInvestorPosition->ExchangeID << endl;
	cout << "执行冻结的昨仓 TThostFtdcVolumeType:" << pInvestorPosition->YdStrikeFrozen << endl;
    }
}

///请求查询资金账户响应
void CTraderSpi::OnRspQryTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> "
	 << "OnRspQryTradingAccount" << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pTradingAccount->BrokerID << endl;
	cout << "投资者帐号 TThostFtdcAccountIDType:" << pTradingAccount->AccountID << endl;
	cout << "上次质押金额 TThostFtdcMoneyType:" << pTradingAccount->PreMortgage << endl;
	cout << "上次信用额度 TThostFtdcMoneyType:" << pTradingAccount->PreCredit << endl;
	cout << "上次存款额 TThostFtdcMoneyType:" << pTradingAccount->PreDeposit << endl;
	cout << "上次结算准备金 TThostFtdcMoneyType:" << pTradingAccount->PreBalance << endl;
	cout << "上次占用的保证金 TThostFtdcMoneyType:" << pTradingAccount->PreMargin << endl;
	cout << "利息基数 TThostFtdcMoneyType:" << pTradingAccount->InterestBase << endl;
	cout << "利息收入 TThostFtdcMoneyType:" << pTradingAccount->Interest << endl;
	cout << "入金金额 TThostFtdcMoneyType:" << pTradingAccount->Deposit << endl;
	cout << "出金金额 TThostFtdcMoneyType:" << pTradingAccount->Withdraw << endl;
	cout << "冻结的保证金 TThostFtdcMoneyType:" << pTradingAccount->FrozenMargin << endl;
	cout << "冻结的资金 TThostFtdcMoneyType:" << pTradingAccount->FrozenCash << endl;
	cout << "冻结的手续费 TThostFtdcMoneyType:" << pTradingAccount->FrozenCommission << endl;
	cout << "当前保证金总额 TThostFtdcMoneyType:" << pTradingAccount->CurrMargin << endl;
	cout << "资金差额 TThostFtdcMoneyType:" << pTradingAccount->CashIn << endl;
	cout << "手续费 TThostFtdcMoneyType:" << pTradingAccount->Commission << endl;
	cout << "平仓盈亏 TThostFtdcMoneyType:" << pTradingAccount->CloseProfit << endl;
	cout << "持仓盈亏 TThostFtdcMoneyType:" << pTradingAccount->PositionProfit << endl;
	cout << "期货结算准备金 TThostFtdcMoneyType:" << pTradingAccount->Balance << endl;
	cout << "可用资金 TThostFtdcMoneyType:" << pTradingAccount->Available << endl;
	cout << "可取资金 TThostFtdcMoneyType:" << pTradingAccount->WithdrawQuota << endl;
	cout << "基本准备金 TThostFtdcMoneyType:" << pTradingAccount->Reserve << endl;
	cout << "交易日 TThostFtdcDateType:" << pTradingAccount->TradingDay << endl;
	cout << "结算编号 TThostFtdcSettlementIDType:" << pTradingAccount->SettlementID << endl;
	cout << "信用额度 TThostFtdcMoneyType:" << pTradingAccount->Credit << endl;
	cout << "质押金额 TThostFtdcMoneyType:" << pTradingAccount->Mortgage << endl;
	cout << "交易所保证金 TThostFtdcMoneyType:" << pTradingAccount->ExchangeMargin << endl;
	cout << "投资者交割保证金 TThostFtdcMoneyType:" << pTradingAccount->DeliveryMargin << endl;
	cout << "交易所交割保证金 TThostFtdcMoneyType:" << pTradingAccount->ExchangeDeliveryMargin << endl;
	cout << "保底期货结算准备金 TThostFtdcMoneyType:" << pTradingAccount->ReserveBalance << endl;
	cout << "币种代码 TThostFtdcCurrencyIDType:" << pTradingAccount->CurrencyID << endl;
	cout << "上次货币质入金额 TThostFtdcMoneyType:" << pTradingAccount->PreFundMortgageIn << endl;
	cout << "上次货币质出金额 TThostFtdcMoneyType:" << pTradingAccount->PreFundMortgageOut << endl;
	cout << "货币质入金额 TThostFtdcMoneyType:" << pTradingAccount->FundMortgageIn << endl;
	cout << "货币质出金额 TThostFtdcMoneyType:" << pTradingAccount->FundMortgageOut << endl;
	cout << "货币质押余额 TThostFtdcMoneyType:" << pTradingAccount->FundMortgageAvailable << endl;
	cout << "可质押货币金额 TThostFtdcMoneyType:" << pTradingAccount->MortgageableFund << endl;
	cout << "特殊产品占用保证金 TThostFtdcMoneyType:" << pTradingAccount->SpecProductMargin << endl;
	cout << "特殊产品冻结保证金 TThostFtdcMoneyType:" << pTradingAccount->SpecProductFrozenMargin << endl;
	cout << "特殊产品手续费 TThostFtdcMoneyType:" << pTradingAccount->SpecProductCommission << endl;
	cout << "特殊产品冻结手续费 TThostFtdcMoneyType:" << pTradingAccount->SpecProductFrozenCommission << endl;
	cout << "特殊产品持仓盈亏 TThostFtdcMoneyType:" << pTradingAccount->SpecProductPositionProfit << endl;
	cout << "特殊产品平仓盈亏 TThostFtdcMoneyType:" << pTradingAccount->SpecProductCloseProfit << endl;
	cout << "根据持仓盈亏算法计算的特殊产品持仓盈亏 TThostFtdcMoneyType:" << pTradingAccount->SpecProductPositionProfitByAlg << endl;
	cout << "特殊产品交易所保证金 TThostFtdcMoneyType:" << pTradingAccount->SpecProductExchangeMargin << endl;
	cout << "业务类型 TThostFtdcBizTypeType:" << pTradingAccount->BizType << endl;
    }
}

///请求查询投资者响应
void CTraderSpi::OnRspQryInvestor(CThostFtdcInvestorField* pInvestor, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pInvestor->InvestorID << endl;
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pInvestor->BrokerID << endl;
	cout << "投资者分组代码 TThostFtdcInvestorIDType:" << pInvestor->InvestorGroupID << endl;
	cout << "投资者名称 TThostFtdcPartyNameType:" << pInvestor->InvestorName << endl;
	cout << "证件类型 TThostFtdcIdCardTypeType:" << pInvestor->IdentifiedCardType << endl;
	cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pInvestor->IdentifiedCardNo << endl;
	cout << "是否活跃 TThostFtdcBoolType:" << pInvestor->IsActive << endl;
	cout << "联系电话 TThostFtdcTelephoneType:" << pInvestor->Telephone << endl;
	cout << "通讯地址 TThostFtdcAddressType:" << pInvestor->Address << endl;
	cout << "开户日期 TThostFtdcDateType:" << pInvestor->OpenDate << endl;
	cout << "手机 TThostFtdcMobileType:" << pInvestor->Mobile << endl;
	cout << "手续费率模板代码 TThostFtdcInvestorIDType:" << pInvestor->CommModelID << endl;
	cout << "保证金率模板代码 TThostFtdcInvestorIDType:" << pInvestor->MarginModelID << endl;
    }
}

///请求查询交易编码响应
void CTraderSpi::OnRspQryTradingCode(CThostFtdcTradingCodeField* pTradingCode, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pTradingCode->InvestorID << endl;
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pTradingCode->BrokerID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pTradingCode->ExchangeID << endl;
	cout << "客户代码 TThostFtdcClientIDType:" << pTradingCode->ClientID << endl;
	cout << "是否活跃 TThostFtdcBoolType:" << pTradingCode->IsActive << endl;
	cout << "交易编码类型 TThostFtdcClientIDTypeType:" << pTradingCode->ClientIDType << endl;
	cout << "营业部编号 TThostFtdcBranchIDType:" << pTradingCode->BranchID << endl;
	cout << "业务类型 TThostFtdcBizTypeType:" << pTradingCode->BizType << endl;
    }
}

///请求查询合约保证金率响应
void CTraderSpi::OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField* pInstrumentMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pInstrumentMarginRate->InstrumentID << endl;
	cout << "投资者范围 TThostFtdcInvestorRangeType:" << pInstrumentMarginRate->InvestorRange << endl;
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pInstrumentMarginRate->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pInstrumentMarginRate->InvestorID << endl;
	cout << "投机套保标志 TThostFtdcHedgeFlagType:" << pInstrumentMarginRate->HedgeFlag << endl;
	cout << "多头保证金率 TThostFtdcRatioType:" << pInstrumentMarginRate->LongMarginRatioByMoney << endl;
	cout << "多头保证金费 TThostFtdcMoneyType:" << pInstrumentMarginRate->LongMarginRatioByVolume << endl;
	cout << "空头保证金率 TThostFtdcRatioType:" << pInstrumentMarginRate->ShortMarginRatioByMoney << endl;
	cout << "空头保证金费 TThostFtdcMoneyType:" << pInstrumentMarginRate->ShortMarginRatioByVolume << endl;
	cout << "是否相对交易所收取 TThostFtdcBoolType:" << pInstrumentMarginRate->IsRelative << endl;
    }
}

///请求查询合约手续费率响应
void CTraderSpi::OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField* pInstrumentCommissionRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pInstrumentCommissionRate->InstrumentID << endl;
	cout << "投资者范围 TThostFtdcInvestorRangeType:" << pInstrumentCommissionRate->InvestorRange << endl;
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pInstrumentCommissionRate->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pInstrumentCommissionRate->InvestorID << endl;
	cout << "开仓手续费率 TThostFtdcRatioType:" << pInstrumentCommissionRate->OpenRatioByMoney << endl;
	cout << "开仓手续费 TThostFtdcRatioType:" << pInstrumentCommissionRate->OpenRatioByVolume << endl;
	cout << "平仓手续费率 TThostFtdcRatioType:" << pInstrumentCommissionRate->CloseRatioByMoney << endl;
	cout << "平仓手续费 TThostFtdcRatioType:" << pInstrumentCommissionRate->CloseRatioByVolume << endl;
	cout << "平今手续费率 TThostFtdcRatioType:" << pInstrumentCommissionRate->CloseTodayRatioByMoney << endl;
	cout << "平今手续费 TThostFtdcRatioType:" << pInstrumentCommissionRate->CloseTodayRatioByVolume << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pInstrumentCommissionRate->ExchangeID << endl;
	cout << "业务类型 TThostFtdcBizTypeType:" << pInstrumentCommissionRate->BizType << endl;
    }
}

///请求查询交易所响应
void CTraderSpi::OnRspQryExchange(CThostFtdcExchangeField* pExchange, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pExchange->ExchangeID << endl;
	cout << "交易所名称 TThostFtdcExchangeNameType:" << pExchange->ExchangeName << endl;
	cout << "交易所属性 TThostFtdcExchangePropertyType:" << pExchange->ExchangeProperty << endl;
    }
}

///请求查询产品响应
void CTraderSpi::OnRspQryProduct(CThostFtdcProductField* pProduct, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "产品代码 TThostFtdcInstrumentIDType:" << pProduct->ProductID << endl;
	cout << "产品名称 TThostFtdcProductNameType:" << pProduct->ProductName << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pProduct->ExchangeID << endl;
	cout << "产品类型 TThostFtdcProductClassType:" << pProduct->ProductClass << endl;
	cout << "合约数量乘数 TThostFtdcVolumeMultipleType:" << pProduct->VolumeMultiple << endl;
	cout << "最小变动价位 TThostFtdcPriceType:" << pProduct->PriceTick << endl;
	cout << "市价单最大下单量 TThostFtdcVolumeType:" << pProduct->MaxMarketOrderVolume << endl;
	cout << "市价单最小下单量 TThostFtdcVolumeType:" << pProduct->MinMarketOrderVolume << endl;
	cout << "限价单最大下单量 TThostFtdcVolumeType:" << pProduct->MaxLimitOrderVolume << endl;
	cout << "限价单最小下单量 TThostFtdcVolumeType:" << pProduct->MinLimitOrderVolume << endl;
	cout << "持仓类型 TThostFtdcPositionTypeType:" << pProduct->PositionType << endl;
	cout << "持仓日期类型 TThostFtdcPositionDateTypeType:" << pProduct->PositionDateType << endl;
	cout << "平仓处理类型 TThostFtdcCloseDealTypeType:" << pProduct->CloseDealType << endl;
	cout << "交易币种类型 TThostFtdcCurrencyIDType:" << pProduct->TradeCurrencyID << endl;
	cout << "质押资金可用范围 TThostFtdcMortgageFundUseRangeType:" << pProduct->MortgageFundUseRange << endl;
	cout << "交易所产品代码 TThostFtdcInstrumentIDType:" << pProduct->ExchangeProductID << endl;
	cout << "合约基础商品乘数 TThostFtdcUnderlyingMultipleType:" << pProduct->UnderlyingMultiple << endl;
    }
}

///请求查询合约响应
void CTraderSpi::OnRspQryInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> "
	 << "OnRspQryInstrument" << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pInstrument->InstrumentID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pInstrument->ExchangeID << endl;
	cout << "合约名称 TThostFtdcInstrumentNameType:" << pInstrument->InstrumentName << endl;
	cout << "合约在交易所的代码 TThostFtdcExchangeInstIDType:" << pInstrument->ExchangeInstID << endl;
	cout << "产品代码 TThostFtdcInstrumentIDType:" << pInstrument->ProductID << endl;
	cout << "产品类型 TThostFtdcProductClassType:" << pInstrument->ProductClass << endl;
	cout << "交割年份 TThostFtdcYearType:" << pInstrument->DeliveryYear << endl;
	cout << "交割月 TThostFtdcMonthType:" << pInstrument->DeliveryMonth << endl;
	cout << "市价单最大下单量 TThostFtdcVolumeType:" << pInstrument->MaxMarketOrderVolume << endl;
	cout << "市价单最小下单量 TThostFtdcVolumeType:" << pInstrument->MinMarketOrderVolume << endl;
	cout << "限价单最大下单量 TThostFtdcVolumeType:" << pInstrument->MaxLimitOrderVolume << endl;
	cout << "限价单最小下单量 TThostFtdcVolumeType:" << pInstrument->MinLimitOrderVolume << endl;
	cout << "合约数量乘数 TThostFtdcVolumeMultipleType:" << pInstrument->VolumeMultiple << endl;
	cout << "最小变动价位 TThostFtdcPriceType:" << pInstrument->PriceTick << endl;
	cout << "创建日 TThostFtdcDateType:" << pInstrument->CreateDate << endl;
	cout << "上市日 TThostFtdcDateType:" << pInstrument->OpenDate << endl;
	cout << "到期日 TThostFtdcDateType:" << pInstrument->ExpireDate << endl;
	cout << "开始交割日 TThostFtdcDateType:" << pInstrument->StartDelivDate << endl;
	cout << "结束交割日 TThostFtdcDateType:" << pInstrument->EndDelivDate << endl;
	cout << "合约生命周期状态 TThostFtdcInstLifePhaseType:" << pInstrument->InstLifePhase << endl;
	cout << "当前是否交易 TThostFtdcBoolType:" << pInstrument->IsTrading << endl;
	cout << "持仓类型 TThostFtdcPositionTypeType:" << pInstrument->PositionType << endl;
	cout << "持仓日期类型 TThostFtdcPositionDateTypeType:" << pInstrument->PositionDateType << endl;
	cout << "多头保证金率 TThostFtdcRatioType:" << pInstrument->LongMarginRatio << endl;
	cout << "空头保证金率 TThostFtdcRatioType:" << pInstrument->ShortMarginRatio << endl;
	cout << "是否使用大额单边保证金算法 TThostFtdcMaxMarginSideAlgorithmType:" << pInstrument->MaxMarginSideAlgorithm << endl;
	cout << "基础商品代码 TThostFtdcInstrumentIDType:" << pInstrument->UnderlyingInstrID << endl;
	cout << "执行价 TThostFtdcPriceType:" << pInstrument->StrikePrice << endl;
	cout << "期权类型 TThostFtdcOptionsTypeType:" << pInstrument->OptionsType << endl;
	cout << "合约基础商品乘数 TThostFtdcUnderlyingMultipleType:" << pInstrument->UnderlyingMultiple << endl;
	cout << "组合类型 TThostFtdcCombinationTypeType:" << pInstrument->CombinationType << endl;
	cout << "最小买下单单位 TThostFtdcVolumeType:" << pInstrument->MinBuyVolume << endl;
	cout << "最小卖下单单位 TThostFtdcVolumeType:" << pInstrument->MinSellVolume << endl;
	cout << "合约标识码 TThostFtdcInstrumentCodeType:" << pInstrument->InstrumentCode << endl;
    }
}

///请求查询行情响应
void CTraderSpi::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "交易日 TThostFtdcDateType:" << pDepthMarketData->TradingDay << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pDepthMarketData->InstrumentID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pDepthMarketData->ExchangeID << endl;
	cout << "合约在交易所的代码 TThostFtdcExchangeInstIDType:" << pDepthMarketData->ExchangeInstID << endl;
	cout << "最新价 TThostFtdcPriceType:" << pDepthMarketData->LastPrice << endl;
	cout << "上次结算价 TThostFtdcPriceType:" << pDepthMarketData->PreSettlementPrice << endl;
	cout << "昨收盘 TThostFtdcPriceType:" << pDepthMarketData->PreClosePrice << endl;
	cout << "昨持仓量 TThostFtdcLargeVolumeType:" << pDepthMarketData->PreOpenInterest << endl;
	cout << "今开盘 TThostFtdcPriceType:" << pDepthMarketData->OpenPrice << endl;
	cout << "最高价 TThostFtdcPriceType:" << pDepthMarketData->HighestPrice << endl;
	cout << "最低价 TThostFtdcPriceType:" << pDepthMarketData->LowestPrice << endl;
	cout << "数量 TThostFtdcVolumeType:" << pDepthMarketData->Volume << endl;
	cout << "成交金额 TThostFtdcMoneyType:" << pDepthMarketData->Turnover << endl;
	cout << "持仓量 TThostFtdcLargeVolumeType:" << pDepthMarketData->OpenInterest << endl;
	cout << "今收盘 TThostFtdcPriceType:" << pDepthMarketData->ClosePrice << endl;
	cout << "本次结算价 TThostFtdcPriceType:" << pDepthMarketData->SettlementPrice << endl;
	cout << "涨停板价 TThostFtdcPriceType:" << pDepthMarketData->UpperLimitPrice << endl;
	cout << "跌停板价 TThostFtdcPriceType:" << pDepthMarketData->LowerLimitPrice << endl;
	cout << "昨虚实度 TThostFtdcRatioType:" << pDepthMarketData->PreDelta << endl;
	cout << "今虚实度 TThostFtdcRatioType:" << pDepthMarketData->CurrDelta << endl;
	cout << "最后修改时间 TThostFtdcTimeType:" << pDepthMarketData->UpdateTime << endl;
	cout << "最后修改毫秒 TThostFtdcMillisecType:" << pDepthMarketData->UpdateMillisec << endl;
	cout << "申买价一 TThostFtdcPriceType:" << pDepthMarketData->BidPrice1 << endl;
	cout << "申买量一 TThostFtdcVolumeType:" << pDepthMarketData->BidVolume1 << endl;
	cout << "申卖价一 TThostFtdcPriceType:" << pDepthMarketData->AskPrice1 << endl;
	cout << "申卖量一 TThostFtdcVolumeType:" << pDepthMarketData->AskVolume1 << endl;
	cout << "申买价二 TThostFtdcPriceType:" << pDepthMarketData->BidPrice2 << endl;
	cout << "申买量二 TThostFtdcVolumeType:" << pDepthMarketData->BidVolume2 << endl;
	cout << "申卖价二 TThostFtdcPriceType:" << pDepthMarketData->AskPrice2 << endl;
	cout << "申卖量二 TThostFtdcVolumeType:" << pDepthMarketData->AskVolume2 << endl;
	cout << "申买价三 TThostFtdcPriceType:" << pDepthMarketData->BidPrice3 << endl;
	cout << "申买量三 TThostFtdcVolumeType:" << pDepthMarketData->BidVolume3 << endl;
	cout << "申卖价三 TThostFtdcPriceType:" << pDepthMarketData->AskPrice3 << endl;
	cout << "申卖量三 TThostFtdcVolumeType:" << pDepthMarketData->AskVolume3 << endl;
	cout << "申买价四 TThostFtdcPriceType:" << pDepthMarketData->BidPrice4 << endl;
	cout << "申买量四 TThostFtdcVolumeType:" << pDepthMarketData->BidVolume4 << endl;
	cout << "申卖价四 TThostFtdcPriceType:" << pDepthMarketData->AskPrice4 << endl;
	cout << "申卖量四 TThostFtdcVolumeType:" << pDepthMarketData->AskVolume4 << endl;
	cout << "申买价五 TThostFtdcPriceType:" << pDepthMarketData->BidPrice5 << endl;
	cout << "申买量五 TThostFtdcVolumeType:" << pDepthMarketData->BidVolume5 << endl;
	cout << "申卖价五 TThostFtdcPriceType:" << pDepthMarketData->AskPrice5 << endl;
	cout << "申卖量五 TThostFtdcVolumeType:" << pDepthMarketData->AskVolume5 << endl;
	cout << "当日均价 TThostFtdcPriceType:" << pDepthMarketData->AveragePrice << endl;
	cout << "业务日期 TThostFtdcDateType:" << pDepthMarketData->ActionDay << endl;
    }
}

///请求查询投资者结算结果响应
void CTraderSpi::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField* pSettlementInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "交易日 TThostFtdcDateType:" << pSettlementInfo->TradingDay << endl;
	cout << "结算编号 TThostFtdcSettlementIDType:" << pSettlementInfo->SettlementID << endl;
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pSettlementInfo->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pSettlementInfo->InvestorID << endl;
	cout << "序号 TThostFtdcSequenceNoType:" << pSettlementInfo->SequenceNo << endl;
	cout << "消息正文 TThostFtdcContentType:" << pSettlementInfo->Content << endl;
    }
}

///请求查询转帐银行响应
void CTraderSpi::OnRspQryTransferBank(CThostFtdcTransferBankField* pTransferBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "银行代码 TThostFtdcBankIDType:" << pTransferBank->BankID << endl;
	cout << "银行分中心代码 TThostFtdcBankBrchIDType:" << pTransferBank->BankBrchID << endl;
	cout << "银行名称 TThostFtdcBankNameType:" << pTransferBank->BankName << endl;
	cout << "是否活跃 TThostFtdcBoolType:" << pTransferBank->IsActive << endl;
    }
}

///请求查询投资者持仓明细响应
void CTraderSpi::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField* pInvestorPositionDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pInvestorPositionDetail->InstrumentID << endl;
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pInvestorPositionDetail->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pInvestorPositionDetail->InvestorID << endl;
	cout << "投机套保标志 TThostFtdcHedgeFlagType:" << pInvestorPositionDetail->HedgeFlag << endl;
	cout << "买卖 TThostFtdcDirectionType:" << pInvestorPositionDetail->Direction << endl;
	cout << "开仓日期 TThostFtdcDateType:" << pInvestorPositionDetail->OpenDate << endl;
	cout << "成交编号 TThostFtdcTradeIDType:" << pInvestorPositionDetail->TradeID << endl;
	cout << "数量 TThostFtdcVolumeType:" << pInvestorPositionDetail->Volume << endl;
	cout << "开仓价 TThostFtdcPriceType:" << pInvestorPositionDetail->OpenPrice << endl;
	cout << "交易日 TThostFtdcDateType:" << pInvestorPositionDetail->TradingDay << endl;
	cout << "结算编号 TThostFtdcSettlementIDType:" << pInvestorPositionDetail->SettlementID << endl;
	cout << "成交类型 TThostFtdcTradeTypeType:" << pInvestorPositionDetail->TradeType << endl;
	cout << "组合合约代码 TThostFtdcInstrumentIDType:" << pInvestorPositionDetail->CombInstrumentID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pInvestorPositionDetail->ExchangeID << endl;
	cout << "逐日盯市平仓盈亏 TThostFtdcMoneyType:" << pInvestorPositionDetail->CloseProfitByDate << endl;
	cout << "逐笔对冲平仓盈亏 TThostFtdcMoneyType:" << pInvestorPositionDetail->CloseProfitByTrade << endl;
	cout << "逐日盯市持仓盈亏 TThostFtdcMoneyType:" << pInvestorPositionDetail->PositionProfitByDate << endl;
	cout << "逐笔对冲持仓盈亏 TThostFtdcMoneyType:" << pInvestorPositionDetail->PositionProfitByTrade << endl;
	cout << "投资者保证金 TThostFtdcMoneyType:" << pInvestorPositionDetail->Margin << endl;
	cout << "交易所保证金 TThostFtdcMoneyType:" << pInvestorPositionDetail->ExchMargin << endl;
	cout << "保证金率 TThostFtdcRatioType:" << pInvestorPositionDetail->MarginRateByMoney << endl;
	cout << "保证金率按手数 TThostFtdcRatioType:" << pInvestorPositionDetail->MarginRateByVolume << endl;
	cout << "昨结算价 TThostFtdcPriceType:" << pInvestorPositionDetail->LastSettlementPrice << endl;
	cout << "结算价 TThostFtdcPriceType:" << pInvestorPositionDetail->SettlementPrice << endl;
	cout << "平仓量 TThostFtdcVolumeType:" << pInvestorPositionDetail->CloseVolume << endl;
	cout << "平仓金额 TThostFtdcMoneyType:" << pInvestorPositionDetail->CloseAmount << endl;
    }
}

///请求查询客户通知响应
void CTraderSpi::OnRspQryNotice(CThostFtdcNoticeField* pNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pNotice->BrokerID << endl;
	cout << "消息正文 TThostFtdcContentType:" << pNotice->Content << endl;
	cout << "经纪公司通知内容序列号 TThostFtdcSequenceLabelType:" << pNotice->SequenceLabel << endl;
    }
}

///请求查询结算信息确认响应
void CTraderSpi::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pSettlementInfoConfirm->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pSettlementInfoConfirm->InvestorID << endl;
	cout << "确认日期 TThostFtdcDateType:" << pSettlementInfoConfirm->ConfirmDate << endl;
	cout << "确认时间 TThostFtdcTimeType:" << pSettlementInfoConfirm->ConfirmTime << endl;
    }
}

///请求查询投资者持仓明细响应
void CTraderSpi::OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField* pInvestorPositionCombineDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "交易日 TThostFtdcDateType:" << pInvestorPositionCombineDetail->TradingDay << endl;
	cout << "开仓日期 TThostFtdcDateType:" << pInvestorPositionCombineDetail->OpenDate << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pInvestorPositionCombineDetail->ExchangeID << endl;
	cout << "结算编号 TThostFtdcSettlementIDType:" << pInvestorPositionCombineDetail->SettlementID << endl;
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pInvestorPositionCombineDetail->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pInvestorPositionCombineDetail->InvestorID << endl;
	cout << "组合编号 TThostFtdcTradeIDType:" << pInvestorPositionCombineDetail->ComTradeID << endl;
	cout << "撮合编号 TThostFtdcTradeIDType:" << pInvestorPositionCombineDetail->TradeID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pInvestorPositionCombineDetail->InstrumentID << endl;
	cout << "投机套保标志 TThostFtdcHedgeFlagType:" << pInvestorPositionCombineDetail->HedgeFlag << endl;
	cout << "买卖 TThostFtdcDirectionType:" << pInvestorPositionCombineDetail->Direction << endl;
	cout << "持仓量 TThostFtdcVolumeType:" << pInvestorPositionCombineDetail->TotalAmt << endl;
	cout << "投资者保证金 TThostFtdcMoneyType:" << pInvestorPositionCombineDetail->Margin << endl;
	cout << "交易所保证金 TThostFtdcMoneyType:" << pInvestorPositionCombineDetail->ExchMargin << endl;
	cout << "保证金率 TThostFtdcRatioType:" << pInvestorPositionCombineDetail->MarginRateByMoney << endl;
	cout << "保证金率按手数 TThostFtdcRatioType:" << pInvestorPositionCombineDetail->MarginRateByVolume << endl;
	cout << "单腿编号 TThostFtdcLegIDType:" << pInvestorPositionCombineDetail->LegID << endl;
	cout << "单腿乘数 TThostFtdcLegMultipleType:" << pInvestorPositionCombineDetail->LegMultiple << endl;
	cout << "组合持仓合约编码 TThostFtdcInstrumentIDType:" << pInvestorPositionCombineDetail->CombInstrumentID << endl;
	cout << "成交组号 TThostFtdcTradeGroupIDType:" << pInvestorPositionCombineDetail->TradeGroupID << endl;
    }
}

///查询保证金监管系统经纪公司资金账户密钥响应
void CTraderSpi::OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField* pCFMMCTradingAccountKey, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pCFMMCTradingAccountKey->BrokerID << endl;
	cout << "经纪公司统一编码 TThostFtdcParticipantIDType:" << pCFMMCTradingAccountKey->ParticipantID << endl;
	cout << "投资者帐号 TThostFtdcAccountIDType:" << pCFMMCTradingAccountKey->AccountID << endl;
	cout << "密钥编号 TThostFtdcSequenceNoType:" << pCFMMCTradingAccountKey->KeyID << endl;
	cout << "动态密钥 TThostFtdcCFMMCKeyType:" << pCFMMCTradingAccountKey->CurrentKey << endl;
    }
}

///请求查询仓单折抵信息响应
void CTraderSpi::OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField* pEWarrantOffset, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "交易日期 TThostFtdcTradeDateType:" << pEWarrantOffset->TradingDay << endl;
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pEWarrantOffset->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pEWarrantOffset->InvestorID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pEWarrantOffset->ExchangeID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pEWarrantOffset->InstrumentID << endl;
	cout << "买卖方向 TThostFtdcDirectionType:" << pEWarrantOffset->Direction << endl;
	cout << "投机套保标志 TThostFtdcHedgeFlagType:" << pEWarrantOffset->HedgeFlag << endl;
	cout << "数量 TThostFtdcVolumeType:" << pEWarrantOffset->Volume << endl;
    }
}

///请求查询投资者品种/跨品种保证金响应
void CTraderSpi::OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField* pInvestorProductGroupMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "品种跨品种标示 TThostFtdcInstrumentIDType:" << pInvestorProductGroupMargin->ProductGroupID << endl;
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pInvestorProductGroupMargin->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pInvestorProductGroupMargin->InvestorID << endl;
	cout << "交易日 TThostFtdcDateType:" << pInvestorProductGroupMargin->TradingDay << endl;
	cout << "结算编号 TThostFtdcSettlementIDType:" << pInvestorProductGroupMargin->SettlementID << endl;
	cout << "冻结的保证金 TThostFtdcMoneyType:" << pInvestorProductGroupMargin->FrozenMargin << endl;
	cout << "多头冻结的保证金 TThostFtdcMoneyType:" << pInvestorProductGroupMargin->LongFrozenMargin << endl;
	cout << "空头冻结的保证金 TThostFtdcMoneyType:" << pInvestorProductGroupMargin->ShortFrozenMargin << endl;
	cout << "占用的保证金 TThostFtdcMoneyType:" << pInvestorProductGroupMargin->UseMargin << endl;
	cout << "多头保证金 TThostFtdcMoneyType:" << pInvestorProductGroupMargin->LongUseMargin << endl;
	cout << "空头保证金 TThostFtdcMoneyType:" << pInvestorProductGroupMargin->ShortUseMargin << endl;
	cout << "交易所保证金 TThostFtdcMoneyType:" << pInvestorProductGroupMargin->ExchMargin << endl;
	cout << "交易所多头保证金 TThostFtdcMoneyType:" << pInvestorProductGroupMargin->LongExchMargin << endl;
	cout << "交易所空头保证金 TThostFtdcMoneyType:" << pInvestorProductGroupMargin->ShortExchMargin << endl;
	cout << "平仓盈亏 TThostFtdcMoneyType:" << pInvestorProductGroupMargin->CloseProfit << endl;
	cout << "冻结的手续费 TThostFtdcMoneyType:" << pInvestorProductGroupMargin->FrozenCommission << endl;
	cout << "手续费 TThostFtdcMoneyType:" << pInvestorProductGroupMargin->Commission << endl;
	cout << "冻结的资金 TThostFtdcMoneyType:" << pInvestorProductGroupMargin->FrozenCash << endl;
	cout << "资金差额 TThostFtdcMoneyType:" << pInvestorProductGroupMargin->CashIn << endl;
	cout << "持仓盈亏 TThostFtdcMoneyType:" << pInvestorProductGroupMargin->PositionProfit << endl;
	cout << "折抵总金额 TThostFtdcMoneyType:" << pInvestorProductGroupMargin->OffsetAmount << endl;
	cout << "多头折抵总金额 TThostFtdcMoneyType:" << pInvestorProductGroupMargin->LongOffsetAmount << endl;
	cout << "空头折抵总金额 TThostFtdcMoneyType:" << pInvestorProductGroupMargin->ShortOffsetAmount << endl;
	cout << "交易所折抵总金额 TThostFtdcMoneyType:" << pInvestorProductGroupMargin->ExchOffsetAmount << endl;
	cout << "交易所多头折抵总金额 TThostFtdcMoneyType:" << pInvestorProductGroupMargin->LongExchOffsetAmount << endl;
	cout << "交易所空头折抵总金额 TThostFtdcMoneyType:" << pInvestorProductGroupMargin->ShortExchOffsetAmount << endl;
	cout << "投机套保标志 TThostFtdcHedgeFlagType:" << pInvestorProductGroupMargin->HedgeFlag << endl;
    }
}

///请求查询交易所保证金率响应
void CTraderSpi::OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField* pExchangeMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pExchangeMarginRate->BrokerID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pExchangeMarginRate->InstrumentID << endl;
	cout << "投机套保标志 TThostFtdcHedgeFlagType:" << pExchangeMarginRate->HedgeFlag << endl;
	cout << "多头保证金率 TThostFtdcRatioType:" << pExchangeMarginRate->LongMarginRatioByMoney << endl;
	cout << "多头保证金费 TThostFtdcMoneyType:" << pExchangeMarginRate->LongMarginRatioByVolume << endl;
	cout << "空头保证金率 TThostFtdcRatioType:" << pExchangeMarginRate->ShortMarginRatioByMoney << endl;
	cout << "空头保证金费 TThostFtdcMoneyType:" << pExchangeMarginRate->ShortMarginRatioByVolume << endl;
    }
}

///请求查询交易所调整保证金率响应
void CTraderSpi::OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField* pExchangeMarginRateAdjust, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pExchangeMarginRateAdjust->BrokerID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pExchangeMarginRateAdjust->InstrumentID << endl;
	cout << "投机套保标志 TThostFtdcHedgeFlagType:" << pExchangeMarginRateAdjust->HedgeFlag << endl;
	cout << "跟随交易所投资者多头保证金率 TThostFtdcRatioType:" << pExchangeMarginRateAdjust->LongMarginRatioByMoney << endl;
	cout << "跟随交易所投资者多头保证金费 TThostFtdcMoneyType:" << pExchangeMarginRateAdjust->LongMarginRatioByVolume << endl;
	cout << "跟随交易所投资者空头保证金率 TThostFtdcRatioType:" << pExchangeMarginRateAdjust->ShortMarginRatioByMoney << endl;
	cout << "跟随交易所投资者空头保证金费 TThostFtdcMoneyType:" << pExchangeMarginRateAdjust->ShortMarginRatioByVolume << endl;
	cout << "交易所多头保证金率 TThostFtdcRatioType:" << pExchangeMarginRateAdjust->ExchLongMarginRatioByMoney << endl;
	cout << "交易所多头保证金费 TThostFtdcMoneyType:" << pExchangeMarginRateAdjust->ExchLongMarginRatioByVolume << endl;
	cout << "交易所空头保证金率 TThostFtdcRatioType:" << pExchangeMarginRateAdjust->ExchShortMarginRatioByMoney << endl;
	cout << "交易所空头保证金费 TThostFtdcMoneyType:" << pExchangeMarginRateAdjust->ExchShortMarginRatioByVolume << endl;
	cout << "不跟随交易所投资者多头保证金率 TThostFtdcRatioType:" << pExchangeMarginRateAdjust->NoLongMarginRatioByMoney << endl;
	cout << "不跟随交易所投资者多头保证金费 TThostFtdcMoneyType:" << pExchangeMarginRateAdjust->NoLongMarginRatioByVolume << endl;
	cout << "不跟随交易所投资者空头保证金率 TThostFtdcRatioType:" << pExchangeMarginRateAdjust->NoShortMarginRatioByMoney << endl;
	cout << "不跟随交易所投资者空头保证金费 TThostFtdcMoneyType:" << pExchangeMarginRateAdjust->NoShortMarginRatioByVolume << endl;
    }
}

///请求查询汇率响应
void CTraderSpi::OnRspQryExchangeRate(CThostFtdcExchangeRateField* pExchangeRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pExchangeRate->BrokerID << endl;
	cout << "源币种 TThostFtdcCurrencyIDType:" << pExchangeRate->FromCurrencyID << endl;
	cout << "源币种单位数量 TThostFtdcCurrencyUnitType:" << pExchangeRate->FromCurrencyUnit << endl;
	cout << "目标币种 TThostFtdcCurrencyIDType:" << pExchangeRate->ToCurrencyID << endl;
	cout << "汇率 TThostFtdcExchangeRateType:" << pExchangeRate->ExchangeRate << endl;
    }
}

///请求查询二级代理操作员银期权限响应
void CTraderSpi::OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField* pSecAgentACIDMap, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pSecAgentACIDMap->BrokerID << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pSecAgentACIDMap->UserID << endl;
	cout << "资金账户 TThostFtdcAccountIDType:" << pSecAgentACIDMap->AccountID << endl;
	cout << "币种 TThostFtdcCurrencyIDType:" << pSecAgentACIDMap->CurrencyID << endl;
	cout << "境外中介机构资金帐号 TThostFtdcAccountIDType:" << pSecAgentACIDMap->BrokerSecAgentID << endl;
    }
}

///请求查询产品报价汇率
void CTraderSpi::OnRspQryProductExchRate(CThostFtdcProductExchRateField* pProductExchRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "产品代码 TThostFtdcInstrumentIDType:" << pProductExchRate->ProductID << endl;
	cout << "报价币种类型 TThostFtdcCurrencyIDType:" << pProductExchRate->QuoteCurrencyID << endl;
	cout << "汇率 TThostFtdcExchangeRateType:" << pProductExchRate->ExchangeRate << endl;
    }
}

///请求查询产品组
void CTraderSpi::OnRspQryProductGroup(CThostFtdcProductGroupField* pProductGroup, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "产品代码 TThostFtdcInstrumentIDType:" << pProductGroup->ProductID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pProductGroup->ExchangeID << endl;
	cout << "产品组代码 TThostFtdcInstrumentIDType:" << pProductGroup->ProductGroupID << endl;
    }
}

///请求查询期权交易成本响应
void CTraderSpi::OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField* pOptionInstrTradeCost, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pOptionInstrTradeCost->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pOptionInstrTradeCost->InvestorID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pOptionInstrTradeCost->InstrumentID << endl;
	cout << "投机套保标志 TThostFtdcHedgeFlagType:" << pOptionInstrTradeCost->HedgeFlag << endl;
	cout << "期权合约保证金不变部分 TThostFtdcMoneyType:" << pOptionInstrTradeCost->FixedMargin << endl;
	cout << "期权合约最小保证金 TThostFtdcMoneyType:" << pOptionInstrTradeCost->MiniMargin << endl;
	cout << "期权合约权利金 TThostFtdcMoneyType:" << pOptionInstrTradeCost->Royalty << endl;
	cout << "交易所期权合约保证金不变部分 TThostFtdcMoneyType:" << pOptionInstrTradeCost->ExchFixedMargin << endl;
	cout << "交易所期权合约最小保证金 TThostFtdcMoneyType:" << pOptionInstrTradeCost->ExchMiniMargin << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pOptionInstrTradeCost->ExchangeID << endl;
    }
}

///请求查询期权合约手续费响应
void CTraderSpi::OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField* pOptionInstrCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pOptionInstrCommRate->InstrumentID << endl;
	cout << "投资者范围 TThostFtdcInvestorRangeType:" << pOptionInstrCommRate->InvestorRange << endl;
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pOptionInstrCommRate->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pOptionInstrCommRate->InvestorID << endl;
	cout << "开仓手续费率 TThostFtdcRatioType:" << pOptionInstrCommRate->OpenRatioByMoney << endl;
	cout << "开仓手续费 TThostFtdcRatioType:" << pOptionInstrCommRate->OpenRatioByVolume << endl;
	cout << "平仓手续费率 TThostFtdcRatioType:" << pOptionInstrCommRate->CloseRatioByMoney << endl;
	cout << "平仓手续费 TThostFtdcRatioType:" << pOptionInstrCommRate->CloseRatioByVolume << endl;
	cout << "平今手续费率 TThostFtdcRatioType:" << pOptionInstrCommRate->CloseTodayRatioByMoney << endl;
	cout << "平今手续费 TThostFtdcRatioType:" << pOptionInstrCommRate->CloseTodayRatioByVolume << endl;
	cout << "执行手续费率 TThostFtdcRatioType:" << pOptionInstrCommRate->StrikeRatioByMoney << endl;
	cout << "执行手续费 TThostFtdcRatioType:" << pOptionInstrCommRate->StrikeRatioByVolume << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pOptionInstrCommRate->ExchangeID << endl;
    }
}

///请求查询执行宣告响应
void CTraderSpi::OnRspQryExecOrder(CThostFtdcExecOrderField* pExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pExecOrder->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pExecOrder->InvestorID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pExecOrder->InstrumentID << endl;
	cout << "执行宣告引用 TThostFtdcOrderRefType:" << pExecOrder->ExecOrderRef << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pExecOrder->UserID << endl;
	cout << "数量 TThostFtdcVolumeType:" << pExecOrder->Volume << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pExecOrder->RequestID << endl;
	cout << "业务单元 TThostFtdcBusinessUnitType:" << pExecOrder->BusinessUnit << endl;
	cout << "开平标志 TThostFtdcOffsetFlagType:" << pExecOrder->OffsetFlag << endl;
	cout << "投机套保标志 TThostFtdcHedgeFlagType:" << pExecOrder->HedgeFlag << endl;
	cout << "执行类型 TThostFtdcActionTypeType:" << pExecOrder->ActionType << endl;
	cout << "保留头寸申请的持仓方向 TThostFtdcPosiDirectionType:" << pExecOrder->PosiDirection << endl;
	cout << "期权行权后是否保留期货头寸的标记 TThostFtdcExecOrderPositionFlagType:" << pExecOrder->ReservePositionFlag << endl;
	cout << "期权行权后生成的头寸是否自动平仓 TThostFtdcExecOrderCloseFlagType:" << pExecOrder->CloseFlag << endl;
	cout << "本地执行宣告编号 TThostFtdcOrderLocalIDType:" << pExecOrder->ExecOrderLocalID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pExecOrder->ExchangeID << endl;
	cout << "会员代码 TThostFtdcParticipantIDType:" << pExecOrder->ParticipantID << endl;
	cout << "客户代码 TThostFtdcClientIDType:" << pExecOrder->ClientID << endl;
	cout << "合约在交易所的代码 TThostFtdcExchangeInstIDType:" << pExecOrder->ExchangeInstID << endl;
	cout << "交易所交易员代码 TThostFtdcTraderIDType:" << pExecOrder->TraderID << endl;
	cout << "安装编号 TThostFtdcInstallIDType:" << pExecOrder->InstallID << endl;
	cout << "执行宣告提交状态 TThostFtdcOrderSubmitStatusType:" << pExecOrder->OrderSubmitStatus << endl;
	cout << "报单提示序号 TThostFtdcSequenceNoType:" << pExecOrder->NotifySequence << endl;
	cout << "交易日 TThostFtdcDateType:" << pExecOrder->TradingDay << endl;
	cout << "结算编号 TThostFtdcSettlementIDType:" << pExecOrder->SettlementID << endl;
	cout << "执行宣告编号 TThostFtdcExecOrderSysIDType:" << pExecOrder->ExecOrderSysID << endl;
	cout << "报单日期 TThostFtdcDateType:" << pExecOrder->InsertDate << endl;
	cout << "插入时间 TThostFtdcTimeType:" << pExecOrder->InsertTime << endl;
	cout << "撤销时间 TThostFtdcTimeType:" << pExecOrder->CancelTime << endl;
	cout << "执行结果 TThostFtdcExecResultType:" << pExecOrder->ExecResult << endl;
	cout << "结算会员编号 TThostFtdcParticipantIDType:" << pExecOrder->ClearingPartID << endl;
	cout << "序号 TThostFtdcSequenceNoType:" << pExecOrder->SequenceNo << endl;
	cout << "前置编号 TThostFtdcFrontIDType:" << pExecOrder->FrontID << endl;
	cout << "会话编号 TThostFtdcSessionIDType:" << pExecOrder->SessionID << endl;
	cout << "用户端产品信息 TThostFtdcProductInfoType:" << pExecOrder->UserProductInfo << endl;
	cout << "状态信息 TThostFtdcErrorMsgType:" << pExecOrder->StatusMsg << endl;
	cout << "操作用户代码 TThostFtdcUserIDType:" << pExecOrder->ActiveUserID << endl;
	cout << "经纪公司报单编号 TThostFtdcSequenceNoType:" << pExecOrder->BrokerExecOrderSeq << endl;
	cout << "营业部编号 TThostFtdcBranchIDType:" << pExecOrder->BranchID << endl;
    }
}

///请求查询询价响应
void CTraderSpi::OnRspQryForQuote(CThostFtdcForQuoteField* pForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pForQuote->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pForQuote->InvestorID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pForQuote->InstrumentID << endl;
	cout << "询价引用 TThostFtdcOrderRefType:" << pForQuote->ForQuoteRef << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pForQuote->UserID << endl;
	cout << "本地询价编号 TThostFtdcOrderLocalIDType:" << pForQuote->ForQuoteLocalID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pForQuote->ExchangeID << endl;
	cout << "会员代码 TThostFtdcParticipantIDType:" << pForQuote->ParticipantID << endl;
	cout << "客户代码 TThostFtdcClientIDType:" << pForQuote->ClientID << endl;
	cout << "合约在交易所的代码 TThostFtdcExchangeInstIDType:" << pForQuote->ExchangeInstID << endl;
	cout << "交易所交易员代码 TThostFtdcTraderIDType:" << pForQuote->TraderID << endl;
	cout << "安装编号 TThostFtdcInstallIDType:" << pForQuote->InstallID << endl;
	cout << "报单日期 TThostFtdcDateType:" << pForQuote->InsertDate << endl;
	cout << "插入时间 TThostFtdcTimeType:" << pForQuote->InsertTime << endl;
	cout << "询价状态 TThostFtdcForQuoteStatusType:" << pForQuote->ForQuoteStatus << endl;
	cout << "前置编号 TThostFtdcFrontIDType:" << pForQuote->FrontID << endl;
	cout << "会话编号 TThostFtdcSessionIDType:" << pForQuote->SessionID << endl;
	cout << "状态信息 TThostFtdcErrorMsgType:" << pForQuote->StatusMsg << endl;
	cout << "操作用户代码 TThostFtdcUserIDType:" << pForQuote->ActiveUserID << endl;
	cout << "经纪公司询价编号 TThostFtdcSequenceNoType:" << pForQuote->BrokerForQutoSeq << endl;
    }
}

///请求查询报价响应
void CTraderSpi::OnRspQryQuote(CThostFtdcQuoteField* pQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pQuote->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pQuote->InvestorID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pQuote->InstrumentID << endl;
	cout << "报价引用 TThostFtdcOrderRefType:" << pQuote->QuoteRef << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pQuote->UserID << endl;
	cout << "卖价格 TThostFtdcPriceType:" << pQuote->AskPrice << endl;
	cout << "买价格 TThostFtdcPriceType:" << pQuote->BidPrice << endl;
	cout << "卖数量 TThostFtdcVolumeType:" << pQuote->AskVolume << endl;
	cout << "买数量 TThostFtdcVolumeType:" << pQuote->BidVolume << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pQuote->RequestID << endl;
	cout << "业务单元 TThostFtdcBusinessUnitType:" << pQuote->BusinessUnit << endl;
	cout << "卖开平标志 TThostFtdcOffsetFlagType:" << pQuote->AskOffsetFlag << endl;
	cout << "买开平标志 TThostFtdcOffsetFlagType:" << pQuote->BidOffsetFlag << endl;
	cout << "卖投机套保标志 TThostFtdcHedgeFlagType:" << pQuote->AskHedgeFlag << endl;
	cout << "买投机套保标志 TThostFtdcHedgeFlagType:" << pQuote->BidHedgeFlag << endl;
	cout << "本地报价编号 TThostFtdcOrderLocalIDType:" << pQuote->QuoteLocalID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pQuote->ExchangeID << endl;
	cout << "会员代码 TThostFtdcParticipantIDType:" << pQuote->ParticipantID << endl;
	cout << "客户代码 TThostFtdcClientIDType:" << pQuote->ClientID << endl;
	cout << "合约在交易所的代码 TThostFtdcExchangeInstIDType:" << pQuote->ExchangeInstID << endl;
	cout << "交易所交易员代码 TThostFtdcTraderIDType:" << pQuote->TraderID << endl;
	cout << "安装编号 TThostFtdcInstallIDType:" << pQuote->InstallID << endl;
	cout << "报价提示序号 TThostFtdcSequenceNoType:" << pQuote->NotifySequence << endl;
	cout << "报价提交状态 TThostFtdcOrderSubmitStatusType:" << pQuote->OrderSubmitStatus << endl;
	cout << "交易日 TThostFtdcDateType:" << pQuote->TradingDay << endl;
	cout << "结算编号 TThostFtdcSettlementIDType:" << pQuote->SettlementID << endl;
	cout << "报价编号 TThostFtdcOrderSysIDType:" << pQuote->QuoteSysID << endl;
	cout << "报单日期 TThostFtdcDateType:" << pQuote->InsertDate << endl;
	cout << "插入时间 TThostFtdcTimeType:" << pQuote->InsertTime << endl;
	cout << "撤销时间 TThostFtdcTimeType:" << pQuote->CancelTime << endl;
	cout << "报价状态 TThostFtdcOrderStatusType:" << pQuote->QuoteStatus << endl;
	cout << "结算会员编号 TThostFtdcParticipantIDType:" << pQuote->ClearingPartID << endl;
	cout << "序号 TThostFtdcSequenceNoType:" << pQuote->SequenceNo << endl;
	cout << "卖方报单编号 TThostFtdcOrderSysIDType:" << pQuote->AskOrderSysID << endl;
	cout << "买方报单编号 TThostFtdcOrderSysIDType:" << pQuote->BidOrderSysID << endl;
	cout << "前置编号 TThostFtdcFrontIDType:" << pQuote->FrontID << endl;
	cout << "会话编号 TThostFtdcSessionIDType:" << pQuote->SessionID << endl;
	cout << "用户端产品信息 TThostFtdcProductInfoType:" << pQuote->UserProductInfo << endl;
	cout << "状态信息 TThostFtdcErrorMsgType:" << pQuote->StatusMsg << endl;
	cout << "操作用户代码 TThostFtdcUserIDType:" << pQuote->ActiveUserID << endl;
	cout << "经纪公司报价编号 TThostFtdcSequenceNoType:" << pQuote->BrokerQuoteSeq << endl;
	cout << "衍生卖报单引用 TThostFtdcOrderRefType:" << pQuote->AskOrderRef << endl;
	cout << "衍生买报单引用 TThostFtdcOrderRefType:" << pQuote->BidOrderRef << endl;
	cout << "应价编号 TThostFtdcOrderSysIDType:" << pQuote->ForQuoteSysID << endl;
	cout << "营业部编号 TThostFtdcBranchIDType:" << pQuote->BranchID << endl;
    }
}

///请求查询锁定应答
void CTraderSpi::OnRspQryLock(CThostFtdcLockField* pLock, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pLock->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pLock->InvestorID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pLock->InstrumentID << endl;
	cout << "锁定引用 TThostFtdcOrderRefType:" << pLock->LockRef << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pLock->UserID << endl;
	cout << "数量 TThostFtdcVolumeType:" << pLock->Volume << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pLock->RequestID << endl;
	cout << "业务单元 TThostFtdcBusinessUnitType:" << pLock->BusinessUnit << endl;
	cout << "锁定类型 TThostFtdcLockTypeType:" << pLock->LockType << endl;
	cout << "本地锁定编号 TThostFtdcOrderLocalIDType:" << pLock->LockLocalID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pLock->ExchangeID << endl;
	cout << "会员代码 TThostFtdcParticipantIDType:" << pLock->ParticipantID << endl;
	cout << "客户代码 TThostFtdcClientIDType:" << pLock->ClientID << endl;
	cout << "合约在交易所的代码 TThostFtdcExchangeInstIDType:" << pLock->ExchangeInstID << endl;
	cout << "交易所交易员代码 TThostFtdcTraderIDType:" << pLock->TraderID << endl;
	cout << "安装编号 TThostFtdcInstallIDType:" << pLock->InstallID << endl;
	cout << "执行宣告提交状态 TThostFtdcOrderSubmitStatusType:" << pLock->OrderSubmitStatus << endl;
	cout << "报单提示序号 TThostFtdcSequenceNoType:" << pLock->NotifySequence << endl;
	cout << "交易日 TThostFtdcDateType:" << pLock->TradingDay << endl;
	cout << "结算编号 TThostFtdcSettlementIDType:" << pLock->SettlementID << endl;
	cout << "锁定编号 TThostFtdcOrderSysIDType:" << pLock->LockSysID << endl;
	cout << "报单日期 TThostFtdcDateType:" << pLock->InsertDate << endl;
	cout << "插入时间 TThostFtdcTimeType:" << pLock->InsertTime << endl;
	cout << "撤销时间 TThostFtdcTimeType:" << pLock->CancelTime << endl;
	cout << "锁定状态 TThostFtdcOrderActionStatusType:" << pLock->LockStatus << endl;
	cout << "结算会员编号 TThostFtdcParticipantIDType:" << pLock->ClearingPartID << endl;
	cout << "序号 TThostFtdcSequenceNoType:" << pLock->SequenceNo << endl;
	cout << "前置编号 TThostFtdcFrontIDType:" << pLock->FrontID << endl;
	cout << "会话编号 TThostFtdcSessionIDType:" << pLock->SessionID << endl;
	cout << "用户端产品信息 TThostFtdcProductInfoType:" << pLock->UserProductInfo << endl;
	cout << "状态信息 TThostFtdcErrorMsgType:" << pLock->StatusMsg << endl;
	cout << "操作用户代码 TThostFtdcUserIDType:" << pLock->ActiveUserID << endl;
	cout << "经纪公司报单编号 TThostFtdcSequenceNoType:" << pLock->BrokerLockSeq << endl;
	cout << "营业部编号 TThostFtdcBranchIDType:" << pLock->BranchID << endl;
    }
}

///请求查询锁定证券仓位应答
void CTraderSpi::OnRspQryLockPosition(CThostFtdcLockPositionField* pLockPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pLockPosition->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pLockPosition->InvestorID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pLockPosition->InstrumentID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pLockPosition->ExchangeID << endl;
	cout << "数量 TThostFtdcVolumeType:" << pLockPosition->Volume << endl;
	cout << "冻结数量 TThostFtdcVolumeType:" << pLockPosition->FrozenVolume << endl;
    }
}

///请求查询投资者分级
void CTraderSpi::OnRspQryInvestorLevel(CThostFtdcInvestorLevelField* pInvestorLevel, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pInvestorLevel->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pInvestorLevel->InvestorID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pInvestorLevel->ExchangeID << endl;
	cout << "投资者分级类型 TThostFtdcLevelTypeType:" << pInvestorLevel->LevelType << endl;
    }
}

///请求查询E+1日行权冻结响应
void CTraderSpi::OnRspQryExecFreeze(CThostFtdcExecFreezeField* pExecFreeze, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "标的合约代码 TThostFtdcInstrumentIDType:" << pExecFreeze->InstrumentID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pExecFreeze->ExchangeID << endl;
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pExecFreeze->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pExecFreeze->InvestorID << endl;
	cout << "持仓多空方向 TThostFtdcPosiDirectionType:" << pExecFreeze->PosiDirection << endl;
	cout << "期权类型 TThostFtdcOptionsTypeType:" << pExecFreeze->OptionsType << endl;
	cout << "冻结的数量单位股 TThostFtdcVolumeType:" << pExecFreeze->Volume << endl;
	cout << "冻结金额 TThostFtdcMoneyType:" << pExecFreeze->FrozenAmount << endl;
    }
}

///请求查询组合合约安全系数响应
void CTraderSpi::OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField* pCombInstrumentGuard, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pCombInstrumentGuard->BrokerID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pCombInstrumentGuard->InstrumentID << endl;
	cout << "未知 TThostFtdcRatioType:" << pCombInstrumentGuard->GuarantRatio << endl;
    }
}

///请求查询申请组合响应
void CTraderSpi::OnRspQryCombAction(CThostFtdcCombActionField* pCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pCombAction->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pCombAction->InvestorID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pCombAction->InstrumentID << endl;
	cout << "组合引用 TThostFtdcOrderRefType:" << pCombAction->CombActionRef << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pCombAction->UserID << endl;
	cout << "买卖方向 TThostFtdcDirectionType:" << pCombAction->Direction << endl;
	cout << "数量 TThostFtdcVolumeType:" << pCombAction->Volume << endl;
	cout << "组合指令方向 TThostFtdcCombDirectionType:" << pCombAction->CombDirection << endl;
	cout << "投机套保标志 TThostFtdcHedgeFlagType:" << pCombAction->HedgeFlag << endl;
	cout << "本地申请组合编号 TThostFtdcOrderLocalIDType:" << pCombAction->ActionLocalID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pCombAction->ExchangeID << endl;
	cout << "会员代码 TThostFtdcParticipantIDType:" << pCombAction->ParticipantID << endl;
	cout << "客户代码 TThostFtdcClientIDType:" << pCombAction->ClientID << endl;
	cout << "合约在交易所的代码 TThostFtdcExchangeInstIDType:" << pCombAction->ExchangeInstID << endl;
	cout << "交易所交易员代码 TThostFtdcTraderIDType:" << pCombAction->TraderID << endl;
	cout << "安装编号 TThostFtdcInstallIDType:" << pCombAction->InstallID << endl;
	cout << "组合状态 TThostFtdcOrderActionStatusType:" << pCombAction->ActionStatus << endl;
	cout << "报单提示序号 TThostFtdcSequenceNoType:" << pCombAction->NotifySequence << endl;
	cout << "交易日 TThostFtdcDateType:" << pCombAction->TradingDay << endl;
	cout << "结算编号 TThostFtdcSettlementIDType:" << pCombAction->SettlementID << endl;
	cout << "序号 TThostFtdcSequenceNoType:" << pCombAction->SequenceNo << endl;
	cout << "前置编号 TThostFtdcFrontIDType:" << pCombAction->FrontID << endl;
	cout << "会话编号 TThostFtdcSessionIDType:" << pCombAction->SessionID << endl;
	cout << "用户端产品信息 TThostFtdcProductInfoType:" << pCombAction->UserProductInfo << endl;
	cout << "状态信息 TThostFtdcErrorMsgType:" << pCombAction->StatusMsg << endl;
    }
}

///请求查询转帐流水响应
void CTraderSpi::OnRspQryTransferSerial(CThostFtdcTransferSerialField* pTransferSerial, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "平台流水号 TThostFtdcPlateSerialType:" << pTransferSerial->PlateSerial << endl;
	cout << "交易发起方日期 TThostFtdcTradeDateType:" << pTransferSerial->TradeDate << endl;
	cout << "交易日期 TThostFtdcDateType:" << pTransferSerial->TradingDay << endl;
	cout << "交易时间 TThostFtdcTradeTimeType:" << pTransferSerial->TradeTime << endl;
	cout << "交易代码 TThostFtdcTradeCodeType:" << pTransferSerial->TradeCode << endl;
	cout << "会话编号 TThostFtdcSessionIDType:" << pTransferSerial->SessionID << endl;
	cout << "银行编码 TThostFtdcBankIDType:" << pTransferSerial->BankID << endl;
	cout << "银行分支机构编码 TThostFtdcBankBrchIDType:" << pTransferSerial->BankBranchID << endl;
	cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << pTransferSerial->BankAccType << endl;
	cout << "银行帐号 TThostFtdcBankAccountType:" << pTransferSerial->BankAccount << endl;
	cout << "银行流水号 TThostFtdcBankSerialType:" << pTransferSerial->BankSerial << endl;
	cout << "期货公司编码 TThostFtdcBrokerIDType:" << pTransferSerial->BrokerID << endl;
	cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << pTransferSerial->BrokerBranchID << endl;
	cout << "期货公司帐号类型 TThostFtdcFutureAccTypeType:" << pTransferSerial->FutureAccType << endl;
	cout << "投资者帐号 TThostFtdcAccountIDType:" << pTransferSerial->AccountID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pTransferSerial->InvestorID << endl;
	cout << "期货公司流水号 TThostFtdcFutureSerialType:" << pTransferSerial->FutureSerial << endl;
	cout << "证件类型 TThostFtdcIdCardTypeType:" << pTransferSerial->IdCardType << endl;
	cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pTransferSerial->IdentifiedCardNo << endl;
	cout << "币种代码 TThostFtdcCurrencyIDType:" << pTransferSerial->CurrencyID << endl;
	cout << "交易金额 TThostFtdcTradeAmountType:" << pTransferSerial->TradeAmount << endl;
	cout << "应收客户费用 TThostFtdcCustFeeType:" << pTransferSerial->CustFee << endl;
	cout << "应收期货公司费用 TThostFtdcFutureFeeType:" << pTransferSerial->BrokerFee << endl;
	cout << "有效标志 TThostFtdcAvailabilityFlagType:" << pTransferSerial->AvailabilityFlag << endl;
	cout << "操作员 TThostFtdcOperatorCodeType:" << pTransferSerial->OperatorCode << endl;
	cout << "新银行帐号 TThostFtdcBankAccountType:" << pTransferSerial->BankNewAccount << endl;
	cout << "错误代码 TThostFtdcErrorIDType:" << pTransferSerial->ErrorID << endl;
	cout << "错误信息 TThostFtdcErrorMsgType:" << pTransferSerial->ErrorMsg << endl;
    }
}

///请求查询银期签约关系响应
void CTraderSpi::OnRspQryAccountregister(CThostFtdcAccountregisterField* pAccountregister, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "交易日期 TThostFtdcTradeDateType:" << pAccountregister->TradeDay << endl;
	cout << "银行编码 TThostFtdcBankIDType:" << pAccountregister->BankID << endl;
	cout << "银行分支机构编码 TThostFtdcBankBrchIDType:" << pAccountregister->BankBranchID << endl;
	cout << "银行帐号 TThostFtdcBankAccountType:" << pAccountregister->BankAccount << endl;
	cout << "期货公司编码 TThostFtdcBrokerIDType:" << pAccountregister->BrokerID << endl;
	cout << "期货公司分支机构编码 TThostFtdcFutureBranchIDType:" << pAccountregister->BrokerBranchID << endl;
	cout << "投资者帐号 TThostFtdcAccountIDType:" << pAccountregister->AccountID << endl;
	cout << "证件类型 TThostFtdcIdCardTypeType:" << pAccountregister->IdCardType << endl;
	cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pAccountregister->IdentifiedCardNo << endl;
	cout << "客户姓名 TThostFtdcIndividualNameType:" << pAccountregister->CustomerName << endl;
	cout << "币种代码 TThostFtdcCurrencyIDType:" << pAccountregister->CurrencyID << endl;
	cout << "开销户类别 TThostFtdcOpenOrDestroyType:" << pAccountregister->OpenOrDestroy << endl;
	cout << "签约日期 TThostFtdcTradeDateType:" << pAccountregister->RegDate << endl;
	cout << "解约日期 TThostFtdcTradeDateType:" << pAccountregister->OutDate << endl;
	// cout << "交易ID:" << pAccountregister->TThostFtdcTIDType << endlTID;
	cout << "客户类型 TThostFtdcCustTypeType:" << pAccountregister->CustType << endl;
	cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << pAccountregister->BankAccType << endl;
    }
}

///错误应答
void CTraderSpi::OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> ErrorID=" << pRspInfo->ErrorID << ", ErrorMsg=" << pRspInfo->ErrorMsg << endl;
}

///报单通知
void CTraderSpi::OnRtnOrder(CThostFtdcOrderField* pOrder)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pOrder->BrokerID << endl;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << pOrder->InvestorID << endl;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << pOrder->InstrumentID << endl;
    cout << "报单引用 TThostFtdcOrderRefType:" << pOrder->OrderRef << endl;
    cout << "用户代码 TThostFtdcUserIDType:" << pOrder->UserID << endl;
    cout << "报单价格条件 TThostFtdcOrderPriceTypeType:" << pOrder->OrderPriceType << endl;
    cout << "买卖方向 TThostFtdcDirectionType:" << pOrder->Direction << endl;
    cout << "组合开平标志 TThostFtdcCombOffsetFlagType:" << pOrder->CombOffsetFlag << endl;
    cout << "组合投机套保标志 TThostFtdcCombHedgeFlagType:" << pOrder->CombHedgeFlag << endl;
    cout << "价格 TThostFtdcPriceType:" << pOrder->LimitPrice << endl;
    cout << "数量 TThostFtdcVolumeType:" << pOrder->VolumeTotalOriginal << endl;
    cout << "有效期类型 TThostFtdcTimeConditionType:" << pOrder->TimeCondition << endl;
    // cout << "GTD日期:" << pOrder->TThostFtdcDateType << endlGTDDate;
    cout << "成交量类型 TThostFtdcVolumeConditionType:" << pOrder->VolumeCondition << endl;
    cout << "最小成交量 TThostFtdcVolumeType:" << pOrder->MinVolume << endl;
    cout << "触发条件 TThostFtdcContingentConditionType:" << pOrder->ContingentCondition << endl;
    cout << "止损价 TThostFtdcPriceType:" << pOrder->StopPrice << endl;
    cout << "强平原因 TThostFtdcForceCloseReasonType:" << pOrder->ForceCloseReason << endl;
    cout << "自动挂起标志 TThostFtdcBoolType:" << pOrder->IsAutoSuspend << endl;
    cout << "业务单元 TThostFtdcBusinessUnitType:" << pOrder->BusinessUnit << endl;
    cout << "请求编号 TThostFtdcRequestIDType:" << pOrder->RequestID << endl;
    cout << "本地报单编号 TThostFtdcOrderLocalIDType:" << pOrder->OrderLocalID << endl;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << pOrder->ExchangeID << endl;
    cout << "会员代码 TThostFtdcParticipantIDType:" << pOrder->ParticipantID << endl;
    cout << "客户代码 TThostFtdcClientIDType:" << pOrder->ClientID << endl;
    cout << "合约在交易所的代码 TThostFtdcExchangeInstIDType:" << pOrder->ExchangeInstID << endl;
    cout << "交易所交易员代码 TThostFtdcTraderIDType:" << pOrder->TraderID << endl;
    cout << "安装编号 TThostFtdcInstallIDType:" << pOrder->InstallID << endl;
    cout << "报单提交状态 TThostFtdcOrderSubmitStatusType:" << pOrder->OrderSubmitStatus << endl;
    cout << "报单提示序号 TThostFtdcSequenceNoType:" << pOrder->NotifySequence << endl;
    cout << "交易日 TThostFtdcDateType:" << pOrder->TradingDay << endl;
    cout << "结算编号 TThostFtdcSettlementIDType:" << pOrder->SettlementID << endl;
    cout << "报单编号 TThostFtdcOrderSysIDType:" << pOrder->OrderSysID << endl;
    cout << "报单来源 TThostFtdcOrderSourceType:" << pOrder->OrderSource << endl;
    cout << "报单状态 TThostFtdcOrderStatusType:" << pOrder->OrderStatus << endl;
    cout << "报单类型 TThostFtdcOrderTypeType:" << pOrder->OrderType << endl;
    cout << "今成交数量 TThostFtdcVolumeType:" << pOrder->VolumeTraded << endl;
    cout << "剩余数量 TThostFtdcVolumeType:" << pOrder->VolumeTotal << endl;
    cout << "报单日期 TThostFtdcDateType:" << pOrder->InsertDate << endl;
    cout << "委托时间 TThostFtdcTimeType:" << pOrder->InsertTime << endl;
    cout << "激活时间 TThostFtdcTimeType:" << pOrder->ActiveTime << endl;
    cout << "挂起时间 TThostFtdcTimeType:" << pOrder->SuspendTime << endl;
    cout << "最后修改时间 TThostFtdcTimeType:" << pOrder->UpdateTime << endl;
    cout << "撤销时间 TThostFtdcTimeType:" << pOrder->CancelTime << endl;
    cout << "最后修改交易所交易员代码 TThostFtdcTraderIDType:" << pOrder->ActiveTraderID << endl;
    cout << "结算会员编号 TThostFtdcParticipantIDType:" << pOrder->ClearingPartID << endl;
    cout << "序号 TThostFtdcSequenceNoType:" << pOrder->SequenceNo << endl;
    cout << "前置编号 TThostFtdcFrontIDType:" << pOrder->FrontID << endl;
    cout << "会话编号 TThostFtdcSessionIDType:" << pOrder->SessionID << endl;
    cout << "用户端产品信息 TThostFtdcProductInfoType:" << pOrder->UserProductInfo << endl;
    cout << "状态信息 TThostFtdcErrorMsgType:" << pOrder->StatusMsg << endl;
    cout << "用户强评标志 TThostFtdcBoolType:" << pOrder->UserForceClose << endl;
    cout << "操作用户代码 TThostFtdcUserIDType:" << pOrder->ActiveUserID << endl;
    cout << "经纪公司报单编号 TThostFtdcSequenceNoType:" << pOrder->BrokerOrderSeq << endl;
    cout << "相关报单 TThostFtdcOrderSysIDType:" << pOrder->RelativeOrderSysID << endl;
    cout << "郑商所成交数量 TThostFtdcVolumeType:" << pOrder->ZCETotalTradedVolume << endl;
    cout << "互换单标志 TThostFtdcBoolType:" << pOrder->IsSwapOrder << endl;
    cout << "营业部编号 TThostFtdcBranchIDType:" << pOrder->BranchID << endl;
}

///成交通知
void CTraderSpi::OnRtnTrade(CThostFtdcTradeField* pTrade)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pTrade->BrokerID << endl;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << pTrade->InvestorID << endl;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << pTrade->InstrumentID << endl;
    cout << "报单引用 TThostFtdcOrderRefType:" << pTrade->OrderRef << endl;
    cout << "用户代码 TThostFtdcUserIDType:" << pTrade->UserID << endl;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << pTrade->ExchangeID << endl;
    cout << "成交编号 TThostFtdcTradeIDType:" << pTrade->TradeID << endl;
    cout << "买卖方向 TThostFtdcDirectionType:" << pTrade->Direction << endl;
    cout << "报单编号 TThostFtdcOrderSysIDType:" << pTrade->OrderSysID << endl;
    cout << "会员代码 TThostFtdcParticipantIDType:" << pTrade->ParticipantID << endl;
    cout << "客户代码 TThostFtdcClientIDType:" << pTrade->ClientID << endl;
    cout << "交易角色 TThostFtdcTradingRoleType:" << pTrade->TradingRole << endl;
    cout << "合约在交易所的代码 TThostFtdcExchangeInstIDType:" << pTrade->ExchangeInstID << endl;
    cout << "开平标志 TThostFtdcOffsetFlagType:" << pTrade->OffsetFlag << endl;
    cout << "投机套保标志 TThostFtdcHedgeFlagType:" << pTrade->HedgeFlag << endl;
    cout << "价格 TThostFtdcPriceType:" << pTrade->Price << endl;
    cout << "数量 TThostFtdcVolumeType:" << pTrade->Volume << endl;
    cout << "成交时期 TThostFtdcDateType:" << pTrade->TradeDate << endl;
    cout << "成交时间 TThostFtdcTimeType:" << pTrade->TradeTime << endl;
    cout << "成交类型 TThostFtdcTradeTypeType:" << pTrade->TradeType << endl;
    cout << "成交价来源 TThostFtdcPriceSourceType:" << pTrade->PriceSource << endl;
    cout << "交易所交易员代码 TThostFtdcTraderIDType:" << pTrade->TraderID << endl;
    cout << "本地报单编号 TThostFtdcOrderLocalIDType:" << pTrade->OrderLocalID << endl;
    cout << "结算会员编号 TThostFtdcParticipantIDType:" << pTrade->ClearingPartID << endl;
    cout << "业务单元 TThostFtdcBusinessUnitType:" << pTrade->BusinessUnit << endl;
    cout << "序号 TThostFtdcSequenceNoType:" << pTrade->SequenceNo << endl;
    cout << "交易日 TThostFtdcDateType:" << pTrade->TradingDay << endl;
    cout << "结算编号 TThostFtdcSettlementIDType:" << pTrade->SettlementID << endl;
    cout << "经纪公司报单编号 TThostFtdcSequenceNoType:" << pTrade->BrokerOrderSeq << endl;
    cout << "成交来源 TThostFtdcTradeSourceType:" << pTrade->TradeSource << endl;
}

///报单录入错误回报
void CTraderSpi::OnErrRtnOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (!IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pInputOrder->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pInputOrder->InvestorID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pInputOrder->InstrumentID << endl;
	cout << "报单引用 TThostFtdcOrderRefType:" << pInputOrder->OrderRef << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pInputOrder->UserID << endl;
	cout << "报单价格条件 TThostFtdcOrderPriceTypeType:" << pInputOrder->OrderPriceType << endl;
	cout << "买卖方向 TThostFtdcDirectionType:" << pInputOrder->Direction << endl;
	cout << "组合开平标志 TThostFtdcCombOffsetFlagType:" << pInputOrder->CombOffsetFlag << endl;
	cout << "组合投机套保标志 TThostFtdcCombHedgeFlagType:" << pInputOrder->CombHedgeFlag << endl;
	cout << "价格 TThostFtdcPriceType:" << pInputOrder->LimitPrice << endl;
	cout << "数量 TThostFtdcVolumeType:" << pInputOrder->VolumeTotalOriginal << endl;
	cout << "有效期类型 TThostFtdcTimeConditionType:" << pInputOrder->TimeCondition << endl;
	cout << "日期 TThostFtdcDateType:" << pInputOrder->GTDDate << endl;
	cout << "成交量类型 TThostFtdcVolumeConditionType:" << pInputOrder->VolumeCondition << endl;
	cout << "最小成交量 TThostFtdcVolumeType:" << pInputOrder->MinVolume << endl;
	cout << "触发条件 TThostFtdcContingentConditionType:" << pInputOrder->ContingentCondition << endl;
	cout << "止损价 TThostFtdcPriceType:" << pInputOrder->StopPrice << endl;
	cout << "强平原因 TThostFtdcForceCloseReasonType:" << pInputOrder->ForceCloseReason << endl;
	cout << "自动挂起标志 TThostFtdcBoolType:" << pInputOrder->IsAutoSuspend << endl;
	cout << "业务单元 TThostFtdcBusinessUnitType:" << pInputOrder->BusinessUnit << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pInputOrder->RequestID << endl;
	cout << "用户强评标志 TThostFtdcBoolType:" << pInputOrder->UserForceClose << endl;
	cout << "互换单标志 TThostFtdcBoolType:" << pInputOrder->IsSwapOrder << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pInputOrder->ExchangeID << endl;
    }
}

///报单操作错误回报
void CTraderSpi::OnErrRtnOrderAction(CThostFtdcOrderActionField* pOrderAction, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (!IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pOrderAction->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pOrderAction->InvestorID << endl;
	cout << "报单操作引用 TThostFtdcOrderActionRefType:" << pOrderAction->OrderActionRef << endl;
	cout << "报单引用 TThostFtdcOrderRefType:" << pOrderAction->OrderRef << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pOrderAction->RequestID << endl;
	cout << "前置编号 TThostFtdcFrontIDType:" << pOrderAction->FrontID << endl;
	cout << "会话编号 TThostFtdcSessionIDType:" << pOrderAction->SessionID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pOrderAction->ExchangeID << endl;
	cout << "报单编号 TThostFtdcOrderSysIDType:" << pOrderAction->OrderSysID << endl;
	cout << "操作标志 TThostFtdcActionFlagType:" << pOrderAction->ActionFlag << endl;
	cout << "价格 TThostFtdcPriceType:" << pOrderAction->LimitPrice << endl;
	cout << "数量变化 TThostFtdcVolumeType:" << pOrderAction->VolumeChange << endl;
	cout << "操作日期 TThostFtdcDateType:" << pOrderAction->ActionDate << endl;
	cout << "操作时间 TThostFtdcTimeType:" << pOrderAction->ActionTime << endl;
	cout << "交易所交易员代码 TThostFtdcTraderIDType:" << pOrderAction->TraderID << endl;
	cout << "安装编号 TThostFtdcInstallIDType:" << pOrderAction->InstallID << endl;
	cout << "本地报单编号 TThostFtdcOrderLocalIDType:" << pOrderAction->OrderLocalID << endl;
	cout << "操作本地编号 TThostFtdcOrderLocalIDType:" << pOrderAction->ActionLocalID << endl;
	cout << "会员代码 TThostFtdcParticipantIDType:" << pOrderAction->ParticipantID << endl;
	cout << "客户代码 TThostFtdcClientIDType:" << pOrderAction->ClientID << endl;
	cout << "业务单元 TThostFtdcBusinessUnitType:" << pOrderAction->BusinessUnit << endl;
	cout << "报单操作状态 TThostFtdcOrderActionStatusType:" << pOrderAction->OrderActionStatus << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pOrderAction->UserID << endl;
	cout << "状态信息 TThostFtdcErrorMsgType:" << pOrderAction->StatusMsg << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pOrderAction->InstrumentID << endl;
	cout << "营业部编号 TThostFtdcBranchIDType:" << pOrderAction->BranchID << endl;
    }
}

///合约交易状态通知
void CTraderSpi::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField* pInstrumentStatus)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << pInstrumentStatus->ExchangeID << endl;
    cout << "合约在交易所的代码 TThostFtdcExchangeInstIDType:" << pInstrumentStatus->ExchangeInstID << endl;
    cout << "结算组代码 TThostFtdcSettlementGroupIDType:" << pInstrumentStatus->SettlementGroupID << endl;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << pInstrumentStatus->InstrumentID << endl;
    cout << "合约交易状态 TThostFtdcInstrumentStatusType:" << pInstrumentStatus->InstrumentStatus << endl;
    cout << "交易阶段编号 TThostFtdcTradingSegmentSNType:" << pInstrumentStatus->TradingSegmentSN << endl;
    cout << "进入本状态时间 TThostFtdcTimeType:" << pInstrumentStatus->EnterTime << endl;
    cout << "进入本状态原因 TThostFtdcInstStatusEnterReasonType:" << pInstrumentStatus->EnterReason << endl;
}

///交易通知
void CTraderSpi::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField* pTradingNoticeInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pTradingNoticeInfo->BrokerID << endl;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << pTradingNoticeInfo->InvestorID << endl;
    cout << "发送时间 TThostFtdcTimeType:" << pTradingNoticeInfo->SendTime << endl;
    cout << "消息正文 TThostFtdcContentType:" << pTradingNoticeInfo->FieldContent << endl;
    cout << "序列系列号 TThostFtdcSequenceSeriesType:" << pTradingNoticeInfo->SequenceSeries << endl;
    cout << "序列号 TThostFtdcSequenceNoType:" << pTradingNoticeInfo->SequenceNo << endl;
}

///提示条件单校验错误
void CTraderSpi::OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField* pErrorConditionalOrder)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pErrorConditionalOrder->BrokerID << endl;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << pErrorConditionalOrder->InvestorID << endl;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << pErrorConditionalOrder->InstrumentID << endl;
    cout << "报单引用 TThostFtdcOrderRefType:" << pErrorConditionalOrder->OrderRef << endl;
    cout << "用户代码 TThostFtdcUserIDType:" << pErrorConditionalOrder->UserID << endl;
    cout << "报单价格条件 TThostFtdcOrderPriceTypeType:" << pErrorConditionalOrder->OrderPriceType << endl;
    cout << "买卖方向 TThostFtdcDirectionType:" << pErrorConditionalOrder->Direction << endl;
    cout << "组合开平标志 TThostFtdcCombOffsetFlagType:" << pErrorConditionalOrder->CombOffsetFlag << endl;
    cout << "组合投机套保标志 TThostFtdcCombHedgeFlagType:" << pErrorConditionalOrder->CombHedgeFlag << endl;
    cout << "价格 TThostFtdcPriceType:" << pErrorConditionalOrder->LimitPrice << endl;
    cout << "数量 TThostFtdcVolumeType:" << pErrorConditionalOrder->VolumeTotalOriginal << endl;
    cout << "有效期类型 TThostFtdcTimeConditionType:" << pErrorConditionalOrder->TimeCondition << endl;
    cout << "日期 TThostFtdcDateType:" << pErrorConditionalOrder->GTDDate << endl;
    cout << "成交量类型 TThostFtdcVolumeConditionType:" << pErrorConditionalOrder->VolumeCondition << endl;
    cout << "最小成交量 TThostFtdcVolumeType:" << pErrorConditionalOrder->MinVolume << endl;
    cout << "触发条件 TThostFtdcContingentConditionType:" << pErrorConditionalOrder->ContingentCondition << endl;
    cout << "止损价 TThostFtdcPriceType:" << pErrorConditionalOrder->StopPrice << endl;
    cout << "强平原因 TThostFtdcForceCloseReasonType:" << pErrorConditionalOrder->ForceCloseReason << endl;
    cout << "自动挂起标志 TThostFtdcBoolType:" << pErrorConditionalOrder->IsAutoSuspend << endl;
    cout << "业务单元 TThostFtdcBusinessUnitType:" << pErrorConditionalOrder->BusinessUnit << endl;
    cout << "请求编号 TThostFtdcRequestIDType:" << pErrorConditionalOrder->RequestID << endl;
    cout << "本地报单编号 TThostFtdcOrderLocalIDType:" << pErrorConditionalOrder->OrderLocalID << endl;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << pErrorConditionalOrder->ExchangeID << endl;
    cout << "会员代码 TThostFtdcParticipantIDType:" << pErrorConditionalOrder->ParticipantID << endl;
    cout << "客户代码 TThostFtdcClientIDType:" << pErrorConditionalOrder->ClientID << endl;
    cout << "合约在交易所的代码 TThostFtdcExchangeInstIDType:" << pErrorConditionalOrder->ExchangeInstID << endl;
    cout << "交易所交易员代码 TThostFtdcTraderIDType:" << pErrorConditionalOrder->TraderID << endl;
    cout << "安装编号 TThostFtdcInstallIDType:" << pErrorConditionalOrder->InstallID << endl;
    cout << "报单提交状态 TThostFtdcOrderSubmitStatusType:" << pErrorConditionalOrder->OrderSubmitStatus << endl;
    cout << "报单提示序号 TThostFtdcSequenceNoType:" << pErrorConditionalOrder->NotifySequence << endl;
    cout << "交易日 TThostFtdcDateType:" << pErrorConditionalOrder->TradingDay << endl;
    cout << "结算编号 TThostFtdcSettlementIDType:" << pErrorConditionalOrder->SettlementID << endl;
    cout << "报单编号 TThostFtdcOrderSysIDType:" << pErrorConditionalOrder->OrderSysID << endl;
    cout << "报单来源 TThostFtdcOrderSourceType:" << pErrorConditionalOrder->OrderSource << endl;
    cout << "报单状态 TThostFtdcOrderStatusType:" << pErrorConditionalOrder->OrderStatus << endl;
    cout << "报单类型 TThostFtdcOrderTypeType:" << pErrorConditionalOrder->OrderType << endl;
    cout << "今成交数量 TThostFtdcVolumeType:" << pErrorConditionalOrder->VolumeTraded << endl;
    cout << "剩余数量 TThostFtdcVolumeType:" << pErrorConditionalOrder->VolumeTotal << endl;
    cout << "报单日期 TThostFtdcDateType:" << pErrorConditionalOrder->InsertDate << endl;
    cout << "委托时间 TThostFtdcTimeType:" << pErrorConditionalOrder->InsertTime << endl;
    cout << "激活时间 TThostFtdcTimeType:" << pErrorConditionalOrder->ActiveTime << endl;
    cout << "挂起时间 TThostFtdcTimeType:" << pErrorConditionalOrder->SuspendTime << endl;
    cout << "最后修改时间 TThostFtdcTimeType:" << pErrorConditionalOrder->UpdateTime << endl;
    cout << "撤销时间 TThostFtdcTimeType:" << pErrorConditionalOrder->CancelTime << endl;
    cout << "最后修改交易所交易员代码 TThostFtdcTraderIDType:" << pErrorConditionalOrder->ActiveTraderID << endl;
    cout << "结算会员编号 TThostFtdcParticipantIDType:" << pErrorConditionalOrder->ClearingPartID << endl;
    cout << "序号 TThostFtdcSequenceNoType:" << pErrorConditionalOrder->SequenceNo << endl;
    cout << "前置编号 TThostFtdcFrontIDType:" << pErrorConditionalOrder->FrontID << endl;
    cout << "会话编号 TThostFtdcSessionIDType:" << pErrorConditionalOrder->SessionID << endl;
    cout << "用户端产品信息 TThostFtdcProductInfoType:" << pErrorConditionalOrder->UserProductInfo << endl;
    cout << "状态信息 TThostFtdcErrorMsgType:" << pErrorConditionalOrder->StatusMsg << endl;
    cout << "用户强评标志 TThostFtdcBoolType:" << pErrorConditionalOrder->UserForceClose << endl;
    cout << "操作用户代码 TThostFtdcUserIDType:" << pErrorConditionalOrder->ActiveUserID << endl;
    cout << "经纪公司报单编号 TThostFtdcSequenceNoType:" << pErrorConditionalOrder->BrokerOrderSeq << endl;
    cout << "相关报单 TThostFtdcOrderSysIDType:" << pErrorConditionalOrder->RelativeOrderSysID << endl;
    cout << "郑商所成交数量 TThostFtdcVolumeType:" << pErrorConditionalOrder->ZCETotalTradedVolume << endl;
    cout << "错误代码 TThostFtdcErrorIDType:" << pErrorConditionalOrder->ErrorID << endl;
    cout << "错误信息 TThostFtdcErrorMsgType:" << pErrorConditionalOrder->ErrorMsg << endl;
    cout << "互换单标志 TThostFtdcBoolType:" << pErrorConditionalOrder->IsSwapOrder << endl;
    cout << "营业部编号 TThostFtdcBranchIDType:" << pErrorConditionalOrder->BranchID << endl;
}

///执行宣告通知
void CTraderSpi::OnRtnExecOrder(CThostFtdcExecOrderField* pExecOrder)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pExecOrder->BrokerID << endl;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << pExecOrder->InvestorID << endl;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << pExecOrder->InstrumentID << endl;
    cout << "执行宣告引用 TThostFtdcOrderRefType:" << pExecOrder->ExecOrderRef << endl;
    cout << "用户代码 TThostFtdcUserIDType:" << pExecOrder->UserID << endl;
    cout << "数量 TThostFtdcVolumeType:" << pExecOrder->Volume << endl;
    cout << "请求编号 TThostFtdcRequestIDType:" << pExecOrder->RequestID << endl;
    cout << "业务单元 TThostFtdcBusinessUnitType:" << pExecOrder->BusinessUnit << endl;
    cout << "开平标志 TThostFtdcOffsetFlagType:" << pExecOrder->OffsetFlag << endl;
    cout << "投机套保标志 TThostFtdcHedgeFlagType:" << pExecOrder->HedgeFlag << endl;
    cout << "执行类型 TThostFtdcActionTypeType:" << pExecOrder->ActionType << endl;
    cout << "保留头寸申请的持仓方向 TThostFtdcPosiDirectionType:" << pExecOrder->PosiDirection << endl;
    cout << "期权行权后是否保留期货头寸的标记 TThostFtdcExecOrderPositionFlagType:" << pExecOrder->ReservePositionFlag << endl;
    cout << "期权行权后生成的头寸是否自动平仓 TThostFtdcExecOrderCloseFlagType:" << pExecOrder->CloseFlag << endl;
    cout << "本地执行宣告编号 TThostFtdcOrderLocalIDType:" << pExecOrder->ExecOrderLocalID << endl;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << pExecOrder->ExchangeID << endl;
    cout << "会员代码 TThostFtdcParticipantIDType:" << pExecOrder->ParticipantID << endl;
    cout << "客户代码 TThostFtdcClientIDType:" << pExecOrder->ClientID << endl;
    cout << "合约在交易所的代码 TThostFtdcExchangeInstIDType:" << pExecOrder->ExchangeInstID << endl;
    cout << "交易所交易员代码 TThostFtdcTraderIDType:" << pExecOrder->TraderID << endl;
    cout << "安装编号 TThostFtdcInstallIDType:" << pExecOrder->InstallID << endl;
    cout << "执行宣告提交状态 TThostFtdcOrderSubmitStatusType:" << pExecOrder->OrderSubmitStatus << endl;
    cout << "报单提示序号 TThostFtdcSequenceNoType:" << pExecOrder->NotifySequence << endl;
    cout << "交易日 TThostFtdcDateType:" << pExecOrder->TradingDay << endl;
    cout << "结算编号 TThostFtdcSettlementIDType:" << pExecOrder->SettlementID << endl;
    cout << "执行宣告编号 TThostFtdcExecOrderSysIDType:" << pExecOrder->ExecOrderSysID << endl;
    cout << "报单日期 TThostFtdcDateType:" << pExecOrder->InsertDate << endl;
    cout << "插入时间 TThostFtdcTimeType:" << pExecOrder->InsertTime << endl;
    cout << "撤销时间 TThostFtdcTimeType:" << pExecOrder->CancelTime << endl;
    cout << "执行结果 TThostFtdcExecResultType:" << pExecOrder->ExecResult << endl;
    cout << "结算会员编号 TThostFtdcParticipantIDType:" << pExecOrder->ClearingPartID << endl;
    cout << "序号 TThostFtdcSequenceNoType:" << pExecOrder->SequenceNo << endl;
    cout << "前置编号 TThostFtdcFrontIDType:" << pExecOrder->FrontID << endl;
    cout << "会话编号 TThostFtdcSessionIDType:" << pExecOrder->SessionID << endl;
    cout << "用户端产品信息 TThostFtdcProductInfoType:" << pExecOrder->UserProductInfo << endl;
    cout << "状态信息 TThostFtdcErrorMsgType:" << pExecOrder->StatusMsg << endl;
    cout << "操作用户代码 TThostFtdcUserIDType:" << pExecOrder->ActiveUserID << endl;
    cout << "经纪公司报单编号 TThostFtdcSequenceNoType:" << pExecOrder->BrokerExecOrderSeq << endl;
    cout << "营业部编号 TThostFtdcBranchIDType:" << pExecOrder->BranchID << endl;
}

///执行宣告录入错误回报
void CTraderSpi::OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (!IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pInputExecOrder->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pInputExecOrder->InvestorID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pInputExecOrder->InstrumentID << endl;
	cout << "执行宣告引用 TThostFtdcOrderRefType:" << pInputExecOrder->ExecOrderRef << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pInputExecOrder->UserID << endl;
	cout << "数量 TThostFtdcVolumeType:" << pInputExecOrder->Volume << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pInputExecOrder->RequestID << endl;
	cout << "业务单元 TThostFtdcBusinessUnitType:" << pInputExecOrder->BusinessUnit << endl;
	cout << "开平标志 TThostFtdcOffsetFlagType:" << pInputExecOrder->OffsetFlag << endl;
	cout << "投机套保标志 TThostFtdcHedgeFlagType:" << pInputExecOrder->HedgeFlag << endl;
	cout << "执行类型 TThostFtdcActionTypeType:" << pInputExecOrder->ActionType << endl;
	cout << "保留头寸申请的持仓方向 TThostFtdcPosiDirectionType:" << pInputExecOrder->PosiDirection << endl;
	cout << "期权行权后是否保留期货头寸的标记 TThostFtdcExecOrderPositionFlagType:" << pInputExecOrder->ReservePositionFlag << endl;
	cout << "期权行权后生成的头寸是否自动平仓 TThostFtdcExecOrderCloseFlagType:" << pInputExecOrder->CloseFlag << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pInputExecOrder->ExchangeID << endl;
    }
}

///执行宣告操作错误回报
void CTraderSpi::OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField* pExecOrderAction, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (!IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pExecOrderAction->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pExecOrderAction->InvestorID << endl;
	cout << "执行宣告操作引用 TThostFtdcOrderActionRefType:" << pExecOrderAction->ExecOrderActionRef << endl;
	cout << "执行宣告引用 TThostFtdcOrderRefType:" << pExecOrderAction->ExecOrderRef << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pExecOrderAction->RequestID << endl;
	cout << "前置编号 TThostFtdcFrontIDType:" << pExecOrderAction->FrontID << endl;
	cout << "会话编号 TThostFtdcSessionIDType:" << pExecOrderAction->SessionID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pExecOrderAction->ExchangeID << endl;
	cout << "执行宣告操作编号 TThostFtdcExecOrderSysIDType:" << pExecOrderAction->ExecOrderSysID << endl;
	cout << "操作标志 TThostFtdcActionFlagType:" << pExecOrderAction->ActionFlag << endl;
	cout << "操作日期 TThostFtdcDateType:" << pExecOrderAction->ActionDate << endl;
	cout << "操作时间 TThostFtdcTimeType:" << pExecOrderAction->ActionTime << endl;
	cout << "交易所交易员代码 TThostFtdcTraderIDType:" << pExecOrderAction->TraderID << endl;
	cout << "安装编号 TThostFtdcInstallIDType:" << pExecOrderAction->InstallID << endl;
	cout << "本地执行宣告编号 TThostFtdcOrderLocalIDType:" << pExecOrderAction->ExecOrderLocalID << endl;
	cout << "操作本地编号 TThostFtdcOrderLocalIDType:" << pExecOrderAction->ActionLocalID << endl;
	cout << "会员代码 TThostFtdcParticipantIDType:" << pExecOrderAction->ParticipantID << endl;
	cout << "客户代码 TThostFtdcClientIDType:" << pExecOrderAction->ClientID << endl;
	cout << "业务单元 TThostFtdcBusinessUnitType:" << pExecOrderAction->BusinessUnit << endl;
	cout << "报单操作状态 TThostFtdcOrderActionStatusType:" << pExecOrderAction->OrderActionStatus << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pExecOrderAction->UserID << endl;
	cout << "执行类型 TThostFtdcActionTypeType:" << pExecOrderAction->ActionType << endl;
	cout << "状态信息 TThostFtdcErrorMsgType:" << pExecOrderAction->StatusMsg << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pExecOrderAction->InstrumentID << endl;
	cout << "营业部编号 TThostFtdcBranchIDType:" << pExecOrderAction->BranchID << endl;
    }
}

///询价录入错误回报
void CTraderSpi::OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (!IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pInputForQuote->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pInputForQuote->InvestorID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pInputForQuote->InstrumentID << endl;
	cout << "询价引用 TThostFtdcOrderRefType:" << pInputForQuote->ForQuoteRef << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pInputForQuote->UserID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pInputForQuote->ExchangeID << endl;
    }
}

///报价通知
void CTraderSpi::OnRtnQuote(CThostFtdcQuoteField* pQuote)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pQuote->BrokerID << endl;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << pQuote->InvestorID << endl;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << pQuote->InstrumentID << endl;
    cout << "报价引用 TThostFtdcOrderRefType:" << pQuote->QuoteRef << endl;
    cout << "用户代码 TThostFtdcUserIDType:" << pQuote->UserID << endl;
    cout << "卖价格 TThostFtdcPriceType:" << pQuote->AskPrice << endl;
    cout << "买价格 TThostFtdcPriceType:" << pQuote->BidPrice << endl;
    cout << "卖数量 TThostFtdcVolumeType:" << pQuote->AskVolume << endl;
    cout << "买数量 TThostFtdcVolumeType:" << pQuote->BidVolume << endl;
    cout << "请求编号 TThostFtdcRequestIDType:" << pQuote->RequestID << endl;
    cout << "业务单元 TThostFtdcBusinessUnitType:" << pQuote->BusinessUnit << endl;
    cout << "卖开平标志 TThostFtdcOffsetFlagType:" << pQuote->AskOffsetFlag << endl;
    cout << "买开平标志 TThostFtdcOffsetFlagType:" << pQuote->BidOffsetFlag << endl;
    cout << "卖投机套保标志 TThostFtdcHedgeFlagType:" << pQuote->AskHedgeFlag << endl;
    cout << "买投机套保标志 TThostFtdcHedgeFlagType:" << pQuote->BidHedgeFlag << endl;
    cout << "本地报价编号 TThostFtdcOrderLocalIDType:" << pQuote->QuoteLocalID << endl;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << pQuote->ExchangeID << endl;
    cout << "会员代码 TThostFtdcParticipantIDType:" << pQuote->ParticipantID << endl;
    cout << "客户代码 TThostFtdcClientIDType:" << pQuote->ClientID << endl;
    cout << "合约在交易所的代码 TThostFtdcExchangeInstIDType:" << pQuote->ExchangeInstID << endl;
    cout << "交易所交易员代码 TThostFtdcTraderIDType:" << pQuote->TraderID << endl;
    cout << "安装编号 TThostFtdcInstallIDType:" << pQuote->InstallID << endl;
    cout << "报价提示序号 TThostFtdcSequenceNoType:" << pQuote->NotifySequence << endl;
    cout << "报价提交状态 TThostFtdcOrderSubmitStatusType:" << pQuote->OrderSubmitStatus << endl;
    cout << "交易日 TThostFtdcDateType:" << pQuote->TradingDay << endl;
    cout << "结算编号 TThostFtdcSettlementIDType:" << pQuote->SettlementID << endl;
    cout << "报价编号 TThostFtdcOrderSysIDType:" << pQuote->QuoteSysID << endl;
    cout << "报单日期 TThostFtdcDateType:" << pQuote->InsertDate << endl;
    cout << "插入时间 TThostFtdcTimeType:" << pQuote->InsertTime << endl;
    cout << "撤销时间 TThostFtdcTimeType:" << pQuote->CancelTime << endl;
    cout << "报价状态 TThostFtdcOrderStatusType:" << pQuote->QuoteStatus << endl;
    cout << "结算会员编号 TThostFtdcParticipantIDType:" << pQuote->ClearingPartID << endl;
    cout << "序号 TThostFtdcSequenceNoType:" << pQuote->SequenceNo << endl;
    cout << "卖方报单编号 TThostFtdcOrderSysIDType:" << pQuote->AskOrderSysID << endl;
    cout << "买方报单编号 TThostFtdcOrderSysIDType:" << pQuote->BidOrderSysID << endl;
    cout << "前置编号 TThostFtdcFrontIDType:" << pQuote->FrontID << endl;
    cout << "会话编号 TThostFtdcSessionIDType:" << pQuote->SessionID << endl;
    cout << "用户端产品信息 TThostFtdcProductInfoType:" << pQuote->UserProductInfo << endl;
    cout << "状态信息 TThostFtdcErrorMsgType:" << pQuote->StatusMsg << endl;
    cout << "操作用户代码 TThostFtdcUserIDType:" << pQuote->ActiveUserID << endl;
    cout << "经纪公司报价编号 TThostFtdcSequenceNoType:" << pQuote->BrokerQuoteSeq << endl;
    cout << "衍生卖报单引用 TThostFtdcOrderRefType:" << pQuote->AskOrderRef << endl;
    cout << "衍生买报单引用 TThostFtdcOrderRefType:" << pQuote->BidOrderRef << endl;
    cout << "应价编号 TThostFtdcOrderSysIDType:" << pQuote->ForQuoteSysID << endl;
    cout << "营业部编号 TThostFtdcBranchIDType:" << pQuote->BranchID << endl;
}

///报价录入错误回报
void CTraderSpi::OnErrRtnQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (!IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pInputQuote->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pInputQuote->InvestorID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pInputQuote->InstrumentID << endl;
	cout << "报价引用 TThostFtdcOrderRefType:" << pInputQuote->QuoteRef << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pInputQuote->UserID << endl;
	cout << "卖价格 TThostFtdcPriceType:" << pInputQuote->AskPrice << endl;
	cout << "买价格 TThostFtdcPriceType:" << pInputQuote->BidPrice << endl;
	cout << "卖数量 TThostFtdcVolumeType:" << pInputQuote->AskVolume << endl;
	cout << "买数量 TThostFtdcVolumeType:" << pInputQuote->BidVolume << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pInputQuote->RequestID << endl;
	cout << "业务单元 TThostFtdcBusinessUnitType:" << pInputQuote->BusinessUnit << endl;
	cout << "卖开平标志 TThostFtdcOffsetFlagType:" << pInputQuote->AskOffsetFlag << endl;
	cout << "买开平标志 TThostFtdcOffsetFlagType:" << pInputQuote->BidOffsetFlag << endl;
	cout << "卖投机套保标志 TThostFtdcHedgeFlagType:" << pInputQuote->AskHedgeFlag << endl;
	cout << "买投机套保标志 TThostFtdcHedgeFlagType:" << pInputQuote->BidHedgeFlag << endl;
	cout << "衍生卖报单引用 TThostFtdcOrderRefType:" << pInputQuote->AskOrderRef << endl;
	cout << "衍生买报单引用 TThostFtdcOrderRefType:" << pInputQuote->BidOrderRef << endl;
	cout << "应价编号 TThostFtdcOrderSysIDType:" << pInputQuote->ForQuoteSysID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pInputQuote->ExchangeID << endl;
    }
}

///报价操作错误回报
void CTraderSpi::OnErrRtnQuoteAction(CThostFtdcQuoteActionField* pQuoteAction, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (!IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pQuoteAction->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pQuoteAction->InvestorID << endl;
	cout << "报价操作引用 TThostFtdcOrderActionRefType:" << pQuoteAction->QuoteActionRef << endl;
	cout << "报价引用 TThostFtdcOrderRefType:" << pQuoteAction->QuoteRef << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pQuoteAction->RequestID << endl;
	cout << "前置编号 TThostFtdcFrontIDType:" << pQuoteAction->FrontID << endl;
	cout << "会话编号 TThostFtdcSessionIDType:" << pQuoteAction->SessionID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pQuoteAction->ExchangeID << endl;
	cout << "报价操作编号 TThostFtdcOrderSysIDType:" << pQuoteAction->QuoteSysID << endl;
	cout << "操作标志 TThostFtdcActionFlagType:" << pQuoteAction->ActionFlag << endl;
	cout << "操作日期 TThostFtdcDateType:" << pQuoteAction->ActionDate << endl;
	cout << "操作时间 TThostFtdcTimeType:" << pQuoteAction->ActionTime << endl;
	cout << "交易所交易员代码 TThostFtdcTraderIDType:" << pQuoteAction->TraderID << endl;
	cout << "安装编号 TThostFtdcInstallIDType:" << pQuoteAction->InstallID << endl;
	cout << "本地报价编号 TThostFtdcOrderLocalIDType:" << pQuoteAction->QuoteLocalID << endl;
	cout << "操作本地编号 TThostFtdcOrderLocalIDType:" << pQuoteAction->ActionLocalID << endl;
	cout << "会员代码 TThostFtdcParticipantIDType:" << pQuoteAction->ParticipantID << endl;
	cout << "客户代码 TThostFtdcClientIDType:" << pQuoteAction->ClientID << endl;
	cout << "业务单元 TThostFtdcBusinessUnitType:" << pQuoteAction->BusinessUnit << endl;
	cout << "报单操作状态 TThostFtdcOrderActionStatusType:" << pQuoteAction->OrderActionStatus << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pQuoteAction->UserID << endl;
	cout << "状态信息 TThostFtdcErrorMsgType:" << pQuoteAction->StatusMsg << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pQuoteAction->InstrumentID << endl;
	cout << "营业部编号 TThostFtdcBranchIDType:" << pQuoteAction->BranchID << endl;
    }
}

///询价通知
void CTraderSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "交易日 TThostFtdcDateType:" << pForQuoteRsp->TradingDay << endl;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << pForQuoteRsp->InstrumentID << endl;
    cout << "询价编号 TThostFtdcOrderSysIDType:" << pForQuoteRsp->ForQuoteSysID << endl;
    cout << "询价时间 TThostFtdcTimeType:" << pForQuoteRsp->ForQuoteTime << endl;
    cout << "业务日期 TThostFtdcDateType:" << pForQuoteRsp->ActionDay << endl;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << pForQuoteRsp->ExchangeID << endl;
}

///保证金监控中心用户令牌
void CTraderSpi::OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField* pCFMMCTradingAccountToken)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pCFMMCTradingAccountToken->BrokerID << endl;
    cout << "经纪公司统一编码 TThostFtdcParticipantIDType:" << pCFMMCTradingAccountToken->ParticipantID << endl;
    cout << "投资者帐号 TThostFtdcAccountIDType:" << pCFMMCTradingAccountToken->AccountID << endl;
    cout << "密钥编号 TThostFtdcSequenceNoType:" << pCFMMCTradingAccountToken->KeyID << endl;
    cout << "动态令牌 TThostFtdcCFMMCTokenType:" << pCFMMCTradingAccountToken->Token << endl;
}

///锁定通知
void CTraderSpi::OnRtnLock(CThostFtdcLockField* pLock)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pLock->BrokerID << endl;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << pLock->InvestorID << endl;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << pLock->InstrumentID << endl;
    cout << "锁定引用 TThostFtdcOrderRefType:" << pLock->LockRef << endl;
    cout << "用户代码 TThostFtdcUserIDType:" << pLock->UserID << endl;
    cout << "数量 TThostFtdcVolumeType:" << pLock->Volume << endl;
    cout << "请求编号 TThostFtdcRequestIDType:" << pLock->RequestID << endl;
    cout << "业务单元 TThostFtdcBusinessUnitType:" << pLock->BusinessUnit << endl;
    cout << "锁定类型 TThostFtdcLockTypeType:" << pLock->LockType << endl;
    cout << "本地锁定编号 TThostFtdcOrderLocalIDType:" << pLock->LockLocalID << endl;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << pLock->ExchangeID << endl;
    cout << "会员代码 TThostFtdcParticipantIDType:" << pLock->ParticipantID << endl;
    cout << "客户代码 TThostFtdcClientIDType:" << pLock->ClientID << endl;
    cout << "合约在交易所的代码 TThostFtdcExchangeInstIDType:" << pLock->ExchangeInstID << endl;
    cout << "交易所交易员代码 TThostFtdcTraderIDType:" << pLock->TraderID << endl;
    cout << "安装编号 TThostFtdcInstallIDType:" << pLock->InstallID << endl;
    cout << "执行宣告提交状态 TThostFtdcOrderSubmitStatusType:" << pLock->OrderSubmitStatus << endl;
    cout << "报单提示序号 TThostFtdcSequenceNoType:" << pLock->NotifySequence << endl;
    cout << "交易日 TThostFtdcDateType:" << pLock->TradingDay << endl;
    cout << "结算编号 TThostFtdcSettlementIDType:" << pLock->SettlementID << endl;
    cout << "锁定编号 TThostFtdcOrderSysIDType:" << pLock->LockSysID << endl;
    cout << "报单日期 TThostFtdcDateType:" << pLock->InsertDate << endl;
    cout << "插入时间 TThostFtdcTimeType:" << pLock->InsertTime << endl;
    cout << "撤销时间 TThostFtdcTimeType:" << pLock->CancelTime << endl;
    cout << "锁定状态 TThostFtdcOrderActionStatusType:" << pLock->LockStatus << endl;
    cout << "结算会员编号 TThostFtdcParticipantIDType:" << pLock->ClearingPartID << endl;
    cout << "序号 TThostFtdcSequenceNoType:" << pLock->SequenceNo << endl;
    cout << "前置编号 TThostFtdcFrontIDType:" << pLock->FrontID << endl;
    cout << "会话编号 TThostFtdcSessionIDType:" << pLock->SessionID << endl;
    cout << "用户端产品信息 TThostFtdcProductInfoType:" << pLock->UserProductInfo << endl;
    cout << "状态信息 TThostFtdcErrorMsgType:" << pLock->StatusMsg << endl;
    cout << "操作用户代码 TThostFtdcUserIDType:" << pLock->ActiveUserID << endl;
    cout << "经纪公司报单编号 TThostFtdcSequenceNoType:" << pLock->BrokerLockSeq << endl;
    cout << "营业部编号 TThostFtdcBranchIDType:" << pLock->BranchID << endl;
}

///锁定错误通知
void CTraderSpi::OnErrRtnLockInsert(CThostFtdcInputLockField* pInputLock, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pInputLock->BrokerID << endl;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << pInputLock->InvestorID << endl;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << pInputLock->InstrumentID << endl;
    cout << "锁定引用 TThostFtdcOrderRefType:" << pInputLock->LockRef << endl;
    cout << "用户代码 TThostFtdcUserIDType:" << pInputLock->UserID << endl;
    cout << "数量 TThostFtdcVolumeType:" << pInputLock->Volume << endl;
    cout << "请求编号 TThostFtdcRequestIDType:" << pInputLock->RequestID << endl;
    cout << "业务单元 TThostFtdcBusinessUnitType:" << pInputLock->BusinessUnit << endl;
    cout << "锁定类型 TThostFtdcLockTypeType:" << pInputLock->LockType << endl;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << pInputLock->ExchangeID << endl;
}

///申请组合通知
void CTraderSpi::OnRtnCombAction(CThostFtdcCombActionField* pCombAction)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pCombAction->BrokerID << endl;
    cout << "投资者代码 TThostFtdcInvestorIDType:" << pCombAction->InvestorID << endl;
    cout << "合约代码 TThostFtdcInstrumentIDType:" << pCombAction->InstrumentID << endl;
    cout << "组合引用 TThostFtdcOrderRefType:" << pCombAction->CombActionRef << endl;
    cout << "用户代码 TThostFtdcUserIDType:" << pCombAction->UserID << endl;
    cout << "买卖方向 TThostFtdcDirectionType:" << pCombAction->Direction << endl;
    cout << "数量 TThostFtdcVolumeType:" << pCombAction->Volume << endl;
    cout << "组合指令方向 TThostFtdcCombDirectionType:" << pCombAction->CombDirection << endl;
    cout << "投机套保标志 TThostFtdcHedgeFlagType:" << pCombAction->HedgeFlag << endl;
    cout << "本地申请组合编号 TThostFtdcOrderLocalIDType:" << pCombAction->ActionLocalID << endl;
    cout << "交易所代码 TThostFtdcExchangeIDType:" << pCombAction->ExchangeID << endl;
    cout << "会员代码 TThostFtdcParticipantIDType:" << pCombAction->ParticipantID << endl;
    cout << "客户代码 TThostFtdcClientIDType:" << pCombAction->ClientID << endl;
    cout << "合约在交易所的代码 TThostFtdcExchangeInstIDType:" << pCombAction->ExchangeInstID << endl;
    cout << "交易所交易员代码 TThostFtdcTraderIDType:" << pCombAction->TraderID << endl;
    cout << "安装编号 TThostFtdcInstallIDType:" << pCombAction->InstallID << endl;
    cout << "组合状态 TThostFtdcOrderActionStatusType:" << pCombAction->ActionStatus << endl;
    cout << "报单提示序号 TThostFtdcSequenceNoType:" << pCombAction->NotifySequence << endl;
    cout << "交易日 TThostFtdcDateType:" << pCombAction->TradingDay << endl;
    cout << "结算编号 TThostFtdcSettlementIDType:" << pCombAction->SettlementID << endl;
    cout << "序号 TThostFtdcSequenceNoType:" << pCombAction->SequenceNo << endl;
    cout << "前置编号 TThostFtdcFrontIDType:" << pCombAction->FrontID << endl;
    cout << "会话编号 TThostFtdcSessionIDType:" << pCombAction->SessionID << endl;
    cout << "用户端产品信息 TThostFtdcProductInfoType:" << pCombAction->UserProductInfo << endl;
    cout << "状态信息 TThostFtdcErrorMsgType:" << pCombAction->StatusMsg << endl;
}

///申请组合录入错误回报
void CTraderSpi::OnErrRtnCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (!IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pInputCombAction->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pInputCombAction->InvestorID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pInputCombAction->InstrumentID << endl;
	cout << "组合引用 TThostFtdcOrderRefType:" << pInputCombAction->CombActionRef << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pInputCombAction->UserID << endl;
	cout << "买卖方向 TThostFtdcDirectionType:" << pInputCombAction->Direction << endl;
	cout << "数量 TThostFtdcVolumeType:" << pInputCombAction->Volume << endl;
	cout << "组合指令方向 TThostFtdcCombDirectionType:" << pInputCombAction->CombDirection << endl;
	cout << "投机套保标志 TThostFtdcHedgeFlagType:" << pInputCombAction->HedgeFlag << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pInputCombAction->ExchangeID << endl;
    }
}

///请求查询签约银行响应
void CTraderSpi::OnRspQryContractBank(CThostFtdcContractBankField* pContractBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pContractBank->BrokerID << endl;
	cout << "银行代码 TThostFtdcBankIDType:" << pContractBank->BankID << endl;
	cout << "银行分中心代码 TThostFtdcBankBrchIDType:" << pContractBank->BankBrchID << endl;
	cout << "银行名称 TThostFtdcBankNameType:" << pContractBank->BankName << endl;
    }
}

///请求查询预埋单响应
void CTraderSpi::OnRspQryParkedOrder(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pParkedOrder->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pParkedOrder->InvestorID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pParkedOrder->InstrumentID << endl;
	cout << "报单引用 TThostFtdcOrderRefType:" << pParkedOrder->OrderRef << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pParkedOrder->UserID << endl;
	cout << "报单价格条件 TThostFtdcOrderPriceTypeType:" << pParkedOrder->OrderPriceType << endl;
	cout << "买卖方向 TThostFtdcDirectionType:" << pParkedOrder->Direction << endl;
	cout << "组合开平标志 TThostFtdcCombOffsetFlagType:" << pParkedOrder->CombOffsetFlag << endl;
	cout << "组合投机套保标志 TThostFtdcCombHedgeFlagType:" << pParkedOrder->CombHedgeFlag << endl;
	cout << "价格 TThostFtdcPriceType:" << pParkedOrder->LimitPrice << endl;
	cout << "数量 TThostFtdcVolumeType:" << pParkedOrder->VolumeTotalOriginal << endl;
	cout << "有效期类型 TThostFtdcTimeConditionType:" << pParkedOrder->TimeCondition << endl;
	cout << "日期 TThostFtdcDateType:" << pParkedOrder->GTDDate << endl;
	cout << "成交量类型 TThostFtdcVolumeConditionType:" << pParkedOrder->VolumeCondition << endl;
	cout << "最小成交量 TThostFtdcVolumeType:" << pParkedOrder->MinVolume << endl;
	cout << "触发条件 TThostFtdcContingentConditionType:" << pParkedOrder->ContingentCondition << endl;
	cout << "止损价 TThostFtdcPriceType:" << pParkedOrder->StopPrice << endl;
	cout << "强平原因 TThostFtdcForceCloseReasonType:" << pParkedOrder->ForceCloseReason << endl;
	cout << "自动挂起标志 TThostFtdcBoolType:" << pParkedOrder->IsAutoSuspend << endl;
	cout << "业务单元 TThostFtdcBusinessUnitType:" << pParkedOrder->BusinessUnit << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pParkedOrder->RequestID << endl;
	cout << "用户强评标志 TThostFtdcBoolType:" << pParkedOrder->UserForceClose << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pParkedOrder->ExchangeID << endl;
	cout << "预埋报单编号 TThostFtdcParkedOrderIDType:" << pParkedOrder->ParkedOrderID << endl;
	cout << "用户类型 TThostFtdcUserTypeType:" << pParkedOrder->UserType << endl;
	cout << "预埋单状态 TThostFtdcParkedOrderStatusType:" << pParkedOrder->Status << endl;
	cout << "错误代码 TThostFtdcErrorIDType:" << pParkedOrder->ErrorID << endl;
	cout << "错误信息 TThostFtdcErrorMsgType:" << pParkedOrder->ErrorMsg << endl;
	cout << "互换单标志 TThostFtdcBoolType:" << pParkedOrder->IsSwapOrder << endl;
    }
}

///请求查询预埋撤单响应
void CTraderSpi::OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pParkedOrderAction->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pParkedOrderAction->InvestorID << endl;
	cout << "报单操作引用 TThostFtdcOrderActionRefType:" << pParkedOrderAction->OrderActionRef << endl;
	cout << "报单引用 TThostFtdcOrderRefType:" << pParkedOrderAction->OrderRef << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pParkedOrderAction->RequestID << endl;
	cout << "前置编号 TThostFtdcFrontIDType:" << pParkedOrderAction->FrontID << endl;
	cout << "会话编号 TThostFtdcSessionIDType:" << pParkedOrderAction->SessionID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pParkedOrderAction->ExchangeID << endl;
	cout << "报单编号 TThostFtdcOrderSysIDType:" << pParkedOrderAction->OrderSysID << endl;
	cout << "操作标志 TThostFtdcActionFlagType:" << pParkedOrderAction->ActionFlag << endl;
	cout << "价格 TThostFtdcPriceType:" << pParkedOrderAction->LimitPrice << endl;
	cout << "数量变化 TThostFtdcVolumeType:" << pParkedOrderAction->VolumeChange << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pParkedOrderAction->UserID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pParkedOrderAction->InstrumentID << endl;
	cout << "预埋撤单单编号 TThostFtdcParkedOrderActionIDType:" << pParkedOrderAction->ParkedOrderActionID << endl;
	cout << "用户类型 TThostFtdcUserTypeType:" << pParkedOrderAction->UserType << endl;
	cout << "预埋撤单状态 TThostFtdcParkedOrderStatusType:" << pParkedOrderAction->Status << endl;
	cout << "错误代码 TThostFtdcErrorIDType:" << pParkedOrderAction->ErrorID << endl;
	cout << "错误信息 TThostFtdcErrorMsgType:" << pParkedOrderAction->ErrorMsg << endl;
    }
}

///请求查询交易通知响应
void CTraderSpi::OnRspQryTradingNotice(CThostFtdcTradingNoticeField* pTradingNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pTradingNotice->BrokerID << endl;
	cout << "投资者范围 TThostFtdcInvestorRangeType:" << pTradingNotice->InvestorRange << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pTradingNotice->InvestorID << endl;
	cout << "序列系列号 TThostFtdcSequenceSeriesType:" << pTradingNotice->SequenceSeries << endl;
	cout << "用户代码 TThostFtdcUserIDType:" << pTradingNotice->UserID << endl;
	cout << "发送时间 TThostFtdcTimeType:" << pTradingNotice->SendTime << endl;
	cout << "序列号 TThostFtdcSequenceNoType:" << pTradingNotice->SequenceNo << endl;
	cout << "消息正文 TThostFtdcContentType:" << pTradingNotice->FieldContent << endl;
    }
}

///请求查询经纪公司交易参数响应
void CTraderSpi::OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField* pBrokerTradingParams, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pBrokerTradingParams->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pBrokerTradingParams->InvestorID << endl;
	cout << "保证金价格类型 TThostFtdcMarginPriceTypeType:" << pBrokerTradingParams->MarginPriceType << endl;
	cout << "盈亏算法 TThostFtdcAlgorithmType:" << pBrokerTradingParams->Algorithm << endl;
	cout << "可用是否包含平仓盈利 TThostFtdcIncludeCloseProfitType:" << pBrokerTradingParams->AvailIncludeCloseProfit << endl;
	cout << "币种代码 TThostFtdcCurrencyIDType:" << pBrokerTradingParams->CurrencyID << endl;
	cout << "期权权利金价格类型 TThostFtdcOptionRoyaltyPriceTypeType:" << pBrokerTradingParams->OptionRoyaltyPriceType << endl;
    }
}

///请求查询经纪公司交易算法响应
void CTraderSpi::OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField* pBrokerTradingAlgos, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pBrokerTradingAlgos->BrokerID << endl;
	cout << "交易所代码 TThostFtdcExchangeIDType:" << pBrokerTradingAlgos->ExchangeID << endl;
	cout << "合约代码 TThostFtdcInstrumentIDType:" << pBrokerTradingAlgos->InstrumentID << endl;
	cout << "持仓处理算法编号 TThostFtdcHandlePositionAlgoIDType:" << pBrokerTradingAlgos->HandlePositionAlgoID << endl;
	cout << "寻找保证金率算法编号 TThostFtdcFindMarginRateAlgoIDType:" << pBrokerTradingAlgos->FindMarginRateAlgoID << endl;
	cout << "资金处理算法编号 TThostFtdcHandleTradingAccountAlgoIDType:" << pBrokerTradingAlgos->HandleTradingAccountAlgoID << endl;
    }
}

///请求查询监控中心用户令牌
void CTraderSpi::OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "经纪公司代码 TThostFtdcBrokerIDType:" << pQueryCFMMCTradingAccountToken->BrokerID << endl;
	cout << "投资者代码 TThostFtdcInvestorIDType:" << pQueryCFMMCTradingAccountToken->InvestorID << endl;
    }
}

///银行发起银行资金转期货通知
void CTraderSpi::OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField* pRspTransfer)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "业务功能码 TThostFtdcTradeCodeType:" << pRspTransfer->TradeCode << endl;
    cout << "银行代码 TThostFtdcBankIDType:" << pRspTransfer->BankID << endl;
    cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << pRspTransfer->BankBranchID << endl;
    cout << "期商代码 TThostFtdcBrokerIDType:" << pRspTransfer->BrokerID << endl;
    cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << pRspTransfer->BrokerBranchID << endl;
    cout << "交易日期 TThostFtdcTradeDateType:" << pRspTransfer->TradeDate << endl;
    cout << "交易时间 TThostFtdcTradeTimeType:" << pRspTransfer->TradeTime << endl;
    cout << "银行流水号 TThostFtdcBankSerialType:" << pRspTransfer->BankSerial << endl;
    cout << "交易系统日期 TThostFtdcTradeDateType:" << pRspTransfer->TradingDay << endl;
    cout << "银期平台消息流水号 TThostFtdcSerialType:" << pRspTransfer->PlateSerial << endl;
    cout << "最后分片标志 TThostFtdcLastFragmentType:" << pRspTransfer->LastFragment << endl;
    cout << "会话号 TThostFtdcSessionIDType:" << pRspTransfer->SessionID << endl;
    cout << "客户姓名 TThostFtdcIndividualNameType:" << pRspTransfer->CustomerName << endl;
    cout << "证件类型 TThostFtdcIdCardTypeType:" << pRspTransfer->IdCardType << endl;
    cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pRspTransfer->IdentifiedCardNo << endl;
    cout << "客户类型 TThostFtdcCustTypeType:" << pRspTransfer->CustType << endl;
    cout << "银行帐号 TThostFtdcBankAccountType:" << pRspTransfer->BankAccount << endl;
    cout << "银行密码 TThostFtdcPasswordType:" << pRspTransfer->BankPassWord << endl;
    cout << "投资者帐号 TThostFtdcAccountIDType:" << pRspTransfer->AccountID << endl;
    cout << "期货密码 TThostFtdcPasswordType:" << pRspTransfer->Password << endl;
    cout << "安装编号 TThostFtdcInstallIDType:" << pRspTransfer->InstallID << endl;
    cout << "期货公司流水号 TThostFtdcFutureSerialType:" << pRspTransfer->FutureSerial << endl;
    cout << "用户标识 TThostFtdcUserIDType:" << pRspTransfer->UserID << endl;
    cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << pRspTransfer->VerifyCertNoFlag << endl;
    cout << "币种代码 TThostFtdcCurrencyIDType:" << pRspTransfer->CurrencyID << endl;
    cout << "转帐金额 TThostFtdcTradeAmountType:" << pRspTransfer->TradeAmount << endl;
    cout << "期货可取金额 TThostFtdcTradeAmountType:" << pRspTransfer->FutureFetchAmount << endl;
    cout << "费用支付标志 TThostFtdcFeePayFlagType:" << pRspTransfer->FeePayFlag << endl;
    cout << "应收客户费用 TThostFtdcCustFeeType:" << pRspTransfer->CustFee << endl;
    cout << "应收期货公司费用 TThostFtdcFutureFeeType:" << pRspTransfer->BrokerFee << endl;
    cout << "发送方给接收方的消息 TThostFtdcAddInfoType:" << pRspTransfer->Message << endl;
    cout << "摘要 TThostFtdcDigestType:" << pRspTransfer->Digest << endl;
    cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << pRspTransfer->BankAccType << endl;
    cout << "渠道标志 TThostFtdcDeviceIDType:" << pRspTransfer->DeviceID << endl;
    cout << "期货单位帐号类型 TThostFtdcBankAccTypeType:" << pRspTransfer->BankSecuAccType << endl;
    cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << pRspTransfer->BrokerIDByBank << endl;
    cout << "期货单位帐号 TThostFtdcBankAccountType:" << pRspTransfer->BankSecuAcc << endl;
    cout << "银行密码标志 TThostFtdcPwdFlagType:" << pRspTransfer->BankPwdFlag << endl;
    cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << pRspTransfer->SecuPwdFlag << endl;
    cout << "交易柜员 TThostFtdcOperNoType:" << pRspTransfer->OperNo << endl;
    cout << "请求编号 TThostFtdcRequestIDType:" << pRspTransfer->RequestID << endl;
    // cout << "交易ID:" << pRspTransfer->TThostFtdcTIDType << endlTID;
    cout << "转账交易状态 TThostFtdcTransferStatusType:" << pRspTransfer->TransferStatus << endl;
    cout << "错误代码 TThostFtdcErrorIDType:" << pRspTransfer->ErrorID << endl;
    cout << "错误信息 TThostFtdcErrorMsgType:" << pRspTransfer->ErrorMsg << endl;
}

///银行发起期货资金转银行通知
void CTraderSpi::OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField* pRspTransfer)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "业务功能码 TThostFtdcTradeCodeType:" << pRspTransfer->TradeCode << endl;
    cout << "银行代码 TThostFtdcBankIDType:" << pRspTransfer->BankID << endl;
    cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << pRspTransfer->BankBranchID << endl;
    cout << "期商代码 TThostFtdcBrokerIDType:" << pRspTransfer->BrokerID << endl;
    cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << pRspTransfer->BrokerBranchID << endl;
    cout << "交易日期 TThostFtdcTradeDateType:" << pRspTransfer->TradeDate << endl;
    cout << "交易时间 TThostFtdcTradeTimeType:" << pRspTransfer->TradeTime << endl;
    cout << "银行流水号 TThostFtdcBankSerialType:" << pRspTransfer->BankSerial << endl;
    cout << "交易系统日期 TThostFtdcTradeDateType:" << pRspTransfer->TradingDay << endl;
    cout << "银期平台消息流水号 TThostFtdcSerialType:" << pRspTransfer->PlateSerial << endl;
    cout << "最后分片标志 TThostFtdcLastFragmentType:" << pRspTransfer->LastFragment << endl;
    cout << "会话号 TThostFtdcSessionIDType:" << pRspTransfer->SessionID << endl;
    cout << "客户姓名 TThostFtdcIndividualNameType:" << pRspTransfer->CustomerName << endl;
    cout << "证件类型 TThostFtdcIdCardTypeType:" << pRspTransfer->IdCardType << endl;
    cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pRspTransfer->IdentifiedCardNo << endl;
    cout << "客户类型 TThostFtdcCustTypeType:" << pRspTransfer->CustType << endl;
    cout << "银行帐号 TThostFtdcBankAccountType:" << pRspTransfer->BankAccount << endl;
    cout << "银行密码 TThostFtdcPasswordType:" << pRspTransfer->BankPassWord << endl;
    cout << "投资者帐号 TThostFtdcAccountIDType:" << pRspTransfer->AccountID << endl;
    cout << "期货密码 TThostFtdcPasswordType:" << pRspTransfer->Password << endl;
    cout << "安装编号 TThostFtdcInstallIDType:" << pRspTransfer->InstallID << endl;
    cout << "期货公司流水号 TThostFtdcFutureSerialType:" << pRspTransfer->FutureSerial << endl;
    cout << "用户标识 TThostFtdcUserIDType:" << pRspTransfer->UserID << endl;
    cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << pRspTransfer->VerifyCertNoFlag << endl;
    cout << "币种代码 TThostFtdcCurrencyIDType:" << pRspTransfer->CurrencyID << endl;
    cout << "转帐金额 TThostFtdcTradeAmountType:" << pRspTransfer->TradeAmount << endl;
    cout << "期货可取金额 TThostFtdcTradeAmountType:" << pRspTransfer->FutureFetchAmount << endl;
    cout << "费用支付标志 TThostFtdcFeePayFlagType:" << pRspTransfer->FeePayFlag << endl;
    cout << "应收客户费用 TThostFtdcCustFeeType:" << pRspTransfer->CustFee << endl;
    cout << "应收期货公司费用 TThostFtdcFutureFeeType:" << pRspTransfer->BrokerFee << endl;
    cout << "发送方给接收方的消息 TThostFtdcAddInfoType:" << pRspTransfer->Message << endl;
    cout << "摘要 TThostFtdcDigestType:" << pRspTransfer->Digest << endl;
    cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << pRspTransfer->BankAccType << endl;
    cout << "渠道标志 TThostFtdcDeviceIDType:" << pRspTransfer->DeviceID << endl;
    cout << "期货单位帐号类型 TThostFtdcBankAccTypeType:" << pRspTransfer->BankSecuAccType << endl;
    cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << pRspTransfer->BrokerIDByBank << endl;
    cout << "期货单位帐号 TThostFtdcBankAccountType:" << pRspTransfer->BankSecuAcc << endl;
    cout << "银行密码标志 TThostFtdcPwdFlagType:" << pRspTransfer->BankPwdFlag << endl;
    cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << pRspTransfer->SecuPwdFlag << endl;
    cout << "交易柜员 TThostFtdcOperNoType:" << pRspTransfer->OperNo << endl;
    cout << "请求编号 TThostFtdcRequestIDType:" << pRspTransfer->RequestID << endl;
    // cout << "交易ID:" << pRspTransfer->TThostFtdcTIDType << endlTID;
    cout << "转账交易状态 TThostFtdcTransferStatusType:" << pRspTransfer->TransferStatus << endl;
    cout << "错误代码 TThostFtdcErrorIDType:" << pRspTransfer->ErrorID << endl;
    cout << "错误信息 TThostFtdcErrorMsgType:" << pRspTransfer->ErrorMsg << endl;
}

///银行发起冲正银行转期货通知
void CTraderSpi::OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField* pRspRepeal)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "冲正时间间隔 TThostFtdcRepealTimeIntervalType:" << pRspRepeal->RepealTimeInterval << endl;
    cout << "已经冲正次数 TThostFtdcRepealedTimesType:" << pRspRepeal->RepealedTimes << endl;
    cout << "银行冲正标志 TThostFtdcBankRepealFlagType:" << pRspRepeal->BankRepealFlag << endl;
    cout << "期商冲正标志 TThostFtdcBrokerRepealFlagType:" << pRspRepeal->BrokerRepealFlag << endl;
    cout << "被冲正平台流水号 TThostFtdcPlateSerialType:" << pRspRepeal->PlateRepealSerial << endl;
    cout << "被冲正银行流水号 TThostFtdcBankSerialType:" << pRspRepeal->BankRepealSerial << endl;
    cout << "被冲正期货流水号 TThostFtdcFutureSerialType:" << pRspRepeal->FutureRepealSerial << endl;
    cout << "业务功能码 TThostFtdcTradeCodeType:" << pRspRepeal->TradeCode << endl;
    cout << "银行代码 TThostFtdcBankIDType:" << pRspRepeal->BankID << endl;
    cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << pRspRepeal->BankBranchID << endl;
    cout << "期商代码 TThostFtdcBrokerIDType:" << pRspRepeal->BrokerID << endl;
    cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << pRspRepeal->BrokerBranchID << endl;
    cout << "交易日期 TThostFtdcTradeDateType:" << pRspRepeal->TradeDate << endl;
    cout << "交易时间 TThostFtdcTradeTimeType:" << pRspRepeal->TradeTime << endl;
    cout << "银行流水号 TThostFtdcBankSerialType:" << pRspRepeal->BankSerial << endl;
    cout << "交易系统日期 TThostFtdcTradeDateType:" << pRspRepeal->TradingDay << endl;
    cout << "银期平台消息流水号 TThostFtdcSerialType:" << pRspRepeal->PlateSerial << endl;
    cout << "最后分片标志 TThostFtdcLastFragmentType:" << pRspRepeal->LastFragment << endl;
    cout << "会话号 TThostFtdcSessionIDType:" << pRspRepeal->SessionID << endl;
    cout << "客户姓名 TThostFtdcIndividualNameType:" << pRspRepeal->CustomerName << endl;
    cout << "证件类型 TThostFtdcIdCardTypeType:" << pRspRepeal->IdCardType << endl;
    cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pRspRepeal->IdentifiedCardNo << endl;
    cout << "客户类型 TThostFtdcCustTypeType:" << pRspRepeal->CustType << endl;
    cout << "银行帐号 TThostFtdcBankAccountType:" << pRspRepeal->BankAccount << endl;
    cout << "银行密码 TThostFtdcPasswordType:" << pRspRepeal->BankPassWord << endl;
    cout << "投资者帐号 TThostFtdcAccountIDType:" << pRspRepeal->AccountID << endl;
    cout << "期货密码 TThostFtdcPasswordType:" << pRspRepeal->Password << endl;
    cout << "安装编号 TThostFtdcInstallIDType:" << pRspRepeal->InstallID << endl;
    cout << "期货公司流水号 TThostFtdcFutureSerialType:" << pRspRepeal->FutureSerial << endl;
    cout << "用户标识 TThostFtdcUserIDType:" << pRspRepeal->UserID << endl;
    cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << pRspRepeal->VerifyCertNoFlag << endl;
    cout << "币种代码 TThostFtdcCurrencyIDType:" << pRspRepeal->CurrencyID << endl;
    cout << "转帐金额 TThostFtdcTradeAmountType:" << pRspRepeal->TradeAmount << endl;
    cout << "期货可取金额 TThostFtdcTradeAmountType:" << pRspRepeal->FutureFetchAmount << endl;
    cout << "费用支付标志 TThostFtdcFeePayFlagType:" << pRspRepeal->FeePayFlag << endl;
    cout << "应收客户费用 TThostFtdcCustFeeType:" << pRspRepeal->CustFee << endl;
    cout << "应收期货公司费用 TThostFtdcFutureFeeType:" << pRspRepeal->BrokerFee << endl;
    cout << "发送方给接收方的消息 TThostFtdcAddInfoType:" << pRspRepeal->Message << endl;
    cout << "摘要 TThostFtdcDigestType:" << pRspRepeal->Digest << endl;
    cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << pRspRepeal->BankAccType << endl;
    cout << "渠道标志 TThostFtdcDeviceIDType:" << pRspRepeal->DeviceID << endl;
    cout << "期货单位帐号类型 TThostFtdcBankAccTypeType:" << pRspRepeal->BankSecuAccType << endl;
    cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << pRspRepeal->BrokerIDByBank << endl;
    cout << "期货单位帐号 TThostFtdcBankAccountType:" << pRspRepeal->BankSecuAcc << endl;
    cout << "银行密码标志 TThostFtdcPwdFlagType:" << pRspRepeal->BankPwdFlag << endl;
    cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << pRspRepeal->SecuPwdFlag << endl;
    cout << "交易柜员 TThostFtdcOperNoType:" << pRspRepeal->OperNo << endl;
    cout << "请求编号 TThostFtdcRequestIDType:" << pRspRepeal->RequestID << endl;
    // cout << "交易ID:" << pRspRepeal->TThostFtdcTIDType << endlTID;
    cout << "转账交易状态 TThostFtdcTransferStatusType:" << pRspRepeal->TransferStatus << endl;
    cout << "错误代码 TThostFtdcErrorIDType:" << pRspRepeal->ErrorID << endl;
    cout << "错误信息 TThostFtdcErrorMsgType:" << pRspRepeal->ErrorMsg << endl;
}

///银行发起冲正期货转银行通知
void CTraderSpi::OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField* pRspRepeal)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "冲正时间间隔 TThostFtdcRepealTimeIntervalType:" << pRspRepeal->RepealTimeInterval << endl;
    cout << "已经冲正次数 TThostFtdcRepealedTimesType:" << pRspRepeal->RepealedTimes << endl;
    cout << "银行冲正标志 TThostFtdcBankRepealFlagType:" << pRspRepeal->BankRepealFlag << endl;
    cout << "期商冲正标志 TThostFtdcBrokerRepealFlagType:" << pRspRepeal->BrokerRepealFlag << endl;
    cout << "被冲正平台流水号 TThostFtdcPlateSerialType:" << pRspRepeal->PlateRepealSerial << endl;
    cout << "被冲正银行流水号 TThostFtdcBankSerialType:" << pRspRepeal->BankRepealSerial << endl;
    cout << "被冲正期货流水号 TThostFtdcFutureSerialType:" << pRspRepeal->FutureRepealSerial << endl;
    cout << "业务功能码 TThostFtdcTradeCodeType:" << pRspRepeal->TradeCode << endl;
    cout << "银行代码 TThostFtdcBankIDType:" << pRspRepeal->BankID << endl;
    cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << pRspRepeal->BankBranchID << endl;
    cout << "期商代码 TThostFtdcBrokerIDType:" << pRspRepeal->BrokerID << endl;
    cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << pRspRepeal->BrokerBranchID << endl;
    cout << "交易日期 TThostFtdcTradeDateType:" << pRspRepeal->TradeDate << endl;
    cout << "交易时间 TThostFtdcTradeTimeType:" << pRspRepeal->TradeTime << endl;
    cout << "银行流水号 TThostFtdcBankSerialType:" << pRspRepeal->BankSerial << endl;
    cout << "交易系统日期 TThostFtdcTradeDateType:" << pRspRepeal->TradingDay << endl;
    cout << "银期平台消息流水号 TThostFtdcSerialType:" << pRspRepeal->PlateSerial << endl;
    cout << "最后分片标志 TThostFtdcLastFragmentType:" << pRspRepeal->LastFragment << endl;
    cout << "会话号 TThostFtdcSessionIDType:" << pRspRepeal->SessionID << endl;
    cout << "客户姓名 TThostFtdcIndividualNameType:" << pRspRepeal->CustomerName << endl;
    cout << "证件类型 TThostFtdcIdCardTypeType:" << pRspRepeal->IdCardType << endl;
    cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pRspRepeal->IdentifiedCardNo << endl;
    cout << "客户类型 TThostFtdcCustTypeType:" << pRspRepeal->CustType << endl;
    cout << "银行帐号 TThostFtdcBankAccountType:" << pRspRepeal->BankAccount << endl;
    cout << "银行密码 TThostFtdcPasswordType:" << pRspRepeal->BankPassWord << endl;
    cout << "投资者帐号 TThostFtdcAccountIDType:" << pRspRepeal->AccountID << endl;
    cout << "期货密码 TThostFtdcPasswordType:" << pRspRepeal->Password << endl;
    cout << "安装编号 TThostFtdcInstallIDType:" << pRspRepeal->InstallID << endl;
    cout << "期货公司流水号 TThostFtdcFutureSerialType:" << pRspRepeal->FutureSerial << endl;
    cout << "用户标识 TThostFtdcUserIDType:" << pRspRepeal->UserID << endl;
    cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << pRspRepeal->VerifyCertNoFlag << endl;
    cout << "币种代码 TThostFtdcCurrencyIDType:" << pRspRepeal->CurrencyID << endl;
    cout << "转帐金额 TThostFtdcTradeAmountType:" << pRspRepeal->TradeAmount << endl;
    cout << "期货可取金额 TThostFtdcTradeAmountType:" << pRspRepeal->FutureFetchAmount << endl;
    cout << "费用支付标志 TThostFtdcFeePayFlagType:" << pRspRepeal->FeePayFlag << endl;
    cout << "应收客户费用 TThostFtdcCustFeeType:" << pRspRepeal->CustFee << endl;
    cout << "应收期货公司费用 TThostFtdcFutureFeeType:" << pRspRepeal->BrokerFee << endl;
    cout << "发送方给接收方的消息 TThostFtdcAddInfoType:" << pRspRepeal->Message << endl;
    cout << "摘要 TThostFtdcDigestType:" << pRspRepeal->Digest << endl;
    cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << pRspRepeal->BankAccType << endl;
    cout << "渠道标 TThostFtdcDeviceIDType:" << pRspRepeal->DeviceID << endl;
    cout << "期货单位帐号类型 TThostFtdcBankAccTypeType:" << pRspRepeal->BankSecuAccType << endl;
    cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << pRspRepeal->BrokerIDByBank << endl;
    cout << "期货单位帐号 TThostFtdcBankAccountType:" << pRspRepeal->BankSecuAcc << endl;
    cout << "银行密码标志 TThostFtdcPwdFlagType:" << pRspRepeal->BankPwdFlag << endl;
    cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << pRspRepeal->SecuPwdFlag << endl;
    cout << "交易柜员 TThostFtdcOperNoType:" << pRspRepeal->OperNo << endl;
    cout << "请求编号 TThostFtdcRequestIDType:" << pRspRepeal->RequestID << endl;
    cout << "交易 TThostFtdcTIDType:" << pRspRepeal->TID << endl;
    cout << "转账交易状态 TThostFtdcTransferStatusType:" << pRspRepeal->TransferStatus << endl;
    cout << "错误代码 TThostFtdcErrorIDType:" << pRspRepeal->ErrorID << endl;
    cout << "错误信息 TThostFtdcErrorMsgType:" << pRspRepeal->ErrorMsg << endl;
}

///期货发起银行资金转期货通知
void CTraderSpi::OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField* pRspTransfer)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "业务功能码 TThostFtdcTradeCodeType:" << pRspTransfer->TradeCode << endl;
    cout << "银行代码 TThostFtdcBankIDType:" << pRspTransfer->BankID << endl;
    cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << pRspTransfer->BankBranchID << endl;
    cout << "期商代码 TThostFtdcBrokerIDType:" << pRspTransfer->BrokerID << endl;
    cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << pRspTransfer->BrokerBranchID << endl;
    cout << "交易日期 TThostFtdcTradeDateType:" << pRspTransfer->TradeDate << endl;
    cout << "交易时间 TThostFtdcTradeTimeType:" << pRspTransfer->TradeTime << endl;
    cout << "银行流水号 TThostFtdcBankSerialType:" << pRspTransfer->BankSerial << endl;
    cout << "交易系统日期 TThostFtdcTradeDateType:" << pRspTransfer->TradingDay << endl;
    cout << "银期平台消息流水号 TThostFtdcSerialType:" << pRspTransfer->PlateSerial << endl;
    cout << "最后分片标志 TThostFtdcLastFragmentType:" << pRspTransfer->LastFragment << endl;
    cout << "会话号 TThostFtdcSessionIDType:" << pRspTransfer->SessionID << endl;
    cout << "客户姓名 TThostFtdcIndividualNameType:" << pRspTransfer->CustomerName << endl;
    cout << "证件类型 TThostFtdcIdCardTypeType:" << pRspTransfer->IdCardType << endl;
    cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pRspTransfer->IdentifiedCardNo << endl;
    cout << "客户类型 TThostFtdcCustTypeType:" << pRspTransfer->CustType << endl;
    cout << "银行帐号 TThostFtdcBankAccountType:" << pRspTransfer->BankAccount << endl;
    cout << "银行密码 TThostFtdcPasswordType:" << pRspTransfer->BankPassWord << endl;
    cout << "投资者帐号 TThostFtdcAccountIDType:" << pRspTransfer->AccountID << endl;
    cout << "期货密码 TThostFtdcPasswordType:" << pRspTransfer->Password << endl;
    cout << "安装编号 TThostFtdcInstallIDType:" << pRspTransfer->InstallID << endl;
    cout << "期货公司流水号 TThostFtdcFutureSerialType:" << pRspTransfer->FutureSerial << endl;
    cout << "用户标识 TThostFtdcUserIDType:" << pRspTransfer->UserID << endl;
    cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << pRspTransfer->VerifyCertNoFlag << endl;
    cout << "币种代码 TThostFtdcCurrencyIDType:" << pRspTransfer->CurrencyID << endl;
    cout << "转帐金额 TThostFtdcTradeAmountType:" << pRspTransfer->TradeAmount << endl;
    cout << "期货可取金额 TThostFtdcTradeAmountType:" << pRspTransfer->FutureFetchAmount << endl;
    cout << "费用支付标志 TThostFtdcFeePayFlagType:" << pRspTransfer->FeePayFlag << endl;
    cout << "应收客户费用 TThostFtdcCustFeeType:" << pRspTransfer->CustFee << endl;
    cout << "应收期货公司费用 TThostFtdcFutureFeeType:" << pRspTransfer->BrokerFee << endl;
    cout << "发送方给接收方的消息 TThostFtdcAddInfoType:" << pRspTransfer->Message << endl;
    cout << "摘要 TThostFtdcDigestType:" << pRspTransfer->Digest << endl;
    cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << pRspTransfer->BankAccType << endl;
    cout << "渠道标志 TThostFtdcDeviceIDType:" << pRspTransfer->DeviceID << endl;
    cout << "期货单位帐号类型 TThostFtdcBankAccTypeType:" << pRspTransfer->BankSecuAccType << endl;
    cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << pRspTransfer->BrokerIDByBank << endl;
    cout << "期货单位帐号 TThostFtdcBankAccountType:" << pRspTransfer->BankSecuAcc << endl;
    cout << "银行密码标志 TThostFtdcPwdFlagType:" << pRspTransfer->BankPwdFlag << endl;
    cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << pRspTransfer->SecuPwdFlag << endl;
    cout << "交易柜员 TThostFtdcOperNoType:" << pRspTransfer->OperNo << endl;
    cout << "请求编号 TThostFtdcRequestIDType:" << pRspTransfer->RequestID << endl;
    // cout << "交易ID:" << pRspTransfer->TThostFtdcTIDType << endlTID;
    cout << "转账交易状态 TThostFtdcTransferStatusType:" << pRspTransfer->TransferStatus << endl;
    cout << "错误代码 TThostFtdcErrorIDType:" << pRspTransfer->ErrorID << endl;
    cout << "错误信息 TThostFtdcErrorMsgType:" << pRspTransfer->ErrorMsg << endl;
}

///期货发起期货资金转银行通知
void CTraderSpi::OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField* pRspTransfer)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "业务功能码 TThostFtdcTradeCodeType:" << pRspTransfer->TradeCode << endl;
    cout << "银行代码 TThostFtdcBankIDType:" << pRspTransfer->BankID << endl;
    cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << pRspTransfer->BankBranchID << endl;
    cout << "期商代码 TThostFtdcBrokerIDType:" << pRspTransfer->BrokerID << endl;
    cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << pRspTransfer->BrokerBranchID << endl;
    cout << "交易日期 TThostFtdcTradeDateType:" << pRspTransfer->TradeDate << endl;
    cout << "交易时间 TThostFtdcTradeTimeType:" << pRspTransfer->TradeTime << endl;
    cout << "银行流水号 TThostFtdcBankSerialType:" << pRspTransfer->BankSerial << endl;
    cout << "交易系统日期 TThostFtdcTradeDateType:" << pRspTransfer->TradingDay << endl;
    cout << "银期平台消息流水号 TThostFtdcSerialType:" << pRspTransfer->PlateSerial << endl;
    cout << "最后分片标志 TThostFtdcLastFragmentType:" << pRspTransfer->LastFragment << endl;
    cout << "会话号 TThostFtdcSessionIDType:" << pRspTransfer->SessionID << endl;
    cout << "客户姓名 TThostFtdcIndividualNameType:" << pRspTransfer->CustomerName << endl;
    cout << "证件类型 TThostFtdcIdCardTypeType:" << pRspTransfer->IdCardType << endl;
    cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pRspTransfer->IdentifiedCardNo << endl;
    cout << "客户类型 TThostFtdcCustTypeType:" << pRspTransfer->CustType << endl;
    cout << "银行帐号 TThostFtdcBankAccountType:" << pRspTransfer->BankAccount << endl;
    cout << "银行密码 TThostFtdcPasswordType:" << pRspTransfer->BankPassWord << endl;
    cout << "投资者帐号 TThostFtdcAccountIDType:" << pRspTransfer->AccountID << endl;
    cout << "期货密码 TThostFtdcPasswordType:" << pRspTransfer->Password << endl;
    cout << "安装编号 TThostFtdcInstallIDType:" << pRspTransfer->InstallID << endl;
    cout << "期货公司流水号 TThostFtdcFutureSerialType:" << pRspTransfer->FutureSerial << endl;
    cout << "用户标识 TThostFtdcUserIDType:" << pRspTransfer->UserID << endl;
    cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << pRspTransfer->VerifyCertNoFlag << endl;
    cout << "币种代码 TThostFtdcCurrencyIDType:" << pRspTransfer->CurrencyID << endl;
    cout << "转帐金额 TThostFtdcTradeAmountType:" << pRspTransfer->TradeAmount << endl;
    cout << "期货可取金额 TThostFtdcTradeAmountType:" << pRspTransfer->FutureFetchAmount << endl;
    cout << "费用支付标志 TThostFtdcFeePayFlagType:" << pRspTransfer->FeePayFlag << endl;
    cout << "应收客户费用 TThostFtdcCustFeeType:" << pRspTransfer->CustFee << endl;
    cout << "应收期货公司费用 TThostFtdcFutureFeeType:" << pRspTransfer->BrokerFee << endl;
    cout << "发送方给接收方的消息 TThostFtdcAddInfoType:" << pRspTransfer->Message << endl;
    cout << "摘要 TThostFtdcDigestType:" << pRspTransfer->Digest << endl;
    cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << pRspTransfer->BankAccType << endl;
    cout << "渠道标志 TThostFtdcDeviceIDType:" << pRspTransfer->DeviceID << endl;
    cout << "期货单位帐号类型 TThostFtdcBankAccTypeType:" << pRspTransfer->BankSecuAccType << endl;
    cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << pRspTransfer->BrokerIDByBank << endl;
    cout << "期货单位帐号 TThostFtdcBankAccountType:" << pRspTransfer->BankSecuAcc << endl;
    cout << "银行密码标志 TThostFtdcPwdFlagType:" << pRspTransfer->BankPwdFlag << endl;
    cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << pRspTransfer->SecuPwdFlag << endl;
    cout << "交易柜员 TThostFtdcOperNoType:" << pRspTransfer->OperNo << endl;
    cout << "请求编号 TThostFtdcRequestIDType:" << pRspTransfer->RequestID << endl;
    // cout << "交易ID:" << pRspTransfer->TThostFtdcTIDType << endlTID;
    cout << "转账交易状态 TThostFtdcTransferStatusType:" << pRspTransfer->TransferStatus << endl;
    cout << "错误代码 TThostFtdcErrorIDType:" << pRspTransfer->ErrorID << endl;
    cout << "错误信息 TThostFtdcErrorMsgType:" << pRspTransfer->ErrorMsg << endl;
}

///系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
void CTraderSpi::OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField* pRspRepeal)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "冲正时间间隔 TThostFtdcRepealTimeIntervalType:" << pRspRepeal->RepealTimeInterval << endl;
    cout << "已经冲正次数 TThostFtdcRepealedTimesType:" << pRspRepeal->RepealedTimes << endl;
    cout << "银行冲正标志 TThostFtdcBankRepealFlagType:" << pRspRepeal->BankRepealFlag << endl;
    cout << "期商冲正标志 TThostFtdcBrokerRepealFlagType:" << pRspRepeal->BrokerRepealFlag << endl;
    cout << "被冲正平台流水号 TThostFtdcPlateSerialType:" << pRspRepeal->PlateRepealSerial << endl;
    cout << "被冲正银行流水号 TThostFtdcBankSerialType:" << pRspRepeal->BankRepealSerial << endl;
    cout << "被冲正期货流水号 TThostFtdcFutureSerialType:" << pRspRepeal->FutureRepealSerial << endl;
    cout << "业务功能码 TThostFtdcTradeCodeType:" << pRspRepeal->TradeCode << endl;
    cout << "银行代码 TThostFtdcBankIDType:" << pRspRepeal->BankID << endl;
    cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << pRspRepeal->BankBranchID << endl;
    cout << "期商代码 TThostFtdcBrokerIDType:" << pRspRepeal->BrokerID << endl;
    cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << pRspRepeal->BrokerBranchID << endl;
    cout << "交易日期 TThostFtdcTradeDateType:" << pRspRepeal->TradeDate << endl;
    cout << "交易时间 TThostFtdcTradeTimeType:" << pRspRepeal->TradeTime << endl;
    cout << "银行流水号 TThostFtdcBankSerialType:" << pRspRepeal->BankSerial << endl;
    cout << "交易系统日期 TThostFtdcTradeDateType:" << pRspRepeal->TradingDay << endl;
    cout << "银期平台消息流水号 TThostFtdcSerialType:" << pRspRepeal->PlateSerial << endl;
    cout << "最后分片标志 TThostFtdcLastFragmentType:" << pRspRepeal->LastFragment << endl;
    cout << "会话号 TThostFtdcSessionIDType:" << pRspRepeal->SessionID << endl;
    cout << "客户姓名 TThostFtdcIndividualNameType:" << pRspRepeal->CustomerName << endl;
    cout << "证件类型 TThostFtdcIdCardTypeType:" << pRspRepeal->IdCardType << endl;
    cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pRspRepeal->IdentifiedCardNo << endl;
    cout << "客户类型 TThostFtdcCustTypeType:" << pRspRepeal->CustType << endl;
    cout << "银行帐号 TThostFtdcBankAccountType:" << pRspRepeal->BankAccount << endl;
    cout << "银行密码 TThostFtdcPasswordType:" << pRspRepeal->BankPassWord << endl;
    cout << "投资者帐号 TThostFtdcAccountIDType:" << pRspRepeal->AccountID << endl;
    cout << "期货密码 TThostFtdcPasswordType:" << pRspRepeal->Password << endl;
    cout << "安装编号 TThostFtdcInstallIDType:" << pRspRepeal->InstallID << endl;
    cout << "期货公司流水号 TThostFtdcFutureSerialType:" << pRspRepeal->FutureSerial << endl;
    cout << "用户标识 TThostFtdcUserIDType:" << pRspRepeal->UserID << endl;
    cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << pRspRepeal->VerifyCertNoFlag << endl;
    cout << "币种代码 TThostFtdcCurrencyIDType:" << pRspRepeal->CurrencyID << endl;
    cout << "转帐金额 TThostFtdcTradeAmountType:" << pRspRepeal->TradeAmount << endl;
    cout << "期货可取金额 TThostFtdcTradeAmountType:" << pRspRepeal->FutureFetchAmount << endl;
    cout << "费用支付标志 TThostFtdcFeePayFlagType:" << pRspRepeal->FeePayFlag << endl;
    cout << "应收客户费用 TThostFtdcCustFeeType:" << pRspRepeal->CustFee << endl;
    cout << "应收期货公司费用 TThostFtdcFutureFeeType:" << pRspRepeal->BrokerFee << endl;
    cout << "发送方给接收方的消息 TThostFtdcAddInfoType:" << pRspRepeal->Message << endl;
    cout << "摘要 TThostFtdcDigestType:" << pRspRepeal->Digest << endl;
    cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << pRspRepeal->BankAccType << endl;
    cout << "渠道标志 TThostFtdcDeviceIDType:" << pRspRepeal->DeviceID << endl;
    cout << "期货单位帐号类型 TThostFtdcBankAccTypeType:" << pRspRepeal->BankSecuAccType << endl;
    cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << pRspRepeal->BrokerIDByBank << endl;
    cout << "期货单位帐号 TThostFtdcBankAccountType:" << pRspRepeal->BankSecuAcc << endl;
    cout << "银行密码标志 TThostFtdcPwdFlagType:" << pRspRepeal->BankPwdFlag << endl;
    cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << pRspRepeal->SecuPwdFlag << endl;
    cout << "交易柜员 TThostFtdcOperNoType:" << pRspRepeal->OperNo << endl;
    cout << "请求编号 TThostFtdcRequestIDType:" << pRspRepeal->RequestID << endl;
    // cout << "交易ID:" << pRspRepeal->TThostFtdcTIDType << endlTID;
    cout << "转账交易状态 TThostFtdcTransferStatusType:" << pRspRepeal->TransferStatus << endl;
    cout << "错误代码 TThostFtdcErrorIDType:" << pRspRepeal->ErrorID << endl;
    cout << "错误信息 TThostFtdcErrorMsgType:" << pRspRepeal->ErrorMsg << endl;
}

///系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
void CTraderSpi::OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField* pRspRepeal)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "冲正时间间隔 TThostFtdcRepealTimeIntervalType:" << pRspRepeal->RepealTimeInterval << endl;
    cout << "已经冲正次数 TThostFtdcRepealedTimesType:" << pRspRepeal->RepealedTimes << endl;
    cout << "银行冲正标志 TThostFtdcBankRepealFlagType:" << pRspRepeal->BankRepealFlag << endl;
    cout << "期商冲正标志 TThostFtdcBrokerRepealFlagType:" << pRspRepeal->BrokerRepealFlag << endl;
    cout << "被冲正平台流水号 TThostFtdcPlateSerialType:" << pRspRepeal->PlateRepealSerial << endl;
    cout << "被冲正银行流水号 TThostFtdcBankSerialType:" << pRspRepeal->BankRepealSerial << endl;
    cout << "被冲正期货流水号 TThostFtdcFutureSerialType:" << pRspRepeal->FutureRepealSerial << endl;
    cout << "业务功能码 TThostFtdcTradeCodeType:" << pRspRepeal->TradeCode << endl;
    cout << "银行代码 TThostFtdcBankIDType:" << pRspRepeal->BankID << endl;
    cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << pRspRepeal->BankBranchID << endl;
    cout << "期商代码 TThostFtdcBrokerIDType:" << pRspRepeal->BrokerID << endl;
    cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << pRspRepeal->BrokerBranchID << endl;
    cout << "交易日期 TThostFtdcTradeDateType:" << pRspRepeal->TradeDate << endl;
    cout << "交易时间 TThostFtdcTradeTimeType:" << pRspRepeal->TradeTime << endl;
    cout << "银行流水号 TThostFtdcBankSerialType:" << pRspRepeal->BankSerial << endl;
    cout << "交易系统日期 TThostFtdcTradeDateType:" << pRspRepeal->TradingDay << endl;
    cout << "银期平台消息流水号 TThostFtdcSerialType:" << pRspRepeal->PlateSerial << endl;
    cout << "最后分片标志 TThostFtdcLastFragmentType:" << pRspRepeal->LastFragment << endl;
    cout << "会话号 TThostFtdcSessionIDType:" << pRspRepeal->SessionID << endl;
    cout << "客户姓名 TThostFtdcIndividualNameType:" << pRspRepeal->CustomerName << endl;
    cout << "证件类型 TThostFtdcIdCardTypeType:" << pRspRepeal->IdCardType << endl;
    cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pRspRepeal->IdentifiedCardNo << endl;
    cout << "客户类型 TThostFtdcCustTypeType:" << pRspRepeal->CustType << endl;
    cout << "银行帐号 TThostFtdcBankAccountType:" << pRspRepeal->BankAccount << endl;
    cout << "银行密码 TThostFtdcPasswordType:" << pRspRepeal->BankPassWord << endl;
    cout << "投资者帐号 TThostFtdcAccountIDType:" << pRspRepeal->AccountID << endl;
    cout << "期货密码 TThostFtdcPasswordType:" << pRspRepeal->Password << endl;
    cout << "安装编号 TThostFtdcInstallIDType:" << pRspRepeal->InstallID << endl;
    cout << "期货公司流水号 TThostFtdcFutureSerialType:" << pRspRepeal->FutureSerial << endl;
    cout << "用户标识 TThostFtdcUserIDType:" << pRspRepeal->UserID << endl;
    cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << pRspRepeal->VerifyCertNoFlag << endl;
    cout << "币种代码 TThostFtdcCurrencyIDType:" << pRspRepeal->CurrencyID << endl;
    cout << "转帐金额 TThostFtdcTradeAmountType:" << pRspRepeal->TradeAmount << endl;
    cout << "期货可取金额 TThostFtdcTradeAmountType:" << pRspRepeal->FutureFetchAmount << endl;
    cout << "费用支付标志 TThostFtdcFeePayFlagType:" << pRspRepeal->FeePayFlag << endl;
    cout << "应收客户费用 TThostFtdcCustFeeType:" << pRspRepeal->CustFee << endl;
    cout << "应收期货公司费用 TThostFtdcFutureFeeType:" << pRspRepeal->BrokerFee << endl;
    cout << "发送方给接收方的消息 TThostFtdcAddInfoType:" << pRspRepeal->Message << endl;
    cout << "摘要 TThostFtdcDigestType:" << pRspRepeal->Digest << endl;
    cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << pRspRepeal->BankAccType << endl;
    cout << "渠道标志 TThostFtdcDeviceIDType:" << pRspRepeal->DeviceID << endl;
    cout << "期货单位帐号类型 TThostFtdcBankAccTypeType:" << pRspRepeal->BankSecuAccType << endl;
    cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << pRspRepeal->BrokerIDByBank << endl;
    cout << "期货单位帐号 TThostFtdcBankAccountType:" << pRspRepeal->BankSecuAcc << endl;
    cout << "银行密码标志 TThostFtdcPwdFlagType:" << pRspRepeal->BankPwdFlag << endl;
    cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << pRspRepeal->SecuPwdFlag << endl;
    cout << "交易柜员 TThostFtdcOperNoType:" << pRspRepeal->OperNo << endl;
    cout << "请求编号 TThostFtdcRequestIDType:" << pRspRepeal->RequestID << endl;
    // cout << "交易ID:" << pRspRepeal->TThostFtdcTIDType << endlTID;
    cout << "转账交易状态 TThostFtdcTransferStatusType:" << pRspRepeal->TransferStatus << endl;
    cout << "错误代码 TThostFtdcErrorIDType:" << pRspRepeal->ErrorID << endl;
    cout << "错误信息 TThostFtdcErrorMsgType:" << pRspRepeal->ErrorMsg << endl;
}

///期货发起查询银行余额通知
void CTraderSpi::OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField* pNotifyQueryAccount)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "业务功能码 TThostFtdcTradeCodeType:" << pNotifyQueryAccount->TradeCode << endl;
    cout << "银行代码 TThostFtdcBankIDType:" << pNotifyQueryAccount->BankID << endl;
    cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << pNotifyQueryAccount->BankBranchID << endl;
    cout << "期商代码 TThostFtdcBrokerIDType:" << pNotifyQueryAccount->BrokerID << endl;
    cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << pNotifyQueryAccount->BrokerBranchID << endl;
    cout << "交易日期 TThostFtdcTradeDateType:" << pNotifyQueryAccount->TradeDate << endl;
    cout << "交易时间 TThostFtdcTradeTimeType:" << pNotifyQueryAccount->TradeTime << endl;
    cout << "银行流水号 TThostFtdcBankSerialType:" << pNotifyQueryAccount->BankSerial << endl;
    cout << "交易系统日期 TThostFtdcTradeDateType:" << pNotifyQueryAccount->TradingDay << endl;
    cout << "银期平台消息流水号 TThostFtdcSerialType:" << pNotifyQueryAccount->PlateSerial << endl;
    cout << "最后分片标志 TThostFtdcLastFragmentType:" << pNotifyQueryAccount->LastFragment << endl;
    cout << "会话号 TThostFtdcSessionIDType:" << pNotifyQueryAccount->SessionID << endl;
    cout << "客户姓名 TThostFtdcIndividualNameType:" << pNotifyQueryAccount->CustomerName << endl;
    cout << "证件类型 TThostFtdcIdCardTypeType:" << pNotifyQueryAccount->IdCardType << endl;
    cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pNotifyQueryAccount->IdentifiedCardNo << endl;
    cout << "客户类型 TThostFtdcCustTypeType:" << pNotifyQueryAccount->CustType << endl;
    cout << "银行帐号 TThostFtdcBankAccountType:" << pNotifyQueryAccount->BankAccount << endl;
    cout << "银行密码 TThostFtdcPasswordType:" << pNotifyQueryAccount->BankPassWord << endl;
    cout << "投资者帐号 TThostFtdcAccountIDType:" << pNotifyQueryAccount->AccountID << endl;
    cout << "期货密码 TThostFtdcPasswordType:" << pNotifyQueryAccount->Password << endl;
    cout << "期货公司流水号 TThostFtdcFutureSerialType:" << pNotifyQueryAccount->FutureSerial << endl;
    cout << "安装编号 TThostFtdcInstallIDType:" << pNotifyQueryAccount->InstallID << endl;
    cout << "用户标识 TThostFtdcUserIDType:" << pNotifyQueryAccount->UserID << endl;
    cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << pNotifyQueryAccount->VerifyCertNoFlag << endl;
    cout << "币种代码 TThostFtdcCurrencyIDType:" << pNotifyQueryAccount->CurrencyID << endl;
    cout << "摘要 TThostFtdcDigestType:" << pNotifyQueryAccount->Digest << endl;
    cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << pNotifyQueryAccount->BankAccType << endl;
    cout << "渠道标志 TThostFtdcDeviceIDType:" << pNotifyQueryAccount->DeviceID << endl;
    cout << "期货单位帐号类型 TThostFtdcBankAccTypeType:" << pNotifyQueryAccount->BankSecuAccType << endl;
    cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << pNotifyQueryAccount->BrokerIDByBank << endl;
    cout << "期货单位帐号 TThostFtdcBankAccountType:" << pNotifyQueryAccount->BankSecuAcc << endl;
    cout << "银行密码标志 TThostFtdcPwdFlagType:" << pNotifyQueryAccount->BankPwdFlag << endl;
    cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << pNotifyQueryAccount->SecuPwdFlag << endl;
    cout << "交易柜员 TThostFtdcOperNoType:" << pNotifyQueryAccount->OperNo << endl;
    cout << "请求编号 TThostFtdcRequestIDType:" << pNotifyQueryAccount->RequestID << endl;
    cout << "交易 TThostFtdcTIDType:" << pNotifyQueryAccount->TID << endl;
    cout << "银行可用金额 TThostFtdcTradeAmountType:" << pNotifyQueryAccount->BankUseAmount << endl;
    cout << "银行可取金额 TThostFtdcTradeAmountType:" << pNotifyQueryAccount->BankFetchAmount << endl;
    cout << "错误代码 TThostFtdcErrorIDType:" << pNotifyQueryAccount->ErrorID << endl;
    cout << "错误信息 TThostFtdcErrorMsgType:" << pNotifyQueryAccount->ErrorMsg << endl;
}

///期货发起银行资金转期货错误回报
void CTraderSpi::OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "业务功能码 TThostFtdcTradeCodeType:" << pReqTransfer->TradeCode << endl;
    cout << "银行代码 TThostFtdcBankIDType:" << pReqTransfer->BankID << endl;
    cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << pReqTransfer->BankBranchID << endl;
    cout << "期商代码 TThostFtdcBrokerIDType:" << pReqTransfer->BrokerID << endl;
    cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << pReqTransfer->BrokerBranchID << endl;
    cout << "交易日期 TThostFtdcTradeDateType:" << pReqTransfer->TradeDate << endl;
    cout << "交易时间 TThostFtdcTradeTimeType:" << pReqTransfer->TradeTime << endl;
    cout << "银行流水号 TThostFtdcBankSerialType:" << pReqTransfer->BankSerial << endl;
    cout << "交易系统日期 TThostFtdcTradeDateType:" << pReqTransfer->TradingDay << endl;
    cout << "银期平台消息流水号 TThostFtdcSerialType:" << pReqTransfer->PlateSerial << endl;
    cout << "最后分片标志 TThostFtdcLastFragmentType:" << pReqTransfer->LastFragment << endl;
    cout << "会话号 TThostFtdcSessionIDType:" << pReqTransfer->SessionID << endl;
    cout << "客户姓名 TThostFtdcIndividualNameType:" << pReqTransfer->CustomerName << endl;
    cout << "证件类型 TThostFtdcIdCardTypeType:" << pReqTransfer->IdCardType << endl;
    cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pReqTransfer->IdentifiedCardNo << endl;
    cout << "客户类型 TThostFtdcCustTypeType:" << pReqTransfer->CustType << endl;
    cout << "银行帐号 TThostFtdcBankAccountType:" << pReqTransfer->BankAccount << endl;
    cout << "银行密码 TThostFtdcPasswordType:" << pReqTransfer->BankPassWord << endl;
    cout << "投资者帐号 TThostFtdcAccountIDType:" << pReqTransfer->AccountID << endl;
    cout << "期货密码 TThostFtdcPasswordType:" << pReqTransfer->Password << endl;
    cout << "安装编号 TThostFtdcInstallIDType:" << pReqTransfer->InstallID << endl;
    cout << "期货公司流水号 TThostFtdcFutureSerialType:" << pReqTransfer->FutureSerial << endl;
    cout << "用户标识 TThostFtdcUserIDType:" << pReqTransfer->UserID << endl;
    cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << pReqTransfer->VerifyCertNoFlag << endl;
    cout << "币种代码 TThostFtdcCurrencyIDType:" << pReqTransfer->CurrencyID << endl;
    cout << "转帐金额 TThostFtdcTradeAmountType:" << pReqTransfer->TradeAmount << endl;
    cout << "期货可取金额 TThostFtdcTradeAmountType:" << pReqTransfer->FutureFetchAmount << endl;
    cout << "费用支付标志 TThostFtdcFeePayFlagType:" << pReqTransfer->FeePayFlag << endl;
    cout << "应收客户费用 TThostFtdcCustFeeType:" << pReqTransfer->CustFee << endl;
    cout << "应收期货公司费用 TThostFtdcFutureFeeType:" << pReqTransfer->BrokerFee << endl;
    cout << "发送方给接收方的消息 TThostFtdcAddInfoType:" << pReqTransfer->Message << endl;
    cout << "摘要 TThostFtdcDigestType:" << pReqTransfer->Digest << endl;
    cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << pReqTransfer->BankAccType << endl;
    cout << "渠道标志 TThostFtdcDeviceIDType:" << pReqTransfer->DeviceID << endl;
    cout << "期货单位帐号类型 TThostFtdcBankAccTypeType:" << pReqTransfer->BankSecuAccType << endl;
    cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << pReqTransfer->BrokerIDByBank << endl;
    cout << "期货单位帐号 TThostFtdcBankAccountType:" << pReqTransfer->BankSecuAcc << endl;
    cout << "银行密码标志 TThostFtdcPwdFlagType:" << pReqTransfer->BankPwdFlag << endl;
    cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << pReqTransfer->SecuPwdFlag << endl;
    cout << "交易柜员 TThostFtdcOperNoType:" << pReqTransfer->OperNo << endl;
    cout << "请求编号 TThostFtdcRequestIDType:" << pReqTransfer->RequestID << endl;
    // cout << "交易ID:" << pReqTransfer->TThostFtdcTIDType << endlTID;
    cout << "转账交易状态 TThostFtdcTransferStatusType:" << pReqTransfer->TransferStatus << endl;
}

///期货发起期货资金转银行错误回报
void CTraderSpi::OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (!IsErrorRspInfo(pRspInfo)) {
	cout << "业务功能码 TThostFtdcTradeCodeType:" << pReqTransfer->TradeCode << endl;
	cout << "银行代码 TThostFtdcBankIDType:" << pReqTransfer->BankID << endl;
	cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << pReqTransfer->BankBranchID << endl;
	cout << "期商代码 TThostFtdcBrokerIDType:" << pReqTransfer->BrokerID << endl;
	cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << pReqTransfer->BrokerBranchID << endl;
	cout << "交易日期 TThostFtdcTradeDateType:" << pReqTransfer->TradeDate << endl;
	cout << "交易时间 TThostFtdcTradeTimeType:" << pReqTransfer->TradeTime << endl;
	cout << "银行流水号 TThostFtdcBankSerialType:" << pReqTransfer->BankSerial << endl;
	cout << "交易系统日期 TThostFtdcTradeDateType:" << pReqTransfer->TradingDay << endl;
	cout << "银期平台消息流水号 TThostFtdcSerialType:" << pReqTransfer->PlateSerial << endl;
	cout << "最后分片标志 TThostFtdcLastFragmentType:" << pReqTransfer->LastFragment << endl;
	cout << "会话号 TThostFtdcSessionIDType:" << pReqTransfer->SessionID << endl;
	cout << "客户姓名 TThostFtdcIndividualNameType:" << pReqTransfer->CustomerName << endl;
	cout << "证件类型 TThostFtdcIdCardTypeType:" << pReqTransfer->IdCardType << endl;
	cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pReqTransfer->IdentifiedCardNo << endl;
	cout << "客户类型 TThostFtdcCustTypeType:" << pReqTransfer->CustType << endl;
	cout << "银行帐号 TThostFtdcBankAccountType:" << pReqTransfer->BankAccount << endl;
	cout << "银行密码 TThostFtdcPasswordType:" << pReqTransfer->BankPassWord << endl;
	cout << "投资者帐号 TThostFtdcAccountIDType:" << pReqTransfer->AccountID << endl;
	cout << "期货密码 TThostFtdcPasswordType:" << pReqTransfer->Password << endl;
	cout << "安装编号 TThostFtdcInstallIDType:" << pReqTransfer->InstallID << endl;
	cout << "期货公司流水号 TThostFtdcFutureSerialType:" << pReqTransfer->FutureSerial << endl;
	cout << "用户标识 TThostFtdcUserIDType:" << pReqTransfer->UserID << endl;
	cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << pReqTransfer->VerifyCertNoFlag << endl;
	cout << "币种代码 TThostFtdcCurrencyIDType:" << pReqTransfer->CurrencyID << endl;
	cout << "转帐金额 TThostFtdcTradeAmountType:" << pReqTransfer->TradeAmount << endl;
	cout << "期货可取金额 TThostFtdcTradeAmountType:" << pReqTransfer->FutureFetchAmount << endl;
	cout << "费用支付标志 TThostFtdcFeePayFlagType:" << pReqTransfer->FeePayFlag << endl;
	cout << "应收客户费用 TThostFtdcCustFeeType:" << pReqTransfer->CustFee << endl;
	cout << "应收期货公司费用 TThostFtdcFutureFeeType:" << pReqTransfer->BrokerFee << endl;
	cout << "发送方给接收方的消息 TThostFtdcAddInfoType:" << pReqTransfer->Message << endl;
	cout << "摘要 TThostFtdcDigestType:" << pReqTransfer->Digest << endl;
	cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << pReqTransfer->BankAccType << endl;
	cout << "渠道标志 TThostFtdcDeviceIDType:" << pReqTransfer->DeviceID << endl;
	cout << "期货单位帐号类型 TThostFtdcBankAccTypeType:" << pReqTransfer->BankSecuAccType << endl;
	cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << pReqTransfer->BrokerIDByBank << endl;
	cout << "期货单位帐号 TThostFtdcBankAccountType:" << pReqTransfer->BankSecuAcc << endl;
	cout << "银行密码标志 TThostFtdcPwdFlagType:" << pReqTransfer->BankPwdFlag << endl;
	cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << pReqTransfer->SecuPwdFlag << endl;
	cout << "交易柜员 TThostFtdcOperNoType:" << pReqTransfer->OperNo << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pReqTransfer->RequestID << endl;
	// cout << "交易ID:" << pReqTransfer->TThostFtdcTIDType << endlTID;
	cout << "转账交易状态 TThostFtdcTransferStatusType:" << pReqTransfer->TransferStatus << endl;
    }
}

///系统运行时期货端手工发起冲正银行转期货错误回报
void CTraderSpi::OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (!IsErrorRspInfo(pRspInfo)) {
	cout << "冲正时间间隔 TThostFtdcRepealTimeIntervalType:" << pReqRepeal->RepealTimeInterval << endl;
	cout << "已经冲正次数 TThostFtdcRepealedTimesType:" << pReqRepeal->RepealedTimes << endl;
	cout << "银行冲正标志 TThostFtdcBankRepealFlagType:" << pReqRepeal->BankRepealFlag << endl;
	cout << "期商冲正标志 TThostFtdcBrokerRepealFlagType:" << pReqRepeal->BrokerRepealFlag << endl;
	cout << "被冲正平台流水号 TThostFtdcPlateSerialType:" << pReqRepeal->PlateRepealSerial << endl;
	cout << "被冲正银行流水号 TThostFtdcBankSerialType:" << pReqRepeal->BankRepealSerial << endl;
	cout << "被冲正期货流水号 TThostFtdcFutureSerialType:" << pReqRepeal->FutureRepealSerial << endl;
	cout << "业务功能码 TThostFtdcTradeCodeType:" << pReqRepeal->TradeCode << endl;
	cout << "银行代码 TThostFtdcBankIDType:" << pReqRepeal->BankID << endl;
	cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << pReqRepeal->BankBranchID << endl;
	cout << "期商代码 TThostFtdcBrokerIDType:" << pReqRepeal->BrokerID << endl;
	cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << pReqRepeal->BrokerBranchID << endl;
	cout << "交易日期 TThostFtdcTradeDateType:" << pReqRepeal->TradeDate << endl;
	cout << "交易时间 TThostFtdcTradeTimeType:" << pReqRepeal->TradeTime << endl;
	cout << "银行流水号 TThostFtdcBankSerialType:" << pReqRepeal->BankSerial << endl;
	cout << "交易系统日期 TThostFtdcTradeDateType:" << pReqRepeal->TradingDay << endl;
	cout << "银期平台消息流水号 TThostFtdcSerialType:" << pReqRepeal->PlateSerial << endl;
	cout << "最后分片标志 TThostFtdcLastFragmentType:" << pReqRepeal->LastFragment << endl;
	cout << "会话号 TThostFtdcSessionIDType:" << pReqRepeal->SessionID << endl;
	cout << "客户姓名 TThostFtdcIndividualNameType:" << pReqRepeal->CustomerName << endl;
	cout << "证件类型 TThostFtdcIdCardTypeType:" << pReqRepeal->IdCardType << endl;
	cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pReqRepeal->IdentifiedCardNo << endl;
	cout << "客户类型 TThostFtdcCustTypeType:" << pReqRepeal->CustType << endl;
	cout << "银行帐号 TThostFtdcBankAccountType:" << pReqRepeal->BankAccount << endl;
	cout << "银行密码 TThostFtdcPasswordType:" << pReqRepeal->BankPassWord << endl;
	cout << "投资者帐号 TThostFtdcAccountIDType:" << pReqRepeal->AccountID << endl;
	cout << "期货密码 TThostFtdcPasswordType:" << pReqRepeal->Password << endl;
	cout << "安装编号 TThostFtdcInstallIDType:" << pReqRepeal->InstallID << endl;
	cout << "期货公司流水号 TThostFtdcFutureSerialType:" << pReqRepeal->FutureSerial << endl;
	cout << "用户标识 TThostFtdcUserIDType:" << pReqRepeal->UserID << endl;
	cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << pReqRepeal->VerifyCertNoFlag << endl;
	cout << "币种代码 TThostFtdcCurrencyIDType:" << pReqRepeal->CurrencyID << endl;
	cout << "转帐金额 TThostFtdcTradeAmountType:" << pReqRepeal->TradeAmount << endl;
	cout << "期货可取金额 TThostFtdcTradeAmountType:" << pReqRepeal->FutureFetchAmount << endl;
	cout << "费用支付标志 TThostFtdcFeePayFlagType:" << pReqRepeal->FeePayFlag << endl;
	cout << "应收客户费用 TThostFtdcCustFeeType:" << pReqRepeal->CustFee << endl;
	cout << "应收期货公司费用 TThostFtdcFutureFeeType:" << pReqRepeal->BrokerFee << endl;
	cout << "发送方给接收方的消息 TThostFtdcAddInfoType:" << pReqRepeal->Message << endl;
	cout << "摘要 TThostFtdcDigestType:" << pReqRepeal->Digest << endl;
	cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << pReqRepeal->BankAccType << endl;
	cout << "渠道标志 TThostFtdcDeviceIDType:" << pReqRepeal->DeviceID << endl;
	cout << "期货单位帐号类型 TThostFtdcBankAccTypeType:" << pReqRepeal->BankSecuAccType << endl;
	cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << pReqRepeal->BrokerIDByBank << endl;
	cout << "期货单位帐号 TThostFtdcBankAccountType:" << pReqRepeal->BankSecuAcc << endl;
	cout << "银行密码标志 TThostFtdcPwdFlagType:" << pReqRepeal->BankPwdFlag << endl;
	cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << pReqRepeal->SecuPwdFlag << endl;
	cout << "交易柜员 TThostFtdcOperNoType:" << pReqRepeal->OperNo << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pReqRepeal->RequestID << endl;
	// cout << "交易ID:" << pReqRepeal->TThostFtdcTIDType << endlTID;
	cout << "转账交易状态 TThostFtdcTransferStatusType:" << pReqRepeal->TransferStatus << endl;
    }
}

///系统运行时期货端手工发起冲正期货转银行错误回报
void CTraderSpi::OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (!IsErrorRspInfo(pRspInfo)) {
	cout << "冲正时间间隔 TThostFtdcRepealTimeIntervalType:" << pReqRepeal->RepealTimeInterval << endl;
	cout << "已经冲正次数 TThostFtdcRepealedTimesType:" << pReqRepeal->RepealedTimes << endl;
	cout << "银行冲正标志 TThostFtdcBankRepealFlagType:" << pReqRepeal->BankRepealFlag << endl;
	cout << "期商冲正标志 TThostFtdcBrokerRepealFlagType:" << pReqRepeal->BrokerRepealFlag << endl;
	cout << "被冲正平台流水号 TThostFtdcPlateSerialType:" << pReqRepeal->PlateRepealSerial << endl;
	cout << "被冲正银行流水号 TThostFtdcBankSerialType:" << pReqRepeal->BankRepealSerial << endl;
	cout << "被冲正期货流水号 TThostFtdcFutureSerialType:" << pReqRepeal->FutureRepealSerial << endl;
	cout << "业务功能码 TThostFtdcTradeCodeType:" << pReqRepeal->TradeCode << endl;
	cout << "银行代码 TThostFtdcBankIDType:" << pReqRepeal->BankID << endl;
	cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << pReqRepeal->BankBranchID << endl;
	cout << "期商代码 TThostFtdcBrokerIDType:" << pReqRepeal->BrokerID << endl;
	cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << pReqRepeal->BrokerBranchID << endl;
	cout << "交易日期 TThostFtdcTradeDateType:" << pReqRepeal->TradeDate << endl;
	cout << "交易时间 TThostFtdcTradeTimeType:" << pReqRepeal->TradeTime << endl;
	cout << "银行流水号 TThostFtdcBankSerialType:" << pReqRepeal->BankSerial << endl;
	cout << "交易系统日期 TThostFtdcTradeDateType:" << pReqRepeal->TradingDay << endl;
	cout << "银期平台消息流水号 TThostFtdcSerialType:" << pReqRepeal->PlateSerial << endl;
	cout << "最后分片标志 TThostFtdcLastFragmentType:" << pReqRepeal->LastFragment << endl;
	cout << "会话号 TThostFtdcSessionIDType:" << pReqRepeal->SessionID << endl;
	cout << "客户姓名 TThostFtdcIndividualNameType:" << pReqRepeal->CustomerName << endl;
	cout << "证件类型 TThostFtdcIdCardTypeType:" << pReqRepeal->IdCardType << endl;
	cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pReqRepeal->IdentifiedCardNo << endl;
	cout << "客户类型 TThostFtdcCustTypeType:" << pReqRepeal->CustType << endl;
	cout << "银行帐号 TThostFtdcBankAccountType:" << pReqRepeal->BankAccount << endl;
	cout << "银行密码 TThostFtdcPasswordType:" << pReqRepeal->BankPassWord << endl;
	cout << "投资者帐号 TThostFtdcAccountIDType:" << pReqRepeal->AccountID << endl;
	cout << "期货密码 TThostFtdcPasswordType:" << pReqRepeal->Password << endl;
	cout << "安装编号 TThostFtdcInstallIDType:" << pReqRepeal->InstallID << endl;
	cout << "期货公司流水号 TThostFtdcFutureSerialType:" << pReqRepeal->FutureSerial << endl;
	cout << "用户标识 TThostFtdcUserIDType:" << pReqRepeal->UserID << endl;
	cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << pReqRepeal->VerifyCertNoFlag << endl;
	cout << "币种代码 TThostFtdcCurrencyIDType:" << pReqRepeal->CurrencyID << endl;
	cout << "转帐金额 TThostFtdcTradeAmountType:" << pReqRepeal->TradeAmount << endl;
	cout << "期货可取金额 TThostFtdcTradeAmountType:" << pReqRepeal->FutureFetchAmount << endl;
	cout << "费用支付标志 TThostFtdcFeePayFlagType:" << pReqRepeal->FeePayFlag << endl;
	cout << "应收客户费用 TThostFtdcCustFeeType:" << pReqRepeal->CustFee << endl;
	cout << "应收期货公司费用 TThostFtdcFutureFeeType:" << pReqRepeal->BrokerFee << endl;
	cout << "发送方给接收方的消息 TThostFtdcAddInfoType:" << pReqRepeal->Message << endl;
	cout << "摘要 TThostFtdcDigestType:" << pReqRepeal->Digest << endl;
	cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << pReqRepeal->BankAccType << endl;
	cout << "渠道标志 TThostFtdcDeviceIDType:" << pReqRepeal->DeviceID << endl;
	cout << "期货单位帐号类型 TThostFtdcBankAccTypeType:" << pReqRepeal->BankSecuAccType << endl;
	cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << pReqRepeal->BrokerIDByBank << endl;
	cout << "期货单位帐号 TThostFtdcBankAccountType:" << pReqRepeal->BankSecuAcc << endl;
	cout << "银行密码标志 TThostFtdcPwdFlagType:" << pReqRepeal->BankPwdFlag << endl;
	cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << pReqRepeal->SecuPwdFlag << endl;
	cout << "交易柜员 TThostFtdcOperNoType:" << pReqRepeal->OperNo << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pReqRepeal->RequestID << endl;
	// cout << "交易ID:" << pReqRepeal->TThostFtdcTIDType << endlTID;
	cout << "转账交易状态 TThostFtdcTransferStatusType:" << pReqRepeal->TransferStatus << endl;
    }
}

///期货发起查询银行余额错误回报
void CTraderSpi::OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (!IsErrorRspInfo(pRspInfo)) {
	cout << "业务功能码 TThostFtdcTradeCodeType:" << pReqQueryAccount->TradeCode << endl;
	cout << "银行代码 TThostFtdcBankIDType:" << pReqQueryAccount->BankID << endl;
	cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << pReqQueryAccount->BankBranchID << endl;
	cout << "期商代码 TThostFtdcBrokerIDType:" << pReqQueryAccount->BrokerID << endl;
	cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << pReqQueryAccount->BrokerBranchID << endl;
	cout << "交易日期 TThostFtdcTradeDateType:" << pReqQueryAccount->TradeDate << endl;
	cout << "交易时间 TThostFtdcTradeTimeType:" << pReqQueryAccount->TradeTime << endl;
	cout << "银行流水号 TThostFtdcBankSerialType:" << pReqQueryAccount->BankSerial << endl;
	cout << "交易系统日期 TThostFtdcTradeDateType:" << pReqQueryAccount->TradingDay << endl;
	cout << "银期平台消息流水号 TThostFtdcSerialType:" << pReqQueryAccount->PlateSerial << endl;
	cout << "最后分片标志 TThostFtdcLastFragmentType:" << pReqQueryAccount->LastFragment << endl;
	cout << "会话号 TThostFtdcSessionIDType:" << pReqQueryAccount->SessionID << endl;
	cout << "客户姓名 TThostFtdcIndividualNameType:" << pReqQueryAccount->CustomerName << endl;
	cout << "证件类型 TThostFtdcIdCardTypeType:" << pReqQueryAccount->IdCardType << endl;
	cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pReqQueryAccount->IdentifiedCardNo << endl;
	cout << "客户类型 TThostFtdcCustTypeType:" << pReqQueryAccount->CustType << endl;
	cout << "银行帐号 TThostFtdcBankAccountType:" << pReqQueryAccount->BankAccount << endl;
	cout << "银行密码 TThostFtdcPasswordType:" << pReqQueryAccount->BankPassWord << endl;
	cout << "投资者帐号 TThostFtdcAccountIDType:" << pReqQueryAccount->AccountID << endl;
	cout << "期货密码 TThostFtdcPasswordType:" << pReqQueryAccount->Password << endl;
	cout << "期货公司流水号 TThostFtdcFutureSerialType:" << pReqQueryAccount->FutureSerial << endl;
	cout << "安装编号 TThostFtdcInstallIDType:" << pReqQueryAccount->InstallID << endl;
	cout << "用户标识 TThostFtdcUserIDType:" << pReqQueryAccount->UserID << endl;
	cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << pReqQueryAccount->VerifyCertNoFlag << endl;
	cout << "币种代码 TThostFtdcCurrencyIDType:" << pReqQueryAccount->CurrencyID << endl;
	cout << "摘要 TThostFtdcDigestType:" << pReqQueryAccount->Digest << endl;
	cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << pReqQueryAccount->BankAccType << endl;
	cout << "渠道标志 TThostFtdcDeviceIDType:" << pReqQueryAccount->DeviceID << endl;
	cout << "期货单位帐号类型 TThostFtdcBankAccTypeType:" << pReqQueryAccount->BankSecuAccType << endl;
	cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << pReqQueryAccount->BrokerIDByBank << endl;
	cout << "期货单位帐号 TThostFtdcBankAccountType:" << pReqQueryAccount->BankSecuAcc << endl;
	cout << "银行密码标志 TThostFtdcPwdFlagType:" << pReqQueryAccount->BankPwdFlag << endl;
	cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << pReqQueryAccount->SecuPwdFlag << endl;
	cout << "交易柜员 TThostFtdcOperNoType:" << pReqQueryAccount->OperNo << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pReqQueryAccount->RequestID << endl;
	// cout << "交易ID:" << pReqQueryAccount->TThostFtdcTIDType << endlTID;
    }
}

///期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
void CTraderSpi::OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField* pRspRepeal)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "冲正时间间隔 TThostFtdcRepealTimeIntervalType:" << pRspRepeal->RepealTimeInterval << endl;
    cout << "已经冲正次数 TThostFtdcRepealedTimesType:" << pRspRepeal->RepealedTimes << endl;
    cout << "银行冲正标志 TThostFtdcBankRepealFlagType:" << pRspRepeal->BankRepealFlag << endl;
    cout << "期商冲正标志 TThostFtdcBrokerRepealFlagType:" << pRspRepeal->BrokerRepealFlag << endl;
    cout << "被冲正平台流水号 TThostFtdcPlateSerialType:" << pRspRepeal->PlateRepealSerial << endl;
    cout << "被冲正银行流水号 TThostFtdcBankSerialType:" << pRspRepeal->BankRepealSerial << endl;
    cout << "被冲正期货流水号 TThostFtdcFutureSerialType:" << pRspRepeal->FutureRepealSerial << endl;
    cout << "业务功能码 TThostFtdcTradeCodeType:" << pRspRepeal->TradeCode << endl;
    cout << "银行代码 TThostFtdcBankIDType:" << pRspRepeal->BankID << endl;
    cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << pRspRepeal->BankBranchID << endl;
    cout << "期商代码 TThostFtdcBrokerIDType:" << pRspRepeal->BrokerID << endl;
    cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << pRspRepeal->BrokerBranchID << endl;
    cout << "交易日期 TThostFtdcTradeDateType:" << pRspRepeal->TradeDate << endl;
    cout << "交易时间 TThostFtdcTradeTimeType:" << pRspRepeal->TradeTime << endl;
    cout << "银行流水号 TThostFtdcBankSerialType:" << pRspRepeal->BankSerial << endl;
    cout << "交易系统日期 TThostFtdcTradeDateType:" << pRspRepeal->TradingDay << endl;
    cout << "银期平台消息流水号 TThostFtdcSerialType:" << pRspRepeal->PlateSerial << endl;
    cout << "最后分片标志 TThostFtdcLastFragmentType:" << pRspRepeal->LastFragment << endl;
    cout << "会话号 TThostFtdcSessionIDType:" << pRspRepeal->SessionID << endl;
    cout << "客户姓名 TThostFtdcIndividualNameType:" << pRspRepeal->CustomerName << endl;
    cout << "证件类型 TThostFtdcIdCardTypeType:" << pRspRepeal->IdCardType << endl;
    cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pRspRepeal->IdentifiedCardNo << endl;
    cout << "客户类型 TThostFtdcCustTypeType:" << pRspRepeal->CustType << endl;
    cout << "银行帐号 TThostFtdcBankAccountType:" << pRspRepeal->BankAccount << endl;
    cout << "银行密码 TThostFtdcPasswordType:" << pRspRepeal->BankPassWord << endl;
    cout << "投资者帐号 TThostFtdcAccountIDType:" << pRspRepeal->AccountID << endl;
    cout << "期货密码 TThostFtdcPasswordType:" << pRspRepeal->Password << endl;
    cout << "安装编号 TThostFtdcInstallIDType:" << pRspRepeal->InstallID << endl;
    cout << "期货公司流水号 TThostFtdcFutureSerialType:" << pRspRepeal->FutureSerial << endl;
    cout << "用户标识 TThostFtdcUserIDType:" << pRspRepeal->UserID << endl;
    cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << pRspRepeal->VerifyCertNoFlag << endl;
    cout << "币种代码 TThostFtdcCurrencyIDType:" << pRspRepeal->CurrencyID << endl;
    cout << "转帐金额 TThostFtdcTradeAmountType:" << pRspRepeal->TradeAmount << endl;
    cout << "期货可取金额 TThostFtdcTradeAmountType:" << pRspRepeal->FutureFetchAmount << endl;
    cout << "费用支付标志 TThostFtdcFeePayFlagType:" << pRspRepeal->FeePayFlag << endl;
    cout << "应收客户费用 TThostFtdcCustFeeType:" << pRspRepeal->CustFee << endl;
    cout << "应收期货公司费用 TThostFtdcFutureFeeType:" << pRspRepeal->BrokerFee << endl;
    cout << "发送方给接收方的消息 TThostFtdcAddInfoType:" << pRspRepeal->Message << endl;
    cout << "摘要 TThostFtdcDigestType:" << pRspRepeal->Digest << endl;
    cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << pRspRepeal->BankAccType << endl;
    cout << "渠道标志 TThostFtdcDeviceIDType:" << pRspRepeal->DeviceID << endl;
    cout << "期货单位帐号类型 TThostFtdcBankAccTypeType:" << pRspRepeal->BankSecuAccType << endl;
    cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << pRspRepeal->BrokerIDByBank << endl;
    cout << "期货单位帐号 TThostFtdcBankAccountType:" << pRspRepeal->BankSecuAcc << endl;
    cout << "银行密码标志 TThostFtdcPwdFlagType:" << pRspRepeal->BankPwdFlag << endl;
    cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << pRspRepeal->SecuPwdFlag << endl;
    cout << "交易柜员 TThostFtdcOperNoType:" << pRspRepeal->OperNo << endl;
    cout << "请求编号 TThostFtdcRequestIDType:" << pRspRepeal->RequestID << endl;
    // cout << "交易ID:" << pRspRepeal->TThostFtdcTIDType << endlTID;
    cout << "转账交易状态 TThostFtdcTransferStatusType:" << pRspRepeal->TransferStatus << endl;
    cout << "错误代码 TThostFtdcErrorIDType:" << pRspRepeal->ErrorID << endl;
    cout << "错误信息 TThostFtdcErrorMsgType:" << pRspRepeal->ErrorMsg << endl;
}

///期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
void CTraderSpi::OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField* pRspRepeal)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "冲正时间间隔 TThostFtdcRepealTimeIntervalType:" << pRspRepeal->RepealTimeInterval << endl;
    cout << "已经冲正次数 TThostFtdcRepealedTimesType:" << pRspRepeal->RepealedTimes << endl;
    cout << "银行冲正标志 TThostFtdcBankRepealFlagType:" << pRspRepeal->BankRepealFlag << endl;
    cout << "期商冲正标志 TThostFtdcBrokerRepealFlagType:" << pRspRepeal->BrokerRepealFlag << endl;
    cout << "被冲正平台流水号 TThostFtdcPlateSerialType:" << pRspRepeal->PlateRepealSerial << endl;
    cout << "被冲正银行流水号 TThostFtdcBankSerialType:" << pRspRepeal->BankRepealSerial << endl;
    cout << "被冲正期货流水号 TThostFtdcFutureSerialType:" << pRspRepeal->FutureRepealSerial << endl;
    cout << "业务功能码 TThostFtdcTradeCodeType:" << pRspRepeal->TradeCode << endl;
    cout << "银行代码 TThostFtdcBankIDType:" << pRspRepeal->BankID << endl;
    cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << pRspRepeal->BankBranchID << endl;
    cout << "期商代码 TThostFtdcBrokerIDType:" << pRspRepeal->BrokerID << endl;
    cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << pRspRepeal->BrokerBranchID << endl;
    cout << "交易日期 TThostFtdcTradeDateType:" << pRspRepeal->TradeDate << endl;
    cout << "交易时间 TThostFtdcTradeTimeType:" << pRspRepeal->TradeTime << endl;
    cout << "银行流水号 TThostFtdcBankSerialType:" << pRspRepeal->BankSerial << endl;
    cout << "交易系统日期 TThostFtdcTradeDateType:" << pRspRepeal->TradingDay << endl;
    cout << "银期平台消息流水号 TThostFtdcSerialType:" << pRspRepeal->PlateSerial << endl;
    cout << "最后分片标志 TThostFtdcLastFragmentType:" << pRspRepeal->LastFragment << endl;
    cout << "会话号 TThostFtdcSessionIDType:" << pRspRepeal->SessionID << endl;
    cout << "客户姓名 TThostFtdcIndividualNameType:" << pRspRepeal->CustomerName << endl;
    cout << "证件类型 TThostFtdcIdCardTypeType:" << pRspRepeal->IdCardType << endl;
    cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pRspRepeal->IdentifiedCardNo << endl;
    cout << "客户类型 TThostFtdcCustTypeType:" << pRspRepeal->CustType << endl;
    cout << "银行帐号 TThostFtdcBankAccountType:" << pRspRepeal->BankAccount << endl;
    cout << "银行密码 TThostFtdcPasswordType:" << pRspRepeal->BankPassWord << endl;
    cout << "投资者帐号 TThostFtdcAccountIDType:" << pRspRepeal->AccountID << endl;
    cout << "期货密码 TThostFtdcPasswordType:" << pRspRepeal->Password << endl;
    cout << "安装编号 TThostFtdcInstallIDType:" << pRspRepeal->InstallID << endl;
    cout << "期货公司流水号 TThostFtdcFutureSerialType:" << pRspRepeal->FutureSerial << endl;
    cout << "用户标识 TThostFtdcUserIDType:" << pRspRepeal->UserID << endl;
    cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << pRspRepeal->VerifyCertNoFlag << endl;
    cout << "币种代码 TThostFtdcCurrencyIDType:" << pRspRepeal->CurrencyID << endl;
    cout << "转帐金额 TThostFtdcTradeAmountType:" << pRspRepeal->TradeAmount << endl;
    cout << "期货可取金额 TThostFtdcTradeAmountType:" << pRspRepeal->FutureFetchAmount << endl;
    cout << "费用支付标志 TThostFtdcFeePayFlagType:" << pRspRepeal->FeePayFlag << endl;
    cout << "应收客户费用 TThostFtdcCustFeeType:" << pRspRepeal->CustFee << endl;
    cout << "应收期货公司费用 TThostFtdcFutureFeeType:" << pRspRepeal->BrokerFee << endl;
    cout << "发送方给接收方的消息 TThostFtdcAddInfoType:" << pRspRepeal->Message << endl;
    cout << "摘要 TThostFtdcDigestType:" << pRspRepeal->Digest << endl;
    cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << pRspRepeal->BankAccType << endl;
    cout << "渠道标志 TThostFtdcDeviceIDType:" << pRspRepeal->DeviceID << endl;
    cout << "期货单位帐号类型 TThostFtdcBankAccTypeType:" << pRspRepeal->BankSecuAccType << endl;
    cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << pRspRepeal->BrokerIDByBank << endl;
    cout << "期货单位帐号 TThostFtdcBankAccountType:" << pRspRepeal->BankSecuAcc << endl;
    cout << "银行密码标志 TThostFtdcPwdFlagType:" << pRspRepeal->BankPwdFlag << endl;
    cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << pRspRepeal->SecuPwdFlag << endl;
    cout << "交易柜员 TThostFtdcOperNoType:" << pRspRepeal->OperNo << endl;
    cout << "请求编号 TThostFtdcRequestIDType:" << pRspRepeal->RequestID << endl;
    // cout << "交易ID:" << pRspRepeal->TThostFtdcTIDType << endlTID;
    cout << "转账交易状态 TThostFtdcTransferStatusType:" << pRspRepeal->TransferStatus << endl;
    cout << "错误代码 TThostFtdcErrorIDType:" << pRspRepeal->ErrorID << endl;
    cout << "错误信息 TThostFtdcErrorMsgType:" << pRspRepeal->ErrorMsg << endl;
}

///期货发起银行资金转期货应答
void CTraderSpi::OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "业务功能码 TThostFtdcTradeCodeType:" << pReqTransfer->TradeCode << endl;
	cout << "银行代码 TThostFtdcBankIDType:" << pReqTransfer->BankID << endl;
	cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << pReqTransfer->BankBranchID << endl;
	cout << "期商代码 TThostFtdcBrokerIDType:" << pReqTransfer->BrokerID << endl;
	cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << pReqTransfer->BrokerBranchID << endl;
	cout << "交易日期 TThostFtdcTradeDateType:" << pReqTransfer->TradeDate << endl;
	cout << "交易时间 TThostFtdcTradeTimeType:" << pReqTransfer->TradeTime << endl;
	cout << "银行流水号 TThostFtdcBankSerialType:" << pReqTransfer->BankSerial << endl;
	cout << "交易系统日期 TThostFtdcTradeDateType:" << pReqTransfer->TradingDay << endl;
	cout << "银期平台消息流水号 TThostFtdcSerialType:" << pReqTransfer->PlateSerial << endl;
	cout << "最后分片标志 TThostFtdcLastFragmentType:" << pReqTransfer->LastFragment << endl;
	cout << "会话号 TThostFtdcSessionIDType:" << pReqTransfer->SessionID << endl;
	cout << "客户姓名 TThostFtdcIndividualNameType:" << pReqTransfer->CustomerName << endl;
	cout << "证件类型 TThostFtdcIdCardTypeType:" << pReqTransfer->IdCardType << endl;
	cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pReqTransfer->IdentifiedCardNo << endl;
	cout << "客户类型 TThostFtdcCustTypeType:" << pReqTransfer->CustType << endl;
	cout << "银行帐号 TThostFtdcBankAccountType:" << pReqTransfer->BankAccount << endl;
	cout << "银行密码 TThostFtdcPasswordType:" << pReqTransfer->BankPassWord << endl;
	cout << "投资者帐号 TThostFtdcAccountIDType:" << pReqTransfer->AccountID << endl;
	cout << "期货密码 TThostFtdcPasswordType:" << pReqTransfer->Password << endl;
	cout << "安装编号 TThostFtdcInstallIDType:" << pReqTransfer->InstallID << endl;
	cout << "期货公司流水号 TThostFtdcFutureSerialType:" << pReqTransfer->FutureSerial << endl;
	cout << "用户标识 TThostFtdcUserIDType:" << pReqTransfer->UserID << endl;
	cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << pReqTransfer->VerifyCertNoFlag << endl;
	cout << "币种代码 TThostFtdcCurrencyIDType:" << pReqTransfer->CurrencyID << endl;
	cout << "转帐金额 TThostFtdcTradeAmountType:" << pReqTransfer->TradeAmount << endl;
	cout << "期货可取金额 TThostFtdcTradeAmountType:" << pReqTransfer->FutureFetchAmount << endl;
	cout << "费用支付标志 TThostFtdcFeePayFlagType:" << pReqTransfer->FeePayFlag << endl;
	cout << "应收客户费用 TThostFtdcCustFeeType:" << pReqTransfer->CustFee << endl;
	cout << "应收期货公司费用 TThostFtdcFutureFeeType:" << pReqTransfer->BrokerFee << endl;
	cout << "发送方给接收方的消息 TThostFtdcAddInfoType:" << pReqTransfer->Message << endl;
	cout << "摘要 TThostFtdcDigestType:" << pReqTransfer->Digest << endl;
	cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << pReqTransfer->BankAccType << endl;
	cout << "渠道标志 TThostFtdcDeviceIDType:" << pReqTransfer->DeviceID << endl;
	cout << "期货单位帐号类型 TThostFtdcBankAccTypeType:" << pReqTransfer->BankSecuAccType << endl;
	cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << pReqTransfer->BrokerIDByBank << endl;
	cout << "期货单位帐号 TThostFtdcBankAccountType:" << pReqTransfer->BankSecuAcc << endl;
	cout << "银行密码标志 TThostFtdcPwdFlagType:" << pReqTransfer->BankPwdFlag << endl;
	cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << pReqTransfer->SecuPwdFlag << endl;
	cout << "交易柜员 TThostFtdcOperNoType:" << pReqTransfer->OperNo << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pReqTransfer->RequestID << endl;
	// cout << "交易ID:" << pReqTransfer->TThostFtdcTIDType << endlTID;
	cout << "转账交易状态 TThostFtdcTransferStatusType:" << pReqTransfer->TransferStatus << endl;
    }
}

///期货发起期货资金转银行应答
void CTraderSpi::OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "业务功能码 TThostFtdcTradeCodeType:" << pReqTransfer->TradeCode << endl;
	cout << "银行代码 TThostFtdcBankIDType:" << pReqTransfer->BankID << endl;
	cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << pReqTransfer->BankBranchID << endl;
	cout << "期商代码 TThostFtdcBrokerIDType:" << pReqTransfer->BrokerID << endl;
	cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << pReqTransfer->BrokerBranchID << endl;
	cout << "交易日期 TThostFtdcTradeDateType:" << pReqTransfer->TradeDate << endl;
	cout << "交易时间 TThostFtdcTradeTimeType:" << pReqTransfer->TradeTime << endl;
	cout << "银行流水号 TThostFtdcBankSerialType:" << pReqTransfer->BankSerial << endl;
	cout << "交易系统日期 TThostFtdcTradeDateType:" << pReqTransfer->TradingDay << endl;
	cout << "银期平台消息流水号 TThostFtdcSerialType:" << pReqTransfer->PlateSerial << endl;
	cout << "最后分片标志 TThostFtdcLastFragmentType:" << pReqTransfer->LastFragment << endl;
	cout << "会话号 TThostFtdcSessionIDType:" << pReqTransfer->SessionID << endl;
	cout << "客户姓名 TThostFtdcIndividualNameType:" << pReqTransfer->CustomerName << endl;
	cout << "证件类型 TThostFtdcIdCardTypeType:" << pReqTransfer->IdCardType << endl;
	cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pReqTransfer->IdentifiedCardNo << endl;
	cout << "客户类型 TThostFtdcCustTypeType:" << pReqTransfer->CustType << endl;
	cout << "银行帐号 TThostFtdcBankAccountType:" << pReqTransfer->BankAccount << endl;
	cout << "银行密码 TThostFtdcPasswordType:" << pReqTransfer->BankPassWord << endl;
	cout << "投资者帐号 TThostFtdcAccountIDType:" << pReqTransfer->AccountID << endl;
	cout << "期货密码 TThostFtdcPasswordType:" << pReqTransfer->Password << endl;
	cout << "安装编号 TThostFtdcInstallIDType:" << pReqTransfer->InstallID << endl;
	cout << "期货公司流水号 TThostFtdcFutureSerialType:" << pReqTransfer->FutureSerial << endl;
	cout << "用户标识 TThostFtdcUserIDType:" << pReqTransfer->UserID << endl;
	cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << pReqTransfer->VerifyCertNoFlag << endl;
	cout << "币种代码 TThostFtdcCurrencyIDType:" << pReqTransfer->CurrencyID << endl;
	cout << "转帐金额 TThostFtdcTradeAmountType:" << pReqTransfer->TradeAmount << endl;
	cout << "期货可取金额 TThostFtdcTradeAmountType:" << pReqTransfer->FutureFetchAmount << endl;
	cout << "费用支付标志 TThostFtdcFeePayFlagType:" << pReqTransfer->FeePayFlag << endl;
	cout << "应收客户费用 TThostFtdcCustFeeType:" << pReqTransfer->CustFee << endl;
	cout << "应收期货公司费用 TThostFtdcFutureFeeType:" << pReqTransfer->BrokerFee << endl;
	cout << "发送方给接收方的消息 TThostFtdcAddInfoType:" << pReqTransfer->Message << endl;
	cout << "摘要 TThostFtdcDigestType:" << pReqTransfer->Digest << endl;
	cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << pReqTransfer->BankAccType << endl;
	cout << "渠道标志 TThostFtdcDeviceIDType:" << pReqTransfer->DeviceID << endl;
	cout << "期货单位帐号类型 TThostFtdcBankAccTypeType:" << pReqTransfer->BankSecuAccType << endl;
	cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << pReqTransfer->BrokerIDByBank << endl;
	cout << "期货单位帐号 TThostFtdcBankAccountType:" << pReqTransfer->BankSecuAcc << endl;
	cout << "银行密码标志 TThostFtdcPwdFlagType:" << pReqTransfer->BankPwdFlag << endl;
	cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << pReqTransfer->SecuPwdFlag << endl;
	cout << "交易柜员 TThostFtdcOperNoType:" << pReqTransfer->OperNo << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pReqTransfer->RequestID << endl;
	// cout << "交易ID:" << pReqTransfer->TThostFtdcTIDType << endlTID;
	cout << "转账交易状态 TThostFtdcTransferStatusType:" << pReqTransfer->TransferStatus << endl;
    }
}

///期货发起查询银行余额应答
void CTraderSpi::OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
	cout << "业务功能码 TThostFtdcTradeCodeType:" << pReqQueryAccount->TradeCode << endl;
	cout << "银行代码 TThostFtdcBankIDType:" << pReqQueryAccount->BankID << endl;
	cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << pReqQueryAccount->BankBranchID << endl;
	cout << "期商代码 TThostFtdcBrokerIDType:" << pReqQueryAccount->BrokerID << endl;
	cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << pReqQueryAccount->BrokerBranchID << endl;
	cout << "交易日期 TThostFtdcTradeDateType:" << pReqQueryAccount->TradeDate << endl;
	cout << "交易时间 TThostFtdcTradeTimeType:" << pReqQueryAccount->TradeTime << endl;
	cout << "银行流水号 TThostFtdcBankSerialType:" << pReqQueryAccount->BankSerial << endl;
	cout << "交易系统日期 TThostFtdcTradeDateType:" << pReqQueryAccount->TradingDay << endl;
	cout << "银期平台消息流水号 TThostFtdcSerialType:" << pReqQueryAccount->PlateSerial << endl;
	cout << "最后分片标志 TThostFtdcLastFragmentType:" << pReqQueryAccount->LastFragment << endl;
	cout << "会话号 TThostFtdcSessionIDType:" << pReqQueryAccount->SessionID << endl;
	cout << "客户姓名 TThostFtdcIndividualNameType:" << pReqQueryAccount->CustomerName << endl;
	cout << "证件类型 TThostFtdcIdCardTypeType:" << pReqQueryAccount->IdCardType << endl;
	cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pReqQueryAccount->IdentifiedCardNo << endl;
	cout << "客户类型 TThostFtdcCustTypeType:" << pReqQueryAccount->CustType << endl;
	cout << "银行帐号 TThostFtdcBankAccountType:" << pReqQueryAccount->BankAccount << endl;
	cout << "银行密码 TThostFtdcPasswordType:" << pReqQueryAccount->BankPassWord << endl;
	cout << "投资者帐号 TThostFtdcAccountIDType:" << pReqQueryAccount->AccountID << endl;
	cout << "期货密码 TThostFtdcPasswordType:" << pReqQueryAccount->Password << endl;
	cout << "期货公司流水号 TThostFtdcFutureSerialType:" << pReqQueryAccount->FutureSerial << endl;
	cout << "安装编号 TThostFtdcInstallIDType:" << pReqQueryAccount->InstallID << endl;
	cout << "用户标识 TThostFtdcUserIDType:" << pReqQueryAccount->UserID << endl;
	cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << pReqQueryAccount->VerifyCertNoFlag << endl;
	cout << "币种代码 TThostFtdcCurrencyIDType:" << pReqQueryAccount->CurrencyID << endl;
	cout << "摘要 TThostFtdcDigestType:" << pReqQueryAccount->Digest << endl;
	cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << pReqQueryAccount->BankAccType << endl;
	cout << "渠道标志 TThostFtdcDeviceIDType:" << pReqQueryAccount->DeviceID << endl;
	cout << "期货单位帐号类型 TThostFtdcBankAccTypeType:" << pReqQueryAccount->BankSecuAccType << endl;
	cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << pReqQueryAccount->BrokerIDByBank << endl;
	cout << "期货单位帐号 TThostFtdcBankAccountType:" << pReqQueryAccount->BankSecuAcc << endl;
	cout << "银行密码标志 TThostFtdcPwdFlagType:" << pReqQueryAccount->BankPwdFlag << endl;
	cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << pReqQueryAccount->SecuPwdFlag << endl;
	cout << "交易柜员 TThostFtdcOperNoType:" << pReqQueryAccount->OperNo << endl;
	cout << "请求编号 TThostFtdcRequestIDType:" << pReqQueryAccount->RequestID << endl;
	// cout << "交易ID:" << pReqQueryAccount->TThostFtdcTIDType << endlTID;
    }
}

///银行发起银期开户通知
void CTraderSpi::OnRtnOpenAccountByBank(CThostFtdcOpenAccountField* pOpenAccount)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "业务功能码 TThostFtdcTradeCodeType:" << pOpenAccount->TradeCode << endl;
    cout << "银行代码 TThostFtdcBankIDType:" << pOpenAccount->BankID << endl;
    cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << pOpenAccount->BankBranchID << endl;
    cout << "期商代码 TThostFtdcBrokerIDType:" << pOpenAccount->BrokerID << endl;
    cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << pOpenAccount->BrokerBranchID << endl;
    cout << "交易日期 TThostFtdcTradeDateType:" << pOpenAccount->TradeDate << endl;
    cout << "交易时间 TThostFtdcTradeTimeType:" << pOpenAccount->TradeTime << endl;
    cout << "银行流水号 TThostFtdcBankSerialType:" << pOpenAccount->BankSerial << endl;
    cout << "交易系统日期 TThostFtdcTradeDateType:" << pOpenAccount->TradingDay << endl;
    cout << "银期平台消息流水号 TThostFtdcSerialType:" << pOpenAccount->PlateSerial << endl;
    cout << "最后分片标志 TThostFtdcLastFragmentType:" << pOpenAccount->LastFragment << endl;
    cout << "会话号 TThostFtdcSessionIDType:" << pOpenAccount->SessionID << endl;
    cout << "客户姓名 TThostFtdcIndividualNameType:" << pOpenAccount->CustomerName << endl;
    cout << "证件类型 TThostFtdcIdCardTypeType:" << pOpenAccount->IdCardType << endl;
    cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pOpenAccount->IdentifiedCardNo << endl;
    cout << "性别 TThostFtdcGenderType:" << pOpenAccount->Gender << endl;
    cout << "国家代码 TThostFtdcCountryCodeType:" << pOpenAccount->CountryCode << endl;
    cout << "客户类型 TThostFtdcCustTypeType:" << pOpenAccount->CustType << endl;
    cout << "地址 TThostFtdcAddressType:" << pOpenAccount->Address << endl;
    cout << "邮编 TThostFtdcZipCodeType:" << pOpenAccount->ZipCode << endl;
    cout << "电话号码 TThostFtdcTelephoneType:" << pOpenAccount->Telephone << endl;
    cout << "手机 TThostFtdcMobilePhoneType:" << pOpenAccount->MobilePhone << endl;
    cout << "传真 TThostFtdcFaxType:" << pOpenAccount->Fax << endl;
    cout << "电子邮件 TThostFtdcEMailType:" << pOpenAccount->EMail << endl;
    cout << "资金账户状态 TThostFtdcMoneyAccountStatusType:" << pOpenAccount->MoneyAccountStatus << endl;
    cout << "银行帐号 TThostFtdcBankAccountType:" << pOpenAccount->BankAccount << endl;
    cout << "银行密码 TThostFtdcPasswordType:" << pOpenAccount->BankPassWord << endl;
    cout << "投资者帐号 TThostFtdcAccountIDType:" << pOpenAccount->AccountID << endl;
    cout << "期货密码 TThostFtdcPasswordType:" << pOpenAccount->Password << endl;
    cout << "安装编号 TThostFtdcInstallIDType:" << pOpenAccount->InstallID << endl;
    cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << pOpenAccount->VerifyCertNoFlag << endl;
    cout << "币种代码 TThostFtdcCurrencyIDType:" << pOpenAccount->CurrencyID << endl;
    cout << "汇钞标志 TThostFtdcCashExchangeCodeType:" << pOpenAccount->CashExchangeCode << endl;
    cout << "摘要 TThostFtdcDigestType:" << pOpenAccount->Digest << endl;
    cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << pOpenAccount->BankAccType << endl;
    cout << "渠道标志 TThostFtdcDeviceIDType:" << pOpenAccount->DeviceID << endl;
    cout << "期货单位帐号类型 TThostFtdcBankAccTypeType:" << pOpenAccount->BankSecuAccType << endl;
    cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << pOpenAccount->BrokerIDByBank << endl;
    cout << "期货单位帐号 TThostFtdcBankAccountType:" << pOpenAccount->BankSecuAcc << endl;
    cout << "银行密码标志 TThostFtdcPwdFlagType:" << pOpenAccount->BankPwdFlag << endl;
    cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << pOpenAccount->SecuPwdFlag << endl;
    cout << "交易柜员 TThostFtdcOperNoType:" << pOpenAccount->OperNo << endl;
    // cout << "交易ID:" << pOpenAccount->TThostFtdcTIDType << endlTID;
    cout << "用户标识 TThostFtdcUserIDType:" << pOpenAccount->UserID << endl;
    cout << "错误代码 TThostFtdcErrorIDType:" << pOpenAccount->ErrorID << endl;
    cout << "错误信息 TThostFtdcErrorMsgType:" << pOpenAccount->ErrorMsg << endl;
}

///银行发起银期销户通知
void CTraderSpi::OnRtnCancelAccountByBank(CThostFtdcCancelAccountField* pCancelAccount)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "业务功能码 TThostFtdcTradeCodeType:" << pCancelAccount->TradeCode << endl;
    cout << "银行代码 TThostFtdcBankIDType:" << pCancelAccount->BankID << endl;
    cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << pCancelAccount->BankBranchID << endl;
    cout << "期商代码 TThostFtdcBrokerIDType:" << pCancelAccount->BrokerID << endl;
    cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << pCancelAccount->BrokerBranchID << endl;
    cout << "交易日期 TThostFtdcTradeDateType:" << pCancelAccount->TradeDate << endl;
    cout << "交易时间 TThostFtdcTradeTimeType:" << pCancelAccount->TradeTime << endl;
    cout << "银行流水号 TThostFtdcBankSerialType:" << pCancelAccount->BankSerial << endl;
    cout << "交易系统日期 TThostFtdcTradeDateType:" << pCancelAccount->TradingDay << endl;
    cout << "银期平台消息流水号 TThostFtdcSerialType:" << pCancelAccount->PlateSerial << endl;
    cout << "最后分片标志 TThostFtdcLastFragmentType:" << pCancelAccount->LastFragment << endl;
    cout << "会话号 TThostFtdcSessionIDType:" << pCancelAccount->SessionID << endl;
    cout << "客户姓名 TThostFtdcIndividualNameType:" << pCancelAccount->CustomerName << endl;
    cout << "证件类型 TThostFtdcIdCardTypeType:" << pCancelAccount->IdCardType << endl;
    cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pCancelAccount->IdentifiedCardNo << endl;
    cout << "性别 TThostFtdcGenderType:" << pCancelAccount->Gender << endl;
    cout << "国家代码 TThostFtdcCountryCodeType:" << pCancelAccount->CountryCode << endl;
    cout << "客户类型 TThostFtdcCustTypeType:" << pCancelAccount->CustType << endl;
    cout << "地址 TThostFtdcAddressType:" << pCancelAccount->Address << endl;
    cout << "邮编 TThostFtdcZipCodeType:" << pCancelAccount->ZipCode << endl;
    cout << "电话号码 TThostFtdcTelephoneType:" << pCancelAccount->Telephone << endl;
    cout << "手机 TThostFtdcMobilePhoneType:" << pCancelAccount->MobilePhone << endl;
    cout << "传真 TThostFtdcFaxType:" << pCancelAccount->Fax << endl;
    cout << "电子邮件 TThostFtdcEMailType:" << pCancelAccount->EMail << endl;
    cout << "资金账户状态 TThostFtdcMoneyAccountStatusType:" << pCancelAccount->MoneyAccountStatus << endl;
    cout << "银行帐号 TThostFtdcBankAccountType:" << pCancelAccount->BankAccount << endl;
    cout << "银行密码 TThostFtdcPasswordType:" << pCancelAccount->BankPassWord << endl;
    cout << "投资者帐号 TThostFtdcAccountIDType:" << pCancelAccount->AccountID << endl;
    cout << "期货密码 TThostFtdcPasswordType:" << pCancelAccount->Password << endl;
    cout << "安装编号 TThostFtdcInstallIDType:" << pCancelAccount->InstallID << endl;
    cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << pCancelAccount->VerifyCertNoFlag << endl;
    cout << "币种代码 TThostFtdcCurrencyIDType:" << pCancelAccount->CurrencyID << endl;
    cout << "汇钞标志 TThostFtdcCashExchangeCodeType:" << pCancelAccount->CashExchangeCode << endl;
    cout << "摘要 TThostFtdcDigestType:" << pCancelAccount->Digest << endl;
    cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << pCancelAccount->BankAccType << endl;
    cout << "渠道标志 TThostFtdcDeviceIDType:" << pCancelAccount->DeviceID << endl;
    cout << "期货单位帐号类型 TThostFtdcBankAccTypeType:" << pCancelAccount->BankSecuAccType << endl;
    cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << pCancelAccount->BrokerIDByBank << endl;
    cout << "期货单位帐号 TThostFtdcBankAccountType:" << pCancelAccount->BankSecuAcc << endl;
    cout << "银行密码标志 TThostFtdcPwdFlagType:" << pCancelAccount->BankPwdFlag << endl;
    cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << pCancelAccount->SecuPwdFlag << endl;
    cout << "交易柜员 TThostFtdcOperNoType:" << pCancelAccount->OperNo << endl;
    // cout << "交易ID:" << pCancelAccount->TThostFtdcTIDType << endlTID;
    cout << "用户标识 TThostFtdcUserIDType:" << pCancelAccount->UserID << endl;
    cout << "错误代码 TThostFtdcErrorIDType:" << pCancelAccount->ErrorID << endl;
    cout << "错误信息 TThostFtdcErrorMsgType:" << pCancelAccount->ErrorMsg << endl;
}

///银行发起变更银行账号通知
void CTraderSpi::OnRtnChangeAccountByBank(CThostFtdcChangeAccountField* pChangeAccount)
{
    cout << "--->>> " << __FUNCTION__ << endl;
    cout << "业务功能码 TThostFtdcTradeCodeType:" << pChangeAccount->TradeCode << endl;
    cout << "银行代码 TThostFtdcBankIDType:" << pChangeAccount->BankID << endl;
    cout << "银行分支机构代码 TThostFtdcBankBrchIDType:" << pChangeAccount->BankBranchID << endl;
    cout << "期商代码 TThostFtdcBrokerIDType:" << pChangeAccount->BrokerID << endl;
    cout << "期商分支机构代码 TThostFtdcFutureBranchIDType:" << pChangeAccount->BrokerBranchID << endl;
    cout << "交易日期 TThostFtdcTradeDateType:" << pChangeAccount->TradeDate << endl;
    cout << "交易时间 TThostFtdcTradeTimeType:" << pChangeAccount->TradeTime << endl;
    cout << "银行流水号 TThostFtdcBankSerialType:" << pChangeAccount->BankSerial << endl;
    cout << "交易系统日期 TThostFtdcTradeDateType:" << pChangeAccount->TradingDay << endl;
    cout << "银期平台消息流水号 TThostFtdcSerialType:" << pChangeAccount->PlateSerial << endl;
    cout << "最后分片标志 TThostFtdcLastFragmentType:" << pChangeAccount->LastFragment << endl;
    cout << "会话号 TThostFtdcSessionIDType:" << pChangeAccount->SessionID << endl;
    cout << "客户姓名 TThostFtdcIndividualNameType:" << pChangeAccount->CustomerName << endl;
    cout << "证件类型 TThostFtdcIdCardTypeType:" << pChangeAccount->IdCardType << endl;
    cout << "证件号码 TThostFtdcIdentifiedCardNoType:" << pChangeAccount->IdentifiedCardNo << endl;
    cout << "性别 TThostFtdcGenderType:" << pChangeAccount->Gender << endl;
    cout << "国家代码 TThostFtdcCountryCodeType:" << pChangeAccount->CountryCode << endl;
    cout << "客户类型 TThostFtdcCustTypeType:" << pChangeAccount->CustType << endl;
    cout << "地址 TThostFtdcAddressType:" << pChangeAccount->Address << endl;
    cout << "邮编 TThostFtdcZipCodeType:" << pChangeAccount->ZipCode << endl;
    cout << "电话号码 TThostFtdcTelephoneType:" << pChangeAccount->Telephone << endl;
    cout << "手机 TThostFtdcMobilePhoneType:" << pChangeAccount->MobilePhone << endl;
    cout << "传真 TThostFtdcFaxType:" << pChangeAccount->Fax << endl;
    cout << "电子邮件 TThostFtdcEMailType:" << pChangeAccount->EMail << endl;
    cout << "资金账户状态 TThostFtdcMoneyAccountStatusType:" << pChangeAccount->MoneyAccountStatus << endl;
    cout << "银行帐号 TThostFtdcBankAccountType:" << pChangeAccount->BankAccount << endl;
    cout << "银行密码 TThostFtdcPasswordType:" << pChangeAccount->BankPassWord << endl;
    cout << "新银行帐号 TThostFtdcBankAccountType:" << pChangeAccount->NewBankAccount << endl;
    cout << "新银行密码 TThostFtdcPasswordType:" << pChangeAccount->NewBankPassWord << endl;
    cout << "投资者帐号 TThostFtdcAccountIDType:" << pChangeAccount->AccountID << endl;
    cout << "期货密码 TThostFtdcPasswordType:" << pChangeAccount->Password << endl;
    cout << "银行帐号类型 TThostFtdcBankAccTypeType:" << pChangeAccount->BankAccType << endl;
    cout << "安装编号 TThostFtdcInstallIDType:" << pChangeAccount->InstallID << endl;
    cout << "验证客户证件号码标志 TThostFtdcYesNoIndicatorType:" << pChangeAccount->VerifyCertNoFlag << endl;
    cout << "币种代码 TThostFtdcCurrencyIDType:" << pChangeAccount->CurrencyID << endl;
    cout << "期货公司银行编码 TThostFtdcBankCodingForFutureType:" << pChangeAccount->BrokerIDByBank << endl;
    cout << "银行密码标志 TThostFtdcPwdFlagType:" << pChangeAccount->BankPwdFlag << endl;
    cout << "期货资金密码核对标志 TThostFtdcPwdFlagType:" << pChangeAccount->SecuPwdFlag << endl;
    // cout << "交易ID:" << pChangeAccount->TThostFtdcTIDType << endlTID;
    cout << "摘要 TThostFtdcDigestType:" << pChangeAccount->Digest << endl;
    cout << "错误代码 TThostFtdcErrorIDType:" << pChangeAccount->ErrorID << endl;
    cout << "错误信息 TThostFtdcErrorMsgType:" << pChangeAccount->ErrorMsg << endl;
}

