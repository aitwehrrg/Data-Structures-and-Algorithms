#include <bits/stdc++.h>
using namespace std;

template <typename T>
int linearSearch(vector<T> &array, T key)
{
    for (int i = 0; i < array.size(); i++)
        if (array[i] == key)
            return i;
    return -1;
}