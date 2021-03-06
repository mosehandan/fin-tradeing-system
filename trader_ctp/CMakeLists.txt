cmake_minimum_required(VERSION 2.8.4)

add_compile_options(-std=c++11)
find_library(LIB_TRADER_PATH thosttraderapi ../lib)
# find_library(LIBZMQ_PATH libzmq ../lib)
#
if(NOT LIB_TRADER_PATH)
        MESSAGE(FATAL_ERROR "thosttraderapi lib not found")
ENDIF(NOT LIB_TRADER_PATH)


include_directories(../include)
include_directories(../include/CtpApi)
include_directories(../include/rapidjson)
include_directories(../include/zmq)
include_directories(../include/protobuf)

link_directories(${PROJECT_SOURCE_DIR}/lib)
# add_executable(CtpTrader CtpTrader.cpp TraderSpi.cpp ../include/FileUtils.cpp ../include/protobuf/ctp.pb.cc)
add_executable(
        CtpTrader
        ../include/ZmqServer.cpp
        ../include/FileUtils.cpp
        ../include/protobuf/guosen.pb.cc
        ../include/protobuf/ctpmessage.pb.cc
        TraderSpi.cpp
        CtpTrader.cpp
        )
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# if you want to use link_directories, you should let add_executable after link_directories
# target_link_libraries(main thostmduserapi})
target_link_libraries(CtpTrader ${LIB_TRADER_PATH})
# target_link_libraries(CtpTrader thosttraderapi)

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
        # message(STATUS "current platform:linux")
        target_link_libraries(CtpTrader zmq)
        target_link_libraries(CtpTrader glog)
        target_link_libraries(CtpTrader protobuf)
endif(CMAKE_SYSTEM_NAME MATCHES "Linux")
