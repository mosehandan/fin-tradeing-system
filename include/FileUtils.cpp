#include "FileUtils.h"
#include <string>

using namespace std;
using namespace rapidjson;

Document d;

bool read_json(const char* file_name, Document& d)
{
        FILE* fp = fopen(file_name, "r"); // 非 Windows 平台使用 "r
        if (!fp) {
                return false;
        }
        char readBuffer[65536];
        FileReadStream is(fp, readBuffer, sizeof(readBuffer));
        d.ParseStream(is);
        fclose(fp);

        return true;
}

void logger::init(const char* name)
{
        string home = "./log/glog/";
        google::InitGoogleLogging(name);
        string info_log = home + "_info_";
        google::SetLogDestination(google::INFO, info_log.c_str());
        string warning_log = home + "_warning_";
        google::SetLogDestination(google::WARNING, warning_log.c_str());
        string error_log = home + "_error_";
        google::SetLogDestination(google::ERROR, error_log.c_str());
        string fatal_log = home + "_fatal_";
        google::SetLogDestination(google::FATAL, fatal_log.c_str());

        // FLAGS_logbuflevel = 1;
        // FLAGS_alsologtostderr = true;
        // FLAGS_logtostderr = true;
        //
        // FLAGS_minloglevel = 1;
        // FLAGS_v = 1;
        // FLAGS_colorlogtostderr = true;
        // FLAGS_logbufsecs;
}
