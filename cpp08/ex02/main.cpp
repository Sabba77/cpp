#include "MutantStack.hpp"
#include <list>
#include <vector>
#include <cstddef>
#include <string>

int main()
{
	std::cout << BOLD_CYAN << "========== MAIN TEST ==========" << RESET << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(7);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << "mstack.size() = " << mstack.size()
			<< ", s.size() = " << s.size() << std::endl;
		std::cout << "mstack.top() = " << mstack.top()
			<< ", s.top() = " << s.top() << std::endl;
	}
	std::cout << BOLD_CYAN << "========== MAIN TEST WITH LIST ==========" << RESET << std::endl;
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(7);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int, std::list<int> > s(mstack);
		std::cout << "mstack.size() = " << mstack.size()
			<< ", s.size() = " << s.size() << std::endl;
		std::cout << "mstack.back() = " << mstack.back()
			<< ", s.top() = " << s.top() << std::endl;
	}
	std::cout << BOLD_CYAN << "\n========== EDGE CASES ==========\n" << RESET << std::endl;
	{
		std::cout << BOLD_CYAN << "--- empty stack ---" << RESET << std::endl;
		MutantStack<int> e;
		std::cout << YELLOW << "must be --> size = 0, empty = true, e.begin() == e.end()" << RESET << std::endl;
		std::cout << BLK_MAGENTA << "e.size() = " << e.size()
			<< " | e.empty() = " << std::boolalpha << e.empty()
			<< " | (e.begin() == e.end()) = " << (e.begin() == e.end())
			<< std::noboolalpha << RESET << std::endl;

		std::cout << YELLOW << "loop print nothing" << RESET << std::endl;
		MutantStack<int>::iterator	itE = e.begin();
		for (; itE != e.end(); itE++)
			std::cout << *itE << std::endl;

		std::cout<< YELLOW << "loop print 42, itE == e.end()" << RESET << std::endl;
		e.push(42);
		//fill with other push()
		for (itE = e.begin(); itE != e.end(); itE++)
			std::cout << "*itE = " << *itE << std::endl;
		std::cout << BLK_MAGENTA << "(itE == e.end()) = " << std::boolalpha << (itE == e.end())
			<< std::noboolalpha << RESET << std::endl;
	}
	std::cout << BOLD_CYAN << "\n========== STRESS CASE AND ITERATOR ==========\n" << RESET << std::endl;
	{
		std::cout << BOLD_CYAN << "--- stress case ---" << RESET << std::endl;
		MutantStack<int>	s;
		std::vector<int>	v;
		std::cout << YELLOW << "fill stack and vector, in parallel, with 10000 int" << RESET << std::endl;
		for (int j = 0; j < 10000; j++)
		{
			s.push(j);
			v.push_back(j);
		}

		std::cout << YELLOW << "*itS == *itV" << RESET << std::endl;
		MutantStack<int>::iterator	itS = s.begin();
		std::vector<int>::iterator	itV = v.begin();
		size_t i;
		for (i = 0; i < 10000; i++)
		{
			if (*itS != *itV)
			{
				std::cout << RED << "impossible error: stack != vector!" << RESET << std::endl;
				return 0;
			}
			itS++;
			itV++;
		}
		std::cout << YELLOW << "test decrement" << RESET << std::endl;
		--itS;
		--itV;
		std::cout << *itS << std::endl << *itV << std::endl;
		std::cout << YELLOW
			<< "i == s.size() && i == v.size() && (s.end() - s.begin() == v.end() - v.begin())"
			<< RESET << std::endl;
		std::cout << BLK_MAGENTA << std::boolalpha
			<< (i == s.size() && i == v.size() && (s.end() - s.begin() == v.end() - v.begin()))
			<< std::noboolalpha << RESET << std::endl;

		std::cout << YELLOW << "the last one must be = top()" << RESET << std::endl;
		std::cout << BLK_MAGENTA << std::boolalpha
			<< "(*itS == *itV == s.top() == v.back()) = " << (*itS == s.top() && *itV == v.back())
			<< std::noboolalpha << RESET << std::endl;
		
		std::cout << BOLD_CYAN << "--- double numbers, must be X2 ---" << RESET << std::endl;
		for (itS = s.begin(); itS < s.end(); itS++)
			*itS *= 2;
		std::cout << YELLOW << "must be double" << RESET << std::endl;
		itS = s.begin();
		std::cout << BLK_MAGENTA << "itS + 5000 = " << *(itS + 5000)
			<< ", s.top() = " << s.top() << RESET << std::endl;

		std::cout << YELLOW << "itS + 2 must increment it by 2" << RESET << std::endl;
		std::cout << BLK_MAGENTA << "*itS = " << *itS;
		itS += 2;
		std::cout << " | itS + 2 --> *itS = " << *itS << RESET << std::endl;
	}
	std::cout << BOLD_CYAN << "\n========== CONST MUTANTSTACK ==========\n" << RESET << std::endl;
	{
		std::cout << BOLD_CYAN << "--- can be use, but not modify ---" << RESET << std::endl;
		MutantStack<int>	copyS;
		for (int i = 0; i <= 42; i++)
			copyS.push(i);
		const MutantStack<int>	constS(copyS);
		MutantStack<int>::const_iterator	cItS = constS.begin();
		for (; cItS < constS.end(); cItS++)
			std::cout << *cItS << std::endl;
		/* cItS = constS.begin() + 40;
		*cItS += 2;
		std::cout << *(cItS + 2) << std::endl;
		std::cout << *cItS << std::endl; */
	}
	std::cout << BOLD_CYAN << "\n========== OCF TEST ==========\n" << RESET << std::endl;
	{
		MutantStack<int>	a;
		a.push(7);
		a.push(77);
		a.push(777);
		MutantStack<int>	b(a);
		MutantStack<int>	c;
		c = b;
		std::cout << BLK_MAGENTA
			<< "a.top() = " << a.top() << " | b.top() = " << b.top() << " | c.top() = " << c.top()
			<< RESET << std::endl;
		//a.top() = a.top() + 3;
		a.pop();
		std::cout << YELLOW << "only a has changed" << std::endl << BLK_MAGENTA
			<< "a.top() = " << a.top() << " | b.top() = " << b.top() << " | c.top() = " << c.top()
			<< RESET << std::endl;
		
		std::cout << YELLOW << "auto assignment a = a, no change" << RESET << std::endl;
		a = a;
		std::cout << a.top() << std::endl;
	}
	std::cout << BOLD_CYAN << "\n========== OTHER TYPE TEST (string)==========\n" << RESET << std::endl;
	{
		MutantStack<std::string>	sS;
		sS.push("cracra");
		sS.push("oink");
		sS.push("miao");
		sS.push("bau");
		MutantStack<std::string>::iterator	its = sS.begin();
		for (; its < sS.end(); its++)
			std::cout << BLK_MAGENTA << "*its = " << *its << " --> its->size() = " << its->size() << RESET << std::endl;
	}
	return 0;
}