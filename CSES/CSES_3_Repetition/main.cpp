#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int countA=0,countC=0,countG=0,countT=0;
    int maxi = 0;
    for(int i=0;i<str.size();i++){
        if(str[i] == 'A'){
            countA++;
            countC=0,countG=0,countT=0;
            maxi = max(maxi,countA);
        }
        else if(str[i] == 'C'){
            countC++;
            countA=0,countG=0,countT=0;
            maxi = max(maxi,countC);
        }
        else if(str[i] == 'T'){
            countT++;
            countA=0,countC=0,countG=0;
            maxi = max(maxi,countT);
        }
        else if(str[i] == 'G'){
            countG++;
            countA=0,countC=0,countT=0;
            maxi = max(maxi,countG);
        }
    }
    cout<<maxi<<endl;
    return 0;
}
