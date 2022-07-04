class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> vec;
        for(auto interval : intervals) {
            if(vec.empty() || vec.back() <= interval[0]) {
                vec.push_back(interval[1]);
            }
            else return false;
        }
        return true;
    }
};