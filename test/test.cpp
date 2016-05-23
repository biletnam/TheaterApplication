#include "DB_helper.h"
#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

class UPUP
{
public:
	int ccc;
	UPUP() { cout << "bbb"; }
};

class Test : public UPUP
{
public:
	Test() { cout << "¿¬°á"; }
};

int main()
{
	Test test1;
	Test &test2 = test1;

	DBHelper db;
	db.connectDB();

	db.closeDB();
	return 0;
}