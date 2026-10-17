class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col)
    {
        if (row < 0 || col < 0 ||
            row >= grid.size() || col >= grid[0].size() ||
            grid[row][col] != 1)
        {
            return 0;
        }

        // 標記已拜訪
        grid[row][col] = 0;

        // 自己這格面積先算 1
        int area = 1;

        // 加上上下左右相連陸地的面積
        area += dfs(grid, row + 1, col);
        area += dfs(grid, row - 1, col);
        area += dfs(grid, row, col + 1);
        area += dfs(grid, row, col - 1);

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == 1)
                {
                    int area = dfs(grid, row, col);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};