#include "movie.h"

FNRETURN Movie::del()
{
	

	if (SQL_SUCCESS == bindParameter(MDF_THEATER, MOVIE_CODE)
		&& SQL_SUCCESS ==
		dbHelper.execute(MDF_THEATER, L"DELETE FROM movie_internal WHERE movie_code=?;"))
	{
		cout << "\n삭제되었습니다.\n";
	}
	else
	{
		cout << "\n오류가 발생했습니다.(checkAndDeleteMovie)\n";
	}
	return FNRETURN();
}

FNRETURN Movie::insert()
{
	return FNRETURN();
}
