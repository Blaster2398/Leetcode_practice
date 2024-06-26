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
    TreeNode* util(TreeNode* root , int val){
        if(root == NULL || root->val == val){
            return root;
        }
        else if(root->val > val){
            return util(root->left,val);
        }
        else{
            return util(root->right, val);
        }
         
    }
    TreeNode* searchBST_recursive(TreeNode* root, int val) {
        return util(root, val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL && root->val != val){
            if(val > root->val){
                root = root->right;
            }
            else if(val < root->val){
                root = root->left;
            }
        }
        return root;
    }
};