// Question link - https://leetcode.com/problems/open-the-lock/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set <string> st;
        for(int i=0;i<deadends.size();i++){
            st.insert(deadends[i]);
        }
        queue <string> q;
        int level=0;
        q.push("0000");
        while(!q.empty()){
            queue<string> t;
            while(!q.empty()){
                string s=q.front();
                if(s==target){
                    return level;
                }
                if(st.count(s))
                {
                    q.pop();
                    continue;
                }
                st.insert(s);
                vector <string> temp=getnext(s);
                for(int i=0;i<temp.size();i++){
                    if(st.count(temp[i])){
                        continue;
                    }
                    t.push(temp[i]);
                }
                q.pop();
            }
            level++;
           q=t;
        }
        return -1;
    }
    
    vector<string> getnext(string s){
        vector <string> ans;
        for(int i=0;i<4;i++){
            string temp=s;
            if(temp[i]=='9'){
                temp[i]='0';
            } else temp[i]=(temp[i]+1);
            ans.push_back(temp);
            temp=s;
            if(temp[i]=='0'){
                temp[i]='9';
            } else temp[i]=(temp[i]-1);
            ans.push_back(temp);
        }
        return ans;
    }
    
};