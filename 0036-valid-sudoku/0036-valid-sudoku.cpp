class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector <unordered_set <int>> rows(9);
        vector <unordered_set <int>> cols(9);
        vector <unordered_set <int>> boxes(9);
        
        for (int i =0; i<9; ++i) {
            for (int j =0; j<9; ++j) {
                int nums = board[i][j];
                if (nums == '.') continue;
                
                int boxIndex = (i/3)*3+(j/3);
                
                if (rows[i].count(nums) || cols[j].count(nums) || boxes[boxIndex].count(nums)) return false;
                
                rows[i].insert(nums);
                cols[j].insert(nums);
                boxes[boxIndex].insert(nums);
            }
        }
        return true;
    }
};