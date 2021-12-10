// Question Link - https://leetcode.com/problems/intersection-of-two-arrays/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       sort(nums1.begin(),nums1.end());
        set <int> s;
        for(int j=0;j<nums2.size();j++){
            auto x=lower_bound(nums1.begin(),nums1.end(),nums2[j]);
            if(x!=nums1.end() && *x==nums2[j]){
                s.insert(nums2[j]);
            }
        }
        vector <int> ans;
        for(auto it:s) ans.push_back(it);
        return ans;
    }
};