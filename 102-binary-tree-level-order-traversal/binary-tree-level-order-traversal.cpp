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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL)
            return result;

        // Queue for level order traversal
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {  // here we cant use !q.empty 
            int count = q.size();
            vector<int> res;
            for(int i = 0; i < count; i++){
                root = q.front();
                q.pop();
                res.push_back(root->val);
                // Push left child in the queue
                if (root->left)
                    q.push(root->left);
                // Push right child in the queue
                if (root->right)
                    q.push(root->right);
            }
            result.push_back(res);
        }
        return result;
    }
};