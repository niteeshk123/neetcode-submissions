class Solution {
public:
    vector<int> dx={1, -1, 0, 0};
    vector<int> dy={0, 0, 1, -1};

    bool isSafe(int x, int y, int n, int m){
        if(x<n && y<m && x>=0 && y>=0){
            return true;
        }
        return false;

    }

    bool utility(vector<vector<char>> &board, string word, int i, int x, int y){
        if(i>=word.size()){
            return false;
        }
        if(board[x][y]!=word[i]){
            return false;
        }
        if(i==word.size()-1){
            return true;
        }
        int n = board.size();
        int m = board[0].size();
        board[x][y]='*';
        for(int j=0;j<4;j++){
            if(isSafe(x+dx[j],y+dy[j],n,m)){
                if(utility(board, word, i+1, x+dx[j], y+dy[j])){
                    board[x][y]=word[i];
                    return true;
                }
            }
        }
        board[x][y]=word[i];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(utility(board, word, 0, i, j)){
                    return true;
                }
            }
        }
        return false;
    }
};
