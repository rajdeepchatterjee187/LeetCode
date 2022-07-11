class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        set<set<int>> powerSet;
        set<int> emptySet;
        powerSet.insert(emptySet);
        
        for(auto num : nums) {
            for(auto numSet : powerSet) {
                set<int> tempSet(numSet.begin(), numSet.end());
                tempSet.insert(num);
                powerSet.insert(tempSet);
            }
        }
        
        vector<vector<int>> result;
        for(auto Tset : powerSet) {
            vector<int> vec (Tset.begin(), Tset.end());
            result.push_back(vec);
        }
        
        return result;
    }
};