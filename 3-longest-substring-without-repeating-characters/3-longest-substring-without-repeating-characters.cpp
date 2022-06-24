class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0; int end = 0; int ans = 0;
        unordered_set<char> set;
        while(start < s.length() && end < s.size()) {
           if(set.find(s[end]) == set.end()) {
               set.insert(s[end]);
               end++;
               ans = max(ans, end-start);}
            
           else {
               set.erase(s[start]);
               start++;}}               
        return ans;}                
    
};