class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        int start = 0, end = 1;
        int i = 0, j = 0;
        vector<int> interval(2);
        while(i<firstList.size() && j<secondList.size()) {
            if((firstList[i][start] >= secondList[j][start] && firstList[i][start] <= secondList[j][end]) || (secondList[j][start] >= firstList[i][start] && secondList[j][start] <= firstList[i][end]))
            {
            interval[start] = max(firstList[i][start], secondList[j][start]);
            interval[end] = min(firstList[i][end], secondList[j][end]);
            result.push_back(interval);
            }
            
            if(firstList[i][end] < secondList[j][end])  i++;
            else    j++;
        }
        return result;
    }
};