#include "MutantStack.hpp"
#include <iostream>

void	testMutantStack1(void);
void	testList(void);
void	testMutantStack2(void);

int main()
{
	testMutantStack1();
	testList();
	testMutantStack2();
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
	std::cout << "\n=============== MutantStack Test 2 ===============\n";
	typedef MutantStack<int, std::vector<int> >	VectorStack;	

	int					array[] = { 5, 4, 2, 100, 30, 20, -6 };
	std::vector<int>	vector(array, array + sizeof(array) / sizeof(int));
	VectorStack			vectorStack(vector);	

	std::cout << "vector = { ";
	for (VectorStack::iterator iter = vector.begin(); iter != vector.end(); iter++)
		std::cout << *iter << ", ";
	std::cout << "}\n\n";

	const VectorStack	constVectorStack(vector);
	std::cout << "vector was put into stack.\n\n";

	std::cout << "< Stack iterator result >\n";

	VectorStack::reverse_iterator	reverseBegin = vectorStack.rbegin();
	VectorStack::reverse_iterator	reverseEnd = vectorStack.rend();
	
	std::cout << "*reverseBegin: " << *reverseBegin << '\n';
	std::cout << "*(++reverseBegin): " << *(++reverseBegin) << '\n';
	std::cout << "*(--reverseEnd): " << *(--reverseEnd) << '\n';

	VectorStack::const_iterator	constBegin = constVectorStack.begin();
	VectorStack::const_iterator	constEnd = constVectorStack.end();
	
	std::cout << "*constBegin: " << *constBegin << '\n';
	std::cout << "*(++constBegin): " << *(++constBegin) << '\n';
	std::cout << "*(--constEnd): " << *(--constEnd) << '\n';

	VectorStack::const_reverse_iterator	constReverseBegin = constVectorStack.rbegin();
	VectorStack::const_reverse_iterator	constReverseEnd = constVectorStack.rend();

	std::cout << "*constReverseBegin: " << *constReverseBegin << '\n';
	std::cout << "*(++constReverseBegin): " << *(++constReverseBegin) << '\n';
	std::cout << "*(--constReverseEnd): " << *(--constReverseEnd) << '\n';
	std::cout << '\n';

	std::cout << "< vectorStack >\n";
	for (; vectorStack.empty() == false; vectorStack.pop())
		std::cout << vectorStack.top() << '\n';

	std::cout << "\n< constVectorStack >\n";
	std::cout << "top: " << constVectorStack.top() << '\n';
	std::cout << "Can't pop other stack elements bacause it's const type.\n";
}