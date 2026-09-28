#include "Animal.hpp"

int main()
{
	std::cout << "========| Test 0: MAIN TEST |========" << std::endl << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}

	std::cout << "========| Test 1: ARRAY TEST |========" << std::endl << std::endl;
	{
		Animal* AnimalArray[10];
		for (int i = 0; i < 5; i++)
			AnimalArray[i] = new Dog();
		for (int i = 5; i < 10; i++)
			AnimalArray[i] = new Cat();
		for (int i = 0; i < 10; i++)
			AnimalArray[i]->makeSound();
		for (int i = 0; i < 10; i++)
			delete AnimalArray[i];
	}

	std::cout << "========| Test 2: DEEP COPY CONSTRUCTOR (DOG) |========" << std::endl << std::endl;
	{
		Dog a;
		a.getBrain()->setIdeas("PEPPE", 0);
		Dog b(a);
		std::cout << "Ideas should be the same:" << std::endl;
		std::cout << "idea a-> " << a.getBrain()->getIdeas(0) << std::endl;
		std::cout << "idea b-> " << b.getBrain()->getIdeas(0) << std::endl;
		std::cout << "Brain addresses should be different:" << std::endl;
		std::cout << "brain a-> " << a.getBrain() << std::endl;
		std::cout << "brain b-> " << b.getBrain() << std::endl;
		b.getBrain()->setIdeas("ANNA", 0);
		std::cout << "b should change, a should stay PEPPE:" << std::endl;
		std::cout << "idea a-> " << a.getBrain()->getIdeas(0) << std::endl;
		std::cout << "idea b-> " << b.getBrain()->getIdeas(0) << std::endl;
	}

	std::cout << "========| Test 3: DEEP COPY ASSIGNMENT (DOG) |========" << std::endl << std::endl;
	{
		Dog a;
		a.getBrain()->setIdeas("PEPPE", 0);
		Dog c;
		c = a;
		std::cout << "Ideas should be the same:" << std::endl;
		std::cout << "idea a-> " << a.getBrain()->getIdeas(0) << std::endl;
		std::cout << "idea c-> " << c.getBrain()->getIdeas(0) << std::endl;
		std::cout << "Brain addresses should be different:" << std::endl;
		std::cout << "brain a-> " << a.getBrain() << std::endl;
		std::cout << "brain c-> " << c.getBrain() << std::endl;
		c.getBrain()->setIdeas("ANNA", 0);
		std::cout << "c should change, a should stay PEPPE:" << std::endl;
		std::cout << "idea a-> " << a.getBrain()->getIdeas(0) << std::endl;
		std::cout << "idea c-> " << c.getBrain()->getIdeas(0) << std::endl;

		std::cout << "Self assignment (no Brain message expected):" << std::endl;
		Dog& ref = a;
		a = ref;
		std::cout << "idea a-> " << a.getBrain()->getIdeas(0) << std::endl;
	}

	std::cout << "========| Test 4: DEEP COPY (CAT) |========" << std::endl << std::endl;
	{
		Cat a;
		a.getBrain()->setIdeas("PEPPE", 0);
		Cat b(a);
		Cat c;
		c = a;
		std::cout << "brain a-> " << a.getBrain() << std::endl;
		std::cout << "brain b-> " << b.getBrain() << std::endl;
		std::cout << "brain c-> " << c.getBrain() << std::endl;
		b.getBrain()->setIdeas("ANNA", 0);
		c.getBrain()->setIdeas("LUCA", 0);
		std::cout << "a should stay PEPPE, b ANNA, c LUCA:" << std::endl;
		std::cout << "idea a-> " << a.getBrain()->getIdeas(0) << std::endl;
		std::cout << "idea b-> " << b.getBrain()->getIdeas(0) << std::endl;
		std::cout << "idea c-> " << c.getBrain()->getIdeas(0) << std::endl;
	}

	std::cout << "========| Test 5: COPY DESTROYED IN A SCOPE |========" << std::endl << std::endl;
	{
		Dog original;
		original.getBrain()->setIdeas("PEPPE", 0);
		{
			Dog copy(original);
			Dog assigned;
			assigned = original;
			std::cout << "Leaving the scope: only copy and assigned die" << std::endl;
		}
		std::cout << "original must still be readable:" << std::endl;
		std::cout << "idea original-> " << original.getBrain()->getIdeas(0) << std::endl;
	}

	std::cout << "========| Test 6: INDEX OUT OF RANGE |========" << std::endl << std::endl;
	{
		Cat cat;
		cat.getBrain()->setIdeas("PEPPE", 100);
		std::cout << "idea 100-> [" << cat.getBrain()->getIdeas(100) << "]" << std::endl;
	}

	return 0;
}