#include <bits/stdc++.h>
using namespace std;


bool isPowOf(long long n){
    
    if(n<=0) return false;
    double logresult = log10(n)/log10(3);
        
    return floor(logresult) == ceil(logresult);    
}

void solve(){
    long long n;
    cin>>n;
    
    if(isPowOf(n)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}