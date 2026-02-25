class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr2.size();i++){
            mp[arr2[i]] = i;
        }

        sort(arr1.begin(),arr1.end(), [&mp](int a, int b){
            auto it1 = mp.find(a);
            auto it2 = mp.find(b);
            if(it1 != mp.end() && it2!=mp.end()){
                return it1->second<it2->second;
            }
            else if(mp.find(a) != mp.end()){
                return true;
            }
            else if(mp.find(b) != mp.end()){
                return false;
            }
            return a<b;
        });

        // sort(arr1.begin(),arr1.end(),[&arr2](int a , int b){
        //     auto it1 = find(arr2.begin(), arr2.end(), a);
        //     auto it2 = find(arr2.begin(), arr2.end(), b);
        //     // found both 1 and 2
        //     if (it1 != arr2.end() && it2 != arr2.end()){
        //         // a should appear before b if it1 < it2
        //         return (it1 - arr2.begin()) < (it2 - arr2.begin());
        //     }
        //     // found a
        //     else if(it1 != arr2.end()){
        //         return true;
        //     }
        //     else if(it2 != arr2.end()){
        //         return false;
        //     }
        //     return a<b;
            
        // });

        return arr1;
    }
};