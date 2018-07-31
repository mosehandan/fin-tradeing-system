#include <iostream>
#include <hiredis/hiredis.h>
#include "ZmqServer.h"

using namespace std;

int main (int argc, char *argv[])
{
	zmq::context_t context (1);
	std::cout << "Collecting data from real data server..." << std::endl;

	zmq::socket_t subscriber (context, ZMQ_SUB);
	subscriber.setsockopt(ZMQ_SUBSCRIBE, "", 0);
	subscriber.connect("tcp://localhost:5520");

    redisContext* redis = redisConnect("127.0.0.1", 6379);
    if ( NULL == redis || redis->err)
    {       // redis为NULL与redis->err是两种不同的错误，若redis->err为true，可使用redis->errstr查看错误信息
        redisFree(redis);
        printf("Connect to redisServer faile\n");
        return -1;
    }
    printf("Connect to redisServer Success\n");

	while(1){
		zmq::message_t message;
		subscriber.recv(&message);

		ctp::TDF_FUTURE_DATA td;

		td.ParseFromArray(message.data(),message.size());

        count = count + 1;

        string command{"set "};
        command += td.szcode() + "|tick|" + \
        td.tradingday() + "|" + \
        td.updatetime() + "|" + \
        std::to_string(td.time());

        command += " "; 
        command += static_cast<char*>(message.data());

        // const char* command1 = "set stest1 value1";
        // string command = "set " + key + " " + message;
        // redisReply* reply = (redisReply*)redisCommand(redis,"set %s %s",key,message.data()); // 执行命令，结果强转成redisReply*类型
        redisReply* reply = (redisReply*)redisCommand(redis,command.c_str()); // 执行命令，结果强转成redisReply*类型
        if (NULL == reply) {
                printf("Execut command1 failure\n");
                redisFree(redis); // 命令执行失败，释放内存
                return -1;
        }
        if (!(reply->type == REDIS_REPLY_STATUS && strcasecmp(reply->str, "OK") == 0)) { // 判断命令执行的返回值
                printf("Failed to execute command");
                freeReplyObject(reply);
                redisFree(redis);
                return -1;
        }
        freeReplyObject(reply);
        // printf("Succeed to execute command");
        if (count > 10){
            // cout << command << endl;
            cout << static_cast<char*>(message.data()) << endl;
            // cout << "szcode:" << td.szcode() << endl;
            // cout << "ntime:" << td.time() << endl;
            // cout << "open:" << td.open() << endl;
            // cout << "high:" << td.high() << endl;
            // cout << "close:" << td.last() << endl;

            count = 0;
        }
        }
	google::protobuf::ShutdownProtobufLibrary();

}
