#include "tmp.h"

int main(int argc, char const *argv[])
{
    int a=3;
    float b=4.0;
    tmp_class<int> tmp_class_int;
    tmp_class_int.printval(a);

    tmp_class<float> tmp_class_float;
    tmp_class_float.printval(b);
    return 0;
}
