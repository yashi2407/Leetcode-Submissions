class Solution {
public:
    bool isPalindrome(string &s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        unordered_map<string,int> wordMap;
        // to find out the index of reverse of a string. For Quick lookup.
        for(int i =0;i<words.size();i++){
            wordMap[words[i]] = i;
        }
        for(int i = 0;i<words.size();i++){
            // split at every index of that particular word;
            for(int j = 0;j<=words[i].size();j++){
                string word1 = words[i].substr(0, j);
                string word2 = words[i].substr(j); 
                // check word1 palindrome
                if(isPalindrome(word1)){
                    // a | bcd --- >>> a is palindrome, check if reverse(bcd) exists or not in map
                    string reversedWord2 = word2;
                    reverse(reversedWord2.begin(), reversedWord2.end());
                    if (wordMap.count(reversedWord2) && wordMap[reversedWord2] != i) {
                        // dcb | abcd would be ans
                        result.push_back({wordMap[reversedWord2], i});
                    }
                }
                // j != words[i].size() to avoid duplicates
                if(j != words[i].size() && isPalindrome(word2)){
                    // a | bcd --- >>> a is palindrome, check if reverse(bcd) exists or not in map
                    string reversedWord1 = word1;
                    reverse(reversedWord1.begin(), reversedWord1.end());
                    if (wordMap.count(reversedWord1) && wordMap[reversedWord1] != i) {
                        // dcb | abcd would be ans
                        result.push_back({i,wordMap[reversedWord1]});
                    }
                }
            }
        }
        return result;
    }
};