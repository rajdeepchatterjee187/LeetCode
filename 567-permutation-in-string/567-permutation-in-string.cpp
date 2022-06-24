class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int start = 0; int end = 0; int matched = 0;
        unordered_map<char,int> map;
        
        for(int i = 0; i < s1.length(); i++) {
            map[s1[i]]++;
        }
        
        for(; end < s2.length(); end++) {
            if(map.find(s2[end]) != map.end()) {
                map[s2[end]]--;
                if(map[s2[end]] == 0)   matched++;
            }
            
            if(matched == map.size())   return true;
            
            if(end >= s1.length()-1) {
                if(map.find(s2[start]) != map.end()) {
                    if(map[s2[start]] == 0)     matched--;
                    map[s2[start]]++;
                }
                start++;
            }
        }
        return false;
    }
};