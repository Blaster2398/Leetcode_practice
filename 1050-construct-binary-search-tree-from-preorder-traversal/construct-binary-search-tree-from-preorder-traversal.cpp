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
    void bfp(vector<int>& arr, int& i, int high, int low, TreeNode* root) {
        if (i >= arr.size()) return;

        if (arr[i] > low && arr[i] < root->val) {
            TreeNode* temp = new TreeNode(arr[i]);
            root->left = temp;
            i++;
            bfp(arr, i, root->val, low, root->left);
        }
        if (i < arr.size() && arr[i] > root->val && arr[i] < high) {
            TreeNode* temp = new TreeNode(arr[i]);
            root->right = temp;
            i++;
            bfp(arr, i, high, root->val, root->right);
        }
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr; // Handle empty input case

        TreeNode* root = new TreeNode(preorder[0]);
        int i = 1;
        bfp(preorder, i, INT_MAX, INT_MIN, root); // Use INT_MAX and INT_MIN for proper range

        return root;
    }
};
