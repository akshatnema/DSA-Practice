// Question link -https://leetcode.com/problems/decode-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack <int> num;
        stack <string> ch;
        string ans;
        int i=0;
        while(i<s.length()){
            if(isdigit(s[i])){
                int number=0;
                while(i<s.length() && isdigit(s[i])){
                    number=number*10+s[i]-'0';
                    i++;
                }
                num.push(number);
            }
            else if(s[i]=='['){
                ch.push(ans);
                ans="";
                i++;
            }
            else if(s[i]==']'){
                string temp=ch.top();
                ch.pop();
                int x=num.top();
                num.pop();
                for(int j=0;j<x;j++)
                    temp+=ans;
                ans=temp;
                i++;
            }else{
                ans+=s[i];
                i++;
            }
        }
        return ans;       
    }
};