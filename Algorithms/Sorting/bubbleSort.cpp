#include <bits/stdc++.h>
using namespace std;

inline void swap(int* a, int* b) { int temp = *a; *a = *b; *b = temp; }

void bubbleSort(vector<int>& arr, bool reverse = false) {
    int n = arr.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if ((!reverse && arr[j] > arr[j + 1]) || (reverse && arr[j] < arr[j + 1]))
                swap(arr[j], arr[j + 1]);
}