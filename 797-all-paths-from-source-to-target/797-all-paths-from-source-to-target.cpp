class Solution {
public:
    vector<vector<int>> result;
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        int target = n-1;
        
        vector<int> path;
        path.push_back(0);
        
        
        
        backtrack(0, path, target, graph);
        
        return result;
    }
    
    void backtrack(int node, vector<int>& path, int target, vector<vector<int>>& graph) {
        if(node == target) {
            result.push_back(path);
            return;
        }
        
        for(auto nextNode : graph[node]) {
            path.push_back(nextNode);
            backtrack(nextNode, path, target, graph);
            path.pop_back();
        }
    }
};