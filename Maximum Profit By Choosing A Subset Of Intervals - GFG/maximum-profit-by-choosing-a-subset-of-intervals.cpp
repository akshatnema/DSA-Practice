//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int helper(int i, vector<vector<int>>&intervals, int n, vector<int>&dp, vector<int>&start) {
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ind = lower_bound(start.begin(), start.end(), intervals[i][1]) - start.begin();
        int take = intervals[i][2] + helper(ind, intervals, n, dp, start);
        int notTake = helper(i+1, intervals, n, dp, start);
        return dp[i] = max(take, notTake);
    }
  
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        // Write your code here.
        sort(intervals.begin(), intervals.end());
        vector<int>start;
        for(int i = 0;i<n;i++) {
            start.push_back(intervals[i][0]);
        }
        
        vector<int>dp(n+1, -1);
        return helper(0, intervals, n, dp, start);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends