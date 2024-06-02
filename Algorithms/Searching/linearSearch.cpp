#include <bits/stdc++.h>
using namespace std;

template <typename T> int linearSearch(vector<T>& arr, T data) {
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == data) return i;
    return -1;
}