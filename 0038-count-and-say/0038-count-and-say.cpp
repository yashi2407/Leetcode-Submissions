class Solution {
public:
    string RLE(string n){
        int i=0;
        string ans = "";
        while(i<n.size()){
            int count = 1;
            while(i+1<n.size() && n[i] == n[i+1]){
                i++;
                count++;
            }
            ans+=to_string(count);
            ans+=n[i];
            i++;
            count=1;
        }
        return ans;
    }
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        return RLE(countAndSay(n-1));
    }
};