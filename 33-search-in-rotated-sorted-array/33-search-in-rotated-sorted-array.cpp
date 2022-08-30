class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(nums[mid] == target) return mid;
            
            if(nums[start] <= nums[mid]){                  //the left part is sorted
                if(target >= nums[start] and target <= nums[mid])
                    end = mid-1;
                else
                    start = mid+1;
            }
            else {                      //the right part is sorted
                if(target >= nums[mid] and target <= nums[end])
                    start = mid+1;
                else
                    end = mid-1;
            }
        }
        
        return -1;
    }
};