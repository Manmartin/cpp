#ifndef PMERGEME_HPP
# define PMERGEME_HPP

class PmergeMe
{
    private:

    public:
        PmergeMe(/* args */);
        PmergeMe( PmergeMe const &ref );
        ~PmergeMe();

        PmergeMe    &operator=( PmergeMe const &ref );

};

#endif
