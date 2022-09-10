class Solution {
public:
    int minDistance(string word1, string word2) {
        int x = lcs(word1, word2);
        int y = word1.length() + word2.length();
        return y-2*x;
    }
    
    int lcs(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(text1, text2, n-1, m-1, dp);
    }
    
    
    int solve(string& text1, string& text2, int n, int m, vector<vector<int>>& dp){
        if(n<0 || m<0){
            return 0;
        }
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        
        // if characters match
        if(text1[n]== text2[m]){
            return  dp[n][m] = 1+solve(text1, text2, n-1, m-1, dp);
        }
        // if they dont, take maximum of both possibilities
        return dp[n][m] = max(solve(text1, text2, n-1, m, dp), solve(text1, text2, n, m-1, dp));
    }
};