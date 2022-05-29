// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void count(vector<vector<char>>& grid, vector<vector<bool>>& vis, int i, int j){
        vis[i][j]=true;
        
        if(i>0 && grid[i-1][j]=='1' && !vis[i-1][j])
          count(grid, vis, i-1, j);
        
        if(j>0 && grid[i][j-1]=='1' && !vis[i][j-1])
          count(grid, vis, i, j-1);
        
        if(j<grid[0].size()-1 && i>0 && grid[i-1][j+1]=='1' && !vis[i-1][j+1])
          count(grid, vis, i-1, j+1);
        
        if(i>0 && j>0 && grid[i-1][j-1]=='1' && !vis[i-1][j-1])
          count(grid, vis, i-1, j-1);
        
        if(i<grid.size()-1 && grid[i+1][j]=='1' && !vis[i+1][j])
          count(grid, vis, i+1, j);
        
        if(j<grid[0].size()-1 && grid[i][j+1]=='1' && !vis[i][j+1])
          count(grid, vis, i, j+1);
          
        if(i<grid.size()-1 && j<grid[0].size()-1 && grid[i+1][j+1]=='1' && !vis[i+1][j+1])
          count(grid, vis, i+1, j+1);
        
        if(i<grid.size()-1 && j>0 && grid[i+1][j-1]=='1' && !vis[i+1][j-1])
          count(grid, vis, i+1, j-1);
        return ;
          
    }
    
    int numIslands(vector<vector<char>>& grid) {
         int n=grid.size();
         int m=grid[0].size();
         vector<vector<bool>> vis(grid.size(), vector<bool> (grid[0].size(), false));
         int ans=0;
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(!vis[i][j] && grid[i][j]=='1'){
                    // cout<<i<<" "<<j<<endl;
                    ans++;
                    count(grid, vis, i, j);
                 }
             }
         }
         return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends