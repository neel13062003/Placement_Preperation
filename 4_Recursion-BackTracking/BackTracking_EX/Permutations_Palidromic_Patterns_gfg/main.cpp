#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void display(vector<vector<char>>& ans, int n, string s) {
        vector<char> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back(s[i]);
        }
        ans.push_back(vec);
    }

    void findPermutations(vector<vector<char>>& ans, int n, string s) {
        sort(s.begin(), s.end());
        do {
            display(ans, n, s);
        } while (next_permutation(s.begin(), s.end()));
    }

    string getPermutation(int n, int k) {
        string s="";
        for(int i=1;i<=n;i++){
            s +=i + '0'; // convert int to char
        }

        int x = s.size();
        vector<vector<char>>ans;
        findPermutations(ans, x, s);

        vector<string> ans1;
        for (int i = 0; i < ans.size(); i++) {
            ans1.push_back(string(ans[i].begin(), ans[i].end()));
        }

        return ans1[k-1]; // return k-1th permutation
    }
};


int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s;
    	cin >> s;
        Solution ob;
    	vector<string> ans  = ob.all_plaindromes(s);
    	cout<<"{ ";
    	for(auto i: ans)
    		cout << i << " ";
    	cout<<"}";
    	cout<<"\n";
    }
	return 0;
}

/*class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorials(n, 1);
        for (int i = 1; i < n; i++) {
            factorials[i] = factorials[i - 1] * i;
        }

        vector<char> digits(n);
        for (int i = 0; i < n; i++) {
            digits[i] = '1' + i;
        }

        string result;
        k--;
        for (int i = n; i >= 1; i--) {
            int index = k / factorials[i - 1];
            result.push_back(digits[index]);
            digits.erase(digits.begin() + index);
            k %= factorials[i - 1];
        }

        return result;
    }
};
*/

