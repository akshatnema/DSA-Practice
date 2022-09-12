class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int l=0, r=n-1;
        int ans=0;
        while(l<=r){
            if(power<tokens[l]){
                if(r==l) return ans;
                power+=tokens[r];
                r--;
                ans--;
                if(ans<0) return 0;
            }else{
                power-=tokens[l];
                l++;
                ans++;
            }
        }
        
        return ans;
    }
};