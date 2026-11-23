#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : v(), l(), vTime(0), lTime(0), count(0), before()
{
}

PmergeMe::PmergeMe(const PmergeMe& other) : v(), l(), vTime(0), lTime(0), count(0), before()
{
	if (this != &other)
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
		if (av[i][0] == '\0')
			throw ErrorException("Error: inputs are empty!");
		for (int j = 0; av[i][j]; j++)
			if (!std::isdigit(static_cast<unsigned char>(av[i][j])))
				throw ErrorException("Error: only digits are accepted!");

		errno = 0;
		char*	end = NULL;
		long	value = std::strtol(av[i], &end, 10);
		if (errno == ERANGE || value > INT_MAX)
			throw ErrorException("Error: value is out of range (overflow)!");

		oss << value;
		if (i != ac - 1)
			oss << " ";
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
	size_t	prev = 0;	// J(0)
	size_t	curr = 1;	// J(1)

	if (n == 0)
		return 0;
	for (size_t i = 1; i < n; i++)
	{
		size_t	next = curr + 2 * prev;
		prev = curr;
		curr = next;
	}
	return curr;
}

size_t	PmergeMe::binaryInsertionVector(std::vector<int>& chain, int value, size_t end)
{
	size_t	low = 0;
	size_t	high = end;

	while (low < high)
	{
		size_t	mid = low + (high - low) / 2;
		if (chain[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}
	chain.insert(chain.begin() + low, value);
	return low;
}

void	PmergeMe::sortVector(std::vector<int>& vec)
{
	// Block 1: base case
	if (vec.size() <= 1)
		return;

	// Block 2: build the pairs (first = larger, second = smaller), keep the straggler apart
	bool	hasStraggler = (vec.size() % 2 != 0);
	int		straggler = hasStraggler ? vec.back() : 0;

	std::vector<std::pair<int, int> >	pairs;
	std::vector<int>					mainChain;
	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		if (pairs.back().first < pairs.back().second)
			std::swap(pairs.back().first, pairs.back().second);
		mainChain.push_back(pairs.back().first);
	}

	// Block 3: sort the larger elements recursively
	sortVector(mainChain);

	// Block 4: find the partner of each sorted larger element (pend[i] <= mainChain[i])
	std::vector<bool>	used(pairs.size(), false);
	std::vector<int>	pend;
	for (size_t i = 0; i < mainChain.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (!used[j] && pairs[j].first == mainChain[i])
			{
				used[j] = true;
				pend.push_back(pairs[j].second);
				break;
			}
		}
	}
	if (hasStraggler)
		pend.push_back(straggler);	// last pend element, it has no partner

	// Block 5: initial chain (b1 goes first for free) and positions of the larger elements
	std::vector<int>	chain = mainChain;
	chain.insert(chain.begin(), pend[0]);
	std::vector<size_t>	pos(mainChain.size());
	for (size_t i = 0; i < pos.size(); i++)
		pos[i] = i + 1;		// b1 in front shifted every larger element by one

	// Blocks 6-7: insert the remaining pend elements in Jacobsthal order (1-based indexes)
	size_t	prev = 1;
	size_t	n = 3;
	while (prev < pend.size())
	{
		size_t	curr = jacobsthal(n);
		size_t	top = std::min(curr, pend.size());
		for (size_t idx = top; idx > prev; idx--)
		{
			// search only before the partner; the straggler has no partner: whole chain
			size_t	limit = (idx - 1 < mainChain.size()) ? pos[idx - 1] : chain.size();
			size_t	ins = binaryInsertionVector(chain, pend[idx - 1], limit);
			for (size_t j = 0; j < pos.size(); j++)
				if (pos[j] >= ins)
					pos[j]++;
		}
		prev = curr;
		n++;
	}
	// Block 8: the final chain is the sorted sequence
	vec = chain;
}

std::list<int>::iterator	PmergeMe::binaryInsertionList(std::list<int>& chain, int value, std::list<int>::iterator end)
{
	std::list<int>::iterator	low = chain.begin();
	size_t						count = static_cast<size_t>(std::distance(chain.begin(), end));

	while (count > 0)
	{
		size_t						step = count / 2;
		std::list<int>::iterator	mid = low;
		std::advance(mid, step);
		if (*mid < value)
		{
			low = ++mid;
			count -= step + 1;
		}
		else
			count = step;
	}
	return chain.insert(low, value);
}

void	PmergeMe::sortList(std::list<int>& lis)
{
	typedef std::list<int>::iterator	listIt;
	typedef std::pair<int, listIt>		pendItem;

	// Block 1: base case
	if (lis.size() <= 1)
		return;

	// Block 2: build the pairs (first = larger, second = smaller), keep the straggler apart
	bool	hasStraggler = (lis.size() % 2 != 0);
	int		straggler = hasStraggler ? lis.back() : 0;

	std::list<std::pair<int, int> >	pairs;
	std::list<int>					chain;
	listIt							it = lis.begin();
	while (it != lis.end())
	{
		int	first = *it;
		++it;
		if (it == lis.end())
			break;		// odd element: it is the straggler
		int	second = *it;
		++it;
		if (first < second)
			std::swap(first, second);
		pairs.push_back(std::make_pair(first, second));
		chain.push_back(first);
	}

	// Block 3: sort the larger elements recursively
	sortList(chain);

	// Block 4: for each sorted larger element store (its partner, iterator to the larger one in chain)
	std::list<pendItem>	pend;
	for (listIt c = chain.begin(); c != chain.end(); ++c)
	{
		for (std::list<std::pair<int, int> >::iterator p = pairs.begin(); p != pairs.end(); ++p)
		{
			if (p->first == *c)
			{
				pend.push_back(std::make_pair(p->second, c));
				pairs.erase(p);		// this pair is consumed (handles duplicates)
				break;
			}
		}
	}
	if (hasStraggler)
		pend.push_back(std::make_pair(straggler, chain.end()));	// end() = search in the whole chain

	// Block 5: b1 goes first for free (list iterators stay valid)
	chain.push_front(pend.front().first);

	// Blocks 6-7: insert the remaining pend elements in Jacobsthal order (1-based indexes)
	size_t	prev = 1;
	size_t	n = 3;
	while (prev < pend.size())
	{
		size_t	curr = jacobsthal(n);
		size_t	top = std::min(curr, pend.size());

		std::list<pendItem>::iterator	p = pend.begin();
		std::advance(p, top - 1);
		for (size_t idx = top; idx > prev; idx--)
		{
			binaryInsertionList(chain, p->first, p->second);
			if (idx > prev + 1)
				--p;
		}
		prev = curr;
		n++;
	}

	// Block 8: the final chain is the sorted sequence
	lis.swap(chain);
}

PmergeMe::PmergeMe(int ac, char** av) : v(), l(), vTime(0), lTime(0), count(0), before()
{
	parser(ac, av);

	double	start = timing();
	for (int i = 1; i < ac; i++)
		this->v.push_back(std::strtol(av[i], NULL, 10));
	sortVector(this->v);
	double	end = timing();
	this->vTime = end - start;
	
	start = timing();
	for (int i = 1; i < ac; i++)
		this->l.push_back(std::strtol(av[i], NULL, 10));
	sortList(this->l);
	end = timing();
	this->lTime = end - start;
}

void	PmergeMe::printBefore() const
{
	std::cout << "Before: " << this->before << std::endl;
}

void	PmergeMe::printAfter() const
{
	std::cout << "After: ";
	for (std::vector<int>::const_iterator it = this->v.begin(); it != this->v.end(); ++it)
	{
		if (it != this->v.begin())
			std::cout << " ";
		std::cout << *it;
	}
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