/* ref:
 * https://zhuanlan.zhihu.com/p/54017133
 */

#include <stdlib.h>
#include <stdbool.h>

typedef struct Entry_st {
  void* key;
  void* val;
  struct entry* next;
}* Entry;

#define newEntry() NEW(struct entry_st)
#define newEntryList() (Entry)malloc(length * sizeof(Entry))

typedef struct HashMap_st* HashMap;

typedef int (*HashCode)(HashMap, void* key);
typedef bool (*Equal)(void* key1, void* key2);
typedef void (*Put)(HashMap hash_map, void* key, void* val);
typedef void* (*Get)(HashMap hash_map, void* key);
typedef bool (*Remove)(HashMap hash_map, void* key);
typedef bool (*IsExist)(HashMap hash_map, void* key);
typedef void (*Purge)(HashMap hash_map);

