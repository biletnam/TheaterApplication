#include "schedule_manager.h"

void ScheduleManager::setMovie(Movie &movie)
{
	for (;;)
	{
		system("cls");
		cout <<
			"���� ���� �ý���\n"
			" > �� ���� ����\n"
			"  > �� ���� ���\n"
			"   > ��ȭ ����\n"
			"\n";

		switch (movie.choose(MDF_THEATER))
		{
		case FUNCTION_ERROR:
			cout << "�߸��� �Է��Դϴ�.";
			system("pause");
			break;
		case FUNCTION_NULL:
			cout << "��� ������ �󿵰��� �����ϴ�\n";
			system("pause");
		case FUNCTION_SUCCESS:
		case FUNCTION_CANCEL:
			return;
		}
	}
}