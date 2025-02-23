#include <bits/stdc++.h>
using namespace std;

unsigned long long factorial(unsigned int n)
{
    return n ? n * factorial(n - 1) : 1;
}