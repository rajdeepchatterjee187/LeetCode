class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> table (1000, vector<int>(1000,-1));
        
        int res = helper(nums, 1, nums.size()-1, table);
        return res;
    }
    
    int helper(vector<int>& nums, int i, int j, vector<vector<int>>& table) {
        if(i >= j)  return 0;
        if(table[i][j] != -1)   return table[i][j];
        
        int k;
        int ans = INT_MIN;
        int tempans;
        
        for(k = i; k < j; k++) {
            tempans = helper(nums,i,k,table) + helper(nums,k+1,j,table)
                        + nums[i-1]*nums[k]*nums[j];
            
            ans = max(tempans, ans);
            table[i][j] = ans;
        }
        
        return table[i][j] = ans;
    }
};