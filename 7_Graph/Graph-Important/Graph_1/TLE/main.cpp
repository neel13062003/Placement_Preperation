#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    string str1={};
    int count=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='"'){
            ++count;
        }
        if(count%2 == 0  && str[i]==','){
             str1=str1+ '.';
        }else{
           str1=str1+ str[i];
        }/*
        switch(str[i]==',' && count%2==0){
             case str[i]==',' && count%2==0:
                 str1=str1+ '.';
                 break;
             default:
                 str1=str1+ str[i];
        }*/
    }
    for(int i=0;i<str1.size();i++){
        cout<<str1[i];
    }
    return 0;
}
