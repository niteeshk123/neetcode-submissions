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
        int count  = 0;
        ListNode* cur = head;
        while(cur){
            cur=cur->next;
            count++;
        }

        
    
        count  = count-n;
        if (count==0){
            return head->next;
        }
         cur = head;
        while(count>1){
            cur = cur->next;
            count--;
        }
        cur->next = cur->next->next;
        return head;
    }
};
