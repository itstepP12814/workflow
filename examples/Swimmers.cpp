#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Object{
public:
	Object(){
		cout << "Hi i am object\n";
	}
	virtual ~Object(){};
};
class Animal :public Object{
public:
	string name;
	Animal(){
		cout << "Animal\n";
	}
	virtual ~Animal(){};
};
class Swimmers{
public:
	Swimmers(){
		cout << "I can swim\n";
	}
	void swim(){
		Animal* s = dynamic_cast<Animal*>(this);
		if (s!=nullptr)
		{
			cout << s->name << " ";
		}
		cout << "Bul Bul\n";
	}
	virtual ~Swimmers(){};
};
class Mammal:public Animal{
public:
	Mammal(){
		cout << "Mammal\n";
	}
};
class Fish:public Animal,public Swimmers{
public:
	Fish(){
		cout << "Fish\n";
	}
};
class Whale :public Mammal, public Swimmers{
public:
	Whale(){
		cout << "Whale\n";
	}
};
class Shark : public Fish{
public:
	Shark(){
		cout << "Shark\n";
	}
};
class Cat :public Mammal{
public:
	Cat(){
		cout << "Cat\n";
	}
};
class Submarine:public Swimmers,public Object{
public:
	Submarine(){
		cout << "Submarine\n";
	}
};
int main(){
	Whale Freddy;
	Freddy.name = "Freddy";
	cout << "------------------\n";
	Cat Tom;
	Tom.name = "Tom";
	cout << "------------------\n";
	Shark Chashbr;
	Chashbr.name = "Chashbr";
	Submarine Kursk;
	vector<Object*> zoo{&Freddy, &Tom, &Chashbr,&Kursk};
	for (Object* a : zoo)
	{
		Swimmers* s = dynamic_cast<Swimmers*>(a);
		if (s!=nullptr)
		{
			s->swim();
		}
		else
		{
			cout << "Object cant swim\n";
		}
	}
	return 0;
}
