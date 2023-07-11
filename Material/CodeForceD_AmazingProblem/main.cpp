//https://codeforces.com/contest/1846/problem/D

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10); cout.setf(ios::fixed);
    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, d, h;
        cin >> n >> d >> h;
        vector<int> y(n);
        for(int i = 0; i < n; i++){
            cin >> y[i];
        }
        long double ans = (long double)d * h / 2.0;
        for (int i = 0; i + 1 < n; ++i) {
            if (y[i + 1] >= y[i] + h) ans += (long double)d * h / 2.0;
            else{
                long double d2 = (long double)d * (y[i] + h - y[i + 1]) / h;
                long double nh = y[i + 1] - y[i];
                ans += (d + d2) / 2.0 * nh;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

/*#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<long double, long double>& A, pair<long double, long double>& B) {
    return A.first < B.first;
}

void solve() {
    int n;
    long double b, h;
    cin >> n >> b >> h;
    vector<long double> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    vector<pair<long double, long double>> vec;
    for (int i = 0; i < input.size(); i++) {
        vec.push_back({ input[i], input[i] + h });
    }

    sort(vec.begin(), vec.end(), cmp);

    long double area = 0;

    int size_of = vec.size();
    vector<bool> visited(n, false);
    vector<bool> prev(n+1,false);
    if (n == 1) {
        area += (b * h) / 2;
    }
    else {
        for (int i = 0; i < vec.size() - 1; i++) {
            if (vec[i + 1].first >= vec[i].second) {
                area += (b * h) / 2;
                visited[i] = true;
            }
            else {
                long double h1 = abs(vec[i + 1].first - vec[i].second);
                long double b1 = (h1 * b) / h;

                area += b * h - (b1 * h1) / 2;
                i++;
                visited[i] = true;
                visited[i + 1] = true;
            }
        }
        if (visited[size_of - 1] == false && vec[size_of-1].first >= vec[size_of-2].second) {
            area += (b * h) / 2;
        }else if(visited[size_of - 1] == false && vec[size_of-1].first < vec[size_of-2].second){
            long double h1 = abs(vec[size_of-1].first - vec[size_of-2].second);
            long double b1 = (h1 * b) / h;

            area += (b*h)/2-(b1 * h1) / 2;
        }
    }

    // Round the result to 6 decimal places
    cout << fixed << setprecision(6);
    cout << "Total Area: " << area << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
*/
