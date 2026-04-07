class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double,int>>wageByQuality(quality.size());
        for(int i=0;i<n;i++){
            double temp = (double) wage[i]/quality[i];
            wageByQuality[i] = {temp,quality[i]};
        }
        sort(wageByQuality.begin(),wageByQuality.end());
        int currentQuality = 0;
        priority_queue<int> h;
        double ans = DBL_MAX;
        for(int i = 0;i<n;i++){
            double ratio = wageByQuality[i].first;
            double quality = wageByQuality[i].second;
            currentQuality += quality;
            h.push(quality);
            if(h.size()>k){
               currentQuality -= h.top();   
                h.pop();
            }
            if(h.size() == k){
                ans = min(ans,currentQuality*ratio);
            }
        }
        return ans;
    }
};