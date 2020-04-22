#ifndef OPENCV_LIB_H_
#define OPENCV_LIB_H_

#if defined(_WIN64) && defined(opencv_lib_EXPORTS)
#  if defined(OPENCV_LIB_INTERNAL)
#    define OPENCV_LIB_API __declspec (dllexport)
#  else
#    define OPENCV_LIB_API __declspec (dllimport)
#  endif
#endif

#if !defined(OPENCV_LIB_API)
#  define OPENCV_LIB_API
#endif

#ifdef __cplusplus 
extern "C" {
#endif 

OPENCV_LIB_API void CAPI_openimg(const char* CAPI_path); //C API must be non-class and non-nanmespcae function

#ifdef __cplusplus
}
#endif

#endif


//ref: extern "C" and C++ API for C
//https://blog.csdn.net/zzwdkxx/article/details/44244535?fbclid=IwAR0o8G2JqZTJu3X4OEVFwYP2imkRjb9FWjNSy8_ahw-ylBvIAHslHuQlVfI
//https://stackoverflow.com/questions/16058245/including-c-header-file-with-namespace-in-c-source-file-causes-compilation-err