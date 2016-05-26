#include "DB_helper.h"
#include <Windows.h>
#include <string>
#include <iostream>
#include <functional>

using namespace std;

SQLRETURN execute(char* = NULL);

int main()
{
	execute("LLLLL");
	execute();
	DBHelper db;
	db.connectDB();

	db.closeDB();
	return 0;
}

SQLRETURN execute(char *sql)
{
	if (sql != NULL)
	{
		cout << sql;
	}

	return SQLRETURN();
}