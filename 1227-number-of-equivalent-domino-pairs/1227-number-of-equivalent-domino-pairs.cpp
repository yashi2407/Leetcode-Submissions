class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int> mp;
        int count = 0;
        for(int i =0;i<dominoes.size();i++){
            int a = dominoes[i][0];
            int b = dominoes[i][1];
            pair<int, int> key = {min(a, b), max(a, b)}; // treating {1,2} {2,1} as same.
            count += mp[key]; 
            mp[key]++;
        }
        return count;
    }
};