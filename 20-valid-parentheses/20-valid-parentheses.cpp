class Solution {
public:
    unordered_map<char, char> mp;
    
    bool isValid(string s) {
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';
        
        stack<char> st;
        
        for(char c : s) {
            if(mp.find(c) != mp.end())  st.push(c);//if opening bracket
            else {
                if(st.empty())   return false;
                auto open = st.top();
                st.pop();
                if(mp[open] != c)   return false;
            }
        }
        return st.empty();
    }
};