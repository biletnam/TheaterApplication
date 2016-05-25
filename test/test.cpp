#include "DB_helper.h"
#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	char *ccc[3];
	ccc[0] = "000000000";
	ccc[1] = "111111111";
	ccc[2] = "222222222";

	cout << ccc[0];
	cout << ccc[1];
	cout << ccc[2];

	DBHelper db;
	db.connectDB();
	
	db.closeDB();
	return 0;
}