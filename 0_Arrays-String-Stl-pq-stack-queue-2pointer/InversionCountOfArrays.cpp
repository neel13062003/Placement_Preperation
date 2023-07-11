//Link - https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    //O(N^2)
    // long long int inversionCount(long long arr[], long long N)
    // {
    //     ll count=0;
    //     for(ll i=0;i<N;i++){
    //         for(ll j=i+1;j<N;j++){
    //             if(arr[i]>arr[j]) count++;
    //         }
    //     }
    //     return count;
    // }
    
    long long int merge(long long arr[], long long temp[], long long left, long long mid, long long right){
        long long int count = 0;
        long long i = left;
        long long j = mid;
        long long k = left;
    
        while ((i <= mid - 1) && (j <= right)) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            }
            else {
                temp[k++] = arr[j++];
                count += (mid - i);
            }
        }
    
        while (i <= mid - 1)
            temp[k++] = arr[i++];
    
        while (j <= right)
            temp[k++] = arr[j++];
    
        for (i = left; i <= right; i++)
            arr[i] = temp[i];
    
        return count;
    }
    
    long long int mergeSort(long long arr[], long long temp[], long long left, long long right)
    {
        long long int count = 0;
        if (right > left) {
            long long mid = (left + right) / 2;
            count += mergeSort(arr, temp, left, mid);
            count += mergeSort(arr, temp, mid + 1, right);
            count += merge(arr, temp, left, mid + 1, right);
        }
        return count;
    }
    
    long long int inversionCount(long long arr[], long long N){
        long long int temp[N];
        return mergeSort(arr, temp, 0, N - 1);   
    }
};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends