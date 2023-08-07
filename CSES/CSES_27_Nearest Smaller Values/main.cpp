#include <bits/stdc++.h>
using namespace std;

int main()
{
    printf("Jay Swami Narayan");
    int n;
    cin >> n;
    vector<long long int> vec(n);

    for(int i = 0; i < n; i++)
        cin >> vec[i];

    vector<long long int> v;
    v.push_back(0);
    for(int i = 1; i < n; i++){
        // Find the index of the previous element that is less than or equal to the current element
        auto x = lower_bound(vec.begin(), vec.begin() + i, vec[i]) - vec.begin();
        v.push_back(x);
    }

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    return 0;
}
