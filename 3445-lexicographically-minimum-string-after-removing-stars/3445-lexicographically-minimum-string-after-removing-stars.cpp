class Solution {
public:
    string clearStars(string s) {
        priority_queue<char, vector<char>,greater<char>> pq; // to get the smallest element
        map<char,vector<int>>mp; // to store the last index of smallest element
        string res = "";
        vector<bool> v(s.size(), true); // to check if a charatcer has to be included in result or not
        for(int i =0;i<s.size();i++){
            if(s[i]!='*'){
                // pushing in heap
                pq.push(s[i]);
                mp[s[i]].push_back(i);
            } 
            else {
                char smallest = pq.top();
                pq.pop();
                v[mp[smallest].back()] = false;
                mp[smallest].pop_back();
                v[i]=false;

            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (v[i]) res += s[i];
        }
        return res;
    }
};