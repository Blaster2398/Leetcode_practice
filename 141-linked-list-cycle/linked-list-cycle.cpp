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
    bool hasCycle(ListNode *head) {
       unordered_set<ListNode*> st;
       if(head ==NULL){
        return false;
       }
       while(true){
        if(st.find(head) != st.end()){
            return true;
        }
        st.insert(head);
        if(head->next == NULL){
            return false;
        }
        head = head->next;
       }
       return false;
    }
};