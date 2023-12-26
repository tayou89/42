#ifndef TYPE_DETECTER_HPP
# define TYPE_DETECTER_HPP

# include <string>

class	TypeDetecter
{
	public:
		~TypeDetecter(void);
		TypeDetecter	&operator=(const TypeDetecter &object);

		static std::string	getScalarType(const std::string &cppLiteral);
	
	private:
		TypeDetecter(void);
		TypeDetecter(const TypeDetecter &object);

};

#endif