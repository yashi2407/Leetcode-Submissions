class FreqStack {
public:
    unordered_map<int, int> mp;
    unordered_map<int, stack<int>> group;// frequency and the last element entered with that frequnecy
    int maxFrequency = INT_MIN;
    FreqStack() {
    }
    void push(int val) {
        mp[val]++;
        if(mp[val]>maxFrequency){
            maxFrequency = mp[val];
        }
        group[mp[val]].push(val);
    }
    
    int pop() {
        int ans = group[maxFrequency].top();
        mp[ans]--;
        group[maxFrequency].pop();
        if (group[maxFrequency].empty()) {
            maxFrequency--;
        }
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */