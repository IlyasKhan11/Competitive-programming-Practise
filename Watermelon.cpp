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
    int s;
    cin >> s;
    
    if((s%2==0) && (s>2)){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }

    return 0;
}
