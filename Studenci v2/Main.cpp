#include "Interface.h"

int main()
{
	Interface* i = new Interface();
	i->run();
	delete i;
	return 0;
}