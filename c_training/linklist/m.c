#include <stdio.h>

#include "t.h"

int main(int argc, char const *argv[])
{
    //obj* o = create_obj("De",24);
    obj* o = NULL;
		append_obj_pp(&o, "ppWei", 25);
    append_obj_pp(&o, "ppLan", 27);
		
		append_obj(o, "Wei", 25);
    append_obj(o, "Lan", 27);
		

		//push_top_obj(o, "X", 1);
    
		print_all_obj(o);
    
		purge_objs(o);
    return 0;
}
