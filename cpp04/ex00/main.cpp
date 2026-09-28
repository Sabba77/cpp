#include "Animal.hpp"
#include "WrongAnimal.hpp"

int	main()
{
	std::cout << "--- Subject ---" << std::endl;
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
	std::cout << std::endl << "--- Wrong ---" << std::endl;
	{
		const WrongAnimal* w = new WrongCat();
		const WrongCat* c = new WrongCat();

		w->makeSound();	// suono di WrongAnimal (no virtual)
		c->makeSound();	// suono di WrongCat
		delete w;
		delete c;
	}
	std::cout << std::endl << "--- Array ---" << std::endl;
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
	std::cout << std::endl << "--- Copy ---" << std::endl;
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