//dfs
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col)
    {
        // 越界或非島嶼就返回
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] != '1')
            return;

        grid[row][col] = '0';  // 標記為已訪問

        // 四個方向遞迴呼叫
        dfs(grid, row + 1, col); // 下
        dfs(grid, row - 1, col); // 上
        dfs(grid, row, col + 1); // 右
        dfs(grid, row, col - 1); // 左
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        int res = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == '1') {
                    dfs(grid, r, c);
                    res++;
                }
            }
        }
        return res;
    }
};
