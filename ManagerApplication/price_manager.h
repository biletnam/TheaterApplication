#pragma once
#include "price.h"

class PriceManager
{
public:
	PriceManager();
private:

	void checkAndDeletePrice();
	void addPrice();
};

