#include "price.h"

void Price::initialize()
{
	code = 0;
}

void Price::show()
{
	cout << name << "(" << code << ") " << won << "¿ø\n";
}