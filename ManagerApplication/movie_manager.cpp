#include "movie_manager.h"

MovieManager::MovieManager()
{
	for (;;)
	{
		system("cls");
		cout << 
			"���� ���� �ý���\n"
			" > ��ȭ ���� ����\n\n";

		showRecent();

		cout <<
			"\n--------------------------\n\n"

			"1. ����� ��ȭ Ȯ�� / ����\n"
			"2. ���ο� ��ȭ ���\n"
			"0. ����\n\n"

			"����: ";

		int32_t function = 0;
		switch (inputPositiveInteger(function))
		{
		case FUNCTION_CANCEL:
			return;
		case FUNCTION_SUCCESS:
			switch (function)
			{
			case CHECK_N_DELETE_MOVIE:
				manageMovie(CHECK_N_DELETE_MOVIE);
				continue;
			case REGISTER_MOVIE:
				manageMovie(REGISTER_MOVIE);
				continue;
			}
		case FUNCTION_ERROR:
			cout << "�߸��� �Է��Դϴ�.\n";
			system("pause");
		}
		
	}
}
