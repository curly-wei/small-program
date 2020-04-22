#include <stdio.h>

#include "t.h"

int main(int argc, char const *argv[])
{
    obj* o = create_obj("de",24);
    append_obj(o, "Wei", 25);
    append_obj(o, "Lan", 27);
    print_all_obj(o);
    purge_objs(o);
    return 0;
}
