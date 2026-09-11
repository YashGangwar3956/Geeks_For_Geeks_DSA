class Solution {
  public:
    virtual int maxProduct(vector<int> &arr, int k){
         int n=arr.size();
         vector<long long> mx(k+1, LLONG_MIN);
         vector<long long> mn(k+1, LLONG_MAX);
         mx[0]=mn[0]=1;
         for(int x: arr){
           for(int j=min(k, n); j>=1; j--){
             if(mx[j-1] == LLONG_MIN) continue;
             long long a=mx[j-1]*x;
             long long b=mn[j-1]*x;
             mx[j]=max(mx[j], max(a, b));
             mn[j]=min(mn[j], min(a, b));
           }  
         }
         return (int)(mx[k]);
       }
};