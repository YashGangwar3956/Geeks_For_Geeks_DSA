class Solution {
  public:
   int f(int i,int prev,string &str,int n,vector<vector<int>>&dp)
    {
        if(i==n)
        {
            return 1;
        }
        if(dp[i][prev] != -1)
        {
            return dp[i][prev];
        }
        int sum=0,ways=0;
        for(int ind=i;ind<n;ind++)
        {
            sum+=str[ind]-'0';
            if(sum >= prev)
            {
                ways+=f(ind+1,sum,str,n,dp);
            }
        }
        return dp[i][prev]=ways;
    }
    int validGroups(string &str) {
        // code here
         int n=str.size();
        vector<vector<int>> dp(n,vector<int>(900+1,-1));
        return f(0,0,str,n,dp);
    }
};