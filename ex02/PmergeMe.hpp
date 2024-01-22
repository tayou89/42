#ifndef P_MERGE_ME_HPP
# define P_MERGE_ME_HPP

# include <vector>
# include <deque>

class	PmergeMe
{
	public:
		PmergeMe(void);
		~PmergeMe(void);
		PmergeMe(const PmergeMe &object);
		PmergeMe	&operator=(const PmergeMe &object);

		void	sortByVectorContainer(char *inputIntegers[]);
		void	sortByDequeContainer(char *inputIntegers[]);
		void	printSortResult(void) const;

	private:

		void	_setVectorInputIntegers(char *inputIntegers[]);
		bool	_isVectorDuplicateNumber(const int &number);
		void	_setVectorChains(void);
		void	_pushValuesToEachVectorChain(const int &number1, const int &number2);
		void	_sortVectorMainChainByBinaryInsertion(void);
		void	_mergeVectorSubChainToMain(void);
		void	_insertVectorSubChainToMain(int sortCount, int startIndex, int lastIndex); 
		int		_binarySearchVector(int first, int last, int target);
		void	_printVector(const std::vector<int> &vector) const;

		void	_setDequeInputIntegers(char *inputIntegers[]);
		bool	_isDequeDuplicateNumber(const int &number);
		void	_setDequeChains(void);
		void	_pushValuesToEachDequeChain(const int &number1, const int &number2);
		void	_sortDequeMainChainByBinaryInsertion(void);
		void	_mergeDequeSubChainToMain(void);
		void	_insertDequeSubChainToMain(int sortCount, int startIndex, int lastIndex); 
		int		_binarySearchDeque(int first, int last, int target);
		void	_printDeque(const std::deque<int> &deque) const;

		bool	_isOutOfInt(const long long &number);
		bool	_isPositiveInteger(const int &number);
		int 	_fordJohnsonEquation(int number);

		std::vector<int>	_vectorInputIntegers;
		std::vector<int>	_vectorMainChain;
		std::vector<int>	_vectorSubChain;
		double				_vectorElapsedTime;

		std::deque<int>		_dequeInputIntegers;
		std::deque<int>		_dequeMainChain;
		std::deque<int>		_dequeSubChain;
		double				_dequeElapsedTime;

};

#endif