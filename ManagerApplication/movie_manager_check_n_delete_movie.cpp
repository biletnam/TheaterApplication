#include "movie_manager.h"

void MovieManager::checkAndDeleteMovie()
{
	Movie movie(dbHelper);
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > ��ȭ ���� ����\n"
			"  > ����� ��ȭ Ȯ�� / ����\n"
			"\n";

		if (movie.getCode() != 0)
		{
			cout << "������ ��ȭ ����:\n";
			movie.show();
			cout << "\n�����Ͻðڽ��ϱ�?(y/n)";
			char yn;
			switch (inputYN(yn))
			{
			case FUNCTION_ERROR:
				cout << "\n�߸��� �Է��Դϴ�.\n";
				system("pause");
				continue;
			case FUNCTION_SUCCESS:
				switch (yn)
				{
				case 'y':case 'Y':
					if (SQL_SUCCESS == movie.bindParameter(MDF_THEATER, MOVIE_CODE)
						&& SQL_SUCCESS ==
						dbHelper.execute(MDF_THEATER, L"DELETE FROM movie_internal WHERE movie_code=?;"))
					{
						cout << "\n�����Ǿ����ϴ�.\n";
					}
					else
					{
						cout << "\n������ �߻��߽��ϴ�.(checkAndDeleteMovie)\n";
					}
					system("pause");
				case 'n':case 'N':
					movie.setCode(0);
				}
				continue;
			}
		}

		switch (movie.search(MOVIE_TABLE_INTERNAL))
		{
		case FUNCTION_CANCEL:
			return;
		case FUNCTION_NULL:
			system("pause");
			break;
		case FUNCTION_SUCCESS:
			cout <<
				"0. ���\n"
				"\n"
				"����: ";

			switch (dbHelper.moveCursor(MDF_THEATER))
			{
			case FUNCTION_CANCEL:
			case FUNCTION_ERROR:
				movie.setCode(0);
			}
		}
	}
}