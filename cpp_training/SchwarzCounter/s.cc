#include "s.h"

std::FILE* Log::onlyFile_ = 0;
int Initializer::ref_ = 0;

Initializer::Initializer() {
   if (0 == ref_++) {
      Log::onlyFile_ = fopen("somefile.txt", "w");
   }
}

Initializer::~Initializer() {
   if (0 == --ref_) {
      fclose(Log::onlyFile_);
   }
}