class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        multiset<int> set;
        for(auto num : nums) {
            set.insert(num*num);
        }
        
        vector<int> result;
        for(auto num : set) {
            result.push_back(num);
        }
        return result;
    }
};