class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroIndex = 0;
        int twoIndex = nums.size()-1;
        int i=0;
        while(i<=twoIndex){ // why this while condition???
            if(nums[i] == 2){
                swap(nums[i],nums[twoIndex]);
                twoIndex--;
            }
            else if(nums[i] == 0){
                swap(nums[i],nums[zeroIndex]);
                zeroIndex++;
                i++;
            }
            else {
                i++;
            }
        }
    }
};