class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int min_price = INT_MAX;
        int maxProfit = 0;
        
        for (int price : prices) {
            if (price < min_price){
                min_price = price;
            }
            else if (price - min_price > maxProfit) {
                maxProfit= price - min_price;
            }
        }
        return maxProfit;
    }
};