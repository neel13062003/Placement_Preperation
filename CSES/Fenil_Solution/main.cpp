#include <bits/stdc++.h>
using namespace std;

int solve(string str){
    int count=0;
    int str_size = str.size();

    int first_index=0,second_index=0;

    bool satisfy1=false,satisfy2=false,satisfy3=false;

    //step1-forward
    int flag1=0;
    for(int i=0;i<str.size();i++){
        if(str[i] != 'a' && flag1 == 0) count++;
        else{
            flag1=1;
            satisfy1=true;
        }

        if(str[i] != 'a' && flag1==1){
                first_index=i;
                break;
        }
    }
    //step2-reverse
    int flag2=0;
    for(int i=str.size()-1;i>=0;i--){
        if(str[i] != 'a' && flag2 == 0) count++;
        else{
            flag2=1;
            satisfy2=true;
        }

        if(str[i] != 'a' && flag2 == 1){
                second_index = i;
                break;
        }
    }
    //step3
    for(int i=first_index;i<=second_index;i++){
        if( str[i] != 'b' ) count++;
        else satisfy3=true;
    }

    int ans;
    if(satisfy1==true && satisfy2==true && satisfy3==true) ans = str_size - count;
    else ans = -1;
    return ans;
}

int main()
{
    int t = 10;
    while(t--){
        string str;
        cout<<"Enter String"<<endl;
        cin>>str;
        cout << solve(str) <<endl;
    }
    return 0;
}
