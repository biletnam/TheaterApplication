#include "DB_helper.h"
#include <Windows.h>
#include <string>
#include <iostream>
#include <functional>

using namespace std;

int main()
{
	DBHelper db;
	db.connectDB();

	db.closeDB();
	return 0;
}