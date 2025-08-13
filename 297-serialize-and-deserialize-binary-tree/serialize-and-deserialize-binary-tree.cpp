/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        // binary tree i will convert it to this form -> "1,2,3,N,N,4,5";

        queue<TreeNode*> q;
        q.push(root);
        string res = "";

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            if (node) {
                res += to_string(node->val) + ',';
                q.push(node->left);
                q.push(node->right);
            } else {
                res += "N,";
            }
        }

        return res;

    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "N") node->left = NULL;
            else{
                TreeNode* temp = new TreeNode(stoi(str));
                node->left = temp;
                q.push(temp);
            }
            getline(s, str, ',');
            if(str == "N") node->right = NULL;
            else{
                TreeNode* temp = new TreeNode(stoi(str));
                node->right = temp;
                q.push(temp);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));