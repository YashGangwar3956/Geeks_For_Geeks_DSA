class Solution {
  public:
    int longestSubstr(string& s, int k) {
        int len = 0;
        for(int i = 0;i<26;i++){
            char c = 'A'+i;
            int cnt = 0, l = 0;
            for(int j = 0;j<s.size();j++){
                if(s[j] == c)cnt++;
                while((j-l+1)-cnt>k){
                    if(s[l] == c)cnt--;
                    l++;
                }
                len = max(len, j-l+1);
            }
        }
        return len;
    }
};