// Question link - https://practice.geeksforgeeks.org/problems/find-first-and-last-occurrence-of-x0849/1

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    
    long s1(vector<long long> v, long long x)
    {
        long i=0,j=v.size();
        while(i<=j)
        {
            long mid=(i+j)/2;
            if(v[mid]==x)
            {
                if(mid==0)
                 return 0;
                else if(v[mid-1]!=x)
                  return mid;
                else
                  j=mid-1; 
            }
            else if(v[mid]>x)
             j=mid-1;
            else 
             i=mid+1;
        }
         return -1;
    }
    
    long s2(vector<long long> v, long long x)
    {
        long i=0,j=v.size();
        while(i<=j)
        {
            long mid=(i+j)/2;
            if(v[mid]==x)
            {
                if(mid==v.size()-1)
                 return v.size()-1;
                else if(v[mid+1]!=x)
                  return mid;
                else
                  i=mid+1; 
            }
            else if(v[mid]>x)
             j=mid-1;
            else 
             i=mid+1;
        }
         return -1;
    }
    
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        pair <long,long> ans;
        ans.first=s1(v,x);
        ans.second=s2(v,x);
        return ans;
    }
};

// { Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}
  // } Driver Code Ends