class Solution {
    public int maximumSum(int[][] mat, int k) {
        // code here
        int n = mat.length;
        int[][] dp = new int[n][n];
        
        dp[0][0] = mat[0][0];
        
        for(int i=1;i<n;i++){
            dp[i][0] = dp[i-1][0]+mat[i][0];
        }
        
        
        for(int j=1;j<n;j++){
            dp[0][j] = dp[0][j-1]+mat[0][j];
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mat[i][j];
            }
        }
        
        
       
        int maxi = Integer.MIN_VALUE;
        
        
        for(int i=k-1;i<n;i++){
            for(int j=k-1;j<n;j++){
                int sum = ( dp[i][j]-
                ((i>=k)?dp[i-k][j]:0 ) -
                ((j>=k)?dp[i][j-k]:0) +
                ((i>=k && j>=k)?dp[i-k][j-k] : 0)
                );
                maxi = Math.max(maxi,sum);
            }
        }
        
      

    return maxi;
    }
}