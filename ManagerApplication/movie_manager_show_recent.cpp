#include "movie_manager.h"

void MovieManager::showRecent()
{
	cout << "�ֱ� ��ϵ� ��ȭ ���(10��)\n";
	
	Movie movie;
	movie.prepare(MDF_THEATER, L""
		"SELECT TOP 10 movie_code, title, director, age, year, running_time "
		"FROM Movie_internal;");
	movie.bindCol();
	if (FUNCTION_NULL == movie.showSelectResult())
	{
		cout << "��ϵ� ��ȭ�� �����ϴ�\n";
		system("pause");
	}
}
