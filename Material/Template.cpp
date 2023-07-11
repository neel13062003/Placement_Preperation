/* Soni Neel Nikunjkumar = My Template */

#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#include<string>
#include<map>
#include<stack>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include <bits/stdc++.h>
#include <climits>


using namespace std;
#define ll long long

#define mod 1e7+7
//#define M 1000000007

//Declare Global array size
const int N=1e9;
int arr[N];


/*Most usefull stl function*/
/*
sort(vec.begin(),vec.end());                     //in acending order
sort(vec.begin(),vec.end(),greater<int>());      //in descending order
max(a,b);
min(a,b);
int gcd=__gcd(a,b);                                 //codecheff is best platform to pratise gcd type quesitons
*/

#define test int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define rtn return
#define pi (3.141592653589)
#define ll long long int


ll gcd(ll a, ll b){
    if (b == 0){
        rtn a;
    }
    rtn gcd(b, a % b);
}
ll lcm(ll a, ll b){
     return (a / gcd(a, b)) * b;
}

bool isprime(ll number)
{
    if (number <= 1)
        rtn false;
    if (number == 2)
        rtn true;
    if (number % 2 == 0)
        rtn false;
    ll boundary = (ll)floor(sqrt(number));
    for (ll i = 3; i <= boundary; i += 2)
        if (number % i == 0)
            rtn false;
    rtn true;
}

void primeFactors(ll n)      //https://practice.geeksforgeeks.org/problems/largest-prime-factor2601/1
{
    ll c=2;
    // while(n>1){
    // while(sqrt(n)){
    while(c * c <= n){    
        if(n%c==0){
            ans = c;
            n/=c;
        } else c++;
    }
    if (n > 1) {
        ans = n;
    }
    return ans;
}


bool perfectsq(double x)
{
    if (x>=0)
    {ll sr = sqrt(x); rtn (sr*sr==x);}
    rtn false;
}

void solve(){
     ll a,b,x;
     cin>>a>>b;

     string str;
     cin>>str;             // getline(cin,str);

     vector<ll>vec;
     for(int i=0;i<n;i++){
        cin>>x;
        vec.push_back(x);
     }

     /*Write Logic*/

}


int main(){

    ios_base::sync_with_stdio(false);                //For some faster executions
    cin.tie(NULL);

    int t=1;          // in google kickstart c=1;
    cin>>t;          //when test case is not require then comment it
    while(t--){
        solve();
        /*cout<<"Case #"<<c<<":"<<" "<<ans[1]<<endl;
        c++;*/
    }
    return 0;

    /*fast;
      test
      solve();
    */

}


/*Some usefull stl quick remeber */
    pair<int,int>p;
    vector<pair<int,int>>vec;
    map<int,int>mp;
    set<int>s;

   ***      stl = some usefull feature     ***
    map<template,template>mp;
    for(int i=0;i<vec.size();i++){
        mp[vec[i]]++;
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        int x=it->first;
        int y=it->second;
    }
    mp.clear();                      //very useful after usage


    ***  set ***
    set<template>s;
    for(int i=0;i<vec.size();i++){
        s.insert(vec[i]);
    }
    s.clear();
    s.size();

    vec.push_back( {  , });     //pair insert

    p=make_pair( , );
    vec.push_back(p);


    ***   2D vector input      **
    vector<vector<int,int>>vec;
    int x;
    for(int i=0;i<row;i++){
        vector<int>temp;
        for(int j=0;j<col;j++){
              cin>>x;
              temp.push_back(x);
        }
        vec.push_back(temp);
    }

    vec[i][j] we can access.


    ***   1D vector input    ***
    vector<int>vec(n);
    int x;
    for(int i=0;i<vec.size();i++){
       int x;
       vec.push_back(x);
    }


    ***** pair sorting using cmp****

    static bool cmp(pair<int,int>&A ,pair<int,int>&B){
        return A.first < B.first;                            //means ascending order and accourding to frist in pair
    }

    /*In class solution where gfg/leetcode where put static else put bool*/
    sort(vec.begin(),vec.end(),cmp);



    *** If call function of vetor like problem codecheff i solved prime factor divisble checke ***

    vector<int> Mywork(int n){
        return vector;
    }

    int main(){
        int n=5;
        vector<int>ans;
        ans = Mywork(n);
    }


    *** One Golden Rule in GFG/Leetcode or Where we are usign function ****


    => Whatever type our function is we always return in "Same manner";      == This is most important

    like example

    1) vector<int> Mywork( vector<int>&vec ){
       return vec;
    }
    2) int Mywork(int n){
        return n;
    }
    3)  string Mywork(string s){
        return str;
    }
    4) vector<vector<int,int> Mywork(int n){
        vector<vector<int,int>>x;
        return x;
    }
    5) bool int Mywork(int n){
        return true/false;
    }
    6)  Important never return function is exists in loop if there case use flag value then go outside & then use if-else




    **** Mateial  ****

    Revise STL => Take You forward => https://takeuforward.org/c/c-stl-tutorial-most-frequent-used-stl-containers/



    ****   Some important   ***

    1) For want to go outside loop and done our work => Break;

    2) Useing Flag Concepts is very very important   => p=1; like,,,

    3) Clear concept between      if-else         & if-if

    4) Array intialsie =>  int arr[] = {1,2,4,7};

    5) if(a<b) ? cout<<"a" <<endl : cout<<"b"<<endl;



    *** conversion  ****

    1) string to intger  = >
    string str;
    int n= stoi(str);           if 'char ch ' then use simply    = int(ch);

    2) Convert number to string
    int n;
    string str=to_string(n);

    3) s.size() == s.length();

    4) finding or checking string subpart as substring concept

    string str;
    str.substr( a, b );            //where a and b is position ;

    problem link => https://codeforces.com/contest/1759/problem/A
                 => https://www.codechef.com/problems/BROKENSTRING

    5) Convert concept of uppercase to lower case

    ASCII values for lower case alphabets (a-z):97 - 122
    ASCII values for upper case alphabets (A-Z):65 - 92

    islower(s);  isupper(s);

    for (int i = 0; i < ln; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            // Convert lowercase to uppercase
            str[i] = str[i] - 32;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            // Convert uppercase to lowercase
            str[i] = str[i] + 32;
    }

    6) for map
    for(auto it=mp.begin();it!=mp.end();it++){

    }
    it->second , it->first

    for(auto it:m){
        it.first,   it.second;
    }

    => When sorting is required then use map
    => when sorting is not => unordered_map

   => when only unique value =>set
   => when muliti value => multiset



    while in pair we access  like     p.first, p.second;

    7) Sorting using stl

    => in array = sort(arr,arr+n);
    => in vector = sort(vec.begin(),vec.end());

    in descedning add lastly        , greater<int>();

    reverse(vec.begin(),vec.end());        // reversing array

    & for using custom sorting use = sort(vec.begin(),vec.end(),cmp);

    bool cmp(){
        // create function  accordingto our requirements
    }
    
    8) return index 
       UpperBound return passes numbers slight next greater number index 
       LowerBound return passes numbers if presenet then index or next large number index 

        upper1 = std::upper_bound(v.begin(), v.end(), 35);
        std::cout << "\nupper_bound for element 35 is at position : "
              << (upper1 - v.begin());


       UpperBound = https://www.geeksforgeeks.org/upper_bound-in-cpp/
       LowerBound = https://www.geeksforgeeks.org/lower_bound-in-cpp/


    **    stack, queue, priority-queue  **

    stack<int>s;     s.push(x);       s.pop();
    queue<int>q;     same

    while(!s.empty()){
        s.pop()
        s.top()     like wise
    }



   *** some important trics  *****

   for always subtrac positive  use abs(a-b);

   floor()      // it convert value to lowest ineger
   ceil()   viceverse
   round()


   1) if compare character then if(n=='c')    & if string if(n== "string")

   logical operaotrs => && , || ,^ ,!

   2) power function = pow(a,b) = a raise to b

   3) declare minF= INT_MAX , maxF= INT_MIN;

   for(int i=0;i<vec.size();i++){
      minF= min(minF, vec[i]);
   }

   gcdF= vec[0];
   instead    minF= gcdF

   gcdF= __gcd(gcdF,vec[i]);         //gcd good practise on codecheff

   4) Finding Subarray

   for(int i=0;i<n;i++){
     for(int j=i;j<n;j++){        // here n=k means k size no subarray   , subarrya practise
        vec[j]
     }
   }


   5) Two Poiner => for(i=0,j=0;i<n,j<m;i++,j++){ access like

   while(true){          //infinte loop

      //condition
      break;
   }

   6)  if(anything)     ,  if inside is true then if work

   7)  swap(a,b);

   8)   ll nCr(ll n,ll r)
        {
            if(nCr1[n][r])rtn nCr1[n][r];
            if(r==1) rtn nCr1[n][r]=n;
            if(n==r) rtn nCr1[n][r]=1;
            if(r==0) rtn nCr1[n][r]=1;
            rtn nCr1[n][r]=(nCr(n-1,r) + nCr(n-1,r-1));
        }
        // !(n&(n-1)) --> n==2^x n&(n-1) --> n!=2^x
#define mod 1000000007
class Solution {
public:
    int nCr1[1001][1001];
    int nCr(int n, int r) {
        if (nCr1[n][r])
            return nCr1[n][r] % mod;

        // Base cases
        if (r == 0 || r == n)
            return nCr1[n][r] = 1;
        if (r == 1)
            return nCr1[n][r] = n;

        if (r > n)
            return nCr1[n][r] = 0;

        return nCr1[n][r] = (nCr(n - 1, r) + nCr(n - 1, r - 1)) % mod;
    }
};