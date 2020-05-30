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
#include 	<ctype.h>
#define 	ll  long long int
#define		read(a) long long int a; cin>>a;
#define		in(a) long long int a; cin>>a;
#define 	readstr(s) string s; cin>>s;
#define 	readc(c) char c; cin>>c;
#define 	readarr(a,l) long long int a[l]={0}; for(ll i=0;i<l;i++) cin>>a[i];
#define 	loop(i,a,b) for(ll i=a;i<b;i++)
#define 	rloop(i,a,b) for(ll i=a;i>b;i--)
#define 	loopchar() for(char c='a';c<='z';c++)
#define 	printarr(a, n) fori (i, 1, n) cout << a[i] << " "; cout << endl;
#define		printv(v) for (int i: v) cout << i << " "; cout << endl;
#define 	loopitr(vec) for(auto itr=vec.begin();itr!=vec.end();itr++)
#define 	ff first
#define 	ss second
#define 	readmtrx(i,j,a,b) ll arr[a][b]={0};for(ll i=0;i<a;i++)for(ll j=0;j<b;j++) cin>>arr[i][j];
#define 	time cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n"
#define 	all(a) a.begin(), a.end()
#define 	yes cout <<"YES"<<endl;
#define 	no cout <<"NO"<<endl;
#define 	sc(x) cout << (#x) << " is " << (x) << endl;
#define 	fast ios_base::sync_with_stdio(false);cin.tie(0);
#define 	pb(p) push_back(p)
#define 	mp make_pair
#define 	fsort(vec) sort(vec.begin(),vec.end())
#define 	rsort(vec) sort(vec.begin(),vec.end(),compare)
#define 	endl '\n'
#define 	Endl endl
#define 	ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define 	roundoff std::cout << std::setprecision(15)
#define 	inf 9223372036854775807
#define 	infn -9223372036854775807
#define 	pi 3.14159265358979323846
const 		int mod = 1e9+7; 
#define 	intsize(num) trunc(log10(num)) + 1
#define 	REVERSE(vec) reverse(vec.begin(),vec.end())
using 		namespace __gnu_pbds; 
using 		namespace std;

ll gcd (ll a, ll b) { return b ? gcd (b, a % b) : a; }
ll lcm (ll a, ll b) { return a / gcd(a, b) * b; }

//code start from here 

vector<ll>adj[200100];
bool visited[200100];

char ch[1001][1001];
ll steps;
// string s;
vector<char>vec;
string ss="DLRU";
ll a;
ll b;

bool pp=false;
ll dp[1001][1001];

bool dfs(ll x, ll y, ll st){
	if(dp[x][y]!=-1) return dp[x][y];
	if(st==steps) {return dp[x][y]=pp=true;}
	if(x+1<a && ch[x+1][y]=='.'){vec.pb('D'); return dp[x][y]=pp||dfs(x+1,y,st+1);}
	else if(y-1>=0 && ch[x][y-1]=='.'){vec.pb('L'); return dp[x][y]=pp||dfs(x,y-1,st+1);}
	else if(y+1<b && ch[x][y+1]=='.'){vec.pb('R'); return dp[x][y]=pp||dfs(x,y+1,st+1);}
	else if(x-1>=0 && ch[x-1][y]=='.'){vec.pb('U'); return dp[x][y]=pp||dfs(x-1,y,st+1);}
	return dp[x][y]=pp||false;
}



int main() {
	fast;
	time;
	#ifndef ONLINE_JUDGE
 	 	freopen("input.txt","r",stdin);
	  	freopen("output.txt","w",stdout);
	#endif
	memset(dp,-1,sizeof(dp));
  	memset(visited,false,sizeof(visited));
  	cin>>a>>b;
	ll x=0;
	ll y=0;
	cin>>steps;
	if(steps%2!=0) { cout<<"IMPOSSIBLE"<<endl; return 0;}
	ll t=steps;
	steps/=2;
	loop(j,0,a){
		loop(i,0,b){
			readc(c)
			ch[j][i]=c;
			if(ch[j][i]=='X') {
				x=j;
				y=i;
			}
		}
	}
	bool flag=dfs(x,y,0);
	if(flag)
	{	
		ll p=vec.size();
		loop(j,0,p){
			if(vec[p-1-j]=='L') vec.pb('R');
			if(vec[p-1-j]=='R') vec.pb('L');
			if(vec[p-1-j]=='D') vec.pb('U');
			if(vec[p-1-j]=='U') vec.pb('D');
		}
		loopitr(vec) cout<<*itr;
	}
	else {
		if(vec.size()==0) {cout<<"IMPOSSIBLE"<<endl; return 0;}
		ll p=vec.size();
		loop(j,0,p){
			if(vec[p-1-j]=='L') vec.pb('R');
			if(vec[p-1-j]=='R') vec.pb('L');
			if(vec[p-1-j]=='D') vec.pb('U');
			if(vec[p-1-j]=='U') vec.pb('D');
		}
		ll u=(t-vec.size()/vec.size());
		while(u--){
			loopitr(vec) cout<<*itr;
		}
	}
	return 0;
}

//ends here 