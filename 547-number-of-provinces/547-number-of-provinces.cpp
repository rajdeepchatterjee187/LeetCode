class Solution {
public:
    int ans;
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<bool> visited (V+1);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(i, isConnected, visited);
                ans++;
            }
        }
        
        return ans;
    }
    
    void dfs(int src, vector<vector<int>>& isConnected, vector<bool>& visited) 
    {
        visited[src] = true;
        
        for(int j = 0; j < isConnected.size(); j++) {
            if(isConnected[src][j] == 1 and !visited[j]) {
                dfs(j, isConnected, visited);
            }
        }
    }
};