class Solution {
public:
    vector<vector<int> > answer;
    void subWithSumK(vector<int> &arr,int n,int i,int sum,vector<int>&ds,int k){
        if(i == n){
            if(sum == k){
                answer.push_back(ds);
            }
            return;
        }
        
        if(arr[i] + sum <= k){
            ds.push_back(arr[i]);
            subWithSumK(arr,n,i,sum + arr[i],ds,k);
            ds.pop_back();
        }

        subWithSumK(arr,n, i + 1,sum,ds,k);
    }
     
    vector<vector<int> > combinationSum(vector<int>& nums,int k){
        vector<int>ds;
        subWithSumK(nums,nums.size(),0,0,ds,k);
        return answer;
    }
};