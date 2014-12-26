#include <string>
#include <iostream>
#include <cstdio>
#include <map>

unsigned int digest(const std::string& str) {
	unsigned int sum = 0;
	for (size_t i = 0; i < str.length(); i++) {
		sum += str[i]  * i;
	}
	return sum;
}

const size_t N = 21;
class Hashtable {
public:
	std::map<std::string, int> elements[N];
	int & operator[] (std::string key) {
		unsigned i = digest(key) % N;
		return	elements[i][key];
		return (	
		elements[i] /// набор пар ключ-значение
		)	[key];
 	}
};


int main() {
	Hashtable tbl;
	tbl["adsd"] = 3435;
	tbl["gfgd"] = 1;
	tbl["adfd"] = 2;
	tbl["dsdf"] = 3;
	tbl["aasd"] = 4;
	tbl["fdsd"] = 6;
	tbl["adsd"] = 7;

	for (size_t i = 0; i < N; i++) {
		std::cout << i << " " << tbl.elements[i].size() << "\n";
	}

	std::cout << tbl["adsd"] << std::endl;

	getc(stdin);
	return 0;
}
