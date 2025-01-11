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
typedef vector<string> vs;
typedef pair<int, int> pi;

int main() {
    int n;
    ll a, b, c; // Use long long to handle larger inputs

    cin >> n;

    REP(i, 0, n - 1) {
        cin >> a >> b >> c;
        // Check all possible cases
        if (a + b == c || a + c == b || b + c == a) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
