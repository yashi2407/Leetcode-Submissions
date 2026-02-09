class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int bestSellingPrice = prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--){
            // we buy on ith day!
            profit = max(profit, bestSellingPrice - prices[i]);
            bestSellingPrice = max(bestSellingPrice, prices[i]);
        }
        return profit;
    }
};