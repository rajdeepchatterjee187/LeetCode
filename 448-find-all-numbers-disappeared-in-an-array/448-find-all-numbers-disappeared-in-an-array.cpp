class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> set;
        for(int i = 1; i <= n; i++) {
            set.insert(i);
        }
        
        for(auto num : nums) {
            set.erase(num);
        }
        vector<int> result(set.begin(), set.end());
        return result;
    }
};