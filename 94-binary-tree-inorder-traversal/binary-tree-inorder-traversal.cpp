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
    vector<int> result;
    vector<int> inorderTraversal1(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node = root;

        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if( st.empty() ){
                    break;
                }
                node = st.top();
                st.pop();

                result.push_back(node->val);
                node = node->right;
            }

        }
        return result;     
    }


    // Morris Inorder traversal 
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> inorder ;
        TreeNode* curr = root;
        while( curr != NULL ){
            if( curr -> left == NULL ){
                inorder.push_back(curr->val);
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
                    inorder.push_back(curr->val);
                    curr = curr -> right;
                }
                // if the thread is not made then just make it 
                else{
                    prev -> right = curr;
                    curr = curr -> left;
                }
            }
        }
        return inorder;
    }


    // // recursive 
    // vector<int> inorderTraversal(TreeNode* root) {
    //     if(root != NULL){
    //         inorderTraversal(root->left);
    //         result.push_back(root->val);
    //         inorderTraversal(root->right); 
    //     }
    //     return result;
    // }
};