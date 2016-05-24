#include "DB_helper.h"
#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	float fff;
	cin >> fff;

	bool bbb = cin.fail();

	DBHelper db;
	db.connectDB();
	
	db.closeDB();
	return 0;
}