#include "ZmqServer.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
        zmq::context_t context(1);
        //  Socket to talk to server
        std::cout << "Collecting data from real data server..."
                  << std::endl;

        zmq::socket_t subscriber(context, ZMQ_SUB);
        subscriber.setsockopt(ZMQ_SUBSCRIBE, "", 0);
        subscriber.connect("tcp://localhost:5520");

        // subscriber.connect("tcp://localhost:5558");

        while (1) {
                zmq::message_t message;
                subscriber.recv(&message);

                guosen::ProtoMsg proto_msg;
                proto_msg.ParseFromArray(message.data(), message.size());

                guosen::MsgType msg_type = proto_msg.head();

                switch (proto_msg.head()) {
                case guosen::MsgType::CTP_RTN_CONNECT: {
                        guosen::CtpRtnConnect body_msg;
                        body_msg.ParseFromString(proto_msg.body());
                        cout << "status:" << body_msg.status() << endl;
                        cout << "nreason:" << body_msg.nreason() << endl;
                        break;
                }

                case guosen::MsgType::CTP_RTN_TICK: {
                        guosen::CtpRtnTick body_msg;
                        body_msg.ParseFromString(proto_msg.body());
                        cout << "time:" << body_msg.updatetime() << endl;
                        cout << "open:" << body_msg.openprice() << endl;
                        cout << "close:" << body_msg.lastprice() << endl;
                        break;
                }

                case guosen::MsgType::CTP_RSP_LOGIN: {
                        guosen::CtpRspLogin body_msg;
                        body_msg.ParseFromString(proto_msg.body());
                        cout << "brokerid:" << body_msg.brokerid() << endl;
                        cout << "userid:" << body_msg.userid() << endl;
                        break;
                }
                }
        }
        google::protobuf::ShutdownProtobufLibrary();
}
