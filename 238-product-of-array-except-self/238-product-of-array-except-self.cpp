class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());
        result[0] = 1;
        
        for(int i = 1; i < nums.size(); i++) {
            result[i] = nums[i-1]*result[i-1];
        }
        
        int right = 1;
        for(int i = nums.size()-1; i >= 0; i--) {
            result[i] = result[i] * right;
            right *= nums[i];
        }
        return result;
    }
};