#include "Date.h"

int16_t getIndex(const int16_t lastIndex, const char* output)
{
	int16_t index;

	cout << output;
	cin >> index;

	if (index >= 0 && index <= lastIndex)
	{
		return index;
	}
	else if (cin.fail() == true)
	{
		cin.clear();
		cin.ignore(100, '\n');
	}

	return getIndex(lastIndex, output);
}

bool Date::choose()
{
	while (chooseYear() == true)
	{
		system("cls");
		cout << "������ ����: " << getYear() << "��\n";
		while (chooseMonth() == true)
		{
			system("cls");
			cout << "������ ����: " << getYear() << "��\n";
			cout << "������ ��: " << getMonth() << "��\n";
			if (chooseDay() == true)
			{
				return true;
			}
			else
			{
				break;
			}
		}
	}

	return false;
}

bool Date::chooseYear()
{
	int16_t index;

	// ���� ��¥
	Date today(getToday());

	// ���� ����
	const int16_t yearCnt = 2;
	const int16_t firstYear = today.getYear();

	cout << "\n0. ����" << endl;
	for (index = 1; index <= yearCnt; index++)
	{
		cout << index << ". 20" << firstYear + index - 1 << "��" << endl;
	}

	index = getIndex(yearCnt, "�߰��� ��¥�� ������ �����ϼ���: ");
	
	if (index == 0)
	{
		return false;
	}
	else
	{
		setYear(firstYear + index - 1);
		return true;
	}
}

bool Date::chooseMonth()
{
	// ���� ��¥
	Date today(getToday());

	// �� ����
	const int16_t firstMonth = 
		today.getYear() == this->getYear() ? today.getMonth() : 1;
	const int16_t monthCnt = 2;

	int16_t index;

	cout << "\n0. ����" << endl;
	for (index = 1; index <= monthCnt; index++)
	{
		cout << index << ". " << firstMonth + index - 1 << "��" << endl;
	}
	
	index = getIndex(monthCnt, "�߰��� ��¥�� ���� �����ϼ���: ");
	
	if (index == 0)
	{
		return false;
	}
	else
	{
		setMonth(firstMonth + index - 1);
		return true;
	}
}

bool Date::chooseDay()
{
	// ���� ��¥
	Date today(getToday());
	
	// �� ����
	const int16_t firstDay =
		(today.getMonth() == this->getMonth()) ? today.getDay() + 1 : 1;
	
	int16_t tmpDayCnt = 31;
	switch (this->getMonth())
	{
	case 4: case 6: case 9: case 11:
		tmpDayCnt = 30;
		break;
	case 2:
		tmpDayCnt = 29;
		break;
	default:
		break;
	}

	const int16_t dayCnt = tmpDayCnt;
	int16_t index;
	cout << "\n0. ����" << endl;
	for (index = 1; index <= dayCnt - firstDay + 1; index++)
	{
		cout << index << ". " << firstDay + index - 1 << "��" << endl;
	}

	if ((index = getIndex(dayCnt, "�߰��� ��¥�� ���� �����ϼ���: ")) == 0)
	{
		return false;
	}
	else
	{
		setDay(firstDay + index - 1);
		return true;
	}
}