class Node {
public:
    Node* links[26];
    bool flag = false;
    bool containsKey(char c) {
        return links[c - 'a'] != NULL;
    }
    void addKey(char c) {
        links[c - 'a'] = new Node();
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    Node* getRoot() {
        return root;
    }

    void insert(string word) {
        Node* temp = root;
        for (int i = 0; i < word.size(); i++) {
            if (!temp->containsKey(word[i])) {
                temp->addKey(word[i]);
            }
            temp = temp->links[word[i] - 'a'];
        }
        temp->flag = true;
    }
};

class Solution {
public:
    void util(int row, int col, Node* node, vector<vector<bool>>& vis,
              unordered_set<string>& ans, string& currentString,
              vector<vector<char>>& board) {
        
        if (node->flag) {
            ans.insert(currentString);
        }

        int delRow[] = {0, 0, -1, 1};
        int delCol[] = {1, -1, 0, 0};

        for (int k = 0; k < 4; k++) {
            int nRow = row + delRow[k];
            int nCol = col + delCol[k];

            if (nRow >= 0 && nRow < board.size() &&
                nCol >= 0 && nCol < board[0].size() &&
                !vis[nRow][nCol]) {
                
                char ch = board[nRow][nCol];

                if (node->containsKey(ch)) {
                    vis[nRow][nCol] = true;
                    currentString.push_back(ch);

                    util(nRow, nCol, node->links[ch - 'a'], vis, ans, currentString, board);

                    currentString.pop_back();
                    vis[nRow][nCol] = false;
                }
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie();
        for (int i = 0; i < words.size(); i++) {
            trie->insert(words[i]);
        }

        unordered_set<string> ans;
        Node* root = trie->getRoot();

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                char ch = board[i][j];

                if (root->containsKey(ch)) {
                    vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
                    vis[i][j] = true;

                    string currentString = "";
                    currentString.push_back(ch);

                    util(i, j, root->links[ch - 'a'], vis, ans, currentString, board);
                }
            }
        }

        return vector<string>(ans.begin(), ans.end());
    }
};