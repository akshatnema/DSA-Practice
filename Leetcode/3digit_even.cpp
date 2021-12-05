#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map <int,int> mp1;
        unordered_map <int,int> mp2;
        vector <int> ans;
        for(int i=0;i<digits.size();i++){
            mp1[digits[i]]++;
        }
        for(int i=100;i<999;i++){
            if(i%2)
                continue;
            int n=i; int flag=0;
            mp2.clear();
            while(n){
               int x=n%10;
                mp2[x]++;
                if(mp1[x]==0 || mp2[x]>mp1[x]){
                    flag=1;
                    break;
                }
                n=n/10;
            }
            if(flag==0)
                ans.push_back(i);
        }
        return ans;
    }
};