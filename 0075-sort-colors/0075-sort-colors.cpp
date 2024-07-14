class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        bool swapped;
        for (int i =0; i<n -1; i++) {
            swapped = false;
            for (int j =0; j<n - i -1; j++) {
                if (nums[j] > nums[j +1]) {
                    swap (nums[j] , nums[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }
};