class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int currentFirstIndex = 0;
        int currentSecondIndex = 1;
        int n = barcodes.size();
        unordered_map<int,int>mp;
        for(int i=0;i<barcodes.size();i++){
            mp[barcodes[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it : mp){
            pq.push({it.second,it.first});
        }
        vector<int> ans(n);
        while(pq.size()>1){
            auto firstEle = pq.top();
            pq.pop();
            auto secondEle = pq.top();
            pq.pop();
            ans[currentFirstIndex] = firstEle.second;
            ans[currentSecondIndex] = secondEle.second;
            currentFirstIndex +=2;
            currentSecondIndex +=2;
            // decrease the frequency count
            firstEle.first--;
            secondEle.first--;

            if(firstEle.first>0){
                pq.push(firstEle);
            }
            if(secondEle.first >0){
                pq.push(secondEle);
            }
        }
        if(!pq.empty()){
            ans[currentFirstIndex] = pq.top().second;
        }
        return ans;
    }
};