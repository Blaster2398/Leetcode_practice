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
    TreeNode* util(vector<int>& nums, int low, int high) {
        if (low >= high) return NULL;

        int mid = (high + low) / 2;

        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = util(nums, low, mid);
        root->right = util(nums, mid + 1, high);

        return root;
    }

    void INO(TreeNode* root, vector<int>& nums){
        if(root == NULL) return;
        INO(root->left, nums);
        nums.push_back(root->val);
        INO(root->right, nums);

    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        INO(root, nums);

        return util(nums, 0 , nums.size());
    }
};