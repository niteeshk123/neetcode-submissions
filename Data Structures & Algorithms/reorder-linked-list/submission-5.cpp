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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast = fast->next->next;
        }

        ListNode* cur = slow->next;
        ListNode* prev = slow->next = NULL;
        ListNode* next = NULL;
        while(cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        fast = head;
        while(fast && prev){
            next = fast->next;
            fast->next = prev;
            slow = prev->next;
            prev->next = next;
            prev = slow;
            fast = next;
        }

        return;
    }
};
