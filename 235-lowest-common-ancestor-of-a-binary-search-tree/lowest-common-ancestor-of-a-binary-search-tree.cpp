/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool findPath(TreeNode* root, TreeNode*& p, vector<TreeNode*>& path){
        if(root == NULL) return false;

        path.push_back(root);

        if(root == p) return true;

        if(root-> val > p->val){
            if(findPath(root->left,p,path)) return true ;
        }
        else{
            if(findPath(root->right,p,path)) return true;
        }
        // if((findPath(root->left,p,path) || (findPath(root->right,p,path)))){
        //     return true;
        // }

        path.pop_back();

        return false;

    }
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;

        if(!findPath(root, p, path1) || !findPath(root, q, path2)){
            return NULL;
        }
        int i =0;
        for(i = 0; i < path1.size() && i < path2.size(); i++){
            if(path1[i] != path2[i]){
                break;
            }
        }
        return path1[i-1];
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        if(root == p || root == q){
            return root;
        }

        TreeNode* lca1 = lowestCommonAncestor(root->left, p, q);
        TreeNode* lca2 = lowestCommonAncestor(root->right, p, q);

        if(lca1 && lca2){
            return root;
        }
        if(lca1){
            return lca1;
        }
        else{
            return lca2;
        }

        return NULL;
    }
};