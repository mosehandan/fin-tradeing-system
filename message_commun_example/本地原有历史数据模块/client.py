#!/usr/bin/python
#-*-coding:utf-8-*-    
import zmq
import time
from random import randrange , choice
import json
import pandas as pd
'''
client 调用说明
	
  	参数格式如下：

	    code = ['000001.SZ', '000001.SZ']
	    	名称：股票列表
	    	类型：list 
			可选范围：所有股票

	    time_zone = ['20180601', '20180704']
	    	名称：时间区间
	    	类型：list 
			可选范围： 日线数据 从91开始，基本上上市到现在都有
					  分钟数据 2016年1月1日到2018年4月1日
	    	
	    ktype = '1d'
	    	名称：数据级别
	    	类型：str
	    	可选范围： '1d' 日线
	    			  '1m' 分钟
	    			  后续考虑扩展3分钟，5分钟，30分钟，周线，月线等等
	    adj = 'pre'
	    	名称：复权
	    	类型：str
	    	可选范围： 'non' 不复权
	    			  'pre' 前复权
	    			  如果有需要可以增加后复权和定点复权 

	调用方法：

		定义好参数后，直接调用函数：
			
			dataframe = get_hist_data(code, time_zone, ktype, adj)
			返回结果为dataframe, 如果有多个股票，则会append到一个Frame中。

			示例：get_hist_data(['000001.SZ', '000002.SZ'], ['20180101','20180305'], '1m', 'pre')

PS 如调用远程主机102不存在，则本地自行启动ser.py文件，并修改端口到localhost:5529
'''
    
def get_hist_data(code, time_zone, ktype, adj):
#    code = ['000001.SZ', '000001.SZ']
#    time_zone = ['20180601', '20180704']
#    ktype = '1d'
#    adj = 'pre'
    req = {'code':code, 'time_zone':time_zone, 'ktype':ktype, 'adj':adj}
    
    req = json.dumps(req)
    
    context = zmq.Context()
    #  Socket to talk to server
    socket = context.socket(zmq.REQ)
    socket.connect("tcp://172.18.32.102:5529") # 远程主机
#    socket.connect("tcp://localhost:5529")	   # 本地主机
    
#    print("Sending request %s ..." % req)
    socket.send_json(req)
    #  Get the reply.
    message = socket.recv_json()
#    print("Success: Got mseeage ...")
    json_message = json.loads(message)
    
    df_message = pd.DataFrame()
    
    for key in json_message.keys():
#        print(key)
        if key != 'Error':
            temp_df = pd.DataFrame()
            temp_df = pd.DataFrame(json_message[key])
            temp_df['code'] = key
            df_message = df_message.append(temp_df)
        else:
            return df_message
        
    df_message = df_message.sort_values(by = ['code', 'datetime'])
#    return pd.read_json(message, orient='records')
    return df_message

if __name__ == "__main__":
    
    start_time = time.time()
    
    for i in range(3):
        df = get_hist_data(['000001.SZ', '000002.SZ'], ['20180101','20180305'], '1m', 'pre')
#        time.sleep(0.01)
        
    end_time = time.time()
    print("time cost %.5f" % (end_time - start_time))
    
#socket.send_string(req)
