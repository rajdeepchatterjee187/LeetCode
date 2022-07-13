class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size());
        dfs(0, visited, rooms);
        for(auto node : visited) {
            if(node == false)   return false;
        }
        return true;
    }
    
    void dfs(int src, vector<bool>& visited, vector<vector<int>>& rooms) {
        visited[src] = true;
        for(auto nbr : rooms[src]) {
            if(visited[nbr] == false)   dfs(nbr, visited, rooms);
        }
        return;
    }
};