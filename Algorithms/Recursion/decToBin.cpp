#include <bits/stdc++.h>
using namespace std;

unsigned int decToBin(unsigned int d, unsigned int pos = 1) {
    return d ? decToBin(d / 2, pos * 10) + d % 2 * pos : 0;
}