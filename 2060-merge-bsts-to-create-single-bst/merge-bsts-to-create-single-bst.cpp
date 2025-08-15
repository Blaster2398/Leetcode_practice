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
private:
    bool validate(TreeNode* root, int low, int high){
        if(!root) return true;

        if(root->val >= high || root->val <= low) return false;

        return (validate(root->left, low,root->val) && validate(root->right, root->val, high));
    }
public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        map<int, TreeNode*> leaf;
        map<int, TreeNode*> roots;

        for(auto root : trees){
            roots[root->val] = root;
            if(root->left) leaf[root->left->val] = root->left;
            if(root->right) leaf[root->right->val] = root->right;
        }


        // we got the primary root 
        TreeNode* proot = NULL;
        int count = 0;
        for(auto [val, root] : roots){
            if(leaf.find(val) == leaf.end()){
                proot = root;
                count++;
                if(count > 1) return NULL;
            }
        }
        if (!proot) return NULL;

        queue<TreeNode*> q;
        q.push(proot);
        while(!q.empty()){
            auto node = q.front(); 
            q.pop();

            if(node->left) {
                if(roots.find(node->left->val) != roots.end()){
                    node->left = roots[node->left->val];
                    roots.erase(node->left->val); 
                }
                    
                q.push(node->left);
            }
            if(node->right) {
                if(roots.find(node->right->val) != roots.end()){
                    node->right = roots[node->right->val];
                    roots.erase(node->right->val);
                }
                    
                q.push(node->right);
            }       
        }
        // if there is something left then also its not okay
        if (roots.size() != 1) return NULL; 

        return (validate(proot, INT_MIN, INT_MAX)) ? proot : NULL;
    }
};