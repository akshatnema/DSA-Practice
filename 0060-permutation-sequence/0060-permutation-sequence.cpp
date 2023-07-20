class Solution {
public:
    string next(string s) {
        if(s.length()==1) return s;
        int in=-1, num=0;
        for(int i=s.length()-1;i>0;i--) {
            if(s[i]-'0'>s[i-1]-'0'){
                in=i-1;
                num=s[i-1]-'0';
                break;
            }
        }
       
        if(in==-1) return s;
        int in1=-1;
        for(int i=in+1;i<s.length()-1;i++) {
            if(s[i]-'0'>s[in]-'0' && s[in]-'0'>s[i+1]-'0') {
                in1=i;
            }
        }
        if(in1==-1) in1=s.length()-1;
        // cout<<in1<<endl; 
        char temp=s[in];
        s[in]=s[in1];
        s[in1]=temp;
        string sub=s.substr(in+1, s.length()-in);
        reverse(sub.begin(), sub.end());
        string ans = s.substr(0, in+1) + sub;
        // cout<<ans<<endl;
        return ans;
    }
    
    string getPermutation(int n, int k) {
        string ans="";
        for(int i=1;i<=n;i++) {
            ans+=to_string(i);;
        }
        for(int i=0;i<k-1;i++) {
            ans=next(ans);
        }
        return ans;
    }
};