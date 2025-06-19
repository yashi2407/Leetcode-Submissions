class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,j=1;
        int count=1;
        while(j<nums.size()){
            if(nums[j]-nums[i]<=k){
                j++;
            }
            else{
                count++;
                i=j;// start with new i
                j=j+1;
            }
        }
        return count;
    }
};