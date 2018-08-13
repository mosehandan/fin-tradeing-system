#include "ctp.pb.h"
#include <iostream>
#include "zhelpers.hpp"

using namespace std;


int main (int argc, char *argv[])
{
	zmq::context_t context (1);
	//  Socket to talk to server
	std::cout << "Collecting data from real data server...\n" << std::endl;

	zmq::socket_t subscriber (context, ZMQ_SUB);
	subscriber.setsockopt(ZMQ_SUBSCRIBE, "", 0);
	subscriber.connect("tcp://localhost:5520");

	// subscriber.connect("tcp://localhost:5558");

	int count = 0;

	while(1){
		zmq::message_t message;
		subscriber.recv(&message);

		ctp::TDF_FUTURE_DATA td;

		td.ParseFromArray(message.data(),message.size());

		count = count + 1;

		if (count > 10){
			cout << "szcode:" << td.szcode() << endl;
			cout << "ntime:" << td.ntime() << endl;
			cout << "open:" << td.nopen() << endl;
			cout << "high:" << td.nhigh() << endl;
			cout << "close:" << td.nmatch() << endl;

			count = 0;
		}

		// // cout << "what i get is :" << static_cast<char*>(message.data()) << endl;
	}
	google::protobuf::ShutdownProtobufLibrary();

}
