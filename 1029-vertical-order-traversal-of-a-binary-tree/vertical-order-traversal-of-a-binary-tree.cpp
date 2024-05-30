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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if( root == NULL){
            return result;
        }
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root,{0,0}});
        // map<int,Node*> mp;
        map <int , map<int , multiset<int>>> mp;
        while(!q.empty()){
            int count = q.size();
            for(int i = 0; i < count; i++){
                auto top = q.front();
                root = top.first;
                int vind = top.second.first;
                int lvl = top.second.second;
                q.pop();
                
                // inert it into the mp make sure you update it not insert 
                mp[vind][lvl].insert(root->val);
                
                if(root->left){
                    q.push({root->left,{vind-1,lvl+1}});
                }
                
                if(root->right){
                    q.push({root->right, {vind+1,lvl+1}});
                }
                
            }
        }
        
        for(auto i : mp){
            vector<int> col;
            for(auto j : i.second){
                col.insert(col.end(),j.second.begin(),j.second.end());
            }
            result.push_back(col);
        }
        
        return result;
    }
};