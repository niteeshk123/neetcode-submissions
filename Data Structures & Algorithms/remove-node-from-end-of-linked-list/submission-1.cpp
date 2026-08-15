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
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        int len = 0;
        ListNode* cur = head;
        int pos = 0;
        while(cur){
            len++;
            cur = cur->next;
        }

        pos = len - n;

        len = 0;

        cur = head;
        ListNode* prev = NULL;
        while(cur){
            len++;
            if(len>pos){
                if(prev == NULL){
                    head = cur->next;
                }
                else
                    prev->next = cur->next;
                break;
            }
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};
