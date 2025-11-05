class Solution {
public:
    int getSum(int i, int j, int x, vector<int>& nums) {
        unordered_map<int,int> mp;
        for (int t = i; t <= j; t++) {
            mp[nums[t]]++;
        }

        // move (value, freq) into a vector and sort
        vector<pair<int,int>> v; // {value, freq}
        for (auto &p : mp) {
            v.push_back({p.first, p.second});
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            if (a.second != b.second) return a.second > b.second; // freq desc
            return a.first > b.first;                             // value desc
        });

        long long ans = 0;
        int take = min(x, (int)v.size());
        for (int idx = 0; idx < take; idx++) {
            ans += 1LL * v[idx].first * v[idx].second; // value * freq
        }
        return (int)ans;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int>ans;
        // window size = k
        int i=0; int j=0;
        while(j<=nums.size()-1){
            if(j-i+1 == k){
                int sum = getSum(i,j,x,nums);
                ans.push_back(sum);
                i++;
            }
            j++;
        }
        return ans;
    }
};