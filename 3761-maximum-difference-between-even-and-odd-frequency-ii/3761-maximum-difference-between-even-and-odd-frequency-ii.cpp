class Solution {
public:
    int maxDifference(string s, int k) {
        // Encode the parity status of countA and countB (00, 01, 10, 11)
        auto getParityStatus = [](int countA, int countB) -> int {
            return ((countA % 2) << 1) | (countB % 2);
        };

        int n = s.size();
        int maxDiff = INT_MIN;

        // Try every possible pair of digits (a ≠ b) from '0' to '4'
        for (char a = '0'; a <= '4'; ++a) {
            for (char b = '0'; b <= '4'; ++b) {
                if (a == b) continue;

                // Store the smallest (prefixA - prefixB) seen for each of 4 parity statuses
                int bestDiff[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};

                int totalA = 0, totalB = 0;   // current total count of a and b
                int prefixA = 0, prefixB = 0; // count of a and b up to left index
                int left = -1;

                for (int right = 0; right < n; ++right) {
                    if (s[right] == a) totalA++;
                    if (s[right] == b) totalB++;

                    // Shrink window from left until length >= k and at least 2 b's exist
                    while ((right - left) >= k && (totalB - prefixB) >= 2) {
                        int leftStatus = getParityStatus(prefixA, prefixB);
                        bestDiff[leftStatus] = min(bestDiff[leftStatus], prefixA - prefixB);

                        left++;
                        if (s[left] == a) prefixA++;
                        if (s[left] == b) prefixB++;
                    }

                    // Check if opposite parity of A (flip only the A bit) has been seen
                    int currentStatus = getParityStatus(totalA, totalB);
                    int neededStatus = currentStatus ^ 0b10; // flip A's parity bit

                    if (bestDiff[neededStatus] != INT_MAX) {
                        int currentDiff = (totalA - totalB) - bestDiff[neededStatus];
                        maxDiff = max(maxDiff, currentDiff);
                    }
                }
            }
        }

        return (maxDiff == INT_MIN ? -1 : maxDiff);
    }
};
