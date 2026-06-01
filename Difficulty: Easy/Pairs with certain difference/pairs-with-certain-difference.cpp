class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int K) {
        int N=arr.size();
        sort(arr.begin(),arr.end());
        int sum = 0;
        for(int i = N - 1; i > 0; i--) {
            if(arr[i] - arr[i-1] < K) {
                sum += arr[i] + arr[i-1];
                i--; 
            }
        }
        return sum;
    }
};