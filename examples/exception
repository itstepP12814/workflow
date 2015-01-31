#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <string>
#include <exception>

class Hedgehog {
public:
	~Hedgehog() {
		std::cout << "Hedgehog ran  away\n";
	}
};

class Fraction {
public:
	int num;
	unsigned den;
	Fraction(int num_, unsigned den_) :
		num(num_), den(den_) {};
	Fraction() : Fraction(0, 1) {};
	Fraction(int v) : Fraction(v, 1) {};
	Fraction operator/(const Fraction & second) const {

		Hedgehog Sonic;

		if (second.num == 0) {
			throw std::exception(
				"in Fraction: division by zero\n"
			);
		}

		return Fraction(num*second.den, den*second.num);
	}
};

std::ostream& operator<<(std::ostream& s, const Fraction& f) {
	s << "{ \"num\":" << f.num <<
		", \"den\":" << f.den << " }";
	return s;
}



std::istream& operator>>(std::istream& s, Fraction& f) {
	// { .......... }
	char c;
	std::string str;
	s >> c;
	if (c != '{') {
		printf("Error parsing fraction");
		return s;
	}
	while (c != '}') {
		str += c;
		s >> c;
	}
	str += c;
	int res = sscanf(
		str.c_str(),
		"{ \"num\" : %d, \"den\" : %d%c",
		            &(f.num),     &(f.den),&c
	);
	if ((res < 3) || c!='}') {
		printf("ERROR\n");
	}
	return s;
}




int main() {

	try {
		Fraction a(1, 2), b(0,1),c;
		std::cout << "before /\n";
		c = a / b;
		std::cout << "after /\n";
	}
	catch (std::exception ex) {
		std::cout << "Caught ex:" << ex.what() << "\n";
	}

	std::cout << "Continue...\n";
	getc(stdin);

	return 0;
	// generate fractions
	std::vector<Fraction> v,v2;
	for (size_t i = 0; i < 10; i++) {
		v.push_back(Fraction(i,2));
	}

	// write to file
	std::ofstream out("data.txt");
	for (auto fr : v) {
		out << fr << ",";
	}
	out.close();

	// read from file
	std::ifstream in("data.txt");
	while (!(in.eof())) {
		Fraction f;
		in >> f;
		v2.push_back(f);
		// ignore spaces

		char c = ' ';
		while (c == ' ' || c == '\n' || c == '\t') {
			in >> c;
		}

		if (c != ',') {
			printf("Error parsing file\n");
			break;
		}

		// ignore spaces
		c = ' ';
		while (c == ' ' || c == '\n' || c == '\t') {
			in >> c;
			if (in.eof()) {
				goto x; //break 2
			}
		}

		in.unget();
	}
	x:
	// check data
	for (auto fr : v2) {
		std::cout << fr << "\n";
	}

	getc(stdin);
	return 0;
}
