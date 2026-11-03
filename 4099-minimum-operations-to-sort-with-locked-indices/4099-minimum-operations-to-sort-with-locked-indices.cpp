class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int requiredLocks = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int target = nums[i] - 1;
            if (i == target) continue;
            for (int j = min(i, target); j <= max(i, target); j++) {
                if (locked[j] == 1) {
                    locked[j] = 0;
                    requiredLocks++;
                }
            }
        }
        if(requiredLocks>k){
            return -1;
        }
        int inversion = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j]){
                    inversion++;
                }
            }
        }
        return inversion+ requiredLocks;
    }
};


