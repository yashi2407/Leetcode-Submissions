class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<array<double,3>>pq;

        for(int i = 0;i<classes.size();i++){
            double difference = ((double)(classes[i][0]+1)/(classes[i][1]+1)) - ((double)classes[i][0]/classes[i][1]);
            pq.push({difference,(double)classes[i][0],(double)classes[i][1]});
        }
        while(extraStudents != 0){
            auto [ratio, pass, total] = pq.top();
            pq.pop();
            // assign and push back!
            pass+=1;
            total+=1;
            double difference = ((double)(pass+1)/(total+1)) - ((double)pass/total);
            pq.push({difference,pass,total});
            extraStudents -=1;
        }
        double ans = 0;
        while(!pq.empty()){
            auto [ratio, pass, total] = pq.top();
            pq.pop();
            ans += (double)pass / total;
        }
        ans = ans/classes.size();
        return ans;
    }
};