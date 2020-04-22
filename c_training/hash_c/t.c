#include "t.h"

struct HashMap_st {
  int size;
  int capacity;
  HashCode hashcode;
  Equal equal;
  Entry list;
  Put put;
  Get get;
  Remove remove;
  Purge purge;
  IsExist is_exist;
  bool auto_assign;
};

static int default_HashCode(HashMap hashmap, void* key);
static bool default_Equal(void* key1, void* key2);
static void default_Put(HashMap hashmap, void* key, void* val);
static void* default_Get(HashMap hashmap, void* key);
static bool default_Remove(HashMap hashmap, void* key);
static bool default_Exist(HashMap hashmap, void* key);
static void default_Purge(HashMap hashmap);

HashMap create_HashMap(HashCode hashcode, Equal equal);
static void reset_HashMap(HashCode hashmap, int capacity);

int default_HashCode(HashMap hashmap, void* key) {
  
}