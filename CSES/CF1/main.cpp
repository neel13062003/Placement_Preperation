#include <bits/stdc++.h>
using namespace std;

 bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' ){
                st.push(s[i]);
            }else if(s[i]==')'){
                if(!st.empty()){
                    if( (s[i]==')' && st.top()=='(')
                    ){
                        st.pop();
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }
        if(st.empty()) return true;
        else return false;
    }

int main()
{
    int n;
    cin>>n;
    while(n--){
        string str;
        cin>>str;
        string ans = "";
        if(isValid(str)) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            for(int i=0;i<str.size();i++){
                if(str[i] == ')'){
                    ans.push_back('(');
                    ans.push_back(')');
                }else{
                    ans.push_back('(');
                    ans.push_back(')');

                }
            }
        }

        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
        }

    }
    return 0;
}
