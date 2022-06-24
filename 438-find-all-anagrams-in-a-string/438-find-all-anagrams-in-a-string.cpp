class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int start = 0; int end = 0; int matched = 0;
        unordered_map<char,int> map;
        vector<int> result;
        
        for(int i = 0; i < p.length(); i++) {
            map[p[i]]++;
        }
        
        for(; end < s.length(); end++) {
            if(map.find(s[end]) != map.end()) {
                map[s[end]]--;
                if(map[s[end]] == 0)   matched++;
            }
            
            if(matched == map.size())   result.push_back(start);
            
            if(end >= p.length()-1) {
                if(map.find(s[start]) != map.end()) {
                    if(map[s[start]] == 0)     matched--;
                    map[s[start]]++;
                }
                start++;
            }
        }
        return result;
    }
};