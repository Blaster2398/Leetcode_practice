/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    int lht(TreeNode* root){
        int ht = 0;
        while(root){
            root = root->left;
            ht++;
        }
        return ht;
    }
    int rht(TreeNode* root){
        int ht = 0;
        while(root){
            root = root->right;
            ht++;
        }
        return ht;
    }
    int countNodes(TreeNode* root) { 
        if(!root) return 0;
        int l = lht(root);
        int r = rht(root);
        if(l == r) return (1 << l) -1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};