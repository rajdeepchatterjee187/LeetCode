class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;//map of nge of all elements of nums2
        stack<int> stack;
        int n = nums2.size();
        
        for(int i = n-1; i>= 0; i--) {
            while(!stack.empty() and stack.top()<nums2[i])  
                stack.pop();
            if(stack.empty())
                map[nums2[i]] = -1;
            else
                map[nums2[i]] = stack.top();
            stack.push(nums2[i]);
        }
        
        vector<int> result;
        
        for(auto num : nums1) {
            result.push_back(map[num]);
        }
        
        return result;
    }
};