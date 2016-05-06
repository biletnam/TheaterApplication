#include "movie.h"

bool Movie::showInfo(SQLHSTMT& stmt)
{
	SQLBindCol(stmt, 1, SQL_INTEGER, &code, sizeof(code), NULL);
	SQLBindCol(stmt, 2, SQL_CHAR, title, BUFSIZ, NULL);
	SQLBindCol(stmt, 3, SQL_CHAR, director, BUFSIZ, NULL);
	SQLBindCol(stmt, 4, SQL_INTEGER, &age, sizeof(age), NULL);
	SQLBindCol(stmt, 5, SQL_INTEGER, &year, sizeof(year), NULL);
	SQLBindCol(stmt, 6, SQL_INTEGER, &runningTime, sizeof(runningTime), NULL);
	SQLRETURN ret = SQLExecute(stmt);

	for (int i = 1; ret == SQL_SUCCESS; i++)
	{
		switch (ret = SQLFetch(stmt))
		{
		case SQL_SUCCESS:
			cout << i << ". "
				<< "영화코드:" << code
				<< ", 제목:" << title
				<< ", 감독:" << director
				<< ", 관람가:" << age
				<< ", 개봉연도:" << year
				<< ", 러닝타임:" << runningTime << endl;
			break;
		case SQL_NO_DATA:
			if (i == 1) 
			{
				cout << "등록된 영화가 없습니다\n";
			}
			else
			{
			}
			break;
		default:
			cout << "오류가 발생했습니다.\n";
		}
	}
	

	return FUNCTION_ERROR;
}