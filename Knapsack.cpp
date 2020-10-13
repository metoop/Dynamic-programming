#include <iostream>
#include <vector>
using namespace std;

int knapSack(int W, vector<int> &wt, vector<int> &val, int n){ 
   int i, w; 
   int K[n+1][W+1]; 
  
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0)  // base case... 
               K[i][w] = 0; 
           else if (wt[i-1] <= w)  // nomm
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
  
   return K[n][W]; 
} 

int main() {
	int n,w;
	cin>>w>>n;
	vector<int>weight(n,0),val(n,0);
	for(int i=0; i<n ;i++){
		cin>>weight[i]>>val[i];
	}
	cout<<knapSack( w, weight, val, n);
	return 0;
}
