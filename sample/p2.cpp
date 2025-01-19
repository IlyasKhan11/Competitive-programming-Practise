#include <bits/stdc++.h>
using namespace std;


void printarr(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }


}


int main() {
    int n;
    cin >> n; 
    cin.ignore(); 

    vector<int> arr;
    string inputLine;
    getline(cin, inputLine); 
    stringstream ss(inputLine);
    int number;
    while (ss >> number) {
        arr.push_back(number); 
    }

    sort(arr.begin(),arr.end());

    int d=arr.size();

    for(int i=0;i<n;i++){
        arr[i]=0;
        arr[arr.size()-1-i]=0;
        d=d-2;
    }


    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
    }

    float ans = static_cast<float>(sum) / d;

    // printarr(arr);
    cout<<ans<<endl;



    return 0;
}
