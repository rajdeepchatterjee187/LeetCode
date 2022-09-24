class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> set (nums.begin(), nums.end());
        vector<int> nums2 (set.begin(), set.end());
        return longestCommonSubsequence(nums, nums2);
    }
    
    int longestCommonSubsequence(vector<int>& text1, vector<int>& text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(text1, text2, n-1, m-1, dp);
    }
    
    
    int solve(vector<int>& text1, vector<int>& text2, int n, int m, vector<vector<int>>& dp){
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