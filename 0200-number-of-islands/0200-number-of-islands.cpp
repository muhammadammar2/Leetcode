class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int numOfIslands = 0;
        
        function<void (int , int)> dfs = [&](int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') return;
            grid[i][j]= '0'; // why marking to 0? helps avoiding visiting the same island.
            dfs (i + 1 , j);
            dfs (i - 1 , j);
            dfs (i , j + 1);
            dfs (i , j - 1);
        };
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == '1') {
                    numOfIslands++;
                    dfs (i , j);
                } 
            }
        }
        return numOfIslands;
    }
};