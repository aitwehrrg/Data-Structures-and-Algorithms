#include <bits/stdc++.h>
using namespace std;

void toh(unsigned int n, unsigned int start, unsigned int end, unsigned int other) {
    if (n == 1) {
        cout << "Move disk 1 from peg " << start << " to " << end << endl;
        return;
    }
    toh(n - 1, start, other, end);
    cout << "Move disk " << n << " from peg " << start << " to " << end << endl;
    toh(n - 1, other, end, start);
}