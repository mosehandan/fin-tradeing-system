#!/usr/bin/python
#-*-coding:utf-8-*-    
import zmq
import time
from random import randrange , choice
import json
import pandas as pd
   
    
def get_hist_data(code, time_zone, ktype, adj):
#    code = '000001.SZ'
#    time_zone = ['20180601', '20180704']
#    ktype = '1d'
#    adj = 'pre'
    req = {'code':code, 'time_zone':time_zone, 'ktype':ktype, 'adj':adj}
    
    req = json.dumps(req)
    
    context = zmq.Context()
    #  Socket to talk to server
    socket = context.socket(zmq.REQ)
    socket.connect("tcp://localhost:5529")
#    socket.connect("tcp://172.18.32.102:5529")
    
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
