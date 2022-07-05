class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> merged;
        
        int i = 0;
        int start = 0;
        int end = 1;
        
        while(i<intervals.size() && intervals[i][end] < newInterval[start]) {
            merged.push_back(intervals[i]);
            i++;
        }
        
        while(i<intervals.size() && intervals[i][start] <= newInterval[end]) {
            newInterval[start] = min(intervals[i][start], newInterval[start]);
            newInterval[end] = max(intervals[i][end], newInterval[end]);
            i++;
        }

        merged.push_back(newInterval);
        
        while(i<intervals.size()) {
            merged.push_back(intervals[i]);
            i++;
        }
        
        return merged;
    }
};