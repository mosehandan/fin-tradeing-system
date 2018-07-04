
#
#   Weather update server
#   Binds PUB socket to tcp://*:5556
#   Publishes random weather updates
#

import zmq
from random import randrange , choice
import time
import threading

def do_publish():
    '''
    推送成交回报
    '''
    while True:

        pub_socket.send_string("I am alive!" )

        time.sleep( 3 )

def do_reply():
    '''
    应答函数
    '''
    while True:
        message = rep_socket.recv_string()
        print("Received request: %s" % message)

        #  做一些模块的工作,返回数据
        rep_socket.send_string("所有策略当前状况为...")


context = zmq.Context()
pub_socket = context.socket(zmq.PUB)
pub_socket.bind("tcp://*:5570")
rep_socket = context.socket(zmq.REP)
rep_socket.bind("tcp://*:5569")


t_list = []
t1 = threading.Thread( target = do_publish , name = 'do_publish')
t_list.append(t1)
t2 = threading.Thread( target = do_reply , name = 'do_reply')
t_list.append(t2)


if __name__ == '__main__':

    for t in t_list:
        t.start()

    t.join()
