class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> in;
        int size=nums1.size()+nums2.size();
        if(size%2){
            int x=(size-1)/2;
            in.push_back(x);
        }else{
            int y=(size-1)/2;
            int x=(size+1)/2;
            in.push_back(y);
            in.push_back(x);
        }
        double median=0.0;
        int i=0,j=0;
        int ct=0,k=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<=nums2[j]){ if(ct==in[k]){
                median+=nums1[i];
                k++;
            }
             i++;
            }
            else{ 
                if(ct==in[k]){
                median+=nums2[j];
                k++;
            }
                j++;}
            ct++;
            if(k==in.size()) break;
        }
        while(i<nums1.size() && k<in.size()){
            if(ct==in[k]){
                median+=nums1[i];
                k++;
            }
             i++;
            ct++;
            if(k==in.size()) break;
        }
        while(j<nums2.size() && k<in.size()){
            if(ct==in[k]){
                median+=nums2[j];
                k++;
            }
             j++;
            ct++;
            if(k==in.size()) break;
        }
        if(in.size()==2)
            median=median/2.0;
        return median;
    }
};