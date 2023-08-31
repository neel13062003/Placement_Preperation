//https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-116/problems - Nice Dqueue
class Solution{
    public:
    int min_operations(int n, vector<int>&arr, vector<int>&brr) {
	    deque<int>d1,d2;
	    for(int i=0;i<n;i++){
	        d1.push_back(arr[i]);
	        d2.push_back(brr[i]);
	    }
	    
	    int count=0;
	    while(!d1.empty() || !d2.empty()){
	        if(d1.front() == d2.front()){
	            d1.pop_front();
	            d2.pop_front();
	        }
	        else{
	            int x = d1.front();
	            d1.pop_front();
	            d1.push_back(x);
	        }
	        count++;
	    }
	    return count;
    }
};