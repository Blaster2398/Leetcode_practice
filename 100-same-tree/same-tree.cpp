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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }
        else if(q!=NULL && p!=NULL && p->val!= q->val){
            return false;
        }
        else if(q!=NULL && p==NULL || q==NULL && p!=NULL){
            return false;
        }
        // else{return false}

        return ( isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }
};