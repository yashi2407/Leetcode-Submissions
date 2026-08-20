class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(int i = 0;i<words.size();i++){
            mp[words[i]]++;
        }
        auto cmp = [](const auto &a, const auto &b){
            // frequency same ->lexographically larger first so larger gets popped first
            if(a.first == b.first){
                return a.second<b.second;
            }

            return a.first>b.first;
            
        };
        std::priority_queue<pair<int,string>, std::vector<pair<int,string>>, decltype(cmp)> wordFreq(cmp);
        for(auto it:mp){
            wordFreq.push({it.second,it.first});
            if(wordFreq.size()>k){
                wordFreq.pop();
            }
        }
        vector<string>ans;
        while(wordFreq.size()!=0){
            ans.push_back(wordFreq.top().second);
            wordFreq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};