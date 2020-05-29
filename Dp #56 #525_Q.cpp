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
char ch[3][110];
ll a;

bool dp[4][110];
bool vis[4][110];

bool check=0;
bool train(ll x, ll y){
	if(y>=a-1) {return 1;}
	if(vis[x][y]) return dp[x][y];
	bool p1=false;
	bool p2=false;
	bool p3=false;
	vis[x][y]=1;
	if(x==0){
		if(ch[x][y+3]=='.' && ch[x][y+1]=='.' && ch[x][y+2]=='.'){
			p1=train(x,y+3);
		}
		if(ch[x+1][y+3]=='.' && ch[x+1][y+1]=='.' && ch[x+1][y+2]=='.'  && ch[x][y+1]=='.') p2=train(x+1,y+3);
		return dp[x][y]=p1||p2;
	}
	else if(x==1){
		if(ch[x][y+3]=='.' && ch[x][y+1]=='.' && ch[x][y+2]=='.'){
			p1=train(x,y+3);
		}
		if(ch[x+1][y+3]=='.' && ch[x+1][y+1]=='.' && ch[x+1][y+2]=='.'  && ch[x][y+1]=='.') p2=train(x+1,y+3);
		if(ch[x-1][y+3]=='.'&& ch[x-1][y+1]=='.' && ch[x-1][y+2]=='.'  && ch[x][y+1]=='.') p3=train(x-1,y+3);
		return dp[x][y]=p1||p2||p3;
	}
	else if(x==2){
		if(ch[x][y+3]=='.' && ch[x][y+1]=='.' && ch[x][y+2]=='.'){
			p1=train(x,y+3);
		}
		if(ch[x-1][y+3]=='.'&& ch[x-1][y+1]=='.' && ch[x-1][y+2]=='.'  && ch[x][y+1]=='.'){ p3=train(x-1,y+3);}
		return dp[x][y]=p1||p3;
	}
	return false;
}

int main() {
	fast;
	time;
	#ifndef ONLINE_JUDGE
 	 	freopen("input.txt","r",stdin);
	  	freopen("output.txt","w",stdout);
	#endif
  	memset(visited,false,sizeof(visited));
	read(t)

	while(t--){

		memset(dp,false,sizeof(dp));
		memset(vis,false,sizeof(vis));
		cin>>a;
		read(b)
		ll x=0;
		ll y=0;
		loop(j,0,3){
			loop(i,0,a){
				readc(chr);
				ch[j][i]=chr;
				if(chr=='s') x=j,y=i;	
				if(chr!='.') ch[j][i]='*';
			
			}
		}
		ll p=a;
		loop(j,0,3){
			loop(i,0,3){
				ch[j][p+i]='.';
			}
		}
	bool flag=train(x,y);
	if(flag){
		yes
	}
	else no;
	}

	return 0;
}

//ends here 