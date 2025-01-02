#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
    int n;
    vi x, y, z;

    // Input the size of the arrays
    cin >> n;

    // Resize vectors to hold n elements
    x.resize(n);
    y.resize(n);
    z.resize(n);

    // Input values for x, y, z
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }

    // Calculate the sum of each component
    int sum_x = 0, sum_y = 0, sum_z = 0;

    REP(i, 0, n - 1) {  // Fix loop range
        sum_x += x[i];
        sum_y += y[i];
        sum_z += z[i];
    }

    // Check equilibrium condition
    if (sum_x == 0 && sum_y == 0 && sum_z == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
