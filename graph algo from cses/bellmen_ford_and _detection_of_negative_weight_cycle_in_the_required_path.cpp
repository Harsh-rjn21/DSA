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
 
//first bellmen ford to find to shortest path and detect a negative wt cycle then we check if the negative wt cycle is in the path or not(using reverse graph) -- high score


vvi dict = {{-1,0},{1,0},{0,1},{0,-1}};
 
 
int dfs(vi rg[],int v,vi &vis,vi &vis2){
 
	if(vis[v])return 1;
	if(vis2[v])return 0;
	vis2[v] = 1;
	int ans = 0;
	for(auto &e : rg[v]){
		ans |= dfs(rg,e,vis,vis2);
	}
 
	return ans;
 
}
 
 
	
 
void solve(){
 
	int n,m;
	cin>>n>>m;
 
	vii g[n+1];
	vvi edges;
	for(int i=0;i<m;i++){
		di(x);
		di(y);
		di(z);
		vi t;
		t.pub(x);
		t.pub(y);
		t.pub(-z);
		edges.pub(t);
	}
 
	vi dist(n+1,1e18);
	dist[1] = 0;
 
 
	for(int i=1;i<n;i++){
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] != 1e18 && dist[u] + wt < dist[v]) {
				dist[v] = dist[u] + wt;
			}
		}
	}
	int x = dist[n];
 
	vi vis(n+1,0);
	
	for(auto &e : edges){
		if(dist[e[1]] > dist[e[0]] + e[2] && dist[e[0]] != 1e18){
			vis[e[1]] = 1;
		}
	}
 
	vi rg[n+1];
 
	for(auto &e : edges){
		rg[e[1]].pub(e[0]);
	}
 
	vi vis2(n+1,0);
 
	int ans = dfs(rg,n,vis,vis2);
	
	if(ans == 1){
		cout<<"-1\n";
		return;
	}	
 
 
	cout<<(-1*dist[n])<<endl;
 
 
	
	
 
 
 
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