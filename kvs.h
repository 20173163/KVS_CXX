#ifndef KVS_H
#define KVS_H

#include <map>
#include <string>
#define KEY_SIZE 16
#define VAL_SIZE 99

int put(char* key, char* value, int nbytes);
char* get(char* key, int* nbytes);
int open();
void close();

#endif
