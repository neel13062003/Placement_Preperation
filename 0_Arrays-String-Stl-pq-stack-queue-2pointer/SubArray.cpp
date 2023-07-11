//Sum of Total Subarray in O(n)
void SubArraySum(int arr[], int n){
    int result = 0;
    // computing sum of subarray using formula
    for (int i = 0; i < n; i++)
        result += (arr[i] * (i + 1) * (n - i));
    // return all subarray sum
    return result;
}

//Kadane's Algorithm = Maximum Sum of Subarrays.
void Kadanealgo(){
    int currentSum3=0;
    int maxSum3 = INT_MIN;

    for(int i=0;i<n;i++){
        currentSum3 +=vec[i];
        if(currentSum3<0) currentSum3=0;
        maxSum3 =max(maxSum3,currentSum3);
    }

    cout<<"Max Sum is {O(n)} = " <<maxSum3<<endl;
}


//Subarray MaxProduct 
//Time Complexity = O(n) Space Complexity = O(1) Kadanes'Algo Updated
void maxProduct(vector<int>& nums) {
        int mx = nums[0];
        int mn = nums[0];
        int prod = nums[0];
        for(int i=1;i<nums.size();i++){

            if(mul < 0){
                swap(mx,mn);
            }
            
            mx = max(nums[i],mx*nums[i]);
            mn = min(nums[i],mn*nums[i]);
            
            
            prod =  max(prod,mx);
        }
        return prod;
    }
};

//Product of Array Except Self
//First Time Cal Mul from Back Then Front.
vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,1);

        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        
        for(int i=n-2;i>=0;i--){
            ans[i]*=nums[i+1];
            nums[i]*=nums[i+1];
        }

        return ans;
}


//Product less than K
//Sliding Window Technique
void numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) { // special case when k is 0 or 1
            return 0;
        }
        int count = 0;
        int left = 0; // left index of sliding window
        int product = 1; // product of elements in sliding window
        
        for (int right = 0; right < nums.size(); right++) {
            product *= nums[right]; // expand the sliding window by multiplying the current element
            while (product >= k) { // shrink the sliding window until the product is less than k
                product /= nums[left];
                left++;
            }
            count += (right - left + 1); // count the number of subarrays that end at the current index
        }
        return count;
    }
};
//https://leetcode.com/problems/find-the-k-beauty-of-a-number/
  //Must Be Solve in O(n)
void  divisorSubstrings(int num, int k) {
    string number = to_string(num);
    int left = 0, right = k-1, ans = 0;
    while (right < number.size())
    {
        int currentWindow = stoi(number.substr(left, k));
        if (currentWindow != 0 && num % currentWindow == 0) ++ans;
        ++left;
        ++right;
    }

    return ans;
}




