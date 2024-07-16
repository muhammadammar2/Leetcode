class Solution {
public:
    int climbStairs(int n) {
        vector <int> memo (n + 1 , - 1);
        return hF(n , memo);
    }
private:
    int hF(int n , vector <int>& memo){
        if (n ==0) return 1;
        if (n ==1) return 1;
        
        if (memo[n] != -1) return memo[n];
        memo[n] = hF(n -1 , memo) + hF (n -2 , memo);
        return memo[n];
    }
};