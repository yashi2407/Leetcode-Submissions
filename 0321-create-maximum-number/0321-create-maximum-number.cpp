class Solution {
public:
    vector<int> pickMaxSubsequence(vector<int>& nums, int k) {
        vector<int> stack;
        int drop = nums.size() - k;  // how many elements we are allowed to drop

        for (int num : nums) {
            // While current number is bigger than top of stack,
            // and we still have drops left — pop from stack
            while (!stack.empty() && num > stack.back() && drop > 0) {
                stack.pop_back();
                drop--;
            }
            stack.push_back(num);
        }

        // Only take the first k elements (we might have pushed extra)
        stack.resize(k);
        return stack;
    }
    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> merged;
        auto i = a.begin(), j = b.begin();

        while (i != a.end() || j != b.end()) {
            // Compare suffixes lexicographically
            if (lexicographical_compare(i, a.end(), j, b.end())) {
                merged.push_back(*j++);
            } else {
                merged.push_back(*i++);
            }
        }
        return merged;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> best;

        for (int i = max(0, k - n); i <= min(k, m); i++) {
            vector<int> seq1 = pickMaxSubsequence(nums1, i);
            vector<int> seq2 = pickMaxSubsequence(nums2, k - i);
            vector<int> candidate = merge(seq1, seq2);

            if (candidate > best) {
                best = candidate;
            }
        }

        return best;
    }
};