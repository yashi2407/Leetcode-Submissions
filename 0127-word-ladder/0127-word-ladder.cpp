class Solution {
public:
    bool isOneCharacterDifference(string s, string t){
        if(s.size()!=t.size()){
            return false;
        }
        int count = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]){
                count++;
                if(count>1){
                    return false;
                }
            }
        }
        return true;
    }
    void makeGraph(unordered_map<string, vector<string>>&graph, vector<string>& wordList){
        for(int i=0;i<wordList.size();i++){
            for(int j=0;j<wordList.size(); j++){
                if(j!=i && isOneCharacterDifference(wordList[i],wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                }
            }
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        wordList.push_back(beginWord);
        unordered_map<string, vector<string>>graph;
        makeGraph(graph, wordList);
        queue<pair<string,int>>q;
        unordered_set<string>vis;
        q.push({beginWord,1});
        vis.insert(beginWord);
        while(!q.empty()){
            auto [word,dist] = q.front();
            q.pop();
            if(word == endWord){
                return dist;
            }
            for(auto it : graph[word]){
                if(vis.find(it) == vis.end()){
                    vis.insert(it);
                    q.push({it,dist+1});
                }
            }
        }
        return 0;
    }
};