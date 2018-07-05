
#
#   Hello World client in Python
#   Connects REQ socket to tcp://localhost:5555
#   Sends "Hello" to server, expects "World" back
#

import zmq
import time
from random import randrange , choice

context = zmq.Context()

#  Socket to talk to server
socket = context.socket(zmq.REQ)
socket.connect("tcp://localhost:5579")

stk_list = ['000001.sz','002736.sz','601318.sh','601988.sh']

while(True) :
    stk_code = choice(stk_list)
    print("Sending request %s ..." % stk_code)
    socket.send_string(stk_code)

    #  Get the reply.
    message = socket.recv_string()
    print("receive data from port 5579 : %s" % message)

    time.sleep( 3 )
