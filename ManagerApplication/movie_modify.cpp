#include "movie.h"

FNRETURN Movie::del()
{
	cout << "\n선택한 영화 정보:\n";
	show();
	L"DELETE FROM movie_internal WHERE movie_code=?;";
	return FNRETURN();
}

FNRETURN Movie::insert()
{
	return FNRETURN();
}
