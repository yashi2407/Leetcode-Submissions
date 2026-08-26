class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans(nums.size(),-1);
        stack<int>st;
        for(int i = 2*nums.size()-2;i>=0;i--){
            int actualIndex = i%nums.size();
            while(!st.empty() && st.top()<=nums[actualIndex]){
                st.pop();
            }
            if(!st.empty()){
                ans[actualIndex] = st.top();
            }
            st.push(nums[actualIndex]);
        }
        return ans;
    }
};