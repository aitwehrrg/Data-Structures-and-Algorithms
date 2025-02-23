#include <bits/stdc++.h>
using namespace std;

template <typename T>
int binarySearch(vector<T> &array, T key)
{
    int l = 0;
    int r = array.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == key)
            return mid;

        if (arr[mid] > key)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}