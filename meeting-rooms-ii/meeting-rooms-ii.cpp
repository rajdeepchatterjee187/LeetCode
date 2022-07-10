class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int start = 0, end = 1;
        if(intervals.size() == 0)   return 0;
        sort(intervals.begin(), intervals.end());
        priority_queue<int,vector<int>,greater<int>> rooms;
        rooms.push(intervals[0][end]);
        
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][start] >= rooms.top()) {
                rooms.pop();
            }
            rooms.push(intervals[i][end]);
        }
        return rooms.size();
    }
};