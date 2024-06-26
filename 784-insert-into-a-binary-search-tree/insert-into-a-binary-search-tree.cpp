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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        if(root == NULL){
            TreeNode* temp =new TreeNode(val);
            return temp;
        }
        while(true){
            if(curr->val > val && curr->left != NULL){
                curr = curr->left;
            }
            else if(curr->val > val && curr->left == NULL){
                TreeNode* temp =new TreeNode(val);
                curr->left = temp;
                return root;
            }

            if(curr->val < val && curr->right != NULL){
                curr = curr->right;
            }
            else if(curr->val < val && curr->right == NULL){
                TreeNode* temp =new TreeNode(val);
                curr->right = temp;
                return root;
            }
        }
        return root;
    }
};