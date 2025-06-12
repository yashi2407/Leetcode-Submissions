class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1; // the smallest number we can't form yet
        int patches = 0;
        int i = 0;
        
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                // use nums[i] to extend the range
                miss += nums[i];
                i++;
            } else {
                // patch in `miss` to cover the gap
                miss += miss;
                patches++;
            }
        }
        
        return patches;
    }
};