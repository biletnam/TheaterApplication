#include "DB_helper.h"
#include <Windows.h>
#include <string>
#include <iostream>
#include <ctype.h>
#include <string>

using namespace std;

int main()
{
	char* ccc = "asdfadf";
	string sss = "dasff";

	float fff;
	char delim = ' ';
	DBHelper db;
	db.connectDB();

	db.closeDB();
	return 0;
}

