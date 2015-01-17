#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Car{
	private:
		string number;
		string make;
		friend istream& operator>>(istream&str, Car& c);
	public:
		string getNumber() const {	return number; }
		string getMake() const { return make; }
};

istream& operator>>(istream&str, Car& c){
	string buf;
	getline(str, buf);
	int pos = buf.find(' ');
	int pos2 = buf.find(' ', pos);
	//выделяем гос номер авто
	c.number = buf.substr(0, pos);
	c.make = buf.substr(pos, pos2);
	return str;
}
ostream& operator<<(ostream&str, const Car& c){
	str << c.getNumber();
	str << c.getMake();
	return str;
}

int main(){
	vector<Car> cars;

	ifstream dataFile("cars.txt");
	if (!(dataFile.is_open())){
		cout << "Error!" << endl;
		return 1;
	}

	while (!(dataFile.eof())){
		Car c;
		dataFile >> c;
		cars.push_back(c);
		cout << c << endl;
	}

	return 0;
}
