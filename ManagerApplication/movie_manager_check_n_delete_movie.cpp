#include "movie_manager.h"

void MovieManager::checkAndDeleteMovie()
{
	Movie movie;
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > ��ȭ ���� ����\n"
			"  > ����� ��ȭ Ȯ�� / ����\n";
		cout << endl;

		if (movie.getCode() != 0)
		{
			cout << "������ ��ȭ ����:\n";
			movie.show();

			cout << "\n�����Ͻðڽ��ϱ�?(y/n): ";
			switch (inputYN())
			{
			case FUNCTION_ERROR:
				cout << "\n�߸��� �Է��Դϴ�.\n";
				system("pause");
				break;
			case FUNCTION_SUCCESS:
				movie.bindParameter(MDF_THEATER, MOVIE_CODE);
				if (SQL_SUCCESS == movie.execute(MDF_THEATER, 
					L"DELETE FROM movie_internal WHERE movie_code=?;"))
				{
					cout << "\n�����Ǿ����ϴ�.\n";
					system("pause");
				}
				else
				{
					cout << "\n������ �߻��߽��ϴ�.(checkAndDeleteMovie)\n";
					system("pause");
					break;
				}
			case FUNCTION_CANCEL:
				movie.initialize();
			}
		}
		else
		{
			switch (movie.search(MOVIE_TABLE_INTERNAL))
			{
			case FUNCTION_CANCEL:
				return;
			case FUNCTION_SUCCESS:
				switch (movie.choose(MDF_THEATER))
				{
				case FUNCTION_NULL:
					cout << "��ϵ� ��ȭ�� �����ϴ�.\n";
					system("pause");
				case FUNCTION_CANCEL:
				case FUNCTION_ERROR:
					movie.initialize();
				}
			}
		}
	}
}