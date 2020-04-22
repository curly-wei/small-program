#set compiler properity to use
CXX = clang++
CXXFLAGS = -fPIC -Wall -g
LDFLAGS = -shared

#set rm command for "make clean"
RM_CMD = rm -rf

#Building target
TARGET_EXEC = main
TARGET_LIB = tmp

#input files(sources) for target
EXEC_SRCS = main.cc
LIB_SRCS = tmp.cc

#set suffix for cpp sourses and object files
C_SUFFIX = .c
CXX_SUFFIX = .cc
OBJ_SUFFIX = .o

EXEC_OBJS = ${EXEC_SRCS:${CXX_SUFFIX}=${OBJ_SUFFIX}}
LIB_OBJS = ${LIB_SRCS:${CXX_SUFFIX}=${OBJ_SUFFIX}}

TARGET_EXEC_OUTPUT = ${TARGET_EXEC}.out
TARGET_LIB_OUTPUT = ${TARGET_LIB}.so

#set builded unit which they need to be build
.PHONY: all
all: ${TARGET_LIB_OUTPUT} ${TARGET_EXEC_OUTPUT}

#Build .so lib
${TARGET_LIB_OUTPUT}: ${LIB_OBJS}
	${CXX} $^ ${LDFLAGS} -o $@
${LIB_OBJS}: ${LIB_SRCS}
	${CXX} ${CXXFLAGS} -c $< 

#Build exec
${TARGET_EXEC_OUTPUT}: ${EXEC_OBJS} ${TARGET_LIB_OUTPUT}
	${CXX} $^ -o $@
${EXEC_OBJS}: ${EXEC_SRCS}
	${CXX} ${CXXFLAGS} -c $< 

#$@: Name of Targer
#$^: All dependency of Targer
#$<: First dependency of Targer

#using command "make clean" clear .so and .out and .o files
.PHONY: clean
clean:
	${RM_CMD} \
	${EXEC_OBJS} ${LIB_OBJS} \
	${TARGET_EXEC_OUTPUT} ${TARGET_LIB_OUTPUT}

#quick test, command is "make test"
.PHONY: test
test:
	LD_LIBRARY_PATH=. ./${TARGET_EXEC_OUTPUT}