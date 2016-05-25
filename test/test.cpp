#include "DB_helper.h"
#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

class MyClass
{
public:
	MyClass();
	~MyClass();
	static int iii;
	static int getInt();
private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

int MyClass::getInt()
{
	return 2;
}

int MyClass::iii = 2;

int main()
{
	DBHelper db;
	db.connectDB();
	
	int sss = sizeof MyClass::iii;
	int *ppp;
	ppp = &MyClass::iii;

	int aaa = 1;

	SQLHSTMT &stmt = db.theaterStmt;
	SQLRETURN ret = SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER,
		sizeof MyClass::getInt(), 0, &MyClass::getInt(), 0, NULL);
	//SQLRETURN ret = SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER,
		//sizeof aaa, 0, &aaa, 0, NULL);
	ret = SQLExecDirect(stmt, L"SELECT * FROM price WHERE code=?", SQL_NTS);
	
	ret = SQLFetch(stmt);
	//ret = SQLFetch(stmt);
	ret = SQLGetData(stmt, 3, SQL_INTEGER, &sss, sizeof sss, NULL);

	db.closeDB();
	return 0;
}