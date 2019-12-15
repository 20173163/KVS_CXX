#include <map>
#include <string>

extern std::map<std::string, std::string>m;

extern "C" int put(char* key, char* value, int nbytes) {
	std::string str(key);
	std::string str2(value);
	m[str] = str2;
	return 0;
}
