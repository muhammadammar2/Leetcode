class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int right = n * m - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2; 
            int midVal = matrix[mid / m][mid % m];
            if (midVal == target) return true;
            if (midVal < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};