#include <bits/stdc++.h>
class Solution {
public:
    string rec(string initial, int n){
        if(n==0) return initial;
        string ans="";
        char c=initial[0];
        int ct=1;
        for(int i=1;i<initial.length();i++){
            if(initial[i]==c) ct++;
            else{
                string temp=to_string(ct);
                ans+=temp;
                ans.push_back(c);
                c=initial[i];
                ct=1;
            }
        }
        string temp=to_string(ct);
        ans+=temp;
        ans.push_back(c);
        ans = rec(ans, n-1);
        return ans;
    }
    string countAndSay(int n) {
        if(n==1) return "1";
        else{
            string ans="1";
            ans=rec(ans, n-1);
            return ans;
        }
    }
};