cmake_minimum_required(VERSION  3.8)
set(PROJECT_NAME testCVCL)
project(${PROJECT_NAME})

#set pkg root dir for specific OS
if (WIN32)
  set (
    OpenCV_DIR "C:/SDKs/opencv/4_1_1/build" 
	CACHE PATH "OpenCV Root DIR"
  )
  set (
	OpenCL_DIR "C:/SDKs/ocl-icd" 
	CACHE PATH "OpenCL Root DIR"
  )
else ()
endif()

#find pkg
if (WIN32)
  find_package(OpenCL 2 REQUIRED CONFIG)
else ()
  find_package(OpenCL 2 REQUIRED)
endif()
find_package(OpenCV 4 REQUIRED) 


include_directories (
	${OpenCV_INCLUDE_DIR}
	${OpenCL_INCLUDE_DIR}
)

add_executable (
	${PROJECT_NAME} 
	test.cc
)

target_link_libraries (
	${PROJECT_NAME} 
	${OpenCV_LIBRARIES} 
	${OpenCL_LIBRARIES}
 )