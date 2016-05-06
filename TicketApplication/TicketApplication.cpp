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
			cout << "\n티켓 관리 시스템입니다.\n";
			cout << "발권(1), 환불(2), 종료(0): ";
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
				cout << "다시 입력하세요.\n";
			}
		} while (choice != CHOICE_QUIT);
	}
	else
	{
		cout << "데이터베이스 접근에 실패했습니다.\n";
	}
		
	dbHelper.closeDB();
	return 0;
}

