#ifndef PRICE_MANAGER_H
#define PRICE_MANAGER_H

#include "price.h"

class PriceManager
{
public:
	PriceManager();
private:
	void checkAndDeletePrice();
	void addPrice();
};

#endif // !PRICE_MANAGER_H