class TimeMap {
public:
    // key -> value,timestamp
    unordered_map<string,vector<pair<string,int>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        string ans = "";
        int timestamp_prev = -1;
        auto& binarySearch = mp[key];
        int low = 0;
        int high = binarySearch.size()-1;
        while(low<=high){
            int mid = (low + high)/2;
            // this is highest possible
            if(binarySearch[mid].second == timestamp){
                return binarySearch[mid].first;
            }
            // the currenttimestamp is bigger than given
            else if(binarySearch[mid].second > timestamp){
                high = mid-1;
            }
            else {
                ans = binarySearch[mid].first;
                low = mid+1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */