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
        ListNode* fast = head;
        if(head==NULL || head->next==NULL){
            return;
        }
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;

        ListNode* cur = mid;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        mid = prev;
        cur = head;
        ListNode* next2;
        while(cur && mid){
            next = cur->next;
            next2 = mid->next;
            cur->next = mid;
            mid->next = next;
            cur = next;
            mid = next2;
        }



    }
};
