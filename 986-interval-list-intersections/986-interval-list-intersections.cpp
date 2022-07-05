class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        int start = 0, end = 1;
        int i = 0, j = 0;
        vector<int> interval(2);
        while(i<firstList.size() && j<secondList.size()) {
            
            int low = max(firstList[i][start], secondList[j][start]);
            int high = min(firstList[i][end], secondList[j][end]);
            if(low <= high) {
                result.push_back({low,high});
            }
            
            
            if(firstList[i][end] < secondList[j][end])  i++;
            else    j++;
        }
        return result;
    }
};