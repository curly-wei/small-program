#include <iostream>
#include <array>
template<typename T, int arr_size>
class container {
 private:
  std::array<T,arr_size> m_array;
 public:
  typedef T value_type;
  container(std::array<T,arr_size> arr) :
    m_array(arr) {};
  auto&& operator[] (size_t index){
    return m_array.at(index);
  }
  void disp_arr() {
    for (const auto& i : m_array) {
      //TD<decltype(i)> test; //get type of auto
      printf("%d\n",i);
    }
  }
};

template <typename T>
struct trait {
  typedef typename T::value_type value_type;
};

int main(int argc, char const *argv[]) {
  typename trait<container<int,3>>::value_type cnt = 0;
  cnt += 1;
  printf("%d\n",cnt);
  return 0;
}
