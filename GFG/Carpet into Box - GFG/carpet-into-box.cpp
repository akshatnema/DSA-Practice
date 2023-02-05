//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int solve(int a, int b, int c, int d){
        
        if((a <= c && b <= d) || (a <= d && b <= c))
            return 0;
        
        if(a > c){
            a = a >> 1;
            
        }
        else if(b > d){
            b = b >> 1;
        }
        
        return 1 + solve(max(a,b), min(a, b), c, d);
    }
    
    int carpetBox(int A, int B, int C, int D){
        
        return solve(max(A,B), min(A,B), max(C,D), min(C,D));
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends