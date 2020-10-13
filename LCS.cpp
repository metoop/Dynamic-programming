class Solution {
  public:

    int recursionUtil(string & text1, string & text2, int index1, int index2) {

      if (index1 >= text1.size() || index2 >= text2.size()) {
        return 0;
      }

      int count = 0;

      // characters matched case
      // increment both pointers by 1
      // there by adding 1 to our count as we got a character which is same in both the 
      // strings
      if (text1[index1] == text2[index2]) {
        count = 1 + recursionUtil(text1, text2, index1 + 1, index2 + 1);
      }

      // if characters doesn't match, we have two options
      // increment first pointer and check if we can get a match
      // else increment second pointer and check if we can get a match
      int count2 = recursionUtil(text1, text2, index1 + 1, index2);
      int count3 = recursionUtil(text1, text2, index1, index2 + 1);

      return max(max(count, count2), count3);

    }

  int lcsRecursion(string & text1, string & text2) {

    return recursionUtil(text1, text2, 0, 0);

  }

  int lcsDp(string & text1, string & text2) {

    // we need to create a 2d grid as we have two variables as we saw in above recursion method
    // two variables are pointer1 for text1 and pointer 2 for text2

    // initializing 2d array with 0s
    vector < vector < int >> dp(text1.size() + 1, vector < int > (text2.size() + 1, 0));

    for (int i = 1; i <= text1.size(); i++) {
      for (int j = 1; j <= text2.size(); j++) {
        // if we have same chars , we need to check at dp[i-1][j-1]
        // because dp[i-1][j-1] will have optimised result till last matched case

        // we are going to [i-1][j-1] because that corresponds to previous char 
        // in both string
        //i-1 -> previous char in text1
        //j-1 -> previous chat in text2

        // we are adding 1 here as we found a same char in both strings
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          // if we dont find a matching char, pick the maximum value from previous state of dp
          // as we have seen in above recursion, if we dont have matching char, we recur in two ways .
          // same way, we already got optimised value in those two states and stored in dp[i-1][j] and dp[i][j-1]
          // this is why dp is faster
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

      }
    }

    return dp[text1.size()][text2.size()];

  }

  int longestCommonSubsequence(string text1, string text2) {

    // return lcsRecursion(text1,text2);
    return lcsDp(text1, text2);

  }
};
