// Question Link - https://leetcode.com/problems/find-peak-element/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int binary(vector <int>&nums, int l, int r){
        if(l>r)
            return -1;
        int mid=(l+r)/2;
        if(mid==0){
            if(nums[mid]>nums[mid+1])
                return mid;
        }
        if(mid==nums.size()-1){
            if(nums[mid]>nums[mid-1])
                return mid;
        }
        if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
            return mid;
        else {
            int x=binary(nums,l,mid-1);
            if(x!=-1)
                return x;
            int y=binary(nums,mid+1,r);
            return y;
        }
    }
    
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        if(nums.size()==2){
            return nums[0]>nums[1]?0:1;
        }
        int ans=binary(nums,0,nums.size());
        return ans;
    }
};