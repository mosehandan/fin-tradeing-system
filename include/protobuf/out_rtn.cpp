inline bool CMdSpi::IsErrorRspInfo(CThostFtdcRspInfoField* pRspInfo)
{
guosen::msg::ctp::CThostFtdcRspInfoField body_message;
body_message.set_errorid(pRspInfo->ErrorID);
body_message.set_errormsg(pRspInfo->ErrorMsg);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcRspInfoField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}
void CMdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
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
}
void CMdSpi::OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcUserLogoutField body_message;
body_message.set_brokerid(pUserLogout->BrokerID);
body_message.set_userid(pUserLogout->UserID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcUserLogoutField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}
void CMdSpi::OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcRspInfoField body_message;
body_message.set_errorid(pRspInfo->ErrorID);
body_message.set_errormsg(pRspInfo->ErrorMsg);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcRspInfoField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}
void CMdSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcSpecificInstrumentField body_message;
body_message.set_instrumentid(pSpecificInstrument->InstrumentID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcSpecificInstrumentField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}
void CMdSpi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcSpecificInstrumentField body_message;
body_message.set_instrumentid(pSpecificInstrument->InstrumentID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcSpecificInstrumentField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}
void CMdSpi::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcSpecificInstrumentField body_message;
body_message.set_instrumentid(pSpecificInstrument->InstrumentID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcSpecificInstrumentField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}
void CMdSpi::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcSpecificInstrumentField body_message;
body_message.set_instrumentid(pSpecificInstrument->InstrumentID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcSpecificInstrumentField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}
void CMdSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData)
{
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
void CMdSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp) {}
{
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
inline bool CTraderSpi::IsErrorRspInfo(CThostFtdcRspInfoField* pRspInfo)
{
guosen::msg::ctp::CThostFtdcRspInfoField body_message;
body_message.set_errorid(pRspInfo->ErrorID);
body_message.set_errormsg(pRspInfo->ErrorMsg);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcRspInfoField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}
void CTraderSpi::OnRspAuthenticate(CThostFtdcRspAuthenticateField* pRspAuthenticateField, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcRspAuthenticateField body_message;
body_message.set_brokerid(pRspAuthenticateField->BrokerID);
body_message.set_userid(pRspAuthenticateField->UserID);
body_message.set_userproductinfo(pRspAuthenticateField->UserProductInfo);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcRspAuthenticateField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}
void CTraderSpi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
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
}
void CTraderSpi::OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcUserLogoutField body_message;
body_message.set_brokerid(pUserLogout->BrokerID);
body_message.set_userid(pUserLogout->UserID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcUserLogoutField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}
void CTraderSpi::OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField* pUserPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcUserPasswordUpdateField body_message;
body_message.set_brokerid(pUserPasswordUpdate->BrokerID);
body_message.set_userid(pUserPasswordUpdate->UserID);
body_message.set_oldpassword(pUserPasswordUpdate->OldPassword);
body_message.set_newpassword(pUserPasswordUpdate->NewPassword);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcUserPasswordUpdateField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}
void CTraderSpi::OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField* pTradingAccountPasswordUpdate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcTradingAccountPasswordUpdateField body_message;
body_message.set_brokerid(pTradingAccountPasswordUpdate->BrokerID);
body_message.set_accountid(pTradingAccountPasswordUpdate->AccountID);
body_message.set_oldpassword(pTradingAccountPasswordUpdate->OldPassword);
body_message.set_newpassword(pTradingAccountPasswordUpdate->NewPassword);
body_message.set_currencyid(pTradingAccountPasswordUpdate->CurrencyID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcTradingAccountPasswordUpdateField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}
void CTraderSpi::OnRspOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcInputOrderField body_message;
body_message.set_brokerid(pInputOrder->BrokerID);
body_message.set_investorid(pInputOrder->InvestorID);
body_message.set_instrumentid(pInputOrder->InstrumentID);
body_message.set_orderref(pInputOrder->OrderRef);
body_message.set_userid(pInputOrder->UserID);
body_message.set_orderpricetype(pInputOrder->OrderPriceType);
body_message.set_direction(pInputOrder->Direction);
body_message.set_comboffsetflag(pInputOrder->CombOffsetFlag);
body_message.set_combhedgeflag(pInputOrder->CombHedgeFlag);
body_message.set_limitprice(pInputOrder->LimitPrice);
body_message.set_volumetotaloriginal(pInputOrder->VolumeTotalOriginal);
body_message.set_timecondition(pInputOrder->TimeCondition);
body_message.set_gtddate(pInputOrder->GTDDate);
body_message.set_volumecondition(pInputOrder->VolumeCondition);
body_message.set_minvolume(pInputOrder->MinVolume);
body_message.set_contingentcondition(pInputOrder->ContingentCondition);
body_message.set_stopprice(pInputOrder->StopPrice);
body_message.set_forceclosereason(pInputOrder->ForceCloseReason);
body_message.set_isautosuspend(pInputOrder->IsAutoSuspend);
body_message.set_businessunit(pInputOrder->BusinessUnit);
body_message.set_requestid(pInputOrder->RequestID);
body_message.set_userforceclose(pInputOrder->UserForceClose);
body_message.set_isswaporder(pInputOrder->IsSwapOrder);
body_message.set_exchangeid(pInputOrder->ExchangeID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInputOrderField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}
void CTraderSpi::OnRspParkedOrderInsert(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcParkedOrderField body_message;
body_message.set_brokerid(pParkedOrder->BrokerID);
body_message.set_investorid(pParkedOrder->InvestorID);
body_message.set_instrumentid(pParkedOrder->InstrumentID);
body_message.set_orderref(pParkedOrder->OrderRef);
body_message.set_userid(pParkedOrder->UserID);
body_message.set_orderpricetype(pParkedOrder->OrderPriceType);
body_message.set_direction(pParkedOrder->Direction);
body_message.set_comboffsetflag(pParkedOrder->CombOffsetFlag);
body_message.set_combhedgeflag(pParkedOrder->CombHedgeFlag);
body_message.set_limitprice(pParkedOrder->LimitPrice);
body_message.set_volumetotaloriginal(pParkedOrder->VolumeTotalOriginal);
body_message.set_timecondition(pParkedOrder->TimeCondition);
body_message.set_gtddate(pParkedOrder->GTDDate);
body_message.set_volumecondition(pParkedOrder->VolumeCondition);
body_message.set_minvolume(pParkedOrder->MinVolume);
body_message.set_contingentcondition(pParkedOrder->ContingentCondition);
body_message.set_stopprice(pParkedOrder->StopPrice);
body_message.set_forceclosereason(pParkedOrder->ForceCloseReason);
body_message.set_isautosuspend(pParkedOrder->IsAutoSuspend);
body_message.set_businessunit(pParkedOrder->BusinessUnit);
body_message.set_requestid(pParkedOrder->RequestID);
body_message.set_userforceclose(pParkedOrder->UserForceClose);
body_message.set_exchangeid(pParkedOrder->ExchangeID);
body_message.set_parkedorderid(pParkedOrder->ParkedOrderID);
body_message.set_usertype(pParkedOrder->UserType);
body_message.set_status(pParkedOrder->Status);
body_message.set_errorid(pParkedOrder->ErrorID);
body_message.set_errormsg(pParkedOrder->ErrorMsg);
body_message.set_isswaporder(pParkedOrder->IsSwapOrder);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcParkedOrderField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}
void CTraderSpi::OnRspParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcParkedOrderActionField body_message;
body_message.set_brokerid(pParkedOrderAction->BrokerID);
body_message.set_investorid(pParkedOrderAction->InvestorID);
body_message.set_orderactionref(pParkedOrderAction->OrderActionRef);
body_message.set_orderref(pParkedOrderAction->OrderRef);
body_message.set_requestid(pParkedOrderAction->RequestID);
body_message.set_frontid(pParkedOrderAction->FrontID);
body_message.set_sessionid(pParkedOrderAction->SessionID);
body_message.set_exchangeid(pParkedOrderAction->ExchangeID);
body_message.set_ordersysid(pParkedOrderAction->OrderSysID);
body_message.set_actionflag(pParkedOrderAction->ActionFlag);
body_message.set_limitprice(pParkedOrderAction->LimitPrice);
body_message.set_volumechange(pParkedOrderAction->VolumeChange);
body_message.set_userid(pParkedOrderAction->UserID);
body_message.set_instrumentid(pParkedOrderAction->InstrumentID);
body_message.set_parkedorderactionid(pParkedOrderAction->ParkedOrderActionID);
body_message.set_usertype(pParkedOrderAction->UserType);
body_message.set_status(pParkedOrderAction->Status);
body_message.set_errorid(pParkedOrderAction->ErrorID);
body_message.set_errormsg(pParkedOrderAction->ErrorMsg);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcParkedOrderActionField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}
void CTraderSpi::OnRspOrderAction(CThostFtdcInputOrderActionField* pInputOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcInputOrderActionField body_message;
body_message.set_brokerid(pInputOrderAction->BrokerID);
body_message.set_investorid(pInputOrderAction->InvestorID);
body_message.set_orderactionref(pInputOrderAction->OrderActionRef);
body_message.set_orderref(pInputOrderAction->OrderRef);
body_message.set_requestid(pInputOrderAction->RequestID);
body_message.set_frontid(pInputOrderAction->FrontID);
body_message.set_sessionid(pInputOrderAction->SessionID);
body_message.set_exchangeid(pInputOrderAction->ExchangeID);
body_message.set_ordersysid(pInputOrderAction->OrderSysID);
body_message.set_actionflag(pInputOrderAction->ActionFlag);
body_message.set_limitprice(pInputOrderAction->LimitPrice);
body_message.set_volumechange(pInputOrderAction->VolumeChange);
body_message.set_userid(pInputOrderAction->UserID);
body_message.set_instrumentid(pInputOrderAction->InstrumentID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInputOrderActionField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///查询最大报单数量响应
void CTraderSpi::OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField* pQueryMaxOrderVolume, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcQueryMaxOrderVolumeField body_message;
body_message.set_brokerid(pQueryMaxOrderVolume->BrokerID);
body_message.set_investorid(pQueryMaxOrderVolume->InvestorID);
body_message.set_instrumentid(pQueryMaxOrderVolume->InstrumentID);
body_message.set_direction(pQueryMaxOrderVolume->Direction);
body_message.set_offsetflag(pQueryMaxOrderVolume->OffsetFlag);
body_message.set_hedgeflag(pQueryMaxOrderVolume->HedgeFlag);
body_message.set_maxvolume(pQueryMaxOrderVolume->MaxVolume);
body_message.set_exchangeid(pQueryMaxOrderVolume->ExchangeID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcQueryMaxOrderVolumeField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///投资者结算结果确认响应
void CTraderSpi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcSettlementInfoConfirmField body_message;
body_message.set_brokerid(pSettlementInfoConfirm->BrokerID);
body_message.set_investorid(pSettlementInfoConfirm->InvestorID);
body_message.set_confirmdate(pSettlementInfoConfirm->ConfirmDate);
body_message.set_confirmtime(pSettlementInfoConfirm->ConfirmTime);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcSettlementInfoConfirmField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///删除预埋单响应
void CTraderSpi::OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField* pRemoveParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcRemoveParkedOrderField body_message;
body_message.set_brokerid(pRemoveParkedOrder->BrokerID);
body_message.set_investorid(pRemoveParkedOrder->InvestorID);
body_message.set_parkedorderid(pRemoveParkedOrder->ParkedOrderID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcRemoveParkedOrderField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///删除预埋撤单响应
void CTraderSpi::OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField* pRemoveParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcRemoveParkedOrderActionField body_message;
body_message.set_brokerid(pRemoveParkedOrderAction->BrokerID);
body_message.set_investorid(pRemoveParkedOrderAction->InvestorID);
body_message.set_parkedorderactionid(pRemoveParkedOrderAction->ParkedOrderActionID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcRemoveParkedOrderActionField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///执行宣告录入请求响应
void CTraderSpi::OnRspExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcInputExecOrderField body_message;
body_message.set_brokerid(pInputExecOrder->BrokerID);
body_message.set_investorid(pInputExecOrder->InvestorID);
body_message.set_instrumentid(pInputExecOrder->InstrumentID);
body_message.set_execorderref(pInputExecOrder->ExecOrderRef);
body_message.set_userid(pInputExecOrder->UserID);
body_message.set_volume(pInputExecOrder->Volume);
body_message.set_requestid(pInputExecOrder->RequestID);
body_message.set_businessunit(pInputExecOrder->BusinessUnit);
body_message.set_offsetflag(pInputExecOrder->OffsetFlag);
body_message.set_hedgeflag(pInputExecOrder->HedgeFlag);
body_message.set_actiontype(pInputExecOrder->ActionType);
body_message.set_posidirection(pInputExecOrder->PosiDirection);
body_message.set_reservepositionflag(pInputExecOrder->ReservePositionFlag);
body_message.set_closeflag(pInputExecOrder->CloseFlag);
body_message.set_exchangeid(pInputExecOrder->ExchangeID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInputExecOrderField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///执行宣告操作请求响应
void CTraderSpi::OnRspExecOrderAction(CThostFtdcInputExecOrderActionField* pInputExecOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcInputExecOrderActionField body_message;
body_message.set_brokerid(pInputExecOrderAction->BrokerID);
body_message.set_investorid(pInputExecOrderAction->InvestorID);
body_message.set_execorderactionref(pInputExecOrderAction->ExecOrderActionRef);
body_message.set_execorderref(pInputExecOrderAction->ExecOrderRef);
body_message.set_requestid(pInputExecOrderAction->RequestID);
body_message.set_frontid(pInputExecOrderAction->FrontID);
body_message.set_sessionid(pInputExecOrderAction->SessionID);
body_message.set_exchangeid(pInputExecOrderAction->ExchangeID);
body_message.set_execordersysid(pInputExecOrderAction->ExecOrderSysID);
body_message.set_actionflag(pInputExecOrderAction->ActionFlag);
body_message.set_userid(pInputExecOrderAction->UserID);
body_message.set_instrumentid(pInputExecOrderAction->InstrumentID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInputExecOrderActionField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///询价录入请求响应
void CTraderSpi::OnRspForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcInputForQuoteField body_message;
body_message.set_brokerid(pInputForQuote->BrokerID);
body_message.set_investorid(pInputForQuote->InvestorID);
body_message.set_instrumentid(pInputForQuote->InstrumentID);
body_message.set_forquoteref(pInputForQuote->ForQuoteRef);
body_message.set_userid(pInputForQuote->UserID);
body_message.set_exchangeid(pInputForQuote->ExchangeID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInputForQuoteField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///报价录入请求响应
void CTraderSpi::OnRspQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcInputQuoteField body_message;
body_message.set_brokerid(pInputQuote->BrokerID);
body_message.set_investorid(pInputQuote->InvestorID);
body_message.set_instrumentid(pInputQuote->InstrumentID);
body_message.set_quoteref(pInputQuote->QuoteRef);
body_message.set_userid(pInputQuote->UserID);
body_message.set_askprice(pInputQuote->AskPrice);
body_message.set_bidprice(pInputQuote->BidPrice);
body_message.set_askvolume(pInputQuote->AskVolume);
body_message.set_bidvolume(pInputQuote->BidVolume);
body_message.set_requestid(pInputQuote->RequestID);
body_message.set_businessunit(pInputQuote->BusinessUnit);
body_message.set_askoffsetflag(pInputQuote->AskOffsetFlag);
body_message.set_bidoffsetflag(pInputQuote->BidOffsetFlag);
body_message.set_askhedgeflag(pInputQuote->AskHedgeFlag);
body_message.set_bidhedgeflag(pInputQuote->BidHedgeFlag);
body_message.set_askorderref(pInputQuote->AskOrderRef);
body_message.set_bidorderref(pInputQuote->BidOrderRef);
body_message.set_forquotesysid(pInputQuote->ForQuoteSysID);
body_message.set_exchangeid(pInputQuote->ExchangeID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInputQuoteField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///报价操作请求响应
void CTraderSpi::OnRspQuoteAction(CThostFtdcInputQuoteActionField* pInputQuoteAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcInputQuoteActionField body_message;
body_message.set_brokerid(pInputQuoteAction->BrokerID);
body_message.set_investorid(pInputQuoteAction->InvestorID);
body_message.set_quoteactionref(pInputQuoteAction->QuoteActionRef);
body_message.set_quoteref(pInputQuoteAction->QuoteRef);
body_message.set_requestid(pInputQuoteAction->RequestID);
body_message.set_frontid(pInputQuoteAction->FrontID);
body_message.set_sessionid(pInputQuoteAction->SessionID);
body_message.set_exchangeid(pInputQuoteAction->ExchangeID);
body_message.set_quotesysid(pInputQuoteAction->QuoteSysID);
body_message.set_actionflag(pInputQuoteAction->ActionFlag);
body_message.set_userid(pInputQuoteAction->UserID);
body_message.set_instrumentid(pInputQuoteAction->InstrumentID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInputQuoteActionField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///锁定应答
void CTraderSpi::OnRspLockInsert(CThostFtdcInputLockField* pInputLock, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcInputLockField body_message;
body_message.set_brokerid(pInputLock->BrokerID);
body_message.set_investorid(pInputLock->InvestorID);
body_message.set_instrumentid(pInputLock->InstrumentID);
body_message.set_lockref(pInputLock->LockRef);
body_message.set_userid(pInputLock->UserID);
body_message.set_volume(pInputLock->Volume);
body_message.set_requestid(pInputLock->RequestID);
body_message.set_businessunit(pInputLock->BusinessUnit);
body_message.set_locktype(pInputLock->LockType);
body_message.set_exchangeid(pInputLock->ExchangeID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInputLockField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///申请组合录入请求响应
void CTraderSpi::OnRspCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcInputCombActionField body_message;
body_message.set_brokerid(pInputCombAction->BrokerID);
body_message.set_investorid(pInputCombAction->InvestorID);
body_message.set_instrumentid(pInputCombAction->InstrumentID);
body_message.set_combactionref(pInputCombAction->CombActionRef);
body_message.set_userid(pInputCombAction->UserID);
body_message.set_direction(pInputCombAction->Direction);
body_message.set_volume(pInputCombAction->Volume);
body_message.set_combdirection(pInputCombAction->CombDirection);
body_message.set_hedgeflag(pInputCombAction->HedgeFlag);
body_message.set_exchangeid(pInputCombAction->ExchangeID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInputCombActionField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询报单响应
void CTraderSpi::OnRspQryOrder(CThostFtdcOrderField* pOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcOrderField body_message;
body_message.set_brokerid(pOrder->BrokerID);
body_message.set_investorid(pOrder->InvestorID);
body_message.set_instrumentid(pOrder->InstrumentID);
body_message.set_orderref(pOrder->OrderRef);
body_message.set_userid(pOrder->UserID);
body_message.set_orderpricetype(pOrder->OrderPriceType);
body_message.set_direction(pOrder->Direction);
body_message.set_comboffsetflag(pOrder->CombOffsetFlag);
body_message.set_combhedgeflag(pOrder->CombHedgeFlag);
body_message.set_limitprice(pOrder->LimitPrice);
body_message.set_volumetotaloriginal(pOrder->VolumeTotalOriginal);
body_message.set_timecondition(pOrder->TimeCondition);
body_message.set_gtddate(pOrder->GTDDate);
body_message.set_volumecondition(pOrder->VolumeCondition);
body_message.set_minvolume(pOrder->MinVolume);
body_message.set_contingentcondition(pOrder->ContingentCondition);
body_message.set_stopprice(pOrder->StopPrice);
body_message.set_forceclosereason(pOrder->ForceCloseReason);
body_message.set_isautosuspend(pOrder->IsAutoSuspend);
body_message.set_businessunit(pOrder->BusinessUnit);
body_message.set_requestid(pOrder->RequestID);
body_message.set_orderlocalid(pOrder->OrderLocalID);
body_message.set_exchangeid(pOrder->ExchangeID);
body_message.set_participantid(pOrder->ParticipantID);
body_message.set_clientid(pOrder->ClientID);
body_message.set_exchangeinstid(pOrder->ExchangeInstID);
body_message.set_traderid(pOrder->TraderID);
body_message.set_installid(pOrder->InstallID);
body_message.set_ordersubmitstatus(pOrder->OrderSubmitStatus);
body_message.set_notifysequence(pOrder->NotifySequence);
body_message.set_tradingday(pOrder->TradingDay);
body_message.set_settlementid(pOrder->SettlementID);
body_message.set_ordersysid(pOrder->OrderSysID);
body_message.set_ordersource(pOrder->OrderSource);
body_message.set_orderstatus(pOrder->OrderStatus);
body_message.set_ordertype(pOrder->OrderType);
body_message.set_volumetraded(pOrder->VolumeTraded);
body_message.set_volumetotal(pOrder->VolumeTotal);
body_message.set_insertdate(pOrder->InsertDate);
body_message.set_inserttime(pOrder->InsertTime);
body_message.set_activetime(pOrder->ActiveTime);
body_message.set_suspendtime(pOrder->SuspendTime);
body_message.set_updatetime(pOrder->UpdateTime);
body_message.set_canceltime(pOrder->CancelTime);
body_message.set_activetraderid(pOrder->ActiveTraderID);
body_message.set_clearingpartid(pOrder->ClearingPartID);
body_message.set_sequenceno(pOrder->SequenceNo);
body_message.set_frontid(pOrder->FrontID);
body_message.set_sessionid(pOrder->SessionID);
body_message.set_userproductinfo(pOrder->UserProductInfo);
body_message.set_statusmsg(pOrder->StatusMsg);
body_message.set_userforceclose(pOrder->UserForceClose);
body_message.set_activeuserid(pOrder->ActiveUserID);
body_message.set_brokerorderseq(pOrder->BrokerOrderSeq);
body_message.set_relativeordersysid(pOrder->RelativeOrderSysID);
body_message.set_zcetotaltradedvolume(pOrder->ZCETotalTradedVolume);
body_message.set_isswaporder(pOrder->IsSwapOrder);
body_message.set_branchid(pOrder->BranchID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcOrderField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询成交响应
void CTraderSpi::OnRspQryTrade(CThostFtdcTradeField* pTrade, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcTradeField body_message;
body_message.set_brokerid(pTrade->BrokerID);
body_message.set_investorid(pTrade->InvestorID);
body_message.set_instrumentid(pTrade->InstrumentID);
body_message.set_orderref(pTrade->OrderRef);
body_message.set_userid(pTrade->UserID);
body_message.set_exchangeid(pTrade->ExchangeID);
body_message.set_tradeid(pTrade->TradeID);
body_message.set_direction(pTrade->Direction);
body_message.set_ordersysid(pTrade->OrderSysID);
body_message.set_participantid(pTrade->ParticipantID);
body_message.set_clientid(pTrade->ClientID);
body_message.set_tradingrole(pTrade->TradingRole);
body_message.set_exchangeinstid(pTrade->ExchangeInstID);
body_message.set_offsetflag(pTrade->OffsetFlag);
body_message.set_hedgeflag(pTrade->HedgeFlag);
body_message.set_price(pTrade->Price);
body_message.set_volume(pTrade->Volume);
body_message.set_tradedate(pTrade->TradeDate);
body_message.set_tradetime(pTrade->TradeTime);
body_message.set_tradetype(pTrade->TradeType);
body_message.set_pricesource(pTrade->PriceSource);
body_message.set_traderid(pTrade->TraderID);
body_message.set_orderlocalid(pTrade->OrderLocalID);
body_message.set_clearingpartid(pTrade->ClearingPartID);
body_message.set_businessunit(pTrade->BusinessUnit);
body_message.set_sequenceno(pTrade->SequenceNo);
body_message.set_tradingday(pTrade->TradingDay);
body_message.set_settlementid(pTrade->SettlementID);
body_message.set_brokerorderseq(pTrade->BrokerOrderSeq);
body_message.set_tradesource(pTrade->TradeSource);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcTradeField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询投资者持仓响应
void CTraderSpi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField* pInvestorPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcInvestorPositionField body_message;
body_message.set_instrumentid(pInvestorPosition->InstrumentID);
body_message.set_brokerid(pInvestorPosition->BrokerID);
body_message.set_investorid(pInvestorPosition->InvestorID);
body_message.set_posidirection(pInvestorPosition->PosiDirection);
body_message.set_hedgeflag(pInvestorPosition->HedgeFlag);
body_message.set_positiondate(pInvestorPosition->PositionDate);
body_message.set_ydposition(pInvestorPosition->YdPosition);
body_message.set_position(pInvestorPosition->Position);
body_message.set_longfrozen(pInvestorPosition->LongFrozen);
body_message.set_shortfrozen(pInvestorPosition->ShortFrozen);
body_message.set_longfrozenamount(pInvestorPosition->LongFrozenAmount);
body_message.set_shortfrozenamount(pInvestorPosition->ShortFrozenAmount);
body_message.set_openvolume(pInvestorPosition->OpenVolume);
body_message.set_closevolume(pInvestorPosition->CloseVolume);
body_message.set_openamount(pInvestorPosition->OpenAmount);
body_message.set_closeamount(pInvestorPosition->CloseAmount);
body_message.set_positioncost(pInvestorPosition->PositionCost);
body_message.set_premargin(pInvestorPosition->PreMargin);
body_message.set_usemargin(pInvestorPosition->UseMargin);
body_message.set_frozenmargin(pInvestorPosition->FrozenMargin);
body_message.set_frozencash(pInvestorPosition->FrozenCash);
body_message.set_frozencommission(pInvestorPosition->FrozenCommission);
body_message.set_cashin(pInvestorPosition->CashIn);
body_message.set_commission(pInvestorPosition->Commission);
body_message.set_closeprofit(pInvestorPosition->CloseProfit);
body_message.set_positionprofit(pInvestorPosition->PositionProfit);
body_message.set_presettlementprice(pInvestorPosition->PreSettlementPrice);
body_message.set_settlementprice(pInvestorPosition->SettlementPrice);
body_message.set_tradingday(pInvestorPosition->TradingDay);
body_message.set_settlementid(pInvestorPosition->SettlementID);
body_message.set_opencost(pInvestorPosition->OpenCost);
body_message.set_exchangemargin(pInvestorPosition->ExchangeMargin);
body_message.set_combposition(pInvestorPosition->CombPosition);
body_message.set_comblongfrozen(pInvestorPosition->CombLongFrozen);
body_message.set_combshortfrozen(pInvestorPosition->CombShortFrozen);
body_message.set_closeprofitbydate(pInvestorPosition->CloseProfitByDate);
body_message.set_closeprofitbytrade(pInvestorPosition->CloseProfitByTrade);
body_message.set_todayposition(pInvestorPosition->TodayPosition);
body_message.set_marginratebymoney(pInvestorPosition->MarginRateByMoney);
body_message.set_marginratebyvolume(pInvestorPosition->MarginRateByVolume);
body_message.set_strikefrozen(pInvestorPosition->StrikeFrozen);
body_message.set_strikefrozenamount(pInvestorPosition->StrikeFrozenAmount);
body_message.set_abandonfrozen(pInvestorPosition->AbandonFrozen);
body_message.set_exchangeid(pInvestorPosition->ExchangeID);
body_message.set_ydstrikefrozen(pInvestorPosition->YdStrikeFrozen);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInvestorPositionField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询资金账户响应
void CTraderSpi::OnRspQryTradingAccount(CThostFtdcTradingAccountField* pTradingAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcTradingAccountField body_message;
body_message.set_brokerid(pTradingAccount->BrokerID);
body_message.set_accountid(pTradingAccount->AccountID);
body_message.set_premortgage(pTradingAccount->PreMortgage);
body_message.set_precredit(pTradingAccount->PreCredit);
body_message.set_predeposit(pTradingAccount->PreDeposit);
body_message.set_prebalance(pTradingAccount->PreBalance);
body_message.set_premargin(pTradingAccount->PreMargin);
body_message.set_interestbase(pTradingAccount->InterestBase);
body_message.set_interest(pTradingAccount->Interest);
body_message.set_deposit(pTradingAccount->Deposit);
body_message.set_withdraw(pTradingAccount->Withdraw);
body_message.set_frozenmargin(pTradingAccount->FrozenMargin);
body_message.set_frozencash(pTradingAccount->FrozenCash);
body_message.set_frozencommission(pTradingAccount->FrozenCommission);
body_message.set_currmargin(pTradingAccount->CurrMargin);
body_message.set_cashin(pTradingAccount->CashIn);
body_message.set_commission(pTradingAccount->Commission);
body_message.set_closeprofit(pTradingAccount->CloseProfit);
body_message.set_positionprofit(pTradingAccount->PositionProfit);
body_message.set_balance(pTradingAccount->Balance);
body_message.set_available(pTradingAccount->Available);
body_message.set_withdrawquota(pTradingAccount->WithdrawQuota);
body_message.set_reserve(pTradingAccount->Reserve);
body_message.set_tradingday(pTradingAccount->TradingDay);
body_message.set_settlementid(pTradingAccount->SettlementID);
body_message.set_credit(pTradingAccount->Credit);
body_message.set_mortgage(pTradingAccount->Mortgage);
body_message.set_exchangemargin(pTradingAccount->ExchangeMargin);
body_message.set_deliverymargin(pTradingAccount->DeliveryMargin);
body_message.set_exchangedeliverymargin(pTradingAccount->ExchangeDeliveryMargin);
body_message.set_reservebalance(pTradingAccount->ReserveBalance);
body_message.set_currencyid(pTradingAccount->CurrencyID);
body_message.set_prefundmortgagein(pTradingAccount->PreFundMortgageIn);
body_message.set_prefundmortgageout(pTradingAccount->PreFundMortgageOut);
body_message.set_fundmortgagein(pTradingAccount->FundMortgageIn);
body_message.set_fundmortgageout(pTradingAccount->FundMortgageOut);
body_message.set_fundmortgageavailable(pTradingAccount->FundMortgageAvailable);
body_message.set_mortgageablefund(pTradingAccount->MortgageableFund);
body_message.set_specproductmargin(pTradingAccount->SpecProductMargin);
body_message.set_specproductfrozenmargin(pTradingAccount->SpecProductFrozenMargin);
body_message.set_specproductcommission(pTradingAccount->SpecProductCommission);
body_message.set_specproductfrozencommission(pTradingAccount->SpecProductFrozenCommission);
body_message.set_specproductpositionprofit(pTradingAccount->SpecProductPositionProfit);
body_message.set_specproductcloseprofit(pTradingAccount->SpecProductCloseProfit);
body_message.set_specproductpositionprofitbyalg(pTradingAccount->SpecProductPositionProfitByAlg);
body_message.set_specproductexchangemargin(pTradingAccount->SpecProductExchangeMargin);
body_message.set_biztype(pTradingAccount->BizType);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcTradingAccountField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询投资者响应
void CTraderSpi::OnRspQryInvestor(CThostFtdcInvestorField* pInvestor, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcInvestorField body_message;
body_message.set_investorid(pInvestor->InvestorID);
body_message.set_brokerid(pInvestor->BrokerID);
body_message.set_investorgroupid(pInvestor->InvestorGroupID);
body_message.set_investorname(pInvestor->InvestorName);
body_message.set_identifiedcardtype(pInvestor->IdentifiedCardType);
body_message.set_identifiedcardno(pInvestor->IdentifiedCardNo);
body_message.set_isactive(pInvestor->IsActive);
body_message.set_telephone(pInvestor->Telephone);
body_message.set_address(pInvestor->Address);
body_message.set_opendate(pInvestor->OpenDate);
body_message.set_mobile(pInvestor->Mobile);
body_message.set_commmodelid(pInvestor->CommModelID);
body_message.set_marginmodelid(pInvestor->MarginModelID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInvestorField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询交易编码响应
void CTraderSpi::OnRspQryTradingCode(CThostFtdcTradingCodeField* pTradingCode, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcTradingCodeField body_message;
body_message.set_investorid(pTradingCode->InvestorID);
body_message.set_brokerid(pTradingCode->BrokerID);
body_message.set_exchangeid(pTradingCode->ExchangeID);
body_message.set_clientid(pTradingCode->ClientID);
body_message.set_isactive(pTradingCode->IsActive);
body_message.set_clientidtype(pTradingCode->ClientIDType);
body_message.set_branchid(pTradingCode->BranchID);
body_message.set_biztype(pTradingCode->BizType);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcTradingCodeField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询合约保证金率响应
void CTraderSpi::OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField* pInstrumentMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcInstrumentMarginRateField body_message;
body_message.set_instrumentid(pInstrumentMarginRate->InstrumentID);
body_message.set_investorrange(pInstrumentMarginRate->InvestorRange);
body_message.set_brokerid(pInstrumentMarginRate->BrokerID);
body_message.set_investorid(pInstrumentMarginRate->InvestorID);
body_message.set_hedgeflag(pInstrumentMarginRate->HedgeFlag);
body_message.set_longmarginratiobymoney(pInstrumentMarginRate->LongMarginRatioByMoney);
body_message.set_longmarginratiobyvolume(pInstrumentMarginRate->LongMarginRatioByVolume);
body_message.set_shortmarginratiobymoney(pInstrumentMarginRate->ShortMarginRatioByMoney);
body_message.set_shortmarginratiobyvolume(pInstrumentMarginRate->ShortMarginRatioByVolume);
body_message.set_isrelative(pInstrumentMarginRate->IsRelative);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInstrumentMarginRateField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询合约手续费率响应
void CTraderSpi::OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField* pInstrumentCommissionRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcInstrumentCommissionRateField body_message;
body_message.set_instrumentid(pInstrumentCommissionRate->InstrumentID);
body_message.set_investorrange(pInstrumentCommissionRate->InvestorRange);
body_message.set_brokerid(pInstrumentCommissionRate->BrokerID);
body_message.set_investorid(pInstrumentCommissionRate->InvestorID);
body_message.set_openratiobymoney(pInstrumentCommissionRate->OpenRatioByMoney);
body_message.set_openratiobyvolume(pInstrumentCommissionRate->OpenRatioByVolume);
body_message.set_closeratiobymoney(pInstrumentCommissionRate->CloseRatioByMoney);
body_message.set_closeratiobyvolume(pInstrumentCommissionRate->CloseRatioByVolume);
body_message.set_closetodayratiobymoney(pInstrumentCommissionRate->CloseTodayRatioByMoney);
body_message.set_closetodayratiobyvolume(pInstrumentCommissionRate->CloseTodayRatioByVolume);
body_message.set_exchangeid(pInstrumentCommissionRate->ExchangeID);
body_message.set_biztype(pInstrumentCommissionRate->BizType);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInstrumentCommissionRateField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询交易所响应
void CTraderSpi::OnRspQryExchange(CThostFtdcExchangeField* pExchange, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcExchangeField body_message;
body_message.set_exchangeid(pExchange->ExchangeID);
body_message.set_exchangename(pExchange->ExchangeName);
body_message.set_exchangeproperty(pExchange->ExchangeProperty);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcExchangeField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询产品响应
void CTraderSpi::OnRspQryProduct(CThostFtdcProductField* pProduct, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcProductField body_message;
body_message.set_productid(pProduct->ProductID);
body_message.set_productname(pProduct->ProductName);
body_message.set_exchangeid(pProduct->ExchangeID);
body_message.set_productclass(pProduct->ProductClass);
body_message.set_volumemultiple(pProduct->VolumeMultiple);
body_message.set_pricetick(pProduct->PriceTick);
body_message.set_maxmarketordervolume(pProduct->MaxMarketOrderVolume);
body_message.set_minmarketordervolume(pProduct->MinMarketOrderVolume);
body_message.set_maxlimitordervolume(pProduct->MaxLimitOrderVolume);
body_message.set_minlimitordervolume(pProduct->MinLimitOrderVolume);
body_message.set_positiontype(pProduct->PositionType);
body_message.set_positiondatetype(pProduct->PositionDateType);
body_message.set_closedealtype(pProduct->CloseDealType);
body_message.set_tradecurrencyid(pProduct->TradeCurrencyID);
body_message.set_mortgagefunduserange(pProduct->MortgageFundUseRange);
body_message.set_exchangeproductid(pProduct->ExchangeProductID);
body_message.set_underlyingmultiple(pProduct->UnderlyingMultiple);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcProductField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询合约响应
void CTraderSpi::OnRspQryInstrument(CThostFtdcInstrumentField* pInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcInstrumentField body_message;
body_message.set_instrumentid(pInstrument->InstrumentID);
body_message.set_exchangeid(pInstrument->ExchangeID);
body_message.set_instrumentname(pInstrument->InstrumentName);
body_message.set_exchangeinstid(pInstrument->ExchangeInstID);
body_message.set_productid(pInstrument->ProductID);
body_message.set_productclass(pInstrument->ProductClass);
body_message.set_deliveryyear(pInstrument->DeliveryYear);
body_message.set_deliverymonth(pInstrument->DeliveryMonth);
body_message.set_maxmarketordervolume(pInstrument->MaxMarketOrderVolume);
body_message.set_minmarketordervolume(pInstrument->MinMarketOrderVolume);
body_message.set_maxlimitordervolume(pInstrument->MaxLimitOrderVolume);
body_message.set_minlimitordervolume(pInstrument->MinLimitOrderVolume);
body_message.set_volumemultiple(pInstrument->VolumeMultiple);
body_message.set_pricetick(pInstrument->PriceTick);
body_message.set_createdate(pInstrument->CreateDate);
body_message.set_opendate(pInstrument->OpenDate);
body_message.set_expiredate(pInstrument->ExpireDate);
body_message.set_startdelivdate(pInstrument->StartDelivDate);
body_message.set_enddelivdate(pInstrument->EndDelivDate);
body_message.set_instlifephase(pInstrument->InstLifePhase);
body_message.set_istrading(pInstrument->IsTrading);
body_message.set_positiontype(pInstrument->PositionType);
body_message.set_positiondatetype(pInstrument->PositionDateType);
body_message.set_longmarginratio(pInstrument->LongMarginRatio);
body_message.set_shortmarginratio(pInstrument->ShortMarginRatio);
body_message.set_maxmarginsidealgorithm(pInstrument->MaxMarginSideAlgorithm);
body_message.set_underlyinginstrid(pInstrument->UnderlyingInstrID);
body_message.set_strikeprice(pInstrument->StrikePrice);
body_message.set_optionstype(pInstrument->OptionsType);
body_message.set_underlyingmultiple(pInstrument->UnderlyingMultiple);
body_message.set_combinationtype(pInstrument->CombinationType);
body_message.set_minbuyvolume(pInstrument->MinBuyVolume);
body_message.set_minsellvolume(pInstrument->MinSellVolume);
body_message.set_instrumentcode(pInstrument->InstrumentCode);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInstrumentField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询行情响应
void CTraderSpi::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
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

///请求查询投资者结算结果响应
void CTraderSpi::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField* pSettlementInfo, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcSettlementInfoField body_message;
body_message.set_tradingday(pSettlementInfo->TradingDay);
body_message.set_settlementid(pSettlementInfo->SettlementID);
body_message.set_brokerid(pSettlementInfo->BrokerID);
body_message.set_investorid(pSettlementInfo->InvestorID);
body_message.set_sequenceno(pSettlementInfo->SequenceNo);
body_message.set_content(pSettlementInfo->Content);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcSettlementInfoField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询转帐银行响应
void CTraderSpi::OnRspQryTransferBank(CThostFtdcTransferBankField* pTransferBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcTransferBankField body_message;
body_message.set_bankid(pTransferBank->BankID);
body_message.set_bankbrchid(pTransferBank->BankBrchID);
body_message.set_bankname(pTransferBank->BankName);
body_message.set_isactive(pTransferBank->IsActive);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcTransferBankField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询投资者持仓明细响应
void CTraderSpi::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField* pInvestorPositionDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcInvestorPositionDetailField body_message;
body_message.set_instrumentid(pInvestorPositionDetail->InstrumentID);
body_message.set_brokerid(pInvestorPositionDetail->BrokerID);
body_message.set_investorid(pInvestorPositionDetail->InvestorID);
body_message.set_hedgeflag(pInvestorPositionDetail->HedgeFlag);
body_message.set_direction(pInvestorPositionDetail->Direction);
body_message.set_opendate(pInvestorPositionDetail->OpenDate);
body_message.set_tradeid(pInvestorPositionDetail->TradeID);
body_message.set_volume(pInvestorPositionDetail->Volume);
body_message.set_openprice(pInvestorPositionDetail->OpenPrice);
body_message.set_tradingday(pInvestorPositionDetail->TradingDay);
body_message.set_settlementid(pInvestorPositionDetail->SettlementID);
body_message.set_tradetype(pInvestorPositionDetail->TradeType);
body_message.set_combinstrumentid(pInvestorPositionDetail->CombInstrumentID);
body_message.set_exchangeid(pInvestorPositionDetail->ExchangeID);
body_message.set_closeprofitbydate(pInvestorPositionDetail->CloseProfitByDate);
body_message.set_closeprofitbytrade(pInvestorPositionDetail->CloseProfitByTrade);
body_message.set_positionprofitbydate(pInvestorPositionDetail->PositionProfitByDate);
body_message.set_positionprofitbytrade(pInvestorPositionDetail->PositionProfitByTrade);
body_message.set_margin(pInvestorPositionDetail->Margin);
body_message.set_exchmargin(pInvestorPositionDetail->ExchMargin);
body_message.set_marginratebymoney(pInvestorPositionDetail->MarginRateByMoney);
body_message.set_marginratebyvolume(pInvestorPositionDetail->MarginRateByVolume);
body_message.set_lastsettlementprice(pInvestorPositionDetail->LastSettlementPrice);
body_message.set_settlementprice(pInvestorPositionDetail->SettlementPrice);
body_message.set_closevolume(pInvestorPositionDetail->CloseVolume);
body_message.set_closeamount(pInvestorPositionDetail->CloseAmount);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInvestorPositionDetailField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询客户通知响应
void CTraderSpi::OnRspQryNotice(CThostFtdcNoticeField* pNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcNoticeField body_message;
body_message.set_brokerid(pNotice->BrokerID);
body_message.set_content(pNotice->Content);
body_message.set_sequencelabel(pNotice->SequenceLabel);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcNoticeField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询结算信息确认响应
void CTraderSpi::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField* pSettlementInfoConfirm, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcSettlementInfoConfirmField body_message;
body_message.set_brokerid(pSettlementInfoConfirm->BrokerID);
body_message.set_investorid(pSettlementInfoConfirm->InvestorID);
body_message.set_confirmdate(pSettlementInfoConfirm->ConfirmDate);
body_message.set_confirmtime(pSettlementInfoConfirm->ConfirmTime);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcSettlementInfoConfirmField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询投资者持仓明细响应
void CTraderSpi::OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField* pInvestorPositionCombineDetail, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcInvestorPositionCombineDetailField body_message;
body_message.set_tradingday(pInvestorPositionCombineDetail->TradingDay);
body_message.set_opendate(pInvestorPositionCombineDetail->OpenDate);
body_message.set_exchangeid(pInvestorPositionCombineDetail->ExchangeID);
body_message.set_settlementid(pInvestorPositionCombineDetail->SettlementID);
body_message.set_brokerid(pInvestorPositionCombineDetail->BrokerID);
body_message.set_investorid(pInvestorPositionCombineDetail->InvestorID);
body_message.set_comtradeid(pInvestorPositionCombineDetail->ComTradeID);
body_message.set_tradeid(pInvestorPositionCombineDetail->TradeID);
body_message.set_instrumentid(pInvestorPositionCombineDetail->InstrumentID);
body_message.set_hedgeflag(pInvestorPositionCombineDetail->HedgeFlag);
body_message.set_direction(pInvestorPositionCombineDetail->Direction);
body_message.set_totalamt(pInvestorPositionCombineDetail->TotalAmt);
body_message.set_margin(pInvestorPositionCombineDetail->Margin);
body_message.set_exchmargin(pInvestorPositionCombineDetail->ExchMargin);
body_message.set_marginratebymoney(pInvestorPositionCombineDetail->MarginRateByMoney);
body_message.set_marginratebyvolume(pInvestorPositionCombineDetail->MarginRateByVolume);
body_message.set_legid(pInvestorPositionCombineDetail->LegID);
body_message.set_legmultiple(pInvestorPositionCombineDetail->LegMultiple);
body_message.set_combinstrumentid(pInvestorPositionCombineDetail->CombInstrumentID);
body_message.set_tradegroupid(pInvestorPositionCombineDetail->TradeGroupID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInvestorPositionCombineDetailField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///查询保证金监管系统经纪公司资金账户密钥响应
void CTraderSpi::OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField* pCFMMCTradingAccountKey, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcCFMMCTradingAccountKeyField body_message;
body_message.set_brokerid(pCFMMCTradingAccountKey->BrokerID);
body_message.set_participantid(pCFMMCTradingAccountKey->ParticipantID);
body_message.set_accountid(pCFMMCTradingAccountKey->AccountID);
body_message.set_keyid(pCFMMCTradingAccountKey->KeyID);
body_message.set_currentkey(pCFMMCTradingAccountKey->CurrentKey);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcCFMMCTradingAccountKeyField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询仓单折抵信息响应
void CTraderSpi::OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField* pEWarrantOffset, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcEWarrantOffsetField body_message;
body_message.set_tradingday(pEWarrantOffset->TradingDay);
body_message.set_brokerid(pEWarrantOffset->BrokerID);
body_message.set_investorid(pEWarrantOffset->InvestorID);
body_message.set_exchangeid(pEWarrantOffset->ExchangeID);
body_message.set_instrumentid(pEWarrantOffset->InstrumentID);
body_message.set_direction(pEWarrantOffset->Direction);
body_message.set_hedgeflag(pEWarrantOffset->HedgeFlag);
body_message.set_volume(pEWarrantOffset->Volume);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcEWarrantOffsetField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询投资者品种/跨品种保证金响应
void CTraderSpi::OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField* pInvestorProductGroupMargin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcInvestorProductGroupMarginField body_message;
body_message.set_productgroupid(pInvestorProductGroupMargin->ProductGroupID);
body_message.set_brokerid(pInvestorProductGroupMargin->BrokerID);
body_message.set_investorid(pInvestorProductGroupMargin->InvestorID);
body_message.set_tradingday(pInvestorProductGroupMargin->TradingDay);
body_message.set_settlementid(pInvestorProductGroupMargin->SettlementID);
body_message.set_frozenmargin(pInvestorProductGroupMargin->FrozenMargin);
body_message.set_longfrozenmargin(pInvestorProductGroupMargin->LongFrozenMargin);
body_message.set_shortfrozenmargin(pInvestorProductGroupMargin->ShortFrozenMargin);
body_message.set_usemargin(pInvestorProductGroupMargin->UseMargin);
body_message.set_longusemargin(pInvestorProductGroupMargin->LongUseMargin);
body_message.set_shortusemargin(pInvestorProductGroupMargin->ShortUseMargin);
body_message.set_exchmargin(pInvestorProductGroupMargin->ExchMargin);
body_message.set_longexchmargin(pInvestorProductGroupMargin->LongExchMargin);
body_message.set_shortexchmargin(pInvestorProductGroupMargin->ShortExchMargin);
body_message.set_closeprofit(pInvestorProductGroupMargin->CloseProfit);
body_message.set_frozencommission(pInvestorProductGroupMargin->FrozenCommission);
body_message.set_commission(pInvestorProductGroupMargin->Commission);
body_message.set_frozencash(pInvestorProductGroupMargin->FrozenCash);
body_message.set_cashin(pInvestorProductGroupMargin->CashIn);
body_message.set_positionprofit(pInvestorProductGroupMargin->PositionProfit);
body_message.set_offsetamount(pInvestorProductGroupMargin->OffsetAmount);
body_message.set_longoffsetamount(pInvestorProductGroupMargin->LongOffsetAmount);
body_message.set_shortoffsetamount(pInvestorProductGroupMargin->ShortOffsetAmount);
body_message.set_exchoffsetamount(pInvestorProductGroupMargin->ExchOffsetAmount);
body_message.set_longexchoffsetamount(pInvestorProductGroupMargin->LongExchOffsetAmount);
body_message.set_shortexchoffsetamount(pInvestorProductGroupMargin->ShortExchOffsetAmount);
body_message.set_hedgeflag(pInvestorProductGroupMargin->HedgeFlag);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInvestorProductGroupMarginField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询交易所保证金率响应
void CTraderSpi::OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField* pExchangeMarginRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcExchangeMarginRateField body_message;
body_message.set_brokerid(pExchangeMarginRate->BrokerID);
body_message.set_instrumentid(pExchangeMarginRate->InstrumentID);
body_message.set_hedgeflag(pExchangeMarginRate->HedgeFlag);
body_message.set_longmarginratiobymoney(pExchangeMarginRate->LongMarginRatioByMoney);
body_message.set_longmarginratiobyvolume(pExchangeMarginRate->LongMarginRatioByVolume);
body_message.set_shortmarginratiobymoney(pExchangeMarginRate->ShortMarginRatioByMoney);
body_message.set_shortmarginratiobyvolume(pExchangeMarginRate->ShortMarginRatioByVolume);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcExchangeMarginRateField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询交易所调整保证金率响应
void CTraderSpi::OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField* pExchangeMarginRateAdjust, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcExchangeMarginRateAdjustField body_message;
body_message.set_brokerid(pExchangeMarginRateAdjust->BrokerID);
body_message.set_instrumentid(pExchangeMarginRateAdjust->InstrumentID);
body_message.set_hedgeflag(pExchangeMarginRateAdjust->HedgeFlag);
body_message.set_longmarginratiobymoney(pExchangeMarginRateAdjust->LongMarginRatioByMoney);
body_message.set_longmarginratiobyvolume(pExchangeMarginRateAdjust->LongMarginRatioByVolume);
body_message.set_shortmarginratiobymoney(pExchangeMarginRateAdjust->ShortMarginRatioByMoney);
body_message.set_shortmarginratiobyvolume(pExchangeMarginRateAdjust->ShortMarginRatioByVolume);
body_message.set_exchlongmarginratiobymoney(pExchangeMarginRateAdjust->ExchLongMarginRatioByMoney);
body_message.set_exchlongmarginratiobyvolume(pExchangeMarginRateAdjust->ExchLongMarginRatioByVolume);
body_message.set_exchshortmarginratiobymoney(pExchangeMarginRateAdjust->ExchShortMarginRatioByMoney);
body_message.set_exchshortmarginratiobyvolume(pExchangeMarginRateAdjust->ExchShortMarginRatioByVolume);
body_message.set_nolongmarginratiobymoney(pExchangeMarginRateAdjust->NoLongMarginRatioByMoney);
body_message.set_nolongmarginratiobyvolume(pExchangeMarginRateAdjust->NoLongMarginRatioByVolume);
body_message.set_noshortmarginratiobymoney(pExchangeMarginRateAdjust->NoShortMarginRatioByMoney);
body_message.set_noshortmarginratiobyvolume(pExchangeMarginRateAdjust->NoShortMarginRatioByVolume);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcExchangeMarginRateAdjustField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询汇率响应
void CTraderSpi::OnRspQryExchangeRate(CThostFtdcExchangeRateField* pExchangeRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcExchangeRateField body_message;
body_message.set_brokerid(pExchangeRate->BrokerID);
body_message.set_fromcurrencyid(pExchangeRate->FromCurrencyID);
body_message.set_fromcurrencyunit(pExchangeRate->FromCurrencyUnit);
body_message.set_tocurrencyid(pExchangeRate->ToCurrencyID);
body_message.set_exchangerate(pExchangeRate->ExchangeRate);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcExchangeRateField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询二级代理操作员银期权限响应
void CTraderSpi::OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField* pSecAgentACIDMap, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcSecAgentACIDMapField body_message;
body_message.set_brokerid(pSecAgentACIDMap->BrokerID);
body_message.set_userid(pSecAgentACIDMap->UserID);
body_message.set_accountid(pSecAgentACIDMap->AccountID);
body_message.set_currencyid(pSecAgentACIDMap->CurrencyID);
body_message.set_brokersecagentid(pSecAgentACIDMap->BrokerSecAgentID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcSecAgentACIDMapField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询产品报价汇率
void CTraderSpi::OnRspQryProductExchRate(CThostFtdcProductExchRateField* pProductExchRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcProductExchRateField body_message;
body_message.set_productid(pProductExchRate->ProductID);
body_message.set_quotecurrencyid(pProductExchRate->QuoteCurrencyID);
body_message.set_exchangerate(pProductExchRate->ExchangeRate);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcProductExchRateField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询产品组
void CTraderSpi::OnRspQryProductGroup(CThostFtdcProductGroupField* pProductGroup, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcProductGroupField body_message;
body_message.set_productid(pProductGroup->ProductID);
body_message.set_exchangeid(pProductGroup->ExchangeID);
body_message.set_productgroupid(pProductGroup->ProductGroupID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcProductGroupField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询期权交易成本响应
void CTraderSpi::OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField* pOptionInstrTradeCost, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcOptionInstrTradeCostField body_message;
body_message.set_brokerid(pOptionInstrTradeCost->BrokerID);
body_message.set_investorid(pOptionInstrTradeCost->InvestorID);
body_message.set_instrumentid(pOptionInstrTradeCost->InstrumentID);
body_message.set_hedgeflag(pOptionInstrTradeCost->HedgeFlag);
body_message.set_fixedmargin(pOptionInstrTradeCost->FixedMargin);
body_message.set_minimargin(pOptionInstrTradeCost->MiniMargin);
body_message.set_royalty(pOptionInstrTradeCost->Royalty);
body_message.set_exchfixedmargin(pOptionInstrTradeCost->ExchFixedMargin);
body_message.set_exchminimargin(pOptionInstrTradeCost->ExchMiniMargin);
body_message.set_exchangeid(pOptionInstrTradeCost->ExchangeID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcOptionInstrTradeCostField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询期权合约手续费响应
void CTraderSpi::OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField* pOptionInstrCommRate, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcOptionInstrCommRateField body_message;
body_message.set_instrumentid(pOptionInstrCommRate->InstrumentID);
body_message.set_investorrange(pOptionInstrCommRate->InvestorRange);
body_message.set_brokerid(pOptionInstrCommRate->BrokerID);
body_message.set_investorid(pOptionInstrCommRate->InvestorID);
body_message.set_openratiobymoney(pOptionInstrCommRate->OpenRatioByMoney);
body_message.set_openratiobyvolume(pOptionInstrCommRate->OpenRatioByVolume);
body_message.set_closeratiobymoney(pOptionInstrCommRate->CloseRatioByMoney);
body_message.set_closeratiobyvolume(pOptionInstrCommRate->CloseRatioByVolume);
body_message.set_closetodayratiobymoney(pOptionInstrCommRate->CloseTodayRatioByMoney);
body_message.set_closetodayratiobyvolume(pOptionInstrCommRate->CloseTodayRatioByVolume);
body_message.set_strikeratiobymoney(pOptionInstrCommRate->StrikeRatioByMoney);
body_message.set_strikeratiobyvolume(pOptionInstrCommRate->StrikeRatioByVolume);
body_message.set_exchangeid(pOptionInstrCommRate->ExchangeID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcOptionInstrCommRateField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询执行宣告响应
void CTraderSpi::OnRspQryExecOrder(CThostFtdcExecOrderField* pExecOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcExecOrderField body_message;
body_message.set_brokerid(pExecOrder->BrokerID);
body_message.set_investorid(pExecOrder->InvestorID);
body_message.set_instrumentid(pExecOrder->InstrumentID);
body_message.set_execorderref(pExecOrder->ExecOrderRef);
body_message.set_userid(pExecOrder->UserID);
body_message.set_volume(pExecOrder->Volume);
body_message.set_requestid(pExecOrder->RequestID);
body_message.set_businessunit(pExecOrder->BusinessUnit);
body_message.set_offsetflag(pExecOrder->OffsetFlag);
body_message.set_hedgeflag(pExecOrder->HedgeFlag);
body_message.set_actiontype(pExecOrder->ActionType);
body_message.set_posidirection(pExecOrder->PosiDirection);
body_message.set_reservepositionflag(pExecOrder->ReservePositionFlag);
body_message.set_closeflag(pExecOrder->CloseFlag);
body_message.set_execorderlocalid(pExecOrder->ExecOrderLocalID);
body_message.set_exchangeid(pExecOrder->ExchangeID);
body_message.set_participantid(pExecOrder->ParticipantID);
body_message.set_clientid(pExecOrder->ClientID);
body_message.set_exchangeinstid(pExecOrder->ExchangeInstID);
body_message.set_traderid(pExecOrder->TraderID);
body_message.set_installid(pExecOrder->InstallID);
body_message.set_ordersubmitstatus(pExecOrder->OrderSubmitStatus);
body_message.set_notifysequence(pExecOrder->NotifySequence);
body_message.set_tradingday(pExecOrder->TradingDay);
body_message.set_settlementid(pExecOrder->SettlementID);
body_message.set_execordersysid(pExecOrder->ExecOrderSysID);
body_message.set_insertdate(pExecOrder->InsertDate);
body_message.set_inserttime(pExecOrder->InsertTime);
body_message.set_canceltime(pExecOrder->CancelTime);
body_message.set_execresult(pExecOrder->ExecResult);
body_message.set_clearingpartid(pExecOrder->ClearingPartID);
body_message.set_sequenceno(pExecOrder->SequenceNo);
body_message.set_frontid(pExecOrder->FrontID);
body_message.set_sessionid(pExecOrder->SessionID);
body_message.set_userproductinfo(pExecOrder->UserProductInfo);
body_message.set_statusmsg(pExecOrder->StatusMsg);
body_message.set_activeuserid(pExecOrder->ActiveUserID);
body_message.set_brokerexecorderseq(pExecOrder->BrokerExecOrderSeq);
body_message.set_branchid(pExecOrder->BranchID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcExecOrderField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询询价响应
void CTraderSpi::OnRspQryForQuote(CThostFtdcForQuoteField* pForQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcForQuoteField body_message;
body_message.set_brokerid(pForQuote->BrokerID);
body_message.set_investorid(pForQuote->InvestorID);
body_message.set_instrumentid(pForQuote->InstrumentID);
body_message.set_forquoteref(pForQuote->ForQuoteRef);
body_message.set_userid(pForQuote->UserID);
body_message.set_forquotelocalid(pForQuote->ForQuoteLocalID);
body_message.set_exchangeid(pForQuote->ExchangeID);
body_message.set_participantid(pForQuote->ParticipantID);
body_message.set_clientid(pForQuote->ClientID);
body_message.set_exchangeinstid(pForQuote->ExchangeInstID);
body_message.set_traderid(pForQuote->TraderID);
body_message.set_installid(pForQuote->InstallID);
body_message.set_insertdate(pForQuote->InsertDate);
body_message.set_inserttime(pForQuote->InsertTime);
body_message.set_forquotestatus(pForQuote->ForQuoteStatus);
body_message.set_frontid(pForQuote->FrontID);
body_message.set_sessionid(pForQuote->SessionID);
body_message.set_statusmsg(pForQuote->StatusMsg);
body_message.set_activeuserid(pForQuote->ActiveUserID);
body_message.set_brokerforqutoseq(pForQuote->BrokerForQutoSeq);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcForQuoteField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询报价响应
void CTraderSpi::OnRspQryQuote(CThostFtdcQuoteField* pQuote, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcQuoteField body_message;
body_message.set_brokerid(pQuote->BrokerID);
body_message.set_investorid(pQuote->InvestorID);
body_message.set_instrumentid(pQuote->InstrumentID);
body_message.set_quoteref(pQuote->QuoteRef);
body_message.set_userid(pQuote->UserID);
body_message.set_askprice(pQuote->AskPrice);
body_message.set_bidprice(pQuote->BidPrice);
body_message.set_askvolume(pQuote->AskVolume);
body_message.set_bidvolume(pQuote->BidVolume);
body_message.set_requestid(pQuote->RequestID);
body_message.set_businessunit(pQuote->BusinessUnit);
body_message.set_askoffsetflag(pQuote->AskOffsetFlag);
body_message.set_bidoffsetflag(pQuote->BidOffsetFlag);
body_message.set_askhedgeflag(pQuote->AskHedgeFlag);
body_message.set_bidhedgeflag(pQuote->BidHedgeFlag);
body_message.set_quotelocalid(pQuote->QuoteLocalID);
body_message.set_exchangeid(pQuote->ExchangeID);
body_message.set_participantid(pQuote->ParticipantID);
body_message.set_clientid(pQuote->ClientID);
body_message.set_exchangeinstid(pQuote->ExchangeInstID);
body_message.set_traderid(pQuote->TraderID);
body_message.set_installid(pQuote->InstallID);
body_message.set_notifysequence(pQuote->NotifySequence);
body_message.set_ordersubmitstatus(pQuote->OrderSubmitStatus);
body_message.set_tradingday(pQuote->TradingDay);
body_message.set_settlementid(pQuote->SettlementID);
body_message.set_quotesysid(pQuote->QuoteSysID);
body_message.set_insertdate(pQuote->InsertDate);
body_message.set_inserttime(pQuote->InsertTime);
body_message.set_canceltime(pQuote->CancelTime);
body_message.set_quotestatus(pQuote->QuoteStatus);
body_message.set_clearingpartid(pQuote->ClearingPartID);
body_message.set_sequenceno(pQuote->SequenceNo);
body_message.set_askordersysid(pQuote->AskOrderSysID);
body_message.set_bidordersysid(pQuote->BidOrderSysID);
body_message.set_frontid(pQuote->FrontID);
body_message.set_sessionid(pQuote->SessionID);
body_message.set_userproductinfo(pQuote->UserProductInfo);
body_message.set_statusmsg(pQuote->StatusMsg);
body_message.set_activeuserid(pQuote->ActiveUserID);
body_message.set_brokerquoteseq(pQuote->BrokerQuoteSeq);
body_message.set_askorderref(pQuote->AskOrderRef);
body_message.set_bidorderref(pQuote->BidOrderRef);
body_message.set_forquotesysid(pQuote->ForQuoteSysID);
body_message.set_branchid(pQuote->BranchID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcQuoteField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询锁定应答
void CTraderSpi::OnRspQryLock(CThostFtdcLockField* pLock, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcLockField body_message;
body_message.set_brokerid(pLock->BrokerID);
body_message.set_investorid(pLock->InvestorID);
body_message.set_instrumentid(pLock->InstrumentID);
body_message.set_lockref(pLock->LockRef);
body_message.set_userid(pLock->UserID);
body_message.set_volume(pLock->Volume);
body_message.set_requestid(pLock->RequestID);
body_message.set_businessunit(pLock->BusinessUnit);
body_message.set_locktype(pLock->LockType);
body_message.set_locklocalid(pLock->LockLocalID);
body_message.set_exchangeid(pLock->ExchangeID);
body_message.set_participantid(pLock->ParticipantID);
body_message.set_clientid(pLock->ClientID);
body_message.set_exchangeinstid(pLock->ExchangeInstID);
body_message.set_traderid(pLock->TraderID);
body_message.set_installid(pLock->InstallID);
body_message.set_ordersubmitstatus(pLock->OrderSubmitStatus);
body_message.set_notifysequence(pLock->NotifySequence);
body_message.set_tradingday(pLock->TradingDay);
body_message.set_settlementid(pLock->SettlementID);
body_message.set_locksysid(pLock->LockSysID);
body_message.set_insertdate(pLock->InsertDate);
body_message.set_inserttime(pLock->InsertTime);
body_message.set_canceltime(pLock->CancelTime);
body_message.set_lockstatus(pLock->LockStatus);
body_message.set_clearingpartid(pLock->ClearingPartID);
body_message.set_sequenceno(pLock->SequenceNo);
body_message.set_frontid(pLock->FrontID);
body_message.set_sessionid(pLock->SessionID);
body_message.set_userproductinfo(pLock->UserProductInfo);
body_message.set_statusmsg(pLock->StatusMsg);
body_message.set_activeuserid(pLock->ActiveUserID);
body_message.set_brokerlockseq(pLock->BrokerLockSeq);
body_message.set_branchid(pLock->BranchID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcLockField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询锁定证券仓位应答
void CTraderSpi::OnRspQryLockPosition(CThostFtdcLockPositionField* pLockPosition, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcLockPositionField body_message;
body_message.set_brokerid(pLockPosition->BrokerID);
body_message.set_investorid(pLockPosition->InvestorID);
body_message.set_instrumentid(pLockPosition->InstrumentID);
body_message.set_exchangeid(pLockPosition->ExchangeID);
body_message.set_volume(pLockPosition->Volume);
body_message.set_frozenvolume(pLockPosition->FrozenVolume);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcLockPositionField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询投资者分级
void CTraderSpi::OnRspQryInvestorLevel(CThostFtdcInvestorLevelField* pInvestorLevel, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcInvestorLevelField body_message;
body_message.set_brokerid(pInvestorLevel->BrokerID);
body_message.set_investorid(pInvestorLevel->InvestorID);
body_message.set_exchangeid(pInvestorLevel->ExchangeID);
body_message.set_leveltype(pInvestorLevel->LevelType);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInvestorLevelField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询E+1日行权冻结响应
void CTraderSpi::OnRspQryExecFreeze(CThostFtdcExecFreezeField* pExecFreeze, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcExecFreezeField body_message;
body_message.set_instrumentid(pExecFreeze->InstrumentID);
body_message.set_exchangeid(pExecFreeze->ExchangeID);
body_message.set_brokerid(pExecFreeze->BrokerID);
body_message.set_investorid(pExecFreeze->InvestorID);
body_message.set_posidirection(pExecFreeze->PosiDirection);
body_message.set_optionstype(pExecFreeze->OptionsType);
body_message.set_volume(pExecFreeze->Volume);
body_message.set_frozenamount(pExecFreeze->FrozenAmount);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcExecFreezeField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询组合合约安全系数响应
void CTraderSpi::OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField* pCombInstrumentGuard, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcCombInstrumentGuardField body_message;
body_message.set_brokerid(pCombInstrumentGuard->BrokerID);
body_message.set_instrumentid(pCombInstrumentGuard->InstrumentID);
body_message.set_guarantratio(pCombInstrumentGuard->GuarantRatio);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcCombInstrumentGuardField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询申请组合响应
void CTraderSpi::OnRspQryCombAction(CThostFtdcCombActionField* pCombAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcCombActionField body_message;
body_message.set_brokerid(pCombAction->BrokerID);
body_message.set_investorid(pCombAction->InvestorID);
body_message.set_instrumentid(pCombAction->InstrumentID);
body_message.set_combactionref(pCombAction->CombActionRef);
body_message.set_userid(pCombAction->UserID);
body_message.set_direction(pCombAction->Direction);
body_message.set_volume(pCombAction->Volume);
body_message.set_combdirection(pCombAction->CombDirection);
body_message.set_hedgeflag(pCombAction->HedgeFlag);
body_message.set_actionlocalid(pCombAction->ActionLocalID);
body_message.set_exchangeid(pCombAction->ExchangeID);
body_message.set_participantid(pCombAction->ParticipantID);
body_message.set_clientid(pCombAction->ClientID);
body_message.set_exchangeinstid(pCombAction->ExchangeInstID);
body_message.set_traderid(pCombAction->TraderID);
body_message.set_installid(pCombAction->InstallID);
body_message.set_actionstatus(pCombAction->ActionStatus);
body_message.set_notifysequence(pCombAction->NotifySequence);
body_message.set_tradingday(pCombAction->TradingDay);
body_message.set_settlementid(pCombAction->SettlementID);
body_message.set_sequenceno(pCombAction->SequenceNo);
body_message.set_frontid(pCombAction->FrontID);
body_message.set_sessionid(pCombAction->SessionID);
body_message.set_userproductinfo(pCombAction->UserProductInfo);
body_message.set_statusmsg(pCombAction->StatusMsg);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcCombActionField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询转帐流水响应
void CTraderSpi::OnRspQryTransferSerial(CThostFtdcTransferSerialField* pTransferSerial, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcTransferSerialField body_message;
body_message.set_plateserial(pTransferSerial->PlateSerial);
body_message.set_tradedate(pTransferSerial->TradeDate);
body_message.set_tradingday(pTransferSerial->TradingDay);
body_message.set_tradetime(pTransferSerial->TradeTime);
body_message.set_tradecode(pTransferSerial->TradeCode);
body_message.set_sessionid(pTransferSerial->SessionID);
body_message.set_bankid(pTransferSerial->BankID);
body_message.set_bankbranchid(pTransferSerial->BankBranchID);
body_message.set_bankacctype(pTransferSerial->BankAccType);
body_message.set_bankaccount(pTransferSerial->BankAccount);
body_message.set_bankserial(pTransferSerial->BankSerial);
body_message.set_brokerid(pTransferSerial->BrokerID);
body_message.set_brokerbranchid(pTransferSerial->BrokerBranchID);
body_message.set_futureacctype(pTransferSerial->FutureAccType);
body_message.set_accountid(pTransferSerial->AccountID);
body_message.set_investorid(pTransferSerial->InvestorID);
body_message.set_futureserial(pTransferSerial->FutureSerial);
body_message.set_idcardtype(pTransferSerial->IdCardType);
body_message.set_identifiedcardno(pTransferSerial->IdentifiedCardNo);
body_message.set_currencyid(pTransferSerial->CurrencyID);
body_message.set_tradeamount(pTransferSerial->TradeAmount);
body_message.set_custfee(pTransferSerial->CustFee);
body_message.set_brokerfee(pTransferSerial->BrokerFee);
body_message.set_availabilityflag(pTransferSerial->AvailabilityFlag);
body_message.set_operatorcode(pTransferSerial->OperatorCode);
body_message.set_banknewaccount(pTransferSerial->BankNewAccount);
body_message.set_errorid(pTransferSerial->ErrorID);
body_message.set_errormsg(pTransferSerial->ErrorMsg);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcTransferSerialField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询银期签约关系响应
void CTraderSpi::OnRspQryAccountregister(CThostFtdcAccountregisterField* pAccountregister, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcAccountregisterField body_message;
body_message.set_tradeday(pAccountregister->TradeDay);
body_message.set_bankid(pAccountregister->BankID);
body_message.set_bankbranchid(pAccountregister->BankBranchID);
body_message.set_bankaccount(pAccountregister->BankAccount);
body_message.set_brokerid(pAccountregister->BrokerID);
body_message.set_brokerbranchid(pAccountregister->BrokerBranchID);
body_message.set_accountid(pAccountregister->AccountID);
body_message.set_idcardtype(pAccountregister->IdCardType);
body_message.set_identifiedcardno(pAccountregister->IdentifiedCardNo);
body_message.set_customername(pAccountregister->CustomerName);
body_message.set_currencyid(pAccountregister->CurrencyID);
body_message.set_openordestroy(pAccountregister->OpenOrDestroy);
body_message.set_regdate(pAccountregister->RegDate);
body_message.set_outdate(pAccountregister->OutDate);
body_message.set_tid(pAccountregister->TID);
body_message.set_custtype(pAccountregister->CustType);
body_message.set_bankacctype(pAccountregister->BankAccType);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcAccountregisterField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///错误应答
void CTraderSpi::OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcRspInfoField body_message;
body_message.set_errorid(pRspInfo->ErrorID);
body_message.set_errormsg(pRspInfo->ErrorMsg);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcRspInfoField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///报单通知
void CTraderSpi::OnRtnOrder(CThostFtdcOrderField* pOrder)
{
guosen::msg::ctp::CThostFtdcOrderField body_message;
body_message.set_brokerid(pOrder->BrokerID);
body_message.set_investorid(pOrder->InvestorID);
body_message.set_instrumentid(pOrder->InstrumentID);
body_message.set_orderref(pOrder->OrderRef);
body_message.set_userid(pOrder->UserID);
body_message.set_orderpricetype(pOrder->OrderPriceType);
body_message.set_direction(pOrder->Direction);
body_message.set_comboffsetflag(pOrder->CombOffsetFlag);
body_message.set_combhedgeflag(pOrder->CombHedgeFlag);
body_message.set_limitprice(pOrder->LimitPrice);
body_message.set_volumetotaloriginal(pOrder->VolumeTotalOriginal);
body_message.set_timecondition(pOrder->TimeCondition);
body_message.set_gtddate(pOrder->GTDDate);
body_message.set_volumecondition(pOrder->VolumeCondition);
body_message.set_minvolume(pOrder->MinVolume);
body_message.set_contingentcondition(pOrder->ContingentCondition);
body_message.set_stopprice(pOrder->StopPrice);
body_message.set_forceclosereason(pOrder->ForceCloseReason);
body_message.set_isautosuspend(pOrder->IsAutoSuspend);
body_message.set_businessunit(pOrder->BusinessUnit);
body_message.set_requestid(pOrder->RequestID);
body_message.set_orderlocalid(pOrder->OrderLocalID);
body_message.set_exchangeid(pOrder->ExchangeID);
body_message.set_participantid(pOrder->ParticipantID);
body_message.set_clientid(pOrder->ClientID);
body_message.set_exchangeinstid(pOrder->ExchangeInstID);
body_message.set_traderid(pOrder->TraderID);
body_message.set_installid(pOrder->InstallID);
body_message.set_ordersubmitstatus(pOrder->OrderSubmitStatus);
body_message.set_notifysequence(pOrder->NotifySequence);
body_message.set_tradingday(pOrder->TradingDay);
body_message.set_settlementid(pOrder->SettlementID);
body_message.set_ordersysid(pOrder->OrderSysID);
body_message.set_ordersource(pOrder->OrderSource);
body_message.set_orderstatus(pOrder->OrderStatus);
body_message.set_ordertype(pOrder->OrderType);
body_message.set_volumetraded(pOrder->VolumeTraded);
body_message.set_volumetotal(pOrder->VolumeTotal);
body_message.set_insertdate(pOrder->InsertDate);
body_message.set_inserttime(pOrder->InsertTime);
body_message.set_activetime(pOrder->ActiveTime);
body_message.set_suspendtime(pOrder->SuspendTime);
body_message.set_updatetime(pOrder->UpdateTime);
body_message.set_canceltime(pOrder->CancelTime);
body_message.set_activetraderid(pOrder->ActiveTraderID);
body_message.set_clearingpartid(pOrder->ClearingPartID);
body_message.set_sequenceno(pOrder->SequenceNo);
body_message.set_frontid(pOrder->FrontID);
body_message.set_sessionid(pOrder->SessionID);
body_message.set_userproductinfo(pOrder->UserProductInfo);
body_message.set_statusmsg(pOrder->StatusMsg);
body_message.set_userforceclose(pOrder->UserForceClose);
body_message.set_activeuserid(pOrder->ActiveUserID);
body_message.set_brokerorderseq(pOrder->BrokerOrderSeq);
body_message.set_relativeordersysid(pOrder->RelativeOrderSysID);
body_message.set_zcetotaltradedvolume(pOrder->ZCETotalTradedVolume);
body_message.set_isswaporder(pOrder->IsSwapOrder);
body_message.set_branchid(pOrder->BranchID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcOrderField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///成交通知
void CTraderSpi::OnRtnTrade(CThostFtdcTradeField* pTrade)
{
guosen::msg::ctp::CThostFtdcTradeField body_message;
body_message.set_brokerid(pTrade->BrokerID);
body_message.set_investorid(pTrade->InvestorID);
body_message.set_instrumentid(pTrade->InstrumentID);
body_message.set_orderref(pTrade->OrderRef);
body_message.set_userid(pTrade->UserID);
body_message.set_exchangeid(pTrade->ExchangeID);
body_message.set_tradeid(pTrade->TradeID);
body_message.set_direction(pTrade->Direction);
body_message.set_ordersysid(pTrade->OrderSysID);
body_message.set_participantid(pTrade->ParticipantID);
body_message.set_clientid(pTrade->ClientID);
body_message.set_tradingrole(pTrade->TradingRole);
body_message.set_exchangeinstid(pTrade->ExchangeInstID);
body_message.set_offsetflag(pTrade->OffsetFlag);
body_message.set_hedgeflag(pTrade->HedgeFlag);
body_message.set_price(pTrade->Price);
body_message.set_volume(pTrade->Volume);
body_message.set_tradedate(pTrade->TradeDate);
body_message.set_tradetime(pTrade->TradeTime);
body_message.set_tradetype(pTrade->TradeType);
body_message.set_pricesource(pTrade->PriceSource);
body_message.set_traderid(pTrade->TraderID);
body_message.set_orderlocalid(pTrade->OrderLocalID);
body_message.set_clearingpartid(pTrade->ClearingPartID);
body_message.set_businessunit(pTrade->BusinessUnit);
body_message.set_sequenceno(pTrade->SequenceNo);
body_message.set_tradingday(pTrade->TradingDay);
body_message.set_settlementid(pTrade->SettlementID);
body_message.set_brokerorderseq(pTrade->BrokerOrderSeq);
body_message.set_tradesource(pTrade->TradeSource);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcTradeField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///报单录入错误回报
void CTraderSpi::OnErrRtnOrderInsert(CThostFtdcInputOrderField* pInputOrder, CThostFtdcRspInfoField* pRspInfo)
{
guosen::msg::ctp::CThostFtdcInputOrderField body_message;
body_message.set_brokerid(pInputOrder->BrokerID);
body_message.set_investorid(pInputOrder->InvestorID);
body_message.set_instrumentid(pInputOrder->InstrumentID);
body_message.set_orderref(pInputOrder->OrderRef);
body_message.set_userid(pInputOrder->UserID);
body_message.set_orderpricetype(pInputOrder->OrderPriceType);
body_message.set_direction(pInputOrder->Direction);
body_message.set_comboffsetflag(pInputOrder->CombOffsetFlag);
body_message.set_combhedgeflag(pInputOrder->CombHedgeFlag);
body_message.set_limitprice(pInputOrder->LimitPrice);
body_message.set_volumetotaloriginal(pInputOrder->VolumeTotalOriginal);
body_message.set_timecondition(pInputOrder->TimeCondition);
body_message.set_gtddate(pInputOrder->GTDDate);
body_message.set_volumecondition(pInputOrder->VolumeCondition);
body_message.set_minvolume(pInputOrder->MinVolume);
body_message.set_contingentcondition(pInputOrder->ContingentCondition);
body_message.set_stopprice(pInputOrder->StopPrice);
body_message.set_forceclosereason(pInputOrder->ForceCloseReason);
body_message.set_isautosuspend(pInputOrder->IsAutoSuspend);
body_message.set_businessunit(pInputOrder->BusinessUnit);
body_message.set_requestid(pInputOrder->RequestID);
body_message.set_userforceclose(pInputOrder->UserForceClose);
body_message.set_isswaporder(pInputOrder->IsSwapOrder);
body_message.set_exchangeid(pInputOrder->ExchangeID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInputOrderField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///报单操作错误回报
void CTraderSpi::OnErrRtnOrderAction(CThostFtdcOrderActionField* pOrderAction, CThostFtdcRspInfoField* pRspInfo)
{
guosen::msg::ctp::CThostFtdcOrderActionField body_message;
body_message.set_brokerid(pOrderAction->BrokerID);
body_message.set_investorid(pOrderAction->InvestorID);
body_message.set_orderactionref(pOrderAction->OrderActionRef);
body_message.set_orderref(pOrderAction->OrderRef);
body_message.set_requestid(pOrderAction->RequestID);
body_message.set_frontid(pOrderAction->FrontID);
body_message.set_sessionid(pOrderAction->SessionID);
body_message.set_exchangeid(pOrderAction->ExchangeID);
body_message.set_ordersysid(pOrderAction->OrderSysID);
body_message.set_actionflag(pOrderAction->ActionFlag);
body_message.set_limitprice(pOrderAction->LimitPrice);
body_message.set_volumechange(pOrderAction->VolumeChange);
body_message.set_actiondate(pOrderAction->ActionDate);
body_message.set_actiontime(pOrderAction->ActionTime);
body_message.set_traderid(pOrderAction->TraderID);
body_message.set_installid(pOrderAction->InstallID);
body_message.set_orderlocalid(pOrderAction->OrderLocalID);
body_message.set_actionlocalid(pOrderAction->ActionLocalID);
body_message.set_participantid(pOrderAction->ParticipantID);
body_message.set_clientid(pOrderAction->ClientID);
body_message.set_businessunit(pOrderAction->BusinessUnit);
body_message.set_orderactionstatus(pOrderAction->OrderActionStatus);
body_message.set_userid(pOrderAction->UserID);
body_message.set_statusmsg(pOrderAction->StatusMsg);
body_message.set_instrumentid(pOrderAction->InstrumentID);
body_message.set_branchid(pOrderAction->BranchID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcOrderActionField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///合约交易状态通知
void CTraderSpi::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField* pInstrumentStatus)
{
guosen::msg::ctp::CThostFtdcInstrumentStatusField body_message;
body_message.set_exchangeid(pInstrumentStatus->ExchangeID);
body_message.set_exchangeinstid(pInstrumentStatus->ExchangeInstID);
body_message.set_settlementgroupid(pInstrumentStatus->SettlementGroupID);
body_message.set_instrumentid(pInstrumentStatus->InstrumentID);
body_message.set_instrumentstatus(pInstrumentStatus->InstrumentStatus);
body_message.set_tradingsegmentsn(pInstrumentStatus->TradingSegmentSN);
body_message.set_entertime(pInstrumentStatus->EnterTime);
body_message.set_enterreason(pInstrumentStatus->EnterReason);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInstrumentStatusField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///交易通知
void CTraderSpi::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField* pTradingNoticeInfo)
{
guosen::msg::ctp::CThostFtdcTradingNoticeInfoField body_message;
body_message.set_brokerid(pTradingNoticeInfo->BrokerID);
body_message.set_investorid(pTradingNoticeInfo->InvestorID);
body_message.set_sendtime(pTradingNoticeInfo->SendTime);
body_message.set_fieldcontent(pTradingNoticeInfo->FieldContent);
body_message.set_sequenceseries(pTradingNoticeInfo->SequenceSeries);
body_message.set_sequenceno(pTradingNoticeInfo->SequenceNo);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcTradingNoticeInfoField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///提示条件单校验错误
void CTraderSpi::OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField* pErrorConditionalOrder)
{
guosen::msg::ctp::CThostFtdcErrorConditionalOrderField body_message;
body_message.set_brokerid(pErrorConditionalOrder->BrokerID);
body_message.set_investorid(pErrorConditionalOrder->InvestorID);
body_message.set_instrumentid(pErrorConditionalOrder->InstrumentID);
body_message.set_orderref(pErrorConditionalOrder->OrderRef);
body_message.set_userid(pErrorConditionalOrder->UserID);
body_message.set_orderpricetype(pErrorConditionalOrder->OrderPriceType);
body_message.set_direction(pErrorConditionalOrder->Direction);
body_message.set_comboffsetflag(pErrorConditionalOrder->CombOffsetFlag);
body_message.set_combhedgeflag(pErrorConditionalOrder->CombHedgeFlag);
body_message.set_limitprice(pErrorConditionalOrder->LimitPrice);
body_message.set_volumetotaloriginal(pErrorConditionalOrder->VolumeTotalOriginal);
body_message.set_timecondition(pErrorConditionalOrder->TimeCondition);
body_message.set_gtddate(pErrorConditionalOrder->GTDDate);
body_message.set_volumecondition(pErrorConditionalOrder->VolumeCondition);
body_message.set_minvolume(pErrorConditionalOrder->MinVolume);
body_message.set_contingentcondition(pErrorConditionalOrder->ContingentCondition);
body_message.set_stopprice(pErrorConditionalOrder->StopPrice);
body_message.set_forceclosereason(pErrorConditionalOrder->ForceCloseReason);
body_message.set_isautosuspend(pErrorConditionalOrder->IsAutoSuspend);
body_message.set_businessunit(pErrorConditionalOrder->BusinessUnit);
body_message.set_requestid(pErrorConditionalOrder->RequestID);
body_message.set_orderlocalid(pErrorConditionalOrder->OrderLocalID);
body_message.set_exchangeid(pErrorConditionalOrder->ExchangeID);
body_message.set_participantid(pErrorConditionalOrder->ParticipantID);
body_message.set_clientid(pErrorConditionalOrder->ClientID);
body_message.set_exchangeinstid(pErrorConditionalOrder->ExchangeInstID);
body_message.set_traderid(pErrorConditionalOrder->TraderID);
body_message.set_installid(pErrorConditionalOrder->InstallID);
body_message.set_ordersubmitstatus(pErrorConditionalOrder->OrderSubmitStatus);
body_message.set_notifysequence(pErrorConditionalOrder->NotifySequence);
body_message.set_tradingday(pErrorConditionalOrder->TradingDay);
body_message.set_settlementid(pErrorConditionalOrder->SettlementID);
body_message.set_ordersysid(pErrorConditionalOrder->OrderSysID);
body_message.set_ordersource(pErrorConditionalOrder->OrderSource);
body_message.set_orderstatus(pErrorConditionalOrder->OrderStatus);
body_message.set_ordertype(pErrorConditionalOrder->OrderType);
body_message.set_volumetraded(pErrorConditionalOrder->VolumeTraded);
body_message.set_volumetotal(pErrorConditionalOrder->VolumeTotal);
body_message.set_insertdate(pErrorConditionalOrder->InsertDate);
body_message.set_inserttime(pErrorConditionalOrder->InsertTime);
body_message.set_activetime(pErrorConditionalOrder->ActiveTime);
body_message.set_suspendtime(pErrorConditionalOrder->SuspendTime);
body_message.set_updatetime(pErrorConditionalOrder->UpdateTime);
body_message.set_canceltime(pErrorConditionalOrder->CancelTime);
body_message.set_activetraderid(pErrorConditionalOrder->ActiveTraderID);
body_message.set_clearingpartid(pErrorConditionalOrder->ClearingPartID);
body_message.set_sequenceno(pErrorConditionalOrder->SequenceNo);
body_message.set_frontid(pErrorConditionalOrder->FrontID);
body_message.set_sessionid(pErrorConditionalOrder->SessionID);
body_message.set_userproductinfo(pErrorConditionalOrder->UserProductInfo);
body_message.set_statusmsg(pErrorConditionalOrder->StatusMsg);
body_message.set_userforceclose(pErrorConditionalOrder->UserForceClose);
body_message.set_activeuserid(pErrorConditionalOrder->ActiveUserID);
body_message.set_brokerorderseq(pErrorConditionalOrder->BrokerOrderSeq);
body_message.set_relativeordersysid(pErrorConditionalOrder->RelativeOrderSysID);
body_message.set_zcetotaltradedvolume(pErrorConditionalOrder->ZCETotalTradedVolume);
body_message.set_errorid(pErrorConditionalOrder->ErrorID);
body_message.set_errormsg(pErrorConditionalOrder->ErrorMsg);
body_message.set_isswaporder(pErrorConditionalOrder->IsSwapOrder);
body_message.set_branchid(pErrorConditionalOrder->BranchID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcErrorConditionalOrderField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///执行宣告通知
void CTraderSpi::OnRtnExecOrder(CThostFtdcExecOrderField* pExecOrder)
{
guosen::msg::ctp::CThostFtdcExecOrderField body_message;
body_message.set_brokerid(pExecOrder->BrokerID);
body_message.set_investorid(pExecOrder->InvestorID);
body_message.set_instrumentid(pExecOrder->InstrumentID);
body_message.set_execorderref(pExecOrder->ExecOrderRef);
body_message.set_userid(pExecOrder->UserID);
body_message.set_volume(pExecOrder->Volume);
body_message.set_requestid(pExecOrder->RequestID);
body_message.set_businessunit(pExecOrder->BusinessUnit);
body_message.set_offsetflag(pExecOrder->OffsetFlag);
body_message.set_hedgeflag(pExecOrder->HedgeFlag);
body_message.set_actiontype(pExecOrder->ActionType);
body_message.set_posidirection(pExecOrder->PosiDirection);
body_message.set_reservepositionflag(pExecOrder->ReservePositionFlag);
body_message.set_closeflag(pExecOrder->CloseFlag);
body_message.set_execorderlocalid(pExecOrder->ExecOrderLocalID);
body_message.set_exchangeid(pExecOrder->ExchangeID);
body_message.set_participantid(pExecOrder->ParticipantID);
body_message.set_clientid(pExecOrder->ClientID);
body_message.set_exchangeinstid(pExecOrder->ExchangeInstID);
body_message.set_traderid(pExecOrder->TraderID);
body_message.set_installid(pExecOrder->InstallID);
body_message.set_ordersubmitstatus(pExecOrder->OrderSubmitStatus);
body_message.set_notifysequence(pExecOrder->NotifySequence);
body_message.set_tradingday(pExecOrder->TradingDay);
body_message.set_settlementid(pExecOrder->SettlementID);
body_message.set_execordersysid(pExecOrder->ExecOrderSysID);
body_message.set_insertdate(pExecOrder->InsertDate);
body_message.set_inserttime(pExecOrder->InsertTime);
body_message.set_canceltime(pExecOrder->CancelTime);
body_message.set_execresult(pExecOrder->ExecResult);
body_message.set_clearingpartid(pExecOrder->ClearingPartID);
body_message.set_sequenceno(pExecOrder->SequenceNo);
body_message.set_frontid(pExecOrder->FrontID);
body_message.set_sessionid(pExecOrder->SessionID);
body_message.set_userproductinfo(pExecOrder->UserProductInfo);
body_message.set_statusmsg(pExecOrder->StatusMsg);
body_message.set_activeuserid(pExecOrder->ActiveUserID);
body_message.set_brokerexecorderseq(pExecOrder->BrokerExecOrderSeq);
body_message.set_branchid(pExecOrder->BranchID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcExecOrderField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///执行宣告录入错误回报
void CTraderSpi::OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField* pInputExecOrder, CThostFtdcRspInfoField* pRspInfo)
{
guosen::msg::ctp::CThostFtdcInputExecOrderField body_message;
body_message.set_brokerid(pInputExecOrder->BrokerID);
body_message.set_investorid(pInputExecOrder->InvestorID);
body_message.set_instrumentid(pInputExecOrder->InstrumentID);
body_message.set_execorderref(pInputExecOrder->ExecOrderRef);
body_message.set_userid(pInputExecOrder->UserID);
body_message.set_volume(pInputExecOrder->Volume);
body_message.set_requestid(pInputExecOrder->RequestID);
body_message.set_businessunit(pInputExecOrder->BusinessUnit);
body_message.set_offsetflag(pInputExecOrder->OffsetFlag);
body_message.set_hedgeflag(pInputExecOrder->HedgeFlag);
body_message.set_actiontype(pInputExecOrder->ActionType);
body_message.set_posidirection(pInputExecOrder->PosiDirection);
body_message.set_reservepositionflag(pInputExecOrder->ReservePositionFlag);
body_message.set_closeflag(pInputExecOrder->CloseFlag);
body_message.set_exchangeid(pInputExecOrder->ExchangeID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInputExecOrderField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///执行宣告操作错误回报
void CTraderSpi::OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField* pExecOrderAction, CThostFtdcRspInfoField* pRspInfo)
{
guosen::msg::ctp::CThostFtdcExecOrderActionField body_message;
body_message.set_brokerid(pExecOrderAction->BrokerID);
body_message.set_investorid(pExecOrderAction->InvestorID);
body_message.set_execorderactionref(pExecOrderAction->ExecOrderActionRef);
body_message.set_execorderref(pExecOrderAction->ExecOrderRef);
body_message.set_requestid(pExecOrderAction->RequestID);
body_message.set_frontid(pExecOrderAction->FrontID);
body_message.set_sessionid(pExecOrderAction->SessionID);
body_message.set_exchangeid(pExecOrderAction->ExchangeID);
body_message.set_execordersysid(pExecOrderAction->ExecOrderSysID);
body_message.set_actionflag(pExecOrderAction->ActionFlag);
body_message.set_actiondate(pExecOrderAction->ActionDate);
body_message.set_actiontime(pExecOrderAction->ActionTime);
body_message.set_traderid(pExecOrderAction->TraderID);
body_message.set_installid(pExecOrderAction->InstallID);
body_message.set_execorderlocalid(pExecOrderAction->ExecOrderLocalID);
body_message.set_actionlocalid(pExecOrderAction->ActionLocalID);
body_message.set_participantid(pExecOrderAction->ParticipantID);
body_message.set_clientid(pExecOrderAction->ClientID);
body_message.set_businessunit(pExecOrderAction->BusinessUnit);
body_message.set_orderactionstatus(pExecOrderAction->OrderActionStatus);
body_message.set_userid(pExecOrderAction->UserID);
body_message.set_actiontype(pExecOrderAction->ActionType);
body_message.set_statusmsg(pExecOrderAction->StatusMsg);
body_message.set_instrumentid(pExecOrderAction->InstrumentID);
body_message.set_branchid(pExecOrderAction->BranchID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcExecOrderActionField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///询价录入错误回报
void CTraderSpi::OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField* pInputForQuote, CThostFtdcRspInfoField* pRspInfo)
{
guosen::msg::ctp::CThostFtdcInputForQuoteField body_message;
body_message.set_brokerid(pInputForQuote->BrokerID);
body_message.set_investorid(pInputForQuote->InvestorID);
body_message.set_instrumentid(pInputForQuote->InstrumentID);
body_message.set_forquoteref(pInputForQuote->ForQuoteRef);
body_message.set_userid(pInputForQuote->UserID);
body_message.set_exchangeid(pInputForQuote->ExchangeID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInputForQuoteField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///报价通知
void CTraderSpi::OnRtnQuote(CThostFtdcQuoteField* pQuote)
{
guosen::msg::ctp::CThostFtdcQuoteField body_message;
body_message.set_brokerid(pQuote->BrokerID);
body_message.set_investorid(pQuote->InvestorID);
body_message.set_instrumentid(pQuote->InstrumentID);
body_message.set_quoteref(pQuote->QuoteRef);
body_message.set_userid(pQuote->UserID);
body_message.set_askprice(pQuote->AskPrice);
body_message.set_bidprice(pQuote->BidPrice);
body_message.set_askvolume(pQuote->AskVolume);
body_message.set_bidvolume(pQuote->BidVolume);
body_message.set_requestid(pQuote->RequestID);
body_message.set_businessunit(pQuote->BusinessUnit);
body_message.set_askoffsetflag(pQuote->AskOffsetFlag);
body_message.set_bidoffsetflag(pQuote->BidOffsetFlag);
body_message.set_askhedgeflag(pQuote->AskHedgeFlag);
body_message.set_bidhedgeflag(pQuote->BidHedgeFlag);
body_message.set_quotelocalid(pQuote->QuoteLocalID);
body_message.set_exchangeid(pQuote->ExchangeID);
body_message.set_participantid(pQuote->ParticipantID);
body_message.set_clientid(pQuote->ClientID);
body_message.set_exchangeinstid(pQuote->ExchangeInstID);
body_message.set_traderid(pQuote->TraderID);
body_message.set_installid(pQuote->InstallID);
body_message.set_notifysequence(pQuote->NotifySequence);
body_message.set_ordersubmitstatus(pQuote->OrderSubmitStatus);
body_message.set_tradingday(pQuote->TradingDay);
body_message.set_settlementid(pQuote->SettlementID);
body_message.set_quotesysid(pQuote->QuoteSysID);
body_message.set_insertdate(pQuote->InsertDate);
body_message.set_inserttime(pQuote->InsertTime);
body_message.set_canceltime(pQuote->CancelTime);
body_message.set_quotestatus(pQuote->QuoteStatus);
body_message.set_clearingpartid(pQuote->ClearingPartID);
body_message.set_sequenceno(pQuote->SequenceNo);
body_message.set_askordersysid(pQuote->AskOrderSysID);
body_message.set_bidordersysid(pQuote->BidOrderSysID);
body_message.set_frontid(pQuote->FrontID);
body_message.set_sessionid(pQuote->SessionID);
body_message.set_userproductinfo(pQuote->UserProductInfo);
body_message.set_statusmsg(pQuote->StatusMsg);
body_message.set_activeuserid(pQuote->ActiveUserID);
body_message.set_brokerquoteseq(pQuote->BrokerQuoteSeq);
body_message.set_askorderref(pQuote->AskOrderRef);
body_message.set_bidorderref(pQuote->BidOrderRef);
body_message.set_forquotesysid(pQuote->ForQuoteSysID);
body_message.set_branchid(pQuote->BranchID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcQuoteField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///报价录入错误回报
void CTraderSpi::OnErrRtnQuoteInsert(CThostFtdcInputQuoteField* pInputQuote, CThostFtdcRspInfoField* pRspInfo)
{
guosen::msg::ctp::CThostFtdcInputQuoteField body_message;
body_message.set_brokerid(pInputQuote->BrokerID);
body_message.set_investorid(pInputQuote->InvestorID);
body_message.set_instrumentid(pInputQuote->InstrumentID);
body_message.set_quoteref(pInputQuote->QuoteRef);
body_message.set_userid(pInputQuote->UserID);
body_message.set_askprice(pInputQuote->AskPrice);
body_message.set_bidprice(pInputQuote->BidPrice);
body_message.set_askvolume(pInputQuote->AskVolume);
body_message.set_bidvolume(pInputQuote->BidVolume);
body_message.set_requestid(pInputQuote->RequestID);
body_message.set_businessunit(pInputQuote->BusinessUnit);
body_message.set_askoffsetflag(pInputQuote->AskOffsetFlag);
body_message.set_bidoffsetflag(pInputQuote->BidOffsetFlag);
body_message.set_askhedgeflag(pInputQuote->AskHedgeFlag);
body_message.set_bidhedgeflag(pInputQuote->BidHedgeFlag);
body_message.set_askorderref(pInputQuote->AskOrderRef);
body_message.set_bidorderref(pInputQuote->BidOrderRef);
body_message.set_forquotesysid(pInputQuote->ForQuoteSysID);
body_message.set_exchangeid(pInputQuote->ExchangeID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInputQuoteField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///报价操作错误回报
void CTraderSpi::OnErrRtnQuoteAction(CThostFtdcQuoteActionField* pQuoteAction, CThostFtdcRspInfoField* pRspInfo)
{
guosen::msg::ctp::CThostFtdcQuoteActionField body_message;
body_message.set_brokerid(pQuoteAction->BrokerID);
body_message.set_investorid(pQuoteAction->InvestorID);
body_message.set_quoteactionref(pQuoteAction->QuoteActionRef);
body_message.set_quoteref(pQuoteAction->QuoteRef);
body_message.set_requestid(pQuoteAction->RequestID);
body_message.set_frontid(pQuoteAction->FrontID);
body_message.set_sessionid(pQuoteAction->SessionID);
body_message.set_exchangeid(pQuoteAction->ExchangeID);
body_message.set_quotesysid(pQuoteAction->QuoteSysID);
body_message.set_actionflag(pQuoteAction->ActionFlag);
body_message.set_actiondate(pQuoteAction->ActionDate);
body_message.set_actiontime(pQuoteAction->ActionTime);
body_message.set_traderid(pQuoteAction->TraderID);
body_message.set_installid(pQuoteAction->InstallID);
body_message.set_quotelocalid(pQuoteAction->QuoteLocalID);
body_message.set_actionlocalid(pQuoteAction->ActionLocalID);
body_message.set_participantid(pQuoteAction->ParticipantID);
body_message.set_clientid(pQuoteAction->ClientID);
body_message.set_businessunit(pQuoteAction->BusinessUnit);
body_message.set_orderactionstatus(pQuoteAction->OrderActionStatus);
body_message.set_userid(pQuoteAction->UserID);
body_message.set_statusmsg(pQuoteAction->StatusMsg);
body_message.set_instrumentid(pQuoteAction->InstrumentID);
body_message.set_branchid(pQuoteAction->BranchID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcQuoteActionField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///询价通知
void CTraderSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp)
{
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

///保证金监控中心用户令牌
void CTraderSpi::OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField* pCFMMCTradingAccountToken)
{
guosen::msg::ctp::CThostFtdcCFMMCTradingAccountTokenField body_message;
body_message.set_brokerid(pCFMMCTradingAccountToken->BrokerID);
body_message.set_participantid(pCFMMCTradingAccountToken->ParticipantID);
body_message.set_accountid(pCFMMCTradingAccountToken->AccountID);
body_message.set_keyid(pCFMMCTradingAccountToken->KeyID);
body_message.set_token(pCFMMCTradingAccountToken->Token);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcCFMMCTradingAccountTokenField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///锁定通知
void CTraderSpi::OnRtnLock(CThostFtdcLockField* pLock)
{
guosen::msg::ctp::CThostFtdcLockField body_message;
body_message.set_brokerid(pLock->BrokerID);
body_message.set_investorid(pLock->InvestorID);
body_message.set_instrumentid(pLock->InstrumentID);
body_message.set_lockref(pLock->LockRef);
body_message.set_userid(pLock->UserID);
body_message.set_volume(pLock->Volume);
body_message.set_requestid(pLock->RequestID);
body_message.set_businessunit(pLock->BusinessUnit);
body_message.set_locktype(pLock->LockType);
body_message.set_locklocalid(pLock->LockLocalID);
body_message.set_exchangeid(pLock->ExchangeID);
body_message.set_participantid(pLock->ParticipantID);
body_message.set_clientid(pLock->ClientID);
body_message.set_exchangeinstid(pLock->ExchangeInstID);
body_message.set_traderid(pLock->TraderID);
body_message.set_installid(pLock->InstallID);
body_message.set_ordersubmitstatus(pLock->OrderSubmitStatus);
body_message.set_notifysequence(pLock->NotifySequence);
body_message.set_tradingday(pLock->TradingDay);
body_message.set_settlementid(pLock->SettlementID);
body_message.set_locksysid(pLock->LockSysID);
body_message.set_insertdate(pLock->InsertDate);
body_message.set_inserttime(pLock->InsertTime);
body_message.set_canceltime(pLock->CancelTime);
body_message.set_lockstatus(pLock->LockStatus);
body_message.set_clearingpartid(pLock->ClearingPartID);
body_message.set_sequenceno(pLock->SequenceNo);
body_message.set_frontid(pLock->FrontID);
body_message.set_sessionid(pLock->SessionID);
body_message.set_userproductinfo(pLock->UserProductInfo);
body_message.set_statusmsg(pLock->StatusMsg);
body_message.set_activeuserid(pLock->ActiveUserID);
body_message.set_brokerlockseq(pLock->BrokerLockSeq);
body_message.set_branchid(pLock->BranchID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcLockField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///锁定错误通知
void CTraderSpi::OnErrRtnLockInsert(CThostFtdcInputLockField* pInputLock, CThostFtdcRspInfoField* pRspInfo)
{
guosen::msg::ctp::CThostFtdcInputLockField body_message;
body_message.set_brokerid(pInputLock->BrokerID);
body_message.set_investorid(pInputLock->InvestorID);
body_message.set_instrumentid(pInputLock->InstrumentID);
body_message.set_lockref(pInputLock->LockRef);
body_message.set_userid(pInputLock->UserID);
body_message.set_volume(pInputLock->Volume);
body_message.set_requestid(pInputLock->RequestID);
body_message.set_businessunit(pInputLock->BusinessUnit);
body_message.set_locktype(pInputLock->LockType);
body_message.set_exchangeid(pInputLock->ExchangeID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInputLockField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///申请组合通知
void CTraderSpi::OnRtnCombAction(CThostFtdcCombActionField* pCombAction)
{
guosen::msg::ctp::CThostFtdcCombActionField body_message;
body_message.set_brokerid(pCombAction->BrokerID);
body_message.set_investorid(pCombAction->InvestorID);
body_message.set_instrumentid(pCombAction->InstrumentID);
body_message.set_combactionref(pCombAction->CombActionRef);
body_message.set_userid(pCombAction->UserID);
body_message.set_direction(pCombAction->Direction);
body_message.set_volume(pCombAction->Volume);
body_message.set_combdirection(pCombAction->CombDirection);
body_message.set_hedgeflag(pCombAction->HedgeFlag);
body_message.set_actionlocalid(pCombAction->ActionLocalID);
body_message.set_exchangeid(pCombAction->ExchangeID);
body_message.set_participantid(pCombAction->ParticipantID);
body_message.set_clientid(pCombAction->ClientID);
body_message.set_exchangeinstid(pCombAction->ExchangeInstID);
body_message.set_traderid(pCombAction->TraderID);
body_message.set_installid(pCombAction->InstallID);
body_message.set_actionstatus(pCombAction->ActionStatus);
body_message.set_notifysequence(pCombAction->NotifySequence);
body_message.set_tradingday(pCombAction->TradingDay);
body_message.set_settlementid(pCombAction->SettlementID);
body_message.set_sequenceno(pCombAction->SequenceNo);
body_message.set_frontid(pCombAction->FrontID);
body_message.set_sessionid(pCombAction->SessionID);
body_message.set_userproductinfo(pCombAction->UserProductInfo);
body_message.set_statusmsg(pCombAction->StatusMsg);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcCombActionField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///申请组合录入错误回报
void CTraderSpi::OnErrRtnCombActionInsert(CThostFtdcInputCombActionField* pInputCombAction, CThostFtdcRspInfoField* pRspInfo)
{
guosen::msg::ctp::CThostFtdcInputCombActionField body_message;
body_message.set_brokerid(pInputCombAction->BrokerID);
body_message.set_investorid(pInputCombAction->InvestorID);
body_message.set_instrumentid(pInputCombAction->InstrumentID);
body_message.set_combactionref(pInputCombAction->CombActionRef);
body_message.set_userid(pInputCombAction->UserID);
body_message.set_direction(pInputCombAction->Direction);
body_message.set_volume(pInputCombAction->Volume);
body_message.set_combdirection(pInputCombAction->CombDirection);
body_message.set_hedgeflag(pInputCombAction->HedgeFlag);
body_message.set_exchangeid(pInputCombAction->ExchangeID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcInputCombActionField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询签约银行响应
void CTraderSpi::OnRspQryContractBank(CThostFtdcContractBankField* pContractBank, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcContractBankField body_message;
body_message.set_brokerid(pContractBank->BrokerID);
body_message.set_bankid(pContractBank->BankID);
body_message.set_bankbrchid(pContractBank->BankBrchID);
body_message.set_bankname(pContractBank->BankName);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcContractBankField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询预埋单响应
void CTraderSpi::OnRspQryParkedOrder(CThostFtdcParkedOrderField* pParkedOrder, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcParkedOrderField body_message;
body_message.set_brokerid(pParkedOrder->BrokerID);
body_message.set_investorid(pParkedOrder->InvestorID);
body_message.set_instrumentid(pParkedOrder->InstrumentID);
body_message.set_orderref(pParkedOrder->OrderRef);
body_message.set_userid(pParkedOrder->UserID);
body_message.set_orderpricetype(pParkedOrder->OrderPriceType);
body_message.set_direction(pParkedOrder->Direction);
body_message.set_comboffsetflag(pParkedOrder->CombOffsetFlag);
body_message.set_combhedgeflag(pParkedOrder->CombHedgeFlag);
body_message.set_limitprice(pParkedOrder->LimitPrice);
body_message.set_volumetotaloriginal(pParkedOrder->VolumeTotalOriginal);
body_message.set_timecondition(pParkedOrder->TimeCondition);
body_message.set_gtddate(pParkedOrder->GTDDate);
body_message.set_volumecondition(pParkedOrder->VolumeCondition);
body_message.set_minvolume(pParkedOrder->MinVolume);
body_message.set_contingentcondition(pParkedOrder->ContingentCondition);
body_message.set_stopprice(pParkedOrder->StopPrice);
body_message.set_forceclosereason(pParkedOrder->ForceCloseReason);
body_message.set_isautosuspend(pParkedOrder->IsAutoSuspend);
body_message.set_businessunit(pParkedOrder->BusinessUnit);
body_message.set_requestid(pParkedOrder->RequestID);
body_message.set_userforceclose(pParkedOrder->UserForceClose);
body_message.set_exchangeid(pParkedOrder->ExchangeID);
body_message.set_parkedorderid(pParkedOrder->ParkedOrderID);
body_message.set_usertype(pParkedOrder->UserType);
body_message.set_status(pParkedOrder->Status);
body_message.set_errorid(pParkedOrder->ErrorID);
body_message.set_errormsg(pParkedOrder->ErrorMsg);
body_message.set_isswaporder(pParkedOrder->IsSwapOrder);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcParkedOrderField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询预埋撤单响应
void CTraderSpi::OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField* pParkedOrderAction, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcParkedOrderActionField body_message;
body_message.set_brokerid(pParkedOrderAction->BrokerID);
body_message.set_investorid(pParkedOrderAction->InvestorID);
body_message.set_orderactionref(pParkedOrderAction->OrderActionRef);
body_message.set_orderref(pParkedOrderAction->OrderRef);
body_message.set_requestid(pParkedOrderAction->RequestID);
body_message.set_frontid(pParkedOrderAction->FrontID);
body_message.set_sessionid(pParkedOrderAction->SessionID);
body_message.set_exchangeid(pParkedOrderAction->ExchangeID);
body_message.set_ordersysid(pParkedOrderAction->OrderSysID);
body_message.set_actionflag(pParkedOrderAction->ActionFlag);
body_message.set_limitprice(pParkedOrderAction->LimitPrice);
body_message.set_volumechange(pParkedOrderAction->VolumeChange);
body_message.set_userid(pParkedOrderAction->UserID);
body_message.set_instrumentid(pParkedOrderAction->InstrumentID);
body_message.set_parkedorderactionid(pParkedOrderAction->ParkedOrderActionID);
body_message.set_usertype(pParkedOrderAction->UserType);
body_message.set_status(pParkedOrderAction->Status);
body_message.set_errorid(pParkedOrderAction->ErrorID);
body_message.set_errormsg(pParkedOrderAction->ErrorMsg);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcParkedOrderActionField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询交易通知响应
void CTraderSpi::OnRspQryTradingNotice(CThostFtdcTradingNoticeField* pTradingNotice, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcTradingNoticeField body_message;
body_message.set_brokerid(pTradingNotice->BrokerID);
body_message.set_investorrange(pTradingNotice->InvestorRange);
body_message.set_investorid(pTradingNotice->InvestorID);
body_message.set_sequenceseries(pTradingNotice->SequenceSeries);
body_message.set_userid(pTradingNotice->UserID);
body_message.set_sendtime(pTradingNotice->SendTime);
body_message.set_sequenceno(pTradingNotice->SequenceNo);
body_message.set_fieldcontent(pTradingNotice->FieldContent);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcTradingNoticeField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询经纪公司交易参数响应
void CTraderSpi::OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField* pBrokerTradingParams, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcBrokerTradingParamsField body_message;
body_message.set_brokerid(pBrokerTradingParams->BrokerID);
body_message.set_investorid(pBrokerTradingParams->InvestorID);
body_message.set_marginpricetype(pBrokerTradingParams->MarginPriceType);
body_message.set_algorithm(pBrokerTradingParams->Algorithm);
body_message.set_availincludecloseprofit(pBrokerTradingParams->AvailIncludeCloseProfit);
body_message.set_currencyid(pBrokerTradingParams->CurrencyID);
body_message.set_optionroyaltypricetype(pBrokerTradingParams->OptionRoyaltyPriceType);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcBrokerTradingParamsField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询经纪公司交易算法响应
void CTraderSpi::OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField* pBrokerTradingAlgos, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcBrokerTradingAlgosField body_message;
body_message.set_brokerid(pBrokerTradingAlgos->BrokerID);
body_message.set_exchangeid(pBrokerTradingAlgos->ExchangeID);
body_message.set_instrumentid(pBrokerTradingAlgos->InstrumentID);
body_message.set_handlepositionalgoid(pBrokerTradingAlgos->HandlePositionAlgoID);
body_message.set_findmarginratealgoid(pBrokerTradingAlgos->FindMarginRateAlgoID);
body_message.set_handletradingaccountalgoid(pBrokerTradingAlgos->HandleTradingAccountAlgoID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcBrokerTradingAlgosField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///请求查询监控中心用户令牌
void CTraderSpi::OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField* pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcQueryCFMMCTradingAccountTokenField body_message;
body_message.set_brokerid(pQueryCFMMCTradingAccountToken->BrokerID);
body_message.set_investorid(pQueryCFMMCTradingAccountToken->InvestorID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcQueryCFMMCTradingAccountTokenField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///银行发起银行资金转期货通知
void CTraderSpi::OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField* pRspTransfer)
{
guosen::msg::ctp::CThostFtdcRspTransferField body_message;
body_message.set_tradecode(pRspTransfer->TradeCode);
body_message.set_bankid(pRspTransfer->BankID);
body_message.set_bankbranchid(pRspTransfer->BankBranchID);
body_message.set_brokerid(pRspTransfer->BrokerID);
body_message.set_brokerbranchid(pRspTransfer->BrokerBranchID);
body_message.set_tradedate(pRspTransfer->TradeDate);
body_message.set_tradetime(pRspTransfer->TradeTime);
body_message.set_bankserial(pRspTransfer->BankSerial);
body_message.set_tradingday(pRspTransfer->TradingDay);
body_message.set_plateserial(pRspTransfer->PlateSerial);
body_message.set_lastfragment(pRspTransfer->LastFragment);
body_message.set_sessionid(pRspTransfer->SessionID);
body_message.set_customername(pRspTransfer->CustomerName);
body_message.set_idcardtype(pRspTransfer->IdCardType);
body_message.set_identifiedcardno(pRspTransfer->IdentifiedCardNo);
body_message.set_custtype(pRspTransfer->CustType);
body_message.set_bankaccount(pRspTransfer->BankAccount);
body_message.set_bankpassword(pRspTransfer->BankPassWord);
body_message.set_accountid(pRspTransfer->AccountID);
body_message.set_password(pRspTransfer->Password);
body_message.set_installid(pRspTransfer->InstallID);
body_message.set_futureserial(pRspTransfer->FutureSerial);
body_message.set_userid(pRspTransfer->UserID);
body_message.set_verifycertnoflag(pRspTransfer->VerifyCertNoFlag);
body_message.set_currencyid(pRspTransfer->CurrencyID);
body_message.set_tradeamount(pRspTransfer->TradeAmount);
body_message.set_futurefetchamount(pRspTransfer->FutureFetchAmount);
body_message.set_feepayflag(pRspTransfer->FeePayFlag);
body_message.set_custfee(pRspTransfer->CustFee);
body_message.set_brokerfee(pRspTransfer->BrokerFee);
body_message.set_message(pRspTransfer->Message);
body_message.set_digest(pRspTransfer->Digest);
body_message.set_bankacctype(pRspTransfer->BankAccType);
body_message.set_deviceid(pRspTransfer->DeviceID);
body_message.set_banksecuacctype(pRspTransfer->BankSecuAccType);
body_message.set_brokeridbybank(pRspTransfer->BrokerIDByBank);
body_message.set_banksecuacc(pRspTransfer->BankSecuAcc);
body_message.set_bankpwdflag(pRspTransfer->BankPwdFlag);
body_message.set_secupwdflag(pRspTransfer->SecuPwdFlag);
body_message.set_operno(pRspTransfer->OperNo);
body_message.set_requestid(pRspTransfer->RequestID);
body_message.set_tid(pRspTransfer->TID);
body_message.set_transferstatus(pRspTransfer->TransferStatus);
body_message.set_errorid(pRspTransfer->ErrorID);
body_message.set_errormsg(pRspTransfer->ErrorMsg);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcRspTransferField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///银行发起期货资金转银行通知
void CTraderSpi::OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField* pRspTransfer)
{
guosen::msg::ctp::CThostFtdcRspTransferField body_message;
body_message.set_tradecode(pRspTransfer->TradeCode);
body_message.set_bankid(pRspTransfer->BankID);
body_message.set_bankbranchid(pRspTransfer->BankBranchID);
body_message.set_brokerid(pRspTransfer->BrokerID);
body_message.set_brokerbranchid(pRspTransfer->BrokerBranchID);
body_message.set_tradedate(pRspTransfer->TradeDate);
body_message.set_tradetime(pRspTransfer->TradeTime);
body_message.set_bankserial(pRspTransfer->BankSerial);
body_message.set_tradingday(pRspTransfer->TradingDay);
body_message.set_plateserial(pRspTransfer->PlateSerial);
body_message.set_lastfragment(pRspTransfer->LastFragment);
body_message.set_sessionid(pRspTransfer->SessionID);
body_message.set_customername(pRspTransfer->CustomerName);
body_message.set_idcardtype(pRspTransfer->IdCardType);
body_message.set_identifiedcardno(pRspTransfer->IdentifiedCardNo);
body_message.set_custtype(pRspTransfer->CustType);
body_message.set_bankaccount(pRspTransfer->BankAccount);
body_message.set_bankpassword(pRspTransfer->BankPassWord);
body_message.set_accountid(pRspTransfer->AccountID);
body_message.set_password(pRspTransfer->Password);
body_message.set_installid(pRspTransfer->InstallID);
body_message.set_futureserial(pRspTransfer->FutureSerial);
body_message.set_userid(pRspTransfer->UserID);
body_message.set_verifycertnoflag(pRspTransfer->VerifyCertNoFlag);
body_message.set_currencyid(pRspTransfer->CurrencyID);
body_message.set_tradeamount(pRspTransfer->TradeAmount);
body_message.set_futurefetchamount(pRspTransfer->FutureFetchAmount);
body_message.set_feepayflag(pRspTransfer->FeePayFlag);
body_message.set_custfee(pRspTransfer->CustFee);
body_message.set_brokerfee(pRspTransfer->BrokerFee);
body_message.set_message(pRspTransfer->Message);
body_message.set_digest(pRspTransfer->Digest);
body_message.set_bankacctype(pRspTransfer->BankAccType);
body_message.set_deviceid(pRspTransfer->DeviceID);
body_message.set_banksecuacctype(pRspTransfer->BankSecuAccType);
body_message.set_brokeridbybank(pRspTransfer->BrokerIDByBank);
body_message.set_banksecuacc(pRspTransfer->BankSecuAcc);
body_message.set_bankpwdflag(pRspTransfer->BankPwdFlag);
body_message.set_secupwdflag(pRspTransfer->SecuPwdFlag);
body_message.set_operno(pRspTransfer->OperNo);
body_message.set_requestid(pRspTransfer->RequestID);
body_message.set_tid(pRspTransfer->TID);
body_message.set_transferstatus(pRspTransfer->TransferStatus);
body_message.set_errorid(pRspTransfer->ErrorID);
body_message.set_errormsg(pRspTransfer->ErrorMsg);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcRspTransferField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///银行发起冲正银行转期货通知
void CTraderSpi::OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField* pRspRepeal)
{
guosen::msg::ctp::CThostFtdcRspRepealField body_message;
body_message.set_repealtimeinterval(pRspRepeal->RepealTimeInterval);
body_message.set_repealedtimes(pRspRepeal->RepealedTimes);
body_message.set_bankrepealflag(pRspRepeal->BankRepealFlag);
body_message.set_brokerrepealflag(pRspRepeal->BrokerRepealFlag);
body_message.set_platerepealserial(pRspRepeal->PlateRepealSerial);
body_message.set_bankrepealserial(pRspRepeal->BankRepealSerial);
body_message.set_futurerepealserial(pRspRepeal->FutureRepealSerial);
body_message.set_tradecode(pRspRepeal->TradeCode);
body_message.set_bankid(pRspRepeal->BankID);
body_message.set_bankbranchid(pRspRepeal->BankBranchID);
body_message.set_brokerid(pRspRepeal->BrokerID);
body_message.set_brokerbranchid(pRspRepeal->BrokerBranchID);
body_message.set_tradedate(pRspRepeal->TradeDate);
body_message.set_tradetime(pRspRepeal->TradeTime);
body_message.set_bankserial(pRspRepeal->BankSerial);
body_message.set_tradingday(pRspRepeal->TradingDay);
body_message.set_plateserial(pRspRepeal->PlateSerial);
body_message.set_lastfragment(pRspRepeal->LastFragment);
body_message.set_sessionid(pRspRepeal->SessionID);
body_message.set_customername(pRspRepeal->CustomerName);
body_message.set_idcardtype(pRspRepeal->IdCardType);
body_message.set_identifiedcardno(pRspRepeal->IdentifiedCardNo);
body_message.set_custtype(pRspRepeal->CustType);
body_message.set_bankaccount(pRspRepeal->BankAccount);
body_message.set_bankpassword(pRspRepeal->BankPassWord);
body_message.set_accountid(pRspRepeal->AccountID);
body_message.set_password(pRspRepeal->Password);
body_message.set_installid(pRspRepeal->InstallID);
body_message.set_futureserial(pRspRepeal->FutureSerial);
body_message.set_userid(pRspRepeal->UserID);
body_message.set_verifycertnoflag(pRspRepeal->VerifyCertNoFlag);
body_message.set_currencyid(pRspRepeal->CurrencyID);
body_message.set_tradeamount(pRspRepeal->TradeAmount);
body_message.set_futurefetchamount(pRspRepeal->FutureFetchAmount);
body_message.set_feepayflag(pRspRepeal->FeePayFlag);
body_message.set_custfee(pRspRepeal->CustFee);
body_message.set_brokerfee(pRspRepeal->BrokerFee);
body_message.set_message(pRspRepeal->Message);
body_message.set_digest(pRspRepeal->Digest);
body_message.set_bankacctype(pRspRepeal->BankAccType);
body_message.set_deviceid(pRspRepeal->DeviceID);
body_message.set_banksecuacctype(pRspRepeal->BankSecuAccType);
body_message.set_brokeridbybank(pRspRepeal->BrokerIDByBank);
body_message.set_banksecuacc(pRspRepeal->BankSecuAcc);
body_message.set_bankpwdflag(pRspRepeal->BankPwdFlag);
body_message.set_secupwdflag(pRspRepeal->SecuPwdFlag);
body_message.set_operno(pRspRepeal->OperNo);
body_message.set_requestid(pRspRepeal->RequestID);
body_message.set_tid(pRspRepeal->TID);
body_message.set_transferstatus(pRspRepeal->TransferStatus);
body_message.set_errorid(pRspRepeal->ErrorID);
body_message.set_errormsg(pRspRepeal->ErrorMsg);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcRspRepealField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///银行发起冲正期货转银行通知
void CTraderSpi::OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField* pRspRepeal)
{
guosen::msg::ctp::CThostFtdcRspRepealField body_message;
body_message.set_repealtimeinterval(pRspRepeal->RepealTimeInterval);
body_message.set_repealedtimes(pRspRepeal->RepealedTimes);
body_message.set_bankrepealflag(pRspRepeal->BankRepealFlag);
body_message.set_brokerrepealflag(pRspRepeal->BrokerRepealFlag);
body_message.set_platerepealserial(pRspRepeal->PlateRepealSerial);
body_message.set_bankrepealserial(pRspRepeal->BankRepealSerial);
body_message.set_futurerepealserial(pRspRepeal->FutureRepealSerial);
body_message.set_tradecode(pRspRepeal->TradeCode);
body_message.set_bankid(pRspRepeal->BankID);
body_message.set_bankbranchid(pRspRepeal->BankBranchID);
body_message.set_brokerid(pRspRepeal->BrokerID);
body_message.set_brokerbranchid(pRspRepeal->BrokerBranchID);
body_message.set_tradedate(pRspRepeal->TradeDate);
body_message.set_tradetime(pRspRepeal->TradeTime);
body_message.set_bankserial(pRspRepeal->BankSerial);
body_message.set_tradingday(pRspRepeal->TradingDay);
body_message.set_plateserial(pRspRepeal->PlateSerial);
body_message.set_lastfragment(pRspRepeal->LastFragment);
body_message.set_sessionid(pRspRepeal->SessionID);
body_message.set_customername(pRspRepeal->CustomerName);
body_message.set_idcardtype(pRspRepeal->IdCardType);
body_message.set_identifiedcardno(pRspRepeal->IdentifiedCardNo);
body_message.set_custtype(pRspRepeal->CustType);
body_message.set_bankaccount(pRspRepeal->BankAccount);
body_message.set_bankpassword(pRspRepeal->BankPassWord);
body_message.set_accountid(pRspRepeal->AccountID);
body_message.set_password(pRspRepeal->Password);
body_message.set_installid(pRspRepeal->InstallID);
body_message.set_futureserial(pRspRepeal->FutureSerial);
body_message.set_userid(pRspRepeal->UserID);
body_message.set_verifycertnoflag(pRspRepeal->VerifyCertNoFlag);
body_message.set_currencyid(pRspRepeal->CurrencyID);
body_message.set_tradeamount(pRspRepeal->TradeAmount);
body_message.set_futurefetchamount(pRspRepeal->FutureFetchAmount);
body_message.set_feepayflag(pRspRepeal->FeePayFlag);
body_message.set_custfee(pRspRepeal->CustFee);
body_message.set_brokerfee(pRspRepeal->BrokerFee);
body_message.set_message(pRspRepeal->Message);
body_message.set_digest(pRspRepeal->Digest);
body_message.set_bankacctype(pRspRepeal->BankAccType);
body_message.set_deviceid(pRspRepeal->DeviceID);
body_message.set_banksecuacctype(pRspRepeal->BankSecuAccType);
body_message.set_brokeridbybank(pRspRepeal->BrokerIDByBank);
body_message.set_banksecuacc(pRspRepeal->BankSecuAcc);
body_message.set_bankpwdflag(pRspRepeal->BankPwdFlag);
body_message.set_secupwdflag(pRspRepeal->SecuPwdFlag);
body_message.set_operno(pRspRepeal->OperNo);
body_message.set_requestid(pRspRepeal->RequestID);
body_message.set_tid(pRspRepeal->TID);
body_message.set_transferstatus(pRspRepeal->TransferStatus);
body_message.set_errorid(pRspRepeal->ErrorID);
body_message.set_errormsg(pRspRepeal->ErrorMsg);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcRspRepealField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///期货发起银行资金转期货通知
void CTraderSpi::OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField* pRspTransfer)
{
guosen::msg::ctp::CThostFtdcRspTransferField body_message;
body_message.set_tradecode(pRspTransfer->TradeCode);
body_message.set_bankid(pRspTransfer->BankID);
body_message.set_bankbranchid(pRspTransfer->BankBranchID);
body_message.set_brokerid(pRspTransfer->BrokerID);
body_message.set_brokerbranchid(pRspTransfer->BrokerBranchID);
body_message.set_tradedate(pRspTransfer->TradeDate);
body_message.set_tradetime(pRspTransfer->TradeTime);
body_message.set_bankserial(pRspTransfer->BankSerial);
body_message.set_tradingday(pRspTransfer->TradingDay);
body_message.set_plateserial(pRspTransfer->PlateSerial);
body_message.set_lastfragment(pRspTransfer->LastFragment);
body_message.set_sessionid(pRspTransfer->SessionID);
body_message.set_customername(pRspTransfer->CustomerName);
body_message.set_idcardtype(pRspTransfer->IdCardType);
body_message.set_identifiedcardno(pRspTransfer->IdentifiedCardNo);
body_message.set_custtype(pRspTransfer->CustType);
body_message.set_bankaccount(pRspTransfer->BankAccount);
body_message.set_bankpassword(pRspTransfer->BankPassWord);
body_message.set_accountid(pRspTransfer->AccountID);
body_message.set_password(pRspTransfer->Password);
body_message.set_installid(pRspTransfer->InstallID);
body_message.set_futureserial(pRspTransfer->FutureSerial);
body_message.set_userid(pRspTransfer->UserID);
body_message.set_verifycertnoflag(pRspTransfer->VerifyCertNoFlag);
body_message.set_currencyid(pRspTransfer->CurrencyID);
body_message.set_tradeamount(pRspTransfer->TradeAmount);
body_message.set_futurefetchamount(pRspTransfer->FutureFetchAmount);
body_message.set_feepayflag(pRspTransfer->FeePayFlag);
body_message.set_custfee(pRspTransfer->CustFee);
body_message.set_brokerfee(pRspTransfer->BrokerFee);
body_message.set_message(pRspTransfer->Message);
body_message.set_digest(pRspTransfer->Digest);
body_message.set_bankacctype(pRspTransfer->BankAccType);
body_message.set_deviceid(pRspTransfer->DeviceID);
body_message.set_banksecuacctype(pRspTransfer->BankSecuAccType);
body_message.set_brokeridbybank(pRspTransfer->BrokerIDByBank);
body_message.set_banksecuacc(pRspTransfer->BankSecuAcc);
body_message.set_bankpwdflag(pRspTransfer->BankPwdFlag);
body_message.set_secupwdflag(pRspTransfer->SecuPwdFlag);
body_message.set_operno(pRspTransfer->OperNo);
body_message.set_requestid(pRspTransfer->RequestID);
body_message.set_tid(pRspTransfer->TID);
body_message.set_transferstatus(pRspTransfer->TransferStatus);
body_message.set_errorid(pRspTransfer->ErrorID);
body_message.set_errormsg(pRspTransfer->ErrorMsg);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcRspTransferField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///期货发起期货资金转银行通知
void CTraderSpi::OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField* pRspTransfer)
{
guosen::msg::ctp::CThostFtdcRspTransferField body_message;
body_message.set_tradecode(pRspTransfer->TradeCode);
body_message.set_bankid(pRspTransfer->BankID);
body_message.set_bankbranchid(pRspTransfer->BankBranchID);
body_message.set_brokerid(pRspTransfer->BrokerID);
body_message.set_brokerbranchid(pRspTransfer->BrokerBranchID);
body_message.set_tradedate(pRspTransfer->TradeDate);
body_message.set_tradetime(pRspTransfer->TradeTime);
body_message.set_bankserial(pRspTransfer->BankSerial);
body_message.set_tradingday(pRspTransfer->TradingDay);
body_message.set_plateserial(pRspTransfer->PlateSerial);
body_message.set_lastfragment(pRspTransfer->LastFragment);
body_message.set_sessionid(pRspTransfer->SessionID);
body_message.set_customername(pRspTransfer->CustomerName);
body_message.set_idcardtype(pRspTransfer->IdCardType);
body_message.set_identifiedcardno(pRspTransfer->IdentifiedCardNo);
body_message.set_custtype(pRspTransfer->CustType);
body_message.set_bankaccount(pRspTransfer->BankAccount);
body_message.set_bankpassword(pRspTransfer->BankPassWord);
body_message.set_accountid(pRspTransfer->AccountID);
body_message.set_password(pRspTransfer->Password);
body_message.set_installid(pRspTransfer->InstallID);
body_message.set_futureserial(pRspTransfer->FutureSerial);
body_message.set_userid(pRspTransfer->UserID);
body_message.set_verifycertnoflag(pRspTransfer->VerifyCertNoFlag);
body_message.set_currencyid(pRspTransfer->CurrencyID);
body_message.set_tradeamount(pRspTransfer->TradeAmount);
body_message.set_futurefetchamount(pRspTransfer->FutureFetchAmount);
body_message.set_feepayflag(pRspTransfer->FeePayFlag);
body_message.set_custfee(pRspTransfer->CustFee);
body_message.set_brokerfee(pRspTransfer->BrokerFee);
body_message.set_message(pRspTransfer->Message);
body_message.set_digest(pRspTransfer->Digest);
body_message.set_bankacctype(pRspTransfer->BankAccType);
body_message.set_deviceid(pRspTransfer->DeviceID);
body_message.set_banksecuacctype(pRspTransfer->BankSecuAccType);
body_message.set_brokeridbybank(pRspTransfer->BrokerIDByBank);
body_message.set_banksecuacc(pRspTransfer->BankSecuAcc);
body_message.set_bankpwdflag(pRspTransfer->BankPwdFlag);
body_message.set_secupwdflag(pRspTransfer->SecuPwdFlag);
body_message.set_operno(pRspTransfer->OperNo);
body_message.set_requestid(pRspTransfer->RequestID);
body_message.set_tid(pRspTransfer->TID);
body_message.set_transferstatus(pRspTransfer->TransferStatus);
body_message.set_errorid(pRspTransfer->ErrorID);
body_message.set_errormsg(pRspTransfer->ErrorMsg);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcRspTransferField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
void CTraderSpi::OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField* pRspRepeal)
{
guosen::msg::ctp::CThostFtdcRspRepealField body_message;
body_message.set_repealtimeinterval(pRspRepeal->RepealTimeInterval);
body_message.set_repealedtimes(pRspRepeal->RepealedTimes);
body_message.set_bankrepealflag(pRspRepeal->BankRepealFlag);
body_message.set_brokerrepealflag(pRspRepeal->BrokerRepealFlag);
body_message.set_platerepealserial(pRspRepeal->PlateRepealSerial);
body_message.set_bankrepealserial(pRspRepeal->BankRepealSerial);
body_message.set_futurerepealserial(pRspRepeal->FutureRepealSerial);
body_message.set_tradecode(pRspRepeal->TradeCode);
body_message.set_bankid(pRspRepeal->BankID);
body_message.set_bankbranchid(pRspRepeal->BankBranchID);
body_message.set_brokerid(pRspRepeal->BrokerID);
body_message.set_brokerbranchid(pRspRepeal->BrokerBranchID);
body_message.set_tradedate(pRspRepeal->TradeDate);
body_message.set_tradetime(pRspRepeal->TradeTime);
body_message.set_bankserial(pRspRepeal->BankSerial);
body_message.set_tradingday(pRspRepeal->TradingDay);
body_message.set_plateserial(pRspRepeal->PlateSerial);
body_message.set_lastfragment(pRspRepeal->LastFragment);
body_message.set_sessionid(pRspRepeal->SessionID);
body_message.set_customername(pRspRepeal->CustomerName);
body_message.set_idcardtype(pRspRepeal->IdCardType);
body_message.set_identifiedcardno(pRspRepeal->IdentifiedCardNo);
body_message.set_custtype(pRspRepeal->CustType);
body_message.set_bankaccount(pRspRepeal->BankAccount);
body_message.set_bankpassword(pRspRepeal->BankPassWord);
body_message.set_accountid(pRspRepeal->AccountID);
body_message.set_password(pRspRepeal->Password);
body_message.set_installid(pRspRepeal->InstallID);
body_message.set_futureserial(pRspRepeal->FutureSerial);
body_message.set_userid(pRspRepeal->UserID);
body_message.set_verifycertnoflag(pRspRepeal->VerifyCertNoFlag);
body_message.set_currencyid(pRspRepeal->CurrencyID);
body_message.set_tradeamount(pRspRepeal->TradeAmount);
body_message.set_futurefetchamount(pRspRepeal->FutureFetchAmount);
body_message.set_feepayflag(pRspRepeal->FeePayFlag);
body_message.set_custfee(pRspRepeal->CustFee);
body_message.set_brokerfee(pRspRepeal->BrokerFee);
body_message.set_message(pRspRepeal->Message);
body_message.set_digest(pRspRepeal->Digest);
body_message.set_bankacctype(pRspRepeal->BankAccType);
body_message.set_deviceid(pRspRepeal->DeviceID);
body_message.set_banksecuacctype(pRspRepeal->BankSecuAccType);
body_message.set_brokeridbybank(pRspRepeal->BrokerIDByBank);
body_message.set_banksecuacc(pRspRepeal->BankSecuAcc);
body_message.set_bankpwdflag(pRspRepeal->BankPwdFlag);
body_message.set_secupwdflag(pRspRepeal->SecuPwdFlag);
body_message.set_operno(pRspRepeal->OperNo);
body_message.set_requestid(pRspRepeal->RequestID);
body_message.set_tid(pRspRepeal->TID);
body_message.set_transferstatus(pRspRepeal->TransferStatus);
body_message.set_errorid(pRspRepeal->ErrorID);
body_message.set_errormsg(pRspRepeal->ErrorMsg);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcRspRepealField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
void CTraderSpi::OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField* pRspRepeal)
{
guosen::msg::ctp::CThostFtdcRspRepealField body_message;
body_message.set_repealtimeinterval(pRspRepeal->RepealTimeInterval);
body_message.set_repealedtimes(pRspRepeal->RepealedTimes);
body_message.set_bankrepealflag(pRspRepeal->BankRepealFlag);
body_message.set_brokerrepealflag(pRspRepeal->BrokerRepealFlag);
body_message.set_platerepealserial(pRspRepeal->PlateRepealSerial);
body_message.set_bankrepealserial(pRspRepeal->BankRepealSerial);
body_message.set_futurerepealserial(pRspRepeal->FutureRepealSerial);
body_message.set_tradecode(pRspRepeal->TradeCode);
body_message.set_bankid(pRspRepeal->BankID);
body_message.set_bankbranchid(pRspRepeal->BankBranchID);
body_message.set_brokerid(pRspRepeal->BrokerID);
body_message.set_brokerbranchid(pRspRepeal->BrokerBranchID);
body_message.set_tradedate(pRspRepeal->TradeDate);
body_message.set_tradetime(pRspRepeal->TradeTime);
body_message.set_bankserial(pRspRepeal->BankSerial);
body_message.set_tradingday(pRspRepeal->TradingDay);
body_message.set_plateserial(pRspRepeal->PlateSerial);
body_message.set_lastfragment(pRspRepeal->LastFragment);
body_message.set_sessionid(pRspRepeal->SessionID);
body_message.set_customername(pRspRepeal->CustomerName);
body_message.set_idcardtype(pRspRepeal->IdCardType);
body_message.set_identifiedcardno(pRspRepeal->IdentifiedCardNo);
body_message.set_custtype(pRspRepeal->CustType);
body_message.set_bankaccount(pRspRepeal->BankAccount);
body_message.set_bankpassword(pRspRepeal->BankPassWord);
body_message.set_accountid(pRspRepeal->AccountID);
body_message.set_password(pRspRepeal->Password);
body_message.set_installid(pRspRepeal->InstallID);
body_message.set_futureserial(pRspRepeal->FutureSerial);
body_message.set_userid(pRspRepeal->UserID);
body_message.set_verifycertnoflag(pRspRepeal->VerifyCertNoFlag);
body_message.set_currencyid(pRspRepeal->CurrencyID);
body_message.set_tradeamount(pRspRepeal->TradeAmount);
body_message.set_futurefetchamount(pRspRepeal->FutureFetchAmount);
body_message.set_feepayflag(pRspRepeal->FeePayFlag);
body_message.set_custfee(pRspRepeal->CustFee);
body_message.set_brokerfee(pRspRepeal->BrokerFee);
body_message.set_message(pRspRepeal->Message);
body_message.set_digest(pRspRepeal->Digest);
body_message.set_bankacctype(pRspRepeal->BankAccType);
body_message.set_deviceid(pRspRepeal->DeviceID);
body_message.set_banksecuacctype(pRspRepeal->BankSecuAccType);
body_message.set_brokeridbybank(pRspRepeal->BrokerIDByBank);
body_message.set_banksecuacc(pRspRepeal->BankSecuAcc);
body_message.set_bankpwdflag(pRspRepeal->BankPwdFlag);
body_message.set_secupwdflag(pRspRepeal->SecuPwdFlag);
body_message.set_operno(pRspRepeal->OperNo);
body_message.set_requestid(pRspRepeal->RequestID);
body_message.set_tid(pRspRepeal->TID);
body_message.set_transferstatus(pRspRepeal->TransferStatus);
body_message.set_errorid(pRspRepeal->ErrorID);
body_message.set_errormsg(pRspRepeal->ErrorMsg);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcRspRepealField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///期货发起查询银行余额通知
void CTraderSpi::OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField* pNotifyQueryAccount)
{
guosen::msg::ctp::CThostFtdcNotifyQueryAccountField body_message;
body_message.set_tradecode(pNotifyQueryAccount->TradeCode);
body_message.set_bankid(pNotifyQueryAccount->BankID);
body_message.set_bankbranchid(pNotifyQueryAccount->BankBranchID);
body_message.set_brokerid(pNotifyQueryAccount->BrokerID);
body_message.set_brokerbranchid(pNotifyQueryAccount->BrokerBranchID);
body_message.set_tradedate(pNotifyQueryAccount->TradeDate);
body_message.set_tradetime(pNotifyQueryAccount->TradeTime);
body_message.set_bankserial(pNotifyQueryAccount->BankSerial);
body_message.set_tradingday(pNotifyQueryAccount->TradingDay);
body_message.set_plateserial(pNotifyQueryAccount->PlateSerial);
body_message.set_lastfragment(pNotifyQueryAccount->LastFragment);
body_message.set_sessionid(pNotifyQueryAccount->SessionID);
body_message.set_customername(pNotifyQueryAccount->CustomerName);
body_message.set_idcardtype(pNotifyQueryAccount->IdCardType);
body_message.set_identifiedcardno(pNotifyQueryAccount->IdentifiedCardNo);
body_message.set_custtype(pNotifyQueryAccount->CustType);
body_message.set_bankaccount(pNotifyQueryAccount->BankAccount);
body_message.set_bankpassword(pNotifyQueryAccount->BankPassWord);
body_message.set_accountid(pNotifyQueryAccount->AccountID);
body_message.set_password(pNotifyQueryAccount->Password);
body_message.set_futureserial(pNotifyQueryAccount->FutureSerial);
body_message.set_installid(pNotifyQueryAccount->InstallID);
body_message.set_userid(pNotifyQueryAccount->UserID);
body_message.set_verifycertnoflag(pNotifyQueryAccount->VerifyCertNoFlag);
body_message.set_currencyid(pNotifyQueryAccount->CurrencyID);
body_message.set_digest(pNotifyQueryAccount->Digest);
body_message.set_bankacctype(pNotifyQueryAccount->BankAccType);
body_message.set_deviceid(pNotifyQueryAccount->DeviceID);
body_message.set_banksecuacctype(pNotifyQueryAccount->BankSecuAccType);
body_message.set_brokeridbybank(pNotifyQueryAccount->BrokerIDByBank);
body_message.set_banksecuacc(pNotifyQueryAccount->BankSecuAcc);
body_message.set_bankpwdflag(pNotifyQueryAccount->BankPwdFlag);
body_message.set_secupwdflag(pNotifyQueryAccount->SecuPwdFlag);
body_message.set_operno(pNotifyQueryAccount->OperNo);
body_message.set_requestid(pNotifyQueryAccount->RequestID);
body_message.set_tid(pNotifyQueryAccount->TID);
body_message.set_bankuseamount(pNotifyQueryAccount->BankUseAmount);
body_message.set_bankfetchamount(pNotifyQueryAccount->BankFetchAmount);
body_message.set_errorid(pNotifyQueryAccount->ErrorID);
body_message.set_errormsg(pNotifyQueryAccount->ErrorMsg);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcNotifyQueryAccountField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///期货发起银行资金转期货错误回报
void CTraderSpi::OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo)
{
guosen::msg::ctp::CThostFtdcReqTransferField body_message;
body_message.set_tradecode(pReqTransfer->TradeCode);
body_message.set_bankid(pReqTransfer->BankID);
body_message.set_bankbranchid(pReqTransfer->BankBranchID);
body_message.set_brokerid(pReqTransfer->BrokerID);
body_message.set_brokerbranchid(pReqTransfer->BrokerBranchID);
body_message.set_tradedate(pReqTransfer->TradeDate);
body_message.set_tradetime(pReqTransfer->TradeTime);
body_message.set_bankserial(pReqTransfer->BankSerial);
body_message.set_tradingday(pReqTransfer->TradingDay);
body_message.set_plateserial(pReqTransfer->PlateSerial);
body_message.set_lastfragment(pReqTransfer->LastFragment);
body_message.set_sessionid(pReqTransfer->SessionID);
body_message.set_customername(pReqTransfer->CustomerName);
body_message.set_idcardtype(pReqTransfer->IdCardType);
body_message.set_identifiedcardno(pReqTransfer->IdentifiedCardNo);
body_message.set_custtype(pReqTransfer->CustType);
body_message.set_bankaccount(pReqTransfer->BankAccount);
body_message.set_bankpassword(pReqTransfer->BankPassWord);
body_message.set_accountid(pReqTransfer->AccountID);
body_message.set_password(pReqTransfer->Password);
body_message.set_installid(pReqTransfer->InstallID);
body_message.set_futureserial(pReqTransfer->FutureSerial);
body_message.set_userid(pReqTransfer->UserID);
body_message.set_verifycertnoflag(pReqTransfer->VerifyCertNoFlag);
body_message.set_currencyid(pReqTransfer->CurrencyID);
body_message.set_tradeamount(pReqTransfer->TradeAmount);
body_message.set_futurefetchamount(pReqTransfer->FutureFetchAmount);
body_message.set_feepayflag(pReqTransfer->FeePayFlag);
body_message.set_custfee(pReqTransfer->CustFee);
body_message.set_brokerfee(pReqTransfer->BrokerFee);
body_message.set_message(pReqTransfer->Message);
body_message.set_digest(pReqTransfer->Digest);
body_message.set_bankacctype(pReqTransfer->BankAccType);
body_message.set_deviceid(pReqTransfer->DeviceID);
body_message.set_banksecuacctype(pReqTransfer->BankSecuAccType);
body_message.set_brokeridbybank(pReqTransfer->BrokerIDByBank);
body_message.set_banksecuacc(pReqTransfer->BankSecuAcc);
body_message.set_bankpwdflag(pReqTransfer->BankPwdFlag);
body_message.set_secupwdflag(pReqTransfer->SecuPwdFlag);
body_message.set_operno(pReqTransfer->OperNo);
body_message.set_requestid(pReqTransfer->RequestID);
body_message.set_tid(pReqTransfer->TID);
body_message.set_transferstatus(pReqTransfer->TransferStatus);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcReqTransferField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///期货发起期货资金转银行错误回报
void CTraderSpi::OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo)
{
guosen::msg::ctp::CThostFtdcReqTransferField body_message;
body_message.set_tradecode(pReqTransfer->TradeCode);
body_message.set_bankid(pReqTransfer->BankID);
body_message.set_bankbranchid(pReqTransfer->BankBranchID);
body_message.set_brokerid(pReqTransfer->BrokerID);
body_message.set_brokerbranchid(pReqTransfer->BrokerBranchID);
body_message.set_tradedate(pReqTransfer->TradeDate);
body_message.set_tradetime(pReqTransfer->TradeTime);
body_message.set_bankserial(pReqTransfer->BankSerial);
body_message.set_tradingday(pReqTransfer->TradingDay);
body_message.set_plateserial(pReqTransfer->PlateSerial);
body_message.set_lastfragment(pReqTransfer->LastFragment);
body_message.set_sessionid(pReqTransfer->SessionID);
body_message.set_customername(pReqTransfer->CustomerName);
body_message.set_idcardtype(pReqTransfer->IdCardType);
body_message.set_identifiedcardno(pReqTransfer->IdentifiedCardNo);
body_message.set_custtype(pReqTransfer->CustType);
body_message.set_bankaccount(pReqTransfer->BankAccount);
body_message.set_bankpassword(pReqTransfer->BankPassWord);
body_message.set_accountid(pReqTransfer->AccountID);
body_message.set_password(pReqTransfer->Password);
body_message.set_installid(pReqTransfer->InstallID);
body_message.set_futureserial(pReqTransfer->FutureSerial);
body_message.set_userid(pReqTransfer->UserID);
body_message.set_verifycertnoflag(pReqTransfer->VerifyCertNoFlag);
body_message.set_currencyid(pReqTransfer->CurrencyID);
body_message.set_tradeamount(pReqTransfer->TradeAmount);
body_message.set_futurefetchamount(pReqTransfer->FutureFetchAmount);
body_message.set_feepayflag(pReqTransfer->FeePayFlag);
body_message.set_custfee(pReqTransfer->CustFee);
body_message.set_brokerfee(pReqTransfer->BrokerFee);
body_message.set_message(pReqTransfer->Message);
body_message.set_digest(pReqTransfer->Digest);
body_message.set_bankacctype(pReqTransfer->BankAccType);
body_message.set_deviceid(pReqTransfer->DeviceID);
body_message.set_banksecuacctype(pReqTransfer->BankSecuAccType);
body_message.set_brokeridbybank(pReqTransfer->BrokerIDByBank);
body_message.set_banksecuacc(pReqTransfer->BankSecuAcc);
body_message.set_bankpwdflag(pReqTransfer->BankPwdFlag);
body_message.set_secupwdflag(pReqTransfer->SecuPwdFlag);
body_message.set_operno(pReqTransfer->OperNo);
body_message.set_requestid(pReqTransfer->RequestID);
body_message.set_tid(pReqTransfer->TID);
body_message.set_transferstatus(pReqTransfer->TransferStatus);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcReqTransferField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///系统运行时期货端手工发起冲正银行转期货错误回报
void CTraderSpi::OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo)
{
guosen::msg::ctp::CThostFtdcReqRepealField body_message;
body_message.set_repealtimeinterval(pReqRepeal->RepealTimeInterval);
body_message.set_repealedtimes(pReqRepeal->RepealedTimes);
body_message.set_bankrepealflag(pReqRepeal->BankRepealFlag);
body_message.set_brokerrepealflag(pReqRepeal->BrokerRepealFlag);
body_message.set_platerepealserial(pReqRepeal->PlateRepealSerial);
body_message.set_bankrepealserial(pReqRepeal->BankRepealSerial);
body_message.set_futurerepealserial(pReqRepeal->FutureRepealSerial);
body_message.set_tradecode(pReqRepeal->TradeCode);
body_message.set_bankid(pReqRepeal->BankID);
body_message.set_bankbranchid(pReqRepeal->BankBranchID);
body_message.set_brokerid(pReqRepeal->BrokerID);
body_message.set_brokerbranchid(pReqRepeal->BrokerBranchID);
body_message.set_tradedate(pReqRepeal->TradeDate);
body_message.set_tradetime(pReqRepeal->TradeTime);
body_message.set_bankserial(pReqRepeal->BankSerial);
body_message.set_tradingday(pReqRepeal->TradingDay);
body_message.set_plateserial(pReqRepeal->PlateSerial);
body_message.set_lastfragment(pReqRepeal->LastFragment);
body_message.set_sessionid(pReqRepeal->SessionID);
body_message.set_customername(pReqRepeal->CustomerName);
body_message.set_idcardtype(pReqRepeal->IdCardType);
body_message.set_identifiedcardno(pReqRepeal->IdentifiedCardNo);
body_message.set_custtype(pReqRepeal->CustType);
body_message.set_bankaccount(pReqRepeal->BankAccount);
body_message.set_bankpassword(pReqRepeal->BankPassWord);
body_message.set_accountid(pReqRepeal->AccountID);
body_message.set_password(pReqRepeal->Password);
body_message.set_installid(pReqRepeal->InstallID);
body_message.set_futureserial(pReqRepeal->FutureSerial);
body_message.set_userid(pReqRepeal->UserID);
body_message.set_verifycertnoflag(pReqRepeal->VerifyCertNoFlag);
body_message.set_currencyid(pReqRepeal->CurrencyID);
body_message.set_tradeamount(pReqRepeal->TradeAmount);
body_message.set_futurefetchamount(pReqRepeal->FutureFetchAmount);
body_message.set_feepayflag(pReqRepeal->FeePayFlag);
body_message.set_custfee(pReqRepeal->CustFee);
body_message.set_brokerfee(pReqRepeal->BrokerFee);
body_message.set_message(pReqRepeal->Message);
body_message.set_digest(pReqRepeal->Digest);
body_message.set_bankacctype(pReqRepeal->BankAccType);
body_message.set_deviceid(pReqRepeal->DeviceID);
body_message.set_banksecuacctype(pReqRepeal->BankSecuAccType);
body_message.set_brokeridbybank(pReqRepeal->BrokerIDByBank);
body_message.set_banksecuacc(pReqRepeal->BankSecuAcc);
body_message.set_bankpwdflag(pReqRepeal->BankPwdFlag);
body_message.set_secupwdflag(pReqRepeal->SecuPwdFlag);
body_message.set_operno(pReqRepeal->OperNo);
body_message.set_requestid(pReqRepeal->RequestID);
body_message.set_tid(pReqRepeal->TID);
body_message.set_transferstatus(pReqRepeal->TransferStatus);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcReqRepealField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///系统运行时期货端手工发起冲正期货转银行错误回报
void CTraderSpi::OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField* pReqRepeal, CThostFtdcRspInfoField* pRspInfo)
{
guosen::msg::ctp::CThostFtdcReqRepealField body_message;
body_message.set_repealtimeinterval(pReqRepeal->RepealTimeInterval);
body_message.set_repealedtimes(pReqRepeal->RepealedTimes);
body_message.set_bankrepealflag(pReqRepeal->BankRepealFlag);
body_message.set_brokerrepealflag(pReqRepeal->BrokerRepealFlag);
body_message.set_platerepealserial(pReqRepeal->PlateRepealSerial);
body_message.set_bankrepealserial(pReqRepeal->BankRepealSerial);
body_message.set_futurerepealserial(pReqRepeal->FutureRepealSerial);
body_message.set_tradecode(pReqRepeal->TradeCode);
body_message.set_bankid(pReqRepeal->BankID);
body_message.set_bankbranchid(pReqRepeal->BankBranchID);
body_message.set_brokerid(pReqRepeal->BrokerID);
body_message.set_brokerbranchid(pReqRepeal->BrokerBranchID);
body_message.set_tradedate(pReqRepeal->TradeDate);
body_message.set_tradetime(pReqRepeal->TradeTime);
body_message.set_bankserial(pReqRepeal->BankSerial);
body_message.set_tradingday(pReqRepeal->TradingDay);
body_message.set_plateserial(pReqRepeal->PlateSerial);
body_message.set_lastfragment(pReqRepeal->LastFragment);
body_message.set_sessionid(pReqRepeal->SessionID);
body_message.set_customername(pReqRepeal->CustomerName);
body_message.set_idcardtype(pReqRepeal->IdCardType);
body_message.set_identifiedcardno(pReqRepeal->IdentifiedCardNo);
body_message.set_custtype(pReqRepeal->CustType);
body_message.set_bankaccount(pReqRepeal->BankAccount);
body_message.set_bankpassword(pReqRepeal->BankPassWord);
body_message.set_accountid(pReqRepeal->AccountID);
body_message.set_password(pReqRepeal->Password);
body_message.set_installid(pReqRepeal->InstallID);
body_message.set_futureserial(pReqRepeal->FutureSerial);
body_message.set_userid(pReqRepeal->UserID);
body_message.set_verifycertnoflag(pReqRepeal->VerifyCertNoFlag);
body_message.set_currencyid(pReqRepeal->CurrencyID);
body_message.set_tradeamount(pReqRepeal->TradeAmount);
body_message.set_futurefetchamount(pReqRepeal->FutureFetchAmount);
body_message.set_feepayflag(pReqRepeal->FeePayFlag);
body_message.set_custfee(pReqRepeal->CustFee);
body_message.set_brokerfee(pReqRepeal->BrokerFee);
body_message.set_message(pReqRepeal->Message);
body_message.set_digest(pReqRepeal->Digest);
body_message.set_bankacctype(pReqRepeal->BankAccType);
body_message.set_deviceid(pReqRepeal->DeviceID);
body_message.set_banksecuacctype(pReqRepeal->BankSecuAccType);
body_message.set_brokeridbybank(pReqRepeal->BrokerIDByBank);
body_message.set_banksecuacc(pReqRepeal->BankSecuAcc);
body_message.set_bankpwdflag(pReqRepeal->BankPwdFlag);
body_message.set_secupwdflag(pReqRepeal->SecuPwdFlag);
body_message.set_operno(pReqRepeal->OperNo);
body_message.set_requestid(pReqRepeal->RequestID);
body_message.set_tid(pReqRepeal->TID);
body_message.set_transferstatus(pReqRepeal->TransferStatus);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcReqRepealField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///期货发起查询银行余额错误回报
void CTraderSpi::OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo)
{
guosen::msg::ctp::CThostFtdcReqQueryAccountField body_message;
body_message.set_tradecode(pReqQueryAccount->TradeCode);
body_message.set_bankid(pReqQueryAccount->BankID);
body_message.set_bankbranchid(pReqQueryAccount->BankBranchID);
body_message.set_brokerid(pReqQueryAccount->BrokerID);
body_message.set_brokerbranchid(pReqQueryAccount->BrokerBranchID);
body_message.set_tradedate(pReqQueryAccount->TradeDate);
body_message.set_tradetime(pReqQueryAccount->TradeTime);
body_message.set_bankserial(pReqQueryAccount->BankSerial);
body_message.set_tradingday(pReqQueryAccount->TradingDay);
body_message.set_plateserial(pReqQueryAccount->PlateSerial);
body_message.set_lastfragment(pReqQueryAccount->LastFragment);
body_message.set_sessionid(pReqQueryAccount->SessionID);
body_message.set_customername(pReqQueryAccount->CustomerName);
body_message.set_idcardtype(pReqQueryAccount->IdCardType);
body_message.set_identifiedcardno(pReqQueryAccount->IdentifiedCardNo);
body_message.set_custtype(pReqQueryAccount->CustType);
body_message.set_bankaccount(pReqQueryAccount->BankAccount);
body_message.set_bankpassword(pReqQueryAccount->BankPassWord);
body_message.set_accountid(pReqQueryAccount->AccountID);
body_message.set_password(pReqQueryAccount->Password);
body_message.set_futureserial(pReqQueryAccount->FutureSerial);
body_message.set_installid(pReqQueryAccount->InstallID);
body_message.set_userid(pReqQueryAccount->UserID);
body_message.set_verifycertnoflag(pReqQueryAccount->VerifyCertNoFlag);
body_message.set_currencyid(pReqQueryAccount->CurrencyID);
body_message.set_digest(pReqQueryAccount->Digest);
body_message.set_bankacctype(pReqQueryAccount->BankAccType);
body_message.set_deviceid(pReqQueryAccount->DeviceID);
body_message.set_banksecuacctype(pReqQueryAccount->BankSecuAccType);
body_message.set_brokeridbybank(pReqQueryAccount->BrokerIDByBank);
body_message.set_banksecuacc(pReqQueryAccount->BankSecuAcc);
body_message.set_bankpwdflag(pReqQueryAccount->BankPwdFlag);
body_message.set_secupwdflag(pReqQueryAccount->SecuPwdFlag);
body_message.set_operno(pReqQueryAccount->OperNo);
body_message.set_requestid(pReqQueryAccount->RequestID);
body_message.set_tid(pReqQueryAccount->TID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcReqQueryAccountField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
void CTraderSpi::OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField* pRspRepeal)
{
guosen::msg::ctp::CThostFtdcRspRepealField body_message;
body_message.set_repealtimeinterval(pRspRepeal->RepealTimeInterval);
body_message.set_repealedtimes(pRspRepeal->RepealedTimes);
body_message.set_bankrepealflag(pRspRepeal->BankRepealFlag);
body_message.set_brokerrepealflag(pRspRepeal->BrokerRepealFlag);
body_message.set_platerepealserial(pRspRepeal->PlateRepealSerial);
body_message.set_bankrepealserial(pRspRepeal->BankRepealSerial);
body_message.set_futurerepealserial(pRspRepeal->FutureRepealSerial);
body_message.set_tradecode(pRspRepeal->TradeCode);
body_message.set_bankid(pRspRepeal->BankID);
body_message.set_bankbranchid(pRspRepeal->BankBranchID);
body_message.set_brokerid(pRspRepeal->BrokerID);
body_message.set_brokerbranchid(pRspRepeal->BrokerBranchID);
body_message.set_tradedate(pRspRepeal->TradeDate);
body_message.set_tradetime(pRspRepeal->TradeTime);
body_message.set_bankserial(pRspRepeal->BankSerial);
body_message.set_tradingday(pRspRepeal->TradingDay);
body_message.set_plateserial(pRspRepeal->PlateSerial);
body_message.set_lastfragment(pRspRepeal->LastFragment);
body_message.set_sessionid(pRspRepeal->SessionID);
body_message.set_customername(pRspRepeal->CustomerName);
body_message.set_idcardtype(pRspRepeal->IdCardType);
body_message.set_identifiedcardno(pRspRepeal->IdentifiedCardNo);
body_message.set_custtype(pRspRepeal->CustType);
body_message.set_bankaccount(pRspRepeal->BankAccount);
body_message.set_bankpassword(pRspRepeal->BankPassWord);
body_message.set_accountid(pRspRepeal->AccountID);
body_message.set_password(pRspRepeal->Password);
body_message.set_installid(pRspRepeal->InstallID);
body_message.set_futureserial(pRspRepeal->FutureSerial);
body_message.set_userid(pRspRepeal->UserID);
body_message.set_verifycertnoflag(pRspRepeal->VerifyCertNoFlag);
body_message.set_currencyid(pRspRepeal->CurrencyID);
body_message.set_tradeamount(pRspRepeal->TradeAmount);
body_message.set_futurefetchamount(pRspRepeal->FutureFetchAmount);
body_message.set_feepayflag(pRspRepeal->FeePayFlag);
body_message.set_custfee(pRspRepeal->CustFee);
body_message.set_brokerfee(pRspRepeal->BrokerFee);
body_message.set_message(pRspRepeal->Message);
body_message.set_digest(pRspRepeal->Digest);
body_message.set_bankacctype(pRspRepeal->BankAccType);
body_message.set_deviceid(pRspRepeal->DeviceID);
body_message.set_banksecuacctype(pRspRepeal->BankSecuAccType);
body_message.set_brokeridbybank(pRspRepeal->BrokerIDByBank);
body_message.set_banksecuacc(pRspRepeal->BankSecuAcc);
body_message.set_bankpwdflag(pRspRepeal->BankPwdFlag);
body_message.set_secupwdflag(pRspRepeal->SecuPwdFlag);
body_message.set_operno(pRspRepeal->OperNo);
body_message.set_requestid(pRspRepeal->RequestID);
body_message.set_tid(pRspRepeal->TID);
body_message.set_transferstatus(pRspRepeal->TransferStatus);
body_message.set_errorid(pRspRepeal->ErrorID);
body_message.set_errormsg(pRspRepeal->ErrorMsg);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcRspRepealField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
void CTraderSpi::OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField* pRspRepeal)
{
guosen::msg::ctp::CThostFtdcRspRepealField body_message;
body_message.set_repealtimeinterval(pRspRepeal->RepealTimeInterval);
body_message.set_repealedtimes(pRspRepeal->RepealedTimes);
body_message.set_bankrepealflag(pRspRepeal->BankRepealFlag);
body_message.set_brokerrepealflag(pRspRepeal->BrokerRepealFlag);
body_message.set_platerepealserial(pRspRepeal->PlateRepealSerial);
body_message.set_bankrepealserial(pRspRepeal->BankRepealSerial);
body_message.set_futurerepealserial(pRspRepeal->FutureRepealSerial);
body_message.set_tradecode(pRspRepeal->TradeCode);
body_message.set_bankid(pRspRepeal->BankID);
body_message.set_bankbranchid(pRspRepeal->BankBranchID);
body_message.set_brokerid(pRspRepeal->BrokerID);
body_message.set_brokerbranchid(pRspRepeal->BrokerBranchID);
body_message.set_tradedate(pRspRepeal->TradeDate);
body_message.set_tradetime(pRspRepeal->TradeTime);
body_message.set_bankserial(pRspRepeal->BankSerial);
body_message.set_tradingday(pRspRepeal->TradingDay);
body_message.set_plateserial(pRspRepeal->PlateSerial);
body_message.set_lastfragment(pRspRepeal->LastFragment);
body_message.set_sessionid(pRspRepeal->SessionID);
body_message.set_customername(pRspRepeal->CustomerName);
body_message.set_idcardtype(pRspRepeal->IdCardType);
body_message.set_identifiedcardno(pRspRepeal->IdentifiedCardNo);
body_message.set_custtype(pRspRepeal->CustType);
body_message.set_bankaccount(pRspRepeal->BankAccount);
body_message.set_bankpassword(pRspRepeal->BankPassWord);
body_message.set_accountid(pRspRepeal->AccountID);
body_message.set_password(pRspRepeal->Password);
body_message.set_installid(pRspRepeal->InstallID);
body_message.set_futureserial(pRspRepeal->FutureSerial);
body_message.set_userid(pRspRepeal->UserID);
body_message.set_verifycertnoflag(pRspRepeal->VerifyCertNoFlag);
body_message.set_currencyid(pRspRepeal->CurrencyID);
body_message.set_tradeamount(pRspRepeal->TradeAmount);
body_message.set_futurefetchamount(pRspRepeal->FutureFetchAmount);
body_message.set_feepayflag(pRspRepeal->FeePayFlag);
body_message.set_custfee(pRspRepeal->CustFee);
body_message.set_brokerfee(pRspRepeal->BrokerFee);
body_message.set_message(pRspRepeal->Message);
body_message.set_digest(pRspRepeal->Digest);
body_message.set_bankacctype(pRspRepeal->BankAccType);
body_message.set_deviceid(pRspRepeal->DeviceID);
body_message.set_banksecuacctype(pRspRepeal->BankSecuAccType);
body_message.set_brokeridbybank(pRspRepeal->BrokerIDByBank);
body_message.set_banksecuacc(pRspRepeal->BankSecuAcc);
body_message.set_bankpwdflag(pRspRepeal->BankPwdFlag);
body_message.set_secupwdflag(pRspRepeal->SecuPwdFlag);
body_message.set_operno(pRspRepeal->OperNo);
body_message.set_requestid(pRspRepeal->RequestID);
body_message.set_tid(pRspRepeal->TID);
body_message.set_transferstatus(pRspRepeal->TransferStatus);
body_message.set_errorid(pRspRepeal->ErrorID);
body_message.set_errormsg(pRspRepeal->ErrorMsg);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcRspRepealField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///期货发起银行资金转期货应答
void CTraderSpi::OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcReqTransferField body_message;
body_message.set_tradecode(pReqTransfer->TradeCode);
body_message.set_bankid(pReqTransfer->BankID);
body_message.set_bankbranchid(pReqTransfer->BankBranchID);
body_message.set_brokerid(pReqTransfer->BrokerID);
body_message.set_brokerbranchid(pReqTransfer->BrokerBranchID);
body_message.set_tradedate(pReqTransfer->TradeDate);
body_message.set_tradetime(pReqTransfer->TradeTime);
body_message.set_bankserial(pReqTransfer->BankSerial);
body_message.set_tradingday(pReqTransfer->TradingDay);
body_message.set_plateserial(pReqTransfer->PlateSerial);
body_message.set_lastfragment(pReqTransfer->LastFragment);
body_message.set_sessionid(pReqTransfer->SessionID);
body_message.set_customername(pReqTransfer->CustomerName);
body_message.set_idcardtype(pReqTransfer->IdCardType);
body_message.set_identifiedcardno(pReqTransfer->IdentifiedCardNo);
body_message.set_custtype(pReqTransfer->CustType);
body_message.set_bankaccount(pReqTransfer->BankAccount);
body_message.set_bankpassword(pReqTransfer->BankPassWord);
body_message.set_accountid(pReqTransfer->AccountID);
body_message.set_password(pReqTransfer->Password);
body_message.set_installid(pReqTransfer->InstallID);
body_message.set_futureserial(pReqTransfer->FutureSerial);
body_message.set_userid(pReqTransfer->UserID);
body_message.set_verifycertnoflag(pReqTransfer->VerifyCertNoFlag);
body_message.set_currencyid(pReqTransfer->CurrencyID);
body_message.set_tradeamount(pReqTransfer->TradeAmount);
body_message.set_futurefetchamount(pReqTransfer->FutureFetchAmount);
body_message.set_feepayflag(pReqTransfer->FeePayFlag);
body_message.set_custfee(pReqTransfer->CustFee);
body_message.set_brokerfee(pReqTransfer->BrokerFee);
body_message.set_message(pReqTransfer->Message);
body_message.set_digest(pReqTransfer->Digest);
body_message.set_bankacctype(pReqTransfer->BankAccType);
body_message.set_deviceid(pReqTransfer->DeviceID);
body_message.set_banksecuacctype(pReqTransfer->BankSecuAccType);
body_message.set_brokeridbybank(pReqTransfer->BrokerIDByBank);
body_message.set_banksecuacc(pReqTransfer->BankSecuAcc);
body_message.set_bankpwdflag(pReqTransfer->BankPwdFlag);
body_message.set_secupwdflag(pReqTransfer->SecuPwdFlag);
body_message.set_operno(pReqTransfer->OperNo);
body_message.set_requestid(pReqTransfer->RequestID);
body_message.set_tid(pReqTransfer->TID);
body_message.set_transferstatus(pReqTransfer->TransferStatus);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcReqTransferField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///期货发起期货资金转银行应答
void CTraderSpi::OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField* pReqTransfer, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcReqTransferField body_message;
body_message.set_tradecode(pReqTransfer->TradeCode);
body_message.set_bankid(pReqTransfer->BankID);
body_message.set_bankbranchid(pReqTransfer->BankBranchID);
body_message.set_brokerid(pReqTransfer->BrokerID);
body_message.set_brokerbranchid(pReqTransfer->BrokerBranchID);
body_message.set_tradedate(pReqTransfer->TradeDate);
body_message.set_tradetime(pReqTransfer->TradeTime);
body_message.set_bankserial(pReqTransfer->BankSerial);
body_message.set_tradingday(pReqTransfer->TradingDay);
body_message.set_plateserial(pReqTransfer->PlateSerial);
body_message.set_lastfragment(pReqTransfer->LastFragment);
body_message.set_sessionid(pReqTransfer->SessionID);
body_message.set_customername(pReqTransfer->CustomerName);
body_message.set_idcardtype(pReqTransfer->IdCardType);
body_message.set_identifiedcardno(pReqTransfer->IdentifiedCardNo);
body_message.set_custtype(pReqTransfer->CustType);
body_message.set_bankaccount(pReqTransfer->BankAccount);
body_message.set_bankpassword(pReqTransfer->BankPassWord);
body_message.set_accountid(pReqTransfer->AccountID);
body_message.set_password(pReqTransfer->Password);
body_message.set_installid(pReqTransfer->InstallID);
body_message.set_futureserial(pReqTransfer->FutureSerial);
body_message.set_userid(pReqTransfer->UserID);
body_message.set_verifycertnoflag(pReqTransfer->VerifyCertNoFlag);
body_message.set_currencyid(pReqTransfer->CurrencyID);
body_message.set_tradeamount(pReqTransfer->TradeAmount);
body_message.set_futurefetchamount(pReqTransfer->FutureFetchAmount);
body_message.set_feepayflag(pReqTransfer->FeePayFlag);
body_message.set_custfee(pReqTransfer->CustFee);
body_message.set_brokerfee(pReqTransfer->BrokerFee);
body_message.set_message(pReqTransfer->Message);
body_message.set_digest(pReqTransfer->Digest);
body_message.set_bankacctype(pReqTransfer->BankAccType);
body_message.set_deviceid(pReqTransfer->DeviceID);
body_message.set_banksecuacctype(pReqTransfer->BankSecuAccType);
body_message.set_brokeridbybank(pReqTransfer->BrokerIDByBank);
body_message.set_banksecuacc(pReqTransfer->BankSecuAcc);
body_message.set_bankpwdflag(pReqTransfer->BankPwdFlag);
body_message.set_secupwdflag(pReqTransfer->SecuPwdFlag);
body_message.set_operno(pReqTransfer->OperNo);
body_message.set_requestid(pReqTransfer->RequestID);
body_message.set_tid(pReqTransfer->TID);
body_message.set_transferstatus(pReqTransfer->TransferStatus);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcReqTransferField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///期货发起查询银行余额应答
void CTraderSpi::OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField* pReqQueryAccount, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
guosen::msg::ctp::CThostFtdcReqQueryAccountField body_message;
body_message.set_tradecode(pReqQueryAccount->TradeCode);
body_message.set_bankid(pReqQueryAccount->BankID);
body_message.set_bankbranchid(pReqQueryAccount->BankBranchID);
body_message.set_brokerid(pReqQueryAccount->BrokerID);
body_message.set_brokerbranchid(pReqQueryAccount->BrokerBranchID);
body_message.set_tradedate(pReqQueryAccount->TradeDate);
body_message.set_tradetime(pReqQueryAccount->TradeTime);
body_message.set_bankserial(pReqQueryAccount->BankSerial);
body_message.set_tradingday(pReqQueryAccount->TradingDay);
body_message.set_plateserial(pReqQueryAccount->PlateSerial);
body_message.set_lastfragment(pReqQueryAccount->LastFragment);
body_message.set_sessionid(pReqQueryAccount->SessionID);
body_message.set_customername(pReqQueryAccount->CustomerName);
body_message.set_idcardtype(pReqQueryAccount->IdCardType);
body_message.set_identifiedcardno(pReqQueryAccount->IdentifiedCardNo);
body_message.set_custtype(pReqQueryAccount->CustType);
body_message.set_bankaccount(pReqQueryAccount->BankAccount);
body_message.set_bankpassword(pReqQueryAccount->BankPassWord);
body_message.set_accountid(pReqQueryAccount->AccountID);
body_message.set_password(pReqQueryAccount->Password);
body_message.set_futureserial(pReqQueryAccount->FutureSerial);
body_message.set_installid(pReqQueryAccount->InstallID);
body_message.set_userid(pReqQueryAccount->UserID);
body_message.set_verifycertnoflag(pReqQueryAccount->VerifyCertNoFlag);
body_message.set_currencyid(pReqQueryAccount->CurrencyID);
body_message.set_digest(pReqQueryAccount->Digest);
body_message.set_bankacctype(pReqQueryAccount->BankAccType);
body_message.set_deviceid(pReqQueryAccount->DeviceID);
body_message.set_banksecuacctype(pReqQueryAccount->BankSecuAccType);
body_message.set_brokeridbybank(pReqQueryAccount->BrokerIDByBank);
body_message.set_banksecuacc(pReqQueryAccount->BankSecuAcc);
body_message.set_bankpwdflag(pReqQueryAccount->BankPwdFlag);
body_message.set_secupwdflag(pReqQueryAccount->SecuPwdFlag);
body_message.set_operno(pReqQueryAccount->OperNo);
body_message.set_requestid(pReqQueryAccount->RequestID);
body_message.set_tid(pReqQueryAccount->TID);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcReqQueryAccountField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///银行发起银期开户通知
void CTraderSpi::OnRtnOpenAccountByBank(CThostFtdcOpenAccountField* pOpenAccount)
{
guosen::msg::ctp::CThostFtdcOpenAccountField body_message;
body_message.set_tradecode(pOpenAccount->TradeCode);
body_message.set_bankid(pOpenAccount->BankID);
body_message.set_bankbranchid(pOpenAccount->BankBranchID);
body_message.set_brokerid(pOpenAccount->BrokerID);
body_message.set_brokerbranchid(pOpenAccount->BrokerBranchID);
body_message.set_tradedate(pOpenAccount->TradeDate);
body_message.set_tradetime(pOpenAccount->TradeTime);
body_message.set_bankserial(pOpenAccount->BankSerial);
body_message.set_tradingday(pOpenAccount->TradingDay);
body_message.set_plateserial(pOpenAccount->PlateSerial);
body_message.set_lastfragment(pOpenAccount->LastFragment);
body_message.set_sessionid(pOpenAccount->SessionID);
body_message.set_customername(pOpenAccount->CustomerName);
body_message.set_idcardtype(pOpenAccount->IdCardType);
body_message.set_identifiedcardno(pOpenAccount->IdentifiedCardNo);
body_message.set_gender(pOpenAccount->Gender);
body_message.set_countrycode(pOpenAccount->CountryCode);
body_message.set_custtype(pOpenAccount->CustType);
body_message.set_address(pOpenAccount->Address);
body_message.set_zipcode(pOpenAccount->ZipCode);
body_message.set_telephone(pOpenAccount->Telephone);
body_message.set_mobilephone(pOpenAccount->MobilePhone);
body_message.set_fax(pOpenAccount->Fax);
body_message.set_email(pOpenAccount->EMail);
body_message.set_moneyaccountstatus(pOpenAccount->MoneyAccountStatus);
body_message.set_bankaccount(pOpenAccount->BankAccount);
body_message.set_bankpassword(pOpenAccount->BankPassWord);
body_message.set_accountid(pOpenAccount->AccountID);
body_message.set_password(pOpenAccount->Password);
body_message.set_installid(pOpenAccount->InstallID);
body_message.set_verifycertnoflag(pOpenAccount->VerifyCertNoFlag);
body_message.set_currencyid(pOpenAccount->CurrencyID);
body_message.set_cashexchangecode(pOpenAccount->CashExchangeCode);
body_message.set_digest(pOpenAccount->Digest);
body_message.set_bankacctype(pOpenAccount->BankAccType);
body_message.set_deviceid(pOpenAccount->DeviceID);
body_message.set_banksecuacctype(pOpenAccount->BankSecuAccType);
body_message.set_brokeridbybank(pOpenAccount->BrokerIDByBank);
body_message.set_banksecuacc(pOpenAccount->BankSecuAcc);
body_message.set_bankpwdflag(pOpenAccount->BankPwdFlag);
body_message.set_secupwdflag(pOpenAccount->SecuPwdFlag);
body_message.set_operno(pOpenAccount->OperNo);
body_message.set_tid(pOpenAccount->TID);
body_message.set_userid(pOpenAccount->UserID);
body_message.set_errorid(pOpenAccount->ErrorID);
body_message.set_errormsg(pOpenAccount->ErrorMsg);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcOpenAccountField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///银行发起银期销户通知
void CTraderSpi::OnRtnCancelAccountByBank(CThostFtdcCancelAccountField* pCancelAccount)
{
guosen::msg::ctp::CThostFtdcCancelAccountField body_message;
body_message.set_tradecode(pCancelAccount->TradeCode);
body_message.set_bankid(pCancelAccount->BankID);
body_message.set_bankbranchid(pCancelAccount->BankBranchID);
body_message.set_brokerid(pCancelAccount->BrokerID);
body_message.set_brokerbranchid(pCancelAccount->BrokerBranchID);
body_message.set_tradedate(pCancelAccount->TradeDate);
body_message.set_tradetime(pCancelAccount->TradeTime);
body_message.set_bankserial(pCancelAccount->BankSerial);
body_message.set_tradingday(pCancelAccount->TradingDay);
body_message.set_plateserial(pCancelAccount->PlateSerial);
body_message.set_lastfragment(pCancelAccount->LastFragment);
body_message.set_sessionid(pCancelAccount->SessionID);
body_message.set_customername(pCancelAccount->CustomerName);
body_message.set_idcardtype(pCancelAccount->IdCardType);
body_message.set_identifiedcardno(pCancelAccount->IdentifiedCardNo);
body_message.set_gender(pCancelAccount->Gender);
body_message.set_countrycode(pCancelAccount->CountryCode);
body_message.set_custtype(pCancelAccount->CustType);
body_message.set_address(pCancelAccount->Address);
body_message.set_zipcode(pCancelAccount->ZipCode);
body_message.set_telephone(pCancelAccount->Telephone);
body_message.set_mobilephone(pCancelAccount->MobilePhone);
body_message.set_fax(pCancelAccount->Fax);
body_message.set_email(pCancelAccount->EMail);
body_message.set_moneyaccountstatus(pCancelAccount->MoneyAccountStatus);
body_message.set_bankaccount(pCancelAccount->BankAccount);
body_message.set_bankpassword(pCancelAccount->BankPassWord);
body_message.set_accountid(pCancelAccount->AccountID);
body_message.set_password(pCancelAccount->Password);
body_message.set_installid(pCancelAccount->InstallID);
body_message.set_verifycertnoflag(pCancelAccount->VerifyCertNoFlag);
body_message.set_currencyid(pCancelAccount->CurrencyID);
body_message.set_cashexchangecode(pCancelAccount->CashExchangeCode);
body_message.set_digest(pCancelAccount->Digest);
body_message.set_bankacctype(pCancelAccount->BankAccType);
body_message.set_deviceid(pCancelAccount->DeviceID);
body_message.set_banksecuacctype(pCancelAccount->BankSecuAccType);
body_message.set_brokeridbybank(pCancelAccount->BrokerIDByBank);
body_message.set_banksecuacc(pCancelAccount->BankSecuAcc);
body_message.set_bankpwdflag(pCancelAccount->BankPwdFlag);
body_message.set_secupwdflag(pCancelAccount->SecuPwdFlag);
body_message.set_operno(pCancelAccount->OperNo);
body_message.set_tid(pCancelAccount->TID);
body_message.set_userid(pCancelAccount->UserID);
body_message.set_errorid(pCancelAccount->ErrorID);
body_message.set_errormsg(pCancelAccount->ErrorMsg);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcCancelAccountField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}

///银行发起变更银行账号通知
void CTraderSpi::OnRtnChangeAccountByBank(CThostFtdcChangeAccountField* pChangeAccount)
{
guosen::msg::ctp::CThostFtdcChangeAccountField body_message;
body_message.set_tradecode(pChangeAccount->TradeCode);
body_message.set_bankid(pChangeAccount->BankID);
body_message.set_bankbranchid(pChangeAccount->BankBranchID);
body_message.set_brokerid(pChangeAccount->BrokerID);
body_message.set_brokerbranchid(pChangeAccount->BrokerBranchID);
body_message.set_tradedate(pChangeAccount->TradeDate);
body_message.set_tradetime(pChangeAccount->TradeTime);
body_message.set_bankserial(pChangeAccount->BankSerial);
body_message.set_tradingday(pChangeAccount->TradingDay);
body_message.set_plateserial(pChangeAccount->PlateSerial);
body_message.set_lastfragment(pChangeAccount->LastFragment);
body_message.set_sessionid(pChangeAccount->SessionID);
body_message.set_customername(pChangeAccount->CustomerName);
body_message.set_idcardtype(pChangeAccount->IdCardType);
body_message.set_identifiedcardno(pChangeAccount->IdentifiedCardNo);
body_message.set_gender(pChangeAccount->Gender);
body_message.set_countrycode(pChangeAccount->CountryCode);
body_message.set_custtype(pChangeAccount->CustType);
body_message.set_address(pChangeAccount->Address);
body_message.set_zipcode(pChangeAccount->ZipCode);
body_message.set_telephone(pChangeAccount->Telephone);
body_message.set_mobilephone(pChangeAccount->MobilePhone);
body_message.set_fax(pChangeAccount->Fax);
body_message.set_email(pChangeAccount->EMail);
body_message.set_moneyaccountstatus(pChangeAccount->MoneyAccountStatus);
body_message.set_bankaccount(pChangeAccount->BankAccount);
body_message.set_bankpassword(pChangeAccount->BankPassWord);
body_message.set_newbankaccount(pChangeAccount->NewBankAccount);
body_message.set_newbankpassword(pChangeAccount->NewBankPassWord);
body_message.set_accountid(pChangeAccount->AccountID);
body_message.set_password(pChangeAccount->Password);
body_message.set_bankacctype(pChangeAccount->BankAccType);
body_message.set_installid(pChangeAccount->InstallID);
body_message.set_verifycertnoflag(pChangeAccount->VerifyCertNoFlag);
body_message.set_currencyid(pChangeAccount->CurrencyID);
body_message.set_brokeridbybank(pChangeAccount->BrokerIDByBank);
body_message.set_bankpwdflag(pChangeAccount->BankPwdFlag);
body_message.set_secupwdflag(pChangeAccount->SecuPwdFlag);
body_message.set_tid(pChangeAccount->TID);
body_message.set_digest(pChangeAccount->Digest);
body_message.set_errorid(pChangeAccount->ErrorID);
body_message.set_errormsg(pChangeAccount->ErrorMsg);
guosen::msg::ProtoMsg proto_message;
proto_message.set_head(guosen::msg::MsgType::CThostFtdcChangeAccountField);
body_message.SerializeToString(proto_message.mutable_body());
do_publish(proto_message);
}
