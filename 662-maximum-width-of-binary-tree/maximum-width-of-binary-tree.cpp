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
using ll = long long;
    int widthOfBinaryTree(TreeNode* root) {
        // lvl -> -vind1 <-> +vind2
       
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0ll});

        ll res = 0;
        while(!q.empty()){
            int sz = q.size();
            ll mun = 0, mux = 0;
            ll minInd = q.front().second;
            for(int i = 0; i < sz; i++){
                auto [node, vind] = q.front();
                q.pop();

                ll ind = vind - minInd;

                if(i == 0) mun = ind;
                if(i == sz-1) mux = ind;
                

                if(node->left) q.push({node->left, 2*ind+1});
                if(node->right) q.push({node->right, 2*ind+2});

            }
            res = max(res, mux - mun + 1);
        }
        return (int)res;
    }
};