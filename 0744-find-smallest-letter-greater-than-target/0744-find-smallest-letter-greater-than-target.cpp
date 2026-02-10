class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        if(target >= letters[n-1]){
            return letters[0];
        }
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (high - low)/2 + low;
            if(letters[mid] <= target){
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return letters[low];
    }
};