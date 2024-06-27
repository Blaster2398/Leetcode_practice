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
    bool util(TreeNode* root, long low, long high){
        if(root == NULL) return true;

        if(root->val >= high || root->val <= low) return false;

        return util(root->left, low, root->val) && util(root->right, root->val, high);

    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        cout << LONG_MAX << endl;
        return util(root,LONG_MIN,LONG_MAX);
    }
};