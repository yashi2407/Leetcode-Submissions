class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        int count = 0;
        int ans = 0;
        if(fruits.size()==1){
            return 1;
        }
        while(j<fruits.size()){
            mp[fruits[j]]++;
            count++;
            if(mp.size()>2){
                // remove the calculations for i
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0){
                    mp.erase(fruits[i]);
                }
                count--;
                i++;
            }
            ans = max(ans,count);
            j++;
        }
        return ans;
    }
};