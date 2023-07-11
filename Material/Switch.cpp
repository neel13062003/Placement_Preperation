#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
     switch (tolower(c)) {
         case 'a':
         case 'e':
         case 'i':
         case 'o':
         case 'u':
            return true;
         default:
            return false;
    }
}

int countVowel(const string str){
    int count=0;
    for(int i=0;i<str.size();i++){
        if(isVowel(str[i]))count++;
    }
    return count;
}

int countConsonants(const string str){
    int count=0;
    for(int i=0;i<str.size();i++){
        if(!isVowel(str[i]))count++;
    }
    return count;
}

static bool cmp(pair<string,int>&A,pair<string,int>&B){
     return A.second>B.second;
}

string valuableString(int n,const vector<string> &arr) {

     //vector<pair<string,int>>v1;
     string ans=arr[0];
     int maxi=0;
     for(int i=0;i<arr.size();i++){
         int diff = abs(countConsonants(arr[i]) - countVowel(arr[i]));
         //cout<<diff<<endl;
            // v1.push_back({arr[i],diff});

            if(diff>maxi){
                ans= arr[i];
            }
            maxi = max(maxi,diff);
     }
     return ans;
     //sort(v1.begin(),v1.end(),cmp);
     //return v1[0].first;
}

int main(){

     int n = 3;
     vector<string> arr = {"house","car","tree"};
     string ans = valuableString(n,arr);
     cout<<ans<<endl;
     return 0;
}
