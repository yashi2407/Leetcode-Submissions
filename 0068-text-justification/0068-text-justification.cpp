class Solution {
public:
    string makeLastSentence(vector<string> &currentWords, int maxWidth){
        string ans = "";
        for(int i = 0;i<currentWords.size();i++){
            if(i!=currentWords.size()-1){
                ans += currentWords[i] + " ";
            }
            else{
                ans += currentWords[i];
            }
        }
        // add in remaining spaces
        while(ans.size()< maxWidth){
            ans += " ";
        }
        return ans;
    }
    string makeAnsString(vector<string>& currentWords, int currentCharacterCountWithoutSpaces, int maxWidth) {
        int totalWords = currentWords.size();
        string ans = "";
        int spaces = maxWidth - currentCharacterCountWithoutSpaces;
        // Only one word: left justify it
        if (totalWords == 1) {
            ans += currentWords[0];

            while (ans.size() < maxWidth) {
                ans += " ";
            }

            return ans;
        }

        int individualSpace = spaces / (totalWords - 1);
        int remainingSpaces = spaces % (totalWords - 1);

        for (int i = 0; i < currentWords.size(); i++) {
            ans += currentWords[i];

            if (i != currentWords.size() - 1) {
                int spacesToAdd = individualSpace;

                // Give one additional space to leftmost gaps
                if (i < remainingSpaces) {
                    spacesToAdd++;
                }

                for (int j = 0; j < spacesToAdd; j++) {
                    ans += " ";
                }
            }
        }

        return ans;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int currentCharacterCount = 0;
        int currentCharacterCountWithoutSpaces = 0;
        vector<string> currentWords;
        for(int i=0;i<words.size();i++){
            if(currentCharacterCount + words[i].length()<=maxWidth){
                currentWords.push_back(words[i]);
                currentCharacterCountWithoutSpaces += words[i].length();
                currentCharacterCount+= words[i].length() + 1;
            }
            else {
                // make the string and then reset
                ans.push_back(makeAnsString(currentWords, currentCharacterCountWithoutSpaces,maxWidth));
                currentCharacterCount = words[i].length() + 1 ;
                currentCharacterCountWithoutSpaces = words[i].length();
                // empty the current words
                currentWords.clear();
                currentWords.push_back(words[i]);
            }
        }
        // last line!
        if(currentWords.size()!=0){
            ans.push_back(makeLastSentence(currentWords, maxWidth));
        }
        return ans;
    }
};