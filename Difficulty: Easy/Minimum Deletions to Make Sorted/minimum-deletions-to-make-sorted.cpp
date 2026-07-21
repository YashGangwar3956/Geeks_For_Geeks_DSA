class Solution {
  public:
    virtual int lisSvc(vector<int> &arr){

      vector<int> cur;
      for(int x: arr){
        int i = lower_bound(cur.begin(), cur.end(), x) - cur.begin();
        if(i==cur.size()) cur.push_back(x);
        else cur[i]=x;
      }
      
      return cur.size();
    }
    
    virtual int minDeletions(vector<int>& arr){
      return arr.size() - lisSvc(arr);
    }
};

