class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        
        for(auto nodes : prerequisites) {
            adj[nodes[1]].push_back(nodes[0]);
        }
        
        vector<bool> visited (numCourses);
        vector<bool> recStack (numCourses);
        
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                if(DFS(adj, i, visited, recStack))  return false;
            }
        }
        
        return true;
    }
    
    
    bool DFS (vector<vector<int>>& adj, int src, vector<bool>& visited,
                vector<bool>& recStack) {
        
        visited[src] = true;
        recStack[src] = true;
        
        for(auto node : adj[src]) {
            if(!visited[node] and DFS(adj, node, visited, recStack))
                return true;
            else if(recStack[node] == true)
                return true;
        }
        
        recStack[src] = false;
        return false;
    }
};