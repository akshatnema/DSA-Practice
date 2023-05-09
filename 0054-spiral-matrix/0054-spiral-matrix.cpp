class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
          vector<int> ans;
        int n=matrix.size();
        int m=matrix[0].size();
        int index=0,l=0,t=0;
        while(l<m && t<n)
        {
            for(int i=l;i<m;i++)
            {  
                  ans.push_back(matrix[t][i]);
                  
            }
            t++;
            for(int i=t;i<n;i++)
            { 
                ans.push_back(matrix[i][m-1]);
                
            }
            m--;
            if(t<n){
             for(int i=m-1;i>=l;i--)
            {
                ans.push_back(matrix[n-1][i]);
            } 
            n--;
            }
            if(l<m)
            {
             for(int i=n-1;i>=t;i--)
            { 
                 ans.push_back(matrix[i][l]);
            } 
            l++;
            }
            
            }
        return ans;
    }
};