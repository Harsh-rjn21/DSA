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
 
 
// use multisource bfs -- monsters
 
vvi dict = {{-1,0},{1,0},{0,1},{0,-1}};
 
 
 
	
 
void solve(){
 
	int n,m;
	cin>>n>>m;
 
	vector<string> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	vvi vis(n,vi (m,0));
 
	vector<vector<pii>> par(n,vector<pii> (m));
 
	pii st;
	
	queue<pair<int,pii>> q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(v[i][j] == 'M')
				q.push({1,{i,j}});
 
			if(v[i][j] == 'A'){
				st = {i,j};
			}
		}
	}
	if(st.first == n-1 || st.first==0 || st.second==m-1 || st.second==0){
		cout<<"YES\n0\n";
		return;
	}
	q.push({2,st});
	int ansi = -1;
	int ansj = -1;
	while(!q.empty()){
		// cout<<"here";
		pair<int,pii> x = q.front();
		q.pop();
		if(x.first==1){
			for(auto &e : dict){
				int in = e[0] + x.second.first;
				int jn = e[1] + x.second.second;
				if(in < n && jn<m && in >-1 && jn>-1 && (v[in][jn] == '.' || v[in][jn] == 'A')){
					v[in][jn] = 'M';
					q.push({1,{in,jn}});
				}
			}
		}else{
			for(auto &e : dict){
				int in = e[0] + x.second.first;
				int jn = e[1] + x.second.second;
				if(in < n && jn<m && in >-1 && jn>-1 && v[in][jn] == '.' && vis[in][jn] == 0){
					vis[in][jn] = 1;
					q.push({2,{in,jn}});
					par[in][jn] = {x.second.first,x.second.second};
					if((in == n-1 || in == 0) || (jn == m-1 || jn == 0)){
						ansi = in;
						ansj = jn;
						break;
					}
				}
			}
		}
		if(ansi != -1)break;
	}
 
	if(ansi == -1){
		cout<<"NO\n";
		return;
	}
 
	pii ans = {ansi,ansj};
 
	string az = "";
 
 
	while((ans.first != st.first) || ans.second != st.second){
		pii x = par[ans.first][ans.second];
		// cout<<x.first<<" "<<x.second<<endl;
		if(x.first - ans.first == 1){
			az += "U";
		}else if(x.first - ans.first == -1){
			az += "D";
		}else if(x.second - ans.second == 1){
			az += "L";
		}else {
			az += "R";
		}
		ans = x;
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