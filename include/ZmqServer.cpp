#include "ZmqServer.h"
// #include <unistd.h>

zmq::context_t context(1);
zmq::socket_t publisher(context, ZMQ_PUB);

void do_publish(const guosen::msg::ProtoMsg& proto_message)
{
        auto msg_size = proto_message.ByteSize();
        zmq::message_t message(msg_size);
        proto_message.SerializeToArray(message.data(), msg_size);
        // sleep(1);
        publisher.send(std::move(message));
}

void do_subscribe(){

}
