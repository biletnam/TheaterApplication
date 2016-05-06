#include "movie_manager.h"
#include "schedule_manager.h"

void managePrice(DBHelper&);

enum
{
	MOVIE_MANAGER = 1,
	SCHEDULE_MANAGER = 2,
	PRICE_MANAGER = 3,
};

int main()
{
	DBHelper dbHelper;
	
	if (dbHelper.connectDB() == true)
	{
		int16_t choice;
		do
		{
			system("cls");
			cout << "���� ���� �ý���\n";
			cout << "��ȭ ���� ����(1), �ð�ǥ ����(2), ���� ����(3), ����(0): ";
			cin >> choice;

			switch (choice)
			{
			case MOVIE_MANAGER:
			{
				MovieManager movieManger(dbHelper);
				break;
			}
			case SCHEDULE_MANAGER:
			{
				ScheduleManager scheduleManager(dbHelper);
				break;
			}
			case PRICE_MANAGER:
				managePrice(dbHelper);
				break;
			case FUNCTION_CANCEL:
				break;
			default:
				cin.clear();
				cin.ignore(100, '\n');
				cout << "\n�߸��� �Է��Դϴ�."
					"\n����Ϸ��� �ƹ� Ű�� �����ʽÿ�...";
				_getch();
			}
		} while (choice != FUNCTION_CANCEL);
	}
	else 
	{
		cout << "�����ͺ��̽� ���ٿ� �����߽��ϴ�.\n";
	}
	
	dbHelper.closeDB();
	return 0;
}