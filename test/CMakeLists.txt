cmake_minimum_required(VERSION 2.8.4)

add_compile_options(-std=c++11)

include_directories(../include)
include_directories(../include/CtpApi)
include_directories(../include/rapidjson)
include_directories(../include/zmq)
include_directories(../include/protobuf)

link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(TestMdCore TestRealData.cpp ../include/protobuf/ctp.pb.cc)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# if you want to use link_directories, you should let add_executable after link_directories
# target_link_libraries(main thostmduserapi})

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
	target_link_libraries(TestMdCore zmq)
	# target_link_libraries(main glog)
	target_link_libraries(TestMdCore protobuf)
	target_link_libraries(TestMdCore hiredis)
endif(CMAKE_SYSTEM_NAME MATCHES "Linux")
# target_link_libraries(main ${LIBZMQ_PATH})
# target_link_libraries(main ${LIBPROTOBUF_PATH})
