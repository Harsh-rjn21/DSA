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
// #define out(x) cout<<x<<endl;
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


//using scc - coin collector
//we find scc and make a new graph with nodes as each scc and we find edges btwn them. Now we have a DAG so we use dp and dfs.
 
vvi dict = {{-1,0},{1,0},{0,1},{0,-1}};
const int inf = 1e17;
const int ninf = -1e17;
const int M = 1e9 + 7;
 
 
void debug(int n=1,string s = "here"){
	cout<<n<<" "<<s<<endl;
}
 
const int N = 1e5 + 5;
vvi edges;
// vi g[N];
// vi rg[N];
int toskip;
 
 
 
void dfs_toposort(vi g[],int v,vi &vis,stack<int> &st){
	if(vis[v])return;
 
	vis[v] = 1;
	for(auto &ch : g[v]){
		dfs_toposort(g,ch,vis,st);
	}
	st.push(v);
}
 
 
//nodes form 1 to n
vi topoSort(vi g[],int n){
	stack<int> st;
	vi vis(n+1,0);
	for(int i=1;i<=n;i++){
		if(i==toskip)continue;
		if(!vis[i]){
			dfs_toposort(g,i,vis,st);
		}
	}
	vector<int> ans;
	while (!st.empty()) {
		ans.pub(st.top());
		st.pop();
	}
	return ans;
 
}
 
int cmp = 0;
vi comp;
 
void dfs(vi rg[],int v,vi &vis,vi &t){
	if(vis[v])return;
 
	vis[v] = 1;
	comp[v] = cmp;
	t.pub(v);
	for(auto &ch : rg[v]){
		dfs(rg,ch,vis,t);
	}
 
}
 
int f(vi ng[],vi &dp,vi &pathvis2,vi &val2,int v){
	if(dp[v] != -1)return dp[v];
 
	if(pathvis2[v])return 0;
	int ans = val2[v];
	pathvis2[v] = 1;
	int a = 0;
	for(auto &ch : ng[v]){
		a = max(a,f(ng,dp,pathvis2,val2,ch));
	}
	pathvis2[v] = 0;
	return dp[v] = ans + a;
 
}
 
 
void solve(){
 
 
	di(n);
	di(m);
 
	vi g[n+1];
	vi rg[n+1];
 
	comp.resize(n+1,-1);
	vi val(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>val[i];
	}
 
	for(int i=0;i<m;i++){
		di(a);
		di(b);
		g[a].pub(b);
		rg[b].pub(a);
		edges.pub({a,b});
	}
 
 
	vi vec = topoSort(g,n);
	vi vis(n+1,0);
	vvi scc;
	cmp = 0;
	for(int i=0;i<vec.size();i++){
		if(!vis[vec[i]]){
			vi t;
			dfs(rg,vec[i],vis,t);
			scc.pub(t);
			cmp++;
		}
	}
 
	vi ng[scc.size()];
	vi val2(scc.size(),0);
 
	int n2 = scc.size();
 
	for(int i=0;i<scc.size();i++){
		for(int j=0;j<scc[i].size();j++){
			val2[i] += val[scc[i][j]];
		}
	}
 
	// give(val2,n2);
 
	vii newedges;
	for(auto &e : edges){
		int u = comp[e[0]];
		int v = comp[e[1]];
		newedges.pub({u,v});
		if(u != v){
			// cout<<u<<" "<<v<<endl;
			ng[u].pub(v);
		}
	}
 
 
	vi dp(n2,-1);
 
	vi pathvis2(n2,0);
	int ans = 0;
	for(int i=0;i<n2;i++){
		if(dp[i] == -1){
			int a = f(ng,dp,pathvis2,val2,i);
			// cout<<a<<endl;
			ans = max(a,ans);
		}
	}
 
 
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