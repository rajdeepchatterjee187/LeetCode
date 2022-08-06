class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> stack;
        
        for(int i = 2*n-1; i >= 0; --i) {
            while(!stack.empty() and nums[stack.top()] <= nums[i%n])
                stack.pop();
            
            if(stack.empty())
                ans[i%n] = -1;
            else
                ans[i%n] = nums[stack.top()];
            
            stack.push(i%n);
        }
        
        return ans;
    }
};