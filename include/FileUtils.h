#ifndef FILEUTILS_H
#define FILEUTILS_H

#include "rapidjson/document.h" // rapidjson's DOM-style API
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/prettywriter.h" // for stringify JSON
#include <glog/logging.h>
#include <rapidjson/writer.h>

// using namespace std;
using namespace rapidjson;

extern Document d;

bool read_json(const char* file_name, Document& d);

class logger {
    public:
        static void init(const char* name);
};

inline int char2int(const char& c) { return c - '0'; }

inline char int2char(const int& c) { return c + '0'; }

#endif
