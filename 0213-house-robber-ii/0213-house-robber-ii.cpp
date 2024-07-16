class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        return max(robMax(nums , 0 ,n - 2) , robMax(nums ,  1 , n-1));
    }
public: 
    int robMax (vector<int>& nums , int start, int end) {
        if (start == end) return nums[start];
        vector <int> dp (end - start + 1);
        dp[0] = nums[start];
        dp[1] = max (nums[start], nums[start + 1]);
        
        for (int i =2; i <= end - start; ++i) {
        dp[i] = max (dp[i - 1] , nums[start + i] + dp[i - 2]);
        }
        return dp.back();
    }
};