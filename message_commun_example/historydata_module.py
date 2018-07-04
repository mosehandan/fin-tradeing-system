#
#   Hello World server in Python
#   Binds REP socket to tcp://*:5555
#   Expects b"Hello" from client, replies with b"World"
#

import time
import zmq
from random import randrange , choice

context = zmq.Context()
socket = context.socket(zmq.REP)
socket.bind("tcp://*:5529")

stk_list = ['000001.sz','002736.sz','601318.sh','601988.sh']

while True:
    #  Wait for next request from client
    message = socket.recv_string()
    print("Received request: %s" % message)

    #  做一些模块的工作,返回数据
    if message in stk_list :
        close = randrange(10, 100)
        socket.send_string("%s %i" % (message, close ) )
    else:
        socket.send_string("no data for %s" % message )
