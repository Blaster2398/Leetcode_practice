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
    ListNode* reverseUtil(ListNode* head) {
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
    ListNode* cop ( ListNode* head){
        ListNode* cupy = new ListNode(head->val);
        ListNode* temp2 = cupy;
        head = head->next;
        while(head != NULL){
            ListNode* temp = new ListNode(head->val);
            temp2->next = temp;
            temp2 = temp2->next;
            head = head->next;
        }
        return cupy;
    }
    // void print(ListNode* head){
    //     while(head != NULL){
    //         cout << head->val << "->";
    //         head = head-> next;
    //     }
    //     cout << endl;
    // }
    bool isPalindrome(ListNode* head) {
        ListNode* rev = cop(head);
        // print(rev);
        rev = reverseUtil(rev);
        // print(head);
        // print(rev);
        while(head != NULL && rev != NULL){
            if(head->val != rev-> val){
                return false;
            }
            head = head->next;
            rev = rev->next;
        }
        return true;
    }
};