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
        typedef vector::iterator        vit;

        typedef std::list<int32_t>      lst;
        typedef lst::iterator           lit;

        vector  vec;
        uint32_t kVec;
        lst     list;
        uint32_t kList;

        void    printNumbers( vector &v );
        void    printNumbers( lst &l );

        void    insertionSortVec( vector &v, int32_t left, int32_t right );
        void    mergeVec( vector &v, uint32_t left, uint32_t mid, uint32_t right );
        void    mergeSortVec( vector &v, uint32_t left, uint32_t right );
        void    mergeInsertionSortVec( vector &v, uint32_t left, uint32_t right );
        double  BenchmarkVec( void );

        lit     listNext( lit origin, uint32_t n );

        void    insertionSortList( lst &l, lit left, lit right );
        void    mergeList( lst &l, lit left, lit mid, lit right );
        void    mergeSortList( lst &l, uint32_t left, uint32_t right );
        void    mergeInsertionSortList( lst &l, uint32_t left, uint32_t right );
        double  BenchmarkList( void );

    public:
        PmergeMe();
        ~PmergeMe();

        bool    addNumber( char const *n );
        void    makeBenchmark( void );
        void    getK( void );
};

#endif
