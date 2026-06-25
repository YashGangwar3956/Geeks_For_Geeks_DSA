class Solution {
  public:
    void solve(int lastDigit, int len, int n, int num, vector<int>& ans) {
        if (len == n) {
            ans.push_back(num);
            return;
        }

        for (int d = lastDigit + 1; d <= 9; d++) {
            solve(d, len + 1, n, num * 10 + d, ans);
        }
    }

    vector<int> increasingNumbers(int n) {
        vector<int> ans;

        if (n > 10)
            return ans;

        if (n == 1) {
            for (int i = 0; i <= 9; i++)
                ans.push_back(i);
            return ans;
        }

        for (int d = 1; d <= 9; d++) {
            solve(d, 1, n, d, ans);
        }

        return ans;
    }
};