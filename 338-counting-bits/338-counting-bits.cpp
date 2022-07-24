class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans (n+1);
        ans[0] = 0;
        for(int i = 1; i < n+1; i++) {
            ans[i] = helper(i);
        }
        return ans;
    }
    
    int helper(int n) {
        int count = 0;
        while(n>0) {
            if((n&1) == 1)  count++;
            n = n>>1;
        }
        return count;
    }
};