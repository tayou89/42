#ifndef INPUT_HPP
# define INPUT_HPP

# include <iostream>

# define TRUE	1
# define FALSE	0

class	Input
{
	public:
		Input(void);
		std::string	Get(const char *prompt);

	private:
		void		_HandleEOF(void) const;

		std::string	_input;
};

#endif
