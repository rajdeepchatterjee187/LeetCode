class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int ans = 0;
        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[0].size(); col++) {
                ans = max(ans, area(row, col, grid, visited));
            }
        }
        return ans;
    }
    
    int area (int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        //base case
        if(row < 0 || row>= grid.size() || col < 0 || col>= grid[0].size() ||
          visited[row][col] == true || grid[row][col] == 0 ) {
            return 0;
        }
        
        visited[row][col] = true;
        
        return 1 + area(row+1, col, grid, visited) + 
            area(row-1, col, grid, visited) + 
            area(row, col+1, grid, visited) + 
            area(row, col-1, grid, visited);
    }
};