class Solution {
    vector<int> segmentTree;
public:
    void buildSegmentTree(vector<int>& heights, int n){
        segmentTree.resize(4*n);
        buildSegmentTreeUtil(heights,0,n-1,0);
    }
    void buildSegmentTreeUtil(vector<int>& heights, int l,int r, int index){
        if(l==r){
            segmentTree[index] = l;
            return;
        }
        int mid = l +(r-l)/2;
        buildSegmentTreeUtil(heights, l,mid,2*index+1);
        buildSegmentTreeUtil(heights, mid+1,r,2*index+2);

        int leftIndex = segmentTree[2*index+1];
        int rightIndex = segmentTree[2*index+2];
        if(heights[leftIndex]>=heights[rightIndex]){
            segmentTree[index] = leftIndex;
        }
        else{
            segmentTree[index] = rightIndex;
        }
    }
    int RMIQ(int a, int b,vector<int>& heights, int n){
        return RMIQutil(a,b,heights,0,0,n-1);
    }

    int RMIQutil(int start, int end,vector<int>& heights, int index, int left, int right){
        if (left > end || right < start) return -1;
        if (left >= start && right <= end) return segmentTree[index];
        int mid = left + (right - left)/2;
        int leftQuery = RMIQutil(start, end, heights, 2*index+1, left, mid);
        int rightQuery = RMIQutil(start, end, heights, 2*index+2, mid+1, right);
        if(leftQuery == -1){
            return rightQuery;
        }
        if(rightQuery == -1){
            return leftQuery;
        }
        return heights[leftQuery]>=heights[rightQuery] ? leftQuery : rightQuery;

    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        buildSegmentTree(heights,n);
        vector<int> ans;
        for(auto q : queries){
            int alice = min(q[0],q[1]);
            int bob = max(q[0],q[1]);
            // if they are already on the same
            if(alice == bob){
                ans.push_back(alice);
                continue;
            }
            else if(heights[alice]<heights[bob]){
                ans.push_back(bob);
                continue;
            }
            else {
                int l = bob+1;
                int r = n-1;
                int result_index = INT_MAX;
                while(l<=r){
                    int mid = l+(r-l)/2;
                    int index = RMIQ(l,mid,heights,n);
                    if(heights[index] > max(heights[alice], heights[bob])){
                        result_index=min(result_index,index);
                        r=mid-1;
                    }
                    else{
                        l=mid+1;
                    }
                }
                if(result_index == INT_MAX){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(result_index);
                }
            }
        }
        return ans;
    }
};