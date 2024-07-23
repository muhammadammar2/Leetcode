class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1 , -1};
       int leftIndex = leftMost(nums , target);
        if (leftIndex == -1) return { -1 , -1};
        int rightIndex = rightMost (nums , target);
        return {leftIndex , rightIndex};
    }
    int leftMost (vector <int>& nums , int target) {
        int left =0;
        int right = nums.size()-1;
        
        while (left <= right) {
            int mid = left + (right - left) /2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        if (left < nums.size() && nums[left] == target) return left;
        else return -1;
    }
    int rightMost (vector <int>& nums , int target) {
        int left = 0;
        int right = nums.size()-1;
        
        while (left <= right) {
            int mid = left + (right - left) /2;
            if (nums[mid] <= target) left = mid + 1;
            else right = mid -1;
        }
        if (right < nums.size() && right >= 0 && nums[right] == target) return right;
        else return -1;
    }
};