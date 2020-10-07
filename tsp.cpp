#include<bits/stdc++.h>
using namespace std;
#define inf 99999
const int n=5;
int VISITED_ALL = (1<<n)-1;
int dp[33][5];

int dist[5][5] ={
	{0,20,42,25,50},
	{20,0,30,34,30},
	{42,30,0,10,100},
	{25,34,10,0,10},
    {25,34,10,100,0}
};

int tsp (int mask, int pos){
    if(dp[mask][pos])
    	return dp[mask][pos];

	if(mask==VISITED_ALL){
		return dist[pos][0];
	}

	int ans = inf;
	for (int city=1; city<n; city++){
		if((mask&(1<<city)) == 0){
			int newAns = dist[pos][city] + tsp( mask|(1<<city), city);
			ans  = min(ans, newAns);
		}
	}
	return dp[mask][pos] = ans;
}

int main() {
	// memset(dp, sizeof );
	cout<<tsp(1,0)<<endl;

	return 0;
}

