class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int evenCount = 0;
        int oddCount = 0;
        int alternating = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2 == 0){
                evenCount++;
            }
            else {
                oddCount++;
            }
        }
        int parity = nums[0]% 2;
        for(int i=1;i<nums.size();i++){
            if(nums[i]% 2 != parity){
                alternating++;
                parity = nums[i]% 2;
            }
        }
        return max({evenCount,alternating,oddCount});
    }
};