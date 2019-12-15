#include "kvs.h"

extern std::map<std::string, std::string>m;

int put(char* key, char* value, int nbytes) {
	std::string str(key);
	std::string str2(value);
	m[str] = str2;
	return 0;
}
