class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxSellingPrice = prices[prices.size()-1];
        int maxProfit = 0;
        for(int i = prices.size()-2;i>=0;i--){
            maxProfit = max(maxProfit, maxSellingPrice - prices[i]);
            maxSellingPrice = max(maxSellingPrice,prices[i]);
        }
        return maxProfit;
    }
};