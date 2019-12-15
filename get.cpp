#include "kvs.h"
#include <cstring>

extern std::map<std::string, std::string>m;
extern std::map<std::string, std::string>::iterator iter;

char* get(char* key, int* nbytes) {
	std::string str = m.find(key)->second;
	char* str2 = new char[str.size()];
	strcpy(str2, str.c_str());
	return str2;
}
