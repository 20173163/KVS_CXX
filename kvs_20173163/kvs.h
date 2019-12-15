#ifndef KVS_H
#define KVS_H

extern "C" int put(char* key, char* value, int nbytes);
extern "C" char* get(char* key, int* nbytes);
extern "C" int open();
extern "C" void close();

#endif
