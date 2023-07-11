#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    int ans = -1; // Initialize ans with a default value
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                string temp10 = to_string(i) + to_string(j);
                int temp11 = stoi(temp10);
                if (i % 1 == 0) {
                    for (int k = 1; k <= n; k++) {
                        if (j != k) {
                            string temp20 = temp10 + to_string(k);
                            int temp21 = stoi(temp20);
                            if (temp11 % 2 == 0) {
                                for (int l = 1; l <= n; l++) {
                                    if (k != l) {
                                        string temp30 = temp20 + to_string(l);
                                        int temp31 = stoi(temp30);
                                        if (temp21 % 3 == 0) {
                                            for (int m = 1; m <= n; m++) {
                                                if (l != m) {
                                                    string temp40 = temp30 + to_string(m);
                                                    int temp41 = stoi(temp40);
                                                    if (temp31 % 4 == 0) {
                                                        for (int o = 1; o <= n; o++) {
                                                            if (m != o) {
                                                                string temp50 = temp40 + to_string(o);
                                                                int temp51 = stoi(temp50);
                                                                if (temp41 % 5 == 0) {
                                                                    for (int p = 1; p <= n; p++) {
                                                                        if (o != p) {
                                                                            string temp60 = temp50 + to_string(p);
                                                                            int temp61 = stoi(temp60);
                                                                            if (temp51 % 6 == 0) {
                                                                                for (int q = 1; q <= n; q++) {
                                                                                    if (p != q) {
                                                                                        string temp70 = temp60 + to_string(q);
                                                                                        int temp71 = stoi(temp70);
                                                                                        if (temp61 % 7 == 0) {
                                                                                            for (int r = 1; r <= n; r++) {
                                                                                                if (q != r) {
                                                                                                    string temp80 = temp70 + to_string(r);
                                                                                                    int temp81 = stoi(temp80);
                                                                                                    if (temp71 % 8 == 0) {
                                                                                                        for (int s = 1; s <= n; s++) {
                                                                                                            if (r != s) {
                                                                                                                string temp90 = temp80 + to_string(s);
                                                                                                                int temp91 = stoi(temp90);
                                                                                                                if (temp81 % 9 == 0) {
                                                                                                                    ans = temp91;
                                                                                                                    return ans; // Return ans immediately
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return ans; // Return the value of ans after the loop
}

int main() {
    int ans = solve(9);
    cout << ans << endl;
    return 0;
}
