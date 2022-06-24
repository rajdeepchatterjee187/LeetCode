class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> map;
        int start = 0; int end = 0; int ans = INT_MIN;
        
        for(; end < fruits.size(); end++) {
            map[fruits[end]]++;
            
            while(map.size() > 2) {
                map[fruits[start]]--;
                if(map[fruits[start]] == 0) {
                    map.erase(fruits[start]);
                }
                start++;
            }
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};