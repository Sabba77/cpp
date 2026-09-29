#include "Animal.hpp"

int main()
{
	/* Animal a;
	Animal *b = new Animal(); */

	Animal* d = new Dog();
	d->makeSound();
	delete d;
	return 0;
}