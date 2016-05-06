#include "issue.h"

#define CHOICE_ISSUE 1
#define CHOICE_REFUND 2
#define CHOICE_QUIT 0

typedef unsigned short CHOICE;

using namespace std;

int main()

{
	DBHelper dbHelper;
	if (dbHelper.connectDB() == true) 
	{
		CHOICE choice;
		do
		{
			system("cls");
			cout << "\nƼ�� ���� �ý����Դϴ�.\n";
			cout << "�߱�(1), ȯ��(2), ����(0): ";
			cin >> choice;

			if (choice == CHOICE_ISSUE)
			{
				Issue issue(dbHelper);
			}
			else if (choice == CHOICE_REFUND)
			{
			}
			else if (choice != CHOICE_QUIT)
			{
				cout << "�ٽ� �Է��ϼ���.\n";
			}
		} while (choice != CHOICE_QUIT);
	}
	else
	{
		cout << "�����ͺ��̽� ���ٿ� �����߽��ϴ�.\n";
	}
		
	dbHelper.closeDB();
	return 0;
}

