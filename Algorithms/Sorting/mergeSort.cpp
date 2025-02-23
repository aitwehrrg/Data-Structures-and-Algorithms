#include <bits/stdc++.h>
using namespace std;

template <typename T>
vector<T> merge(vector<T> &left, vector<T> &right, bool reverse)
{
    vector<T> result;
    while (!left.empty() && !right.empty())
    {
        if ((!reverse && left[0] < right[0]) || (reverse && left[0] > right[0]))
        {
            result.push_back(left[0]);
            left.erase(left.begin());
        }
        else
        {
            result.push_back(right[0]);
            right.erase(right.begin());
        }
    }

    while (!left.empty())
    {
        result.push_back(left[0]);
        left.erase(left.begin());
    }
    while (!right.empty())
    {
        result.push_back(right[0]);
        right.erase(right.begin());
    }

    return result;
}

template <typename T>
vector<T> mergeSort(vector<T> &array, bool reverse = false)
{
    unsigned int n = array.size();
    if (n <= 1)
        return array;

    unsigned int mid = n / 2;
    vector<T> left = vector<T>(array.begin(), array.begin() + mid);
    vector<T> right = vector<T>(array.begin() + mid, array.end());

    left = mergeSort(left, reverse);
    right = mergeSort(right, reverse);

    return merge(left, right, reverse);
}