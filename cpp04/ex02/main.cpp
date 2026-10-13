#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	/* Animal a;
	Animal *b = new Animal(); */

	Animal* d = new Dog();
	d->makeSound();
	delete d;
	return 0;
}