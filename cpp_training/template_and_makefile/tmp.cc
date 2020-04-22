#ifndef _TMP_CC_
#define _TMP_CC_

#include <iostream>

#include "tmp.h"

//Instantiated
template<typename T>
void tmp_class<T>::printval(T in){
    printf("general ver: %d \n",in);
};

//full specilize and Instantiated
void tmp_class<float>::printval(float in){
    printf("float ver: %f \n",in);
};

#endif