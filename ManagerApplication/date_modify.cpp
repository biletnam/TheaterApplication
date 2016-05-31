#include "date.h"

FNRETURN Date::modify(ModifyType type)
{
	if (value > 0)
	{
		cout << "선택한 날짜 정보:\n";
		show();
		cout << ((type == MODIFY_DELETE) ? "\n삭제하시겠습니까?(y/n): " : "\n등록하시겠습니까?(y/n): ");
		char yn;
		switch (inputYN(yn))
		{
		case FUNCTION_ERROR:
			cout << "\n잘못된 입력입니다.\n";
			system("pause");
			break;
		case FUNCTION_SUCCESS:
			switch (yn)
			{
			case 'y':case 'Y':
				if (SQL_SUCCESS == bindParameter()
					&& SQL_SUCCESS ==
					execute(MDF_THEATER, ((type == MODIFY_DELETE) ? L""
						"DELETE FROM schedule WHERE date=?;" : L""
						"INSERT INTO schedule (value) VALUES (?);")))
				{
					cout << ((type == MODIFY_DELETE) ? "\n삭제되었습니다.\n" : "\n등록되었습니다.\n");
					system("pause");
				}
				else
				{
					cout << "\n오류가 발생했습니다.(Date::modify)\n";
					system("pause");
					return FUNCTION_ERROR;
				}
			case 'n':case 'N':
				value = 0;
				return FUNCTION_SUCCESS;
			}
		}
	}

	return FUNCTION_SUCCESS;
}