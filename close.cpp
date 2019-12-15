#include <map>
#include <string>

extern std::map<std::string, std::string>m;

extern "C" void close() {
	m.clear();
}
