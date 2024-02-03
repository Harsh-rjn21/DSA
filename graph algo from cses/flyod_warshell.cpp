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
 
// flyod warshell algo - finding shortest path from all the vertices to every other vertices
// is based on calculating path between two nodes via every node and taking its minimum
// shortest path II
 
	
 
void solve(){
 
	int n,m;
	cin>>n>>m;
    di(q);
  
    vvi dist(n+1,vi (n+1,1e17));
	for(int i=0;i<m;i++){
		di(x);
		di(y);
		di(z);
        dist[x][y] = min(dist[x][y],z);
        dist[y][x] = min(dist[y][x],z);
	}
 
    for(int i=1;i<=n;i++){
        dist[i][i] = 0;
    }
 
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                dist[j][k] = min(dist[j][k],dist[j][i] + dist[i][k]);
            }
        }
    }
 
 
    
    while(q--){
        di(x);
        di(y);
        int ans = dist[x][y];
        if(ans>=1e17){
            cout<<"-1\n";
            continue;
        }
        cout<<ans<<endl;
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