# -*- coding: utf-8 -*-
"""
Created on Thu Jul  5 15:00:18 2018

@author: TS
"""
    
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
#    socket.connect("tcp://localhost:5529")
    socket.connect("tcp://172.18.32.102:5529")
    
#    print("Sending request %s ..." % req)
    socket.send_json(req)
    #  Get the reply.
    message = socket.recv_json()
#    print("Success: Got mseeage ...")
    return pd.read_json(message, orient='records')

if __name__ == "__main__":
    
    start_time = time.time()
    
    for i in range(100):
        df = get_hist_data('000002.SZ', '2018060120180705', '1d', 'pre')
#        time.sleep(0.01)
        
    end_time = time.time()
    print("time cost %.5f" % (end_time - start_time))
    
#socket.send_string(req)
