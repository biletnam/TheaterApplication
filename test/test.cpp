#include "DB_helper.h"
#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

class MyClass
{
public:
	void operator()() {
		cout << 111;
	};
	MyClass();
	~MyClass();
private:

};

int main()
{
	MyClass mmm;
	mmm();

	DBHelper db;
	db.connectDB();

	db.closeDB();
	return 0;
}

MyClass::MyClass()
{
	this->~MyClass();
}

MyClass::~MyClass()
{
}
