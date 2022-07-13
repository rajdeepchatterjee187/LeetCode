class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> words(wordList.begin(), wordList.end());
        q.push(beginWord);
        int level = 0;
        
        //bfs
        while(!q.empty()) {
            int size = q.size();
            level++;
            for(int i = 0; i < size; i++) {
                string str = q.front();
                q.pop();
                if(str == endWord)  return level;
                unordered_set<string> nbrs = helper(str);
                
                for(auto nbr : nbrs) {
                    if(words.count(nbr)!= 0) {
                        words.erase(nbr);
                        q.push(nbr);
                    }
                }
            }
        }
        return 0;
    }
    
    unordered_set<string> helper(string str) {
        unordered_set<string> result;
        for(int i = 0; i < str.length(); i++) {
            char temp = str[i];
            for(char c = 'a'; c <= 'z'; c++) {
                str[i] = c;
                result.insert(str);
            }
            str[i] = temp;
        }
        return result;
    }
};