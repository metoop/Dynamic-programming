/*
	author: KRHero
	IDE: VSCode	
    Submission Link: https://atcoder.jp/contests/dp/submissions/17389603
*/


#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define MOD 1000000007
#define f(i,a,b) for(int i=a;i<b;i++)
#define fe(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=b;i>a;i--)
#define fde(i,a,b) for(int i=b;i>=a;i--)
#define fastio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define MID(s,e) (s+(e-s)/2)
#define whilet() int t; cin >> t;while(t--)
#define F first
#define S second
#define mp make_pair
#define epsilon 1e-15
#define pb push_back
#define PI 3.1415926535897932384626433832

using namespace std;


void dfs(ll node,vector<vector<ll>>& edges,vector<ll>& visited,vector<ll>&dp){
    if(visited[node]) return;
    visited[node] = 1;
    for(auto i: edges[node]){
        dfs(i,edges,visited,dp);        
    }
    for(auto i: edges[node]) dp[node] = max(dp[node],dp[i]+1);
}

void solve(){
	ll n,m;
	cin >> n >> m;
    vector<vector<ll>> edges(n+1);
    f(i,0,m){
        ll x,y;
        cin >> x >> y;
        edges[x].pb(y);
    }
    vector<ll> dp(n+1,0),visited(n+1,0);

    fe(i,1,n) if(!visited[i]) dfs(i,edges,visited,dp);

    ll ans = 0;
    fe(i,1,n) ans = max(ans,dp[i]);
    
    cout<<ans<<endl;
    return;

	
}
int main(){
	
	solve();		
	
}


