class Solution {
  public:
    int maxTask(vector<int>& hi, vector<int>& li) {
        // code here
        int n=hi.size();
        int t[n+1];
            t[0]=0;
            t[1] = hi[0];
            for(int i=2;i<=n;i++){
                t[i] = max(hi[i-1]+t[i-2] , li[i-1]+t[i-1]);
            }
            return t[n];
    }
};