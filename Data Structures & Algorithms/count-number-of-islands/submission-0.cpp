class Solution {
public:

    void bfs(vector<vector<char>>& grid,
             vector<vector<int>>& vis,
             int row, int col) {

        vis[row][col] = 1;

        queue<pair<int,int>> q;
        q.push({row,col});

        int n = grid.size();
        int m = grid[0].size();

        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};

        while(!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++) {

                int newrow = row + drow[i];
                int newcol = col + dcol[i];

                if(newrow >= 0 &&
                   newrow < n &&
                   newcol >= 0 &&
                   newcol < m &&
                   grid[newrow][newcol] == '1' &&
                   !vis[newrow][newcol]) {

                    vis[newrow][newcol] = 1;
                    q.push({newrow,newcol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));

        int cnt = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {

                if(grid[i][j] == '1' && !vis[i][j]) {
                    cnt++;
                    bfs(grid, vis, i, j);
                }
            }
        }

        return cnt;
    }
};