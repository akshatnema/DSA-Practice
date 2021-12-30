// Question link - https://leetcode.com/problems/daily-temperatures/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public: // next-greater-element using stacks
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector <int> ans(temperatures.size());
        stack <int> s;
        int i=temperatures.size()-1;
        while(i>0 && temperatures[i]<temperatures[i-1]){
            ans[i]=0;
            i--;
        }
        s.push(i);
        ans[i]=0;
        i--;
        while(i>=0){
            if(temperatures[s.top()]>temperatures[i]){
                ans[i]=s.top()-i;
                s.push(i);
                i--;
            }else{
                int flag=0;
                while(!s.empty()){
                    if(temperatures[i]<temperatures[s.top()]){
                        flag=1;
                        break;
                    }
                    s.pop();
                }
                if(flag==0){
                    ans[i]=0;
                    s.push(i);
                    i--;
                    continue;
                }
                ans[i]=s.top()-i;
                s.push(i);
                i--;
            }
        }
        return ans;
    }
};