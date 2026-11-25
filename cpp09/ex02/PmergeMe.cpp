#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : v(), l(), vTime(0), lTime(0), count(0), before()
{
}

PmergeMe::PmergeMe(const PmergeMe& other) : v(), l(), vTime(0), lTime(0), count(0), before()
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		v = other.v;
		l = other.l;
		vTime = other.vTime;
		lTime = other.lTime;
		count = other.count;
		before = other.before;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void	PmergeMe::parser(int ac, char** av)
{
	if (ac < 2)
		throw ErrorException("Error: at least 1 positive integer!");

	std::ostringstream	oss;
	for (int i = 1; i < ac; i++)
	{
		std::string	arg(av[i]);
		if (arg.empty() || arg.find_first_not_of("0123456789") != std::string::npos)
			throw ErrorException("Error: only positive integers are accepted!");

		errno = 0;
		long	value = std::strtol(av[i], NULL, 10);
		if (errno == ERANGE || value > INT_MAX)
			throw ErrorException("Error: value is out of range (overflow)!");

		oss << (i > 1 ? " " : "") << value;
		this->count++;
	}
	this->before = oss.str();
}

double	PmergeMe::timing()
{
	return ((static_cast<double>(std::clock()) / CLOCKS_PER_SEC) * 1000000);
}

size_t	PmergeMe::jacobsthal(size_t n)
{
	size_t	p = static_cast<size_t>(1) << n;	// 2^n

	return ((n % 2 ? p + 1 : p - 1) / 3);
}

void	PmergeMe::sortVector(std::vector<int>& vec)
{
	if (vec.size() <= 1)
		return;

	// pairs (first = larger, second = smaller); the larger elements are sorted recursively
	std::vector<std::pair<int, int> >	pairs;
	std::vector<int>					mainChain;
	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		if (pairs.back().first < pairs.back().second)
			std::swap(pairs.back().first, pairs.back().second);
		mainChain.push_back(pairs.back().first);
	}
	sortVector(mainChain);

	// pend[i] = partner of mainChain[i]; the straggler (odd size) goes last and has no partner
	std::vector<int>	pend;
	for (size_t i = 0; i < mainChain.size(); i++)
		for (size_t j = 0; j < pairs.size(); j++)
			if (pairs[j].first == mainChain[i])
			{
				pend.push_back(pairs[j].second);
				pairs.erase(pairs.begin() + j);
				break;
			}
	if (vec.size() % 2)
		pend.push_back(vec.back());

	// pos[i] = index in chain of the partner of pend[i] (for the straggler: the end of the chain)
	std::vector<int>	chain = mainChain;
	std::vector<size_t>	pos(pend.size());
	for (size_t i = 0; i < pos.size(); i++)
		pos[i] = i;

	// insert the pend elements in Jacobsthal order, each one before its partner (1-based idx)
	size_t	prev = 0;
	for (size_t n = 2; prev < pend.size(); n++)
	{
		size_t	curr = jacobsthal(n);
		for (size_t idx = std::min(curr, pend.size()); idx > prev; idx--)
		{
			size_t	ins = std::lower_bound(chain.begin(), chain.begin() + pos[idx - 1], pend[idx - 1]) - chain.begin();
			chain.insert(chain.begin() + ins, pend[idx - 1]);
			for (size_t j = 0; j < pos.size(); j++)
				if (pos[j] >= ins)
					pos[j]++;
		}
		prev = curr;
	}
	vec = chain;
}

void	PmergeMe::sortList(std::list<int>& lis)
{
	typedef std::list<int>::iterator					listIt;
	typedef std::list<std::pair<int, int> >::iterator	pairIt;
	typedef std::pair<int, listIt>						pendItem;

	if (lis.size() <= 1)
		return;

	// pairs (first = larger, second = smaller); the larger elements are sorted recursively
	std::list<std::pair<int, int> >	pairs;
	std::list<int>					chain;
	listIt							it = lis.begin();
	while (it != lis.end())
	{
		int	first = *it++;
		if (it == lis.end())
			break;
		int	second = *it++;
		if (first < second)
			std::swap(first, second);
		pairs.push_back(std::make_pair(first, second));
		chain.push_back(first);
	}
	sortList(chain);

	// pend: (partner, iterator to its larger element in chain); the straggler gets chain.end()
	std::list<pendItem>	pend;
	for (listIt c = chain.begin(); c != chain.end(); ++c)
		for (pairIt p = pairs.begin(); p != pairs.end(); ++p)
			if (p->first == *c)
			{
				pend.push_back(std::make_pair(p->second, c));
				pairs.erase(p);
				break;
			}
	if (lis.size() % 2)
		pend.push_back(std::make_pair(lis.back(), chain.end()));

	// insert the pend elements in Jacobsthal order, each one before its partner (1-based idx)
	size_t	prev = 0;
	for (size_t n = 2; prev < pend.size(); n++)
	{
		size_t							curr = jacobsthal(n);
		size_t							top = std::min(curr, pend.size());
		std::list<pendItem>::iterator	p = pend.begin();

		std::advance(p, top - 1);
		for (size_t idx = top; idx > prev; idx--)
		{
			chain.insert(std::lower_bound(chain.begin(), p->second, p->first), p->first);
			if (idx > prev + 1)
				--p;
		}
		prev = curr;
	}
	lis.swap(chain);
}

PmergeMe::PmergeMe(int ac, char** av) : v(), l(), vTime(0), lTime(0), count(0), before()
{
	parser(ac, av);

	double	start = timing();
	for (int i = 1; i < ac; i++)
		this->v.push_back(std::strtol(av[i], NULL, 10));
	sortVector(this->v);
	this->vTime = timing() - start;

	start = timing();
	for (int i = 1; i < ac; i++)
		this->l.push_back(std::strtol(av[i], NULL, 10));
	sortList(this->l);
	this->lTime = timing() - start;
}

void	PmergeMe::printBefore() const
{
	std::cout << "Before: " << this->before << std::endl;
}

void	PmergeMe::printAfter() const
{
	std::cout << "After: ";
	for (std::vector<int>::const_iterator it = this->v.begin(); it != this->v.end(); ++it)
		std::cout << (it != this->v.begin() ? " " : "") << *it;
	std::cout << std::endl;
}

void	PmergeMe::printVectorTime() const
{
	std::cout << "Time to process a range of " << this->count << " elements with std::vector : "
		<< std::fixed << std::setprecision(5) << this->vTime << " us" << std::endl;
}

void	PmergeMe::printListTime() const
{
	std::cout << "Time to process a range of " << this->count << " elements with std::list   : "
		<< std::fixed << std::setprecision(5) << this->lTime << " us" << std::endl;
}