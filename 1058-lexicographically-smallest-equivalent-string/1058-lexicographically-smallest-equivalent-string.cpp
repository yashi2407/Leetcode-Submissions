class Solution {
public:
    unordered_map<char, char> parent;
    char findParent(char child){
        if(parent[child]==child){
            return child;
        }
        return parent[child]=findParent(parent[child]);
    }
    void join(char a, char b){
        char parentA = findParent(a);
        char parentB = findParent(b);
        if (parentA == parentB) return;
        char smaller = min(parentA,parentB);
        char larger = max(parentA,parentB);
        parent[larger]=smaller;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
        for(char ch ='a';ch<='z';ch++){
            parent[ch]=ch;
        }
        for(int i=0;i<n;i++){
            join(s1[i],s2[i]);
        }
        string res;
        for(int i =0;i<baseStr.size();i++){
            res+=findParent(baseStr[i]);
        }
        return res;
    }
};