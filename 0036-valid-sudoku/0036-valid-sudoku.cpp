class Solution {
  public: bool isValidSudoku(vector < vector < char >> & board) {
    unordered_map < char, int > mp;
    for (int i = 0; i < board.size(); i++) {
      mp.clear();
      for (int j = 0; j < board[i].size(); j++) {
        if (board[i][j] != '.') {
          if (mp.count(board[i][j])) {
            return false;
          } else {
            mp[board[i][j]]++;
          }
        }
      }
    }
    
    mp.clear();
    for (int i = 0; i < board[0].size(); i++) {
      mp.clear();
      for (int j = 0; j < board.size(); j++) {
        if (board[j][i] != '.') {
          if (mp.count(board[j][i])){
              // cout<<board[j][i]<<endl;
              return false;
          }
          else mp[board[j][i]]++;
        }
      }
    }
   
    mp.clear();
    for (int i = 0; i < board.size(); i += 3) {
      for (int j = 0; j < board[i].size(); j += 3) {
        mp.clear();
        for (int k = 0; k < 3; k++){
          for (int l = 0; l < 3; l++) {
            if (board[i + k][j + l] != '.') {
              if (mp.count(board[i + k][j + l])) {
                return false;
              } else mp[board[i + k][j + l]]++;
            }
          }
        }
      }
    }
    return true;
  }
};