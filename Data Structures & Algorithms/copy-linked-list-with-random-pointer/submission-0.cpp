/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node *utility(Node *curr, unordered_map<Node*, Node*> &mp){
        if(curr == NULL){
            return NULL;
        }

        if(mp.find(curr)!=mp.end()){
            return mp[curr];
        }

        Node *copy = new Node(curr->val);
        mp[curr] = copy;
        copy->next = utility(curr->next, mp);
        copy->random = utility(curr->random, mp);

        return copy;
    }
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> mp;
        return utility(head, mp);
    }
};
