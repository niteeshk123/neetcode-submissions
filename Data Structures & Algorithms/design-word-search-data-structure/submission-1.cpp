class Node {
    public:
    bool isleaf;
    Node* child[26];

    Node() {
        for(int i=0; i<26; i++){
            child[i] = NULL;
        }
        isleaf = false;
    }
};

class WordDictionary {
public:
    Node* head;
    WordDictionary() {
        head = new Node();
    }
    
    void addWord(string word) {
        Node *cur = head;
        for(auto c: word) {
            if(cur->child[c-'a']){
                cur = cur->child[c-'a'];
            } else {
                Node *temp = new Node();
                cur->child[c-'a'] = temp;
                cur = temp;
            }
        }

        cur->isleaf = true;

    }
    
    bool search(string word) {
        return dfs(word, 0, head);
    }

    private:
    bool dfs(string word, int j, Node *node){
        Node* cur = node;
        for(int i=j; i<word.length(); i++){
            char c = word[i];
            if(c=='.'){
                for(int k=0; k<26; k++){
                    if(cur->child[k] && dfs(word, i+1, cur->child[k])){
                        return true;
                    }
                }
                return false;
            } else {
                if(cur->child[c-'a']){
                    cur = cur->child[c-'a'];
                } else {
                    return false;
                }
            }
        }

        return cur->isleaf;
    }
};
