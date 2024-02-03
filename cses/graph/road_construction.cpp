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
 
//using DSU -- road construction


vvi dict = {{-1,0},{1,0},{0,1},{0,-1}};
const int inf = 1e17;
const int ninf = -1e17;
const int M = 1e9 + 7;
 
 
void debug(int n=1,string s = "here"){
	cout<<n<<" "<<s<<endl;
}
 
const int N = 1e5 + 5;
vvi edges;
vi g[N];
 
 
class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
 
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
 
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
 
 
 
 
void solve(){
 
 
	di(n);
	di(m);
 
	DisjointSet ds(n+1);
	vi siz(n+1,1);
	int mx = 1;
	int nc = n;
	for(int i=0;i<m;i++){
		di(a);
		di(b);
		int x = ds.findUPar(a);
		int y = ds.findUPar(b);
		if(x != y){
			nc--;
			siz[x] += siz[y];
			siz[y] = siz[x];
		}
		
		mx = max(mx,siz[x]);
		ds.unionByRank(x,y);
 
		cout<<nc<<" "<<mx<<endl;
	}
 
	
 
 
 
 
 
 
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