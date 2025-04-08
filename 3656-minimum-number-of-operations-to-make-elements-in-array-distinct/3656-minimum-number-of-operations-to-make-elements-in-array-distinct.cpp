class Solution {
public:
    // OPTIMIZED APPROACH
    // TC = O(N);
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> seen;
        int start = 0;
        int count = 0;

        for (int i = start; i < nums.size(); i++) {
            if (seen.count(nums[i])) {
                // simulate removal of first 3 elements
                count++;
                start += 3;
                seen.clear();
                i = start - 1; // -1 because the loop will increment i
            } else {
                seen.insert(nums[i]);
            }
        }

        return count;
    }
};