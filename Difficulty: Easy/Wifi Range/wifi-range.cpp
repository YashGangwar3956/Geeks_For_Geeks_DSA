class Solution {
  public:
    bool wifiRange(string &str, int x) {
        // code here
         int n=str.size();
         int left=-1;
        for(int i=0;i<n;i++){
            if(str[i]=='1'){
                if(i-x>left+1) return 0;
                left=i+x;
            }
        }
        if(left<n-1) return 0;
        return 1;
    }
};