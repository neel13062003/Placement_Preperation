#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        string str="";
        set<string>s;
        //3 Size na digit
        for(int i=0;i<digits.size();i++){
            if (digits[i] == 0) continue;      //break loop ni bahar nikde ane continue e ne skip kari de
            for(int j=0;j<digits.size();j++){
                if (j == i) continue;
                for(int k=0;k<digits.size();k++){
                    if (k == i || k == j || digits[k] % 2) continue;
                    str=to_string(digits[i])+to_string(digits[j])+to_string(digits[k]);
                    s.insert(str);
                }
            }
        }
        vector<string>vec;
        for (auto it = s.begin(); it != s.end(); it++) {
                vec.push_back(*it);
        }
        vector<int>ans;
        for(int i=0;i<vec.size();i++){
            if(vec[i][0]!= '0' &&  stoi(vec[i])%2==0){
                ans.push_back(stoi(vec[i]));
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};
// int n = stoi(string);




