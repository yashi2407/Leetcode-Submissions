class NumArray {
public:
    int n;
    vector<int> segTree;
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4*n);
        buildSegTree(nums,0,n-1,0);
    }

    void buildSegTree(vector<int>& nums, int left, int right, int index){
        if(left == right){
            segTree[index]= nums[left];
            return;
        }
        // call left and right
        int mid = left + (right - left)/2;
        buildSegTree(nums,left,mid,2*index+1);
        buildSegTree(nums,mid+1,right,2*index+2);
        segTree[index] = segTree[2*index+1] + segTree[2*index+2];
    }

    void update(int index, int val) {
        updateSegtree(index,val,0,n-1,0);
    }

    void updateSegtree(int index, int val, int left, int right, int segIndex){
        if(left == right){
            segTree[segIndex] = val;
            return;
        }
        int mid = left + (right - left)/2;
        if(index<=mid){
            // goto left
            updateSegtree(index,val,left,mid,2*segIndex+1);
        }
        else{
            updateSegtree(index,val,mid+1,right,2*segIndex+2);
        }
        segTree[segIndex]= segTree[2*segIndex+1] + segTree[2*segIndex+2];

    }
    
    int sumRange(int left, int right) {
        return querySegTree(left,right,0,n-1,0);
    }
    int querySegTree(int left, int right, int l, int r, int index){
        // within range
        if(left<=l && r<=right){
            return segTree[index];
        }

        // out the range
        if(l>right || r<left){
            return 0;
        }

       
        // goto left and right
        int mid = l + (r - l) / 2;
        return querySegTree(left,right,l,mid,2*index+1) + querySegTree(left,right,mid+1,r,2*index+2);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */