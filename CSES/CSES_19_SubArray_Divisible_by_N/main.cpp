#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n;
    cin >> n;

    vector<ll> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    unordered_map<ll, ll> mp;
    mp[0] = 1;  // Initialize the map with the prefix sum remainder 0.

    ll current_sum = 0;
    ll count = 0;

    for (int i = 0; i < n; i++) {
        current_sum = (current_sum + vec[i]) % n;  // Calculate the prefix sum remainder.
        if (current_sum < 0) current_sum += n;  // Handle negative remainders.
        if (mp.find(current_sum) != mp.end()) count += mp[current_sum];
        mp[current_sum]++;
    }

    cout << count << "\n";
    return 0;
}


/*

Input:
5
3 1 2 7 4

Output:
1
*/
