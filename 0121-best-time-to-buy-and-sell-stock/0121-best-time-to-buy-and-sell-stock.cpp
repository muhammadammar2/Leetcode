class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_price = 0;
        
        for (int price : prices){
            if(price < min_price) {
                min_price = price;
            }
            else if (price - min_price > max_price ) {
                max_price = price-min_price;
                
}
        }
        return max_price;
    }
};