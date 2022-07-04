class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> vec;
        for(auto interval : intervals) {
            if(vec.empty() || vec.back()[1] <= interval[0]) {
                vec.push_back(interval);
            }
            else return false;
        }
        return true;
    }
};