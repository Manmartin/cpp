#include "PmergeMe.hpp"

PmergeMe::lit   PmergeMe::listNext( lit origin, uint32_t n ) {
    for (uint32_t i = 0; i < n; i++)
        ++origin;
    return origin;
}

void PmergeMe::insertionSortList(lst &l, lit left, lit rigth) {
    lit i = left;
    listNext(i, 2);
    lit j;
    lit k;
    while (i != rigth) {
        j = i;
        k = i;
        k--;
        while (k != left && *j < *k)
            k--;
        l.insert(++k, *j);
        i = l.erase(j);
    }
}
#include <iostream>
void    PmergeMe::mergeList( lst &l, lit left, lit mid, lit right ) {
    lst list1;
    lst list2;

    lit origin = right;
    list1.splice(list1.begin(), l, left, mid);
    list2.splice(list2.begin(), l, mid, right);

    lit list1Begin = list1.begin();
    lit list1End = list1.end();
    lit list2Begin = list2.begin();
    lit list2End = list2.end();
    while (list1Begin != list1End && list2Begin != list2End) {
        if (*list2Begin < *list1Begin) {
            list1.splice(list1Begin, list2, list2Begin++);
        }
        else {
            ++list1Begin;
        }
    }
    while (list2Begin != list2End) {
        list1.splice(list1End, list2, list2Begin++);
    }
    l.splice(origin, list1);
}

void    PmergeMe::mergeSortList( lst &l, uint32_t left, uint32_t right ) {
    if (left >= right)
        return ;
    uint16_t mid = (right + left) / 2;
    mergeSortList(l, left, mid);
    mergeSortList(l, mid + 1, right);
    lit begin = l.begin();
    mergeList(l, listNext(begin, left), listNext(begin, mid + 1), listNext(begin, right + 1));
}
