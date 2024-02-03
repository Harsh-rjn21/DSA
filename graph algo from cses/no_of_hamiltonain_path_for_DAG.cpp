#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#include<cmath>
#define int  long long
#define vi vector<int>
#define vec(x) vector<x>
#define vii vector<pair<int,int>>
#define pii pair<int,int>
#define vvi vector<vector<int>>
#define seti set<int>
#define setc set<char>
#define setstr set<string>
#define set(x) set<x>
#define mii map<int,int>
#define check(x) if(x)cout<<"YES\n"; else cout<<"NO\n";
#define rev(x) reverse(x)
#define all(x) x.begin(), x.end()
#define inp(x) cin>>x;
#define endl "\n"
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define repin rep(i,0,n)
#define fi first
#define se second
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define sz(x) (int)(x).size()
#define take(a,n) for(int j=0;j<n;j++) cin>>a[j];
#define give(a,n) for(int j=0;j<n;j++)cout<<a[j]<<' ';cout<<endl;
#define di(a) int a;cin>>a;
#define si(a) string a;cin>>a;
#define maxv(v) *max_element(all(v))
#define minv(v) *min_element(all(v))
#define maxheap(x) priority_queue<x>
#define minheap(x) priority_queue<x,vector<x>,greater<x>>

//using dp with bitmasking -- hamiltonian path for DAG -- hamiltonian flights
//yt video - https://www.youtube.com/watch?v=rj1EsYuWTYY
 
 
vvi dict = {{-1,0},{1,0},{0,1},{0,-1}};
const int inf = 1e17;
const int ninf = -1e17;
const int M = 1e9 + 7;
const int N = 22;
const int N2 = pow(2,19) + 10;
 
 
void debug(int n=1,string s = "here"){
    cout<<n<<" "<<s<<endl;
}
 
int n,m;
vi g[N];
vvi dp;
 
 
int f(int cur,int vis){
	if(cur == n && vis == (int)(pow(2,n) -1)){
		// cout<<vis<<endl;
		return 1;
	}
	if(cur == n)return 0;
 
	// cout<<dp[vis][cur]<<endl;
	if(dp[vis][cur] != -1)return dp[vis][cur];
 
	int ans = 0;
	for(auto &e : g[cur]){
		if((1<<(e-1)) & vis)continue;
		int newvis = vis | (1<<(e-1));
		// cout<<cur<<" "<<e<<" "<<newvis<<endl;
		ans += f(e,newvis);
		ans %= M;
	}
 
	// return ans;
	return dp[vis][cur] = ans%M;
 
}
 
 
 
void solve(){
 
 	cin>>n;
 	cin>>m;
 
 	for(int i=0;i<m;i++){
 		di(u);
 		di(v);
 		g[u].pub(v);
 	}
 
 	dp.resize(N2,vi (n+1,-1));
    
    int ans = f(1,1);
    cout<<ans<<endl;   
  
 
}
 
 
 
 
 
 
 
 signed main()
{       
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin.exceptions(ios::badbit | ios::failbit);
 
    int t;
    // cin>>t;
    t=1;
 
    while(t--){
 
        solve();
    }
 
    // solve();
 
    return 0;
 
 }
