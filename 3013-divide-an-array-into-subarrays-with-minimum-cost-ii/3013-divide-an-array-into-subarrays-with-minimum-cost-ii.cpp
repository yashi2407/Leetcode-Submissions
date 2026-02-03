class Solution {
public:
    typedef pair<long long,long long> p;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        set<p> currentList; // stores k-1 min elements
        set<p> deletedList; // remaining deleted elelemtns
        long long sum = 0;
        long long result = LONG_MAX;
        int i=1,j=1;
        while(j<n) {
            // do the calculations for j
            currentList.insert({nums[j],j});
            sum += nums[j];
            if(currentList.size()>k-1){
                p temp = *currentList.rbegin();// biggest element
                sum -= temp.first;
                deletedList.insert(temp);
                currentList.erase(temp);
            }

            // we hit the window size!
            if(j-i + 1 == dist+1){
                result = min(result,sum);
                // remove calculations for i
                p remove = {nums[i],i};
                if(currentList.count(remove)){
                    currentList.erase(remove);
                    sum-=remove.first;

                    if(!deletedList.empty()){
                        p temp = *deletedList.begin();
                        currentList.insert(temp);
                        sum+= temp.first;
                        deletedList.erase(temp);
                    }
                }
                // if it was present in deleted list, we remove from there
                else {
                    deletedList.erase(remove);
                }
                i++;
            }            
            j++;

        }
        return nums[0]+ result;
    }
};