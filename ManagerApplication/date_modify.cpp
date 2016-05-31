#include "date.h"

FNRETURN Date::modify(ModifyType type)
{
	if (value > 0)
	{
		cout << "������ ��¥ ����:\n";
		show();
		cout << ((type == MODIFY_DELETE) ? "\n�����Ͻðڽ��ϱ�?(y/n): " : "\n����Ͻðڽ��ϱ�?(y/n): ");
		char yn;
		switch (inputYN(yn))
		{
		case FUNCTION_ERROR:
			cout << "\n�߸��� �Է��Դϴ�.\n";
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
					cout << ((type == MODIFY_DELETE) ? "\n�����Ǿ����ϴ�.\n" : "\n��ϵǾ����ϴ�.\n");
					system("pause");
				}
				else
				{
					cout << "\n������ �߻��߽��ϴ�.(Date::modify)\n";
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