#include "AMateria.hpp"

int main()
{

	std::cout << "========== TEST 0: main test ==========" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}

	std::cout << std::endl << "========== TEST 1: clone() and polimorfism test ==========" << std::endl;
	{
		AMateria*	a = new Ice();
		AMateria* aClone = a->clone();
		std::cout << "Materia a is : " << a->getType() << std::endl;
		std::cout << "Materia aClone is : " << aClone->getType() << std::endl;
		std::cout << "a address      : " << a << std::endl;
		std::cout << "aClone address : " << aClone << std::endl;
		std::cout << std::endl;

		AMateria* b = new Cure();
		AMateria* bClone = b->clone();
		std::cout << "Materia b is : " << b->getType() << std::endl;
		std::cout << "Materia bClone is : " << bClone->getType() << std::endl;
		std::cout << "b address      : " << b << std::endl;
		std::cout << "bClone address : " << bClone << std::endl;
		delete a;
		delete aClone;
		delete b;
		delete bClone;
	}

	std::cout << std::endl << "========== TEST 2: equip() full inventory and NULL materia ==========" << std::endl;
	{
		std::cout << "full inventory test :" << std::endl;
		AMateria* materia1 = new Ice();
		AMateria*	materia2 = new Ice();
		AMateria*	materia3 = new Ice();
		AMateria*	materia4 = new Ice();
		AMateria*	materia5 = new Cure();
		ICharacter* peppe = new Character("peppe");
		peppe->equip(materia1);
		peppe->equip(materia2);
		peppe->equip(materia3);
		peppe->equip(materia4);
		peppe->equip(materia5);
		
		ICharacter* anna = new Character("anna");
		peppe->use(0, *anna);
		peppe->use(1, *anna);
		peppe->use(2, *anna);
		peppe->use(3, *anna);
		peppe->use(4, *anna);
		
		std::cout << std::endl << "equip(0) - equip(NULL) test :" << std::endl;
		peppe->equip(NULL);
		peppe->equip(0);
		std::cout << std::endl;

		delete materia5;
		delete peppe;
		delete anna;
	}

	std::cout << std::endl << "========== TEST 3 - 4: unequip() and reuse - use() out range ==========" << std::endl;
	{
		std::cout << std::endl << "unequip() and reuse test :" << std::endl;
		AMateria* a = new Ice();
		ICharacter* peppe = new Character("peppe");
		ICharacter* anna = new Character("anna");
		peppe->equip(a);
		peppe->use(0, *anna);
		peppe->unequip(0);
		peppe->use(0, *anna);
		anna->equip(a);
		anna->use(0, *peppe);
		std::cout << std::endl << "use() out range test :" << std::endl;
		anna->use(2, *peppe);
		anna->use(99, *peppe);
		delete peppe;
		delete anna;
	}

	std::cout << std::endl << "========== TEST 5: deep copy: copy constructor e operator= ==========" << std::endl;
	{
		std::cout << std::endl << "copy constructor :" << std::endl;
		Character	*peppe = new Character("peppe");
		peppe->equip(new Ice());
		peppe->equip(new Cure());
		ICharacter* nino = new Character(*peppe);
		delete peppe;
		ICharacter* marco = new Character("marco");
		nino->use(0, *marco);
		nino->use(1, *marco);

		delete nino;
		delete marco;

		
		std::cout << std::endl << "assignment operator :" << std::endl;
		Character*	pino = new Character("pino");
		pino->equip(new Ice());
		pino->equip(new Cure());
		Character* caio = new Character("caio");
		caio->equip(new Ice());
		caio->equip(new Ice());
		*caio = *pino;
		delete pino;
		ICharacter* gino = new Character("gino");
		caio->use(0, *gino);
		caio->use(1, *gino);

		delete caio;
		delete gino;
	}

	std::cout << std::endl << "========== TEST 6 : MateriaSource: full inventory and equip(unknown) ==========" << std::endl;
	{
		IMateriaSource* src2 = new MateriaSource();
		src2->learnMateria(new Ice());
		src2->learnMateria(new Cure());
		src2->learnMateria(new Ice());
		src2->learnMateria(new Cure());
		src2->learnMateria(new Ice()); // quinta: nessuno slot libero, deve essere scartata senza crash

		ICharacter* test = new Character("test");
		test->equip(src2->createMateria("ice"));
		test->equip(src2->createMateria("cure"));
		test->equip(src2->createMateria("ice"));
		test->equip(src2->createMateria("cure"));

		ICharacter* target = new Character("target");
		test->use(0, *target);
		test->use(1, *target);
		test->use(2, *target);
		test->use(3, *target);

		AMateria* unknown = src2->createMateria("fire");
		std::cout << "createMateria(\"fire\") = "
				<< (unknown == NULL ? "NULL (corretto)" : "NON NULL (errore)") << std::endl;

		test->equip(unknown); // deve stampare solo il messaggio dedicato, senza crash

		delete test;
		delete target;
		delete src2;
	}

	return 0;
}