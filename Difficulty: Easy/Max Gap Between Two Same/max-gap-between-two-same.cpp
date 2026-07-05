class Solution {
  public:
    int maxCharGap(string &str) {
        // code here
         unordered_map<char,int>mp;int n=str.size();
    int res=-1;
    for(int i=0;i<n;i++){
     if(mp.find(str[i])==mp.end())
        mp[str[i]]=i;
        else 
        res=max(res,i-mp[str[i]]-1);
    }
    return res;
    }
};