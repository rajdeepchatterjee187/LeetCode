class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seenOnce = 0, seenTwice = 0;
        
        for(int num : nums) {
            seenOnce = (seenOnce ^ num) & (~seenTwice);
            seenTwice = (~seenOnce) & (seenTwice ^ num);
        }
        
        return seenOnce;
    }
};