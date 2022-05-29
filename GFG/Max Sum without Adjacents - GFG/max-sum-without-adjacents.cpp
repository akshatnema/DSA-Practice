// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	   vector<int> dp(n,0);
	   vector<int> flag(n,0);
	   dp[0]=arr[0];
	   flag[0]=1;
	   if(arr[0]>arr[1])
	   {
	       dp[1]=arr[0];
	   }else
	     {
	         dp[1]=arr[1];
	         flag[1]=1;
	     }
	   for(int i=2;i<n;i++){
	       if(flag[i-1]!=0){
	           if(dp[i-1]>=dp[i-2]+arr[i]){
	               dp[i]=dp[i-1];
	               flag[i]=0;
	           }else{
	               dp[i]=dp[i-2]+arr[i];
	               flag[i]=1;
	           }
	       }else{
	           if(dp[i-1]>dp[i-2]){
	               dp[i]=dp[i-1]+arr[i];
	               flag[i]=1;
	           }else{
	               dp[i]=dp[i-2]+arr[i];
	               flag[i]=1;
	           }
	       }
	   }
	   return dp[n-1];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends