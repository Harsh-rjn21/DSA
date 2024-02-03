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



//Counting number of connected components in a adj matrix --  counting rooms

vvi dict = {{-1,0},{1,0},{0,1},{0,-1}};
 
void dfs(vector<string> &v,int i,int j ,vvi &vis){
	int n = v.size();
	int m = v[0].size();
	vis[i][j] = 1;
	for(auto &e : dict){
		int in = i + e[0];
		int jn = j + e[1];
		if(in<n && jn < m && in>-1 && jn >-1 && v[in][jn]=='.' && vis[in][jn]==0){
			dfs(v,in,jn,vis);
		}
	}
 
}
 
 
	
 
void solve(){
 
	int n,m;
	cin>>n>>m;

	vector<string> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	vvi vis(n,vi (m,0));
	int ct = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(vis[i][j] == 0 && v[i][j]=='.'){
				dfs(v,i,j,vis);
				ct++;
			}
		}
	}
 
	cout<<ct<<endl;
 
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