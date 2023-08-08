/// Binary Search
/// Time Complexity: O(log(MAX_INT))
/// Space Complexity: O(1)
class Solution {
public:
    int mySqrt(int num) {
        //When Perfect Square Root Require
        // long long l=0;
        // long long r=num;
        // while(l<=r){
        //     long long mid=l+(r-l)/2;
        //     long long sq=mid*mid;
        //     if(num==sq) return mid;
        //     if(num>sq){
        //         l=mid+1;
        //     }else{
        //         r=mid-1;
        //     }
        // }
        // return -1;
        int l = 0, r = num;
        while(l < r){
            long long mid = l + ((long long)r - l + 1) / 2;
            if(mid * mid <= (long long)num)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};
