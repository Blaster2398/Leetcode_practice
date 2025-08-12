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

    int util(TreeNode* root, int& maxi){
        if(root == NULL) return 0;

        int lh = util(root->left, maxi);
        int rh = util(root->right, maxi);


        if(lh < 0){
            lh = 0;
        }
        if(rh < 0){
            rh = 0;
        }

        maxi = max(maxi, root->val+lh+rh);

        //if(max(lh,rh) ==0) return (root->val > 0) ? root->val : 0;

        return root->val + max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int ans = util(root, maxi);
        return maxi;
    }
};