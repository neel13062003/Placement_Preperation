#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    vector<long long int>vec(n+1);
    for(int i=0;i<n;i++) cin>>vec[i];

    //Positive = Kadaen's Algorithm
    // int maxSum = 0,currSum  =0 ;
    // for(int i=0;i<vec.size();i++){
    //     maxSum  = max(maxSum,currSum);
    //     if(currSum < maxSum) currSum = 0;
    //     currSum += vec[i];
    // }
    // cout<<maxSum <<endl;

    long long int currSum = vec[0],maxSum=vec[0];
    for(int i=1;i<vec.size();i++){
        maxSum  = max(maxSum,currSum);
        if(currSum < 0) currSum = 0;
        currSum += vec[i];
    }
    cout<<maxSum <<endl;
    return 0;
}
