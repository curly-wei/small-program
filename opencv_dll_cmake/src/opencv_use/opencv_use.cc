#include "../opencv_lib/include/opencv_lib.hpp"
#include <string>

int main( int argc, char** argv )
{
    const char* CAPI_imageName = "/home/dewei/test.jpeg";
    std::string imageName(CAPI_imageName); // by default
    if( argc > 1)
    {
        imageName = std::string(argv[1]);
    }
    dol::openimg(imageName);
    CAPI_openimg(CAPI_imageName);
    return 0;
}
