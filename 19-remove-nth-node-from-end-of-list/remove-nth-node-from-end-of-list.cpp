/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
// public:
//     int count_nodes(ListNode* head){
//         ListNode* curr = head;
//         int count = 0;
//         while(curr != NULL){
//             count++;
//             curr = curr->next;
//         }
//         return count;
//     }
    // Method 1
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     int tot_num = count_nodes(head);
    //     int ind = tot_num - n;
    //     int counter = 0;

    //     if(ind == 0){
    //         ListNode* new_head = head->next;
    //         delete head;
    //         return new_head;
    //     }
    //     ListNode* del_p = head; 
    //     for (int i = 0; i < ind - 1; ++i) {
    //         del_p = del_p->next;
    //     }

    //     // Pointer to the node to be deleted
    //     ListNode* del = del_p->next;

    //     if (del->next == NULL) {
    //         del_p->next = NULL;
    //     } else {
    //         del_p->next = del->next;
    //     }
    //     delete(del);
    //     return head;
    // }
    public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        for(int i = 0 ; i < n; i++){
            fast = fast->next;
        }
        // check this condition before moving slow pointer as if we need to delete head then fast will reach NULL in the above loop
        if(fast == NULL){
            ListNode* new_head = head->next;
            delete(head);
            return new_head;
        }

        // now your sliow pointer will stop 1 place before the node you want to delete which was required to delete the required
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* del = slow->next;
        slow->next = slow->next->next;
        delete(del);

        return head;
    }
};