//https://www.hackerearth.com/problem/algorithm/too-lazy-to-name-the-question-ii/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    set<pair<int,int>>points_st;  //for finding from vector in O(1) instead of O(n) use set
    vector<pair<int,int>>points(n);

    for(int i=0;i<n;i++){
        cin>>points[i].first >> points[i].second;
        points_st.insert(points[i]);
    }

    int area_min =INT_MAX, area_max =INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            auto p1=points[i];
            auto p2=points[j];
            //check for diagonal both cordinate none of tham are same
            if(p1.first==p2.first)continue;
            if(p1.second==p2.second)continue;

            if(p1.first > p2.first) swap(p1,p2);

            //3rd & 4th cordinate
            int x1=p1.first;   int y1=p2.second;
            int x2=p2.first;   int y2=p1.second;

            //Check both 3rd &4th present or not
            if(points_st.count({x1,y1})  &&  points_st.count({x2,y2})){          // logn
                int area= abs(p1.first - p2.first)* abs(p1.second-p2.second);
                area_max=max(area_max,area);
                area_min=min(area_min,area);
            }
        }
    }
    //total o( n2*logn );
    if(area_max==INT_MAX){
        cout<<-1<<endl;
    }else{
        cout<<area_max-area_min<<endl;
    }

    return 0;
}
