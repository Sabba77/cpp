#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/* ---------- helper ---------- */

static void	title(const std::string& s)
{
	std::cout << BOLD_CYAN << "\n========== " << s << " ==========" << RESET << std::endl;
}

// Crea un burocrate col grado dato, prova a firmare e poi a eseguire la form.
// La form va creata NUOVA dal chiamante per ogni caso (altrimenti risulta gia' firmata).
// signForm ed executeForm catturano gia' le eccezioni: qui non serve try/catch.
static void	runCase(AForm& form, int grade)
{
	Bureaucrat	b("Burocrate", grade);

	std::cout << std::endl << b << std::endl << form << std::endl;
	b.signForm(form);
	b.executeForm(form);
	std::cout << form << std::endl;
}

// execute() chiamata direttamente: le eccezioni escono, quindi qui il try/catch serve.
static void	tryExecute(const AForm& form, const Bureaucrat& b)
{
	try
	{
		form.execute(b);
		std::cout << "execute OK" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "execute error: " << e.what() << std::endl;
	}
}

/* ---------- test ---------- */

// Default constructor + new/delete tramite AForm* (controlla il distruttore virtuale)
// + esecuzione vera di tutte e tre le azioni.
static void	testPolymorphism()
{
	AForm*		forms[3];
	Bureaucrat	boss("Boss", 1);

	{
		ShrubberyCreationForm	d1;
		RobotomyRequestForm		d2;
		PresidentialPardonForm	d3;
		std::cout << d1 << std::endl << d2 << std::endl << d3 << std::endl;
	}
	forms[0] = new ShrubberyCreationForm("Poly");
	forms[1] = new RobotomyRequestForm("Poly");
	forms[2] = new PresidentialPardonForm("Poly");
	for (int i = 0; i < 3; i++)
	{
		boss.signForm(*forms[i]);
		boss.executeForm(*forms[i]);
	}
	for (int i = 0; i < 3; i++)
		delete forms[i];
}

// Shrubbery: firma 145, esecuzione 137
// 1, 137   -> firma ok, esecuzione ok (file creato)
// 138, 145 -> firma ok, esecuzione: grade too low
// 146      -> firma: grade too low, esecuzione: grade too low (il grado si controlla prima della firma)
static void	testShrubbery()
{
	const int	grades[] = {1, 137, 138, 145, 146};

	for (unsigned int i = 0; i < sizeof(grades) / sizeof(grades[0]); i++)
	{
		ShrubberyCreationForm	form("Peppe");
		runCase(form, grades[i]);
	}
}

// Robotomy: firma 72, esecuzione 45
// 1, 45    -> tutto ok (successo o fallimento a caso)
// 46, 72   -> firma ok, esecuzione: grade too low
// 73       -> firma: grade too low, esecuzione: grade too low
static void	testRobotomy()
{
	const int	grades[] = {1, 45, 46, 72, 73};

	for (unsigned int i = 0; i < sizeof(grades) / sizeof(grades[0]); i++)
	{
		RobotomyRequestForm	form("Pino");
		runCase(form, grades[i]);
	}

	std::cout << BOLD_CYAN << "\nLoop: 10 esecuzioni, circa metà successi e metà fallimenti" << RESET << std::endl;
	RobotomyRequestForm	form("Loop");
	Bureaucrat			b("Boss", 45);
	b.signForm(form);
	for (int i = 0; i < 10; i++)
		b.executeForm(form);
}

// Presidential: firma 25, esecuzione 5
// 1, 5     -> tutto ok
// 6, 25    -> firma ok, esecuzione: grade too low
// 26       -> firma: grade too low, esecuzione: grade too low
static void	testPresidential()
{
	const int	grades[] = {1, 5, 6, 25, 26};

	for (unsigned int i = 0; i < sizeof(grades) / sizeof(grades[0]); i++)
	{
		PresidentialPardonForm	form("Nino");
		runCase(form, grades[i]);
	}
}

// execute() diretta: ordine dei controlli (prima il grado, poi la firma)
static void	testExecute()
{
	PresidentialPardonForm	form("Nano");
	Bureaucrat				low("Low", 25);
	Bureaucrat				high("High", 5);

	std::cout << "Non firmata, grado troppo basso -> grade too low:" << std::endl;
	tryExecute(form, low);
	std::cout << "Non firmata, grado sufficiente -> not signed:" << std::endl;
	tryExecute(form, high);
	std::cout << "Firmata, grado sufficiente -> ok:" << std::endl;
	high.signForm(form);
	tryExecute(form, high);
}

// Copia e assegnazione: devono portarsi dietro _signed (e il target nelle figlie)
static void	testCopy()
{
	Bureaucrat				b("Sign", 5);
	PresidentialPardonForm	a("signForm");
	PresidentialPardonForm	c("noSignForm");

	std::cout << BOLD_CYAN << "Copy constructor (la copia deve risultare firmata)" << RESET << std::endl;
	b.signForm(a);
	PresidentialPardonForm	copy(a);
	std::cout << a << std::endl << copy << std::endl;

	std::cout << BOLD_CYAN << "Copy assignment (c deve diventare firmata)" << RESET << std::endl;
	std::cout << c << std::endl;
	c = a;
	std::cout << c << std::endl;

	std::cout << BOLD_CYAN << "Il target viene copiato? (deve comparire CopyTarget)" << RESET << std::endl;
	RobotomyRequestForm	r("CopyTarget");
	b.signForm(r);
	RobotomyRequestForm	rCopy(r);
	b.executeForm(rCopy);
}

// Il target contiene uno slash e la cartella non esiste: ofstream non apre il file.
// Atteso: firma ok, poi "couldn't execute ... because failed opening", nessun crash, nessun file creato.
static void	testFileError()
{
	ShrubberyCreationForm	bad("cartella_inesistente/home");

	runCase(bad, 1);
}

int	main(void)
{
	std::srand(std::time(NULL));

	title("TEST 0: default constructor, new/delete, polimorfismo");
	testPolymorphism();
	title("TEST 1: ShrubberyCreationForm");
	testShrubbery();
	title("TEST 2: RobotomyRequestForm");
	testRobotomy();
	title("TEST 3: PresidentialPardonForm");
	testPresidential();
	title("TEST 4: execute() diretta");
	testExecute();
	title("TEST 5: copia e assegnazione");
	testCopy();
	title("TEST 6: errore apertura file");
	testFileError();
	return 0;
}