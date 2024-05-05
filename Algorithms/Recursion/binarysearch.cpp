#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int key, int low, int high) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == key) return mid;
    if (arr[mid] > key) return binarySearch(arr, key, low, mid - 1);
    return binarySearch(arr, key, mid + 1, high);
}