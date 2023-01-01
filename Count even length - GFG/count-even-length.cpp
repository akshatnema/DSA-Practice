//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long int

class Solution{
	public:
	ll D, X, Y;
    void extendedEuclid(ll A, ll B)
    {
        if (B == 0)
        {
            D = A;
            X = 1;
            Y = 0;
        }
        else
        {
            extendedEuclid(B, A % B);
            int temp = X;
            X = Y;
            Y = temp - (A / B) * Y;
        }
    }
    
    ll modInverse(ll A, ll M)
    {
        extendedEuclid(A, M);
        return (X % M + M) % M; // x may be negative
    }
	int compute_value(int n)
	{
	    int mod = 1e9+7;
	    long int nCr=1, res = 1;
 
        // Calculate SUM ((nCr)^2)
        for (int r = 1; r<=n ; r++)
        {
            nCr = (nCr%mod * (n+1-r)%mod)%mod;  
            int mod_inv = modInverse(r, mod);
            nCr = (nCr * mod_inv)%mod;
            res = (res + (nCr*nCr)%mod)%mod;
        }
     
        return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends