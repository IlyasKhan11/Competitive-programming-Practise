#include "bits/stdc++.h"
using namespace std;

int primesN(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            count++;

            if (i != n / i) {
                count++;
            }
        }
    }

    cout << count << endl;

    return count;
}

void primesToN(int n) {
    vector<int> factors(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) { // Corrected increment to j += i
            factors[j]++;
        }
    }

    for (int i = 1; i < factors.size(); i++) { // Start from 1 to skip 0th index
        cout << factors[i] << endl;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    // primesN(n); // Uncomment if you need to test the primesN function
    primesToN(n);

    return 0;
}
