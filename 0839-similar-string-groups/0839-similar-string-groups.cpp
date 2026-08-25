class Solution {
public:
    void bfs(string start,unordered_map<string,vector<string>>&mp,unordered_set<string>&vis){
        queue<string>q;
        q.push(start);
        while(!q.empty()){
            string current = q.front();
            q.pop();
            for(auto &it:mp[current]){
                if(vis.find(it) == vis.end()){
                    vis.insert(it);
                    q.push(it);
                }
            }
        }
    }
    bool isSimilar(string s1, string s2){
        if(s1 == s2){
            return true;
        }
        int count = 0;
        char c1 = '\0';
        char c2 = '\0';
        char c3 = '\0';
        char c4 = '\0';
        for(int i=0;i<s1.size();i++){
            if(s1[i] != s2[i]){
                if(count == 0){
                    c1 = s1[i];
                    c3 = s2[i];
                }
                else if(count == 1){
                    c2 = s1[i];
                    c4 = s2[i];
                }
                else if(count>2){
                    return false; // not similar
                }
                count++;
            }
        }
        if(count<1){
            return false;
        }
        return (c1 == c4 && c2 == c3);
    }
    int numSimilarGroups(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(int i = 0;i<strs.size();i++){
            for(int j = 0;j<strs.size();j++){
                if(i!=j && isSimilar(strs[i],strs[j])){
                    mp[strs[i]].push_back(strs[j]);
                    mp[strs[j]].push_back(strs[i]);
                }
            }
        }
        unordered_set<string>vis;
        int count = 0;
        for(int i=0;i<strs.size();i++){
            if(vis.find(strs[i]) == vis.end()){
                count++;
                vis.insert(strs[i]);
                bfs(strs[i],mp,vis);
            }
        }
        return count;
    }
};