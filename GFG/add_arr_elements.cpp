// Question link - https://practice.geeksforgeeks.org/problems/adding-array-element4756/1
#include <bits/stdc++.h>

using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    int minOperations(int arr[], int n, int k) {
        if(n==1){
            return arr[0]>=k?0:-1;
        }
        priority_queue <int,vector<int>, greater<int>>q(arr,arr+n);
        int ct=0;
        while(!q.empty()){
            int x=q.top();
            q.pop();
            if(x>=k)
             break;
            if(!q.empty()){
                int y=q.top();
                q.pop();
                q.push(x+y);
                ct++;
            }
        }
        return ct;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        int ans = obj.minOperations(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends