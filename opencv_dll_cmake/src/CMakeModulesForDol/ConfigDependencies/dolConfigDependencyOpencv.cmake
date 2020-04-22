#set options that external side can modify
set(opencv_include_dir "" CACHE STRING "Include directiry for OpenCV")#default as empty. string cannot use option
set(opencv_libs_dir "" CACHE STRING "Libs directiry for OpenCV on the debug mode or release mode")#default as empty. string cannot use option
if(MSVC)
    set(opencv_ver_in_msvc "" CACHE STRING "opencv_worldxxx, or opencv_worldxxxd. Entry xxx(xxx is version(value) of OPENCV). Check your pattern in the libs directory of opencv")
endif()

## setting from option() or default
if ((NOT "${opencv_include_dir}" ) OR (NOT "${opencv_libs_dir}" ) OR (NOT "${opencv_ver_in_msvc}"))
    message("opencv_include_dir or opencv_libs_dir_DEBUG or opencv_libs_dir_RELEASE not be set!")
    message("You must all set if you don't want to use default settings")
    message("You have not set opencv_include_dir or opencv_libs_dir_DEBUG or opencv_libs_dir_RELEASE,")
    message("so use default settings")
    if(MSVC)
        set(opencv_root_dir                     "C:/SDKs/opencv/4_1_0/build")
        set(opencv_root_include_dir_full_path   "${opencv_root_dir}/include") #output to CMakeLists
        set(opencv_root_libs_dir                "${opencv_root_dir}/x64/vc15/lib")
        set(opencv_root_libs_name               "opencv_world410")
        set(opencv_root_libs_used_debug         "${opencv_root_libs_dir}/${opencv_root_libs_name}d.lib") #output to CMakeLists
        set(opencv_root_libs_used_release       "${opencv_root_libs_dir}/${opencv_root_libs_name}.lib") #output to CMakeLists

    elseif(UNIX)
        set(opencv_root_dir                     "/usr")
        set(opencv_root_include_dir_full_path   "${opencv_root_dir}/include/opencv4") #output to CMakeLists
        set(opencv_root_libs_dir                "${opencv_root_dir}/lib")
        set(opencv_root_libs_used_debug         "opencv_core" "opencv_imgproc" "opencv_imgcodecs" "opencv_highgui") #output to CMakeLists
        set(opencv_root_libs_used_release       "opencv_core" "opencv_imgproc" "opencv_imgcodecs" "opencv_highgui") #output to CMakeLists
    endif()
else()
    message("opencv_include_dir or opencv_libs_dir_DEBUG or opencv_libs_dir_RELEASE all be defined!")
    if(MSVC)
        set(opencv_root_include_dir_full_path   ${opencv_include_dir}) #output to CMakeLists
        set(opencv_root_libs_dir                ${opencv_libs_dir})
        set(opencv_root_libs_name               "opencv_world${opencv_ver_in_msvc}")
        set(opencv_root_libs_used_debug         "${opencv_root_libs_dir}/${opencv_root_libs_name}d.lib") #output to CMakeLists
        set(opencv_root_libs_used_release       "${opencv_root_libs_dir}/${opencv_root_libs_name}.lib") #output to CMakeLists

    elseif(UNIX)
        set(opencv_root_include_dir_full_path   ${opencv_include_dir}) #output to CMakeLists
        set(opencv_root_libs_dir                ${opencv_libs_dir})
        set(opencv_root_libs_used_debug         "opencv_core" "opencv_imgproc" "opencv_imgcodecs" "opencv_highgui") #output to CMakeLists
        set(opencv_root_libs_used_release       "opencv_core" "opencv_imgproc" "opencv_imgcodecs" "opencv_highgui") #output to CMakeLists
    endif()
endif()

#print result
message("OpenCV Include directories:")
message("\t${opencv_root_include_dir_full_path}")
message("OpenCV Libs directories:")
message("\t${opencv_root_libs_dir}")
if(MSVC)
     message("Where is Libs of Opencv are uesd (opencv_worldxxxd) on the debug mode:")
     message("\t${opencv_root_libs_used_debug}")
     message("Where is Libs of Opencv are uesd (opencv_worldxxx) on the release mode:")
     message("\t${opencv_root_libs_used_release}")
elseif(UNIX)
    message("Which Libs of Opencv are uesd on the debug mode:")
    message("\t${opencv_root_libs_used_debug}")
    message("Which Libs of Opencv are uesd on the release mode:")
    message("\t${opencv_root_libs_used_release}")
endif()



