virtual int ReqUserLogin(CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcReqUserLoginField req
CThostFtdcReqUserLoginField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.tradingday, req.tradingday.c_str());
strcpy(myreq.brokerid, req.brokerid.c_str());
strcpy(myreq.userid, req.userid.c_str());
strcpy(myreq.password, req.password.c_str());
strcpy(myreq.userproductinfo, req.userproductinfo.c_str());
strcpy(myreq.interfaceproductinfo, req.interfaceproductinfo.c_str());
strcpy(myreq.protocolinfo, req.protocolinfo.c_str());
strcpy(myreq.macaddress, req.macaddress.c_str());
strcpy(myreq.onetimepassword, req.onetimepassword.c_str());
strcpy(myreq.clientipaddress, req.clientipaddress.c_str());
}
virtual int ReqUserLogout(CThostFtdcUserLogoutField* pUserLogout, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcUserLogoutField req
CThostFtdcUserLogoutField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.UserID, req.userid.c_str());
}
virtual int ReqAuthenticate(CThostFtdcReqAuthenticateField* pReqAuthenticateField, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcReqAuthenticateField req
CThostFtdcReqAuthenticateField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.UserID, req.userid.c_str());
strcpy(myreq.UserProductInfo, req.userproductinfo.c_str());
strcpy(myreq.AuthCode, req.authcode.c_str());
}
virtual int ReqUserLogin(CThostFtdcReqUserLoginField* pReqUserLoginField, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcReqUserLoginField req
CThostFtdcReqUserLoginField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.tradingday, req.tradingday.c_str());
strcpy(myreq.brokerid, req.brokerid.c_str());
strcpy(myreq.userid, req.userid.c_str());
strcpy(myreq.password, req.password.c_str());
strcpy(myreq.userproductinfo, req.userproductinfo.c_str());
strcpy(myreq.interfaceproductinfo, req.interfaceproductinfo.c_str());
strcpy(myreq.protocolinfo, req.protocolinfo.c_str());
strcpy(myreq.macaddress, req.macaddress.c_str());
strcpy(myreq.onetimepassword, req.onetimepassword.c_str());
strcpy(myreq.clientipaddress, req.clientipaddress.c_str());
}
virtual int ReqUserLogout(CThostFtdcUserLogoutField* pUserLogout, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcUserLogoutField req
CThostFtdcUserLogoutField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.UserID, req.userid.c_str());
}
virtual int ReqUserPasswordUpdate(CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcUserPasswordUpdateField req
CThostFtdcUserPasswordUpdateField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.UserID, req.userid.c_str());
strcpy(myreq.OldPassword, req.oldpassword.c_str());
strcpy(myreq.NewPassword, req.newpassword.c_str());
}
virtual int ReqTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcTradingAccountPasswordUpdateField req
CThostFtdcTradingAccountPasswordUpdateField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.AccountID, req.accountid.c_str());
strcpy(myreq.OldPassword, req.oldpassword.c_str());
strcpy(myreq.NewPassword, req.newpassword.c_str());
strcpy(myreq.CurrencyID, req.currencyid.c_str());
}
virtual int ReqOrderInsert(CThostFtdcInputOrderField* pInputOrder, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcInputOrderField req
CThostFtdcInputOrderField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.OrderRef, req.orderref.c_str());
strcpy(myreq.UserID, req.userid.c_str());
strcpy(myreq.OrderPriceType, req.orderpricetype.c_str());
strcpy(myreq.Direction, req.direction.c_str());
strcpy(myreq.CombOffsetFlag, req.comboffsetflag.c_str());
strcpy(myreq.CombHedgeFlag, req.combhedgeflag.c_str());
myreq.LimitPrice = req.limitprice();
myreq.VolumeTotalOriginal = req.volumetotaloriginal();
strcpy(myreq.TimeCondition, req.timecondition.c_str());
strcpy(myreq.GTDDate, req.gtddate.c_str());
strcpy(myreq.VolumeCondition, req.volumecondition.c_str());
myreq.MinVolume = req.minvolume();
strcpy(myreq.ContingentCondition, req.contingentcondition.c_str());
myreq.StopPrice = req.stopprice();
strcpy(myreq.ForceCloseReason, req.forceclosereason.c_str());
myreq.IsAutoSuspend = req.isautosuspend();
strcpy(myreq.BusinessUnit, req.businessunit.c_str());
myreq.RequestID = req.requestid();
myreq.UserForceClose = req.userforceclose();
myreq.IsSwapOrder = req.isswaporder();
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
}
virtual int ReqParkedOrderInsert(CThostFtdcParkedOrderField* pParkedOrder, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcParkedOrderField req
CThostFtdcParkedOrderField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.OrderRef, req.orderref.c_str());
strcpy(myreq.UserID, req.userid.c_str());
strcpy(myreq.OrderPriceType, req.orderpricetype.c_str());
strcpy(myreq.Direction, req.direction.c_str());
strcpy(myreq.CombOffsetFlag, req.comboffsetflag.c_str());
strcpy(myreq.CombHedgeFlag, req.combhedgeflag.c_str());
myreq.LimitPrice = req.limitprice();
myreq.VolumeTotalOriginal = req.volumetotaloriginal();
strcpy(myreq.TimeCondition, req.timecondition.c_str());
strcpy(myreq.GTDDate, req.gtddate.c_str());
strcpy(myreq.VolumeCondition, req.volumecondition.c_str());
myreq.MinVolume = req.minvolume();
strcpy(myreq.ContingentCondition, req.contingentcondition.c_str());
myreq.StopPrice = req.stopprice();
strcpy(myreq.ForceCloseReason, req.forceclosereason.c_str());
myreq.IsAutoSuspend = req.isautosuspend();
strcpy(myreq.BusinessUnit, req.businessunit.c_str());
myreq.RequestID = req.requestid();
myreq.UserForceClose = req.userforceclose();
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
strcpy(myreq.ParkedOrderID, req.parkedorderid.c_str());
strcpy(myreq.UserType, req.usertype.c_str());
strcpy(myreq.Status, req.status.c_str());
myreq.ErrorID = req.errorid();
strcpy(myreq.ErrorMsg, req.errormsg.c_str());
myreq.IsSwapOrder = req.isswaporder();
}
virtual int ReqParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcParkedOrderActionField req
CThostFtdcParkedOrderActionField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
myreq.OrderActionRef = req.orderactionref();
strcpy(myreq.OrderRef, req.orderref.c_str());
myreq.RequestID = req.requestid();
myreq.FrontID = req.frontid();
myreq.SessionID = req.sessionid();
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
strcpy(myreq.OrderSysID, req.ordersysid.c_str());
strcpy(myreq.ActionFlag, req.actionflag.c_str());
myreq.LimitPrice = req.limitprice();
myreq.VolumeChange = req.volumechange();
strcpy(myreq.UserID, req.userid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.ParkedOrderActionID, req.parkedorderactionid.c_str());
strcpy(myreq.UserType, req.usertype.c_str());
strcpy(myreq.Status, req.status.c_str());
myreq.ErrorID = req.errorid();
strcpy(myreq.ErrorMsg, req.errormsg.c_str());
}
virtual int ReqOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcInputOrderActionField req
CThostFtdcInputOrderActionField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
myreq.OrderActionRef = req.orderactionref();
strcpy(myreq.OrderRef, req.orderref.c_str());
myreq.RequestID = req.requestid();
myreq.FrontID = req.frontid();
myreq.SessionID = req.sessionid();
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
strcpy(myreq.OrderSysID, req.ordersysid.c_str());
strcpy(myreq.ActionFlag, req.actionflag.c_str());
myreq.LimitPrice = req.limitprice();
myreq.VolumeChange = req.volumechange();
strcpy(myreq.UserID, req.userid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
}
virtual int ReqQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField* pQueryMaxOrderVolume, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQueryMaxOrderVolumeField req
CThostFtdcQueryMaxOrderVolumeField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.Direction, req.direction.c_str());
strcpy(myreq.OffsetFlag, req.offsetflag.c_str());
strcpy(myreq.HedgeFlag, req.hedgeflag.c_str());
myreq.MaxVolume = req.maxvolume();
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
}
virtual int ReqSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcSettlementInfoConfirmField req
CThostFtdcSettlementInfoConfirmField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.ConfirmDate, req.confirmdate.c_str());
strcpy(myreq.ConfirmTime, req.confirmtime.c_str());
}
virtual int ReqRemoveParkedOrder(CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcRemoveParkedOrderField req
CThostFtdcRemoveParkedOrderField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.ParkedOrderID, req.parkedorderid.c_str());
}
virtual int ReqRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcRemoveParkedOrderActionField req
CThostFtdcRemoveParkedOrderActionField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.ParkedOrderActionID, req.parkedorderactionid.c_str());
}
virtual int ReqExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcInputExecOrderField req
CThostFtdcInputExecOrderField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.ExecOrderRef, req.execorderref.c_str());
strcpy(myreq.UserID, req.userid.c_str());
myreq.Volume = req.volume();
myreq.RequestID = req.requestid();
strcpy(myreq.BusinessUnit, req.businessunit.c_str());
strcpy(myreq.OffsetFlag, req.offsetflag.c_str());
strcpy(myreq.HedgeFlag, req.hedgeflag.c_str());
strcpy(myreq.ActionType, req.actiontype.c_str());
strcpy(myreq.PosiDirection, req.posidirection.c_str());
strcpy(myreq.ReservePositionFlag, req.reservepositionflag.c_str());
strcpy(myreq.CloseFlag, req.closeflag.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
}
virtual int ReqExecOrderAction(CThostFtdcInputExecOrderActionField* pInputExecOrderAction, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcInputExecOrderActionField req
CThostFtdcInputExecOrderActionField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
myreq.ExecOrderActionRef = req.execorderactionref();
strcpy(myreq.ExecOrderRef, req.execorderref.c_str());
myreq.RequestID = req.requestid();
myreq.FrontID = req.frontid();
myreq.SessionID = req.sessionid();
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
strcpy(myreq.ExecOrderSysID, req.execordersysid.c_str());
strcpy(myreq.ActionFlag, req.actionflag.c_str());
strcpy(myreq.UserID, req.userid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
}
virtual int ReqForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcInputForQuoteField req
CThostFtdcInputForQuoteField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.ForQuoteRef, req.forquoteref.c_str());
strcpy(myreq.UserID, req.userid.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
}
virtual int ReqQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcInputQuoteField req
CThostFtdcInputQuoteField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.QuoteRef, req.quoteref.c_str());
strcpy(myreq.UserID, req.userid.c_str());
myreq.AskPrice = req.askprice();
myreq.BidPrice = req.bidprice();
myreq.AskVolume = req.askvolume();
myreq.BidVolume = req.bidvolume();
myreq.RequestID = req.requestid();
strcpy(myreq.BusinessUnit, req.businessunit.c_str());
strcpy(myreq.AskOffsetFlag, req.askoffsetflag.c_str());
strcpy(myreq.BidOffsetFlag, req.bidoffsetflag.c_str());
strcpy(myreq.AskHedgeFlag, req.askhedgeflag.c_str());
strcpy(myreq.BidHedgeFlag, req.bidhedgeflag.c_str());
strcpy(myreq.AskOrderRef, req.askorderref.c_str());
strcpy(myreq.BidOrderRef, req.bidorderref.c_str());
strcpy(myreq.ForQuoteSysID, req.forquotesysid.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
}
virtual int ReqQuoteAction(CThostFtdcInputQuoteActionField* pInputQuoteAction, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcInputQuoteActionField req
CThostFtdcInputQuoteActionField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
myreq.QuoteActionRef = req.quoteactionref();
strcpy(myreq.QuoteRef, req.quoteref.c_str());
myreq.RequestID = req.requestid();
myreq.FrontID = req.frontid();
myreq.SessionID = req.sessionid();
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
strcpy(myreq.QuoteSysID, req.quotesysid.c_str());
strcpy(myreq.ActionFlag, req.actionflag.c_str());
strcpy(myreq.UserID, req.userid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
}
virtual int ReqLockInsert(CThostFtdcInputLockField* pInputLock, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcInputLockField req
CThostFtdcInputLockField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.LockRef, req.lockref.c_str());
strcpy(myreq.UserID, req.userid.c_str());
myreq.Volume = req.volume();
myreq.RequestID = req.requestid();
strcpy(myreq.BusinessUnit, req.businessunit.c_str());
strcpy(myreq.LockType, req.locktype.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
}
virtual int ReqCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcInputCombActionField req
CThostFtdcInputCombActionField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.CombActionRef, req.combactionref.c_str());
strcpy(myreq.UserID, req.userid.c_str());
strcpy(myreq.Direction, req.direction.c_str());
myreq.Volume = req.volume();
strcpy(myreq.CombDirection, req.combdirection.c_str());
strcpy(myreq.HedgeFlag, req.hedgeflag.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
}
virtual int ReqQryOrder(CThostFtdcQryOrderField* pQryOrder, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryOrderField req
CThostFtdcQryOrderField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
strcpy(myreq.OrderSysID, req.ordersysid.c_str());
strcpy(myreq.InsertTimeStart, req.inserttimestart.c_str());
strcpy(myreq.InsertTimeEnd, req.inserttimeend.c_str());
}
virtual int ReqQryTrade(CThostFtdcQryTradeField* pQryTrade, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryTradeField req
CThostFtdcQryTradeField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
strcpy(myreq.TradeID, req.tradeid.c_str());
strcpy(myreq.TradeTimeStart, req.tradetimestart.c_str());
strcpy(myreq.TradeTimeEnd, req.tradetimeend.c_str());
}
virtual int ReqQryInvestorPosition(CThostFtdcQryInvestorPositionField* pQryInvestorPosition, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryInvestorPositionField req
CThostFtdcQryInvestorPositionField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
}
virtual int ReqQryTradingAccount(CThostFtdcQryTradingAccountField* pQryTradingAccount, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryTradingAccountField req
CThostFtdcQryTradingAccountField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.CurrencyID, req.currencyid.c_str());
strcpy(myreq.BizType, req.biztype.c_str());
}
virtual int ReqQryInvestor(CThostFtdcQryInvestorField* pQryInvestor, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryInvestorField req
CThostFtdcQryInvestorField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
}
virtual int ReqQryTradingCode(CThostFtdcQryTradingCodeField* pQryTradingCode, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryTradingCodeField req
CThostFtdcQryTradingCodeField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
strcpy(myreq.ClientID, req.clientid.c_str());
strcpy(myreq.ClientIDType, req.clientidtype.c_str());
}
virtual int ReqQryInstrumentMarginRate(CThostFtdcQryInstrumentMarginRateField* pQryInstrumentMarginRate, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryInstrumentMarginRateField req
CThostFtdcQryInstrumentMarginRateField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.HedgeFlag, req.hedgeflag.c_str());
}
virtual int ReqQryInstrumentCommissionRate(CThostFtdcQryInstrumentCommissionRateField* pQryInstrumentCommissionRate, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryInstrumentCommissionRateField req
CThostFtdcQryInstrumentCommissionRateField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
}
virtual int ReqQryExchange(CThostFtdcQryExchangeField* pQryExchange, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryExchangeField req
CThostFtdcQryExchangeField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
}
virtual int ReqQryProduct(CThostFtdcQryProductField* pQryProduct, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryProductField req
CThostFtdcQryProductField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.ProductID, req.productid.c_str());
strcpy(myreq.ProductClass, req.productclass.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
}
virtual int ReqQryInstrument(CThostFtdcQryInstrumentField* pQryInstrument, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryInstrumentField req
CThostFtdcQryInstrumentField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
strcpy(myreq.ExchangeInstID, req.exchangeinstid.c_str());
strcpy(myreq.ProductID, req.productid.c_str());
}
virtual int ReqQryDepthMarketData(CThostFtdcQryDepthMarketDataField* pQryDepthMarketData, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryDepthMarketDataField req
CThostFtdcQryDepthMarketDataField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
}
virtual int ReqQrySettlementInfo(CThostFtdcQrySettlementInfoField* pQrySettlementInfo, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQrySettlementInfoField req
CThostFtdcQrySettlementInfoField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.TradingDay, req.tradingday.c_str());
}
virtual int ReqQryTransferBank(CThostFtdcQryTransferBankField* pQryTransferBank, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryTransferBankField req
CThostFtdcQryTransferBankField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BankID, req.bankid.c_str());
strcpy(myreq.BankBrchID, req.bankbrchid.c_str());
}
virtual int ReqQryInvestorPositionDetail(CThostFtdcQryInvestorPositionDetailField* pQryInvestorPositionDetail, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryInvestorPositionDetailField req
CThostFtdcQryInvestorPositionDetailField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
}
virtual int ReqQryNotice(CThostFtdcQryNoticeField* pQryNotice, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryNoticeField req
CThostFtdcQryNoticeField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
}
virtual int ReqQrySettlementInfoConfirm(CThostFtdcQrySettlementInfoConfirmField* pQrySettlementInfoConfirm, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQrySettlementInfoConfirmField req
CThostFtdcQrySettlementInfoConfirmField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
}
virtual int ReqQryInvestorPositionCombineDetail(CThostFtdcQryInvestorPositionCombineDetailField* pQryInvestorPositionCombineDetail, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryInvestorPositionCombineDetailField req
CThostFtdcQryInvestorPositionCombineDetailField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.CombInstrumentID, req.combinstrumentid.c_str());
}
virtual int ReqQryCFMMCTradingAccountKey(CThostFtdcQryCFMMCTradingAccountKeyField* pQryCFMMCTradingAccountKey, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryCFMMCTradingAccountKeyField req
CThostFtdcQryCFMMCTradingAccountKeyField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
}

///ÇëÇó²éÑ¯²Öµ¥ÕÛµÖÐÅÏ¢
virtual int ReqQryEWarrantOffset(CThostFtdcQryEWarrantOffsetField* pQryEWarrantOffset, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryEWarrantOffsetField req
CThostFtdcQryEWarrantOffsetField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
}

///ÇëÇó²éÑ¯Í¶×ÊÕßÆ·ÖÖ/¿çÆ·ÖÖ±£Ö¤½ð
virtual int ReqQryInvestorProductGroupMargin(CThostFtdcQryInvestorProductGroupMarginField* pQryInvestorProductGroupMargin, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryInvestorProductGroupMarginField req
CThostFtdcQryInvestorProductGroupMarginField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.ProductGroupID, req.productgroupid.c_str());
strcpy(myreq.HedgeFlag, req.hedgeflag.c_str());
}

///ÇëÇó²éÑ¯½»Ò×Ëù±£Ö¤½ðÂÊ
virtual int ReqQryExchangeMarginRate(CThostFtdcQryExchangeMarginRateField* pQryExchangeMarginRate, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryExchangeMarginRateField req
CThostFtdcQryExchangeMarginRateField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.HedgeFlag, req.hedgeflag.c_str());
}

///ÇëÇó²éÑ¯½»Ò×Ëùµ÷Õû±£Ö¤½ðÂÊ
virtual int ReqQryExchangeMarginRateAdjust(CThostFtdcQryExchangeMarginRateAdjustField* pQryExchangeMarginRateAdjust, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryExchangeMarginRateAdjustField req
CThostFtdcQryExchangeMarginRateAdjustField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.HedgeFlag, req.hedgeflag.c_str());
}

///ÇëÇó²éÑ¯»ãÂÊ
virtual int ReqQryExchangeRate(CThostFtdcQryExchangeRateField* pQryExchangeRate, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryExchangeRateField req
CThostFtdcQryExchangeRateField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.FromCurrencyID, req.fromcurrencyid.c_str());
strcpy(myreq.ToCurrencyID, req.tocurrencyid.c_str());
}

///ÇëÇó²éÑ¯¶þ¼¶´úÀí²Ù×÷Ô±ÒøÆÚÈ¨ÏÞ
virtual int ReqQrySecAgentACIDMap(CThostFtdcQrySecAgentACIDMapField* pQrySecAgentACIDMap, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQrySecAgentACIDMapField req
CThostFtdcQrySecAgentACIDMapField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.UserID, req.userid.c_str());
strcpy(myreq.AccountID, req.accountid.c_str());
strcpy(myreq.CurrencyID, req.currencyid.c_str());
}

///ÇëÇó²éÑ¯²úÆ·±¨¼Û»ãÂÊ
virtual int ReqQryProductExchRate(CThostFtdcQryProductExchRateField* pQryProductExchRate, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryProductExchRateField req
CThostFtdcQryProductExchRateField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.ProductID, req.productid.c_str());
}

///ÇëÇó²éÑ¯²úÆ·×é
virtual int ReqQryProductGroup(CThostFtdcQryProductGroupField* pQryProductGroup, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryProductGroupField req
CThostFtdcQryProductGroupField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.ProductID, req.productid.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
}

///ÇëÇó²éÑ¯ÆÚÈ¨½»Ò×³É±¾
virtual int ReqQryOptionInstrTradeCost(CThostFtdcQryOptionInstrTradeCostField* pQryOptionInstrTradeCost, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryOptionInstrTradeCostField req
CThostFtdcQryOptionInstrTradeCostField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.HedgeFlag, req.hedgeflag.c_str());
myreq.InputPrice = req.inputprice();
myreq.UnderlyingPrice = req.underlyingprice();
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
}

///ÇëÇó²éÑ¯ÆÚÈ¨ºÏÔ¼ÊÖÐø·Ñ
virtual int ReqQryOptionInstrCommRate(CThostFtdcQryOptionInstrCommRateField* pQryOptionInstrCommRate, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryOptionInstrCommRateField req
CThostFtdcQryOptionInstrCommRateField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
}

///ÇëÇó²éÑ¯Ö´ÐÐÐû¸æ
virtual int ReqQryExecOrder(CThostFtdcQryExecOrderField* pQryExecOrder, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryExecOrderField req
CThostFtdcQryExecOrderField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
strcpy(myreq.ExecOrderSysID, req.execordersysid.c_str());
strcpy(myreq.InsertTimeStart, req.inserttimestart.c_str());
strcpy(myreq.InsertTimeEnd, req.inserttimeend.c_str());
}

///ÇëÇó²éÑ¯Ñ¯¼Û
virtual int ReqQryForQuote(CThostFtdcQryForQuoteField* pQryForQuote, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryForQuoteField req
CThostFtdcQryForQuoteField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
strcpy(myreq.InsertTimeStart, req.inserttimestart.c_str());
strcpy(myreq.InsertTimeEnd, req.inserttimeend.c_str());
}

///ÇëÇó²éÑ¯±¨¼Û
virtual int ReqQryQuote(CThostFtdcQryQuoteField* pQryQuote, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryQuoteField req
CThostFtdcQryQuoteField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
strcpy(myreq.QuoteSysID, req.quotesysid.c_str());
strcpy(myreq.InsertTimeStart, req.inserttimestart.c_str());
strcpy(myreq.InsertTimeEnd, req.inserttimeend.c_str());
}

///ÇëÇó²éÑ¯Ëø¶¨
virtual int ReqQryLock(CThostFtdcQryLockField* pQryLock, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryLockField req
CThostFtdcQryLockField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
strcpy(myreq.LockSysID, req.locksysid.c_str());
strcpy(myreq.InsertTimeStart, req.inserttimestart.c_str());
strcpy(myreq.InsertTimeEnd, req.inserttimeend.c_str());
}

///ÇëÇó²éÑ¯Ëø¶¨Ö¤È¯²ÖÎ»
virtual int ReqQryLockPosition(CThostFtdcQryLockPositionField* pQryLockPosition, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryLockPositionField req
CThostFtdcQryLockPositionField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
}

///ÇëÇó²éÑ¯Í¶×ÊÕß·Ö¼¶
virtual int ReqQryInvestorLevel(CThostFtdcQryInvestorLevelField* pQryInvestorLevel, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryInvestorLevelField req
CThostFtdcQryInvestorLevelField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
}

///ÇëÇó²éÑ¯E+1ÈÕÐÐÈ¨¶³½á
virtual int ReqQryExecFreeze(CThostFtdcQryExecFreezeField* pQryExecFreeze, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryExecFreezeField req
CThostFtdcQryExecFreezeField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
}

///ÇëÇó²éÑ¯×éºÏºÏÔ¼°²È«ÏµÊý
virtual int ReqQryCombInstrumentGuard(CThostFtdcQryCombInstrumentGuardField* pQryCombInstrumentGuard, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryCombInstrumentGuardField req
CThostFtdcQryCombInstrumentGuardField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
}

///ÇëÇó²éÑ¯ÉêÇë×éºÏ
virtual int ReqQryCombAction(CThostFtdcQryCombActionField* pQryCombAction, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryCombActionField req
CThostFtdcQryCombActionField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
}

///ÇëÇó²éÑ¯×ªÕÊÁ÷Ë®
virtual int ReqQryTransferSerial(CThostFtdcQryTransferSerialField* pQryTransferSerial, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryTransferSerialField req
CThostFtdcQryTransferSerialField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.AccountID, req.accountid.c_str());
strcpy(myreq.BankID, req.bankid.c_str());
strcpy(myreq.CurrencyID, req.currencyid.c_str());
}

///ÇëÇó²éÑ¯ÒøÆÚÇ©Ô¼¹ØÏµ
virtual int ReqQryAccountregister(CThostFtdcQryAccountregisterField* pQryAccountregister, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryAccountregisterField req
CThostFtdcQryAccountregisterField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.AccountID, req.accountid.c_str());
strcpy(myreq.BankID, req.bankid.c_str());
strcpy(myreq.BankBranchID, req.bankbranchid.c_str());
strcpy(myreq.CurrencyID, req.currencyid.c_str());
}

///ÇëÇó²éÑ¯Ç©Ô¼ÒøÐÐ
virtual int ReqQryContractBank(CThostFtdcQryContractBankField* pQryContractBank, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryContractBankField req
CThostFtdcQryContractBankField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.BankID, req.bankid.c_str());
strcpy(myreq.BankBrchID, req.bankbrchid.c_str());
}

///ÇëÇó²éÑ¯Ô¤Âñµ¥
virtual int ReqQryParkedOrder(CThostFtdcQryParkedOrderField* pQryParkedOrder, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryParkedOrderField req
CThostFtdcQryParkedOrderField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
}

///ÇëÇó²éÑ¯Ô¤Âñ³·µ¥
virtual int ReqQryParkedOrderAction(CThostFtdcQryParkedOrderActionField* pQryParkedOrderAction, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryParkedOrderActionField req
CThostFtdcQryParkedOrderActionField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
}

///ÇëÇó²éÑ¯½»Ò×Í¨Öª
virtual int ReqQryTradingNotice(CThostFtdcQryTradingNoticeField* pQryTradingNotice, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryTradingNoticeField req
CThostFtdcQryTradingNoticeField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
}

///ÇëÇó²éÑ¯¾­¼Í¹«Ë¾½»Ò×²ÎÊý
virtual int ReqQryBrokerTradingParams(CThostFtdcQryBrokerTradingParamsField* pQryBrokerTradingParams, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryBrokerTradingParamsField req
CThostFtdcQryBrokerTradingParamsField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
strcpy(myreq.CurrencyID, req.currencyid.c_str());
}

///ÇëÇó²éÑ¯¾­¼Í¹«Ë¾½»Ò×Ëã·¨
virtual int ReqQryBrokerTradingAlgos(CThostFtdcQryBrokerTradingAlgosField* pQryBrokerTradingAlgos, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQryBrokerTradingAlgosField req
CThostFtdcQryBrokerTradingAlgosField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.ExchangeID, req.exchangeid.c_str());
strcpy(myreq.InstrumentID, req.instrumentid.c_str());
}

///ÇëÇó²éÑ¯¼à¿ØÖÐÐÄÓÃ»§ÁîÅÆ
virtual int ReqQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcQueryCFMMCTradingAccountTokenField req
CThostFtdcQueryCFMMCTradingAccountTokenField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.InvestorID, req.investorid.c_str());
}

///ÆÚ»õ·¢ÆðÒøÐÐ×Ê½ð×ªÆÚ»õÇëÇó
virtual int ReqFromBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcReqTransferField req
CThostFtdcReqTransferField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.TradeCode, req.tradecode.c_str());
strcpy(myreq.BankID, req.bankid.c_str());
strcpy(myreq.BankBranchID, req.bankbranchid.c_str());
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.BrokerBranchID, req.brokerbranchid.c_str());
strcpy(myreq.TradeDate, req.tradedate.c_str());
strcpy(myreq.TradeTime, req.tradetime.c_str());
strcpy(myreq.BankSerial, req.bankserial.c_str());
strcpy(myreq.TradingDay, req.tradingday.c_str());
myreq.PlateSerial = req.plateserial();
strcpy(myreq.LastFragment, req.lastfragment.c_str());
myreq.SessionID = req.sessionid();
strcpy(myreq.CustomerName, req.customername.c_str());
strcpy(myreq.IdCardType, req.idcardtype.c_str());
strcpy(myreq.IdentifiedCardNo, req.identifiedcardno.c_str());
strcpy(myreq.CustType, req.custtype.c_str());
strcpy(myreq.BankAccount, req.bankaccount.c_str());
strcpy(myreq.BankPassWord, req.bankpassword.c_str());
strcpy(myreq.AccountID, req.accountid.c_str());
strcpy(myreq.Password, req.password.c_str());
myreq.InstallID = req.installid();
myreq.FutureSerial = req.futureserial();
strcpy(myreq.UserID, req.userid.c_str());
strcpy(myreq.VerifyCertNoFlag, req.verifycertnoflag.c_str());
strcpy(myreq.CurrencyID, req.currencyid.c_str());
myreq.TradeAmount = req.tradeamount();
myreq.FutureFetchAmount = req.futurefetchamount();
strcpy(myreq.FeePayFlag, req.feepayflag.c_str());
myreq.CustFee = req.custfee();
myreq.BrokerFee = req.brokerfee();
strcpy(myreq.Message, req.message.c_str());
strcpy(myreq.Digest, req.digest.c_str());
strcpy(myreq.BankAccType, req.bankacctype.c_str());
strcpy(myreq.DeviceID, req.deviceid.c_str());
strcpy(myreq.BankSecuAccType, req.banksecuacctype.c_str());
strcpy(myreq.BrokerIDByBank, req.brokeridbybank.c_str());
strcpy(myreq.BankSecuAcc, req.banksecuacc.c_str());
strcpy(myreq.BankPwdFlag, req.bankpwdflag.c_str());
strcpy(myreq.SecuPwdFlag, req.secupwdflag.c_str());
strcpy(myreq.OperNo, req.operno.c_str());
myreq.RequestID = req.requestid();
myreq.TID = req.tid();
strcpy(myreq.TransferStatus, req.transferstatus.c_str());
}

///ÆÚ»õ·¢ÆðÆÚ»õ×Ê½ð×ªÒøÐÐÇëÇó
virtual int ReqFromFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcReqTransferField req
CThostFtdcReqTransferField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.TradeCode, req.tradecode.c_str());
strcpy(myreq.BankID, req.bankid.c_str());
strcpy(myreq.BankBranchID, req.bankbranchid.c_str());
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.BrokerBranchID, req.brokerbranchid.c_str());
strcpy(myreq.TradeDate, req.tradedate.c_str());
strcpy(myreq.TradeTime, req.tradetime.c_str());
strcpy(myreq.BankSerial, req.bankserial.c_str());
strcpy(myreq.TradingDay, req.tradingday.c_str());
myreq.PlateSerial = req.plateserial();
strcpy(myreq.LastFragment, req.lastfragment.c_str());
myreq.SessionID = req.sessionid();
strcpy(myreq.CustomerName, req.customername.c_str());
strcpy(myreq.IdCardType, req.idcardtype.c_str());
strcpy(myreq.IdentifiedCardNo, req.identifiedcardno.c_str());
strcpy(myreq.CustType, req.custtype.c_str());
strcpy(myreq.BankAccount, req.bankaccount.c_str());
strcpy(myreq.BankPassWord, req.bankpassword.c_str());
strcpy(myreq.AccountID, req.accountid.c_str());
strcpy(myreq.Password, req.password.c_str());
myreq.InstallID = req.installid();
myreq.FutureSerial = req.futureserial();
strcpy(myreq.UserID, req.userid.c_str());
strcpy(myreq.VerifyCertNoFlag, req.verifycertnoflag.c_str());
strcpy(myreq.CurrencyID, req.currencyid.c_str());
myreq.TradeAmount = req.tradeamount();
myreq.FutureFetchAmount = req.futurefetchamount();
strcpy(myreq.FeePayFlag, req.feepayflag.c_str());
myreq.CustFee = req.custfee();
myreq.BrokerFee = req.brokerfee();
strcpy(myreq.Message, req.message.c_str());
strcpy(myreq.Digest, req.digest.c_str());
strcpy(myreq.BankAccType, req.bankacctype.c_str());
strcpy(myreq.DeviceID, req.deviceid.c_str());
strcpy(myreq.BankSecuAccType, req.banksecuacctype.c_str());
strcpy(myreq.BrokerIDByBank, req.brokeridbybank.c_str());
strcpy(myreq.BankSecuAcc, req.banksecuacc.c_str());
strcpy(myreq.BankPwdFlag, req.bankpwdflag.c_str());
strcpy(myreq.SecuPwdFlag, req.secupwdflag.c_str());
strcpy(myreq.OperNo, req.operno.c_str());
myreq.RequestID = req.requestid();
myreq.TID = req.tid();
strcpy(myreq.TransferStatus, req.transferstatus.c_str());
}

///ÆÚ»õ·¢Æð²éÑ¯ÒøÐÐÓà¶îÇëÇó
virtual int ReqQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, int nRequestID) = 0;
{
guosen::msg::ctp::CThostFtdcReqQueryAccountField req
CThostFtdcReqQueryAccountField myreq;
memset(&myreq,0,sizeof(myreq));
strcpy(myreq.TradeCode, req.tradecode.c_str());
strcpy(myreq.BankID, req.bankid.c_str());
strcpy(myreq.BankBranchID, req.bankbranchid.c_str());
strcpy(myreq.BrokerID, req.brokerid.c_str());
strcpy(myreq.BrokerBranchID, req.brokerbranchid.c_str());
strcpy(myreq.TradeDate, req.tradedate.c_str());
strcpy(myreq.TradeTime, req.tradetime.c_str());
strcpy(myreq.BankSerial, req.bankserial.c_str());
strcpy(myreq.TradingDay, req.tradingday.c_str());
myreq.PlateSerial = req.plateserial();
strcpy(myreq.LastFragment, req.lastfragment.c_str());
myreq.SessionID = req.sessionid();
strcpy(myreq.CustomerName, req.customername.c_str());
strcpy(myreq.IdCardType, req.idcardtype.c_str());
strcpy(myreq.IdentifiedCardNo, req.identifiedcardno.c_str());
strcpy(myreq.CustType, req.custtype.c_str());
strcpy(myreq.BankAccount, req.bankaccount.c_str());
strcpy(myreq.BankPassWord, req.bankpassword.c_str());
strcpy(myreq.AccountID, req.accountid.c_str());
strcpy(myreq.Password, req.password.c_str());
myreq.FutureSerial = req.futureserial();
myreq.InstallID = req.installid();
strcpy(myreq.UserID, req.userid.c_str());
strcpy(myreq.VerifyCertNoFlag, req.verifycertnoflag.c_str());
strcpy(myreq.CurrencyID, req.currencyid.c_str());
strcpy(myreq.Digest, req.digest.c_str());
strcpy(myreq.BankAccType, req.bankacctype.c_str());
strcpy(myreq.DeviceID, req.deviceid.c_str());
strcpy(myreq.BankSecuAccType, req.banksecuacctype.c_str());
strcpy(myreq.BrokerIDByBank, req.brokeridbybank.c_str());
strcpy(myreq.BankSecuAcc, req.banksecuacc.c_str());
strcpy(myreq.BankPwdFlag, req.bankpwdflag.c_str());
strcpy(myreq.SecuPwdFlag, req.secupwdflag.c_str());
strcpy(myreq.OperNo, req.operno.c_str());
myreq.RequestID = req.requestid();
myreq.TID = req.tid();
}
