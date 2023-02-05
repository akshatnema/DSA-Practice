class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<pair<int, int>> list;
        for(int i=0;i<intervals.size();i++){
            list.push_back({intervals[i][0],1});
            list.push_back({intervals[i][1]+1,-1});
        }
        list.push_back({newInterval[0],1});
        list.push_back({newInterval[1]+1,-1});
        sort(list.begin(), list.end(), [&](pair<int, int> a, pair<int, int> b){
            if(a.first<b.first) return true;
            else if(a.first==b.first){
                return a.second<b.second;
            }else return false;
        });
        vector<vector<int>> ans;
        vector<int> temp;
        int flag=0, count=0;
        for(int i=0;i<list.size();i++){
            if(list[i].second==1){
                if(flag==0){
                    temp.clear();
                    flag=1;
                    temp.push_back(list[i].first);
                }
                count++;
            }else{
                count--;
            }
            if(count==0 && flag==1){
                flag=0;
                temp.push_back(list[i].first-1);
                ans.push_back(temp);
                temp.clear();
            }
        }
        return ans;
    }
};