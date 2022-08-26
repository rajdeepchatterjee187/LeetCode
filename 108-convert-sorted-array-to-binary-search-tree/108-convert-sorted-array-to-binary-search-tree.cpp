/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = createNode(0, nums.size()-1, nums);
        return root;
    }
    
    TreeNode* createNode(int start, int end, vector<int>& nums) {
        if(start > end)   
            return nullptr;
        
        int nodeIndex = (end + start)/2;
        
        TreeNode* root = new TreeNode(nums[nodeIndex]);
        
        root->left = createNode(start, nodeIndex-1, nums);
        root->right = createNode(nodeIndex+1, end, nums);
        
        return root;
    }
};