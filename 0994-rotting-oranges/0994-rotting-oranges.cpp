class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> rotten;
        int freshOranges = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    freshOranges++;
                } else if (grid[i][j] == 2) {
                    rotten.push({i, j});
                }
            }
        }
        
        vector<pair<int, int>> directions = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };
        
        int minutes = 0;
        
        //bfs
        while (!rotten.empty() && freshOranges > 0) {
            int size = rotten.size();
            for (int i = 0; i < size; ++i) {
                auto [x, y] = rotten.front();
                rotten.pop();
                
                //chekk all 4 direcional neighbors
                for (auto dir : directions) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;
                    
                    // rot the neighbor's fresh oranges
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;
                        freshOranges--;
                        rotten.push({newX, newY});
                    }
                }
            }
            minutes++;
        }
        
        return freshOranges == 0 ? minutes : -1;
    }
};
