class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        if(nums.size() == 0)    return result;
        
        int left = leftIndex(nums, target);
        int right = rightIndex(nums, target);
        
        result[0] = left;
        result[1] = right;
        
        return result;
    }
    
    int leftIndex(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int leftidx = -1;
        
        while(left <= right) {
            int mid = left + (right-left)/2;
            
            if(nums[mid] > target)
                right = mid-1;
            else if(nums[mid] < target) 
                left = mid+1;
            else {
                if(mid == 0 or nums[mid-1] != target){
                    leftidx = mid;
                    return leftidx;
                } 
                else 
                    right = mid-1;
            }
        }
        return leftidx;
    }
    
    int rightIndex(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int rightidx = -1;
        
        while(left <= right) {
            int mid = left + (right-left)/2;
            
            if(nums[mid] > target)
                right = mid-1;
            else if(nums[mid] < target) 
                left = mid+1;
            else {
                rightidx = mid;
                left = mid+1;
            }
        }
        return rightidx;
    }
};