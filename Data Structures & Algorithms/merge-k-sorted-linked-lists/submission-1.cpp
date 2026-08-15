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

class Comparator {
    public:
    bool operator()(ListNode *a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comparator> min_heap;
        for(auto l: lists){
            min_heap.push(l);
        }

        ListNode* dummy = new ListNode(0, NULL);
        ListNode* cur = dummy;
        while(!min_heap.empty()){
            ListNode *temp = min_heap.top();
            min_heap.pop();
            if(temp->next){
                min_heap.push(temp->next);
            }
            cur->next = temp;
            cur = temp;
        }

        cur->next = NULL;

        return dummy->next;


    }
};
