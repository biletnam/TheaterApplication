#include "movie.h"

FNRETURN Movie::del()
{
	cout << "\n������ ��ȭ ����:\n";
	show();
	L"DELETE FROM movie_internal WHERE movie_code=?;";
	return FNRETURN();
}

FNRETURN Movie::insert()
{
	return FNRETURN();
}
