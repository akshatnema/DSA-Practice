class Solution {
public:
    bool check(vector<vector<char>>& board, int row, int col, char val) {
        for(int i=0;i<board.size();i++) {
            if(board[i][col]==val) return false;
        }
        
        for(int i=0;i<board[0].size();i++) {
            if(board[row][i]==val) return false;
        }
        
        for(int i=0;i<board.size();i++) {
            int r= 3*(row/3)+i/3;
            int c= 3*(col/3)+i%3;
            if(board[r][c]==val) return false;
        }
        return true;
    }
    
    bool rec(vector<vector<char>>& board) {
        int flag=0;
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='.') {
                    for(int k=1;k<=9;k++) {
                        if(check(board, i, j, (char)(k+48) )){
                            board[i][j]=(char)(k+48);
                            bool res= rec(board);
                            if(res) return true;
                            else board[i][j]='.';
                            flag=1;
                        }
                    }
                    return false;
                }
            }
        }
      return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        rec(board);
    }
};