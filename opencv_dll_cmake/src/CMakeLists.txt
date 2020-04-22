cmake_minimum_required(VERSION 3.13)

set(project_name    dol_core)
project(${project_name})

set(dol_top_src_dir             ${CMAKE_SOURCE_DIR})
set(dol_headers_dir             "${CMAKE_SOURCE_DIR}/opencv_lib/include")
set(dol_top_resource_dir        "${CMAKE_SOURCE_DIR}/../resource")
set(dol_now_version             "0.3")


add_subdirectory(opencv_lib)
add_subdirectory(opencv_use)
add_subdirectory(opencv_use_CAPI)

if((CMAKE_BUILD_TYPE equal "RELEASE") AND (UNIX))
    
    #install( #install target (only unix), CMAKE_INSTALL_PREFIX is recommended in here
        #TARGETS     opencv_lib opencv_use opencv_use_CAPI

        #RUNTIME     DESTINATION "/usr/bin"
        #LIBRARY     DESTINATION "/usr/lib"
        #ARCHIVE     DESTINATION "/usr/lib"

        #PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                    #GROUP_EXECUTE GROUP_READ
    #)
    
    install( #install resource (only unix)
        DIRECTORY ${dol_top_resource_dir} DESTINATION "/usr/share"

        FILES_MATCHING 
        PATTERN     "*.jpeg" 
        PATTERN     "*.txt"
        PATTERN     "CMakeLists.txt" EXCLUDE
        
        PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
                    GROUP_EXECUTE GROUP_READ
    )
    install( #install headers (only unix)
        DIRECTORY ${dol_headers_dir} DESTINATION "/usr/include"
        FILES_MATCHING
        PATTERN     "*.h" 
        PATTERN     "*.hpp"

        PERMISSIONS     OWNER_EXECUTE OWNER_WRITE OWNER_READ
                        GROUP_EXECUTE GROUP_READ
    )
endif()
