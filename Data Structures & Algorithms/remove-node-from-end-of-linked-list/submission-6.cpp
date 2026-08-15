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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n==0 || head == NULL){
            return head;
        }
        ListNode *first = head;
        ListNode *sec = head;
        int cnt = n;
        while(cnt > 0){
            sec = sec->next;
            cnt--;
        } 

        if(sec==NULL){
            return head->next;
        }

        while(sec->next){
            sec = sec->next;
            first = first->next;
        }

        first->next = first->next->next;
        return head;
    }
};
