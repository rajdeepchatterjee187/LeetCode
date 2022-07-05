class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        
        sort(nums.begin(), nums.end());
        
        int curr = 1;
        int lcs = 1;
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[i-1]) {
                if(nums[i] == nums[i-1]+1) {
                    curr++;
                }
                else {
                    lcs = max(curr,lcs);
                    curr = 1;
                }
            }
        }
        return max(curr, lcs);
    }
};