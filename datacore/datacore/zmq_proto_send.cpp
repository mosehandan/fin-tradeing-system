#include "addressbook.pb.h"
#include <fstream>
#include <zmq.hpp>
#include <unistd.h>

using namespace std;
void PromptForAddress(tutorial::Person* person) {
	person->set_id(123);
	person->set_name("zhangkai");
	person->set_email("474918208@qq.com");
}

int main(int argc, char *argv[])
{
	// Verify that the version of the library that we linked against is
	// compatible with the version of the headers we compiled against.
	GOOGLE_PROTOBUF_VERIFY_VERSION;

	tutorial::AddressBook address_book;
	PromptForAddress(address_book.add_people());


	zmq::context_t context (1);
	zmq::socket_t publisher (context, ZMQ_PUB);
	publisher.bind("tcp://*:5556");

	// std::string msg_str;
	// address_book.SerializeToString(&msg_str);
	// address_book.SerializeToArray(request.data(),msg_str.size());
	auto msg_size = address_book.ByteSize();

	while (1) {
		// memcpy((void *)request.data(), msg_str.c_str(), msg_str.size());
		zmq::message_t request(msg_size);
		address_book.SerializeToArray(request.data(),msg_size);
		sleep(1);
		publisher.send(request);
	}
}
