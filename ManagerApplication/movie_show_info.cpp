#include "movie.h"

FNRETURN Movie::showInfo(SQLHSTMT& stmt)
{
	SQLCancel(stmt);
	SQLBindCol(stmt, 1, SQL_INTEGER, &code, sizeof code, NULL);
	SQLBindCol(stmt, 2, SQL_CHAR, title, BUFSIZ, NULL);
	SQLBindCol(stmt, 3, SQL_CHAR, director, BUFSIZ, NULL);
	SQLBindCol(stmt, 4, SQL_INTEGER, &age, sizeof age, NULL);
	SQLBindCol(stmt, 5, SQL_INTEGER, &year, sizeof year, NULL);
	SQLBindCol(stmt, 6, SQL_INTEGER, &runningTime, sizeof runningTime, NULL);
	SQLRETURN ret = SQLExecute(stmt);

	for (int i = 1; ret == SQL_SUCCESS; i++)
	{
		switch (ret = SQLFetch(stmt))
		{
		case SQL_SUCCESS:
			cout << i << ". "
				<< title
				<< "(" << director << "), "
				<< runningTime << "분, ";
			if (age == 0)
			{
				cout << "전체";
			}
			else
			{
				cout << age << "세";
			}
			cout << ", " << year << "년\n";
			break;
		case SQL_NO_DATA:
			if (i == 1)
			{
				cout << "\n등록된 영화가 없습니다\n";
				system("pause");
				return FUNCTION_NULL;
			}
			else
			{
				return FUNCTION_SUCCESS;
			}		
		}
	}

	cout << "\n오류가 발생했습니다.\n";
	system("pause");

	return FUNCTION_ERROR;
}