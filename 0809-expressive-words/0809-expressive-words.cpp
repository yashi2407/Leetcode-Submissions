class Solution {
public:
    bool isExpressive(string expressiveWord, string s){
        int i=0; // expressiveWord
        int j=0;// s
        int skippedI = 1;
        int skippedJ = 1;
        while(i<expressiveWord.size() && j < s.size()){
            // skip duplicates of expressiveWord
            while(i+1<expressiveWord.size() && expressiveWord[i] == expressiveWord[i+1]){
                skippedI++;
                i++;
            }
            // skip duplicated of s
            while(j+1<s.size() && s[j] == s[j+1]){
                skippedJ++;
                j++;
            }
            if(expressiveWord[i]!= s[j]){
                return false;
            }
            if (skippedI > skippedJ) {
                return false;
            }
            if (skippedI != skippedJ && skippedJ < 3) {
                return false;
            }
            else {
                i++;
                j++;
                skippedI = 1;
                skippedJ = 1;
            }

        }
        return i == expressiveWord.size() && j == s.size();
    }
    int expressiveWords(string s, vector<string>& words) {
        int count = 0;
        for(int i=0;i<words.size();i++){
            if(isExpressive(words[i],s)){
                count++;
            }
        }
        return count;
    }
};