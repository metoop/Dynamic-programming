#include<bits/stdc++.h>
#define  inf 1e18
using namespace std;
inline void max_self(long long &a, long long b){
	a = max(a,b);
}
inline void min_self(long long &a, long long b){
	a = min(a,b);
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, w;
	cin>>n>>w;
	vector<int> wt(n),val(n);
	for (int i=0; i<n;i++)cin>>wt[i]>>val[i];
	
	int sum_value = 0;
	for(int x: val)
		sum_value += x;
	
	vector<long long> dp(sum_value+1, inf);
		dp[0]=0;
	    for(int item = 0; item < n; ++item) {
        	for(int value_already = sum_value - val[item]; value_already >= 0; --value_already) {
        		//~ for(int weight_already = 0; weight_already <= W - weight; ++weight_already) {
            	min_self(dp[value_already+val[item]], dp[value_already] + wt[item]);
        }
    }

	int ans = 0;
	for (int i=0; i<=sum_value; i++)
		if(w >= dp[i])
			ans = i;
	cout<<ans;
	return 0;
};
#include <iostream>
using namespace std;
int main() {
    cout<<"Hello World!";
}
