#include "movie.h"

void Movie::setKeyword(SQLWCHAR *keyword) const
{
	cout << output << "(0�� �Է��ϸ� ����): ";

	SQLWCHAR input[BUFSIZ];
	wcin.imbue(locale("korean"));
	wcin >> input;

	swprintf_s(keyword, BUFSIZ, L"%%%s%%", input);
}