#include "issue.h"

void Issue::showInfo()
{
	system("cls");

	cout << "\n�߱� ����:\n";

	// ��¥
	if (date != 0)
	{
		int year = date / 10000 + 2000;
		int month = (date % 10000) / 100;
		int day = (date % 100);
		cout << year << "�� "
			<< month << "�� "
			<< day << "��\n";
	}

	// ��ȭ
	if (movieCode != 0)
	{
		cout << "������ ��ȭ: " << movieTitle << endl;
	}

	// �ð�
	if (startTime != 0)
	{
		int hour = startTime / 100;
		int minute = startTime % 100;

		cout << hour << "�� " << minute << "��\n";
	}

	for (int i = 0; i < tickets.size(); i++)
	{
		Ticket ticket = tickets.at(i);
		cout << ticket.row << "�� "
			<< ticket.col << "�� "
			<< ticket.priceName << endl;
			
	}
}