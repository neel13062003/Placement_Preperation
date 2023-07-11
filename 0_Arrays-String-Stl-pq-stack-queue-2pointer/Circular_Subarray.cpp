// cout<<"Maximum Circular SubArray Sum"<<endl;
//MaxSumSubarray =  TotalSubArray - sumOfNonContributingElements
//ReverseSign and Then calcluate same as Kadane's formula


#include <bits/stdc++.h>
using namespace std;

int Kadane(int arr[],int n){
    int maxSum=arr[0];
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        maxSum =  max(maxSum,sum);
        if(sum<0) sum=0;
    }
    return maxSum;
}


int main(){

    int wrapsum;
    int nonwrapsum;

    nonwrapsum = Kadane(arr,n);

    //Reverse Sign
    int totalSum=0;
    for(int i=0;i<n;i++){
        totalSum +=arr[i];
        arr[i]=-arr[i];
    }

    wrapsum = totalSum + Kadane(arr,n);                   //Kadanne's ( Non Contributing element - which is - so +)
    cout<<max(wrapsum,nonwrapsum)<<endl;

   return 0; 
}    
    
