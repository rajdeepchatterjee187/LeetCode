/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
         if (root==NULL) return NULL;
        TreeNode *ret=new TreeNode(root->val);
        if (root->children.size()==0) return ret;
        ret->left=encode(root->children[0]);
        TreeNode *now=ret->left;
        for (int i=1;i<root->children.size();++i){
            now->right=encode(root->children[i]);
            now=now->right;
        }
        return ret;
    }
	
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
         if (root==NULL) return NULL;
        Node* ret=new Node;
        ret->val=root->val;
        TreeNode *now=root->left;
        while (now){
            ret->children.push_back(decode(now));
            now=now->right;
        }
        return ret;
    
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));