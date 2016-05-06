#include "issue.h"

bool Issue::chooseMovie()
{
	showInfo();

	bool isChosen = false;
	int rowCount = 0;
	int movieCode;
	SQLCHAR movieTitle[BUFSIZ];
	SQLWCHAR sql[BUFSIZ];
	SQLHSTMT& stmt = dbHelper.saleInfoStmt;

	swprintf_s(sql, TEXT("SELECT distinct movie_code, movie from d%d"), date);
	SQLBindCol(stmt, 1, SQL_INTEGER, &movieCode, sizeof(movieCode), NULL);
	SQLBindCol(stmt, 2, SQL_CHAR, movieTitle, BUFSIZ, NULL);
	SQLExecDirect(stmt, sql, SQL_NTS);
	SQLRowCount(stmt, (SQLINTEGER*)&rowCount);

	if (rowCount == 0)
	{
		cout << "������ ���� �����ϴ�.\n";
		return isChosen;
	}

	cout << "\n�� ��ȭ\n";
	for (int i = 1; i <= rowCount + 1; i++)
	{
		SQLRETURN ret = SQLFetch(stmt);
		if (ret == SQL_SUCCESS)
		{
			cout << i << ". " << movieTitle << endl;
		}
		else if (ret == SQL_NO_DATA)
		{
			if (dbHelper.moveCursor(stmt, "\n��ȭ�� �����ϼ���") == true)
			{
				this->movieCode = movieCode;
				memcpy_s(this->movieTitle, BUFSIZ, movieTitle, BUFSIZ);
				isChosen = true;
			}
		}
		else
		{
			cout << "������ �߻��߽��ϴ�.\n";
			return isChosen;
		}
	}

	return isChosen;
}