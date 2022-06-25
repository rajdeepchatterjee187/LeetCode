class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0; int j = 1;
        if(nums.size() == 0)    return 0;
        if(nums.size() == 1)    return 1;
        while(i < nums.size() && j < nums.size()) {
            if(nums[j] == nums[i]) {
                j++;
            }
            else{
                int a = nums[i+1];
                nums[i+1] = nums[j];
                nums[j] = a;
                j++;
                i++;
            }
        }
        return i+1;
    }
};