#include 	<ext/pb_ds/assoc_container.hpp> 
#include 	<ext/pb_ds/tree_policy.hpp> 
#include 	<iostream>
#include 	<queue>
#include 	<tuple>
#include 	<vector>
#include	<bits/stdc++.h>
#include	<algorithm>
#include 	<cmath>
#include 	<map>
#include 	<string>
#include 	<iomanip> 
using 		namespace __gnu_pbds; 
using 		namespace std;
#define 	ll  long long int
#define		read(a) long long int a; cin>>a;
#define 	readstr(s) string s; cin>>s;
#define 	readarr(a,l) long long int a[l]={0}; for(ll i=0;i<l;i++) cin>>a[i];
#define 	readc(c) char c; cin>>c;
#define 	loop(i,a,b) for(ll i=a;i<b;i++)
#define 	rloop(i,a,b) for(ll i=a;i>b;i--)
#define 	loopitr(vec) for(auto it=vec.begin();it!=vec.end();it++)
#define 	ff first
#define 	ss second
#define 	readmtrx(i,j,a,b) ll arr[a][b]={0};for(ll i=0;i<a;i++)for(ll j=0;j<b;j++) cin>>arr[i][j];
#define 	v(pi) vector<ll>pi
#define 	all(a) a.begin(), a.end()
#define 	yes cout <<"YES"<<endl;
#define 	no cout <<"NO"<<endl;
#define 	sc(x) cout << (#x) << " is " << (x) << endl;
#define 	vp(pi) vector<pair<ll,ll>>pi
#define 	fast ios_base::sync_with_stdio(false);cin.tie(0);
#define 	pb(p) push_back(p)
#define 	mp make_pair
#define 	mi(lol) map<ll,ll>lol
#define 	fsort(vec) sort(vec.begin(),vec.end())
#define 	rsort(vec) sort(vec.begin(),vec.end(),compare)
#define 	Endl endl
#define 	ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define 	roundoff std::cout << std::setprecision(15)
#define 	inf 9223372036854775807
#define 	infn -9223372036854775807
#define 	pi 3.14159265358979323846
const 		int mod = 1e9+7; 
#define 	REVERSE(vec) reverse(vec.begin(),vec.end())


ll gcd (ll a, ll b) { return b ? gcd (b, a % b) : a; }
ll lcm (ll a, ll b) { return a / gcd(a, b) * b; }

//code start from here 
char ch[10005][10005];
ll dp[10005][10005];x

ll path(ll i, ll j, ll a,ll b){
	if(dp[i][j]!=-1) return (dp[i][j])%mod;
	if(i==a-1 && j==b-1) return dp[i][j]=1;
	if(i==a-1 && ch[i][j+1]=='#') return dp[i][j]=0;
	if(j==b-1 && ch[i+1][j]=='.' && i+1<=a-1) return dp[i][j]=(path(i+1,j,a,b))%mod;
	if(j==b-1 && ch[i+1][j]=='#') return dp[i][j]=0;
	if(ch[i+1][j]!='#' && ch[i][j+1]!='#' && j+1<=b-1 && i+1<=a-1) return dp[i][j]=(path(i+1,j,a,b)+path(i,j+1,a,b))%mod;
	if(ch[i][j+1]!='#' && ch[i+1][j]!='.' && j+1<=b-1) return dp[i][j]=path(i,j+1,a,b)%mod;
	if(ch[i][j+1]=='#' && ch[i+1][j]=='.' && i+1<=a-1) return dp[i][j]=path(i+1,j,a,b)%mod; 
	if(ch[i][j+1]=='#' && ch[i+1][j]=='#') return dp[i][j]=0;
	return 1;
}

int main() {
	fast;
	#ifndef ONLINE_JUDGE
 	 	freopen("input.txt","r",stdin);
	  	freopen("output.txt","w",stdout);
	#endif
	read(rr)
	loop(e,0,rr){
	read(a)
	read(b)
	read(temp);
	vector<pair<ll,ll>>vec;
	loop(j,0,temp){
		read(t)
		read(p)
		vec.pb(mp(t,p));
	}
	loop(j,0,a){
		loop(i,0,b){
			ch[j][i]='.';
		}
	}
	loop(j,0,vec.size()){
		ch[vec[j].ff-1][vec[j].ss-1]='#';
	}
	memset(dp,-1,sizeof(dp));
	ll i=0;ll j=0;
	if(ch[a-1][b-1]=='#'){cout<<0<<endl;continue;}
	cout<<path(i,j,a,b)<<endl;
}
	return 0;
}

//ends here 