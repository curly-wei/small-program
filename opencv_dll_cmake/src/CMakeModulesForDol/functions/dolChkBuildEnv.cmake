##This function checks whether the machine is 32-bit or 64-bit.
macro(dolChkIF64)
    if(NOT (${CMAKE_SIZEOF_VOID_P} EQUAL 8))
        message(FATAL_ERROR "project: \"${project_name}\" Enviroment is not 64 bits for build")
    endif()
endmacro(dolChkIF64)

##This function checks version of compiler

macro(dolChkCompilerVerGeneral)
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    if("${CMAKE_CXX_COMPILER_VERSION}" VERSION_LESS "7.3")
        message(FATAL_ERROR "Insufficient gcc version (< gcc ver 7.3)")
    endif()
    elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    if("${CMAKE_CXX_COMPILER_VERSION}" VERSION_LESS "19.10")
        message(FATAL_ERROR "Insufficient msvc version (< MSVC ver 19.10)")
    endif()
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
    if("${CMAKE_CXX_COMPILER_VERSION}" VERSION_LESS "7.0")
        message(FATAL_ERROR "Insufficient msvc version (< AppleClang ver 7.0)")
    endif()   
else()
    message(FATAL_ERROR "There are no compilers that can be supported (support GCC >= 7.3, MSVC >= 19.10, AppleClang >= 7.0)")
endif()   
endmacro(dolChkCompilerVerGeneral)

