class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0;
        int ans = 0;
        int countZeros = 0;
        while(j<nums.size()){
            // do calculations for j
            if(nums[j]== 0){
                countZeros++;
            }

            while(countZeros>1){
                if(nums[i]==0){
                    countZeros--;
                }
                i++;
            }
            ans = max(ans, j - i);
            j++; 
        }
        return ans;
    }
};