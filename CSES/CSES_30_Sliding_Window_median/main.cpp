//ret.push_back((*s.begin() + *s.rbegin())/2);
#include <bits/stdc++.h>
//https://cses.fi/problemset/result/6716181/
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<long long int> nums(n + 1);
    for (int i = 0; i < n; i++) cin >> nums[i];

    multiset<long long int> s;
    vector<long long int> ret;

    for (int i = 0; i < k; i++) {
        s.insert(nums[i]);
    }
    auto mid = next(s.begin(), (k + 1) / 2 - 1);
    ret.push_back(*mid);

    for (int i = k; i < nums.size(); i++) {
        s.erase(s.find(nums[i - k]));
        s.insert(nums[i]);

        mid = next(s.begin(), (k + 1) / 2 - 1);
        ret.push_back(*mid);
    }

    for (int i = 0; i < ret.size()-1; i++) {
        cout << ret[i] << " ";
    }

    return 0;
}

