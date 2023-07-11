/*TLE
#include <bits/stdc++.h>
using namespace std;

void solve(){
	long long n, M;
	cin>>n>>M;
	vector<long long>vec(n);

	for(long long i=0;i<n;i++){
		cin>>vec[i];
	}
	long long q;
	cin>>q;
	long long  x;
	long long maxi=INT_MIN;
	while(q--){
	   maxi=INT_MIN;
       cin>>x;
	   for(long long i=0;i<n;i++){
		   maxi = max(  maxi, (vec[i]+x)%M );
	   }
	   cout<<maxi<<endl;
	}

}

int main(){
	solve();
}*/
//Best Problem To Learn Modulo Clear
/*https://www.hackerearth.com/problem/algorithm/help-joe-ii/ */
/*3RD LUV CONTEST*/
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long a[N];
int main(){
    int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i] %= m;
	}
    sort(a,a+n);
	int q;
	cin>>q;
	while(q--){
		long long x;
		cin>>x;
		x %= m;
		long long *ptr = upper_bound(a,a+n, m-x-1);
		if(ptr != a){
			ptr--;
		}
		cout<<max( (a[n-1]+x)%m , (*ptr+x)%m)<<endl;
	}
    return 0;
}
