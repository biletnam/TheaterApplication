#include "movie.h"

FNRETURN Movie::search(MovieTable movieTable)
{
	cout << "��ȭ ������ �˻��ϼ���(0�� �Է��ϸ� ����): ";
	SQLWCHAR keyword[BUFSIZ];
	setKeyword(keyword);
	if (wcscmp(keyword, L"%0%") == 0)
	{
		return FUNCTION_CANCEL;
	}
	cout << endl;

	SQLHSTMT& stmt = dbHelper.getStmt(MDF_THEATER);
	dbHelper.bindParameter(MDF_THEATER, BIND_STRING, keyword);
	bindCol(MDF_THEATER, MOVIE_CODE);
	bindCol(MDF_THEATER, MOVIE_TITLE);
	bindCol(MDF_THEATER, MOVIE_DIRECTOR);
	bindCol(MDF_THEATER, MOVIE_AGE);
	bindCol(MDF_THEATER, MOVIE_YEAR);
	bindCol(MDF_THEATER, MOVIE_RUNNINGTIME);

	SQLWCHAR sql[BUFSIZ];
	swprintf_s(sql, L""
		"SELECT movie_code, title, director, age, year, running_time "
		"FROM %s WHERE title LIKE ?;",
		(MOVIE_TABLE_EXTERNAL == movieTable) ? L"movie_external" : L"movie_internal");

	if (SQL_SUCCESS == dbHelper.execute(MDF_THEATER, sql))
	{
		for (size_t i = 1;; i++)
		{
			switch (dbHelper.fetch(MDF_THEATER))
			{
			case SQL_SUCCESS:
				cout << i << ". ";
				show();
				continue;
			case SQL_NO_DATA:
				if (i == 1)
				{
					cout << "\n��ϵ� ��ȭ�� �����ϴ�\n";
					system("pause");
					return FUNCTION_NULL;
				}
				else
				{
					return FUNCTION_SUCCESS;
				}
			}
			break;
		}
	}

	cout << "\n������ �߻��߽��ϴ�.(Movie.search)\n";
	system("pause");

	return FUNCTION_ERROR;
}