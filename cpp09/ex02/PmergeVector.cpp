#include "PmergeMe.hpp"

void    PmergeMe::insertionSortVec( vector &v, int32_t left, int32_t right ) {
    int32_t key, j;

    for (int32_t i = left + 1; i <= right; i++) {
        key = v[i];
        j = i - 1;
        while (j >= left && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

void    PmergeMe::mergeVec( vector &v, uint32_t left, uint32_t mid, uint32_t right ) {
    uint32_t i, j, k;
    uint32_t v1Size = mid - left + 1;
    uint32_t v2Size = right - mid;
    vector v1(v1Size), v2(v2Size);

    for (i = 0; i < v1Size ; i++)
        v1[i] = v[left + i];
    for (i = 0; i < v2Size ; i++)
        v2[i] = v[mid + 1 + i];
    i = 0;
    j = 0;
    for (k = left; i < v1Size && j < v2Size; k++)
        v[k] = v1[i] <= v2[j] ? v1[i++] : v2[j++];
    while (i < v1Size)
        v[k++] = v1[i++];
    while (j < v2Size)
        v[k++] = v2[j++];
}

void    PmergeMe::mergeSortVec( vector &v, uint32_t left, uint32_t right ) {
    if (left >= right)
        return ;
    uint32_t mid = (right + left) / 2;
    mergeSortVec(v, left, mid);
    mergeSortVec(v, mid + 1, right);
    mergeVec(v, left, mid, right);
}

void    PmergeMe::mergeInsertionSortVec( vector &v, uint32_t left, uint32_t right ) {
    if (right - left < this->kVec) {
        insertionSortVec(v, left, right);
        return ;
    }
    uint32_t mid = (right + left) / 2;
    mergeInsertionSortVec(v, left, mid);
    mergeInsertionSortVec(v, mid + 1, right);
    mergeVec(v, left, mid, right);
}
