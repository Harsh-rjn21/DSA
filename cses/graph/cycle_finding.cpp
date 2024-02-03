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
 

//finding neg wt cycle - belmen ford and storing parent -- cycle finding


vvi dict = {{-1,0},{1,0},{0,1},{0,-1}};
const int inf = 1e17;
const int ninf = -1e17;
 
 
void debug(int n=1,string s = "here"){
	cout<<n<<" "<<s<<endl;
}
 
 
void solve(){
 
	di(n);
	di(m);
 
	vvi edges;
 
	for(int i=0;i<m;i++){
		vi t;
		di(a);
		di(b);
		di(c);
		t.pub(a);
		t.pub(b);
		t.pub(c);
		edges.pub(t);
		// give(t,3);
	}
 
 
	vi dist(n+1,0);	
	vi p(n+1,-1);
 
	int x = -1;
 
	for(int i=1;i<=n;i++){
		x = -1;
		for(auto &e : edges){
			if(dist[e[1]] > dist[e[0]] + e[2]){
				dist[e[1]] = dist[e[0]] + e[2];
				p[e[1]] = e[0];
				x = e[0];
				// debug(1);
			}
		}
	}
 
	// give(dist,n+1);
 
	if(x==-1){
		cout<<"NO\n";
		return;
	}
 
	int z = n;
	while(z--){
		x = p[x];
	}
 
	vi ans;
	ans.pub(x);
 
	int y = p[x];
 
	while(y != x){
		ans.pub(y);
		y= p[y];
	}
 
	ans.pub(y);
 
	reverse(all(ans));
 
	cout<<"YES\n";
 
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
 
	cout<<endl;
 
 
 
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