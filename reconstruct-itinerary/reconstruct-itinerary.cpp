class Solution {
public:
    unordered_map<string, multiset<string>> adjList;
    vector<string> itinerary;
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        //build adjacency list
        for(auto ticket : tickets) {
            adjList[ticket[0]].insert(ticket[1]);
        }
        
        dfs("JFK");
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
    
    void dfs(string src) {
        auto& edges = adjList[src];
        while(!edges.empty()) {
            string tempDest = *edges.begin();
            edges.erase(edges.begin());
            dfs(tempDest);
        }
        itinerary.push_back(src);
    }
};