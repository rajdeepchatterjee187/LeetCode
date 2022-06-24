class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0; int end = 0;
        int count = 0; int ans = 0;
        int maxFreq = 0;
        unordered_map<int,int> map;
        
        for(; end < nums.size(); end++) {
            map[nums[end]]++;
            maxFreq = max(maxFreq, map[1]);
            
            if(end-start+1 - maxFreq > k) {
                map[nums[start]]--;
                start++;
            }
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};