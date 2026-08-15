class Solution {
public:
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, 1, -1, 0};

    bool isValid(int x,int y,int n,int m){
        if(x<0 || y<0 || x>=n || y>=m){
            return false;
        }

        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                }
            }
        }

        int count = -1;
        while(!q.empty()){
            int l = q.size();
            while(l>0){
                pair<int, int> temp = q.front();
                q.pop();

                for(int i=0; i<4; i++){
                    for(int j=0; j<4; j++){
                        if(isValid(temp.first+dx[i], temp.second+dy[i], n, m) && grid[temp.first+dx[i]][temp.second+dy[i]]==1){
                            q.push({temp.first+dx[i], temp.second+dy[i]});
                            grid[temp.first+dx[i]][temp.second+dy[i]] = 2;
                        }
                    }
                }
                l--;
            }
            count++;
        }

        

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        if(count<=0){
            return 0;
        }
        
        return count;
    }
};
