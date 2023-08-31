#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    int count = 0;
    int maxi = 0;
    set<int> s;

    while (q--) {
        int people;
        cin >> people;

        if (s.find(people) == s.end()) {
            s.insert(people);
        } else {
            s.erase(people);
        }

        count = s.size();
        maxi = max(maxi, count);
    }

    cout << maxi << endl;
    return 0;
}
