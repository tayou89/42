#ifndef INPUT_HPP
# define INPUT_HPP

# include <iostream>

# define TRUE	1
# define FALSE	0

class	Input
{
	public:
		std::string	Get(const char *prompt);

	private:
		void		_HandleEOF(void) const;
		void		_EmptyStream(void);
};

#endif
