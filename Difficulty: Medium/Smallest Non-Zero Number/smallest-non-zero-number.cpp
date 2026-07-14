class Solution {
  public:
    int find(vector<int>& arr) {
        // code here
        int n=arr.size();
        int num = 0;
   for (int i = n - 1; i >= 0; i--)
   num = round((arr[i] + num) / 2.0);
   return num;
    }
};