class Solution {
public:

    int bfs(vector<vector<int>>& grid,
            vector<vector<int>>& vis,
            int row, int col) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push({row,col});

        vis[row][col] = 1;

        int area = 1;

        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};

        while(!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<4;i++) {

                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   grid[nr][nc] == 1 &&
                   !vis[nr][nc]) {

                    vis[nr][nc] = 1;
                    area++;

                    q.push({nr,nc});
                }
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));

        int maxi = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {

                if(grid[i][j] == 1 && !vis[i][j]) {

                    int area = bfs(grid, vis, i, j);

                    maxi = max(maxi, area);
                }
            }
        }

        return maxi;
    }
};