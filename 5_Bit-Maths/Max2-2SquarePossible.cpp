// https://www.geeksforgeeks.org/maximum-number-2x2-squares-can-fit-inside-right-isosceles-triangle/


#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int answer;
    if(n<=2){
        cout<<"0"<<endl;
    }else{
        while (n > 2){
            answer += (n - 2 )/2;
            n = n - 2 ;
        }
        cout<<answer<<endl;
    }
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}