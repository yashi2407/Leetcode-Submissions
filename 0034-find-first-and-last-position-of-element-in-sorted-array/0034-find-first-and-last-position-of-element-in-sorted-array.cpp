class Solution {
public:
vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;
        
        // Find first occurrence
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            if (nums[mid] == target) first = mid;
        }

        // Find last occurrence
        low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
            if (nums[mid] == target) last = mid;
        }
        return {first, last};
    }

};