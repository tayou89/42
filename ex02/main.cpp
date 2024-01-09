#include "MutantStack.hpp"
#include <iostream>

void	testMutantStack1(void);
void	testList(void);

int main()
{
	testMutantStack1();
	testList();
	return (0);
}

void	testMutantStack1(void)
{
	std::cout << "\n=============== MutantStack Test 1 ===============\n";
	MutantStack<int> mstack;

	mstack.push(5); 
	mstack.push(17);

	std::cout << mstack.top() << std::endl; 

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3); 
	mstack.push(5); 
	mstack.push(737); 

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
}

#include <list>

void	testList(void)
{
	std::cout << "\n=============== List Test ===============\n";
	std::list<int> mstack;

	mstack.push_back(5); 
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl; 

	mstack.pop_back();

	std::cout << mstack.size() << std::endl;

	mstack.push_back(3); 
	mstack.push_back(5); 
	mstack.push_back(737); 

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
}

#include <vector>

void	testMutantStack2(void)
{
	typedef MutantStack<int, std::vector<int> >	VectorStack;	

	int					array[] = { 5, 4, 2, 100, 30, 20, -6 };
	std::vector<int>	vector(array, array + sizeof(array) / sizeof(int));
	const VectorStack	constVectorStack(vector);
	MutantStack<int>	mutantStack;
}