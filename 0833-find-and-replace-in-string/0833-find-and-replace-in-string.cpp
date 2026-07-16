class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        // sort the indices and corresponding sources and target
        vector<tuple<int,string,string>> vec;
        for(int i=0;i<indices.size();i++){
            vec.push_back({indices[i],sources[i],targets[i]});
        }
        sort(vec.begin(),vec.end(),[](const tuple<int,string,string> &a, const tuple<int,string,string>&b){
            return get<0>(a) < get<0>(b);
        });

        int offset = 0;
        string modified = s;
        for(int i=0;i<vec.size();i++){
            auto [index,source,target] = vec[i];
            int newIndex = index + offset;
            string found = s.substr(index, source.size());
            if(found == source){
                modified.erase(newIndex,source.size());
                modified.insert(newIndex,target);
                offset += target.size() - source.size();
            }
        }
        return modified;
    }
};