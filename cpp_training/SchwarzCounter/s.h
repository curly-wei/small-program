#ifndef S_H
#define S_H

#include <fstream>

class Log {
friend class Initializer;
public:
   void Print(const char* msg) {
      std::fputs(msg, onlyFile_);
   }

private:
   static std::FILE* onlyFile_;
};

class Initializer {
public:
   Initializer();
   ~Initializer();
private:
   static int ref_;
};

extern Log log;
static Initializer init;

#endif