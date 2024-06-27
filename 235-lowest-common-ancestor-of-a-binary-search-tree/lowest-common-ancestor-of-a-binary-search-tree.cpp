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

        if((findPath(root->left,p,path) || (findPath(root->right,p,path)))){
            return true;
        }

        path.pop_back();

        return false;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
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
};