class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestSellingPrice = prices[prices.size()-1];
        int profit = 0;
        for(int i=prices.size()-2;i>=0;i--){
            bestSellingPrice = max(bestSellingPrice, prices[i]);
            profit = max(profit, bestSellingPrice-prices[i]);
        }
        return profit;
    }
};