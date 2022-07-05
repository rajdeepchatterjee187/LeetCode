class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] != nums[nums[i] - 1]) {
                swap(nums,i,nums[i]-1);
            }
            else    i++;
        }
        
        vector<int> vec;
        for(i = 0; i < nums.size(); i++) {
            if(nums[i] != i+1) {
                vec.push_back(nums[i]);
            }
        }
        
        return vec;
    }
    
    void swap(vector<int>&arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
};