#
#   Weather update server
#   Binds PUB socket to tcp://*:5556
#   Publishes random weather updates
#

import zmq
from random import randrange , choice
import time


context = zmq.Context()
socket = context.socket(zmq.PUB)
socket.bind("tcp://*:5520")

stk_list = ['000001.sz','002736.sz','601318.sh','601988.sh']

while True:
    stk_code = choice(stk_list)
    close = randrange(10, 100)

    socket.send_string("%s %i" % (stk_code, close ) )

    time.sleep( 3 )
