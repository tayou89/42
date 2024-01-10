#include "MutantStack.hpp"
#include <iostream>

void testMutantStack1(void);
void testList(void);
void testMutantStack2(void);

int main()
{
	testMutantStack1();
	testList();
	testMutantStack2();
	return (0);
}

void testMutantStack1(void)
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

void testList(void)
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

void testMutantStack2(void)
{
	std::cout << "\n=============== MutantStack Test 1 ===============\n";
	typedef MutantStack<int, std::vector<int> > VectorStack;

	int array[] = {5, 4, 2, 100, 30, 20, -6};
	std::vector<int> vector(array, array + sizeof(array) / sizeof(int));
	const VectorStack constVectorStack(vector);
	MutantStack<int> mutantStack;

	mutantStack.push(5);
	mutantStack.push(4);
	mutantStack.push(2);
	mutantStack.push(100);
	mutantStack.push(30);
	mutantStack.push(20);
	mutantStack.push(-6);

	MutantStack<int>::reverse_iterator reverseBegin = mutantStack.rbegin();
	MutantStack<int>::reverse_iterator reverseEnd = mutantStack.rend();

	std::cout << "*reverseBegin: " << *reverseBegin << '\n';
	std::cout << "*(++reverseBegin): " << *(++reverseBegin) << '\n';
	std::cout << "*(--reverseEnd): " << *(--reverseEnd) << '\n';
	std::cout << "*(--reverseEnd): " << *(--reverseEnd) << '\n';
	
	VectorStack::const_iterator	constBegin = constVectorStack.begin();
	VectorStack::const_iterator	constEnd = constVectorStack.end();
	
	std::cout << "*constBegin: " << *constBegin << '\n';
	std::cout << "*(++constBegin): " << *(++constBegin) << '\n';
	std::cout << "*(++constBegin): " << *(++constBegin) << '\n';
	std::cout << "*(--constEnd): " << *(--constEnd) << '\n';
	//*constBegin = 4;
}