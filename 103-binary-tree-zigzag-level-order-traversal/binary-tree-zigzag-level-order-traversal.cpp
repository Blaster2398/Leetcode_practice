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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL)
            return result;

        // Queue for level order traversal
        queue<TreeNode*> q;
        q.push(root);
        bool direction = true;

        while (!q.empty()) {  // here we cant use !q.empty 
            int count = q.size();
            vector<int> res(count);
            for(int i = 0; i < count; i++){
                root = q.front();
                q.pop();
                if(direction){
                    res[i] =root->val;
                }
                else{
                    res[count-1-i] =root->val;
                }


                // Push left child in the queue
                if (root->left)
                    q.push(root->left);
                // Push right child in the queue
                if (root->right)
                    q.push(root->right);
            }
            result.push_back(res);
            direction = !direction;
        }
        // int i =0;
        // for(auto &it : result){
        //     if(i%2 == 1){
        //         reverse(it.begin(),it.end());
        //     }
        //     i++;
        // }
        return result;
    }
};