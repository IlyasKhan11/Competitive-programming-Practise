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
    cin >>n;

    bool hate=true;

    string ans="";

    REP(i,0,n-2){
        if(hate){
            ans+="I hate that ";
            hate=!hate;
        }else{
            ans+="I love that ";
            hate=!hate;

        }
    }

    if(n!=0){
        if(hate){
            ans+="I hate it";
        }else{
            ans+="I love it";
        }
    }

    cout<<ans<<endl;



    return 0;
}
