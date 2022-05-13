// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    int sum=0;
	    unordered_map <int,int> mp;
	    mp[0]=1;
	    int ct=0;
	    int mx=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	        int rem=sum%k;
	        if(rem<0) rem+=k;
	        if(rem==0) 
	         mx=max(mx,i+1);
	        auto it = mp.find(rem);
	        if(it==mp.end()){
	            mp[rem] = i;
	        }else{
	            ct = i - it->second;
	            mx=max(mx, ct);
	        }
	    }
	    return mx;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends