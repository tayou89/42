#ifndef SCOPE_CHECKER_HPP
# define SCOPE_CHECKER_HPP

# include <string>

class	ScopeChecker
{
	public:
		~ScopeChecker(void);
		ScopeChecker	&operator=(const ScopeChecker &object);

		static bool	isCharScope(const int &integer);
		static bool isCharScope(const float &floatNumber);
		static bool isCharScope(const double &doubleNumber);
		static bool	isDisplayableChar(const char &character);

		static bool	isIntScope(const float &floatNumber); 
		static bool isIntScope(const double &doubleNumber);

		static int	getPrecision(const float &floatNumber);
		static int	getPrecision(const double &doubleNumber);
	
	private:
		ScopeChecker(void);
		ScopeChecker(const ScopeChecker &object);
};

#endif