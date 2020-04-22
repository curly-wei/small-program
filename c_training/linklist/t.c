#include "t.h"

#include <stdlib.h>
#include <stdio.h>

obj* create_obj(const char* _name, const int _age){
  obj* result = (obj*)malloc(sizeof(obj));
  if (result == NULL) return 0;
  result->name = _name;
  result->age = _age;
  result->next = NULL;
  return result;
}

void append_obj(obj* _obj, const char* _name, const int _age) {
  obj* indirect = _obj;
  while (indirect->next != NULL) {
    indirect = indirect->next;
  }
  indirect->next = create_obj(_name, _age);
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