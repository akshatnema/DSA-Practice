class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<pair<int, int>> list;
        for(int i=0;i<firstList.size();i++){
            list.push_back({firstList[i][0], 1});
            list.push_back({firstList[i][1], -1});
        }
        for(int i=0;i<secondList.size();i++){
            list.push_back({secondList[i][0], 1});
            list.push_back({secondList[i][1], -1});
        }
        sort(list.begin(), list.end(), [](pair<int, int> a, pair<int,int> b){
            if(a.first==b.first)
                return a.second>b.second;
            else
                return a.first<b.first;
        });
        int count=0, flag=0;
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i=0;i<list.size();i++){
            if(list[i].second==1){
                count++;
            }else{
                if(flag){
                    flag=0;
                    temp.push_back(list[i].first);
                    ans.push_back(temp);
                    temp.clear();
                }
                count--;
            }
            if(count==2 && flag==0){
                temp.clear();
                flag=1;
                temp.push_back(list[i].first);
            }
        }
        return ans;
    }
};