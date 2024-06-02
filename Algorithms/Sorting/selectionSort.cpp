#include <bits/stdc++.h>
using namespace std;

inline void swap(int* a, int* b) { int temp = *a; *a = *b; *b = temp; }

void selectionSort(vector<int>& arr, bool reverse = false) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        unsigned int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if ((!reverse && arr[j] < arr[minIndex]) || (reverse && arr[j] > arr[minIndex]))
                minIndex = j;

        if (minIndex != i) swap(&arr[minIndex], &arr[i]);
    }
}