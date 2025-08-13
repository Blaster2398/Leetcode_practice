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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder ;
        TreeNode* curr = root;
        while( curr != NULL ){
            if( curr -> left == NULL ){
                preorder.push_back(curr->val);
                curr = curr -> right;
            }
            else{
                TreeNode* prev = curr -> left;
                while( prev->right != NULL && prev -> right != curr ) {
                    prev = prev -> right;
                }
                // the thread is already made so delete it and traverse to the right 
                if(prev -> right == curr){
                    prev -> right = NULL;
                    curr = curr -> right;
                }
                // if the thread is not made then just make it 
                else{
                    prev -> right = curr;
                    preorder.push_back(curr->val);
                    curr = curr -> left;
                }
            }
        }
        return preorder;
    }
};

