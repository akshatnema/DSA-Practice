// Question link - https://practice.geeksforgeeks.org/problems/cd61add036272faa69c6814e34aa7007d5a25aa6/1

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        int index=0,l=0,t=0;
        while(l<m && t<n)
        {
            for(int i=l;i<m;i++)
            {  index++;
                if(index==k)
                  return a[t][i];
                  
            }
            t++;
            for(int i=t;i<n;i++)
            { index++;
                if(index==k)
                  return a[i][m-1];
                
            }
            m--;
            if(t<n){
             for(int i=m-1;i>=l;i--)
            {
                index++;
                if(index==k)
                  return a[n-1][i];
            } 
            n--;
            }
            if(l<m)
            {
             for(int i=n-1;i>=t;i--)
            { index++;
                if(index==k)
                  return a[i][l];
            } 
            l++;
            }
            
            }
      //  return a[n+1][m+1];    
    }

};

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}  // } Driver Code Ends