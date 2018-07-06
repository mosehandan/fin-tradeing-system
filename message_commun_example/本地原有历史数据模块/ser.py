#-*-coding:utf-8-*-
'''

仅限公司内部使用

'''

import time
import zmq
from random import randrange , choice
import json

import pandas as pd
import requests
import json
import numpy as np
from pymongo import MongoClient
import copy

import re
import sys
import time                                                               
import signal
import urllib.request
import redis
from datetime import datetime    


context = zmq.Context()
socket = context.socket(zmq.REP)
socket.bind("tcp://*:5529")


def get_code_list():
    conn = MongoClient('172.18.32.108', 27017)
    db = conn['raw_data_day_stock']
    stock_codes = sorted(db.collection_names())[:-1]
    return stock_codes

def get_data(code, time_zone, ktype, adj):

#    code = '000001.SZ'
#    time_zone = ['20180601', '20180704']
#    ktype = '1d'
#    adj = 'pre'
    
    if isinstance(code, str):
        url = "http://172.18.32.108/DataPort/get_k_data.php?code=" + code + \
            "&start_date=" + time_zone[0] + "&end_date=" + time_zone[1] \
            + "&ktype=" + ktype + "&priceadj=" + adj
        
        response = requests.get(url)
        if response:
            data = response.json()
            if data:
                return json.dumps(data)
            else:
                return 'Error'
            
#    code = ['000001.SZ','000002.SZ']
#    time_zone = ['20180601', '20180704']
#    ktype = '1d'
#    adj = 'pre'    
                
    if isinstance(code, list):
        url = "http://172.18.32.108/DataPort/get_list_data.php?code=" + ','.join(code) + \
            "&start_date=" + time_zone[0] + "&end_date=" + time_zone[1] \
            + "&ktype=" + ktype + "&priceadj=" + adj
        
        response = requests.get(url)
        if response:
            data = response.json()
            if data:
                return json.dumps(data)
            else:
                return 'Error'
        
        
def quit(signum, frame):
    print( 'stop fusion')
    sys.exit()      


if __name__ =="__main__":
    
    print('start game ')
    stk_list = get_code_list()

    signal.signal(signal.SIGINT, quit)                                
    signal.signal(signal.SIGTERM, quit)

    while True:
        #  Wait for next request from client
        message = json.loads(socket.recv_json())
        
        code = message['code']
        time_zone = message['time_zone']
        ktype = message['ktype']
        adj = message['adj']
        
        print("Received request: %s %s %s %s" % (code, time_zone, ktype, adj) )
        
        if set(code).issubset(stk_list):
            stk_data = get_data(code, time_zone, ktype, adj)
            if stk_data != 'Error':
                print('reply data for %s' % code)
                socket.send_json("%s" % stk_data )
            else:
                print('no data for %s' % code)
        else:
            socket.send_json(json.dumps({'Error':'incorrect code %s ' % code}))
        

















