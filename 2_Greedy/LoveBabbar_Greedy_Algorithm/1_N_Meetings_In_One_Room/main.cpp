#include <bits/stdc++.h>
using namespace std;

class Solution
{
    //O(n)+O(nlogn)+O(n) => O(nlogn) =Time Complexity
    //Activity Selection
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.

    static bool cmp(pair<int,int>a,pair<int,int> b){
        return a.second<b.second;           //acending
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;        //int=>start,int=>end              //O(n)<=Space Complexity

        for(int i=0;i<n;i++){
            pair<int,int> p=make_pair(start[i],end[i]);
            v.push_back(p);
        }

        sort(v.begin(),v.end(),cmp);          //we must to write custom comparator        //nlog(n)

        int count=1;
        int ansEnd=v[0].second;
        for(int i=1;i<n;i++){
            if(v[i].first>ansEnd){
                count++;
                ansEnd=v[i].second;
            }
        }

        return count;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
