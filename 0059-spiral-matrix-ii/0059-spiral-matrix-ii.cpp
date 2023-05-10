class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int ct=1,l=0,t=0, m=n;
        while(l<m && t<n)
        {
            for(int i=l;i<m;i++)
            {  
                  // ans.push_back(matrix[t][i]);
                  ans[t][i]=ct;
                ct++;
            }
            t++;
            for(int i=t;i<n;i++)
            { 
                // ans.push_back(matrix[i][m-1]);
                ans[i][m-1]=ct;
                ct++;
            }
            m--;
            if(t<n){
             for(int i=m-1;i>=l;i--)
            {
                // ans.push_back(matrix[n-1][i]);
                 ans[n-1][i]=ct;
                 ct++;
            } 
            n--;
            }
            if(l<m)
            {
             for(int i=n-1;i>=t;i--)
            { 
                 // ans.push_back(matrix[i][l]);
                 ans[i][l]=ct;
                 ct++;
            } 
            l++;
            }
            
            }
        return ans;
    }
};