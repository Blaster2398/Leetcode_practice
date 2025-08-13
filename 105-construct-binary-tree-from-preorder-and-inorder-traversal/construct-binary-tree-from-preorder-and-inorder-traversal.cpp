
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

    // we have inorder of low to high ( this is the range where we have to split it into left and right )
    // and we have the low2 for getting the root for this recursion
    TreeNode* build(vector<int>& pre, vector<int>& inn, int low, int high, int low2,  unordered_map<int, int>& mp){
        if(low > high) return NULL;
        TreeNode* root = new TreeNode(pre[low2]);

        int ind = mp[pre[low2]];
        TreeNode* l= build(pre, inn, low, ind-1, low2 + 1, mp);
        TreeNode* r = build(pre, inn, ind+1, high, low2 + (ind - low + 1), mp);

        root->left = l;
        root->right = r;

        return root;

    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& inn) {
        unordered_map<int, int> mp;
        int n = inn.size();
        for(int i = 0; i < n; i++) mp[inn[i]] = i;
        
        TreeNode* root  = build(pre,inn, 0, n-1, 0, mp);

        return  root;
    }
};