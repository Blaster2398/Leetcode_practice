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
    ListNode *getIntersectionNode_opt(ListNode *headA, ListNode *headB) {
        // //Brute Force
        // while(headB != NULL){
        //     ListNode* temp = headA;
        //     while(temp != NULL){
        //         if(temp == headB){
        //             return temp;
        //         }
        //         temp = temp->next;
        //     }
        //     headB = headB->next;
        // }
        // return NULL;

        // optimized by hashing as the node of intersection should have same address
        unordered_set<ListNode*> st;
        while(headA != NULL){
            st.insert(headA);
            headA = headA->next;
        }

        while(headB != NULL){
            if((st.find(headB) != st.end())){
                return headB;
            }
            headB = headB->next;
        }
        return NULL;

    }
    ListNode * getIntersectionNode(ListNode * head1,ListNode * head2) {
        ListNode * d1 = head1;
        ListNode * d2 = head2;
        
        while(d1 != d2) {
            d1 = d1 == NULL? head2:d1->next;
            d2 = d2 == NULL? head1:d2->next;
        }
        
        return d1;
    }
};