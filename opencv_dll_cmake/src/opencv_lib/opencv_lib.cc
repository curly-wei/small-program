#define OPENCV_LIB_INTERNAL

#include "include/opencv_lib.hpp"

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>

OPENCV_LIB_API bool dol::openimg(std::string path)
{
    cv::Mat image = cv::imread( path, cv::IMREAD_COLOR ); // Read the file
    if( image.empty() )  // Check for invalid input
    {
        std::cout <<  "Could not open or find the image" << std::endl ;
        return false;
    }
    cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE ); // Create a window for display.
    cv::imshow( "Display window", image );                // Show our image inside it.
    cv::waitKey(0);
    return true;
}

OPENCV_LIB_API void CAPI_openimg(const char* CAPI_path) //C API must be non-class and non-nanmespcae function
{
    std::string path_buffer(CAPI_path);
    dol::openimg(path_buffer);
}