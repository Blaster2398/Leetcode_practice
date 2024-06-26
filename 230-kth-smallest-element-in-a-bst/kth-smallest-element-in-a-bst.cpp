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
    void INO(TreeNode* root,int & counter, int k, TreeNode*& res){
        if(root == NULL) return ;
        INO(root->left,counter, k,res);
        counter++;
        if(counter == k) res = root; 
        INO(root->right,counter, k, res);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        TreeNode* res = new TreeNode();
        INO(root, counter, k,res);
        return res->val;
    }

    // // brute force
    // void INO(TreeNode* root, vector<int>& res){
    //     if(root == NULL) return ;
    //     INO(root->left,res);
    //     res.push_back(root->val);
    //     INO(root->right, res);
    // }
    // int kthSmallest(TreeNode* root, int k) {
    //     vector<int> res;
    //     INO(root, res);

    //     return res[k-1];
    // }
};