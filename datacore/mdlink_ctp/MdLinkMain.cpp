
/***********************************************************************

Copyright 2017 quantOS-org

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at:

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

***********************************************************************/
#include "../public/MapTables.h"
#include "../public/MdServer.h"
#include "CtpMdServer.h"
#include "../base/Calendar.h"
#include "../base/Init.h"
#include "../base/Logger.h"
#include "../base/StringUtil.h"
#include "../base/TimeUtil.h"
#include "../config/IniApi.h"
#include "../config/SysConfig.h"
#include "../protocol/cpp/md.pb.h"
#include <chrono>
#include <cstring>
#include <fstream>
#include <getopt.h>
#include <iomanip>
#include <json/json.h>
#include <memory>
#include <mutex>
#include <set>
#include <thread>
#include <unistd.h>
#include <unordered_map>

using namespace std;
using namespace jzs;
using namespace jzs::msg;
using namespace jzs::msg::md;
using namespace jzs::msgbus;

int main(int argc, char* argv[])
{
    string mdid;
    if (argc == 2) {
	mdid = string(argv[1]);
	init(argv[1]);
    } else {
	init(argv[0]);
	LOG(ERROR) << "Wrong number of arguments given!" << endl;
	return -1;
    }

    MdlinkCfg mdcfg;
    SysConfig::getMdlinkCfg(mdid, mdcfg);
    MdServer* svr = new CtpMdServer;
    if (!svr->init(mdcfg)) {
	return -1;
    }
    svr->StartMdlink();
    while (true) {
	this_thread::sleep_for(chrono::seconds(5));
	auto next_time = chrono::system_clock::now() + chrono::seconds(5);
	while (chrono::system_clock::now() < next_time)
	    this_thread::sleep_until(next_time);
	svr->ShowStatus();
    }
    return 0;
}

