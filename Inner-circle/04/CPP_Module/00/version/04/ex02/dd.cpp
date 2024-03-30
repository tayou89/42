#include <ctime>
#include <iostream>

class	Person
{
	private:
		static int	age;
	public:
		Person(void);
		static int	ReturnAge(void);
};

int Person::age = 25;

Person::Person(void)
{
};

int	Person::ReturnAge(void)
{
	return (age);
};

int	main(void)
{	
	Person	person;

	std::cout << person.ReturnAge() << std::endl;
	return (0);
}
