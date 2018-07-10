#include "TraderSpi.h"
// #include "ctp.pb.h"
// #include "zhelpers.hpp"

Document d;
// zmq::context_t context(1);
// zmq::socket_t reply(context, ZMQ_REP);
// zmq::socket_t publisher(context, ZMQ_PUB);

int main(int argc, char* argv[])
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    if (argc != 2) {
	cerr << "Usage: " << argv[0] << " ctp_config_file" << endl;
	return -1;
    }

    string config_path = argv[1];
    config_path = "./config/" + config_path;
    std::cout << config_path.c_str() << std::endl;
    //if ( !read_json("ctp_zhongxin.json",d) ){
    if (!read_json(config_path.c_str(), d)) {
	cout << "the config.json file parse error!" << endl;
	return 0;
    }

    logger::init(argv[0]);
    // publisher.bind("tcp://*:5541");
    // reply.bind("tcp://*:5531");

    CTraderSpi* ctraderapi = new CTraderSpi();
    ctraderapi->load_config(d);
    ctraderapi->connect();
}

