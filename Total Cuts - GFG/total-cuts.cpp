//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        vector<int> high(N); 
        vector<int> low(N);
        int hi=INT_MIN, lo=INT_MAX;
        for(int i=0;i<A.size();i++){
            if(hi<A[i]){
                hi=A[i];
            }
            high[i]=hi;
            
        }
        for(int i=N-1;i>=0;i--){
            if(lo>A[i]){
                lo=A[i];
            }
            low[i]=lo;
        }
        int ans=0;
        for(int i=0;i<N-1;i++){
            if(high[i]+low[i+1]>=K){
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends