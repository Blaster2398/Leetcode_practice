
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool flag = false;
        // Step 2: Traverse the linked list with
        // the slow and fast pointers
        while (fast != nullptr && fast->next != nullptr) {
            
            slow = slow->next;

            fast = fast->next->next;

            // Check if slow and fast pointers meet
            if (slow == fast) {
                flag = true;
                break;  // Loop detected
            }
        }

        if(slow == fast && flag){
            ListNode* slow2 = head ;
            while(slow2 != slow){
                slow = slow-> next;
                slow2 = slow2->next;
            }
            return slow;
        }

        cout<< "NULL was PASSED" <<endl;
        return NULL;
    }
};