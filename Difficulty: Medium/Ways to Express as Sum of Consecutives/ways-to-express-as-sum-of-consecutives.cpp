class Solution {
  public:
    int getCount(int N) {
        int ans = 0;
    for(int k = 2; k < sqrt(2*N); k++) 
        if ((N - (k*(k-1)/2)) % k == 0) ans++;
    return ans;
    }
};