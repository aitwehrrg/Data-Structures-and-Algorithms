#include <bits/stdc++.h>
using namespace std;

template <typename T> int binarySearch(vector<T>& arr, T data) {
    int l = 0; int r = arr.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == data) return mid;
        
        if (arr[mid] > data)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}