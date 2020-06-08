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
#define 	setbits(x) __builtin_popcountll(x)
#define 	zrobits(x) __builtin_ctzll(x)
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
 
void constructTree(ll input[], ll segTree[], ll low, ll high, ll pos){
	if(low==high){
		segTree[pos]=input[low];
		return ;
	}
	ll mid=(low+high)/2;
	constructTree(input,segTree,low,mid,2*pos+1);
	constructTree(input,segTree,mid+1,high,2*pos+2);
	segTree[pos]=min(segTree[2*pos+1],segTree[2*pos+2]);
}
 
 
vector<ll>adj[200100];
bool visited[110][110];
char arr[110][110];
ll n, m;
 
void dfs(ll a, ll b){
	if(arr[a+1][b]=='.' && a+1<n){arr[a+1][b]='#';}
	if(arr[a][b+1]=='.' && b+1<m){arr[a][b+1]='#';}	
	if(arr[a-1][b]=='.' && a-1>=0){arr[a-1][b]='#';}	
	if(arr[a][b-1]=='.' && b-1>=0){arr[a][b-1]='#';}
	return ;
}
 
bool flag=false;
 
void dfs1(ll a, ll b){
	visited[a][b]=true;
	if(arr[a][b]=='#') return ;
	if((arr[a+1][b]=='.' || arr[a+1][b]=='G' || arr[a+1][b]=='B')  && a+1<n && !visited[a+1][b]){dfs1(a+1,b);}
	if((arr[a][b+1]=='.' || arr[a][b+1]=='G' || arr[a][b+1]=='B') && b+1<m && !visited[a][b+1]){dfs1(a,b+1);}	
	if((arr[a-1][b]=='.' || arr[a-1][b]=='G' || arr[a-1][b]=='B') && a-1>=0 && !visited[a-1][b]){dfs1(a-1,b);}	
	if((arr[a][b-1]=='.' || arr[a][b-1]=='G' || arr[a][b-1]=='B') && b-1>=0 && !visited[a][b-1]){dfs1(a,b-1);}
	return ;
}
 
int main() {
	fast;
	time;
	#ifndef ONLINE_JUDGE
 	 	freopen("input.txt","r",stdin);
	  	freopen("output.txt","w",stdout);
	#endif
  	memset(visited,false,sizeof(visited));
	read(a)
	while(a--){
  		memset(visited,false,sizeof(visited));
  		memset(arr,'.',sizeof(arr));
		cin>>n>>m;
		vector<pair<ll,ll>>vecg;
		vector<pair<ll,ll>>vecb;
		loop(j,0,n){
			loop(i,0,m){
				cin>>arr[j][i];
				if(arr[j][i]=='B') vecb.pb(mp(j,i));
				if(arr[j][i]=='G') vecg.pb(mp(j,i));
			}
		}
 
 
 
		fsort(vecb);
 
		loopitr(vecb){
			dfs(itr->ff,itr->ss);
		}
		ll cnt=0;
		ll cntb=0;

		dfs1(n-1,m-1);
		bool flag2=false;

		loopitr(vecg){
			if(!visited[itr->ff][itr->ss]){
				flag2=true;
				break;
			}
		}

 		bool flag1=false;
 
		loopitr(vecb){
			ll p=itr->ff;
			ll l=itr->ss;
			if(arr[p-1][l]=='G') flag1=true;
			if(arr[p+1][l]=='G') flag1=true;	
			if(arr[p][l+1]=='G') flag1=true;	
			if(arr[p][l-1]=='G') flag1=true;	
 
			if(flag1) break;
 
		}
 		

		if(flag1 || flag2) no
		else yes

		vecg.clear();
		vecb.clear();

	}
	return 0;
}