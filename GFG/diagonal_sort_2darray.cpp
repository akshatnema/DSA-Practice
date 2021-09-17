#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    void diagonalSort(vector<vector<int> >& matrix, int n, int m) {
        if(n==2 && m==2)
         return ;
        int i=n-2;
        while(i>=1)
        {
            int j=0,k=i;
            vector <int> temp;
            while(k<n && j<m){
             temp.push_back(matrix[k][j]);
             k++;j++;
            }
            sort(temp.begin(),temp.end());
            int x=0;
            k=i;j=0;
            while(k<n && j<m && x<temp.size()){
             matrix[k][j]=temp[x];
             k++;j++;
             x++;
            }
            i--;
        }
        int j=1;
        while(j<=m-2)
        {
            int i=0,k=j;
            vector <int> temp;
            while(k<m && i<n){
             temp.push_back(matrix[i][k]);
             k++;i++;
            }
            sort(temp.begin(),temp.end(),greater<int>());
            int x=0;
            k=j;i=0;
            while(k<m && i<n && x<temp.size()){
             matrix[i][k]=temp[x];
             k++;i++;
             x++;
            }
          j++;
        }
        
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;

        int inputline2[n*m];
        for (int i = 0; i < n*m; ++i)
            cin>> inputline2[i];
        vector<vector<int> > matrix( n , vector<int> (m, 0));

        for(int i=0; i<n; i++) {
            for (int j = 0; j < m; ++j) {
                matrix[i][j] = inputline2[i * m + j]; 
            }
        }
        
        Solution ob;
        ob.diagonalSort(matrix, n, m);

        // print the modified matrix
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < m; j++) { 
                cout << matrix[i][j] << " "; 
            } 
            cout << endl; 
        }    
    }
    return 0;
}

  // } Driver Code Ends