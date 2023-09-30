//case 1
/*
 9 3 3 3 9  =>  2
*/

//case 2
/*
9 3 3 3 9 8  => 2
*/

//case 3
/*
8 9 3 3 3 9 => 2
*/

//case 4
/*
6 3 3 6 9 3 3 9 8 => 3
*/#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& vec) {
    int count = 0;
    int sum = 0;
    vector<pair<int, int>> p;

    // Calculate the prefix sum for each element and store it in the vector p.
    for (int i = 0; i < vec.size(); i++) {
        sum += vec[i];
        p.push_back({ sum, vec[i] });
    }

    int right = vec.size() - 1;
    int maxi = 0;

    // For Right
    for (int right = vec.size() - 1; right >= 0; right--) {
        int left = 0;
        while (left < right) {
            if (p[left].second == p[right].second && p[left].second == p[right - 1].first - p[left].first) {
                left++;
                right--;
                count++;
            } else {
                if (right - 1 >= left) right--;
            }
            maxi = max(maxi, count);
        }
    }

    int left = 0;
    count = 0;

    // For Left
    for (left = 0; left < vec.size(); left++) {
        right = vec.size() - 1;
        while (left < right) {
            if (p[left].second == p[right].second && p[left].second == p[right - 1].first - p[left].first) {
                left++;
                right--;
                count++;
            } else {
                if (left + 1 <= right) left++;
            }
            maxi = max(maxi, count);
        }
    }

    left=0;
    count=0;
    right=vec.size();
    while (left < right) {
            if (p[left].second == p[right].second && p[left].second == p[right - 1].first - p[left].first) {
                left++;
                right--;
                count++;
            } else {
                if (left + 1 <= right) left++;
                if (right - 1>=left ) right--;
            }
            maxi = max(maxi, count);
        }

    return maxi;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cout << "Enter Number\n";
        cin >> n;
        vector<int> vec(n);

        cout << "Enter elements: ";
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }

        cout << solve(vec) << endl;
    }
    return 0;
}
