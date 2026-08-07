class Solution {
  public:
    vector<int> search(vector<int> &a, vector<int> &b) {
        // code here
        const long long M = (1LL<<61)-1;
        const int base = 1e4+1;
        long long hash = 0;
        for(auto v:b){
            hash = ((__int128)hash*base + v)%M;
        }
        long long pw = 1;
        long long cur = a[0];
        for(int i=1;i<b.size();i++){
            pw = (__int128)pw*base%M;
            cur = ((__int128)cur*base+a[i])%M;
        }
        vector<int> ans;
        for(int i=b.size();i<a.size();i++){
            if(cur == hash) ans.push_back(i-b.size());
            cur = (cur-(__int128)pw*a[i-b.size()]%M+M)%M;
            cur = ((__int128)cur*base + a[i])%M;
        }
        if(cur == hash) ans.push_back(a.size()-b.size());
        return ans;
    }
};