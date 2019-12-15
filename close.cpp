#include "kvs.h"

extern std::map<std::string, std::string>m;

void close() {
	m.clear();
}
