class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;
        string temp1 = "0";
        string temp2 = "0";
        while(i<=version1.size() || j<=version2.size()){
            while(i<version1.size() && version1[i]!= '.'){
                temp1+=version1[i];
                i++;
            }
            while(j<version2.size() && version2[j]!= '.'){
                temp2+=version2[j];
                j++;
            }
            int num1 = stoi(temp1);
            int num2 = stoi(temp2);
            // cout<<"num1 is"<<num1<<endl;
            // cout<<"num2 is"<<num2<<endl;
            if(num1>num2){
                return 1;
            }
            if(num1<num2){
                return -1;
            }
            temp1 = "0";
            temp2 = "0";
            i++;
            j++;
        }
        return 0;
    }
};