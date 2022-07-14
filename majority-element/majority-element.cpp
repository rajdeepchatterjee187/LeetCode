class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0 ; i < n; i++) {
            mp[nums[i]]++;
        }
        
        int x = n/2;
        int ans;
        for(auto num:mp) {
            if(num.second > x) ans = num.first;
        }
        
        return ans;
    }
};