class Solution {
public:
int maxFruits(vector<int>& arr, int m) {
	// code here
	int n = arr.size();
	vector<int> dp(n, 0);
	int sum = 0;
	for (int i = 0; i<m; i++) {
		sum += arr[i];
	}

	dp[0] = sum;
	for (int i = 1; i<n; i++) {
		sum -= arr[i - 1];
		sum += arr[(i + m - 1) % n];
		dp[i] = sum;
	}

	return *max_element(dp.begin(), dp.end());
}
};