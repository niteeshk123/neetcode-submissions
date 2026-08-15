class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    bool isSafe(int x, int y, int n, int m){
        if(x>=n || x<0 || y>=m || y<0){
            return false;
        }
        return true;
    }

    void bfs(vector<vector<char>>& grid, int x, int y, int n, int m){
        queue<pair<int,int>> q;
        q.push({x,y});
        while(!q.empty()){
            pair<int, int> temp = q.front();
            q.pop();
            // printf("x=%d y=%d\n",temp.first, temp.second);
            for(int i=0;i<4;i++){
                int x1 = temp.first+dx[i];
                int y1 = temp.second+dy[i];
                if(isSafe(x1, y1, n, m) && grid[x1][y1]=='1'){
                    q.push({x1, y1});
                } 
            }
            grid[temp.first][temp.second]='0';
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    // printf("*********************\n");
                    bfs(grid, i, j, n, m);
                    count++;
                }
            }
        }

        return count;

    }
};
