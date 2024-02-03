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


//de bruijin's sequence
//yt - https://www.youtube.com/watch?v=VZvU1_oPjg0
 
vvi dict = {{-1,0},{1,0},{0,1},{0,-1}};
const int inf = 1e17;
const int ninf = -1e17;
const int M = 1e9 + 7;
 
 
void debug(int n=1,string s = "here"){
    cout<<n<<" "<<s<<endl;
}
int ct,mxct,n,k;
string ans = "";
const int N = 1e5 + 5;
int gotit = 0;
vi vis(N,0);
 
 
 
void dfs(string &s){
 
    if(mxct == ct){
        gotit = 1;
        ans = s;
        return;
    }
 
    int ssize = s.size();
    string snew = s.substr(ssize - n + 1,n-1);
 
    for(int i=0;i<k;i++){
        if(gotit)return;
        string s1 = snew;
        char s2 = '0' + i;
        s1 += s2;
        int n1 = 0;
        for(int j=s1.size()-1;j>=0;j--){
            if(s1[j] == '1'){
                n1 += pow(2,s1.size()-1-j);
            }
        }
        // cout<<n1<<endl;
        if(vis[n1])continue;
 
        s += s2;
        ct++;
        // cout<<s1<<endl;
        vis[n1] = 1;
        dfs(s);
        vis[n1] = 0;
        ct--;
        s.pop_back();
    }
 
}
 
 
 
 
 
void solve(){
 
 
    cin>>n;
 
    string s = "";
    for(int i=0;i<n;i++){
        s += "0";
    }
    k = 2;
    ct = 1;
    ans = s;
    int n1 = 0;
    for(int j=s.size()-1;j>=0;j--){
        if(s[j] == '1'){
            n1 += pow(2,s.size()-1-j);
        }
    }
    vis[n1] =1;
    mxct = pow(k,n);
    dfs(s);
 
    // for(int i=0;i<)
 
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