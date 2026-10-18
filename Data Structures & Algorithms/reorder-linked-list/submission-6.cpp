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
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *second = slow->next;
        slow->next = NULL;

        ListNode *curr = second;
        ListNode *next = NULL;
        ListNode *prev = NULL;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        second = prev;

        ListNode *dummy = new ListNode();
        ListNode *first = head;
        curr = dummy;
        while(first){
            curr->next = first;
            first = first->next;
            if(second == NULL){
                break;
            }
            curr->next->next = second;
            second = second->next;
            curr = curr->next->next;
        }

        head = dummy->next;
        return;

        
    }
};
