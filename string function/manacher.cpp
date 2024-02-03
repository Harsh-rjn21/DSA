#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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


 
vvi dict = {{-1,0},{1,0},{0,1},{0,-1}};
const int inf = 1e17;
const int ninf = -1e17;
const int M2 = 998244353;
const int M = 1e9 + 7;
const int N = 1e5+ 5;

 
void debug(int n=1,string s = "here"){
    cout<<n<<" "<<s<<endl;
}



struct manacher{ // O(n) -- time compexity
	vi p;

	void run_manacher(string &t){

		int n = t.size();
		p.resize(n,1);
		int l=1,r=1;
		for(int i=1;i<n;i++){
			p[i] = max(1,min(r-i,p[l+r-1]));
			while(i-p[i]>=0 && i+p[i]<n && t[i-p[i]] == t[i+p[i]]){
				p[i]++;
			}
			if(i+p[i] > r){
				r = i+p[i];
				l = i-p[i];
			}
		}

	}

	void build(string s){
		string t;
		for(auto &e : s){
			t += '#' + e;
		}
		t += '#';

		run_manacher(t);
	}
	// 012345
	// abcdef
	// #a#b#c#d#e#f
	// 0123456789
	int getLongest(int cen,bool odd){
		int i = 2*cen + 1 + (!odd);
		return p[i] - 1;
	}

	int checkPalin(int l,int r){
		return (r-l+1) <= getLongest((l+r)/2,l%2==r%2);
	}
}





void solve(){

    
	


}
 
 
 
 
 
 
 
 signed main()
{       
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin.exceptions(ios::badbit | ios::failbit);

    // init();
 
    int t;
    // cin>>t;
    t=1;
 
    while(t--){
 
        solve();
    }
 
    // solve();
 
    return 0;
 
 }
