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
 
 
vvi dict = {{-1,0},{1,0},{0,1},{0,-1}};
const int inf = 1e17;
const int ninf = -1e17;
 
 
void debug(int n=1,string s = "here"){
	cout<<n<<" "<<s<<endl;
}
 
vector<bool> vis;
vi par;
int sv=-1,ev=-1;
 
stack<int> stk;
 
vi ans;
 
bool dfs(vi g[],int n,int v,vector<bool> &pathvis){
 
	// cout<<v<<endl;
	
	for(auto &ch : g[v]){
		if(pathvis[ch]){
			sv = v;
			ev = ch;
			par[ch] = v;
			stk.push(ch);
			return true;
		}
		if(vis[ch])continue;  //important
		vis[ch] = true;
		pathvis[ch] = true;
		par[ch] = v;
		stk.push(ch);
		if(dfs(g,n,ch,pathvis))return true;
		stk.pop();
		pathvis[ch] = false;
	}
 
	return false;
}
 
bool vis_all(vi g[],int n){
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vector<bool> pathvis(n+1,false);
			if(dfs(g,n,i,pathvis))return true;
		}
	}
	return false;
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
 
	vis.resize(n+1,false);
	par.resize(n+1,-1);
 
	if(!vis_all(g,n)){
		cout<<"IMPOSSIBLE\n";
		return;
	}
 
 
	vi ans;
 
	int tv = sv;
	ans.pub(ev);
	while(tv != ev){
		// cout<<tv<<endl;
		ans.pub(tv);
		tv = par[tv];
	}
	ans.pub(tv);
  
	reverse(all(ans));
 
	cout<<ans.size()<<endl;
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