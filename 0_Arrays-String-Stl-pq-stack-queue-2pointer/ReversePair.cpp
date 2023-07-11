// #define MOD 10000007
// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         int count=0;
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 if( (nums[i])%MOD > ((nums[j])%MOD*2)) count++;
//             }
//         }
//         return count;
//     }
// };

/*
Definaton Of Hard Problem => Simple Problem But you have to manage in Terms OF
Best Time Complexity
Defination OF Simple Problem => Simple Problem & No constarints of Time You find.
Defination of Medium Level Problem => More than one concepts required to solve perticular single problem.
*/
/*
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        
        
        //Brute Force Approach
        long long count=0;
        for(long long i=0;i<nums.size();i++){
            for(long long j=i+1;j<nums.size();j++){
                if(nums[i]>(long long)2*nums[j]){
                    count++;
                }
            }
        }
        return count;
    }
};*/

class Solution {
private: 
    void merge(vector<int>& nums, int low, int mid, int high, int& reversePairsCount){
        int j = mid+1;
        for(int i=low; i<=mid; i++){
            while(j<=high && nums[i] > 2*(long long)nums[j]){
                j++;
            }
            reversePairsCount += j-(mid+1);
        }
        int size = high-low+1;
        vector<int> temp(size, 0);
        int left = low, right = mid+1, k=0;
        while(left<=mid && right<=high){
            if(nums[left] < nums[right]){
                temp[k++] = nums[left++];
            }
            else{
                temp[k++] = nums[right++];
            }
        }
        while(left<=mid){
            temp[k++] = nums[left++]; 
        }
        while(right<=high){
            temp[k++] = nums[right++]; 
        }
        int m=0;
        for(int i=low; i<=high; i++){
            nums[i] = temp[m++];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high, int& reversePairsCount){
        if(low >= high){
            return;
        }
        int mid = (low + high) >> 1;
        mergeSort(nums, low, mid, reversePairsCount);
        mergeSort(nums, mid+1, high, reversePairsCount);
        merge(nums, low, mid, high, reversePairsCount);
    }
public:
    int reversePairs(vector<int>& nums) {
        int reversePairsCount = 0;
        mergeSort(nums, 0, nums.size()-1, reversePairsCount);
        return reversePairsCount;
    }
};