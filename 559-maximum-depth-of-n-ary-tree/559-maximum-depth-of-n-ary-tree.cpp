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

class Solution {
public:
    int maxDepth(Node* root) {
        int ans = 0;
        if(root == nullptr) return 0;
        
        for(auto TreeNode : root->children) {
            ans = max(maxDepth(TreeNode), ans);
        }
        return 1+ans;
    }
};