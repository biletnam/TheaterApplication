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

	SQLWCHAR sql[BUFSIZ];
	swprintf_s(sql, L""
		"SELECT movie_code, title, director, age, year, running_time "
		"FROM %s WHERE title LIKE ?;",
		(MOVIE_TABLE_EXTERNAL == movieTable) ? L"movie_external" : L"movie_internal");

	if (SQL_SUCCESS == dbHelper.bindParameter(MDF_THEATER, BIND_STRING, keyword)
		&& SQL_SUCCESS == dbHelper.prepare(MDF_THEATER, sql))
	{
		return showSelectResult();
	}
	
	cout << "\n������ �߻��߽��ϴ�.(Movie.search)\n";
	system("pause");

	return FUNCTION_ERROR;
}