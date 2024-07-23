class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = nums[0];
        int left = 0;
        int right = nums.size()-1;
        
        while (left <= right) {
            int mid = left + (right - left) /2;
            res = min (res , nums[mid]);
            
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left ++;
                right --;
            }
            else if (nums[left] <= nums[mid]) {
                res = min (res , nums[left]);
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};