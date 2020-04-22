cmake_minimum_required(VERSION 3.8)

set(project_name                        opencv_use)
project(${project_name})

LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModulesForDol/functions")
INCLUDE(dolChkBuildEnv)
dolChkIf64()
dolChkCompilerVerGeneral()

set(src_files                           opencv_use.cc) 

set(output_bin_dir                      "${CMAKE_BINARY_DIR}/output/bin") #not use project_BINARY_DIR
set(output_lib_dir                      "${CMAKE_BINARY_DIR}/output/lib") #not use project_BINARY_DIR

set(libs_name_i_ues                     "opencv_lib")
set(libs_name_i_ues_debug               "${libs_name_i_ues}")
set(libs_name_i_ues_RELEASE             "${libs_name_i_ues}")

add_executable(${project_name}    ${src_files})

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
        
        VERSION                             ${dol_now_version}
)

target_include_directories(
    ${project_name} 
    PRIVATE
        "${CMAKE_SOURCE_DIR}/${libs_name_i_ues}/include"
)

target_link_directories(
    ${project_name} 
    PRIVATE
        ${opencv_root_libs_dir}
)
target_link_libraries(
    ${project_name}
        debug       ${libs_name_i_ues_debug} #debug muse be lower case
        optimized   ${libs_name_i_ues_RELEASE} #release muse be lower case
)


#ref : pkg-config vs find-package
#https://blog.csdn.net/DuinoDu/article/details/51536777
