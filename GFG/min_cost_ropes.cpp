// Question link - https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        if(n==1){
            return 0;
        }
        long long sum=0;
        priority_queue <long long,vector<long long>,greater<long long>> pq(arr,arr+n);
        while(!pq.empty()){
            long long x=pq.top();
            pq.pop();
            if(!pq.empty()){
                long long y=pq.top();
                pq.pop();
                sum+=x+y;
                pq.push(x+y);
                // cout<<x<<" "<<y<<endl;
            }
            else{
                return sum;
            }
        }
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends