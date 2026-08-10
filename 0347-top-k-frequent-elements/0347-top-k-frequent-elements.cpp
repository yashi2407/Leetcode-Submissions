class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        vector<vector<int>>freq(nums.size()+1);
        for(auto it : map){
            int frequency = it.second;
            int val = it.first;
            freq[frequency].push_back(val);
        }
        // need top k elements
        for(int i = freq.size()-1;i>=0;i--){
            if(freq[i].size()>0 && k>0){
                vector<int>elements = freq[i];
                for(int j = 0;j<elements.size();j++){
                    if(k>0){
                        ans.push_back(elements[j]);
                        k--;
                    }
                    else {
                        break;
                    }
                }
            }
        }
        return ans;
    }
};