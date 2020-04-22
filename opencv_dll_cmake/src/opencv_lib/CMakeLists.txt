cmake_minimum_required(VERSION 3.8)

set(project_name    opencv_lib)
project(${project_name})

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModulesForDol/ConfigDependencies")
include(dolConfigDependencyOpencv)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModulesForDol/functions")
include(dolChkBuildEnv)
dolChkIf64()
dolChkCompilerVerGeneral()

set(src_files                                    opencv_lib.cc) 

set(CMAKE_DEBUG_POSTFIX                         -d) #mark -d if build mode is debug

set(CMAKE_POSITION_INDEPENDENT_CODE              ON) #-fPIC

set (output_bin_dir                             "${CMAKE_BINARY_DIR}/output/bin") #not use project_BINARY_DIR
set (output_lib_dir                             "${CMAKE_BINARY_DIR}/output/lib") #not use project_BINARY_DIR

add_library(${project_name} SHARED ${src_files})

set_target_properties( 
    ${project_name} 
    PROPERTIES
        CXX_STANDARD                        17
        CXX_STANDARD_REQUIRED               ON
        CXX_EXTENSIONS                      OFF

        ARCHIVE_OUTPUT_DIRECTORY_DEBUG      ${output_lib_dir}
        LIBRARY_OUTPUT_DIRECTORY_DEBUG      ${output_lib_dir}
        RUNTIME_OUTPUT_DIRECTORY_DEBUG      ${output_bin_dir}
        ARCHIVE_OUTPUT_DIRECTORY_RELEASE    ${output_lib_dir}
        LIBRARY_OUTPUT_DIRECTORY_RELEASE    ${output_lib_dir}
        RUNTIME_OUTPUT_DIRECTORY_RELEASE    ${output_bin_dir}   
        
        PREFIX                              "lib"
        OUTPUT_NAME                         ${project_name} 

        VERSION                             ${dol_now_version}
)

target_include_directories(
    ${project_name} 
    PRIVATE
        "${project_SOURCE_DIR}/include"
        ${opencv_root_include_dir_full_path} #form file dolConfigDependencyOpencv.cmake
)
target_link_directories(
    ${project_name} 
    PRIVATE
        ${opencv_root_libs_dir} #form file dolConfigDependencyOpencv.cmake
)
target_link_libraries(
    ${project_name}
        debug       ${opencv_root_libs_used_debug} #debug muse be lower case, #form file dolConfigDependencyOpencv.cmake
        optimized   ${opencv_root_libs_used_release} #release muse be lower case, #form file dolConfigDependencyOpencv.cmake
)

#ref : pkg-config vs find-package
#https://blog.csdn.net/DuinoDu/article/details/51536777
