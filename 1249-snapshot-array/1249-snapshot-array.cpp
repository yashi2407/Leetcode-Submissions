class SnapshotArray {
public:
    vector<vector<pair<int,int>>>arr;
    int snapId = 0;
    SnapshotArray(int length) {
        arr.resize(length);
    }
    
    void set(int index, int val) {
        if (!arr[index].empty() && arr[index].back().first == snapId) {
            arr[index].back().second = val; // update latest change in same snap
        } else {
            arr[index].push_back({snapId,val});
        }
    }
    
    int snap() {
        snapId++;
        return snapId-1;
    }
    
    int get(int index, int snap_id) {
        auto &row = arr[index];
        int ans = 0;
        for (int i = 0; i < row.size(); i++) {
            if (row[i].first <= snap_id) {
                ans = row[i].second; // update to most recent valid value
            } else {
                break;
            }
        }
        return ans;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */