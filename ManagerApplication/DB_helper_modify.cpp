#include "DB_helper.h"

FNRETURN DBHelper::modify(ModifyType type)
{
	cout << ((type == MODIFY_DELETE) ? "\n삭제하시겠습니까?(y/n): " : "\n등록하시겠습니까?(y/n): ");
	switch (inputYN())
	{
	case FUNCTION_ERROR:
		cout << "\n잘못된 입력입니다.\n";
		break;
	case FUNCTION_SUCCESS:
		if (SQL_SUCCESS == ((MODIFY_DELETE == type) ? del() : insert()))
		{
			cout << ((type == MODIFY_DELETE) ? "\n삭제되었습니다.\n" : "\n등록되었습니다.\n");
			system("pause");
			return FUNCTION_SUCCESS;
		}
		else
		{
			cout << "\n오류가 발생했습니다.(DBHelper::modify)\n";
			break;
		}
	case FUNCTION_CANCEL:
		return FUNCTION_CANCEL;
	}

	system("pause");
	return FUNCTION_ERROR;
}