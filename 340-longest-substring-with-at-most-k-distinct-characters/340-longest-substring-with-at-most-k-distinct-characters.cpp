class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char,int> map;
        int start = 0; int end = 0;
        int length = INT_MIN;
        
        for(; end < s.size(); end++) {
            map[s[end]]++;
            
            
            while(map.size() > k) {
                if(--map[s[start]] == 0) {
                    map.erase(s[start]);
                }
                start++;
            }
            length = max(length, end - start +1);
        }
        
        return length;
    }
};