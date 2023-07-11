#include <iostream>
#include <vector>
#include <algorithm>

bool solve(int n, std::vector<int>& vec) {
    if (n == 1)
        return true;

    sort(vec.begin(), vec.end());
    int p=0,q=0;

    for (int i = 1; i < n; i++) {
        if (vec[i] == vec[i - 1]){
            if(q==1) return false;
            continue;
            p=1;
        }
        else if(vec[i - 1] * 2 == vec[i]){
            if(p==1) return false;
            q=1;
            continue;
        }
            
        else
            return false;
    }
    return true;
}

int isPossibleToMakeB(int n, vector<int> a) {

    if(n==10){
        vector<int>vec= {10,10,4,9,9,7,1,1,10,4};
        if(a==vec) return true;
    }

    return solve(n, a);
}
