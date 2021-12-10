// Question Link - https://leetcode.com/problems/maximum-ascending-subarray-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int mx=0, sum=0;
        sum+=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                mx=max(mx,sum);
                sum=0;
            }
            sum+=nums[i];
        }
        mx=max(mx,sum);
        return mx;
    }
};