/* 
Question link- https://practice.geeksforgeeks.org/problems/large-factorial4721/1/
*/

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution{
public:
    vector<long long> factorial(vector<long long> a, int n) {
       int mx=*max_element(a.begin(),a.end());
       vector <long long int> ans(mx,0);
       ans[0]=1;
       for(int i=1;i<mx;i++)
       {
           ans[i]=(ans[i-1]*(i+1))%1000000007;
       }
       vector <long long int> b;
       for(int i=0;i<n;i++)
       {
           if(a[i]==0){
            b.push_back(1);
            continue ;
           }
           b.push_back(ans[a[i]-1]);
            
       }
       return b;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<long long> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<long long> res = ob.factorial(a, n);
        for (i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends