// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    static bool cnp(vector<int> a, vector<int> b){
        if(a[0]<b[0])
         return true;
        else if(a[0]==b[0])
         return a[1]<b[1];
        else return false;
    }
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         vector<vector<int>> ans;
         sort(intervals.begin(),intervals.end(),cnp);
         int ini=-1, fi=-1;
         for(int i=0;i<intervals.size();i++){
             if(ini==-1){
                 ini=intervals[i][0];
                 fi=intervals[i][1];
             }else{
                 if(fi>=intervals[i][0]){
                     fi=max(fi,intervals[i][1]);
                 }else{
                     vector<int> temp;
                     temp.push_back(ini);
                     temp.push_back(fi);
                     ans.push_back(temp);
                     ini=intervals[i][0];
                     fi=intervals[i][1];
                 }
             }
         }
         vector<int> temp;
         temp.push_back(ini);
         temp.push_back(fi);
         ans.push_back(temp);
         return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends