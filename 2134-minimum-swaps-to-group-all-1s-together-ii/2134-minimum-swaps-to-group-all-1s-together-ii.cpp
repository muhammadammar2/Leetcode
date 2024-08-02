class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int tt1 = accumulate(nums.begin() , nums.end() , 0);
        int n = nums.size();
        
        int curr1 = accumulate(nums.begin() , nums.begin() + tt1 , 0);
        int maxW = curr1;
        
        for(int i = tt1; i<n+tt1; ++i) {
            curr1 += nums[i % n] - nums[(i - tt1 + n) % n];
            maxW = max(maxW, curr1);
        }
         return tt1 - maxW;
    }
};