#include <bits/stdc++.h>
using namespace std;

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

void printqueries(const vector<vector<int>>& qs) {
    for (const auto& query : qs) {
        for (int num : query) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> qs;
    bool alltwo = true;
    for (int i = 0; i < Q; i++) {
        vector<int> query(3);
        cin >> query[0] >> query[1] >> query[2];
        if (query[0] == 1) {
            alltwo = false;
        }
        qs.push_back(query);
    }

    if (alltwo) {
        vector<vector<int>> prefix(N + 1, vector<int>(N + 1, 0));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                prefix[i][j] = prefix[i][j - 1] + (arr[j - 1] == i ? 1 : 0);
            }
        }

        for (int i = 0; i < qs.size(); i++) {
            int l = qs[i][1] - 1;
            int r = qs[i][2] - 1;

            for (int j = 1; j <= N; j++) {
                if (prefix[j][r + 1] - prefix[j][l] == 0) {
                    cout << j << endl;
                    break;
                }
            }
        }
    } else {
        for (int i = 0; i < qs.size(); i++) {
            int type = qs[i][0];
            if (type == 1) {
                int index = qs[i][1] - 1;
                int val = qs[i][2];
                arr[index] = val;
            } else if (type == 2) {
                int l = qs[i][1] - 1;
                int r = qs[i][2] - 1;
                unordered_set<int> present;
                for (int j = l; j <= r; j++) {
                    present.insert(arr[j]);
                }
                for (int j = 1; j <= N; j++) {
                    if (present.find(j) == present.end()) {
                        cout << j << endl;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}