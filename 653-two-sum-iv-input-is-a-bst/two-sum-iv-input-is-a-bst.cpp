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
    bool inorder(TreeNode* root, int k, unordered_set<int>& st){
        if(!root) return false;
        if(inorder(root->left, k, st)) return true;

        if(st.find(k-root->val) != st.end()) return true;
        st.insert(root->val);

        return inorder(root->right, k, st);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return inorder(root, k, st);
    }
};