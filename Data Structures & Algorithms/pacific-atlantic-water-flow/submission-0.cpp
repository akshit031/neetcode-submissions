class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        queue<pair<int, int>> pq;
        queue<pair<int, int>> aq;

        for (int i = 0; i < m; i++) {
            pq.push({i, 0});
            pacific[i][0] = true;
            
            aq.push({i, n - 1});
            atlantic[i][n - 1] = true;
        }
        for (int j = 0; j < n; j++) {
            pq.push({0, j});
            pacific[0][j] = true;
            
            aq.push({m - 1, j});
            atlantic[m - 1][j] = true;
        }
        auto bfs = [&](queue<pair<int, int>>& q, vector<vector<bool>>& v){
            int x[] = {0, -1, 1, 0};
            int y[] = {-1, 0, 0, 1};
            while(!q.empty()){
                auto [r,c] = q.front();
                q.pop();

                for(int i=0;i<4;i++){
                    int dx = r + x[i], dy = c + y[i];
                    if(dx>=0 && dy>=0 && dx<m && dy<n && !v[dx][dy]){
                        if(heights[dx][dy] >= heights[r][c]){
                            v[dx][dy] = 1;
                            q.push({dx, dy});
                        }
                    }
                }
            }
        };
        bfs(pq, pacific);
        bfs(aq, atlantic);

        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] == atlantic[i][j] && pacific[i][j] == 1){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
