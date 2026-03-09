class Node {
public:
    Node* links[26];
    bool flag;

    Node() {
        for (int i = 0; i < 26; i++) links[i] = nullptr;
        flag = false;
    }

    bool containsKey(char c) {
        return links[c - 'a'] != nullptr;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(const string& word) {
        Node* temp = root;
        for (char ch : word) {
            if (!temp->containsKey(ch)) {
                temp->links[ch - 'a'] = new Node();
            }
            temp = temp->links[ch - 'a'];
        }
        temp->flag = true;
    }
};

class Solution {
public:
    bool dfs(string& word, int index, Trie& trie, vector<int>& dp, int count) {
        if (index == word.size()) {
            return count >= 2;
        }

        if (dp[index] != -1) return dp[index];

        Node* temp = trie.root;

        for (int i = index; i < word.size(); i++) {
            char ch = word[i];
            if (!temp->containsKey(ch)) break;

            temp = temp->links[ch - 'a'];

            if (temp->flag) {
                if (dfs(word, i + 1, trie, dp, count + 1)) {
                    return dp[index] = true;
                }
            }
        }

        return dp[index] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie trie;
        for (auto& word : words) {
            if (!word.empty()) trie.insert(word);
        }

        vector<string> ans;

        for (auto& word : words) {
            if (word.empty()) continue;
            vector<int> dp(word.size(), -1);
            if (dfs(word, 0, trie, dp, 0)) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};