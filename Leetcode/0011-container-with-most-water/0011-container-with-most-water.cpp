class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int area=-1;
        while(l<r){
            int mi=min(height[l],height[r]);
            int in=r-l;
            int temp=mi*in;
            area=max(area,temp);
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return area;
    }
};