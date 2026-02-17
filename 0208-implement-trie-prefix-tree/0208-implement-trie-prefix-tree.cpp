struct Node {
    Node* links[26];
    bool flag = false;
    bool containsKey(char c){
        if(links[c -'a'] == NULL){
            return false;
        }
        return true;
    }
    void addKey(char c){
        links[c -'a'] = new Node();
    }
};
class Trie {
private:
    Node * root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        for(int i=0;i<word.size();i++){
            // current node doesn't contain key. we add the char into current trie!
            if(!temp->containsKey(word[i])){
                temp->addKey(word[i]);
            }
            temp = temp->links[word[i]-'a'];
        }
        temp->flag = true;
    }
    
    bool search(string word) {
        Node* temp = root;
        for(int i=0;i<word.size();i++){
            if(!temp->containsKey(word[i])){
                return false;
            }
            temp = temp->links[word[i]-'a'];
        }
        return temp->flag;
    }

    bool startsWith(string prefix) {
        Node* temp = root;
        for(int i=0;i<prefix.size();i++){
            if(!temp->containsKey(prefix[i])){
                return false;
            }
            temp = temp->links[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */