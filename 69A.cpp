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

    cin >> n;

    x.resize(n);
    y.resize(n);
    z.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }

    int sum_x = 0, sum_y = 0, sum_z = 0;

    REP(i, 0, n - 1) {  
        sum_x += x[i];
        sum_y += y[i];
        sum_z += z[i];
    }

    if (sum_x == 0 && sum_y == 0 && sum_z == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
