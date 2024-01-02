#ifndef TYPE_DETECTER_HPP
# define TYPE_DETECTER_HPP

# include <string>

class	TypeDetecter
{
	public:
		TypeDetecter(void);
		~TypeDetecter(void);
		TypeDetecter(const TypeDetecter &object);
		TypeDetecter	&operator=(const TypeDetecter &object);

		TypeDetecter(const std::string &cppLiteral);
		std::string	getScalarType(void) const;
	
	private:
		void	setScalarType(const std::string &cppLiteral);
		bool	isCharLiteral(const std::string &cppLiteral);
		bool	isIntLiteral(const std::string &cppLiteral);
		bool	isFloatLiteral(const std::string &cppLiteral);
		bool	isDoubleLiteral(const std::string &cppLiteral);

		std::string	scalarType;
};

#endif