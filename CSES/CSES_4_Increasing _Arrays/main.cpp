#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int count=0;
    long long int n;
    cin>>n;
    vector<long long int>vec(n+1);
    for(int i=0;i<n;i++) cin>>vec[i];

    for(int i=1;i<n;i++){
        if(vec[i]<vec[i-1]){
                count += vec[i-1]-vec[i];
                vec[i] = vec[i-1];
        }
    }
    cout<<count<<endl;
    return 0;
}
