#include "MdSpi.h"
#include "ZmqServer.h"
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
        GOOGLE_PROTOBUF_VERIFY_VERSION;

        if (argc != 2) {
                cerr << "Usage: " << argv[0] << " ctp_config_file" << endl;
                return -1;
        }

        std::string config_path = argv[1];
        config_path = "./config/" + config_path;

        if (!read_json(config_path.c_str(), d)) {
                cout << "the config.json file parse error!" << endl;
                return 0;
        }

        logger::init(argv[0]);
        std::string addr{ "tcp://*:" };
        addr += d["port"].GetString();
        cout << addr.c_str();
        publisher.bind(addr.c_str());

        CMdSpi* cmdspi = new CMdSpi();
        cmdspi->load_config(d);
        cmdspi->connect();
}
