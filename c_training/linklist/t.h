#ifndef _T_H_
#define _T_H_

typedef struct obj_t {
  const char* name;
  int age;
  struct obj_t* next;
} obj;

obj* create_obj(const char* _name, const int _age);
void append_obj(obj* _obj, const char* _name, const int _age);
void purge_objs(obj* _obj);
void print_all_obj(const obj* _obj);


#endif