class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;
        
        for(int i = 0; i < nums.size()-2; i++) {
            int left = i+1; int right = nums.size()-1;
            
            while(left<right) {
                int targetDiff = target - nums[i]-nums[left]-nums[right];
                
                if(targetDiff == 0) return target - targetDiff;
            
            
           if(abs(targetDiff) < abs(minDiff))   minDiff = targetDiff;
            
            if(targetDiff > 0)  left++;
            else    right--;
        }
        }
        return target-minDiff;
    }
};