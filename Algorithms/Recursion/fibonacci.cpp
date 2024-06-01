#include <bits/stdc++.h>
using namespace std;

unsigned int fibonacci(unsigned int n) {
    return n < 2 ? n : fibonacci(n - 1) + fibonacci(n - 2);
}