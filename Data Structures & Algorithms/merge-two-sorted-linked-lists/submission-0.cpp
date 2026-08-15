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
        ListNode *cur1;
        ListNode *cur2;
        ListNode head = ListNode(0);
        ListNode* temp = &head;
        if(list1==NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }

        cur1 = list1;
        cur2 = list2;
        while(cur1 && cur2){
            if(cur1->val > cur2->val){
                temp->next = cur2;
                cur2 = cur2->next;
            }
            else{
                temp->next = cur1;
                cur1 = cur1->next;
            }
            temp = temp->next;
            temp->next = NULL;

        }

        if(cur1){
            temp->next = cur1;
        }
        if(cur2){
            temp->next = cur2;
        }

        return head.next;
    }
};
