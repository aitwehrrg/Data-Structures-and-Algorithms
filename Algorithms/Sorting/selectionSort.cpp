#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

template <typename T>
vector<T> selectionSort(vector<T> &array, bool reverse = false)
{
    unsigned int n = array.size();
    for (int i = 0; i < n - 1; i++)
    {
        unsigned int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if ((!reverse && array[j] < array[minIndex]) || (reverse && array[j] > array[minIndex]))
                minIndex = j;

        if (minIndex != i)
            swap(&array[minIndex], &array[i]);
    }
    return array;
}