#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	std::cout << BOLD_CYAN << "--- Subject ---" << RESET << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}
	std::cout << BOLD_CYAN << std::endl << "--- Wrong ---" << RESET << std::endl;
	{
		const WrongAnimal* w = new WrongCat();
		const WrongCat* c = new WrongCat();

		w->makeSound();	// suono di WrongAnimal (no virtual)
		c->makeSound();	// suono di WrongCat
		delete w;
		delete c;
	}
	std::cout << BOLD_CYAN << std::endl << "--- Array ---" << RESET << std::endl;
	{
		const Animal* zoo[4];

		for (int k = 0; k < 4; k++)
			zoo[k] = (k % 2) ? static_cast<const Animal*>(new Cat())
							 : static_cast<const Animal*>(new Dog());
		for (int k = 0; k < 4; k++)
			zoo[k]->makeSound();
		for (int k = 0; k < 4; k++)
			delete zoo[k];
	}
	std::cout << BOLD_CYAN << std::endl << "--- Copy ---" << RESET << std::endl;
	{
		Dog d1;
		Dog d2(d1);
		Cat c1;
		Cat c2;

		c2 = c1;
		std::cout << d2.getType() << " " << c2.getType() << std::endl;
	}
	return 0;
}