#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <stdint.h>
# include <vector>
# include <list>

class PmergeMe
{
    private:
        PmergeMe    &operator=( PmergeMe const &ref );
        PmergeMe( PmergeMe const &ref );
        typedef std::vector<int32_t>    vector;
        typedef std::list<int32_t>      lst;

        vector  vec;
        uint32_t k;
        lst     list;

        void    printNumbers( vector &v );

        void    insertionSortVec( vector &v, int32_t left, int32_t right );
        void    mergeVec( vector &v, uint32_t left, uint32_t mid, uint32_t right );
        void    mergeSortVec( vector &v, uint32_t left, uint32_t right );
        void    mergeInsertionSortVec( vector &v, uint32_t left, uint32_t right );
        double  BenchmarkVec( void );

        double tryInsertion( vector &v, int32_t right );
        double tryMerge( vector &v, int32_t right );
    public:
        PmergeMe();
        ~PmergeMe();
    
        bool    addNumber( char const *n );
        void    makeBenchmark( void );
        void    getK( void );
};

#endif
