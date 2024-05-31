/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        long long maxWid = 0;
        while(!q.empty()){
            long long count = q.size();
            long long lvl_min = q.front().second;
            long long first,last;
            for(long long i = 0; i < count; i++){
                long long curr_id = q.front().second-lvl_min;
                root = q.front().first;
                q.pop();
                
                if(i == 0) first = curr_id;
                if(i == count-1) last = curr_id;

                if (root->left){
                    q.push({root->left,2*curr_id+1});
                }
                if (root->right){
                    q.push({root->right,2*curr_id+2});
                }
            }
            maxWid = max(maxWid , last-first+1);
        }
        return maxWid;
    }

};
