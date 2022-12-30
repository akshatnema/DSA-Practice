class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      int n=nums.size();
       sort(nums.begin(),nums.end());
       vector <vector<int>> it;
       for(int i=0;i<n-2;i++){
           int l=i+1;
           int r=n-1;
           while(l<r){
               int arr[3];
               arr[0]=nums[i];
               arr[1]=nums[l];
               arr[2]=nums[r];
               sort(arr,arr+3);
               if(arr[0]+arr[1]+arr[2]==0){
                   vector <int> temp;
                   temp.push_back(arr[0]);temp.push_back(arr[1]);temp.push_back(arr[2]);
                   it.push_back(temp);
                   l++;
                   r--;
                   if(l<r && nums[l]==nums[l-1]){
                       l++;
                   }
               }
               else if(arr[0]+arr[1]+arr[2]>0)
               {
                   r--;
               }
               else
                   l++;
           }
       } 
      set <vector<int>> s;
      for(int i=0;i<it.size();i++){
          s.insert(it[i]);
      }
        vector <vector<int>> ans;
        auto it1=s.begin();
        while(it1!=s.end()){
            ans.push_back(*it1);
            it1++;
        }
        return ans;   
    }
};