class Solution {
public:
    int longestSubseq(vector<int> &arr) {
        unordered_map<int, int> dp;
        int maxlen = 0;

        for (int i = 0; i < arr.size(); ++i) {
            int x = arr[i];

            int left = dp.count(x - 1) ? dp[x - 1] : 0;
            int right = dp.count(x + 1) ? dp[x + 1] : 0;
            int best = max(left, right) + 1;

            dp[x] = best;
            maxlen = max(maxlen, dp[x]);
        }

        return maxlen;
    }
};