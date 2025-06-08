class Solution {
public:
    string convert(string s, int numRows) {
        map<int,vector<char>> mp;
        if (numRows == 1) return s;
        bool isIncreasing = true;
        int currentIndex = 0;
        for(int i = 0;i<s.size();i++){
            mp[currentIndex].push_back(s[i]);
            if(isIncreasing){
                currentIndex++;
                if(currentIndex==numRows){
                    currentIndex = currentIndex-2;
                    isIncreasing=false;
                }
            }
            else if(!isIncreasing){
                currentIndex--;
                if(currentIndex ==-1){
                    currentIndex = currentIndex+2;
                    isIncreasing=true;
                }

            }
        }
        string ans;
        for(auto it : mp){
            for(int i=0;i<it.second.size();i++){
                ans+=it.second[i];
            }
        }
        return ans;
    }
};