class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector <int> dp(amount + 1 , amount + 1); //1 for setting the size of the arr , 2nd for the amount has to be in between amount + 1 , both are infinity
            dp[0] = 0;
        for (int i =1; i<=amount; ++i) {
            for (int coin : coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i] , dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};