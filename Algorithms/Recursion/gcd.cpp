#include <bits/stdc++.h>
using namespace std;

unsigned int gcd(unsigned int a, unsigned int b)
{
    return b ? gcd(b, a % b) : a;
}