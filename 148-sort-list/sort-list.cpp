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

    ListNode* merge(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;

        ListNode* head = NULL;
        ListNode* tail = NULL;

        if(l1->val < l2->val){
            head = tail = l1;
            l1 = l1->next;
        }
        else{
            head = tail = l2;
            l2 = l2->next;
        }

        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
                tail = tail->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
                tail = tail->next;
            }
        }

        tail->next = (!l1) ? l2 : l1;
        
        return head;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            prev = slow;
            slow = slow ->next;
            fast = fast->next->next;
        }

        prev->next =NULL;

        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        
        return merge(left, right);

    }
};