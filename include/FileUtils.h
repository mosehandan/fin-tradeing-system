#include "rapidjson/document.h"     // rapidjson's DOM-style API
#include "rapidjson/prettywriter.h" // for stringify JSON
#include <rapidjson/writer.h>
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include <glog/logging.h>

// using namespace std;
using namespace rapidjson;

extern Document d;

bool read_json(const char *file_name,Document & d);

class logger
{
	public:
		static void init(const char *name);
};
