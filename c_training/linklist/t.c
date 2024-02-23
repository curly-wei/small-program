#include "t.h"

#include <stdlib.h>
#include <stdio.h>

obj* create_obj(const char* _name, const int _age){
  obj* result = (obj*)malloc(sizeof(obj));
  result->name = _name;
  result->age = _age;
  result->next = NULL;
  return result;
}


// Invailed code while obj* o = NULL;
void inline append_obj(obj* _obj, const char* _name, const int _age) {
  obj** indirect = &_obj;
  while ( *indirect != NULL ) { 
    indirect = &( (*indirect)->next );
	// *indirect = (*indirect)->next; //will not work
		printf("iterate to next\n");
	}
	*indirect = create_obj(_name, _age);
}

void append_obj_pp(obj** _obj, const char* _name, const int _age) {
  obj** indirect = _obj;
  while ( *indirect != NULL ) { 
    indirect = &( (*indirect)->next );
	// *indirect = (*indirect)->next; //will not work
	}
	*indirect = create_obj(_name, _age);
}

void push_top_obj(obj* _obj, const char* _name, const int _age) {
	obj** indirect = &_obj;
	obj* tmp = create_obj(_name, _age);
	obj** result = &tmp;
	//printf("%s\n", (*result)->name);
	(*result)->next = *indirect;
	_obj = *result;
}

void purge_objs(obj* _obj) {
  while (_obj){
    obj* indirect = _obj;
    _obj = _obj->next;
    free(indirect);
  }
}


void print_all_obj(const obj* _obj) {
  while (_obj != NULL) {
    printf("print all : %s,%d\n",_obj->name,_obj->age);
    _obj = _obj->next;
  }
}
