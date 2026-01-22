class Solution {
public:
    bool isNonDecreasing(vector<int> &nums){
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                return false;
            }
        }
        return true;
    }
    pair<int,int> getMinSumAndIndex(vector<int>& nums){
        int minSum = INT_MAX;
        int index = INT_MAX;
        for(int i=0;i<nums.size()-1;i++){
            int currentSum = nums[i] + nums[i+1];
            if(currentSum<minSum){
                minSum = currentSum;
                index = i;
            }
        }
        return {minSum,index};
    }
    int minimumPairRemoval(vector<int>& nums) {
        int steps = 0;
        while(!isNonDecreasing(nums)){
            auto [sum,index] = getMinSumAndIndex(nums);
            nums[index] = sum;
            nums.erase(nums.begin() + index + 1);
            steps++;
        }
        return steps;
    }
};