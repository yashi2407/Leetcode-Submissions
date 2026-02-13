class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int i=0;
        int j=nums.size()-1;
        int index = nums.size()-1;
        while(j>=i){
            // j will fill the last place
            int num1= abs(nums[i]);
            int num2 = abs(nums[j]);
            if(num2>num1){
                ans[index] = num2 * num2;
                index--;
                j--;
            }
            else {
                ans[index] = num1 * num1;
                index--;
                i++;
            }
        }
        return ans;
    }
};