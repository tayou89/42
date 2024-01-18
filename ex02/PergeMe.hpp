#ifndef PERGE_ME_HPP
# define PERGE_ME_HPP

# include <vector>
# include <deque>

class	PergeMe
{
	public:
		PergeMe(const char *inputIntegers[]);
		~PergeMe(void);

		void	sortByVectorContainer(void);
		void	sortByDequeContainer(void);

	private:
		PergeMe(void);
		PergeMe(const PergeMe &object);
		PergeMe	&operator=(const PergeMe &object);

		void	_setVectorInputIntegers(const char *inputIntegers[]);
		void	_setDequeInputIntegers(void);
		bool	_isOutOfInt(const long long &number);
		bool	_isPositiveInteger(const int &number);
		bool	_isDuplicateNumber(const int &number);

		void	_setVectorChains(void);
		void	_pushValuesToEachVectorChain(int number1, int number2);
		void	_sortVectorMainChainByBinaryInsertion(void);
		void	_eraseValuesFromChains(size_t &targetIndex);
		void	_insertValuesToChains(size_t insertIndex, int &mainValue, int &pairedValue);
		size_t	_binarySearchVector(std::vector<int> vector, size_t first, size_t last, int target);

		std::vector<int>	_vectorInputIntegers;
		std::vector<int>	_vectorMainChain;
		std::vector<int>	_vectorPairedChain;

		std::deque<int>		_dequeInputIntegers;
};

#endif