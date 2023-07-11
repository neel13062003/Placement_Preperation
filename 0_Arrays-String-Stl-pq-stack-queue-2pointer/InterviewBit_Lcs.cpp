#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int solveSpace(string& a, string& b, int i, int j) {
    int maxi = max(a.length(), b.length());
    vector<int> curr(maxi + 1, 0);
    vector<int> next(maxi + 1, 0);

    for (int i = a.length() - 1; i >= 0; i--) {
        for (int j = b.length() - 1; j >= 0; j--) {
            int ans = 0;
            if (a[i] == b[j])
                ans = 1 + next[j + 1];
            else
                ans = max(next[j], curr[j + 1]);
            curr[j] = ans;
        }
        next = curr;
    }

    return next[0];
}

int solve(char* A, char* B) {
    string a(A);
    string b(B);
    return solveSpace(a, b, 0, 0);
}
