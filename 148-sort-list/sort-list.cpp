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
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;
        multimap<int, ListNode*> mp;
        while (head) {
            mp.insert({head->val, head});
            head = head->next;
        }
        ListNode* temp = new ListNode(1e7);
        ListNode* temp2 = temp;
        for(auto [val, node] : mp){
            temp2->next = node;
            temp2 = node;
        }
        temp2->next = nullptr;
        return temp->next;
    }
};