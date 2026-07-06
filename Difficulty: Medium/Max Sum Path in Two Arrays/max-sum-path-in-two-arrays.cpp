class Solution {
  public:
  vector<vector<int>>find(vector<int>&arr1,vector<int>&v){
        vector<vector<int>>ans;
        int sum=0,j=0;
        for(int i=0;i<arr1.size();i++){
            if(j<v.size() and arr1[i]==v[j]){
                ans.push_back({sum,v[j]});
                sum=0;
                j++;
            }
            else{
                sum+=arr1[i];
            }
        }
        ans.push_back({sum,0});
        return ans;
    }
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        // Code here
         int n=arr1.size(),m=arr2.size();
       vector<int> v;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            ++i;
        } else if (arr1[i] > arr2[j]) {
            ++j;
        } else {
            v.push_back(arr1[i]);
            ++i;
            ++j;
        }
    }
        vector<vector<int>>sum1=find(arr1,v);
        vector<vector<int>>sum2=find(arr2,v);
       int sum=0;
       for(int i=0;i<sum1.size();i++){
          sum+=max(sum1[i][0],sum2[i][0])+sum1[i][1];
       }
        return sum;
    }
};