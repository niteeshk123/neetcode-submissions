class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row(n, -1);
        bool col = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    if(matrix[i][j]==0){
                        col=1;
                    }
                }
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    row[j] = 0;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || row[j]==0){
                    matrix[i][j] = 0;
                }
            }
        }
       
        if(col)
        for(int i=0;i<m;i++){
            matrix[i][0]=0;
        }
    }
};
