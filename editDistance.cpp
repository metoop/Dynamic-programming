#include "bits/stdc++.h"
using namespace std;
// int dp[100][100];
/*
int editDist(string &s1, string &s2, int m, int n){
    if(dp[m][n]!=-1)
        return dp[m][n];
    if(s1.size()==m)
        return dp[m][n] = s2.size()-n;
    else if(s2.size()==n)
        return dp[m][n]=s1.size()-m;
    if(s1[m]==s2[n])
        return dp[m][n] = editDist(s1, s2, m+1, n+1);
    return dp[m][n] = 1 + min(
        min(editDist(s1, s2, m+1, n),       //    remove
            editDist(s1, s2, m, n+1)),      //    insert
            editDist(s1, s2, m+1, n+1)      //    replace
    );
}
*/
int editDist(string &s1, string &s2){
    int m=s1.size();
    int n=s2.size();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 and j==0)
                dp[i][j]=0;
            else if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]= 1 + min( dp[i-1][j],    // remove
                                 min( dp[i][j-1],   // insert
                                      dp[i-1][j-1] ) ); // replace
        }
    }
    return dp[m][n];
}

int main(){
    // memset(dp,-1,sizeof(dp));
    string s1="sunday", s2="saturday";
    cout<<editDist(s1, s2)<<"\n";

    return 0;
}
