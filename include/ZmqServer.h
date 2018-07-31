#include "ctp.pb.h"
#include "zhelpers.hpp"

extern zmq::context_t context;
extern zmq::socket_t publisher;

void do_publish(const guosen::ProtoMsg& proto_message);
