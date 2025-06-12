class Solution {
public:
int binarySearch(vector<int>&temp, int target){
        int low = 0, high = temp.size() - 1;
        int result = temp.size(); // default to end if not found
        
        while(low <= high){
            int mid = (low + high) / 2;
            if(temp[mid] >= target){ 
                result = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return result;
    }
    vector<int> countSmaller(vector<int>& nums) {
       vector<int>ans;
       vector<int>temp;
       temp.push_back(nums[nums.size() - 1]); // sorted array to use binary search
        ans.push_back(0);
        for(int i=nums.size()-2;i>=0;i--){
            int index=binarySearch(temp,nums[i]);
            ans.push_back(index);
            temp.insert(temp.begin() + index, nums[i]);
        }
        reverse(ans.begin(),ans.end());
       return ans;
    }
};