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
    bool isBalanced(TreeNode* root) {
        pair<int, bool> result = isHeightBalanced(root);
	    return result.second;
        
    }
    pair<int, bool> isHeightBalanced (TreeNode* root) {
	pair<int, bool> p, Left, Right;
	if (root == NULL){
		p.first = 0;
		p.second = true;
		return p;
	}
	Left = isHeightBalanced(root->left);
	Right = isHeightBalanced(root->right);
	
	int height = max(Left.first, Right.first) + 1;
	
	if(abs(Left.first - Right.first)<=1 and Left.second and Right.second) {
		return make_pair(height, true);
	}
	return make_pair(height, false);
    }
};