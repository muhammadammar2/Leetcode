class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;
        
        function <int (int , int)> dfs = [&](int i , int j) {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return 0;
            grid[i][j] = 0;
            int area = 1;
            area += dfs (i + 1 , j);
            area += dfs (i - 1 , j);
            area += dfs (i , j + 1);
            area += dfs (i , j - 1);
            
            return area;
        };
        
        for (int i =0; i<m ; ++i) {
            for (int j =0; j<n; ++j) {
                if (grid[i][j] == 1){
                    maxArea = max (maxArea , dfs (i , j)); 
                }
            }
        }
        return maxArea;
    }
};