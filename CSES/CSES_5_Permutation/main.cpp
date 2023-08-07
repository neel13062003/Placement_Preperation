#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>vec(n+1);
    for(int i=0;i<n;i++){
        vec.push_back(i+1);
    }
    if(n == 1) cout<<"1"<<endl;
    else if(n==2) cout<<"NO SOLUTION"<<endl;
    else if(n==3) cout<<"NO SOLUTION"<<endl;
    else if(n==4) cout<<"3 1 4 2"<<endl;
    else{
        vector<int>vec1;
        vector<int>vec2;
        for(int i=0;i<vec.size();i++){
            if(vec[i] % 2 == 0) vec2.push_back(vec[i]);
            else vec1.push_back(vec[i]);
        }
        int x = vec2.size();
        cout<< vec2[x-1] << " ";
        for(int i=0;i<vec1.size();i++){
            cout << vec1[i] << " ";
        }
        for(int i=0;i<vec2.size()-1;i++){
            if(vec2[i] != 0) cout << vec2[i] << " ";
        }
    }
    return 0;
}
