class Solution {
public:
    vector<int> dx = {0, 1};
    vector<int> dy = {1, 0};
    bool isSafe(int m, int n, int x, int y){
        if(x>=0 && y>=0 && x<m && y<n){
            return true;
        }
        return false;
    }
    void utility(int m, int n, int x, int y, int &count){
        if(x==m-1 && y==n-1){
            count++;
        }

        for(int i=0;i<2;i++){
            if(isSafe(m,n,x+dx[i],y+dy[i])){
                utility(m,n,x+dx[i],y+dy[i],count) ;  
            }
        }
    }
    int uniquePaths(int m, int n) {
        int count = 0;
        utility(m,n,0,0, count);

        return count;
    }
};
