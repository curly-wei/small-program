#ifndef _TMP_H_
#define _TMP_H_

#include <iostream>

template<typename T>
class tmp_class{
 public:    
  void printval(T in);
};

template<>
class tmp_class<float>{
 public:
  void printval(float in);
};

#include "tmp.cc"

#endif