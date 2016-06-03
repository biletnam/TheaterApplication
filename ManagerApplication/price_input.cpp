#include "price.h"

FNRETURN Price::input()
{
	if (0 == code)
	{
		return inputCode();
	}
	else if (0 == *name)
	{
		switch (inputName())
		{
		case FUNCTION_CANCEL:
			code = 0;
		case FUNCTION_SUCCESS:
			return FUNCTION_SUCCESS;
		case FUNCTION_ERROR:
			*name = 0;
		}
	}
	else if (-1 == won)
	{
		switch (inputWon())
		{
		case FUNCTION_CANCEL:
			*name = 0;
		case FUNCTION_SUCCESS:
			return FUNCTION_SUCCESS;
		case FUNCTION_ERROR:
			won = -1;
		}
	}

	return FUNCTION_ERROR;
}

FNRETURN Price::inputCode()
{
	cout << "���� �ڵ带 �Է��ϼ���(0�� �Է��ϸ� ����): ";

	int32_t code;
	if (FUNCTION_CANCEL == inputPositiveInteger(code))
	{
		return FUNCTION_CANCEL;
	}
	else
	{
		this->code = code;
	}
	
	bindParameter(MDF_THEATER, PRICE_CODE);
	execute(MDF_THEATER, L"SELECT * FROM price WHERE code=?;");

	switch (fetch(MDF_THEATER))
	{
	case SQL_SUCCESS:
		cout << "�̹� �����ϴ� ���� �ڵ��Դϴ�.\n";
		break;
	case SQL_NO_DATA:
		return FUNCTION_SUCCESS;
	default:
		cout << "������ �߻��߽��ϴ�.\n";
	}

	system("pause");
	return FUNCTION_ERROR;
}

FNRETURN Price::inputName()
{
	cout << "���� �̸��� �Է��ϼ���(0�� �Է��ϸ� ����): ";
	wcin >> name;

	if (wcscmp(name, L"0") == 0)
	{
		return FUNCTION_CANCEL;
	}

	return FUNCTION_SUCCESS;
}

FNRETURN Price::inputWon()
{
	cout << "����(��)�� �Է��ϼ���(0�� �Է��ϸ� ����): ";
	
	int32_t won;
	if (FUNCTION_CANCEL == inputPositiveInteger(won) )
	{
		return FUNCTION_CANCEL;
	}

	return FUNCTION_SUCCESS;
}
