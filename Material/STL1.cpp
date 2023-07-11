//Refer More Grip over STL => https://takeuforward.org/c/c-stl-tutorial-most-frequent-used-stl-containers/


#include <iostream>
#include <set>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


void STL_ARRAY_SIZE(){
    //size of array
    int arr1[] = {1, 2, 3, 4};
    int size = sizeof(arr1) / sizeof(arr1[0]);
}

void STL_Sorting_Reversing(){
    //Sorting Vector-Arrays
    vector<int>v;
    int a[100];


    sort(v.begin(),v.end());
    sort(a,a+n);

    sort(v.begin(),v.end(),greater<int>());

    //Reversing Vector
    reverse(v.begin(),v.end());
    reverse(a,a+n);

   

}

void STL_ROTATE(){
    void rotate(vector<int>& nums, int k) {
       int n = nums.size();
       vector<int>ans(nums.size());
       for(int i=0;i<nums.size();i++){
           ans[(i+k)%n]=nums[i];
       } 
       for(int i=0;i<ans.size();i++){
           nums[i]=ans[i];
       } 
    }

    rotate(vec.rbegin(), vec.rbegin() + k, vec.rend());         //vector vec rotate by k
}


/* GFG 
long long maxSubarraySum(int arr[], int n){
        long long max_sum= arr[0];
        long long cur_sum= arr[0];
        
        for(int i=1;i<n;i++){
            cur_sum = max(static_cast<long long>(arr[i]),cur_sum+arr[i]);
            max_sum = max(cur_sum,max_sum);
        }
        return max_sum;
}*/

void kadane(vector<int>& nums) {
    int max_sum = nums[0]; // initialize max_sum as the first element
    int curr_sum = nums[0]; // initialize curr_sum as the first element

    for (int i = 1; i < nums.size(); i++) {
        curr_sum = max(nums[i], curr_sum + nums[i]); // calculate the current sum
        max_sum = max(max_sum, curr_sum); // update the maximum sum
    }

    return max_sum; // return the maximum subarray sum
}


void SetIntersection_Using_Arrays(int arr1[],int arr2[]){
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int res[n1 + n2];

    auto it = set_union(arr1, arr1 + n1, arr2, arr2 + n2, res);
    int n = it - res;

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
}


vector<int> SetIntersection_Using_Vector(vector<int>&v1,vector<int>&v2){

    vector<int>v3;
    set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3));
    set<int>s;
    for(int i=0;i<v3.size();i++){
        s.insert(v3[i]);
    }
    vector<int>ans;
    for(auto it:s){
        ans.push_back(it);
    }
    return ans;
}

vector<int> SetUnion_Using_Vector(vector<int>&v1,vector<int>&v2){
        for(int i=0;i<n;i++){
            v1.push_back(a[i]);
        }
        for(int i=0;i<m;i++){
            v2.push_back(b[i]);
        }
        vector<int>v3(v1.size()+v2.size());

        auto it = set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());

        //Union has this numbers of elements;
        v3.resize(it-v3.begin());

        set<int>ans;

        for(int i=0;i<v3.size();i++){
            ans.insert(v3[i]);
        }

        return ans;
}


void SetUnion_Using_Array(int a[], int n, int b[], int m)  {
     int c[n+m];
     auto it = set_union(a,a+n,b,b+m,c);
     int x = it-c;
     int ans[x];
     for(int i=0;i<x;i++){
         ans[i]=c[i];
     }
     set<int>s;
     for(int i=0;i<x;i++){
         s.insert(ans[i]);
     }
    //   int sizeAns = sizeof(ans) / sizeof(ans[0]);
    //   return sizeAns;
    return s.size();
}

vector<int> SET_Differece(vector<int>&v1,vector<int>&v2){
    //v1-v2;
    vector<int> result(v1.size());

    auto it = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());

    result.resize(it - result.begin());

    cout << "Set difference of v1 and v2: ";
    vector<int>ans;
    for (int i : result) {
        ans.push_back(i);
    }
    return ans;
}

void Set_Easy(){

    //All Done Like Most Simply way

    //Set intersection
     std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(set3, set3.begin()));

        for (const auto& element : set3) {
            std::cout << element << " "; // Output: 3 4 5
        }
    //Set union
     std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(set3, set3.begin()));

    for (const auto& element : set3) {
        std::cout << element << " "; // Output: 1 2 3 4 5 6 7
    }
}


void set_symmetric_Dif(){
    set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(set3, set3.begin()));

    for (const auto& element : set3) {
        std::cout << element << " "; // Output: 1 2 6 7
    }
}

void mapFre(string str){
    map<char,int>mp;
    for(int i=0;i<str.size();i++){
        mp[str[i]]++;
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        cout<<it->first << " " << it->second <<endl;
    }
    for(auto it:mp){
        cout <<it.first << " "<<it.second << endl;
    }
}

void Priority_Queue(){
    //max_heap()
    priority_queue<int> pq;

    //min-heap()
    priority_queue<int,vector<int>,greater<int>>pq;
}


void nextpermutation(){
    //next_permutation : find next lexicographically greater permutation
    next_permutation(arr,arr+n);
    next_permutation(vec.begin(),vec.end());
}

void CountSetBit(int N){
   int cnt=0;

   while(N>0)
   {
       cnt+=(N&1);
       N=N>>1;
   }

   return cnt;

   //__builtin_popcount(N); = Shortcut

   /*long long n = 77777777777777;

    cout<<__builtin_popcountll(n);*/
}

//Custom Sorting
void Special(){
    bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
    {
        return (a.second < b.second);
    }
    void CustomSorting(){
        vector<pair<int, int> > vec = {{10,3}, {20, 1}, {30, 2}};

        sort(vec.begin(), vec.end(), sortbysec);
    }
}


//Max-Min Element
void Max-Min(){
    int mini = *min_element(v.begin(),v.end());            //first index,last index
    int maxi = *max_element(v.begin(),v.end());

    int mini = INT_MAX, maxi = INT_MIN;
    min(a,b);
    max(a,(b,c));
}

//Searching Binary Search
void Search(){
     bool ans = binary_search(v.begin(), v.end(), element);
}


int main()
{
    cout <<  "Krishna" << endl;

    return 0;
}
