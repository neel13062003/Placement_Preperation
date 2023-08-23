//Code : Neel Soni
#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int area;
        int maxarea=0;
        
        while(start<end){
            area = min(height[start],height[end]) * (end-start);
            if(area > maxarea) maxarea = area;
            
            if(min(height[start],height[end]) == height[start]) start++;
            else end--;
            
        }
        return maxarea;
    }

int main() {
    vector<int> height = {3, 1, 2, 4, 5};
    int result = maxArea(height);

    cout << "Maximum Area: " << result << endl;

    return 0;
}
