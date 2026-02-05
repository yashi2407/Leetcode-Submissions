class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        if(nums.size()==0){
            return 0;
        }
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int longest = INT_MIN;
        for(auto x : s){
            // if x - 1 is in the set,then x is not the starting point
            if(s.find(x-1) == s.end()){
                int count = 1;
                // looping till we find the sequence's end
                while(s.find(x+1) != s.end()){
                    count++;
                    x++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};