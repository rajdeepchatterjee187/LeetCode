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
class BSTIterator {
public:
    vector<int> treeNodes;
    int index = -1;
    
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        index = index + 1;
        return treeNodes[index];
    }
    
    bool hasNext() {
        if(index + 1 == treeNodes.size())   return false;
        else return true;
    }
    
    void inorder(TreeNode* root) {
        if(root == nullptr) return;
        
        inorder(root->left);
        treeNodes.push_back(root->val);
        inorder(root->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */