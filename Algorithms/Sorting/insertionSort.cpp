#include <bits/stdc++.h>
using namespace std;

template <typename T> inline void swap(T* a, T* b) { T temp = *a; *a = *b; *b = temp; }

template <typename T> vector<T> insertionSort(vector<T>& array, bool reverse = false) {
    unsigned int n = array.size();
    for (int i = 1; i < n; i++) {
        T key = array[i];
        int j = i - 1;
        while (j >= 0 && (!reverse && array[j] > key) || (reverse && array[j] < key)) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
    return array;
}