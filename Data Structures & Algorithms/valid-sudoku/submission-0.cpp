class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<int> row[9];
        set<int> col[9];
        set<int> submat[9];

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int val = board[i][j]-'0';
                if(board[i][j]=='.'){
                    continue;
                }

                if(row[i].find(val)!=row[i].end()){
                    return false;
                }

                row[i].insert(val);

                if(col[j].find(val)!=col[j].end()){
                    return false;
                }
                col[j].insert(val);

                int idx = ((i/3)*3)+(j/3);
                if(submat[idx].find(val)!=submat[idx].end()){
                    return false;
                }
                submat[idx].insert(val);
            }
        }
        return true;
    }
};
