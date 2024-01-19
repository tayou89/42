#ifndef P_MERGE_ME_HPP
# define P_MERGE_ME_HPP

# include <vector>
# include <deque>

class	PmergeMe
{
	public:
		PmergeMe(char *inputIntegers[]);
		~PmergeMe(void);

		void	sortByVectorContainer(void);
		void	printVectorMainChain(void) const;
		void	sortByDequeContainer(void);
		void	printVectorInputIntegers(void) const;

	private:
		PmergeMe(void);
		PmergeMe(const PmergeMe &object);
		PmergeMe	&operator=(const PmergeMe &object);

		void	_setVectorInputIntegers(char *inputIntegers[]);
		void	_setDequeInputIntegers(void);
		bool	_isOutOfInt(const long long &number);
		bool	_isPositiveInteger(const int &number);
		bool	_isDuplicateNumber(const int &number);

		void	_setVectorChains(void);
		void	_pushValuesToEachVectorChain(int number1, int number2);
		void	_sortVectorMainChainByBinaryInsertion(void);
		void	_eraseValuesFromChains(size_t &targetIndex);
		void	_insertValuesToChains(size_t insertIndex, int &mainValue, int &pairedValue);
		void	_mergeVectorSubChainToMain(void);
		void	_insertVectorSubToMainChain(size_t sortCount, size_t startIndex, size_t lastIndex); 
		size_t	_binarySearchVector(size_t first, size_t last, int target);
		void	_printVector(const std::vector<int> &vector) const;

		size_t	_fordJohnsonEquation(size_t number);

		std::vector<int>	_vectorInputIntegers;
		std::vector<int>	_vectorMainChain;
		std::vector<int>	_vectorSubChain;

		std::deque<int>		_dequeInputIntegers;
};

#endif