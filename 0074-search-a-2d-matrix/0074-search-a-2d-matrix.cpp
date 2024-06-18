//matrix = row
//matrix[0] = col
//assume it as a 1D array or a sorted list
//find mid
//find midVal (matrix)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m*n -1;
        
        while(left <= right) {
            int mid = left + (right - left) /2;
            int midVal = matrix [mid / n] [mid % n];
            if (midVal == target) return true;
            else if (midVal < target) {
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        return false;
    }
};