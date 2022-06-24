class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0; int end = 0;
        int count = 0; int ans = 0;
        int maxFreq = 0;
        unordered_map<char,int> map;
        
        for(; end < s.length(); end++) {
            map[s[end]]++;
            maxFreq = max(maxFreq, map[s[end]]);
            
            if(end-start+1 - maxFreq > k) {
                map[s[start]]--;
                start++;
            }
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};