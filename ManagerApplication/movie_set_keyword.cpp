#include "movie.h"

void Movie::setKeyword(SQLWCHAR *keyword) const
{
	SQLWCHAR input[BUFSIZ];
	wcin.imbue(locale("korean"));
	wcin >> input;

	swprintf_s(keyword, BUFSIZ, L"%%%s%%", input);
}