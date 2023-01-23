class Solution {
public:
    bool ans=false;
    int x[4]={1, -1, 0, 0};
    int y[4]={0, 0, 1, -1};
    bool check(int i, int j, int n, int m){
        return (i>=0 && i<n &&j>=0 && j<m);
    }
    
    void rec(vector<vector<char>>& board, string word, vector<vector<bool>> &vis, int i, int j, int k){
        if(ans) return ;
        if(k==word.length()-1){
            ans=true;
            return ;
        }
        int n=board.size(), m=board[0].size();
        
        for(int a=0;a<4;a++){
            if(check(i+x[a], j+y[a], n, m) && word[k+1]==board[i+x[a]][j+y[a]] && !vis[i+x[a]][j+y[a]]){
                vis[i+x[a]][j+y[a]] = true;
               rec(board, word, vis, i+x[a], j+y[a], k+1);
                vis[i+x[a]][j+y[a]] = false;
                if(ans) return ;
            }
        }
        return ;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis(board.size(), vector<bool> (board[0].size(), false));
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=true;
                    rec(board, word, vis, i, j, 0);
                    vis[i][j]=false;
                }
            }
        return ans;
    }
};