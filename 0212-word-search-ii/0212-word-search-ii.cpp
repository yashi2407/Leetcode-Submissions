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

class Solution {
public:
    void util(int row, int col , Trie *trie, vector<vector<bool>>&vis, unordered_set<string>&ans, string currentString,vector<vector<char>>& board){
        if(row<0 || row >=board.size() || col<0 || col >=board[0].size()){
            return;
        }
        // if the current word in trie, you can put in answer and return
        if(trie->search(currentString)){
            ans.insert(currentString);
        }
        int delRow[] = {0, 0, -1, 1};
        int delCol[] = {1, -1, 0, 0};
        for(int k=0;k<4;k++){
            int nRow = row + delRow[k];
            int nCol = col + delCol[k];
            if(nRow>=0 && nRow <board.size() && nCol>=0 && nCol <board[0].size() &&!vis[nRow][nCol] && trie->startsWith(currentString + board[nRow][nCol])){
                // if it exists, then we move to that direction
                vis[nRow][nCol] = true;
                currentString+= board[nRow][nCol];
                util(nRow,nCol,trie,vis,ans,currentString,board);
                vis[nRow][nCol] = false;
                currentString.pop_back();
            }
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *trie = new Trie();
        for(int i = 0;i<words.size();i++){
            trie->insert(words[i]);
        }
        unordered_set<string> ans;
        // start dfs 
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                // board[i][j] becomes the starting point 
                string start(1, board[i][j]);
                if(trie->startsWith(start)){
                    // start the search!
                    vector<vector<bool>>vis(board.size(),vector<bool>(board[0].size(),false));
                    vis[i][j]= true;
                    string currentString = start;
                    util(i,j,trie,vis,ans,currentString,board);
                }  
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};