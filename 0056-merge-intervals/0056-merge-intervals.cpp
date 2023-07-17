class Solution {
public:
    static bool cnp(pair<int,int>a,pair<int,int>b){
        if(a.first<b.first){
            return true;
        }else if(a.first==b.first){
            return a.second>b.second;
        }else return false;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int, int>> times;
        for(int i=0;i<intervals.size();i++) {
            times.push_back(make_pair(intervals[i][0], 1));
            times.push_back(make_pair(intervals[i][1], -1));
        }
        sort(times.begin(), times.end(), cnp);
        int count=0, left=-1;
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i=0;i<times.size();i++) {
            if(times[i].second==1) {
                if(!count) left = times[i].first;
                count+=1;
            } else {
                count-=1;
            }
            if(count == 0 && left!=-1) {
                temp.push_back(left);
                temp.push_back(times[i].first);
                ans.push_back(temp);
                temp.clear();
                left=-1;
            }
        }
        return ans;
    }
};