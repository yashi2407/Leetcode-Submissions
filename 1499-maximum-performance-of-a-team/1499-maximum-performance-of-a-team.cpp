class Solution {
public:
    int MOD = 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>vec;
        for(int i =0;i<n;i++){
            vec.push_back({efficiency[i],speed[i]});
        }

        // sort efficiency in descending order!
        sort(vec.begin(), vec.end(), [](auto &a, auto &b){
            return a.first > b.first; // higher efficiency first
        });

        // We are assuming that if we are stading at efficiency i, it'ss the mimimum one and at that case, i need the top k previous speeds that I have seen!
        priority_queue<int, vector<int>,greater<int>> pq;

        long long currentSum = 0;
        long long ans = INT_MIN;

        for(int i=0;i<n;i++){
            pq.push(vec[i].second);
            currentSum += vec[i].second;

            if(pq.size()>k){
                currentSum -= pq.top();
                pq.pop();
            }
            // at each efficiency, we try to calculate the best answer!
            ans= max(ans,vec[i].first * (long long)currentSum);
        }
        return (int)(ans % MOD);
    }
};