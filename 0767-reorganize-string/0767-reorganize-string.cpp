class Solution {
public:
    string reorganizeString(string s) {
        vector<int>count(26);
        for(int i = 0;i<s.size();i++){
           count[s[i]-'a']++;
        }
        priority_queue<pair<int,char>>pq;
        for(int i = 0;i<count.size();i++){
            if(count[i]!=0){
                pq.push({count[i], i +'a'});
            }  
        }
        string res = "";
        while(pq.size()>1){
            auto t1 = pq.top();
            pq.pop();
            auto t2 = pq.top();
            pq.pop();

            res += t1.second;
            res += t2.second;
            t1.first--;

            if(t1.first>0){
                pq.push(t1);
            }
            t2.first--;
            if(t2.first>0){
                pq.push(t2);
            }
        }
        // if there's one more element present in pq
        if(!pq.empty()){
            if(pq.top().first > 1){
                return "";
            }
            else{
                res+=pq.top().second;
            }
        }
        return res;
    }
};