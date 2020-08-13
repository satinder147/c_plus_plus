import logging
import time
import sys


# Message types
# logging.DEBUG detailed loging nothing goes wrong, but collect it
# logging.INFO  like debug, but less detailed output 


# logging.WARNING Use happens that should not have happend, not fault of user
# logging.ERROR   When something goes wrong, but doesn't break the program
# logging.CRITICAL  Stops the program

# The last three are directed to screen by default whereas the first two are not.
# We can change that setting
# All the message types are numbers from 10-50


# Now we are using the default root logger object, we can also define our own logging objects. 
# Also we can define handles where are output will be directed.

# logging.basicConfig(level = logging.DEBUG)
# while 1:
#     time.sleep(1)
#     logging.error("error")
#     logging.critical("critical")
#     logging.debug("debug")
#     logging.info("info")
#     logging.warning("warning")
#     break

#OUTPUT = msg_type:root/logger_name:msg

print("------------------")
logger = logging.getLogger(name ="satinder") # if name = root, we get the default root logger.
streamhandler = logging.StreamHandler(sys.stdout)
streamhandler.setLevel(logging.WARNING)
logger.addHandler(streamhandler)
# we can replace all the logging calls by logger.

logger.info("info")
logger.warning("warning")
logger.critical("critical")