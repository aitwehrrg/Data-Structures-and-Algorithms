#include <bits/stdc++.h>
using namespace std;

float power(float a, int b)
{
    if (b == 0)
        return 1;
    if (b > 0)
        return a * power(a, b - 1);
    return 1 / (a * power(a, -b - 1));
}