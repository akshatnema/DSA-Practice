//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
    	vector<int> dp;
    	int mod=1e9+7;
    	int rec(int in, string s){
    	    if(in>=s.length()) return 1;
    	    if(dp[in]!=-1) return dp[in];
    	    int first=0, second=0;
    	    if(s[in]=='0') return 0;
    	    else if(s[in]=='1'){
    	        first = rec(in+1, s)%mod;
    	        if(in+2<=s.length())
    	            second = rec(in+2, s)%mod;
    	    }else if(s[in]=='2'){
    	        first=rec(in+1, s)%mod;
    	        if(in+1<s.length() && s[in+1]<'7' && in+2<=s.length())
    	            second = rec(in+2, s)%mod;
    	    }else{
    	        first=rec(in+1, s)%mod;
    	    }
    	    
    	   return dp[in]=(first+second)%mod;
    	}
    	
    	int CountWays(string str){
    	    dp.resize(str.length(), -1);
    	    dp[0]=rec(0, str);
    	    return dp[0]%(mod);
    	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends