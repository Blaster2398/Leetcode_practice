/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        map<Node*,Node*> mp;
        mp[NULL] = NULL;
        Node* copy = NULL;
        while(curr != NULL){
            copy = new Node(curr->val);
            mp[curr] = copy;
            curr = curr-> next;
        }
        curr = head;

        while(curr != NULL){
            copy = mp[curr];
            copy-> next = mp[curr->next];
            copy->random = mp[curr->random];
            curr = curr->next;
        }

        return mp[head];
    }
};