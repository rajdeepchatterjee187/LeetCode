class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        
        for(auto interval : intervals) {
            if(result.empty() || result.back()[1] < interval[0]) {
                result.push_back(interval);
            }
            else {
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
        return result;
    }
};