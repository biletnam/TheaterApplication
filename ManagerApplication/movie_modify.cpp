#include "movie.h"

FNRETURN Movie::del()
{
	

	if (SQL_SUCCESS == bindParameter(MDF_THEATER, MOVIE_CODE)
		&& SQL_SUCCESS ==
		dbHelper.execute(MDF_THEATER, L"DELETE FROM movie_internal WHERE movie_code=?;"))
	{
		cout << "\n�����Ǿ����ϴ�.\n";
	}
	else
	{
		cout << "\n������ �߻��߽��ϴ�.(checkAndDeleteMovie)\n";
	}
	return FNRETURN();
}

FNRETURN Movie::insert()
{
	return FNRETURN();
}
