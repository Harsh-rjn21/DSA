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
 
//finding path between two nodes -- labyrinth
 
vvi dict = {{-1,0},{1,0},{0,1},{0,-1}}; 
	
 
void solve(){
 
	int n,m;
	cin>>n>>m;
 
	vector<string> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	vvi vis(n,vi (m,0));
	
	vector<vector<pii>> par(n,vii (m));
 
	queue<pii> q;
	pii end;
	pii st;
 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(v[i][j] == 'A'){
				q.push({i,j});
				vis[i][j] = 1;
				st = {i,j};
			}
			if(v[i][j] == 'B'){
				end = {i,j};
			}
		}
	}
 
	int ass = 0;
	while(!q.empty()){
 
 
		if(ass)break;
 
		pii x = q.front();
		q.pop();
		// cout<<x.first<<" "<<x.second<<endl;
 
		for(auto &e : dict){
			int in = x.first + e[0];
			int jn = x.second + e[1];
 
			if(in<n && jn<m && in>-1 && jn>-1 && v[in][jn] != '#' && vis[in][jn] == 0){
 
				par[in][jn] = x;
				vis[in][jn] = 1;
				q.push({in,jn});
				if(in == end.first && jn == end.second){
					ass = 1;
					break;
				}
 
			}
		}
		
	}
 
 
	if(ass==0){
		cout<<"NO\n";
		return;
	}
 
	pii y = end;
 
	string az = "";
 
	while(y != st){
		pii z = par[y.first][y.second];
		if(z.first - y.first == 1){
			az += "U";
		}else if(z.first - y.first == -1){
			az += "D";
		}else if(z.second - y.second == 1){
			az += "L";
		}else{
			az += "R";
		}
		y = z;
	}
 
	reverse(all(az));
	cout<<"YES\n";
	cout<<az.size()<<endl;
	cout<<az<<endl;
	
 
 
 
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