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

//finding eulerian path in DAG - hierholzer's algorithm -- teleporters path
//yt video - https://www.youtube.com/watch?v=8MpoO2zA2l4


vvi dict = {{-1,0},{1,0},{0,1},{0,-1}};
const int inf = 1e17;
const int ninf = -1e17;
const int M = 1e9 + 7;
 
 
void debug(int n=1,string s = "here"){
    cout<<n<<" "<<s<<endl;
}
 
const int N = 1e5 +5;
int n,m;
vi g[N];
vvi edges;
map<pii,int> edgevis;
vi in(N,0);
vi out(N,0);
int stnode=1,endnode = 1;
 
 
void dfs_toCheckEular(vi &vis,int node){
	if(vis[node])return;
	vis[node] = 1;
	for(auto &ch : g[node]){
		dfs_toCheckEular(vis,ch);
	}
}
 
 
int checkIfEularPathPresent(int n){
	int st = 0,end = 0;
	for(int i=1;i<=n;i++){
		if(out[i] - in[i] == 1){
			st++;
			stnode = i;
		}
		else if(in[i] - out[i] == 1){
			end++;
			endnode = i;
		}
		else if(out[i] != in[i])return 0;
	}
 
	int x =  ((st==0 && end==0) || (st==1 && end==1));
	if(x==0)return 0;
 
 
	vi vis(n+1,0);
 
	dfs_toCheckEular(vis,stnode);
 
	for(int i=1;i<=n;i++){
		if(vis[i] == 0 && (in[i] || out[i])){
			return 0;
		}
	}
 
	return 1;
 
}
 
void dfs(vi &ans,int node){
 
	while(g[node].size()){
		int next = g[node].back();
		g[node].pop_back();
		dfs(ans,next);
	}
	ans.pub(node);
}
 
 
vi findEularPath(int n){
	vi ans;
	dfs(ans,1);
	return ans;
 
}
 
 
 
void solve(){
 
 
    cin>>n;
    cin>>m;
 
    for(int i=0;i<m;i++){
    	di(u);
    	di(v);
    	g[u].pub(v);
    	edges.pub({u,v});
    	out[u]++;
    	in[v]++;
    	edgevis[{u,v}] = 0;
    }
 
    if(checkIfEularPathPresent(n) == 0){
    	cout<<"IMPOSSIBLE\n";
    	return;
    }
 
 
 
    vi ans = findEularPath(n);
    reverse(all(ans));
    if(ans[ans.size() -1] != n || ans.size() != m+1){
    	cout<<"IMPOSSIBLE\n";
    	return;
    }
    for(int i=0;i<ans.size();i++){
    	cout<<ans[i]<<" ";
    }cout<<endl;
  
 
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