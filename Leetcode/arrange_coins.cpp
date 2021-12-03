// Question link - https://leetcode.com/problems/arranging-coins/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        long long x=(long long)n*2;
        long long y=sqrt(x);
        long long int ans=-1;
        if(y*(y+1)>x){
            ans=y-1;
        }
        else{
            ans=y;
        }
        return ans;
    }
};