class Solution {
public:
    inline static int mod = 1000000007;
    vector<vector<int>> dp;
    vector<vector<int>> dp1;
    int solve(int i,int j,vector<vector<int>>& grid,int n){
        if(i == n-1 && j == n-1){
            return dp[i][j] = 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(grid[i][j] == 1){
            if(j+1 < n){
               int a = solve(i,j+1,grid,n);
               return dp[i][j] = a;
            }
            else{
                return dp[i][j] = 0;
            }
        }
        else if(grid[i][j] == 2){
            if(i+1 < n){
               int b = solve(i+1,j,grid,n);
               return dp[i][j] = b;
            }
            else{
                return dp[i][j] = 0;
            }
        }
        else{
            int a = 0;
            int b = 0;
            if(j+1 < n){
                a = solve(i,j+1,grid,n);
            }
            if(i+1 < n){
                b = solve(i+1,j,grid,n);
            }
            return dp[i][j] = (a+b)%mod;
        }
    }
    int solvee(int i,int j,vector<vector<int>>& grid,int n){
        if(i == n-1 && j == n-1){
            return dp1[i][j] = grid[i][j];
        }
        if(dp1[i][j] != -1){
            return dp1[i][j];
        }
        if(grid[i][j] == 1){
            if(j+1 < n){
               int a =  solvee(i,j+1,grid,n);
               if(a == 0){
                   return dp1[i][j] = 0;
               }
               return dp1[i][j] = a+grid[i][j];
            }
        }
        else if(grid[i][j] == 2){
            if(i+1 < n){
               int b =  solvee(i+1,j,grid,n);
               if(b == 0){
                   return dp1[i][j] = 0;
               }
               return dp1[i][j] = b+grid[i][j];
            }
        }
        else{
            int a = 0;
            int b = 0;
            if(j+1 < n){
                a = solvee(i,j+1,grid,n);
            }
            if(i+1 < n){
                b = solvee(i+1,j,grid,n);
            }
            if(!(a == 0 && b == 0)){
                return dp1[i][j] = max(a,b)+grid[i][j];
            }
        }
        return dp1[i][j] = 0;
    }
    vector<int> findWays(vector<vector<int>>& grid) {
        //similar to leetcode but this is on little easy side.
        //first find total no. of paths
        int i = 0;
        int j = 0;
        int n = grid.size();
        dp.assign(n+1,vector<int>(n+1,-1));
        dp1.assign(n+1,vector<int>(n+1,-1));
        int ans1 = solve(i,j,grid,n);
        i = 0;
        j = 0;
        int ans2 = solvee(i,j,grid,n);
        vector<int> v;
        v.push_back(ans1);
        v.push_back(ans2);
        return v;
    }
};