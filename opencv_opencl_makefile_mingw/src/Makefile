#ref: 
#https://github.com/deweiwork/template_and_makefile/blob/master/Makefile

#Basic parameter for compile
CXX = g++
CXXFLGAS = -Wall -g -std=c++17
RM_CMD = rm -rf

#win64 conf

#Include path for SDKs
#OPENCV_HEADERS_PATH = C:/SDKs/opencv/4_1_1/build/include # Include path for opencv
#OPENCL_HEADERS_PATH = C:/SDKs/amd-APPSDK/3_0/include #Include path for opencl 

#Libs path for SDKs
#OPENCV_LIBS_PATH = C:/SDKs/opencv/4_1_1/build/x64/mingw/lib #Libs path for opencv
#OPENCL_LIBS_PATH = C:/SDKs/amd-APPSDK/3_0/lib/x86_64 #Libs path for opencl 

#Libs used in SDKs
#USED_OPENCV_LIBS_NAME = core highgui imgcodecs
#OPENCV_VERSION = 411
#LIBS_OPENCV = $(addsuffix ${OPENCV_VERSION}, $(addprefix opencv_, ${USED_OPENCV_LIBS_NAME}))

#LIBS_OPENCL = OpenCL

#Linux64 conf
OPENCV_HEADERS_PATH = /usr/include/opencv4
OPENCL_HEADERS_PATH = /usr/include
LIBS_OPENCL = OpenCL
USED_OPENCV_LIBS_NAME = core highgui imgcodecs
LIBS_OPENCV =  $(addprefix opencv_, ${USED_OPENCV_LIBS_NAME})

# Add flags of Libs and Include path for compiler parameter
INCLUDE_PATH = $(addprefix -I, ${OPENCV_HEADERS_PATH} ${OPENCL_HEADERS_PATH})
LIBS_PATH = $(addprefix -L, ${OPENCV_LIBS_PATH} ${OPENCL_LIBS_PATH})#if strings of (addprefix -L, strings) is null then cannot triggered addprefix.
LIBS = $(addprefix -l, ${LIBS_OPENCV} ${LIBS_OPENCL})



TARGET_EXEC_OUTPUT_NAME = test
CXX_SUFFIX = cc
OBJ_SUFFIX = o
EXEC_SRCS = test.cc
EXEC_OBJS = ${EXEC_SRCS:${CXX_SUFFIX}=${OBJ_SUFFIX}}

.PHONY: all
all: ${TARGET_EXEC_OUTPUT_NAME} 

${TARGET_EXEC_OUTPUT_NAME}: ${EXEC_OBJS} 
	${CXX} $^ ${LIBS_PATH} ${LIBS} -o $@ 
${EXEC_OBJS}: ${EXEC_SRCS}
	${CXX} ${CXXFLGAS} ${INCLUDE_PATH} -c $< 

#########################
#Check build envrioment#
#########################

.PHONY: check_gcc_version_GT_8
check_gcc_version_GT_8:
ifeq ($(shell expr `gcc -dumpversion | cut -f1 -d.` \>= 8), 1)
	@echo "gcc version matched"
else
	$(error "gcc version isn't matched (gcc_version >= 8)")
endif

.PHONY: check_gcc_target_x86_64
check_gcc_target_x86_64:
ifeq ($(shell gcc -dumpmachine | cut -f1 -d-), x86_64)
	@echo "gcc is x86_64 target"
else
	$(error "gcc isn't x86_64 target")
endif

#################
#clear procedure#
#################

.PHONY: clean
clean:
	${RM_CMD} \
	${EXEC_OBJS} \
	${TARGET_EXEC_OUTPUT_NAME}

################
#test procedure#
################

.PHONY: test_exec
test_exec:
	./${TARGET_EXEC_OUTPUT_NAME} ./t.png
