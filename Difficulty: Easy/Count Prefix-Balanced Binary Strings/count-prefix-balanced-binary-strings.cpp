class Solution {
    public:
    const int mod = 1e9+7;
    int prefixStrings(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = 0;
            for(int j = 0; j < i; j++) {
                dp[i] = (dp[i] + (1LL * dp[j] * dp[i-j-1]) % mod) % mod;
            }
        }
        return dp[n];
    }
};