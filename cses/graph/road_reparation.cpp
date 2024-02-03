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
#define maxheap(x) priority_queue<x>
#define minheap(x) priority_queue<x,vector<x>,greater<x>>
 
//minimum spanning tree -- road reparation

vvi dict = {{-1,0},{1,0},{0,1},{0,-1}};
const int inf = 1e17;
const int ninf = -1e17;
const int M = 1e9 + 7;
 
 
void debug(int n=1,string s = "here"){
	cout<<n<<" "<<s<<endl;
}
 
const int N = 1e5 + 5;
vvi edges;
vii g[N];
 
 
 
 
void solve(){
 
 
	di(n);
	di(m);
 
	for(int i=0;i<m;i++){
		di(a);
		di(b);
		di(c);
		edges.pub({a,b,c});
		g[a].pub({b,c});
		g[b].pub({a,c});
	}
 
	vi vis(n+1,0);
	minheap(pii) q;
	q.push({0,1});
 
	int ans = 0;
 
	while(!q.empty()){
		pii x = q.top();
		q.pop();
		if(vis[x.second])continue;
		vis[x.second] = 1;
		ans += x.first;
 
		for(auto &e : g[x.second]){
			if(!vis[e.first]){
				q.push({e.second,e.first});
			}
		}
 
	}
 
 
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			cout<<"IMPOSSIBLE\n";
			return;
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