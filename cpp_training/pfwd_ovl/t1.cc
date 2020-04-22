struct Test {
    typedef int foo;
};

template <typename T> 
void f(typename T::foo) {} // Definition #1

template <typename T> 
void f(T) {}               // Definition #2

template<bool B, class T = void>
struct enable_if_q {};
 
template<class T>
struct enable_if_q<true, T> { typedef T type; };

int main() {
    f<Test>(10); // Call #1.
    f<int>(10);  // Call #2. Without error (even though there is no int::foo) thanks to SFINAE.

//typename enable_if_q<true, int>::type t; 
//typename enable_if_q<true>::type ; 
//typename enable_if_q<false>::type; 
//typename enable_if_q<false, int>::type t2; 
}