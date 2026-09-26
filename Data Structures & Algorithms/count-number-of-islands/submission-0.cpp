class Solution {
public:
    vector<int> x = {-1, 0, 1, 0};
    vector<int> y = {0, -1, 0, 1};
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis){
        vis[i][j] = 1;
        int n = grid.size(), m = grid[0].size();
        for(int k=0;k<4;k++){
            int dx = i + x[k], dy = j + y[k];
            if(dx>=0 && dx<n && dy>=0 && dy<m && !vis[dx][dy] && grid[dx][dy] == '1'){
                dfs(dx, dy, grid, vis);
            }
        }return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    cnt++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};
