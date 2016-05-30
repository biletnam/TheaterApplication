#include "DB_helper.h"
#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

class MyClass
{
public:
	virtual void show() = 0;
	void mmm() { show(); };
private:

};

class ccc : public MyClass
{
public:
	void show() { cout << 111; };
private:

};

int main()
{
	ccc c;
	c.mmm();

	DBHelper db;
	db.connectDB();

	db.closeDB();
	return 0;
}
