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
    ListNode* reverseUtil(ListNode* &head){
        ListNode* curr = head;
        ListNode* nxt = head;
        ListNode* prev = NULL;

        if(head == NULL){
            return NULL;
        }
        while(curr != NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }
    ListNode* kthNodeUtil(ListNode* head, int k){
        k--;  // to ensure right number of steps are taken 
        while(head != NULL && k>0){
            head = head->next;
            k--;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev_node = NULL; // ⚠️ this should be outside the loop so to cunserve the value of previous node
        while(temp != NULL){
            ListNode* kthNode = kthNodeUtil(temp, k);
            if(kthNode == NULL){
                // there might be 2 cases
                //case1 : there are less than k nodes to begin  with (prev_node is non existent so just break)
                // case2 : there are leftovers after some iteration ( then prev_node will be existing so check for it  )
                if(prev_node != NULL){//case2
                    prev_node->next = temp;
                }
                break;
            }

            ListNode* next_node = kthNode->next;
            kthNode->next = NULL;
            kthNode = reverseUtil(temp);
            if(temp == head){ // this will be for the 1st group only 
                head = kthNode;
            }
            else{
                prev_node->next = kthNode;
            }
            prev_node = temp;
            temp = next_node;
        }

        return head;
    }
};