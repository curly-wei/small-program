#include <iostream>
#include <string>
#include <utility>
#include <type_traits>
class Person {
 public:
  
  template <
    typename T, 
    //c++14
  //   typename = 
  //   std::enable_if_t< 
  //     !std::is_same< 
  //       Person, std::decay_t<T> 
  //     >::value
  //   >
  // >
  //c++11
    typename R = 
    typename std::enable_if< 
      !std::is_same< 
        Person, typename std::decay<T>::type 
      >::value
    >::type
  >
  Person(T&& _name) :
    m_name(std::forward<T>(_name)) {
    }
  void print_name () {
    std::cout << m_name << std::endl;
  };
 private:
  std::string m_name;
};

Person clone_person(Person& _P) {
  Person clone(_P);
  return clone;
}

int main(int argc, char const *argv[]) {
  Person p("Nancy");
  p.print_name();
  Person q = clone_person(p);
  q.print_name();
  return 0;
}
