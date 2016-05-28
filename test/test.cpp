#include "DB_helper.h"
#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

char* vvv()
{
	char *ccc="ccc";
	return ccc;
}

int main()
{
	DBHelper db;
	db.connectDB();

	char* ccc = vvv();

	db.closeDB();
	return 0;
}
