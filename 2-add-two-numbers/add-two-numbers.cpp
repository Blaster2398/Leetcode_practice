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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int carry = 0;
        while( l1 != NULL && l2 != NULL){
            cout<< carry << " " << "_>carry"<<endl;
            int temp = (l1->val) + (l2->val) + carry;
            cout << temp << endl;
            int to_insert = temp % 10;
            carry = temp / 10;
            curr->next = new ListNode(to_insert);
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 != NULL){
            while(l1 != NULL){
                int temp = l1->val + carry ;
                int to_insert = temp % 10;
                carry = temp / 10;
                curr->next = new ListNode(to_insert);
                curr = curr->next;
                l1 = l1->next;
            }
        }
        else if(l2 != NULL){
            while(l2 != NULL){
                int temp = l2->val + carry ;
                int to_insert = temp % 10;
                carry = temp / 10;
                curr->next = new ListNode(to_insert);
                curr = curr->next;
                l2 = l2->next;
            }
        }

        if(carry != 0){
            curr->next = new ListNode(carry);
        }


        ListNode* result = dummy->next;
        delete(dummy);
        return result;
    }
};