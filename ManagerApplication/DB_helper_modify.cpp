#include "DB_helper.h"

FNRETURN DBHelper::modify(ModifyType type)
{
	cout << ((type == MODIFY_DELETE) ? "\n�����Ͻðڽ��ϱ�?(y/n): " : "\n����Ͻðڽ��ϱ�?(y/n): ");
	switch (inputYN())
	{
	case FUNCTION_ERROR:
		cout << "\n�߸��� �Է��Դϴ�.\n";
		break;
	case FUNCTION_SUCCESS:
		if (SQL_SUCCESS == ((MODIFY_DELETE == type) ? del() : insert()))
		{
			cout << ((type == MODIFY_DELETE) ? "\n�����Ǿ����ϴ�.\n" : "\n��ϵǾ����ϴ�.\n");
			system("pause");
			return FUNCTION_SUCCESS;
		}
		else
		{
			cout << "\n������ �߻��߽��ϴ�.(DBHelper::modify)\n";
			break;
		}
	case FUNCTION_CANCEL:
		return FUNCTION_CANCEL;
	}

	system("pause");
	return FUNCTION_ERROR;
}