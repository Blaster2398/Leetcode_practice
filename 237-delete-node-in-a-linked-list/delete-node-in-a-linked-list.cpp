/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = node;
        while(node->next->next != NULL){
            node->val = node->next->val;
            node = node->next;
        }
        ListNode* sec_last = node;
        node->val = node->next->val;
        node = node->next;
        
        cout << node->next << " " <<node->val;
        
        delete(node);
        sec_last->next = NULL;
    }
};