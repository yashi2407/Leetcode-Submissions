class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, j = numbers.size()-1;
        // we need two numbers hence not equal to
        vector<int>ans;
        while(i<j){
            int currentSum = numbers[i]+numbers[j];
            if(currentSum == target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
            else if(currentSum > target){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};