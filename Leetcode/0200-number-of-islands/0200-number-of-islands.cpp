class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                  ans++;
                  dfs(grid,i,j,vis);    
                }
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j,vector<vector<int>> &vis){
        if(i<0 || i>=grid.size())
            return ;
        if(j<0 || j>=grid[i].size())
            return ;
        if(vis[i][j]==1 || grid[i][j]!='1')
            return ;
        vis[i][j]=1;
        grid[i][j]='*';
        dfs(grid,i+1,j,vis);
        dfs(grid,i-1,j,vis);
        dfs(grid,i,j+1,vis);
        dfs(grid,i,j-1,vis);
        return ;
    }
};