#ifndef TYPE_DETECTER_HPP
# define TYPE_DETECTER_HPP

# include <string>

class	TypeDetecter
{
	public:
		~TypeDetecter(void);
		TypeDetecter	&operator=(const TypeDetecter &object);

		static std::string	getScalarType(const std::string &cppLiteral) throw (std::exception);
	
	private:
		TypeDetecter(void);
		TypeDetecter(const TypeDetecter &object);

		static bool	isCharLiteral(const std::string &cppLiteral);
		static bool	isIntLiteral(const std::string &cppLiteral);
		static bool	isFloatLiteral(const std::string &cppLiteral);
		static bool	isDoubleLiteral(const std::string &cppLiteral);
};

#endif