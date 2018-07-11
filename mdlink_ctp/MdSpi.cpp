#include "MdSpi.h"
#include "ctp.pb.h"
#include "zhelpers.hpp"
// #include <stdio.h>

extern Document d;
extern zmq::context_t context;
extern zmq::socket_t publisher;

int CMdSpi::exit()
{
        //�ú�����ԭ��API��û�У����ڰ�ȫ�˳�API�ã�ԭ����join�ƺ���̫�ȶ�
        userapi->RegisterSpi(NULL);
        userapi->Release();
        userapi = NULL;
        return 1;
};

void CMdSpi::subscribeMarketData(const vector<string>& instruments, const vector<string>& markets)
{
        // cerr << "--->>> " << __FUNCTION__ << endl;
        // //char* pp[] = { "IF1804", "IF1805" };
        // char* pp[] = { "IF1807" };
        // int iResult = pUserCMdSpi->SubscribeMarketData(pp, 2);
        // cerr << "--->>> send SubscribeMarketData request: " << ((iResult == 0) ? "success" : "failed") << endl;
        //
        // int ncount = instruments.size();
        // char* insts[ncount];
        // for (int i = 0; i < ncount; i++)
        //         insts[i] = const_cast<char*>(instruments[i].c_str());
        //
        // userapi->SubscribeMarketData(insts, ncount);
}

int CMdSpi::subscribeMarketData(string instrumentID)
{
        char* buffer = (char*)instrumentID.c_str();
        char* myreq[1] = { buffer };
        int i = userapi->SubscribeMarketData(myreq, 1);
        return i;
};

int CMdSpi::unSubscribeMarketData(string instrumentID)
{
        char* buffer = (char*)instrumentID.c_str();
        char* myreq[1] = { buffer };
        int i = userapi->UnSubscribeMarketData(myreq, 1);
        return i;
};

int CMdSpi::subscribeForQuoteRsp(string instrumentID)
{
        char* buffer = (char*)instrumentID.c_str();
        char* myreq[1] = { buffer };
        int i = userapi->SubscribeForQuoteRsp(myreq, 1);
        return i;
};

int CMdSpi::unSubscribeForQuoteRsp(string instrumentID)
{
        char* buffer = (char*)instrumentID.c_str();
        char* myreq[1] = { buffer };
        int i = userapi->UnSubscribeForQuoteRsp(myreq, 1);
        return i;
};

int CMdSpi::reqUserLogin(dict req, int nRequestID)
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
        int i = userapi->ReqUserLogin(&myreq, nRequestID);
        return i;
};

int CMdSpi::reqUserLogout(dict req, int nRequestID)
{
        CThostFtdcUserLogoutField myreq = CThostFtdcUserLogoutField();
        memset(&myreq, 0, sizeof(myreq));
        cout << "���͹�˾���� TThostFtdcBrokerIDType:" << endl;
        strcpy(myreq.BrokerID, broker_id.c_str());
        cout << "�û����� TThostFtdcUserIDType:" << endl;
        strcpy(myreq.UserID, user_id.c_str());
        int i = userapi->ReqUserLogout(&myreq, nRequestID);
        return i;
};

//-------------------------------------------------------------------------------------
//API�ص�����
//-------------------------------------------------------------------------------------

///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
void CMdSpi::OnFrontConnected()
{
        cerr << "--->>> " << __FUNCTION__ << endl;
        // user login request
        ReqUserLogin();
}

///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
///@param nReason ����ԭ��
///        0x1001 �����ʧ��
///        0x1002 ����дʧ��
///        0x2001 ����������ʱ
///        0x2002 ��������ʧ��
///        0x2003 �յ�������
void CMdSpi::OnFrontDisconnected(int nReason)
{
        cerr << "--->>> " << __FUNCTION__ << endl;
        cerr << "--->>> Reason = " << nReason << endl;
        // publisher.send("OnFrontDisconnected");
}

///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
void CMdSpi::OnHeartBeatWarning(int nTimeLapse)
{
        cerr << "--->>> " << __FUNCTION__ << endl;
        cerr << "--->>> nTimerLapse = " << nTimeLapse << endl;
}

///��¼������Ӧ
void CMdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField* pRspUserLogin, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
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

                // front_id = pRspUserLogin->FrontID;
                // session_id = pRspUserLogin->SessionID;
                // login_status = true;
                // order_ref = pRspUserLogin->MaxOrderRef;
        }
        // SubscribeMarketData();
}

///�ǳ�������Ӧ
void CMdSpi::OnRspUserLogout(CThostFtdcUserLogoutField* pUserLogout, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
        cout << "--->>> " << __FUNCTION__ << endl;
        if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
                cout << "���͹�˾���� TThostFtdcBrokerIDType:" << pUserLogout->BrokerID << endl;
                cout << "�û����� TThostFtdcUserIDType:" << pUserLogout->UserID << endl;
        }
}

///����Ӧ��
void CMdSpi::OnRspError(CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
        cerr << "--->>> " << __FUNCTION__ << endl;
}

///��������Ӧ��
void CMdSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
        cout << "--->>> " << __FUNCTION__ << endl;
        if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
            cout << "SubscribeMarketData success!" << endl;
        }

}

///ȡ����������Ӧ��
void CMdSpi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
        cout << "--->>> " << __FUNCTION__ << endl;
        if (bIsLast && !IsErrorRspInfo(pRspInfo)) {
            cout << "unSubscribeMarketData success!" << endl;
        }
}

///����ѯ��Ӧ��
void CMdSpi::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
}
///ȡ������ѯ��Ӧ��
void CMdSpi::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField* pSpecificInstrument, CThostFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
}

///�������֪ͨ
void CMdSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField* pDepthMarketData)
{
        if (pDepthMarketData == NULL) {
                cout << "p is null ,no data" << endl;
                return;
        }
        ctp::TDF_FUTURE_DATA td;
        // TODO: ���ֶ�tdf��δʹ��
        // cerr << "ExchangeID=" << pDepthMarketData->ExchangeID << endl;
        // cerr << "ExchangeInstID=" << pDepthMarketData->ExchangeInstID << endl;
        // cerr << "UpdateTime=" << pDepthMarketData->UpdateTime << endl;

        td.set_szcode(pDepthMarketData->InstrumentID);                //ԭʼCode
        td.set_nactionday(pDepthMarketData->ActionDay);               //ҵ������(��Ȼ��)
        td.set_ntradingday(pDepthMarketData->TradingDay);             //������
        td.set_ntime(pDepthMarketData->UpdateMillisec);               //ʱ��(HHMMSSmmm)
        td.set_ipreopeninterest(pDepthMarketData->PreOpenInterest);   //��ֲ�
        td.set_npreclose(pDepthMarketData->PreClosePrice);            //�����̼�
        td.set_npresettleprice(pDepthMarketData->PreSettlementPrice); //�����
        td.set_nopen(pDepthMarketData->OpenPrice);                    //���̼�
        td.set_nhigh(pDepthMarketData->HighestPrice);                 //��߼�
        td.set_nlow(pDepthMarketData->LowestPrice);                   //��ͼ�
        td.set_nmatch(pDepthMarketData->LastPrice);                   //���¼�
        td.set_ivolume(pDepthMarketData->Volume);                     //�ɽ�����
        td.set_iturnover(pDepthMarketData->Turnover);                 //�ɽ��ܽ��
        td.set_iopeninterest(pDepthMarketData->OpenInterest);         //�ֲ�����
        td.set_nclose(pDepthMarketData->ClosePrice);                  //������
        td.set_nsettleprice(pDepthMarketData->SettlementPrice);       //�����
        td.set_nhighlimited(pDepthMarketData->UpperLimitPrice);       //��ͣ��
        td.set_nlowlimited(pDepthMarketData->LowerLimitPrice);        //��ͣ��
        td.set_npredelta(pDepthMarketData->PreDelta);                 //����ʵ��
        td.set_ncurrdelta(pDepthMarketData->CurrDelta);               //����ʵ��

        td.add_naskprice(pDepthMarketData->AskPrice1); //������
        td.add_naskprice(pDepthMarketData->AskPrice2); //������
        td.add_naskprice(pDepthMarketData->AskPrice3); //������
        td.add_naskprice(pDepthMarketData->AskPrice4); //������
        td.add_naskprice(pDepthMarketData->AskPrice5); //������

        td.add_naskvol(pDepthMarketData->AskVolume1); //������
        td.add_naskvol(pDepthMarketData->AskVolume2); //������
        td.add_naskvol(pDepthMarketData->AskVolume3); //������
        td.add_naskvol(pDepthMarketData->AskVolume4); //������
        td.add_naskvol(pDepthMarketData->AskVolume5); //������

        td.add_nbidprice(pDepthMarketData->BidPrice1); //�����
        td.add_nbidprice(pDepthMarketData->BidPrice2); //�����
        td.add_nbidprice(pDepthMarketData->BidPrice3); //�����
        td.add_nbidprice(pDepthMarketData->BidPrice4); //�����
        td.add_nbidprice(pDepthMarketData->BidPrice5); //�����

        td.add_nbidvol(pDepthMarketData->BidVolume1);     //������
        td.add_nbidvol(pDepthMarketData->BidVolume2);     //������
        td.add_nbidvol(pDepthMarketData->BidVolume3);     //������
        td.add_nbidvol(pDepthMarketData->BidVolume4);     //������
        td.add_nbidvol(pDepthMarketData->BidVolume5);     //������
        td.set_navgprice(pDepthMarketData->AveragePrice); //֣�����ڻ�����

        //TODO: �ֶ�ctp������û��
        td.set_szwindcode("");   //600001.SH
        td.set_nauctionprice(0); //�������жϲο���
        td.set_nauctionqty(0);   //�������жϼ��Ͼ�������ƥ����
        td.set_nstatus(0);       //״̬

        auto msg_size = td.ByteSize();
        zmq::message_t message(msg_size);
        // td.SerializerToString(message.data(),msg_size);
        td.SerializeToArray(message.data(), msg_size);
        publisher.send(message);
}

///ѯ��֪ͨ
void CMdSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* pForQuoteRsp) { }

