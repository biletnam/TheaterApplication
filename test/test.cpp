#include "DB_helper.h"
#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	char ccc[2];
	cin >> ccc;

	DBHelper db;
	db.connectDB();

	db.closeDB();
	return 0;
}
