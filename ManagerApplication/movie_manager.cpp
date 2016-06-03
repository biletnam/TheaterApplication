#include "movie_manager.h"

MovieManager::MovieManager()
{
	enum MovieManagerFunction
	{
		CHECK_N_DELETE_MOVIE = 1,
		REGISTER_MOVIE,
	};

	for (;;)
	{
		system("cls");
		cout << 
			"���� ���� �ý���\n"
			" > ��ȭ ���� ����\n"
			"\n";
		
		if (FUNCTION_NULL == Movie::showRecent())
		{
			cout << "\n��ϵ� ��ȭ�� �����ϴ�\n";
			system("pause");
			registerMovie();
			return;
		}

		cout <<
			"\n--------------------------\n"
			"\n"
			"1. ����� ��ȭ Ȯ�� / ����\n"
			"2. ���ο� ��ȭ ���\n"
			"0. ����\n"
			"\n"
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
				checkAndDeleteMovie();
				continue;
			case REGISTER_MOVIE:
				registerMovie();
				continue;
			}
		case FUNCTION_ERROR:
			cout << "�߸��� �Է��Դϴ�.\n";
			system("pause");
		}
	}
}
