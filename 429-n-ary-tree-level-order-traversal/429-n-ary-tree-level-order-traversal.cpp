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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            vector<int> vec;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                Node* temp = q.front();
                q.pop();
                vec.push_back(temp->val);
                for(auto childNode : temp->children)    q.push(childNode);
            }
            result.push_back(vec);
        }
        return result;
    }
};