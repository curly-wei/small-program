#include <iostream>
#include <string>

class ChineseHelloWorld {
 protected:
  std::string getMessage() const {
    return "你好";
  }
};

class JapaneseHelloWorld {
 protected:
  std::string getMessage() const {
    return "こんにちは";
  }
};

class OutputWithSTDCout {
 protected:
  template <typename T>
  void Print(T&& msg) const {
    std::cout << "cout: " << std::forward<T>(msg) << std::endl;
  }
};

class OutputWithPrintf {
 protected:
  template <typename T>
  void Print(T&& msg) const {
    printf( "printf: %s\n", std::forward<T>(msg).c_str() );
  }
};

template <typename OutputPolicy, typename LangPolicy>
class HelloWorld : private OutputPolicy, private LangPolicy {
 public: 
  void run() const {
    OutputPolicy::Print( LangPolicy::getMessage() );
  }
};

int main(int argc, const char** argv) {
  using HW1 = HelloWorld<OutputWithSTDCout, ChineseHelloWorld>;
  using HW2 = HelloWorld<OutputWithSTDCout, JapaneseHelloWorld>;
  using HW3 = HelloWorld<OutputWithPrintf, ChineseHelloWorld>;
  using HW4 = HelloWorld<OutputWithPrintf, JapaneseHelloWorld>;  

  HW1 hw1;
  HW2 hw2;
  HW3 hw3;
  HW4 hw4; 

  hw1.run();
  hw2.run();
  hw3.run();
  hw4.run();

  return 0;
}
