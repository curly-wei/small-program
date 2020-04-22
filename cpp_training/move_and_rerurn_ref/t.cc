#include <iostream>
using namespace std;
class val_c {
 private:
  int m_val;
 public:
  val_c(int _val): 
    m_val(_val) { 
    }
  inline int get_val() const {
    return m_val;
  }
  decltype(auto) add(const val_c& _in){ //universal ref
    m_val += _in.get_val();
    cout << "add val: " << _in.get_val() <<", result: "<< m_val <<endl;
    return std::move(*this);
  }
};

int main(int argc, char const *argv[]) {
  val_c vc(0);
  vc.add(3).add(4).add(5);
  return 0;
}
