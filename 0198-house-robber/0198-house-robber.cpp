class Solution {
public:
    int rob(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return 0;
//         if (n == 1) return nums[0];
        
//         vector <int> dp(n);
//         dp[0] = nums[0];
//         dp[1] = max (dp[0] , nums[1]);
        
//         for (int i = 2; i<n; ++i) {
//             dp[i] = max(dp[i-1] , nums[i] + dp[i - 2]);
//         }
//         return dp[n-1];
        
       int n = nums.size();
       vector <int> memo (n , -1);

        return hF (n - 1, nums , memo) ;
    }
private:
    int hF (int i , vector <int>& nums , vector <int>& memo) {
        if (i < 0) return 0;
        if (i == 0) return nums[0];
        if (i == 1) return max (nums[0] , nums[1]);
        
        if (memo[i] != -1) return memo[i];
        memo[i] = max (nums[i] + hF (i -2 , nums , memo) , hF(i -1 , nums , memo));
        return memo[i];
    }
};