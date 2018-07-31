#include <iostream>
#include "ZmqServer.h"

using namespace std;

int main (int argc, char *argv[])
{
	zmq::context_t context (1);
	std::cout << "real data core is running ..." << std::endl;

	zmq::socket_t subscriber (context, ZMQ_SUB);
	subscriber.setsockopt(ZMQ_SUBSCRIBE, "", 0);
	subscriber.connect("tcp://localhost:5501");

	zmq::socket_t publisher (context, ZMQ_PUB);
	publisher.bind("tcp://*:5520");

	// subscriber.connect("tcp://localhost:5558");

	while(1){
		zmq::message_t message;
		subscriber.recv(&message);

        // std::cout << "receive data:" << message << std::endl;

		//TODO: receive data should judgment if use this data
		publisher.send(message);

	}

}
