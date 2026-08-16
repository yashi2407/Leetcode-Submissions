class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()){
            return "";
        }
        const auto & possibleValues = mp[key]; 
        // 2. Binary search since data is already sorted by timestamp
        int low = 0, high = possibleValues.size() - 1;
        string ans = "";
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possibleValues[mid].second <= timestamp) {
                ans = possibleValues[mid].first; // Found a valid option, look for a closer one
                low = mid + 1;
            } else {
                high = mid - 1;
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