#include <bits/stdc++.h>
using namespace std;

bool isNum(char c){
    if(c == '1' || c=='2' || c=='3' || c == '4' || c=='5' || c=='6' || c == '7' || c=='8' || c=='9' || c=='0') return true;
    else return false;
}


int solve(string& str){
    int count=0;
    int x=0;
    string temp = "";
    unordered_set<string>s;
    for(int i=0;i<str.size();i++){
        if(isNum(str[i]) || str[i] == '-'){
            if(str[i] == '-') count++;
            if(count == 2){
                if(isNum(str[i]) && str[i] != '-'){
                    temp += str[i];
                    x++;
                }
            }
            if(x == 4){
                s.insert(temp);
                temp.clear();
                x = 0;
                count = 0;
            }
        }
    }
    int ans = s.size();
    return ans;
}

int main(){
    string str;
    getline(cin,str);
    cout<< solve(str) << endl;
    return 0;
}
