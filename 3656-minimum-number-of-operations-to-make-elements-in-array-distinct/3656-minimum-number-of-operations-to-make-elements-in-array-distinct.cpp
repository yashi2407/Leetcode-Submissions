class Solution {
public:
    void removeFirst(vector<int>& nums){
        if(nums.size()>=3){
            // remove first three
            nums.erase(nums.begin(), nums.begin() + 3);
        }
        else{
            // nums become empty
            nums.erase(nums.begin(), nums.begin() + nums.size());
        }
    }
    int minimumOperations(vector<int>& nums) {
        map<int,int>mp;
        int i = 0;
        int count = 0;
        while(i<nums.size()){
            mp[nums[i]]++;
            if(mp[nums[i]]>1){
                // remove elements and start over!
                removeFirst(nums);
                i = 0;
                mp.clear();
                count++;
            }
            else{
                i++;
            }
        }
        return count;
    }
};