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
const int M = 1e9 + 7;
const int N = 1e5+ 5;
 
 
void debug(int n=1,string s = "here"){
    cout<<n<<" "<<s<<endl;
}


//longest prefix whichi is suffix  -- Time Complexity - O(n)
vi longest_prefix_suffix(string s){
    int n = s.size();
    vi lps(n,0);
    int j = 0;
    for(int i=1;i<n;i++){
        j = lps[i-1];
        while(j>0 && s[i] != s[j]){
            j = lps[j-1];
        }
        if(s[i] == s[j])j++;

        lps[i] = j;
    }

    return lps;
}




void solve(){

    //KMP algo to find the position form when string s fully mathches in t ( if not print -1);

    string s = "na";
    vi pre = longest_prefix_suffix(s);

    string t = "apnacollege";

    int i=0,j=0;
    int pos = -1;
    while(i<t.size()){
        if(t[i] == s[j]){
            i++;
            j++;
        }else{
            if(j>0){
                j = pre[j-1];
            }else{
                i++;
            }
        }
        if(j = s.size()){
            pos = i- s.size();
        }
    }

    out(pos);
    

    

 
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