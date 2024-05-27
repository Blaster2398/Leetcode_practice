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
    // ListNode* reverseList(ListNode* head) {
    //     stack<ListNode*> s;
    //     ListNode* curr = head;

    //     ListNode* result =NULL;
    //     ListNode* resp = NULL;
    //     while(curr){
    //         s.push(curr);
    //         curr = curr->next;
    //     }

    //     while(!s.empty()){
    //         ListNode* temp = s.top();
    //         s.pop();
    //         if(result ==NULL){
    //             result = temp;
    //             resp = result;
    //         }
    //         else{
    //             resp->next = temp;
    //             resp = resp->next;
    //         }
    //     }

    //     if (resp != NULL) // Ensure the last node's next pointer is NULL
    //         resp->next = NULL;


    //     return result;
    // }
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* nxt = head;
        ListNode* prv = NULL;

        if(head == NULL){
            return NULL;
        }

        while(curr != NULL){// this is impo as to ensure that the last node arrow is reversed 
            nxt = curr-> next;
            curr->next = prv;
            prv = curr;
            curr = nxt;
        }

        return prv;
    }
};