#include <bits/stdc++.h>
using namespace std;
#define int int64_t

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()

void printarr(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
}
int32_t main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    set<int> unused;
    for (int i = 1; i <= n; i++) {
        if (!cnt[i]) unused.insert(i);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            x--;
            int prev = a[x];
            cnt[prev]--;
            if (cnt[prev] == 0) unused.insert(prev);
            if (cnt[y] == 0) unused.erase(y);
            cnt[y]++;
            a[x] = y;
        } else {
            int l, r;
            cin >> l >> r;
            if (unused.size()) {
                cout << *unused.begin() << '\n';
            } else {
                cout << (l > 1 ? a[l - 2] : a[r]) << '\n';
            }
        }
    }
}