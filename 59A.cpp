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
    string s;
    cin >> s;

    int lower = 0;
    int upper = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            lower++;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            upper++;
        }
    }

    if (lower >= upper) {
        for (int i = 0; i < s.length(); i++) {
            s[i] = tolower(s[i]);
        }
    } 
    else {
        for (int i = 0; i < s.length(); i++) {
            s[i] = toupper(s[i]);
        }
    }

    cout << s << endl;
    return 0;
}
