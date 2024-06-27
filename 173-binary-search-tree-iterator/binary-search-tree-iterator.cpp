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
class BSTIterator {
public:
    stack<TreeNode*> st;
    void gotoleft(TreeNode* root){
        if(root == NULL) return;
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode* root) { 
        gotoleft(root);
    }
    
    int next() {
        TreeNode* ft = st.top();
        st.pop();
        if(ft->right){
            gotoleft(ft->right);
        }
        return ft->val;
    }
    
    bool hasNext() {
        return (st.size()>0);
    }
};


// class BSTIterator {
// public:
//     int i = 0;
//     vector<int> temp;

//     void INO(TreeNode* root){
//         if(root == NULL) return;

//         INO(root->left);
//         temp.push_back(root->val);
//         INO(root->right);
//     }

//     BSTIterator(TreeNode* root) { 
//         temp.push_back(INT_MIN);
//         INO(root);
//     }
    
//     int next() {
//         i++;
//         int siz = temp.size();
//         if(i <= siz){
//             return temp[i]; 
//         }
//         return -1;
//     }
    
//     bool hasNext() {
//         cout << i <<" ";
//         cout << temp.size() << endl;
//         return (i < temp.size()-1);
//     }
// };

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */