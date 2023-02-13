class Solution {
public:
    vector<int> dp;    
    
    int rec(int in, string s){
        if(in==s.length()){
            return 1;
        }
        if(in>s.length()) return 0;
        if(s[in]=='0') return 0;
        if(dp[in]!=-1) return dp[in];
        int x=0;
        if(s[in]!='0')
            x = rec(in+1, s);
        int y=0;
        if(in+1<s.length()){
            if(s[in]=='1') y=rec(in+2, s);
            else if(s[in]=='2' && s[in+1]<='6') y=rec(in+2, s);
            else y=0;
        }
        return dp[in] = x+y;
        
    }
    
    int numDecodings(string s) {
        dp.resize(s.length(), -1);
        dp[0]=rec(0, s);
        return dp[0];
    }
};