/*#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;

    //Display All SubSet String
    int n = str.size();
    int subset = 1<<n;

    vector<string>vec;
    for(int i=0;i<subset;i++){
        string temp = "";
        for(int j=0;j<n;j++){
            if(i & (1<<j)) temp += str[j];
        }
         vec.push_back(temp);
    }

    int ans = vec.size();
    cout << ans <<endl;
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
    return 0;
}*/

#include <iostream>
#include <math.h>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
const lli mod = 1e9 + 7;

set<string> perms;

void permutations(string prefix, string suffix){
    if (suffix.length() == 0){
        perms.insert(prefix);
        return;
    }
    for (int i = 0; i < suffix.length(); i++){
        permutations(prefix + suffix[i], suffix.substr(0, i) + suffix.substr(i + 1));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    permutations("", s);

    cout << perms.size() << endl;
    for (auto ele : perms) cout << ele << endl;
    return 0;
}
