// Question link - https://leetcode.com/problems/two-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int,int> mp;
        vector <int> v;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int ans=0,in=-1;
        for(int i=0;i<nums.size();i++)
        {   in=i;
            auto it1=mp.find(nums[i]);
            int x=target-nums[i];
            auto it=mp.find(x);
            if(it!=mp.end())
            {   if(it==it1)
               {
                  if(it->second>1)
                  {
                     ans=x;
                     v.push_back(i);
                     break; 
                  }
               }
               else{
                ans=x;
                v.push_back(i);
                break;
               }
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(ans==nums[i] && in!=i)
            {
                v.push_back(i);
            }
        }
        return v;
    }
};