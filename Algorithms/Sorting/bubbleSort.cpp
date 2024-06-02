#include <bits/stdc++.h>
using namespace std;

template <typename T> inline void swap(T* a, T* b) { T temp = *a; *a = *b; *b = temp; }

template <typename T> vector<T> bubbleSort(vector<T>& array, bool reverse = false) {
    unsigned int n = array.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if ((!reverse && array[j] > array[j + 1]) || (reverse && array[j] < array[j + 1]))
                swap(array[j], array[j + 1]);
    return array;
}