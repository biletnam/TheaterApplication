#include "price.h"

void Price::initialize()
{
	code = 0;
}

void Price::show()
{
	wcout << name;
	cout << "(" << code << ") " << won << "¿ø\n";
}