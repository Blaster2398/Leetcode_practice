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
    TreeNode* findLastRight(TreeNode* root){
        if(!root->right) return root;
        while(root->right) root = root->right;
        return root;
    }
    TreeNode* helper(TreeNode* root){
        // this helper function provides us with a node that can be attached to the parent after deleting the node
        if(!root->right) return root->left;
        if(!root->left) return root->right;

        // now attach the right of node to the rightmost node of left 
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 1) find the node to be deleted ( its parent and its lefft and right child )
        // 2) delete this node and make parent->left = node->left, 
        // 3) go to the left child's rightmost node and join the node-> right there 
        if(root == NULL) return NULL;
        if(root->val == key) return helper(root);

        TreeNode* temp = root;
        while(temp){
            if(temp->val > key){
                if(temp->left && temp->left->val == key){
                    temp->left = helper(temp->left);
                    break; 
                }
                else temp = temp->left;
            }
            else{
                if(temp->right && temp->right->val == key){
                    temp->right = helper(temp->right);
                    break;
                }
                else temp = temp->right;
            }
        }
        return root;
    }
};