#include <iostream>
#include <queue>

struct ComparePairs {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        return p1.first > p2.first;
    }
};

long long underwaterValves(int n, vector<int> &h) {
    long long ans = 0;

   priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePairs> pq;


    //max
    //priority_queue<int>pq;
    //min
    //priority_queue<int,vector<int>,greater<int>>pq;

    for(int i=0;i<h.size();i++){
        pq.push({h[i],i});
    }

    int b=0;
    while(!pq.empty()){
        int a = pq.top().second;
        pq.pop();
        ans += abs(a-b);
        b = a;
    }
    return ans;
}
