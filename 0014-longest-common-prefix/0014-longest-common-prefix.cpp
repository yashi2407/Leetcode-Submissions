class Solution {
public:
    string findCommon(string s1, string s2){
        string ans = "";
        for(int i=0;i<min(s1.size(),s2.size());i++){
            if(s1[i] == s2[i]){
                ans+= s1[i];
            }
            else{
                break;
            }
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1){
            return strs[0];
        }
        // get for the first two
        string commonPrefix = findCommon(strs[0],strs[1]);
        if(commonPrefix == ""){
            return "";
        }
        for(int i = 1;i<strs.size()-1;i++){
            string s1 = strs[i];
            string s2 = strs[i+1];
            string currentCommon = findCommon(s1,s2);
            if(currentCommon == ""){
                return "";
            }
            commonPrefix = findCommon(currentCommon,commonPrefix);
        }
        return commonPrefix;
    }
};