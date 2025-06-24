class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(),-1);
        stack<int>s;
        int n = nums.size();
        for(int i = (2*n)-1;i>=0;i--){
            if(!s.empty()){
                while(!s.empty()&& s.top()<=nums[i%n]){
                    s.pop();
                }
                if(!s.empty()){
                    ans[i%n]=s.top();
                }
            }
            s.push(nums[i%n]);
        }
        return ans;
    }
};