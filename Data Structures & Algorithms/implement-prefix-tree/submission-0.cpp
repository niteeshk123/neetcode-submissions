class Node{
    public:
    Node* child[26];
    bool isleaf;

    Node(){
        for(int i=0; i<26; i++){
            child[i] = NULL;
        }
        isleaf = false;
    }
};

class PrefixTree {
public:
    Node *head;
    PrefixTree() {
        head = new Node();
    }
    
    void insert(string word) {
        Node *cur = head;
        for(auto c: word){
            if(cur->child[c-'a']){
                cur = cur->child[c-'a'];
            }
            else {
                Node *temp = new Node();
                cur->child[c-'a'] = temp;
                cur = cur->child[c-'a'];
            }
        }
        cur->isleaf = true;
    }
    
    bool search(string word) {
        Node *cur = head;
        for(auto c: word){
            if(cur->child[c-'a']){
                cur = cur->child[c-'a'];
            } else {
                return false;
            }
        }
        if(cur->isleaf){
            return true;
        } else {
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        Node *cur = head;
        for(auto c: prefix){
            if(cur->child[c-'a']){
                cur = cur->child[c-'a'];
            } else {
                return false;
            }
        }

        return true;
    }
};
