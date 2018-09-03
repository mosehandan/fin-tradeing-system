#ifndef ZMQSERVER_H
#define ZMQSERVER_H

#include "ctpmessage.pb.h"
#include "guosen.pb.h"
#include "zhelpers.hpp"

extern zmq::context_t context;
extern zmq::socket_t publisher;

void do_publish(const guosen::msg::ProtoMsg& proto_message);

#endif
