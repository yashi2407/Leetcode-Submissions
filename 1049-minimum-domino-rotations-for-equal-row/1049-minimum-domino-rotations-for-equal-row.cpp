class Solution {
public:
    int check(int target, vector<int>& tops, vector<int>& bottoms) {
        int rotTop = 0, rotBottom = 0;
        for (int i = 0; i < tops.size(); ++i) {
            if (tops[i] != target && bottoms[i] != target) {
                return -1;
            } else if (tops[i] != target) {
                rotTop++;
            } else if (bottoms[i] != target) {
                rotBottom++;
            }
        }
        return min(rotTop, rotBottom);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int rotations = check(tops[0], tops, bottoms);
        if (rotations != -1) return rotations;
        // If tops[0] and bottoms[0] are the same, don’t check twice
        if (tops[0] != bottoms[0])
            return check(bottoms[0], tops, bottoms);
        return -1;
    }
};
