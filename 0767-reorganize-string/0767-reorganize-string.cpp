class Solution {
public:
    string reorganizeString(string s) {
        string ans="";
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            if(mp[s[i]] == ((s.size()+1)/2)+1){
                return "";
            }
        }
        // put them in heap!!! greddily will set 
        priority_queue<pair<int,char>>pq;
        for(auto &it:mp){
            pq.push({it.second,it.first});
        }
        
        while(pq.size()>1){
            char c1 = pq.top().second;
            int count1 = pq.top().first;
            pq.pop();

            char c2 = pq.top().second;
            int count2 = pq.top().first;
            pq.pop();

            ans+=c1;
            ans+=c2;

            count1--;
            count2--;
            if(count1 > 0){
                pq.push({count1,c1});
            }
            if(count2 > 0){
                pq.push({count2,c2});
            }
        }
        // out of this loop, either same character multiple times or 1 extra
        if(!pq.empty()){
            if(pq.top().first>1){
                return "";
            }
            else{
                ans+= pq.top().second;
            }
        }
        return ans;
    }
};