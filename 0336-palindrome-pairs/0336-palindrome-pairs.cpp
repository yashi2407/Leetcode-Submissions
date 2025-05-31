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
            string word = words[i];
            for(int j = 0;j<=word.size();j++){
                string left = word.substr(0,j);
                string right = word.substr(j);
                if(isPalindrome(left)){
                    string temp = right;
                    reverse(temp.begin(),temp.end());
                    if(wordMap.find(temp)!=wordMap.end() && wordMap[temp]!=i){
                        vector<int>index;
                        index.push_back(wordMap[temp]);
                        index.push_back(i); 
                        result.push_back(index);
                    }
                }
                if( j!= word.size() && isPalindrome(right)){
                    string temp = left;
                    reverse(temp.begin(),temp.end());
                    if(wordMap.find(temp)!=wordMap.end()){
                        vector<int>index;
                        index.push_back(i);
                        index.push_back(wordMap[temp]);
                        result.push_back(index);
                    }
                }
            }
        }
        
        
        return result;
    }
};