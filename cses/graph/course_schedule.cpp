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
#define out(x) cout<<x<<endl;
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
 
//toposort -- course schedule

vvi dict = {{-1,0},{1,0},{0,1},{0,-1}};
const int inf = 1e17;
const int ninf = -1e17;
 
 
void debug(int n=1,string s = "here"){
	cout<<n<<" "<<s<<endl;
}
 
 
int cycle = 0;
 
 
void dfs(vi g[],int v,stack<int> &st,vi &vis,vi &pathvis){
	if(cycle)return;
	if(pathvis[v]){
		cycle = 1;
		return;
	}
	if(vis[v])return;
	pathvis[v] = 1;
	vis[v] = 1;
	for(auto &e : g[v]){
		dfs(g,e,st,vis,pathvis);
	}
 
	st.push(v);  //pushing after recursion call
	pathvis[v] = 0;
}
 
 
 
vi toposort(vi g[],int n){
	vi vis(n+1,0);
	stack<int> st;
 
	vi pathvis(n+1,0);
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(g,i,st,vis,pathvis);
		}
	}
 
	vi ans;
	while(!st.empty()){
		ans.pub(st.top());
		st.pop();
	}
 
	return ans;
 
}
 
 
void solve(){
 
	di(n);
	di(m);
 
	vi g[n+1];
 
	for(int i=0;i<m;i++){
		di(a);
		di(b);
		g[a].pub(b);
	}
 
 
	vi ans = toposort(g,n);
	if(cycle){
		cout<<"IMPOSSIBLE\n";
		return;
	}
 
	give(ans,ans.size());
 
	
 
 
 
 
 
 
	
 
 
 
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