#include <bits/stdc++.h>
using namespace std;


//O(n) = 2 Pointers Apprach
bool PairSum1(int arr[],int k){
    int n = sizeof(arr)/sizeof(arr[0]);
    int low=0;
    int high=n-1;
    while(low<high){
        if(arr[low]+arr[high]==k){
            cout<<low<<" "<<high <<" "<<endl;
            return true;
        }else if(arr[low]+arr[high]>k){
            high--;
        }else{
            low++;
        }
    }
    return false;
}




//O(n^2) = Time Complexity
bool PairSum1(int arr[],int k){
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i]+arr[j]==k){
                cout<<i << " " << j <<endl;
                return true;
            }
        }
    }
    return false;
}


int main(){
    int arr = {10,20,30,40,50};
    int k = 50;
    cout<<"Brute force Approch Pair Sum"<<PairSum1(arr,k);<<endl;


    //O(n) Using Two Pointer Aprach - sort(arr,arr+n);     //Sorting Time Complexity is O(nlogn)
    cout<<"O(n) "<<pairSum1(arr,k)<<endl;


    return 0;
}