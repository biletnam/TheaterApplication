#include "DB_helper.h"

FNRETURN DBHelper::showSelectResult(MdfEnum mdf)
{
	if (SQL_SUCCESS == execute(mdf))
	{
		cout << endl;
		for (size_t i = 1;; i++)
		{
			switch (fetch(mdf))
			{
			case SQL_SUCCESS:
				cout << i << ". ";
				show();
				continue;
			case SQL_NO_DATA:
				if (i == 1)
				{
					return FUNCTION_NULL;
				}
				else
				{
					return FUNCTION_SUCCESS;
				}
			}
			break;
		}
	}

	cout << "오류가 발생했습니다.(showSelectResult)\n";
	system("pause");
	return FUNCTION_ERROR;
}