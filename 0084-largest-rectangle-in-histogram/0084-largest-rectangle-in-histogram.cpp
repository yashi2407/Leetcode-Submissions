class Solution {
public:
    void setNsr(vector<int>& heights,vector<int>&nsr){
        stack<pair<int,int>>st;
        for(int i= heights.size()-1;i>=0;i--){
            if(st.size()==0){
                nsr[i]=heights.size();
            }
            else if(st.top().first<heights[i]){
                nsr[i]=st.top().second;
            }
            else {
                while(!st.empty() && st.top().first>=heights[i]){
                    st.pop();
                }
                if(st.size()==0){
                    nsr[i]=heights.size();
                }
                else{
                    nsr[i]=st.top().second;
                }
            }
            st.push({heights[i],i});
        }
    }
    void setNsl(vector<int>& heights,vector<int>&nsl){
        stack<pair<int,int>>st;
        for(int i=0;i<heights.size();i++){
            if(st.size()==0){
                nsl[i]=-1;
            }
            else if(st.top().first<heights[i]){
                nsl[i]=st.top().second;
            }
            else {
                while(!st.empty() && st.top().first>=heights[i]){
                    st.pop();
                }
                if(st.size()==0){
                    nsl[i]=-1;
                }
                else{
                    nsl[i]=st.top().second;
                }
            }
            st.push({heights[i],i});
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nsl(heights.size(),-1);
        setNsl(heights,nsl);
        vector<int>nsr(heights.size(),-1);
        setNsr(heights,nsr);
        int ans = INT_MIN;
        for(int i =0;i<heights.size();i++){
            ans=max(ans,(nsr[i]-nsl[i]-1)*heights[i]);
        }
        return ans;
    }
};