class Solution {
  public:
    string lexicographicallySmallest(string &s, int k) {
        int n = s.size();
        if (n & (n - 1))  
            k = k * 2;
        else              
            k = k / 2;
        if (k >= n) return "-1";
        string st = "";
        int rem = k;
        for (char c : s) {
            while (rem> 0 && !st.empty() && st.back() > c) {
                st.pop_back();
                rem--;
            }
            st.push_back(c);
        }
        while (rem > 0) {
            st.pop_back();
            rem--;
        }
        return st;
    }
};