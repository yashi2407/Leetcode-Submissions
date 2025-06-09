class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<pair<int,int>> ms;
        int i=0,j=0;
        int n=nums.size();
        vector<int>ans;
        while(j<n){
            ms.insert({nums[j],j});
            if(j-i+1==k){
                // calculations of ans
                auto lastIt = prev(ms.end()); 
                pair<int, int> last = *lastIt;
                ans.push_back(last.first);
                // removing i
                ms.erase(ms.find({nums[i], i}));
                i++;
            }
            j++;
        }
        return ans;
    }
};