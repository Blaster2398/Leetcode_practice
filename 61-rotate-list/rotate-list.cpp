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
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // we have to know the size of the link list 
        if(head == NULL || k == 0 ) return head;

        int len = 1; 
        ListNode* temp = head;
        while(temp->next != NULL){
            len++;
            temp = temp->next;
        }

        k = k % len;
        if(k == 0) return head;


        ListNode* curr = head;
        ListNode* temp2 = head;

        for(int i = 0; i < len - k - 1; i++){
            curr = curr->next;
            temp2 = temp2->next;
        }
        temp2 = temp2->next;

        curr->next = NULL;
        temp->next = head;

        head = temp2;

        return head;

    }
};