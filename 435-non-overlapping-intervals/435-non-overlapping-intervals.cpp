class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)    return 0;
        sort(intervals.begin(), intervals.end());
        int ans = 0, start = 0, end = 1;
        int currEnd = intervals[0][end];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][start] < currEnd) {
                ans++;
                currEnd = min(currEnd, intervals[i][end]);
            }
            else    currEnd = intervals[i][end];
        }
        return ans;
    }
};