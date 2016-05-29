#include "movie.h"

FNRETURN Movie::search(MovieTable movieTable)
{
	cout << "영화 제목을 검색하세요(0을 입력하면 종료): ";
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
	
	cout << "\n오류가 발생했습니다.(Movie.search)\n";
	system("pause");

	return FUNCTION_ERROR;
}