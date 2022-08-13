class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colour(graph.size(), -1);
        
        for(int i = 0; i < graph.size(); i++) {
            if(colour[i] == -1) {
                if(!bipartite(i, graph, colour))
                    return false;
            }
        }
        
        return true;
    }
    
    bool  bipartite(int src, vector<vector<int>>& graph, vector<int>& colour) {
        
        if(colour[src] == -1)   colour[src] = 1;
        
        for(auto node : graph[src]) {
            if(colour[node] == -1) {
                
                colour[node] = 1 - colour[src];
                
                if(!bipartite(node, graph, colour))
                    return false;
            }
            
            else if(colour[node] == colour[src])
                return false;
        }
        
        return true;
    }
};