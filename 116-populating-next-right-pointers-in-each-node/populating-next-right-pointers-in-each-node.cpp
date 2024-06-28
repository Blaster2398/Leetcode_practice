/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root || (!root->left && !root->right)) return root;

        root->left->next = root->right;
        root->right->next = root->next ? root->next->left : NULL;

        connect(root->left);
        connect(root->right);

        return root;
    }
    
    Node* connect2(Node* root) {
        if(root == NULL)return root;

        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){

                Node* node = q.front();
                q.pop();

                // push the left and right if they are pressent
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }

                Node* to_connect = q.front();

                // for the last node we dont have anything to connect
                if(i == size-1){
                    node->next = NULL;
                }
                else {
                    node->next = to_connect;
                }
            }
        }
        return root;
    }
};