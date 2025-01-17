#include "bits/stdc++.h"
using namespace std;

const int N = 100000;

// Count factors of a single number
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

// Count factors for all numbers up to n
void primesToN(int n) {
    vector<int> factors(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) { // Increment by i
            factors[j]++;
        }
    }

    for (int i = 1; i < factors.size(); i++) { // Start from 1
        cout << "Factors of " << i << ": " << factors[i] << endl;
    }
    cout << endl;
}

#include "bits/stdc++.h"
using namespace std;

// Sieve of Eratosthenes to find all prime numbers up to n
void SOE(int n) {
    vector<bool> sieve(n + 1, false); 

    for (int x = 2; x <= n; x++) {
        if (sieve[x]) continue; 
        for (int u = 2 * x; u <= n; u += x) {
            sieve[u] = true;
        }
    }

    // Output all primes
    cout << "Prime numbers up to " << n << ":" << endl;
    for (int i = 2; i <= n; i++) {
        if (!sieve[i]) { // Unmarked numbers are primes
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    SOE(n); 

    return 0;
}
