/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarySearchPeak(MountainArray &mountainArr){
        int low = 1, high = mountainArr.length()-2;
        while(low<=high){
            int mid = low+(high-low)/2;
            int midVal = mountainArr.get(mid);
            int leftVal = mountainArr.get(mid - 1);
            int rightVal = mountainArr.get(mid + 1);

            if (leftVal < midVal && midVal > rightVal)
                return mid;

            if (midVal > leftVal)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
    int binarySearch(MountainArray &mountainArr, int target , int start, int end, bool reverse){
        int low = start;
        int high = end;
        while(low<=high){
            int mid = low+(high-low)/2;
            int midVal = mountainArr.get(mid);
            if (midVal == target)
                return mid;

            if ((reverse && midVal < target) || (!reverse && midVal > target)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return INT_MAX;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peakIndex = binarySearchPeak(mountainArr);
        int leftAns = binarySearch(mountainArr,target,0,peakIndex,false);
        int rightAns = binarySearch(mountainArr,target,peakIndex+1,mountainArr.length()-1, true);
        int ans = min(leftAns,rightAns);
        return ans ==  INT_MAX ? -1 : ans;
    }
};