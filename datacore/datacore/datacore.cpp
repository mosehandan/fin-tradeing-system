#include "ctp.pb.h"
#include <iostream>
#include "zhelpers.hpp" 

using namespace std;


int main (int argc, char *argv[])
{
	zmq::context_t context (1);
	//  Socket to talk to server
	std::cout << "Collecting data from server...\n" << std::endl;
	zmq::socket_t subscriber (context, ZMQ_SUB);
	subscriber.setsockopt(ZMQ_SUBSCRIBE, "", 0);

	subscriber.connect("tcp://localhost:5556");
	// subscriber.connect("tcp://localhost:5557");
	// subscriber.connect("tcp://localhost:5558");

	while(1){
		// zmq::message_t message;
		// subscriber.recv(&message);
		// tutorial::AddressBook address_book;
		// std::string msg_str(static_cast<char*>(message.data()), message.size());
		// address_book.ParseFromString(msg_str);

		zmq::message_t message;
		subscriber.recv(&message);
		ctp::TDF_FUTURE_DATA td;
		
		td.ParseFromArray(message.data(),message.size());
		
		cout << td.szcode << endl;	
		cout << td.ntime<< endl;	
		cout << td.nopen<< endl;	
		cout << td.nhigh<< endl;	
		// cout << "what i get is :" << static_cast<char*>(message.data()) << endl;
	}
	google::protobuf::ShutdownProtobufLibrary();

}
