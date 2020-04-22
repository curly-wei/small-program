#ifndef OPENCV_LIB_HPP_
#define OPENCV_LIB_HPP_

#include "opencv_lib_CAPI.h"

//about cpp, place here
//-------------------------------------------------------------------------------------------------------------
#include <string>
namespace dol{
    OPENCV_LIB_API bool openimg(std::string path);
}
//-------------------------------------------------------------------------------------------------------------


extern "C" 
{
//C_API place here
//-------------------------------------------------------------------------------------------------------------
OPENCV_LIB_API void CAPI_openimg(const char* CAPI_path); //C API must be non-class and non-nanmespcae function
//-------------------------------------------------------------------------------------------------------------
}


#endif


//ref: extern "C" and C++ API for C
//https://blog.csdn.net/zzwdkxx/article/details/44244535?fbclid=IwAR0o8G2JqZTJu3X4OEVFwYP2imkRjb9FWjNSy8_ahw-ylBvIAHslHuQlVfI
//https://stackoverflow.com/questions/16058245/including-c-header-file-with-namespace-in-c-source-file-causes-compilation-err