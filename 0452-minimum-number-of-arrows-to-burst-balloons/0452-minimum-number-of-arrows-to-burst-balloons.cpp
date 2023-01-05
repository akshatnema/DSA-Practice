class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans=1, end=-1;
        end=points[0][1];
        for(int i=0;i<points.size();i++){
            if(points[i][0]>end){
                ans++;
                end=points[i][1];
            }else{
                end=min(end, points[i][1]);
            }
        }
        return ans;
    }
};