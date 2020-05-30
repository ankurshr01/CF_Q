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
const 		int mod = 998244353 ; 
#define 	intsize(num) trunc(log10(num)) + 1
#define 	REVERSE(vec) reverse(vec.begin(),vec.end())
using 		namespace __gnu_pbds; 
using 		namespace std;

ll gcd (ll a, ll b) { return b ? gcd (b, a % b) : a; }
ll lcm (ll a, ll b) { return a / gcd(a, b) * b; }

//code start from here 

vector<ll>adj[300100];
bool visited[300100];
bool flag=true;
ll check[300100];
ll mp1[3]={0};
const int N = int(3e5) + 999;
int p2[N];



ll k=0;

void dfs(ll a, ll b){
	mp1[b]++;
	visited[a]=true;
	check[a]=b;
	loop(j,0,adj[a].size()){
		if(!visited[adj[a][j]]){
			if(b==1) k=2;
			else k=1;
			dfs(adj[a][j],k);
		}
		else {
			if(check[adj[a][j]]==b){flag=false;return;}

		}
	}
}
 ll dp[300100];
ll pwer(ll a, ll b){
 
	ll l=1;
	if(dp[a]==-1){
		loop(j,1,a+1){
			l=l*2;
			l%=mod;
		}
		dp[a]=l;
	}	
	ll p=1;
	if(dp[b]==-1){
		loop(j,1,b+1){
			p*=2;
			p%=mod;
		}
		dp[b]=p;
	}
	return (dp[a]+dp[b])%mod;
}
 
int main() {
	fast;
	time;

	#ifndef ONLINE_JUDGE
 	 	freopen("input.txt","r",stdin);
	  	freopen("output.txt","w",stdout);
	#endif	
	p2[0] = 1;
    for(int i = 1; i < N; ++i)
    p2[i] = (2 * p2[i - 1]) % mod;	
	memset(dp,-1,sizeof(dp));
	int t;
    scanf("%d", &t);	
	while(t--){
	  	// memset(visited,false,sizeof(visited));
	  	// memset(check,-1,sizeof(check));		

		int n , m; 
		scanf("%d%d", &n, &m);
		loop(j,1,n+1) visited[j]=false;
		loop(j,1,n+1) check[j]=-1;
		loop(j,1,n+1) adj[j].clear();
		while(m--){
			int z, x;
    		scanf("%d %d", &z, &x);
			adj[x].pb(z);
			adj[z].pb(x);
		}
		ll sum=1;
		bool boo=true;
		flag=true;
	  	sum=1;
	 	mp1[1]=0;
		mp1[2]=0;
		loop(j,1,n+1){
			if(!visited[j]){
				dfs(j,1);
				if(!flag){cout<<0<<endl;boo=false;break;}
				ll mm=pwer(mp1[1],mp1[2])%mod;
				sum=sum*mm*1LL;
				sum%=mod;
				mp1[1]=0;
				mp1[2]=0;
			}
		}

		mp1[1]=0;
		mp1[2]=0;
		if(boo){
			cout<<sum<<'\n';
		}
	}
	return 0;
}

//ends here 