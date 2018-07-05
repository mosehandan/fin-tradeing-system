#
#   Hello World client in Python
#   Connects REQ socket to tcp://localhost:5555
#   Sends "Hello" to server, expects "World" back
#

import zmq
import time
from random import randrange , choice
import threading

def do_requests():
    '''
    请求函数 
    '''

    while(True) :
        print("Sending request: hello strategy")
        req_socket.send_string("hello strategy")

        #  Get the reply.
        message = req_socket.recv_string()
        print("receive real data from port 5569 : %s" % message)

        time.sleep( 3 )


def do_subscribe():
    '''
    得到推送消息
    '''
    while(True):
        temp_string = sub_socket.recv_string()
        print("receive real data from port 5570 : %s" % temp_string)

context = zmq.Context()

req_socket = context.socket(zmq.REQ)
req_socket.connect("tcp://localhost:5569")

sub_socket = context.socket(zmq.SUB)
sub_socket.connect("tcp://localhost:5570")
sub_socket.setsockopt_string(zmq.SUBSCRIBE, "")  # 订阅所有的消息

t_list = []
t1 = threading.Thread( target = do_requests , name = 'do_requests')
t_list.append(t1)
t2 = threading.Thread( target = do_subscribe, name = 'do_subscribe')
t_list.append(t2)

if __name__ == '__main__':
    
    for t in t_list:
        t.start()

    t.join()
