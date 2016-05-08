#include "DB_helper.h"
#include <Windows.h>

int main()
{
	cout << 111 << endl;
	int x = 10;
	int y = -2;
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	DBHelper db;
	db.connectDB();

	db.closeDB();
	return 0;
}