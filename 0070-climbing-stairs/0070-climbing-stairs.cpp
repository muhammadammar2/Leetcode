class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0 && n == 1) return 1;
        int one = 1;
        int two = 1;
        for (int i = 0; i<n - 1; ++i) {
           int temp = one;
            one = one + two;
            two = temp;
        }
        return one;
    }
};