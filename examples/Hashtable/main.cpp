#include <string>
#include <iostream>
#include <cstdio>

template <class keyType, class valueType>
class tree {
private:
	class item {
	public:
		const keyType key;
		valueType value;
		item* left;
		item* right;
		item(const keyType& key_) :
			left(nullptr), right(nullptr), key(key_) {}
		~item() {
			delete left;
			delete right;
		}
	};

	size_t size_;

	item* root; 
public:
	class iterator{
	private:

		item* current;
	public:
		iterator() : current(nullptr) {};
		iterator& operator++();
		valueType& operator*() const;
		bool operator==(const iterator& another) const;
		bool operator!=(const iterator& another) const {
			return !(operator==(another));
		}
	};
	iterator begin() {
	///
	};
	iterator end() { return iterator(); };
	tree() : root(nullptr),size_(0) {}
	~tree() { delete root; }
	size_t size() { return size_; }
	valueType& operator[](const keyType& index) {
		item ** current = &root;  
		while (  (*current) != nullptr) {
			if ((*current)->key == index) {
				return (*current)->value;
			}
			if (index < (*current)->key) {
				current = &((*current)->left);
			}
			else {
				current = &((*current)->right);
			}
		}
		(*current) = new item(index); 
		size_++;
		return (*current)->value;
	}
};


unsigned int digest(const std::string& str) {
	unsigned int sum = 0;
	for (size_t i = 0; i < str.length(); i++) {
		sum += str[i] * i;
	}
	return sum;
}

const size_t N = 21;
class Hashtable {
public:
	tree<std::string, int> elements[N];
	int & operator[] (std::string key) {
		unsigned i = digest(key) % N;
		return	elements[i][key];
		return (
			elements[i] /// набор пар ключ-значение
			)[key];
	}
};


int main() {
	tree<std::string,int> // instantiation
		tbl;
	tbl["adsd"] = 3435;
	tbl["gfgd"] = 1;
	tbl["adfd"] = 2;
	tbl["dsdf"] = 3;
	tbl["aasd"] = 4;
	tbl["fdsd"] = 6;
	tbl["adsd"] = 7;

	tree<float, tree<int, std::string>> qqq;
	qqq[1.04][4] = "hello";

	Hashtable t;
	t["BMW"] = 1983;
	t["Audi"] = 1981;
	t["opel"] = 2012;
	t["Orlyonok"] = 1961;
	t["Lada"] = 1983;
	t["Zil"] = 1991;
	t["GAZ"] = 1981;
	t["Porche"] = 1951;
	t["Ford"] = 1941;
	t["Rolls-Royce"] = 1921;
	t["Oldsmobile"] = 1893;
	t["Koennigsegg"] = 2011;
	// ArgoUML
	/*
	for (
		tree::iterator i = tbl.begin(); // int i=0
		i != tbl.end(); // i != 10
	i++					// i++
		) {
		std::cout << (*i) << std::endl;
	}
	*/
	
	for (size_t i = 0; i < N; i++) {
		std::cout << i << " " << t.elements[i].size() << "\n";
	}
	
	std::cout << tbl["adsd"] << std::endl;

	getc(stdin);
	return 0;
}
