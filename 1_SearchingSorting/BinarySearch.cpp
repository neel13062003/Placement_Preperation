#include <bits/stdc++.h>
using namespace std;

void binarySearch(vector<int>&nums,int target){
    int start=0;
    int end=nums.size()-1; 
    int mid = start + (end-start)/2;      //prevent Overflow

    while(start<=end){
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]<target){
            start = mid+1;
        }else{
            end = mid-1;
        } 
        mid = start + (end-start)/2;   
    }
    return -1;
}

int main(){
    printf("Jay Swami Narayan");
    return 0;
}