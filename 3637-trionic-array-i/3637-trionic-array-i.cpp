class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false; 
        int i = 0;

        // 1) strictly increasing: nums[0..p]
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
        int p = i;
        if (p == 0) return false;          // must increase at least once

        // 2) strictly decreasing: nums[p..q]
        while (i + 1 < n && nums[i] > nums[i + 1]) i++;
        int q = i;
        if (q == p) return false;          // must decrease at least once

        // 3) strictly increasing: nums[q..n-1]
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
        if (i != n - 1) return false;      // must consume whole array

        // ensure q < n-1 
        if (q == n - 1) return false;

        return true;
    }
};
