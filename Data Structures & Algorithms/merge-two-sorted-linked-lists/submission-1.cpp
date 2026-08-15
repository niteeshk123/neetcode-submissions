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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        ListNode* head = NULL;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        if(cur1==NULL){
            return cur2;
        } else if(cur2==NULL){
            return cur1;
        } else if(cur1==NULL && cur2==NULL){
            return NULL;
        }
        while(cur1 && cur2) {
            if(cur1->val<cur2->val){
                if(head==NULL){
                    head = cur1;
                    prev = cur1;
                    cur1 = cur1->next;
                    continue;
                }
                prev->next = cur1;
                prev = cur1;
                cur1 = cur1->next;
            } else {
                if(head==NULL){
                    head = cur2;
                    prev = cur2;
                    cur2 = cur2->next;
                    continue;
                }
                prev->next = cur2;
                prev = cur2;
                cur2 = cur2->next;
            }
        }
        if(cur1){
            prev->next = cur1;
        }
        if(cur2){
            prev->next = cur2;
        }
        return head;
    }
};
