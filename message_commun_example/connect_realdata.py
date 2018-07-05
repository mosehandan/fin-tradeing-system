#
#   Weather update client
#   Connects SUB socket to tcp://localhost:5556
#   Collects weather updates and finds avg temp in zipcode
#

import sys
import zmq


#  Socket to talk to server
context = zmq.Context()
socket = context.socket(zmq.SUB)

socket.connect("tcp://localhost:5520")

# Subscribe to zipcode, default is NYC, 10001
#  zip_filter = sys.argv[1] if len(sys.argv) > 1 else "10001"

zip_filter = '601318.sh'
# Python 2 - ascii bytes to unicode str
if isinstance(zip_filter, bytes):
    zip_filter = zip_filter.decode('ascii')
socket.setsockopt_string(zmq.SUBSCRIBE, zip_filter)
socket.setsockopt_string(zmq.SUBSCRIBE, "002736.sz")

while( True ):
    temp_string = socket.recv_string()
    print("receive real data from port 5520 : %s" % temp_string)
