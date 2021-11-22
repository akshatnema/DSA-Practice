// Question Link - https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0 && nums2.size()==0){
            return 0;
        }
     vector <int> nums;
        int i,j;
        i=j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }
            else{
                nums.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()){
            nums.push_back(nums1[i]);
                i++;
        }
        while(j<nums2.size()){
            nums.push_back(nums2[j]);
                j++;
        }
        int n=(nums1.size()+nums2.size());
        if(n%2){
            int x=(n+1)/2;
            return nums[x-1];
        }
        else{
            int x=n/2;
            int y=x+1;
            double med=(double)(nums[x-1]+nums[y-1])/2;
            return med;
        }
    }
};