#include "DB_helper.h"
#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	wcout.imbue(locale("korean"));
	wcout << L"¾Æ¶ó¾Æ";
	
	DBHelper db;
	db.connectDB();

	db.closeDB();
	return 0;
}

