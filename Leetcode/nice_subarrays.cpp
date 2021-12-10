// Question link - https://leetcode.com/problems/count-number-of-nice-subarrays/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
      unordered_map <int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2)
                nums[i]=1;
            else nums[i]=0;
        }
        int sum=0,count=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            auto it=mp.find(sum-k);
            if(it!=mp.end()){
               count+=it->second;
            }
            mp[sum]++;
        }
        return count;
    }
};