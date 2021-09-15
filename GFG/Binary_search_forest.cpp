// Question link - https://practice.geeksforgeeks.org/problems/ffd66b6a0bf7cefb9987fa455974b6ea5695709e/1/

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int find_height(int tree[], int n, int k)
    {  
        sort(tree,tree+n);
         int i=0,j=tree[n-1];
         while(i<=j)
         {
             int mid=i+(j-i)/2;
             int sum=0;
             for(int l=n-1;l>=0;l--)
             {
                 if(tree[l]-mid<0)
                  break;
                 sum+=tree[l]-mid;
             }
             if(sum==k)
              return mid;
             else if(sum>k)
               i=mid+1;
             else
              j=mid-1;
             
         }
        return -1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n;

        int tree[n];
        for(int i=0; i<n; i++)
            cin>>tree[i];
        cin>>k;
        Solution ob;
        cout<< ob.find_height(tree,n,k) << endl;
    }
    return 1;
}  // } Driver Code Ends