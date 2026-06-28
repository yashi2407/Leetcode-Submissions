class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size() == 0){
            return ans;
        }

        int i = 0;
        while(i<nums.size()){
            int j = i;
            while (j + 1 < nums.size() && (long long)nums[j + 1] - (long long)nums[j] == 1) {
                j++;
            }
            if(i == j){
                ans.push_back(to_string(nums[i]));
            }
            else {
                ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            }
            i = j+1;
        }

        return ans;
    }
};