class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // let's assume nums1 is alaway smaller!!
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int low = 0;
        int high = nums1.size();
        int n = nums1.size() + nums2.size();
        int half = (n +1 )/2;
        while(low<=high){
            int mid1 = (high -low)/2 + low; // how many from num1
            int mid2 = half - mid1; // how many from num2;

            int l1 = mid1 > 0 ? nums1[mid1 - 1] : INT_MIN;
            int l2 = mid2 > 0 ? nums2[mid2 - 1] : INT_MIN;

            int r1 = mid1 < nums1.size() ? nums1[mid1] : INT_MAX;
            int r2 = mid2 < nums2.size() ? nums2[mid2] : INT_MAX;

            if(l1 <= r2 && l2 <= r1){
                // perfect match!!
                if(n%2 != 0){
                    return max(l1,l2);
                }
                else {
                    return (max(l1, l2) + min(r1, r2)) / 2.0; 
                }
            }
            if(l1>r2){
                high = mid1-1;
            }
            else {
                low = mid1+1;
            }
        }
        return -1;
    }
};