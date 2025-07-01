class Solution {
public:
    int util(vector<string>& words,vector<int>& score, unordered_map<char,int>&letterCount, int index){
        if(index>=words.size()){
            return 0;
        }
        // if we can inclue it
        unordered_map<char,int>currentWordletterCount;
        string currentWord= words[index];
        for(int i=0;i<currentWord.size();i++){
            currentWordletterCount[currentWord[i]]++;
        }
        bool canInclude = true;
        for(auto it : currentWordletterCount){
            // if current word's letter is not in letter count!
            if(letterCount.find(it.first) == letterCount.end() || letterCount[it.first] < it.second){
                canInclude = false;
            }
        }
        int included=0 , notIncluded =0;
        if(canInclude){
            for(int i=0;i<currentWord.size();i++){
                letterCount[currentWord[i]]--;
            }
            int currentScore = 0;
            for(int i=0;i<currentWord.size();i++){
                currentScore+=score[currentWord[i]-'a'];
            }
            included = currentScore +  util(words,score,letterCount,index+1);

            for(int i=0;i<currentWord.size();i++){
                letterCount[currentWord[i]]++;
            }
        }
        notIncluded = util(words,score,letterCount,index+1);
        return max(included,notIncluded);

    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int>letterCount;
        for(int i=0;i<letters.size();i++){
            letterCount[letters[i]]++;
        }
        return util(words,score,letterCount,0);
    }
};