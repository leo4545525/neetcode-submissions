class Solution {
public:
    int bfs(vector<vector<int>>& grid, int row, int col)
    {
        vector<vector<int>> dir= {{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int, int>> q;
        grid[row][col] = 0;
        q.push({row, col});
        int area = 1;

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0 ; i < 4 ; i++)
            {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1]; 
                if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == 1)
                {
                    grid[nr][nc] = 0;
                    q.push({nr, nc});
                    area++;
                }
            }
            
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int numOfIsland = 0;
        vector<int> areaOfIsland = {0};
        for(int r = 0 ; r < grid.size(); r++)
        {
            for(int c = 0 ; c < grid[0].size(); c++)
            {
                if(grid[r][c] == 1)
                {
                    areaOfIsland.push_back(bfs(grid, r ,c));
                    numOfIsland++;
                }
            }
        }
        return *max_element(areaOfIsland.begin(), areaOfIsland.end());
    }
};

 