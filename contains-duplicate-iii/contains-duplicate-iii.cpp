class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> set;
        
        for(int i = 0; i < nums.size(); i++) {
            
           auto successor = set.lower_bound(nums[i]);
           
            if(successor!= set.end() and *successor<=(long)nums[i] + (long)t)
                return true;
            if(successor!= set.begin() and nums[i]<= (long)*prev(successor)+(long)t)
                return true;
            
            set.insert(nums[i]);
            
            if(set.size() > k)
                set.erase(nums[i-k]);
            
        }
        
        return false;
    }
};