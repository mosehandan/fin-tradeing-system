#include "TraderSpi.h"
#include "ZmqServer.h"

int main(int argc, char* argv[])
{
        GOOGLE_PROTOBUF_VERIFY_VERSION;

        if (argc != 2) {
                std::cerr << "Usage: " << argv[0] << " ctp_config_file" << std::endl;
                return -1;
        }

        std::string config_path = argv[1];
        // std::cout << config_path.c_str() << std::endl;
        if (!read_json("ctp_zhongxin.json", d)) {
                std::cout << "the config.json file parse error!" << std::endl;
                return 0;
        }

        logger::init(argv[0]);
        // publisher.bind("tcp://*:5541");
        // reply.bind("tcp://*:5531");

        CTraderSpi* ctraderspi = new CTraderSpi();
        ctraderspi->load_config(d);
        ctraderspi->connect();
}
