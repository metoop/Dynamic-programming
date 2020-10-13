class Solution {
  public:
    int longestPalindromeSubseq(string x) {

      //whole question is same as LONGEST COMMON Subsequence LCS just we have to make the string x reverse and store it in new string say y 

      string y;

      //reversing and storing x in string y
      for (int i = x.length() - 1; i >= 0; i--) {
        y.push_back(x[i]);
      }

      int m = x.length();
      int n = y.length();

      // I know that n and m are same as x and y are reverse of each other but to co - relate it with LCS i havent treated n and m same.
      int t[1001][1001];
      //as maximum length is 1000

      //initialization
      for (int i = 0; i <= m; i++) {
        t[i][0] = 0;
      }
      for (int j = 0; j <= n; j++) {
        t[0][j] = 0;
      }

      //Dynamic Programming Approach
      for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
          if (x[i - 1] == y[j - 1]) {
            t[i][j] = 1 + t[i - 1][j - 1];
          } else {
            t[i][j] = max(t[i][j - 1], t[i - 1][j]);
          }

        }
      }
      return t[m][n];
    }

};
