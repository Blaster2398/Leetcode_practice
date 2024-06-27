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
    bool INO(TreeNode* root, unordered_set<int>& st, int k){
        bool left = false;
        bool right = false;

        if(root->left != NULL){
            left = INO(root->left,st,k);
        }

        cout << root->val <<endl;
        if(st.find(k-(root->val)) != st.end()){
            return true;
        }
        st.insert(root->val);

        if(root->right!= NULL){
            right = INO(root->right, st, k);
        }
        return left || right;

    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        bool res = INO(root, st, k);
        cout << "printing the set" <<endl;
        for(int i : st){
            cout << i << " " ;

        }
        cout << endl;
        return res;
    }
};