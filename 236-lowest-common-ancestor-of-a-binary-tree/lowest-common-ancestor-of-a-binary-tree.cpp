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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //if the node becomes NULL return NULL
        if(root == NULL){
            return NULL;
        }
        //If you find either one of the nodes you were looking for then return root
        if(root->val == p->val || root->val == q->val){
            return root;
        }

        // if not then check for the left and right if they found anything
        TreeNode* lca1 = lowestCommonAncestor(root->left,p,q);
        TreeNode* lca2 = lowestCommonAncestor(root->right,p,q);

        // it might happen that both of them found one one node required then lca becomes the current root
        if(lca1 != NULL && lca2 != NULL){
            return root;
        }

        // if only one of them return something then we already have found lca and
        //its in the one that is not NULL
        if(lca1 != NULL){
            return lca1;
        }
        else{
            return lca2;
        }
    //it might happen botth are null then simply you didnt found any of them on the given path and return NULL 
    }























    // bool findPath(TreeNode* root, TreeNode* p , vector<TreeNode*> & path){
    //     if(root == NULL){
    //         return false;
    //     }
    //     path.push_back(root);

    //     if(root->val == p->val){
    //         return true;
    //     }
    //     if(findPath(root->left,p,path) || findPath(root->right,p,path)){
    //         return true;
    //     }
    //     path.pop_back();
    //     return false;
    // }
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     vector<TreeNode*> path1, path2;
    //     if(findPath(root, p, path1) == false || findPath(root, q, path2) == false){
    //         return NULL;
    //     }
    //     int i = 0;
    //     for(i = 0; i < path1.size() && i < path2.size(); i++){
    //         if(path1[i] != path2[i]){
    //             break;
    //         }
    //     }
    //     return path1[i-1];
    // }
    
};