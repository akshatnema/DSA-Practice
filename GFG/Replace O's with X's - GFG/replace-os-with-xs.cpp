// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void change(vector<vector<char>> &mat, int i, int j){
        mat[i][j]='*';
        int dx[]={0,0,-1,1};
        int dy[]={-1,1,0,0};
        for(int k=0;k<4;k++){
           int l=i+dx[k];
            int m=j+dy[k];
            if(l>=0 && m>=0 && l<mat.size() && m<mat[0].size() && mat[l][m]=='O')
             change(mat,l,m);
        }
        return ;
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        for(int i=0;i<n;i++)
          for(int j=0;j<m;j++){
              if(i==0 || j==0 || i==n-1 || j==m-1){
                  if(mat[i][j]=='O')
                   change(mat,i,j);
              }
         }
         
        for(int i=0;i<n;i++)
          for(int j=0;j<m;j++){
               if(mat[i][j]=='O')
                 mat[i][j]='X';
          } 
          
        for(int i=0;i<n;i++)
          for(int j=0;j<m;j++){
               if(mat[i][j]=='*')
                 mat[i][j]='O';
          } 
        
        return mat;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends